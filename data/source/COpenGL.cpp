//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: IOpenGL.cpp
// Description	: Implements the OpenGL extensions.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "IOpenGL.h"
			
// This Includes

namespace OpenGL
{	
	// Static Variables
	PFNWGLCHOOSEPIXELFORMATARBPROC IOpenGL::wglChoosePixelFormatARB = 0;
	PFNWGLCREATECONTEXTATTRIBSARBPROC IOpenGL::wglCreateContextAttribsARB = 0;
	PFNWGLSWAPINTERVALEXTPROC IOpenGL::wglSwapIntervalEXT = 0;
	PFNGLATTACHSHADERPROC IOpenGL::glAttachShader = 0;
	PFNGLBINDBUFFERPROC IOpenGL::glBindBuffer = 0;
	PFNGLBINDVERTEXARRAYPROC IOpenGL::glBindVertexArray = 0;
	PFNGLBUFFERDATAPROC IOpenGL::glBufferData = 0;
	PFNGLCOMPILESHADERPROC IOpenGL::glCompileShader = 0;
	PFNGLCREATEPROGRAMPROC IOpenGL::glCreateProgram = 0;
	PFNGLCREATESHADERPROC IOpenGL::glCreateShader = 0;
	PFNGLDELETEBUFFERSPROC IOpenGL::glDeleteBuffers = 0;
	PFNGLDELETEPROGRAMPROC IOpenGL::glDeleteProgram = 0;
	PFNGLDELETESHADERPROC IOpenGL::glDeleteShader = 0;
	PFNGLDELETEVERTEXARRAYSPROC IOpenGL::glDeleteVertexArrays = 0;
	PFNGLDETACHSHADERPROC IOpenGL::glDetachShader = 0;
	PFNGLENABLEVERTEXATTRIBARRAYPROC IOpenGL::glEnableVertexAttribArray = 0;
	PFNGLGENBUFFERSPROC IOpenGL::glGenBuffers = 0;
	PFNGLGENVERTEXARRAYSPROC IOpenGL::glGenVertexArrays = 0;
	PFNGLGETATTRIBLOCATIONPROC IOpenGL::glGetAttribLocation = 0;
	PFNGLGETPROGRAMINFOLOGPROC IOpenGL::glGetProgramInfoLog = 0;
	PFNGLGETPROGRAMIVPROC IOpenGL::glGetProgramiv = 0;
	PFNGLGETSHADERINFOLOGPROC IOpenGL::glGetShaderInfoLog = 0;
	PFNGLGETSHADERIVPROC IOpenGL::glGetShaderiv = 0;
	PFNGLLINKPROGRAMPROC IOpenGL::glLinkProgram = 0;
	PFNGLSHADERSOURCEPROC IOpenGL::glShaderSource = 0;
	PFNGLUSEPROGRAMPROC IOpenGL::glUseProgram = 0;
	PFNGLVERTEXATTRIBPOINTERPROC IOpenGL::glVertexAttribPointer = 0;
	PFNGLBINDATTRIBLOCATIONPROC IOpenGL::glBindAttribLocation = 0;
	PFNGLGETUNIFORMLOCATIONPROC IOpenGL::glGetUniformLocation = 0;
	PFNGLUNIFORMMATRIX4FVPROC IOpenGL::glUniformMatrix4fv = 0;
	PFNGLACTIVETEXTUREPROC IOpenGL::glActiveTexture = 0;
	PFNGLUNIFORM1IPROC IOpenGL::glUniform1i = 0;
	PFNGLGENERATEMIPMAPPROC IOpenGL::glGenerateMipmap = 0;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC IOpenGL::glDisableVertexAttribArray = 0;
	PFNGLUNIFORM3FVPROC IOpenGL::glUniform3fv = 0;
	PFNGLUNIFORM4FVPROC IOpenGL::glUniform4fv = 0;
				
	// Static Function Prototypes
				
	// Implementation
	bool IOpenGL::LoadExtensions()
	{
		// Load the OpenGL extensions that this application will be using.
		wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
		if(!wglChoosePixelFormatARB)
		{
			return false;
		}

		wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
		if(!wglCreateContextAttribsARB)
		{
			return false;
		}

		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
		if(!wglSwapIntervalEXT)
		{
			return false;
		}

		glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
		if(!glAttachShader)
		{
			return false;
		}

		glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
		if(!glBindBuffer)
		{
			return false;
		}

		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
		if(!glBindVertexArray)
		{
			return false;
		}

		glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
		if(!glBufferData)
		{
			return false;
		}

		glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
		if(!glCompileShader)
		{
			return false;
		}

		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
		if(!glCreateProgram)
		{
			return false;
		}

		glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
		if(!glCreateShader)
		{
			return false;
		}

		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
		if(!glDeleteBuffers)
		{
			return false;
		}

		glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
		if(!glDeleteProgram)
		{
			return false;
		}

		glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
		if(!glDeleteShader)
		{
			return false;
		}

		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
		if(!glDeleteVertexArrays)
		{
			return false;
		}

		glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
		if(!glDetachShader)
		{
			return false;
		}

		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
		if(!glEnableVertexAttribArray)
		{
			return false;
		}

		glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
		if(!glGenBuffers)
		{
			return false;
		}

		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
		if(!glGenVertexArrays)
		{
			return false;
		}

		glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
		if(!glGetAttribLocation)
		{
			return false;
		}

		glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
		if(!glGetProgramInfoLog)
		{
			return false;
		}

		glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
		if(!glGetProgramiv)
		{
			return false;
		}

		glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
		if(!glGetShaderInfoLog)
		{
			return false;
		}

		glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
		if(!glGetShaderiv)
		{
			return false;
		}

		glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
		if(!glLinkProgram)
		{
			return false;
		}

		glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
		if(!glShaderSource)
		{
			return false;
		}

		glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
		if(!glUseProgram)
		{
			return false;
		}

		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
		if(!glVertexAttribPointer)
		{
			return false;
		}

		glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
		if(!glBindAttribLocation)
		{
			return false;
		}

		glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
		if(!glGetUniformLocation)
		{
			return false;
		}

		glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
		if(!glUniformMatrix4fv)
		{
			return false;
		}

		glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
		if(!glActiveTexture)
		{
			return false;
		}

		glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
		if(!glUniform1i)
		{
			return false;
		}

		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
		if(!glGenerateMipmap)
		{
			return false;
		}

		glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
		if(!glDisableVertexAttribArray)
		{
			return false;
		}

		glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
		if(!glUniform3fv)
		{
			return false;
		}

		glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
		if(!glUniform4fv)
		{
			return false;
		}

		return true;
	}
};
