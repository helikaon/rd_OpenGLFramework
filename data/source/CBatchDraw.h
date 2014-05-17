#ifndef __CBatchDraw_H__
#define __CBatchDraw_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBatchDraw.h
// Description	: Defines the CBatchDraw class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes

// Local Includes
#include "IBatchDraw.h"
#include "IShaders.h"
#include "IBuffer.h"
#include "ITexture.h"
			
namespace OpenGL
{
	// Types
			
	// Constants
			
	// Prototypes
	class CBatchDraw : public IBatchDraw
	{
		public:
			CBatchDraw();
			~CBatchDraw();

			void AttachShaders(IShaders* _pShaders);
			void AttachBuffers(IBuffer* _pBuffers);

			void DrawBatch(GLenum _glTopology, GLuint _glFirstVertex, GLsizei _glCount);
			void DrawIndexedBatch(GLenum _glTopology, GLsizei _glCount, GLenum _glType = GL_UNSIGNED_INT, const GLvoid* _glOffset = 0);

			void AttachTextures(ITexture** _ppTextures, GLuint _glCount);
					
		protected:
		private:
				
		public:
		protected:
		private:
			IBuffer** m_ppBuffers;
			GLuint m_uiNumBuffers;

			ITexture** m_ppTextures;
			GLuint m_uiNumTextures;

			IShaders* m_pShaders;
	};
};

#endif // __BatchDraw_H__