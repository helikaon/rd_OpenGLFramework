//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CTexture.cpp
// Description	: Implements the CTexture class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "CTexture.h"
			
// This Includes

namespace OpenGL
{	
	// Static Variables
				
	// Static Function Prototypes
				
	// Implementation
	CTexture::CTexture()
	{
				
	}
				
	CTexture::~CTexture()
	{
		glDeleteTextures(1, &m_glTexture);
	}

	void CTexture::Initialise(const char* _pcFilename)
	{
		m_glTexture = SOIL_load_OGL_texture(
			_pcFilename, 
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	}

	GLuint CTexture::GetTexture()
	{
		return m_glTexture;
	}
};
