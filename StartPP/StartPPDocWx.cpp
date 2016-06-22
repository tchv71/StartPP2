#include "stdafx.h"
#include "PropertiesWnd.h"
#include "StartPPDoc.h"
#include "MainFrame.h"
#include "Strings.h"
#include <wx/fileconf.h>
#include "StartPPView.h"
#include "main.h"
#include "Pipe.h"
#include "NewPipeDialog.h"
#include "DelPipesDialog.h"



wxIMPLEMENT_DYNAMIC_CLASS(CStartPPDoc, wxDocument);

wxBEGIN_EVENT_TABLE(CStartPPDoc, wxDocument)
    EVT_MENU(MainFrameBaseClass::wxID_NEW_PIPE, CStartPPDoc::OnNewPipe)
    EVT_MENU(MainFrameBaseClass::wxID_DEL_PIPE, CStartPPDoc::OnDelPipe)
	EVT_UPDATE_UI(MainFrameBaseClass::wxID_UNDO1, CStartPPDoc::OnUpdateUndo)
	EVT_UPDATE_UI(MainFrameBaseClass::wxID_REDO1, CStartPPDoc::OnUpdateRedo)
	EVT_MENU(MainFrameBaseClass::wxID_UNDO1, CStartPPDoc::OnUndo)
	EVT_MENU(MainFrameBaseClass::wxID_REDO1, CStartPPDoc::OnRedo)
wxEND_EVENT_TABLE()

CStartPPDoc::CStartPPDoc() : m_nUndoPos(-1)
{
}

CStartPPDoc::~CStartPPDoc()
{

}

void CStartPPDoc::OnRecordNext()
{
	if (m_pipes.m_nIdx == m_pipes.m_vecPnN.size() - 1)
		return;
	m_pipes.m_nIdx++;
	SyncSel();
}


void CStartPPDoc::OnRecordPrev()
{
	if (m_pipes.m_nIdx == 0)
		return;
	m_pipes.m_nIdx--;
	SyncSel();
}

void CStartPPDoc::SyncSel(void)
{
	UpdateData(TRUE);
	CPipeAndNode& p = m_pipes.CurPipe();
	vecSel.clear();
	vecSel.SelNAYZ = int(m_pFrame->GetPropWnd()->m_PropMode == E_NODE ? p.m_KOYZ : p.m_NAYZ);
	vecSel.SelKOYZ = int(p.m_KOYZ);
	vecSel.insert(SelStr(vecSel.SelNAYZ, vecSel.SelKOYZ));
	UpdateData(FALSE);
}


bool CStartPPDoc::OnNewDocument()
{
	if (!wxDocument::OnNewDocument())
		return false;

	CPipeAndNode p;
	p.m_KOYZ = 1;
	p.m_MNEO = _T("мо");
	m_pipes.m_vecPnN.push_back(p);
	p.m_MNEO = _T("");
	p.m_RADA = 16.0f;
	p.m_RATE = 150.0f;
	p.m_KOPE = 0.8f;
	p.m_NAMA = _T("20");
	p.m_KOPR = 1.0f;
	p.m_OSIX = 1.0f;
	p.m_NAYZ = 1;
	p.m_KOYZ = 2;
	m_pipes.m_vecPnN.push_back(p);
	m_pipes.m_nIdx = 1;
	vecSel.insert(SelStr(1, 2));
	m_pFrame = static_cast<MainFrame *>(wxGetApp().GetTopWindow());
	m_pFrame->GetPropWnd()->m_PropMode = E_PIPE;

	UpdateAllViews(nullptr, m_pFrame->GetGlPanel());
	UpdateData(FALSE);
	return true;
}

