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
    // Set icon(s) to the application/dialog
    wxIconBundle app_icons;
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("MaiinIcon"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    SetIcons( app_icons );

    
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
    
    m_menuItemHelpAbout = new wxMenuItem(m_menuHelp, wxID_ABOUT, _("About..."), wxT(""), wxITEM_NORMAL);
    m_menuHelp->Append(m_menuItemHelpAbout);
    
    m_statusBar = new wxStatusBar(this, wxID_ANY, wxSTB_DEFAULT_STYLE|wxSTB_SIZEGRIP);
    m_statusBar->SetFieldsCount(1);
    this->SetStatusBar(m_statusBar);
    
    m_mgr = new wxAuiManager;
    m_mgr->SetManagedWindow( this );
    m_mgr->SetFlags( wxAUI_MGR_LIVE_RESIZE|wxAUI_MGR_RECTANGLE_HINT|wxAUI_MGR_TRANSPARENT_HINT|wxAUI_MGR_TRANSPARENT_DRAG|wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_ALLOW_FLOATING);
    m_mgr->GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, wxAUI_GRADIENT_NONE);
    
    m_auiBook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(250,250), wxAUI_NB_DEFAULT_STYLE|wxBK_DEFAULT);
    m_auiBook->SetName(wxT("m_auiBook"));
    
    m_mgr->AddPane(m_auiBook, wxAuiPaneInfo().Direction(wxAUI_DOCK_CENTER).Layer(0).Row(0).Position(0).BestSize(100,100).MinSize(100,100).MaxSize(100,100).CaptionVisible(false).MaximizeButton(false).CloseButton(true).MinimizeButton(false).PinButton(true));
    
    m_panel = new wxPanel(m_auiBook, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_auiBook->AddPage(m_panel, _("Page"), false);
    
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    m_panel->SetSizer(boxSizer);
    
    m_auibarView = new wxAuiToolBar(m_panel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibarView->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer->Add(m_auibarView, 0, wxALL|wxEXPAND, 5);
    
    m_auibarView->AddTool(wxID_ViewZoomIn, _("Zoom In"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewZoomIn")), wxNullBitmap, wxITEM_NORMAL, _("Zoom In"), wxT(""), NULL);
    
    m_auibarView->AddTool(wxID_ViewZoomOut, _("Zoom Out"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewZoomOut")), wxNullBitmap, wxITEM_NORMAL, _("Zoom Out"), wxT(""), NULL);
    
    m_auibarView->AddSeparator();
    
    m_auibarView->AddTool(wxID_ZoomAll, _("Zoom All"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewZoomAll")), wxNullBitmap, wxITEM_NORMAL, _("Zoom All"), wxT(""), NULL);
    
    m_auibarView->AddSeparator();
    
    m_auibarView->AddTool(wxID_ViewZoomWindow, _("Zoom Window"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewZoomWin")), wxNullBitmap, wxITEM_RADIO, _("Zoom Window"), wxT(""), NULL);
    
    m_auibarView->AddTool(wxID_ViewPan, _("Pan"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewPan")), wxNullBitmap, wxITEM_RADIO, _("Pan"), wxT(""), NULL);
    
    m_auibarView->AddTool(wxID_ViewRotate, _("Rotate"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewRotate")), wxNullBitmap, wxITEM_RADIO, _("Rotate"), wxT(""), NULL);
    
    m_auibarView->AddTool(wxID_ViewSelect, _("Select"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewSelect")), wxNullBitmap, wxITEM_RADIO, _("Select"), wxT(""), NULL);
    
    m_auibarView->AddSeparator();
    
    m_auibarView->AddTool(wxID_ANY, _("Predefined Views"), wxXmlResource::Get()->LoadBitmap(wxT("ToolViewPredefView")), wxNullBitmap, wxITEM_NORMAL, _("Predefined Views"), wxT(""), NULL);
    wxAuiToolBarItem* m_tbiViewTop = m_auibarView->FindToolByIndex(m_auibarView->GetToolCount()-1);
    if (m_tbiViewTop) {
        m_tbiViewTop->SetHasDropDown(true);
        m_menuViewPredef = new wxMenu;
        m_menuItemViewTop = new wxMenuItem(m_menuViewPredef, wxID_ViewTop, _("Top"), wxT(""), wxITEM_NORMAL);
        m_menuItemViewTop->SetBitmap(wxXmlResource::Get()->LoadBitmap(wxT("ToolViewPredefView")));
        m_menuViewPredef->Append(m_menuItemViewTop);
        
        m_dropdownMenus.insert(std::make_pair( m_tbiViewTop->GetId(), m_menuViewPredef) );
    }
    
    m_auibarView->AddTool(wxID_View3D, _("3D"), wxXmlResource::Get()->LoadBitmap(wxT("ToolView3D")), wxNullBitmap, wxITEM_CHECK, _("3D"), wxT(""), NULL);
    m_auibarView->Realize();
    
    m_view = new CStartPPView(m_panel);
    boxSizer->Add(m_view, 1, wxALL|wxEXPAND, 5);
    
    m_auibarFilter = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE|wxAUI_TB_HORZ_LAYOUT|wxAUI_TB_GRIPPER);
    m_auibarFilter->SetToolBitmapSize(wxSize(16,16));
    
    m_mgr->AddPane(m_auibarFilter, wxAuiPaneInfo().Name(wxT("Filters")).Caption(_("Filters")).Direction(wxAUI_DOCK_TOP).Layer(0).Row(0).Position(0).Fixed().CaptionVisible(true).MaximizeButton(false).CloseButton(true).MinimizeButton(false).PinButton(false).ToolbarPane());
    m_mgr->Update();
    
    m_auibarFilter->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("ToolFilterNodenum")), wxNullBitmap, wxITEM_CHECK, _("Node numbers"), wxT(""), NULL);
    
    m_auibarFilter->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("ToolFilterLength")), wxNullBitmap, wxITEM_CHECK, wxT(""), wxT(""), NULL);
    
    m_auibarFilter->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("ToolFilterAprof")), wxNullBitmap, wxITEM_CHECK, wxT(""), wxT(""), NULL);
    
    m_auibarFilter->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("ToolFilterElements")), wxNullBitmap, wxITEM_CHECK, _("Elements"), wxT(""), NULL);
    
    m_auibarFilter->AddTool(wxID_ANY, _("Tool Label"), wxXmlResource::Get()->LoadBitmap(wxT("ToolFilterNodes")), wxNullBitmap, wxITEM_CHECK, _("Nodes"), wxT(""), NULL);
    m_auibarFilter->Realize();
    
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    
    #if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_auiBook)){
        wxPersistenceManager::Get().RegisterAndRestore(m_auiBook);
    } else {
        wxPersistenceManager::Get().Restore(m_auiBook);
    }
    #endif
    
    SetName(wxT("MainFrameBaseClass"));
    SetSize(800,600);
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
    this->Connect(m_menuItemHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    this->Connect(wxID_ViewZoomIn, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomIn), NULL, this);
    this->Connect(wxID_ViewZoomOut, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomOut), NULL, this);
    this->Connect(wxID_ZoomAll, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomAll), NULL, this);
    this->Connect(wxID_ViewZoomWindow, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomWindow), NULL, this);
    this->Connect(wxID_ViewPan, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnPan), NULL, this);
    this->Connect(wxID_ViewRotate, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnRotate), NULL, this);
    this->Connect(wxID_ViewSelect, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnSelect), NULL, this);
    this->Connect(m_menuItemViewTop->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewTop), NULL, this);
    this->Connect(wxID_View3D, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnShowOgl), NULL, this);
    
    this->Connect(wxID_ANY, wxEVT_COMMAND_AUITOOLBAR_TOOL_DROPDOWN, wxAuiToolBarEventHandler(MainFrameBaseClass::ShowAuiToolMenu), NULL, this);
}

