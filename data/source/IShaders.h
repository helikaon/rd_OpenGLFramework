#ifndef __IShaders_H__
#define __IShaders_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: IShaders.h
// Description	: Defines the IShaders interface.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
#include <string>
			
// Local Includes

namespace OpenGL
{
	// Types
	enum EShaders
	{
		SHADERS_VERTEX, SHADERS_GEOMETRY, SHADERS_FRAGMENT, SHADERS_MAX
	};
				
	// Constants
				
	// Prototypes
	class IShaders
	{
		public:
			IShaders() {};
			virtual ~IShaders() {};

			virtual void AttachAttribute(const char* _pAttribute, GLuint _glSize, GLenum _glType, GLsizei _glStride, GLvoid* _glOffset, GLboolean _glNormalized = false) = 0;

			virtual void AttachShader(EShaders _eShader, const char* _pFile) = 0;
			virtual void AttachUniform(std::string _sName) = 0;
			virtual GLint GetUniform(std::string _sName) = 0;

			virtual void LinkProgram() = 0;

			virtual void UseProgram() = 0;
						
		protected:
		private:
					
		public:
		protected:
		private:
	};
};

#endif // __IShaders_H__
		