void CStartPPDoc::OnImportDbf()
{
	wxFileDialog dlg(m_pFrame, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString, "*.dbf");
	wxFileConfig fcf(_T("StartPP"),wxEmptyString,_T(".StartPP"),wxEmptyString,wxCONFIG_USE_LOCAL_FILE);
	CString strDir; //AfxGetApp()->GetProfileString(_T("Settings"), _T("ImportDbf"));
	fcf.Read(_T("ImportDbf"),&strDir,_T(""));
	if (!strDir.IsEmpty())
		dlg.SetDirectory(strDir);
	//	dlg.m_ofn.lpstrInitialDir = strDir;
	if (dlg.ShowModal() == wxID_OK)
	{
		//AfxGetApp()->m_pDocManager->OpenDocumentFile(nullptr,FALSE);
		CString strFile = dlg.GetFilename();
		//SetTitle(strFile);
		CString strFolder = dlg.GetDirectory();
		//AfxGetApp()->WriteProfileString(_T("Settings"), _T("ImportDbf"), strFolder);
		fcf.Write(_T("ImportDbf"), strFolder);
		fcf.Flush();
		m_StartPPSet.m_strPath = strFolder;
		m_StartPPSet.m_strTable = strFile;
		//m_strPathName = strFolder + _T("/") + strFile;
		m_pipes.m_vecPnN.clear();
		m_pipes.m_nIdx = 0;
		try
		{
			m_StartPPSet.SetOldSet(false);
			m_StartPPSet.Open();
		}
		catch (std::exception)
		{
			m_StartPPSet.SetOldSet(true);
			m_StartPPSet.Open();
			//e->Delete();
		}
		while (!m_StartPPSet.IsEOF())
		{
			m_pipes.m_vecPnN.push_back(m_StartPPSet);
			m_StartPPSet.MoveNext();
		}
		m_StartPPSet.Close();
		//m_pFrame->GetView()->OnCreate(this,0);
		UpdateAllViews(nullptr,m_pFrame->GetGlPanel());
		/*		POSITION pos = GetFirstViewPosition();
				while (pos != nullptr)
				{
					CView* pView = GetNextView(pos);
					ASSERT_VALID(pView);
					pView->OnInitialUpdate();
				}
        */
		UpdateData(FALSE);
	}
	else
		OnCloseDocument();
}

void CStartPPDoc::SetUndo(void)
{
	if (m_vecUndo.size() != 0 && m_pipes.m_vecPnN.size() == m_vecUndo[m_vecUndo.size() - 1].vec.m_vecPnN.size())
	{
		std::vector<CPipeAndNode>& vecTop = m_vecUndo[m_vecUndo.size() - 1].vec.m_vecPnN;
		unsigned i;
		for (i = 0; i < vecTop.size(); i++)
		{
			if (memcmp(&vecTop[i], &m_pipes.m_vecPnN[i], sizeof(CPipeAndNode)) != 0)
				break;
		}
		if (i == vecTop.size())
			return;
	}
	m_vecUndo.push_back(SUndo(m_pipes, vecSel));
	m_nUndoPos = m_vecUndo.size() - 1;
}



void CStartPPDoc::UpdateData(bool bSaveAndValidate)
{
	CDataExchange dx(m_pFrame, bSaveAndValidate);
	m_pFrame->GetPropWnd()->DoDataExchange(&dx, &m_pipes.CurPipe(), this);
	//m_pFrame->m_wndPipeTable.DoDataExchange(&dx, this);
	if (!bSaveAndValidate)
	{
		SetUndo();
		wxDocument::UpdateAllViews(nullptr,nullptr); // Selection is changed
	}
}

void CStartPPDoc::PnNIsUpdated(void)
{
	Modify(true);
	SetUndo();
	wxDocument::UpdateAllViews();
}


CPipeAndNode* CStartPPDoc::GetPrevPnN(int NAYZ)
{
	for (unsigned i = 0; i < m_pipes.m_vecPnN.size(); i++)
		if (fabs(m_pipes.m_vecPnN[i].m_KOYZ - NAYZ) < 1e-3f)
			return &m_pipes.m_vecPnN[i];
	return nullptr;
}


void CStartPPDoc::RotateThisAndOthers(float fAngle)
{
	m_bvecRotated.resize(m_pipes.m_vecPnN.size());
	for (unsigned i = 0; i < m_bvecRotated.size(); i++)
		m_bvecRotated[i] = false;
	RotateOne(m_pipes.m_nIdx, fAngle);
	RotateAll(int(m_pipes.m_vecPnN[m_pipes.m_nIdx].m_KOYZ), fAngle);
}

void CStartPPDoc::RotateThisAndOthers(CPipeAndNode* pPnN, float fAngle)
{
	m_bvecRotated.resize(m_pipes.m_vecPnN.size());
	int nIdx = 0;
	for (unsigned i = 0; i < m_bvecRotated.size(); i++)
	{
		m_bvecRotated[i] = false;
		if (pPnN->m_NAYZ == m_pipes.m_vecPnN[i].m_NAYZ && pPnN->m_KOYZ == m_pipes.m_vecPnN[i].m_KOYZ)
			nIdx = i;
	}
	RotateOne(nIdx, fAngle);
	RotateAll(int(m_pipes.m_vecPnN[nIdx].m_KOYZ), fAngle);
}


extern float Round(float x, int N);


