/***************************************************************
 * Name:      solver_appApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mateusz Oleszek (motmen001@gmail.com)
 * Created:   2021-03-19
 * Copyright: Mateusz Oleszek (paraon.xyz)
 * License:
 **************************************************************/

#include "solver_appApp.h"

//(*AppHeaders
#include "solver_appMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(solver_appApp);

bool solver_appApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	solver_appFrame* Frame = new solver_appFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