MainFrameBaseClass::~MainFrameBaseClass()
{
    this->Disconnect(m_menuItemImportDbf->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnImportDbf), NULL, this);
    this->Disconnect(m_menuItemFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Disconnect(m_menuItemRecordPrevious->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRecordPrevious), NULL, this);
    this->Disconnect(m_menuItemRecordNext->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnRecordNext), NULL, this);
    this->Disconnect(m_menuItemHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    this->Disconnect(wxID_ViewZoomIn, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomIn), NULL, this);
    this->Disconnect(wxID_ViewZoomOut, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomOut), NULL, this);
    this->Disconnect(wxID_ZoomAll, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomAll), NULL, this);
    this->Disconnect(wxID_ViewZoomWindow, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnZoomWindow), NULL, this);
    this->Disconnect(wxID_ViewPan, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnPan), NULL, this);
    this->Disconnect(wxID_ViewRotate, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnRotate), NULL, this);
    this->Disconnect(wxID_ViewSelect, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnSelect), NULL, this);
    this->Disconnect(m_menuItemViewTop->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnViewTop), NULL, this);
    this->Disconnect(wxID_View3D, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainFrameBaseClass::OnShowOgl), NULL, this);
    
    m_mgr->UnInit();
    delete m_mgr;

    std::map<int, wxMenu*>::iterator menuIter = m_dropdownMenus.begin();
    for( ; menuIter != m_dropdownMenus.end(); ++menuIter ) {
        wxDELETE( menuIter->second );
    }
    m_dropdownMenus.clear();

    this->Disconnect(wxID_ANY, wxEVT_COMMAND_AUITOOLBAR_TOOL_DROPDOWN, wxAuiToolBarEventHandler(MainFrameBaseClass::ShowAuiToolMenu), NULL, this);
}


void MainFrameBaseClass::ShowAuiToolMenu(wxAuiToolBarEvent& event)
{
    event.Skip();
    if (event.IsDropDownClicked()) {
        wxAuiToolBar* toolbar = wxDynamicCast(event.GetEventObject(), wxAuiToolBar);
        if (toolbar) {
            wxAuiToolBarItem* item = toolbar->FindTool(event.GetId());
            if (item) {
                std::map<int, wxMenu*>::iterator iter = m_dropdownMenus.find(item->GetId());
                if (iter != m_dropdownMenus.end()) {
                    event.Skip(false);
                    wxPoint pt = event.GetItemRect().GetBottomLeft();
                    pt.y++;
                    toolbar->PopupMenu(iter->second, pt);
                }
            }
        }
    }
}
ImageList::ImageList()
    : wxImageList(16, 16, true)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("PropMo"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("PropMo"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("PropNapr"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("PropNapr"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("PropSk"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("PropSk"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("PropOtvIz"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("PropOtvIz"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("PropOtvSv"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("PropOtvSv"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("PropArm"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("PropArm"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("Select"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("Select"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("Pan"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("Pan"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("Rotate"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("Rotate"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("Zoom"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("Zoom"), bmp ) );
    }
    
}

ImageList::~ImageList()
{
}