void CStartPPDoc::RotateOne(size_t recNo, float fAngle)
{
	float x, y, x1, y1;
	x = m_pipes.m_vecPnN[recNo].m_OSIX;
	y = m_pipes.m_vecPnN[recNo].m_OSIY;
	m_bvecRotated[recNo] = true;
	x1 = Round(x * cos(fAngle) - y * sin(fAngle), 3);
	y1 = Round(x * sin(fAngle) + y * cos(fAngle), 3);
	m_pipes.m_vecPnN[recNo].m_OSIX = x1;
	m_pipes.m_vecPnN[recNo].m_OSIY = y1;
}


void CStartPPDoc::RotateAll(int NAYZ, float fAngle)
{
	unsigned i = 0;
	bool bFound = false;
	for (; i < m_pipes.m_vecPnN.size(); i++)
		if (fabs(m_pipes.m_vecPnN[i].m_NAYZ - NAYZ) < 1e-3f)
		{
			bFound = true;
			break;
		}
	while (bFound)
	{
		if (!m_bvecRotated[i])
		{
			RotateOne(i, fAngle);
			RotateAll(int(m_pipes.m_vecPnN[i].m_KOYZ), fAngle);
		}
		i++;
		bFound = false;
		for (; i < m_pipes.m_vecPnN.size(); i++)
			if (fabs(m_pipes.m_vecPnN[i].m_NAYZ - NAYZ) < 1e-3f)
			{
				bFound = true;
				break;
			}
	}
}


void CStartPPDoc::Select(int NAYZ, int KOYZ)
{
	vecSel.SelNAYZ = NAYZ;
	vecSel.SelKOYZ = KOYZ;
	if (NAYZ < 0 || KOYZ < 0)
	{
		vecSel.clear();
		return;
	}
	if (vecSel.size() == 0)
	{
		vecSel.insert(SelStr(NAYZ, KOYZ));
	}
	else if (vecSel.size() == 1)
	{
		vecSel.clear();
		vecSel.insert(SelStr(NAYZ, KOYZ));
	}
	if (NAYZ == KOYZ)
	{
		for (unsigned i = 0; i < m_pipes.m_vecPnN.size(); i++)
			if (fabs(m_pipes.m_vecPnN[i].m_KOYZ - NAYZ) < 1e-3f)
			{
				UpdateData(TRUE);
				m_pipes.m_nIdx = i;
				m_pFrame->GetPropWnd()->m_PropMode = E_NODE;
				UpdateData(FALSE);
				break;
			}
		return;
	}

	for (unsigned i = 0; i < m_pipes.m_vecPnN.size(); i++)
		if (fabs(m_pipes.m_vecPnN[i].m_NAYZ - NAYZ) < 1e-3f && fabs(m_pipes.m_vecPnN[i].m_KOYZ - KOYZ) < 1e-3f)
		{
			UpdateData(TRUE);
			m_pipes.m_nIdx = i;
			m_pFrame->GetPropWnd()->m_PropMode = E_PIPE;
			UpdateData(FALSE);
			break;
		}
}

void CStartPPDoc::UpdateAllViews(wxView *sender, wxObject *hint)
{
	wxDocument::UpdateAllViews(sender, hint);
}

void CStartPPDoc::Serialize(CArchive& ar)
{
	UNREFERENCED_PARAMETER(ar);
}


