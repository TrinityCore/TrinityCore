//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#include <stdlib.h>
#include <string.h>
#include "RecastAlloc.h"

static void *rcAllocDefault(int size, rcAllocHint)
{
	return malloc(size);
}

static void rcFreeDefault(void *ptr)
{
	free(ptr);
}

static rcAllocFunc* sRecastAllocFunc = rcAllocDefault;
static rcFreeFunc* sRecastFreeFunc = rcFreeDefault;

void rcAllocSetCustom(rcAllocFunc *allocFunc, rcFreeFunc *freeFunc)
{
	sRecastAllocFunc = allocFunc ? allocFunc : rcAllocDefault;
	sRecastFreeFunc = freeFunc ? freeFunc : rcFreeDefault;
}

void* rcAlloc(int size, rcAllocHint hint)
{
	return sRecastAllocFunc(size, hint);
}

void rcFree(void* ptr)
{
	if (ptr)
		sRecastFreeFunc(ptr);
}


void rcIntArray::resize(int n)
{
	if (n > m_cap)
	{
		if (!m_cap) m_cap = n;
		while (m_cap < n) m_cap *= 2;
		int* newData = (int*)rcAlloc(m_cap*sizeof(int), RC_ALLOC_TEMP);
		if (m_size && newData) memcpy(newData, m_data, m_size*sizeof(int));
		rcFree(m_data);
		m_data = newData;
	}
	m_size = n;
}

