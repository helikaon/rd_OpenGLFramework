//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: system.h
// Description	: Defines the CSystem class.
// Author		: Rian Drake
// Mail			: rian.drake@mediadesign.school.nz
//

#pragma once

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#define WIN32_LEAN_AND_MEAN

// Library Includes
#include <Windows.h>

// Local Includes
#include "IApplication.h"
#include "IOpenGL.h"

namespace Application
{
	// Types

	// Constants

	// Prototypes
	class CSystem
	{
		// Member Functions
	public:
		// Constructors/Destructors
		CSystem();
		~CSystem();

		// Methods
		bool Initialise();
		void Shutdown();
		void Run();

		LRESULT CALLBACK MessageHandler(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam);

	protected:
	private:
		bool Frame();

		// Member Variables
	public:
	protected:
	private:
		LPCWSTR m_psApplicationName;
		HINSTANCE m_hInstance;
		HWND m_hWnd;

		IApplication* m_pApplication;

		int m_iWidth, m_iHeight;
		bool m_bFullscreen;

		GLFWwindow* window;
	};
};

#endif // __SYSTEM_H__