void CStartPPDoc::DeleteSelected(void)
{
	std::vector<CPipeAndNode> vecRemained;
	std::vector<CPipeAndNode> vecSelected;
	for (auto& x : m_pipes.m_vecPnN)
	{
		if (!vecSel.Contains(x.m_NAYZ, x.m_KOYZ))
			vecRemained.push_back(x);
		else
			vecSelected.push_back(x);
	}
	CPipeArray arrRemained;
	arrRemained.copy_pipes(vecRemained);
	if (!arrRemained.CheckConnectivity())
	{
		if (AfxMessageBox(LoadStr(IDS_UNITE_NODES_Q), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			while (!vecSelected.empty())
			{
				CPipeArray arrSelected(vecSelected);
				std::set<int> setSelNodes;
				arrSelected.CheckConnectivity();
				std::multimap<int, Pipe>& pipes = arrSelected.GetPipes();
				for (auto& x : pipes)
					if (x.second.Drawed)
					{
						setSelNodes.insert(x.second.StrP);
						setSelNodes.insert(x.second.EndP);
						for (auto its = vecSelected.begin(); its != vecSelected.end(); ++its)
							if (int(its->m_NAYZ) == x.second.StrP && int(its->m_KOYZ) == x.second.EndP)
							{
								vecSelected.erase(its);
								break;
							}
					}
				std::set<int> setNodesUnite;
				for (auto& x : setSelNodes)
					if (arrRemained.InCount(x) > 0 || arrRemained.OutCount(x) > 0)
						setNodesUnite.insert(x);
				int nNewNum = *setNodesUnite.begin();
				for (auto it = vecRemained.begin(); it != vecRemained.end(); ++it)
				{
					if (setNodesUnite.find(int(it->m_NAYZ)) != setNodesUnite.end())
						it->m_NAYZ = float(nNewNum);
					if (setNodesUnite.find(int(it->m_KOYZ)) != setNodesUnite.end())
						it->m_KOYZ = float(nNewNum);
				}
			}
		}
	}
	vecSel.clear();
	vecSel.SelNAYZ = vecSel.SelKOYZ = -1;
	m_pipes.m_vecPnN = vecRemained;
	m_pipes.m_nIdx = 0;
	PnNIsUpdated();
}

bool CStartPPDoc::IsSelConnected(void)
{
	std::vector<CPipeAndNode> vecCopy;
	for (auto it = m_pipes.m_vecPnN.begin(); it != m_pipes.m_vecPnN.end(); ++it)
		if (vecSel.Contains(it->m_NAYZ, it->m_KOYZ))
			vecCopy.push_back(*it);
	CPipeArray pipeArr;
	pipeArr.copy_pipes(vecCopy);
	return pipeArr.CheckConnectivity();
}

void CStartPPDoc::OnNewPipe(wxCommandEvent& event)
{
	CPipes pipes(m_pipes.m_nIdx, m_pipes.m_vecPnN);
	CNewPipeDialog dlg(nullptr, pipes);
	if (dlg.ShowModal() == wxID_OK)
	{
		Modify(true);
		UpdateAllViews(nullptr);
		UpdateData(FALSE);
	}
}

void CStartPPDoc::OnDelPipe(wxCommandEvent& event)
{
	CDelPipesDialog dlg(nullptr, this);
	dlg.ShowModal();
}


void CStartPPDoc::OnMultPipe()
{
	CPipes pipes(m_pipes.m_nIdx, m_pipes.m_vecPnN);
	CMultPipeDialog dlg(nullptr, pipes);
	if (dlg.DoModal() == IDOK)
	{
		m_bModified = true;
		UpdateAllViews(nullptr);
		UpdateData(FALSE);
	}
}

#if 0

void CStartPPDoc::OnCopyPipeParams()
{
	CPipes pipes(m_pipes.m_nIdx, m_pipes.m_vecPnN);
	CCopyParamsDialog dlg(nullptr, pipes);
	if (dlg.DoModal() == IDOK)
	{
		m_bModified = true;
		UpdateAllViews(nullptr);
		UpdateData(FALSE);
	}
}


void CStartPPDoc::OnInvertPipe()
{
	CPipeAndNode& p = m_pipes.m_vecPnN[m_pipes.m_nIdx];
	float n = p.m_KOYZ;
	p.m_KOYZ = p.m_NAYZ;
	p.m_NAYZ = n;
	p.m_OSIX = -p.m_OSIX;
	p.m_OSIY = -p.m_OSIY;
	p.m_OSIZ = -p.m_OSIZ;
	UpdateAllViews(nullptr);
	UpdateData(FALSE);
}


void CStartPPDoc::OnNewNode()
{
	CPipes pipes(m_pipes.m_nIdx, m_pipes.m_vecPnN);
	CNewNodeDialog dlg(nullptr, pipes);
	if (dlg.DoModal() == IDOK)
	{
		m_bModified = true;
		UpdateAllViews(nullptr);
		UpdateData(FALSE);
	}
}


void CStartPPDoc::OnDelNode()
{
	CString str;
	int nKOYZ = int(m_pipes.m_vecPnN[m_pipes.m_nIdx].m_KOYZ);
	str.Format(LoadStr(IDS_DELETE_NODE_Q), nKOYZ);
	if (AfxMessageBox(str, MB_OKCANCEL) == IDCANCEL)
		return;
	CPipes pipes(m_pipes.m_nIdx, m_pipes.m_vecPnN);
	if (!pipes.FindFirstKOYZ(nKOYZ))
	{
		str.Format(LoadStr(IDS_MN_NO_PIPES_UZ), nKOYZ);
		AfxMessageBox(str);
		return;
	}
	if (pipes.FindNextKOYZ(nKOYZ))
	{
		str.Format(LoadStr(IDS_MN_2PIPES_IN), nKOYZ);
		AfxMessageBox(str);
		return;
	}

	if (!pipes.FindFirstNAYZ(nKOYZ))
	{
		str.Format(LoadStr(IDS_MN_NO_PIPES_OUT), nKOYZ);
		AfxMessageBox(str);
		return;
	}
	if (pipes.FindNextNAYZ(nKOYZ))
	{
		str.Format(LoadStr(IDS_MN_2_PIPES_OUT), nKOYZ);
		AfxMessageBox(str);
		return;
	}
	CPipeAndNode p = m_pipes.m_vecPnN[m_pipes.m_nIdx];
	float dx1 = p.m_OSIX,
		dy1 = p.m_OSIY,
		dz1 = p.m_OSIZ,
		Len1 = sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
	pipes.FindFirstNAYZ(nKOYZ);
	CPipeAndNode& p1 = m_pipes.m_vecPnN[pipes.m_SearchIdx];
	//int NewEndNode=int(p1.m_KOYZ);
	float dx2 = p1.m_OSIX,
		dy2 = p1.m_OSIY,
		dz2 = p1.m_OSIZ,
		Len2 = sqrt(dx2 * dx2 + dy2 * dy2 + dz2 * dz2);

	if (fabs(Len1) < 0.001 || fabs(Len2) < 0.001)
	{
		AfxMessageBox(LoadStr(IDS_MN_NULL_LEN));
		return;
	}
	if (fabs(dx1 / Len1 - dx2 / Len2) > 0.001 || fabs(dy1 / Len1 - dy2 / Len2) > 0.001 ||
		fabs(dz1 / Len1 - dz2 / Len2) > 0.001)
	{
		str.Format(LoadStr(IDS_MN_IZLOM1), nKOYZ);
		AfxMessageBox(str);
		return;
	}

	p1.m_NAYZ = p.m_NAYZ;
	p1.m_OSIX = dx1 + dx2;
	p1.m_OSIY = dy1 + dy2;
	p1.m_OSIZ = dz1 + dz2;

	m_pipes.m_vecPnN.erase(m_pipes.m_vecPnN.begin() + m_pipes.m_nIdx);
	m_bModified = true;
	UpdateAllViews(nullptr);
	UpdateData(FALSE);
}


void CStartPPDoc::OnMoveNode()
{
	CPipes pipes(m_pipes.m_nIdx, m_pipes.m_vecPnN);
	CMoveNodeDialog dlg(nullptr, pipes);
	if (dlg.DoModal() == IDOK)
	{
		m_bModified = true;
		UpdateAllViews(nullptr);
		UpdateData(FALSE);
	}
}


void CStartPPDoc::OnRenumPipes()
{
	if (AfxMessageBox(IDS_RENUM_NODES_Q, MB_YESNO) == IDNO)
		return;
	int FirstNum = 1;
	int MaxNodeNum = m_pipes.GetMaxNodeNum();
	m_pipes.RenumPipes(FirstNum, MaxNodeNum);
	m_bModified = true;
	UpdateAllViews(nullptr);
	UpdateData(FALSE);
}

#endif


void CStartPPDoc::OnUndo(wxCommandEvent& event)
{
	m_pipes = m_vecUndo[--m_nUndoPos].vec;
	vecSel = m_vecUndo[m_nUndoPos].sel;
	CDataExchange dx(m_pFrame, FALSE);
	m_pFrame->GetPropWnd()->DoDataExchange(&dx, &m_pipes.m_vecPnN[m_pipes.m_nIdx], this);

	UpdateAllViews(nullptr);
	event.Skip();
}


void CStartPPDoc::OnUpdateUndo(wxUpdateUIEvent& event)
{
	event.Enable(m_nUndoPos > 0);
	event.Skip();
}


void CStartPPDoc::OnRedo(wxCommandEvent& event)
{
	m_pipes = m_vecUndo[++m_nUndoPos].vec;
	vecSel = m_vecUndo[m_nUndoPos].sel;
	CDataExchange dx(m_pFrame, FALSE);
	m_pFrame->GetPropWnd()->DoDataExchange(&dx, &m_pipes.m_vecPnN[m_pipes.m_nIdx], this);

	UpdateAllViews(nullptr);
	event.Skip();
}


void CStartPPDoc::OnUpdateRedo(wxUpdateUIEvent& event)
{
	event.Enable(m_nUndoPos + 1 < int(m_vecUndo.size()));
	event.Skip();
}

