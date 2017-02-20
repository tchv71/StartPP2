#include "stdafx.h"
#include <wx/window.h>
#include "PipeGrid.h"
#include "PipeTable.h"
#include "Material.h"
#include <PipesSet.h>
#include "main.h"
#include "MainFrame.h"

PipeGrid::PipeGrid()
{
}

PipeGrid::~PipeGrid()
{
}

PipeGrid::PipeGrid(wxWindow *pWin, wxStandardID id, const wxPoint point, wxSize size, int i) :
		wxGrid(pWin, id, point, size,i)
{
	UseNativeColHeader(true);
}

void PipeGrid::SetColFormat()
{
	for (int i = 0; i <= 4;i++)
		SetColFormatFloat(i,-1,3);
	SetColFormatFloat(5,-1,1);
	SetColFormatFloat(6,-1,1);
	SetColFormatFloat(7,-1,1);
	SetColFormatFloat(8,-1,0);
	SetColFormatFloat(9, -1, 0);

	for (int i = 0;i < GetNumberRows();i++)
	{
		MainFrame *frame = wxStaticCast(wxGetApp().GetTopWindow(), MainFrame);
		CStartPPDoc* pDoc = frame->m_doc;
		BOOL bPodzem = fabs(pDoc->m_pipes.m_vecPnN[i].m_NAGV + 1) < 1e-6;
		std::vector<float> vecDiams;
		CPipesSet set;
		set.m_strPath = DATA_PATH;
		set.m_strTable = _T("Pipes.dbf"); // set.m_strTable.Format(_T("[Pipes] where %d=PODZ order by DIAM"), int(bPodzem));
		set.Open();
		for (; !set.IsEOF(); set.MoveNext())
		{
			if (bPodzem != set.m_PODZ)
				continue;
			vecDiams.push_back(set.m_DIAM);
		}
		set.Close();
		std::sort(vecDiams.begin(), vecDiams.end());
		wxArrayString ar;
		for (auto x : vecDiams)
			ar.push_back(CString::Format(_T("%g"), x));
		SetCellEditor(i, 9, new wxGridCellChoiceEditor(ar,true));

	}
	for (int i=0;i<GetNumberRows();i++)
    {
         CMaterial setMaterial;
         setMaterial.m_strPath = DATA_PATH;
         setMaterial.m_strTable = _T("Matup.dbf");// _T("[MATUP]  order by NOM");
         setMaterial.Open();
         wxArrayString ar;
         while (!setMaterial.IsEOF())
         {
             ar.Add(CString(setMaterial.m_MAT));
             setMaterial.MoveNext();
         }
	    SetCellEditor(i, 10, new wxGridCellChoiceEditor(ar));
    }
	SetColFormatFloat(11,-1,1);
	SetColFormatFloat(12,-1,2);
	SetColFormatFloat(13,-1,1);
	SetColFormatFloat(14,-1,1);
	SetColFormatFloat(15,-1,1);
	for (int i=16; i<=20;i++)
		SetColFormatFloat(i, -1, 2);
}
