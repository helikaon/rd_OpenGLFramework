#ifndef __ITexture_H__
#define __ITexture_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: ITexture.h
// Description	: Defines the ITexture interface.
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
	class ITexture
	{
		public:
			ITexture() {};
			virtual ~ITexture() {};

			void Initialise(const char* _pcFilename);
			virtual GLuint GetTexture() = 0;
						
		protected:
		private:
					
		public:
		protected:
		private:
	};
};

#endif // __ITexture_H__
		