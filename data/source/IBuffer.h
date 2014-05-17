#ifndef __IBuffer_H__
#define __IBuffer_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: IBuffer.h
// Description	: Defines the IBuffer interface.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "IOpenGL.h"

namespace OpenGL
{
	// Types
				
	// Constants
				
	// Prototypes
	class IBuffer
	{
		public:
			IBuffer() {};
			virtual ~IBuffer() {};

			virtual void Map(void* _pData, GLuint _glSize, GLenum _glUsage, GLenum _glTarget) = 0;

			virtual void Bind() = 0;
						
		protected:
		private:
					
		public:
		protected:
		private:
	};
};

#endif // __IBuffer_H__
		