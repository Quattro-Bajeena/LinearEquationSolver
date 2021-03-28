/***************************************************************
 * Name:      solver_appApp.h
 * Purpose:   Defines Application Class
 * Author:    Mateusz Oleszek (motmen001@gmail.com)
 * Created:   2021-03-19
 * Copyright: Mateusz Oleszek (paraon.xyz)
 * License:
 **************************************************************/

#ifndef SOLVER_APPAPP_H
#define SOLVER_APPAPP_H

#include <wx/app.h>

class solver_appApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SOLVER_APPAPP_H
