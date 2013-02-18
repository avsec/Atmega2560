//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Placement new

#ifndef _ATMEGA2560_CORE_MEMORY_NEW_H_
#define _ATMEGA2560_CORE_MEMORY_NEW_H_

#include <stddef.h>

void * operator new (size_t, void *);

#endif // _ARION_CORE_MEMORY_NEW_H_
