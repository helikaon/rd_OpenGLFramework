//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: system.cpp
// Description	: Implements the CSystem class.
// Author		: Rian Drake
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "CCubeApplication.h"

// This Includes
#include "CSystem.h"

namespace Application
{
	// Static Variables
	static CSystem* ApplicationHandle = 0;

	// Static Function Prototypes

	// Implementation
	LRESULT CALLBACK WndProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
	{
		switch(_uiMsg)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			break;

		default:
			return ApplicationHandle->MessageHandler(_hWnd, _uiMsg, _wParam, _lParam);
		}

		return 0;
	}

	CSystem::CSystem():
		m_pApplication(0),
		m_bFullscreen(false)
	{

	}

	CSystem::~CSystem()
	{

	}

	bool CSystem::Initialise()
	{
		glfwInit();
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		
		if(m_bFullscreen)
			window = glfwCreateWindow(1920, 1080, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
		else
			window = glfwCreateWindow(1920, 1080, "OpenGL", nullptr, nullptr); // Windowed
		
		glfwMakeContextCurrent(window);

		GL::LoadExtensions();

		m_pApplication = new CCubeApplication;

		if(!m_pApplication->Initialise())
		{
			return false;
		}

		return true;
	}

	void CSystem::Shutdown()
	{
		if(m_pApplication)
			m_pApplication->Shutdown();
		
		glfwTerminate();

		delete m_pApplication;
		m_pApplication = 0;
	}

	void CSystem::Run()
	{
		glClearColor(1.0f, 0.5f, 0.5f, 1.0f);

		while(!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);

			glfwSwapBuffers(window);
			glfwPollEvents();
			
			glClear(GL_COLOR_BUFFER_BIT);
			m_pApplication->Frame();
		}
	}

	LRESULT CALLBACK CSystem::MessageHandler(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
	{	
		return DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam);
	}

	bool CSystem::Frame()
	{
		return true;
	}
};