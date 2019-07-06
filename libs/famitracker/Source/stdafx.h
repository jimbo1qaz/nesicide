/*
** FamiTracker - NES/Famicom sound tracker
** Copyright (C) 2005-2014  Jonathan Liss
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful, 
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
** Library General Public License for more details.  To obtain a 
** copy of the GNU Library General Public License, write to the Free 
** Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** Any permitted reproduction of these routines, in whole or in part,
** must bear this legend.
*/

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#include "cqtmfc.h"

// Releasing pointers
#define SAFE_RELEASE(p) \
	if (p != NULL) { \
		delete p;	\
		p = NULL;	\
	}	\

#define SAFE_RELEASE_ARRAY(p) \
	if (p != NULL) { \
		delete [] p;	\
		p = NULL;	\
	}	\

#include "res/resource.h"
#define DEBUG_NEW new

// Calling member function
#define CALL_MEMBER_FN(obj, ptr) ((obj)->*(ptr))

#ifdef TRACE
#undef TRACE
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
template <typename... T>
bool _trace(TCHAR *format, T... args)
{
	TCHAR buffer[1000];
	_sntprintf_s(buffer, sizeof(buffer), _TRUNCATE, format, args...);
	OutputDebugString(buffer);

	return true;
}
#define TRACE _trace
#else
#define TRACE(...) // no-op
#endif


#include "name.h"
