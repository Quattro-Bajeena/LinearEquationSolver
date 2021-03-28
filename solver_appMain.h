/***************************************************************
 * Name:      solver_appMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mateusz Oleszek (motmen001@gmail.com)
 * Created:   2021-03-19
 * Copyright: Mateusz Oleszek (paraon.xyz)
 * License:
 **************************************************************/

#include "solver.h"

#ifndef SOLVER_APPMAIN_H
#define SOLVER_APPMAIN_H


#include <wx/valtext.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/textfile.h>

//(*Headers(solver_appFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class solver_appFrame: public wxFrame
{
    public:

        solver_appFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~solver_appFrame();

    private:

        //(*Handlers(solver_appFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnSolveButtonClick(wxCommandEvent& event);
        void OnLoadFromFileSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(solver_appFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL5;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(solver_appFrame)
        wxButton* ButtonSolve;
        wxMenuItem* MenuItem3;
        wxRadioButton* RadioButtonDouble;
        wxRadioButton* RadioButtonInterval;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlAccuracy;
        wxTextCtrl* TextCtrlConstants;
        wxTextCtrl* TextCtrlEquations;
        wxTextCtrl* TextCtrlIterations;
        wxTextCtrl* TextCtrlIterationsDone;
        wxTextCtrl* TextCtrlResults;
        //*)
        DECLARE_EVENT_TABLE()
};

#endif // SOLVER_APPMAIN_H
