#ifndef __CubeApplication_H__
#define __CubeApplication_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CubeApplication.h
// Description	: Defines the CCubeApplication class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "IApplication.h"
#include "IBatchDraw.h"
#include "IShaders.h"
#include "IBuffer.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Application
{
	// Types
	enum EMatricies
	{
		MATRIX_PROJ,
		MATRIX_VIEW,
		MATRIX_WORLD,
		MATRIX_WVP,
		MATRIX_MAX
	};
			
	// Constants
			
	// Prototypes
	class CCubeApplication : public IApplication
	{
		public:
			CCubeApplication();
			~CCubeApplication();

			bool Initialise();
			void Shutdown();
			bool Frame();
					
		protected:
			bool Update();
			bool Draw();

			bool InitialiseBatch();

		private:
				
		public:
		protected:
		private:
			OpenGL::IBatchDraw* m_pBatch[2];

			glm::mat4x4 m_matMatrices[MATRIX_MAX];

			OpenGL::IShaders* m_pShaders;

			OpenGL::IBuffer* buffers[3];

			glm::vec3 m_f3Eye;
	};
};

#endif // __CubeApplication_H__
		