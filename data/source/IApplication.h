#ifndef __Application_H__
#define __Application_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: Application.h
// Description	: Defines the IApplication interface.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
			
namespace Application
{
	// Types
			
	// Constants
			
	// Prototypes
	class IApplication
	{
		public:
			IApplication() {};
			virtual ~IApplication() {};

			virtual bool Initialise() = 0;
			virtual void Shutdown() = 0;
			virtual bool Frame() = 0;
					
		protected:
		private:
				
		public:
		protected:
		private:
	};
};
		
#endif // __Application_H__