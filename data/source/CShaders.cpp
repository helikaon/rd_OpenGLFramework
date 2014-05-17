//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CShaders.cpp
// Description	: Implements the CShaders class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes
#include <fstream>
#include <cassert>

// Local Includes
#include "CShaders.h"
#include "IOpenGL.h"

// This Includes

namespace OpenGL
{	
	// Static Variables

	// Static Function Prototypes

	// Implementation
	CShaders::CShaders():
		m_glShaderProgram(0),
		m_glVertexArrayObject(0)
	{
		GL::glGenVertexArrays(1, &m_glVertexArrayObject);
		GL::glBindVertexArray(m_glVertexArrayObject);

		m_glShaderProgram = GL::glCreateProgram();
	}

	CShaders::~CShaders()
	{
		GL::glDeleteVertexArrays(1, &m_glVertexArrayObject);
		GL::glDeleteProgram(m_glShaderProgram);
	}

	void CShaders::AttachAttribute(const char* _pAttribute, GLuint _glSize, GLenum _glType, GLsizei _glStride, GLvoid* _glOffset, GLboolean _glNormalized)
	{
		GLint glAttribute = GL::glGetAttribLocation(m_glShaderProgram, _pAttribute);

		if(glAttribute == -1)
		{
			MessageBox(0, L"Could not find attribute.", L"Shader Error", 0);
			PostQuitMessage(0);
		}

		GL::glEnableVertexAttribArray(glAttribute);
		GL::glVertexAttribPointer(glAttribute, _glSize, _glType, _glNormalized, _glStride, _glOffset);
	}

	void CShaders::AttachUniform(std::string _sName)
	{
		m_glUniforms[_sName] = GL::glGetUniformLocation(m_glShaderProgram, _sName.c_str());
	}

	GLint CShaders::GetUniform(std::string _sName)
	{
		return m_glUniforms[_sName];
	}

	void CShaders::LinkProgram()
	{
		GL::glLinkProgram(m_glShaderProgram);
		GL::glUseProgram(m_glShaderProgram);
	}

	void CShaders::UseProgram()
	{
		GL::glUseProgram(m_glShaderProgram);
	}

	void CShaders::AttachShader(EShaders _eShader, const char* _pFile)
	{
		GLuint glShader = 0;

		switch(_eShader)
		{
		case SHADERS_VERTEX:
			glShader = GL::glCreateShader(GL_VERTEX_SHADER);
			break;
		case SHADERS_FRAGMENT:
			glShader = GL::glCreateShader(GL_FRAGMENT_SHADER);
			break;
		default:assert(0);
		}

		std::string sShader;
		ReadShader(_pFile, sShader);
		const char* pShader = sShader.c_str();

		GL::glShaderSource(glShader, 1, &pShader, NULL);
		GL::glCompileShader(glShader);

		GLint status = 0;
		GL::glGetShaderiv(glShader, GL_COMPILE_STATUS, &status);

		if(!status)
		{
			char buffer[512];
			GL::glGetShaderInfoLog(glShader, 512, NULL, buffer);

			MessageBox(0, L"Shader failed to compile.", L"Shader Error", 0);
			PostQuitMessage(0);
		}
		
		GL::glAttachShader(m_glShaderProgram, glShader);
	}

	void CShaders::ReadShader(const char* _pFile, std::string& _rsShader)
	{
		std::fstream myFile(_pFile);
		std::string sLine, sShader;

		if(!myFile || myFile.bad())
		{
			MessageBox(0, L"Shader file was not found.", L"Shader Error", 0);
			PostQuitMessage(0);
		}

		while(!myFile.eof())
		{
			std::getline(myFile, sLine);
			sShader += sLine + '\n';
		}

		_rsShader = sShader.c_str();
	}
};
