/***************************************************************
 * Name:      solver_appMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mateusz Oleszek (motmen001@gmail.com)
 * Created:   2021-03-19
 * Copyright: Mateusz Oleszek (paraon.xyz)
 * License:
 **************************************************************/

#include "solver_appMain.h"
#include <wx/msgdlg.h>


//(*InternalHeaders(solver_appFrame)
#include <wx/font.h>
#include <wx/fontenum.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(solver_appFrame)
const long solver_appFrame::ID_TEXTCTRL1 = wxNewId();
const long solver_appFrame::ID_TEXTCTRL2 = wxNewId();
const long solver_appFrame::ID_RADIOBUTTON1 = wxNewId();
const long solver_appFrame::ID_RADIOBUTTON2 = wxNewId();
const long solver_appFrame::ID_TEXTCTRL3 = wxNewId();
const long solver_appFrame::ID_TEXTCTRL4 = wxNewId();
const long solver_appFrame::ID_BUTTON1 = wxNewId();
const long solver_appFrame::ID_TEXTCTRL6 = wxNewId();
const long solver_appFrame::ID_TEXTCTRL5 = wxNewId();
const long solver_appFrame::ID_MENUITEM2 = wxNewId();
const long solver_appFrame::ID_MENUITEM1 = wxNewId();
const long solver_appFrame::idMenuAbout = wxNewId();
const long solver_appFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(solver_appFrame,wxFrame)
    //(*EventTable(solver_appFrame)
    //*)
END_EVENT_TABLE()

