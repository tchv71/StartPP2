//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;


MainFrameBaseClass::MainFrameBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    m_propWnd= new CPropertiesWnd(this, wxID_ANY);
    boxSizer1->Add(m_propWnd, 1, wxALL|wxEXPAND, 5);
    
    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);
    
    m_menuFile = new wxMenu();
    m_menuBar->Append(m_menuFile, _("&File"));
    
    m_menuItemImportDbf = new wxMenuItem(m_menuFile, wxID_ImportDbf, _("Import Dbf...\tCtrl-I"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItemImportDbf);
    
    m_menuItemFileExit = new wxMenuItem(m_menuFile, wxID_EXIT, _("Exit\tAlt-X"), _("Quit"), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItemFileExit);
    
    m_menuRecord = new wxMenu();
    m_menuBar->Append(m_menuRecord, _("&Record"));
    
    m_menuItemRecordPrevious = new wxMenuItem(m_menuRecord, wxID_ANY, _("&Previous\tCtrl-P"), wxT(""), wxITEM_NORMAL);
    m_menuRecord->Append(m_menuItemRecordPrevious);
    
    m_menuItemRecordNext = new wxMenuItem(m_menuRecord, wxID_ANY, _("&Next\tCtrl-N"), wxT(""), wxITEM_NORMAL);
    m_menuRecord->Append(m_menuItemRecordNext);
    
    m_menuHelp = new wxMenu();
    m_menuBar->Append(m_menuHelp, _("&Help"));
    
    m_menuItem9 = new wxMenuItem(m_menuHelp, wxID_ABOUT, _("About..."), wxT(""), wxITEM_NORMAL);
    m_menuHelp->Append(m_menuItem9);
    
    m_mainToolbar = this->CreateToolBar(wxTB_FLAT, wxID_ANY);
    m_mainToolbar->SetToolBitmapSize(wxSize(16,16));
    
    m_mainToolbar->AddTool(wxID_ANY, _("Мертвая опора"), wxXmlResource::Get()->LoadBitmap(wxT("PropMo")), wxNullBitmap, wxITEM_CHECK, _("Мертвая опора"), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Скользящая опора"), wxXmlResource::Get()->LoadBitmap(wxT("PropSk")), wxNullBitmap, wxITEM_CHECK, _("Скользящая опора"), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Направляющая опора"), wxXmlResource::Get()->LoadBitmap(wxT("PropNapr")), wxNullBitmap, wxITEM_NORMAL, _("Направляющая опора"), wxT(""), NULL);
    
    m_mainToolbar->AddSeparator();
    
    m_mainToolbar->AddTool(wxID_ANY, _("Отвод сварной"), wxXmlResource::Get()->LoadBitmap(wxT("PropOtvSv")), wxNullBitmap, wxITEM_NORMAL, _("Отвод сварной"), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Отвод изогнутый"), wxXmlResource::Get()->LoadBitmap(wxT("PropOtvIz")), wxNullBitmap, wxITEM_NORMAL, _("Отвод изогнутый"), wxT(""), NULL);
    
    m_mainToolbar->AddTool(wxID_ANY, _("Арматура"), wxXmlResource::Get()->LoadBitmap(wxT("PropArm")), wxNullBitmap, wxITEM_NORMAL, _("Арматура"), wxT(""), NULL);
    m_mainToolbar->Realize();
    
    m_statusBar = new wxStatusBar(this, wxID_ANY, wxSTB_DEFAULT_STYLE|wxSTB_SIZEGRIP);
    m_statusBar->SetFieldsCount(1);
    this->SetStatusBar(m_statusBar);
    
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    SetName(wxT("MainFrameBaseClass"));
    SetSize(600,500);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    this->Connect(m_menuItemImportDbf->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImportDbf), NULL, this);
    this->Connect(m_menuItemFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Connect(m_menuItemRecordPrevious->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRecordPrevious), NULL, this);
    this->Connect(m_menuItemRecordNext->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRecordNext), NULL, this);
    this->Connect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    this->Connect(wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMo), NULL, this);
    
}

MainFrameBaseClass::~MainFrameBaseClass()
{
    this->Disconnect(m_menuItemImportDbf->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImportDbf), NULL, this);
    this->Disconnect(m_menuItemFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Disconnect(m_menuItemRecordPrevious->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRecordPrevious), NULL, this);
    this->Disconnect(m_menuItemRecordNext->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRecordNext), NULL, this);
    this->Disconnect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnMo), NULL, this);
    
}
