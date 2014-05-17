//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CubeApplication.cpp
// Description	: Implements the CCubeApplication class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "CCubeApplication.h"
#include "CBatchDraw.h"
#include "CShaders.h"
#include "CBuffer.h"
#include "IOpenGL.h"
			
// This Includes
			
namespace Application
{
	// Static Variables
			
	// Static Function Prototypes
			
	// Implementation
	CCubeApplication::CCubeApplication():
		m_f3Eye(0,0,-1)
	{
		m_pBatch[0] = 0;
		m_pBatch[1] = 0;
	}
			
	CCubeApplication::~CCubeApplication()
	{
		Shutdown();
	}
		
	bool CCubeApplication::Initialise()
	{
		return InitialiseBatch();
	}

	bool CCubeApplication::InitialiseBatch()
	{
		using namespace OpenGL;
		m_pBatch[0] = new CBatchDraw();
		m_pBatch[1] = new CBatchDraw();

		float f = 0.5f;
		
		float vertices[] =
		{
			-f, -f, -f,	0,0,0, 
			-f, -f,  f,	0,0,1, 
			-f,  f, -f,	0,1,0, 
			-f,  f,  f,	0,1,1,  
			 f, -f, -f,	1,0,0, 
			 f, -f,  f,	1,0,1, 
			 f,  f, -f,	1,1,0,
			 f,  f,  f,	1,1,1  
		};

		float vertices2[] =
		{
			-f + 1, -f + 1, -f,	1,0,0, 
			-f + 1, -f + 1,  f,	1,0,1, 
			-f + 1,  f + 1, -f,	1,1,0, 
			-f + 1,  f + 1,  f,	1,1,1,  
			 f + 1, -f + 1, -f,	0,0,0,
			 f + 1, -f + 1,  f,	0,0,1,
			 f + 1,  f + 1, -f,	0,1,0,
			 f + 1,  f + 1,  f,	0,1,1,
		};

		GLuint elements[] =
		{
			// FRONT
			0,4,2,
			2,4,6,
			
			// BACK
			1,3,5,
			5,3,7,
			
			// LEFT
			1,0,3,
			3,0,2,
			
			// RIGHT
			4,5,6,
			6,5,7,

			// TOP
			2,6,3,
			3,6,7,

			// BOTTOM
			0,1,4,
			4,1,5,
		};

		buffers[0] = new CBuffer;
		buffers[1] = new CBuffer;
		buffers[2] = new CBuffer;

		buffers[0]->Map(vertices, sizeof(vertices), GL_STATIC_DRAW, GL_ARRAY_BUFFER);
		buffers[1]->Map(vertices2, sizeof(vertices2), GL_STATIC_DRAW, GL_ARRAY_BUFFER);
		buffers[2]->Map(elements, sizeof(elements), GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER);

		m_pShaders = new CShaders;
		m_pShaders->AttachShader(EShaders::SHADERS_VERTEX, "data/source/glsl/cubeshaders_vs.glsl");
		m_pShaders->AttachShader(EShaders::SHADERS_FRAGMENT, "data/source/glsl/cubeshaders_ps.glsl");
		m_pShaders->LinkProgram();
		m_pShaders->AttachAttribute("position", 3, GL_FLOAT, 6*sizeof(float), 0, false);
		m_pShaders->AttachAttribute("Color", 3, GL_FLOAT, 6*sizeof(float), (void*)(sizeof(float)*3), false);
		m_pShaders->AttachUniform("triangleColor");
		m_pShaders->AttachUniform("matWVP");

		GLint glMatUniform = m_pShaders->GetUniform("matWVP");
		GLint glUniform = m_pShaders->GetUniform("triangleColor");

		float color[3] = { 1,1,1 };
		GL::glUniform3fv(glUniform, 1, color);

		m_pBatch[0]->AttachBuffers(buffers[0]);
		m_pBatch[0]->AttachBuffers(buffers[2]);
		m_pBatch[0]->AttachShaders(m_pShaders);
		m_pBatch[1]->AttachBuffers(buffers[1]);
		m_pBatch[1]->AttachBuffers(buffers[2]);
		m_pBatch[1]->AttachShaders(m_pShaders);

		m_matMatrices[MATRIX_PROJ] = glm::perspective(glm::radians(45.f), 800.f/600.f, 0.1f, 1000.0f);

		return true;
	}

	bool CCubeApplication::Update()
	{
		static float frame = 0.0f;
		frame += 0.0001f;

		m_f3Eye.x = sin(frame) * 5;
		m_f3Eye.y = sin(frame) * 5;
		m_f3Eye.z = cos(frame) * 5;
		
		m_matMatrices[MATRIX_VIEW] = glm::lookAt(m_f3Eye, glm::vec3(0,0,0), glm::vec3(0,1,0));
		m_matMatrices[MATRIX_WVP] = m_matMatrices[MATRIX_PROJ] * m_matMatrices[MATRIX_VIEW] * m_matMatrices[MATRIX_WORLD];

		GL::glUniformMatrix4fv(m_pShaders->GetUniform("matWVP"), 1, false, glm::value_ptr(m_matMatrices[MATRIX_WVP]));

		return true;
	}

	bool CCubeApplication::Draw()
	{
		if(GetAsyncKeyState('Q') & 0x8000)
			m_pBatch[0]->DrawIndexedBatch(GL_TRIANGLES, 36);
		else
			m_pBatch[1]->DrawIndexedBatch(GL_TRIANGLES, 36);

		return true;
	}

	void CCubeApplication::Shutdown()
	{
		delete m_pBatch[0];
		m_pBatch[0] = 0;
		delete m_pBatch[1];
		m_pBatch[1] = 0;

		delete m_pShaders;
		m_pShaders = 0;

		delete buffers[0];
		buffers[0] = 0;
		delete buffers[1];
		buffers[1] = 0;
		delete buffers[2];
		buffers[2] = 0;
	}

	bool CCubeApplication::Frame()
	{
		Update();
		Draw();
		return true;
	}
};