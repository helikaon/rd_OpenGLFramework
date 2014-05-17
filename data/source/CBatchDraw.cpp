//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBatchDraw.cpp
// Description	: Implements the CBatchDraw class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "CBatchDraw.h"
#include "CShaders.h"

// This Includes

namespace OpenGL
{
	// Static Variables

	// Static Function Prototypes

	// Implementation
	CBatchDraw::CBatchDraw():
		m_ppBuffers(0),
		m_pShaders(0),
		m_uiNumBuffers(0),
		m_ppTextures(0),
		m_uiNumTextures(0)
	{

	}

	CBatchDraw::~CBatchDraw()
	{
		for(unsigned ui = 0; ui < m_uiNumTextures; ++ui)
		{
			GLuint glTexture = m_ppTextures[ui]->GetTexture();
			glDeleteTextures(1, &glTexture);
		}
	}

	void CBatchDraw::AttachShaders(IShaders* _pShaders)
	{
		m_pShaders = _pShaders;
	}

	void CBatchDraw::AttachBuffers(IBuffer* _pBuffers)
	{
		IBuffer** ppBuffers = new IBuffer*[m_uiNumBuffers + 1];

		for(unsigned ui = 0; ui < m_uiNumBuffers; ++ui)
			ppBuffers[ui] = m_ppBuffers[ui];
		
		ppBuffers[m_uiNumBuffers] = _pBuffers;

		delete[] m_ppBuffers;
		m_ppBuffers = ppBuffers;

		++m_uiNumBuffers;
	}

	void CBatchDraw::DrawBatch(GLenum _glTopology, GLuint _glFirstVertex, GLsizei _glCount)
	{
		m_pShaders->UseProgram();

		for(unsigned ui = 0; ui < m_uiNumBuffers; ++ui)
			m_ppBuffers[ui]->Bind();

		glDrawArrays(_glTopology, _glFirstVertex, _glCount);
	}

	void CBatchDraw::DrawIndexedBatch(GLenum _glTopology, GLsizei _glCount, GLenum _glType, const GLvoid* _glOffset)
	{
		m_pShaders->UseProgram();

		for(unsigned ui = 0; ui < m_uiNumBuffers; ++ui)
			m_ppBuffers[ui]->Bind();

		glDrawElements(_glTopology, _glCount, _glType, _glOffset);
	}
	
	void CBatchDraw::AttachTextures(ITexture** _ppTextures, GLuint _glCount)
	{
		m_ppTextures = _ppTextures;
		m_uiNumTextures = 0;
	}
};