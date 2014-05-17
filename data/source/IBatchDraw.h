#ifndef __IBatchDraw_H__
#define __IBatchDraw_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: IBatchDraw.h
// Description	: Defines the IBatchDraw interface.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "IOpenGL.h"
#include "IShaders.h"
#include "IBuffer.h"
#include "ITexture.h"

namespace OpenGL
{
	// Types
				
	// Constants
				
	// Prototypes
	class IBatchDraw
	{
		public:
			IBatchDraw() {};
			virtual ~IBatchDraw() {};

			virtual void AttachShaders(IShaders* _pShaders) = 0;
			virtual void AttachBuffers(IBuffer* _pBuffers) = 0;

			virtual void AttachTextures(ITexture** _ppTextures, GLuint _glCount) = 0;

			virtual void DrawBatch(GLenum _glTopology, GLuint _glFirstVertex, GLsizei _glCount) = 0;
			virtual void DrawIndexedBatch(GLenum _glTopology, GLsizei _glCount, GLenum _glType = GL_UNSIGNED_INT, const GLvoid* _glOffset = 0) = 0;
						
		protected:
		private:
					
		public:
		protected:
		private:
	};
};

#endif // __IBatchDraw_H__
		