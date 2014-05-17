//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBuffer.cpp
// Description	: Implements the CBuffer class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "CBuffer.h"
			
// This Includes

namespace OpenGL
{	
	// Static Variables
				
	// Static Function Prototypes
				
	// Implementation
	CBuffer::CBuffer()
	{
		GL::glGenBuffers(1, &m_glBuffer);		
	}
				
	CBuffer::~CBuffer()
	{
		GL::glDeleteBuffers(1, &m_glBuffer);
	}

	void CBuffer::Map(void* _pData, GLuint _glSize, GLenum _glUsage, GLenum _glTarget)
	{
		m_glTarget = _glTarget;
		Bind();
		GL::glBufferData(_glTarget, _glSize, _pData, _glUsage);
	}

	void CBuffer::Bind()
	{
		GL::glBindBuffer(m_glTarget, m_glBuffer);
	}
};
