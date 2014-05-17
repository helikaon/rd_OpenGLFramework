#ifndef __CShaders_H__
#define __CShaders_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CShaders.h
// Description	: Defines the CShaders class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
#include <map>
			
// Local Includes
#include "IOpenGL.h"
#include "IShaders.h"
#include <string>

namespace OpenGL
{
	// Types
				
	// Constants
				
	// Prototypes
	class CShaders : public IShaders
	{
		public:
			CShaders();
			~CShaders();

			void AttachAttribute(
				const char* _pAttribute, 
				GLuint _glSize, 
				GLenum _glType, 
				GLsizei _glStride, 
				GLvoid* _glOffset, 
				GLboolean _glNormalized = false);

			void AttachShader(EShaders _eShader, const char* _pFile);
			void AttachUniform(std::string _sName);
			GLint GetUniform(std::string _sName);

			void LinkProgram();

			void UseProgram();

		protected:
			void ReadShader(const char* _pFile, std::string& _rShader);

		private:
					
		public:
		protected:
		private:
			GLuint
				m_glShaderProgram,
				m_glVertexArrayObject;

			std::map<std::string, GLint> m_glUniforms;
	};
};

#endif // __Shaders_H__