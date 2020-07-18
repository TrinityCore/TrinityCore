#ifndef EFSW_THREADIMPLWIN_HPP
#define EFSW_THREADIMPLWIN_HPP

#include <efsw/base.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <process.h>

namespace efsw {

class Thread;

namespace Platform {

class ThreadImpl
{
	public:
		ThreadImpl( Thread * owner );

		~ThreadImpl();
		
		void wait();
		
		void terminate();
	protected:
		static unsigned int __stdcall entryPoint(void* userData);

		HANDLE			mThread;
		unsigned int	mThreadId;
};

}}

#endif

#endif
