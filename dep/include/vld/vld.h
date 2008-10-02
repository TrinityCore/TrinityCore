////////////////////////////////////////////////////////////////////////////////
//  $Id: vld.h,v 1.27 2006/11/12 18:09:20 dmouldin Exp $
//
//  Visual Leak Detector (Version 1.9d) - Import Library Header
//  Copyright (c) 2006 Dan Moulding
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
//  See COPYING.txt for the full terms of the GNU Lesser General Public License.
//
////////////////////////////////////////////////////////////////////////////////

//#pragma once
#ifndef _VLD_H_
#define _VLD_H_

#ifdef _DEBUG

#pragma comment(lib, "vld.lib")

// Force a symbolic reference to the global VisualLeakDetector class object from
// the DLL. This enusres that the DLL is loaded and linked with the program,
// even if no code otherwise imports any of the DLL's exports.
#pragma comment(linker, "/include:__imp_?vld@@3VVisualLeakDetector@@A")

////////////////////////////////////////////////////////////////////////////////
//
//  Visual Leak Detector APIs
//

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// VLDDisable - Disables Visual Leak Detector's memory leak detection at
//   runtime. If memory leak detection is already disabled, then calling this
//   function has no effect.
//
//  Note: In multithreaded programs, this function operates on a per-thread
//    basis. In other words, if you call this function from one thread, then
//    memory leak detection is only disabled for that thread. If memory leak
//    detection is enabled for other threads, then it will remain enabled for
//    those other threads. It was designed to work this way to insulate you,
//    the programmer, from having to ensure thread synchronization when calling
//    VLDEnable() and VLDDisable(). Without this, calling these two functions
//    unsychronized could result in unpredictable and unintended behavior.
//    But this also means that if you want to disable memory leak detection
//    process-wide, then you need to call this function from every thread in
//    the process.
//
//  Return Value:
//
//    None.
//

__declspec(dllimport) void VLDDisable ();

// VLDEnable - Enables Visual Leak Detector's memory leak detection at runtime.
//   If memory leak detection is already enabled, which it is by default, then
//   calling this function has no effect.
//
//  Note: In multithreaded programs, this function operates on a per-thread
//    basis. In other words, if you call this function from one thread, then
//    memory leak detection is only enabled for that thread. If memory leak
//    detection is disabled for other threads, then it will remain disabled for
//    those other threads. It was designed to work this way to insulate you,
//    the programmer, from having to ensure thread synchronization when calling
//    VLDEnable() and VLDDisable(). Without this, calling these two functions
//    unsychronized could result in unpredictable and unintended behavior.
//    But this also means that if you want to enable memory leak detection
//    process-wide, then you need to call this function from every thread in
//    the process.
//
//  Return Value:
//
//    None.
//

__declspec(dllimport) void VLDEnable ();

#ifdef __cplusplus
}
#endif // __cplusplus

#else // !_DEBUG

#define VLDEnable()
#define VLDDisable()

#endif // _DEBUG

#endif // _VLD_H_
