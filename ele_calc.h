
// ele_calc.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CelecalcApp:
// See ele_calc.cpp for the implementation of this class
//

class CelecalcApp : public CWinApp
{
public:
	CelecalcApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CelecalcApp theApp;
