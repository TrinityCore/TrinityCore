#ifndef EFSW_MUTEXIMPLWIN_HPP
#define EFSW_MUTEXIMPLWIN_HPP

#include <efsw/base.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

namespace efsw { namespace Platform {

class MutexImpl
{
	public:
		MutexImpl();

		~MutexImpl();

		void lock();

		void unlock();
	private:
		CRITICAL_SECTION mMutex;
};

}}

#endif

#endif
 
