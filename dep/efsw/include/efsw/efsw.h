/**
	@author Sepul Sepehr Taghdisian

	Copyright (c) 2013 Martin Lucas Golini

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.

	This software is a fork of the "simplefilewatcher" by James Wynn (james@jameswynn.com)
	http://code.google.com/p/simplefilewatcher/ also MIT licensed.
*/
/** This is the C API wrapper of EFSW */
#ifndef ESFW_H
#define ESFW_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
	#ifdef EFSW_DYNAMIC
		// Windows platforms
		#ifdef EFSW_EXPORTS
			// From DLL side, we must export
			#define EFSW_API __declspec(dllexport)
		#else
			// From client application side, we must import
			#define EFSW_API __declspec(dllimport)
		#endif
	#else
		// No specific directive needed for static build
		#ifndef EFSW_API
		#define EFSW_API
		#endif
	#endif
#else
	#if ( __GNUC__ >= 4 ) && defined( EFSW_EXPORTS )
		#define EFSW_API __attribute__ ((visibility("default")))
	#endif

	// Other platforms don't need to define anything
	#ifndef EFSW_API
	#define EFSW_API
	#endif
#endif

/// Type for a watch id
typedef long efsw_watchid;

/// Type for watcher
typedef void* efsw_watcher;

enum efsw_action
{
	EFSW_ADD = 1,		/// Sent when a file is created or renamed
	EFSW_DELETE = 2,	/// Sent when a file is deleted or renamed
	EFSW_MODIFIED = 3,	/// Sent when a file is modified
	EFSW_MOVED = 4		/// Sent when a file is moved
};

enum efsw_error
{
	EFSW_NOTFOUND		= -1,
	EFSW_REPEATED		= -2,
	EFSW_OUTOFSCOPE		= -3,
	EFSW_NOTREADABLE	= -4,
	EFSW_REMOTE			= -5,
	EFSW_UNSPECIFIED	= -6
};

/// Basic interface for listening for file events.
typedef void (*efsw_pfn_fileaction_callback) (
		efsw_watcher watcher,
		efsw_watchid watchid,
		const char* dir,
		const char* filename,
		enum efsw_action action,
		const char* old_filename,
		void* param
);

/**
 * Creates a new file-watcher
 * @param generic_mode Force the use of the Generic file watcher
 */
efsw_watcher EFSW_API efsw_create(int generic_mode);

/// Release the file-watcher and unwatch any directories
void EFSW_API efsw_release(efsw_watcher watcher);

/// Retreive last error occured by file-watcher
EFSW_API const char* efsw_getlasterror();

/// Add a directory watch. Same as the other addWatch, but doesn't have recursive option.
/// For backwards compatibility.
/// On error returns WatchID with Error type.
efsw_watchid EFSW_API efsw_addwatch(efsw_watcher watcher, const char* directory, 
	efsw_pfn_fileaction_callback callback_fn, int recursive, void* param);

/// Remove a directory watch. This is a brute force search O(nlogn).
void EFSW_API efsw_removewatch(efsw_watcher watcher, const char* directory);

/// Remove a directory watch. This is a map lookup O(logn).
void EFSW_API efsw_removewatch_byid(efsw_watcher watcher, efsw_watchid watchid);

/// Starts watching ( in other thread )
void EFSW_API efsw_watch(efsw_watcher watcher);

/**
 * Allow recursive watchers to follow symbolic links to other directories
 * followSymlinks is disabled by default
 */
void EFSW_API efsw_follow_symlinks(efsw_watcher watcher, int enable);

/** @return If can follow symbolic links to directorioes */
int EFSW_API efsw_follow_symlinks_isenabled(efsw_watcher watcher);

/**
 * When enable this it will allow symlinks to watch recursively out of the pointed directory.
 * follorSymlinks must be enabled to this work.
 * For example, added symlink to /home/folder, and the symlink points to /, this by default is not allowed,
 * it's only allowed to symlink anything from /home/ and deeper. This is to avoid great levels of recursion.
 * Enabling this could lead in infinite recursion, and crash the watcher ( it will try not to avoid this ).
 * Buy enabling out of scope links, it will allow this behavior.
 * allowOutOfScopeLinks are disabled by default.
 */
void EFSW_API efsw_allow_outofscopelinks(efsw_watcher watcher, int allow);

/// @return Returns if out of scope links are allowed
int EFSW_API efsw_outofscopelinks_isallowed(efsw_watcher watcher);

#ifdef __cplusplus
}
#endif

#endif