solver_appFrame::solver_appFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(solver_appFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer7;

    Create(parent, wxID_ANY, _("Linear Equation Solver"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX|wxBORDER_SIMPLE|wxCLIP_CHILDREN, _T("wxID_ANY"));
    wxFontEnumerator __FontEnumerator;
    __FontEnumerator.EnumerateFacenames();
    #if wxCHECK_VERSION(2, 8, 0)
    	const wxArrayString& __FontFaces = __FontEnumerator.GetFacenames();
    #else
    	const wxArrayString& __FontFaces = *__FontEnumerator.GetFacenames();
    #endif
    wxString __thisFontFace;
    if ( __FontFaces.Index(_T("Cascadia Code")) != wxNOT_FOUND )
    	__thisFontFace = _T("Cascadia Code");
    else if ( __FontFaces.Index(_T("@Arial Unicode MS")) != wxNOT_FOUND )
    	__thisFontFace = _T("@Arial Unicode MS");
    wxFont thisFont(10,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,__thisFontFace,wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Equation matrix [A]"));
    TextCtrlEquations = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_MULTILINE, wxTextValidator(wxFILTER_ASCII), _T("ID_TEXTCTRL1"));
    StaticBoxSizer2->Add(TextCtrlEquations, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(StaticBoxSizer2, 4, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Constant Terms [b]"));
    TextCtrlConstants = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_MULTILINE, wxTextValidator(wxFILTER_ASCII), _T("ID_TEXTCTRL2"));
    StaticBoxSizer3->Add(TextCtrlConstants, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(StaticBoxSizer3, 3, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer1, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Options"));
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, this, _("Data type"));
    RadioButtonDouble = new wxRadioButton(this, ID_RADIOBUTTON1, _("Double"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButtonDouble->SetValue(true);
    StaticBoxSizer4->Add(RadioButtonDouble, 1, wxALL|wxALIGN_LEFT, 5);
    RadioButtonInterval = new wxRadioButton(this, ID_RADIOBUTTON2, _("Interval"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer4->Add(RadioButtonInterval, 1, wxALL|wxALIGN_LEFT, 5);
    StaticBoxSizer1->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Accuracy [%]"));
    TextCtrlAccuracy = new wxTextCtrl(this, ID_TEXTCTRL3, _("0.001"), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC), _T("ID_TEXTCTRL3"));
    TextCtrlAccuracy->SetMaxLength(20);
    StaticBoxSizer5->Add(TextCtrlAccuracy, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer5, 0, wxALL|wxEXPAND, 1);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Max no. of iterations"));
    TextCtrlIterations = new wxTextCtrl(this, ID_TEXTCTRL4, _("100"), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_DIGITS), _T("ID_TEXTCTRL4"));
    TextCtrlIterations->SetMaxLength(13);
    StaticBoxSizer6->Add(TextCtrlIterations, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND, 1);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxALIGN_TOP, 5);
    BoxSizer4->Add(BoxSizer2, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxSHAPED, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    ButtonSolve = new wxButton(this, ID_BUTTON1, _("Solve"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer5->Add(ButtonSolve, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Iterations"));
    TextCtrlIterationsDone = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrlIterationsDone->SetMaxLength(33);
    TextCtrlIterationsDone->Disable();
    StaticBoxSizer7->Add(TextCtrlIterationsDone, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    TextCtrlResults = new wxTextCtrl(this, ID_TEXTCTRL5, _("Results [x]"), wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrlResults->Disable();
    BoxSizer3->Add(TextCtrlResults, 2, wxALL|wxALIGN_TOP, 5);
    BoxSizer4->Add(BoxSizer3, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    SetSizer(BoxSizer4);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Equation From File"), _("Load equation matrix and constant terms from txt file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer4->Fit(this);
    BoxSizer4->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&solver_appFrame::OnSolveButtonClick);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&solver_appFrame::OnLoadFromFileSelected);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&solver_appFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&solver_appFrame::OnAbout);
    //*)
}

solver_appFrame::~solver_appFrame()
{
    //(*Destroy(solver_appFrame)
    //*)
}

void solver_appFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void solver_appFrame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    wxString msg =
        "App solving linear equations using Gauss-Seidel method.\n"
        "Coefficients of equation have to be separated with semicolons.\n"
        "Every equation on a new line";
    wxMessageBox(msg, _("Linear equation solver"));
}



void solver_appFrame::OnSolveButtonClick(wxCommandEvent& event)
{
    //Get Data
    std::string equation_matrix_str = TextCtrlEquations->GetValue().ToStdString();
    std::string constant_terms_str = TextCtrlConstants->GetValue().ToStdString();

    bool double_option = RadioButtonDouble->GetValue();
    int iterations = std::stoi(TextCtrlIterations->GetValue().ToStdString());
    double accuracy = std::stod(TextCtrlAccuracy->GetValue().ToStdString());


    //Validate
    if(accuracy == 0.0){
        std::cout<<"Wrong accuracy value \n";
        return;
    }

    std::vector<std::vector<double>> equation_matrix = ParseAppInputEquations(equation_matrix_str, ";");
    std::vector<double> constant_terms = ParseAppInputConstants(constant_terms_str);


    if(equation_matrix.size() == 0 ||
       constant_terms.size() == 0  ||
       equation_matrix.size() != constant_terms.size()){

        TextCtrlResults->ChangeValue("Incorrect data");
        std::cout << "Error, wrong input\n";
        return;
    }

    if(double_option == true){
        int done_iterations;
        std::vector<double> answers = SolveEquation(equation_matrix,
                                                    constant_terms,
                                                    accuracy, iterations, done_iterations);

        if(answers.size() == 0){
            TextCtrlResults->ChangeValue("Incorrect data");
            return;
        }

        std::stringstream output;
        std::stringstream iterations_output;

        for(const double ans : answers){
            output <<std::setprecision(std::numeric_limits<double>::digits10 + 1) << ans << "\n";
        }

        iterations_output << done_iterations;

        if(done_iterations == iterations){
            output << "Reached max iterations, solution propably didn't converge\n";
        }


        TextCtrlResults->ChangeValue(wxString(output.str()));
        TextCtrlIterationsDone->ChangeValue(wxString(iterations_output.str()));

    }
    else{
        std::vector<std::vector<Interval<double>>> equation_matrix_interval= DoubleMatrixToInterval(equation_matrix);
        std::vector<Interval<double>> constant_terms_interval = DoubleVectorToInterval(constant_terms);

        int done_iterations;
        std::vector<Interval<double>> answers = SolveEquation(equation_matrix_interval,
                                                    constant_terms_interval,
                                                    accuracy, iterations, done_iterations);

        if(answers.size() == 0){
            TextCtrlResults->ChangeValue("Incorrect data");
            return;
        }

        std::stringstream output;
        std::stringstream iterations_output;

        for(Interval<double> ans : answers){
            std::string left, right;
            ans.IEndsToStrings(left, right);
            output << left << " : " << right << "\n";
            //output << std::setprecision(std::numeric_limits<double>::digits10 + 1)  << ans.a << " : " << ans.b << "\n";
        }

        iterations_output << done_iterations;

        if(done_iterations == iterations){
            output << "Reached max iterations, solution propably didn't converge\n";
        }


        TextCtrlResults->ChangeValue(wxString(output.str()));
        TextCtrlIterationsDone->ChangeValue(wxString(iterations_output.str()));
    }

}




void solver_appFrame::OnLoadFromFileSelected(wxCommandEvent& event)
{

    wxFileDialog openFileDialog(this, ("Open file with equations"), "", "",
                                "Text files (*.txt)|*.txt", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if(openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxTextFile file;
    file.Open(openFileDialog.GetPath());

    std::stringstream equations;
    std::stringstream constants;

    std::string line;

    for(std::string line = file.GetFirstLine().ToStdString();
        file.Eof()==false;
        line = file.GetNextLine().ToStdString())
    {

        trim(line);
        size_t constant_pos = line.rfind(";");

        std::string coefficients = line.substr(0, constant_pos);
        std::string constant = line.substr(constant_pos+1);

        trim(constant);
        trim(coefficients);


        equations << coefficients << "\n";
        constants << constant << "\n";
    }


    TextCtrlEquations->SetValue(wxString(equations.str()));
    TextCtrlConstants->SetValue(wxString(constants.str()));

}







