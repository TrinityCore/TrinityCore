#ifndef EFSW_THREADIMPLPOSIX_HPP
#define EFSW_THREADIMPLPOSIX_HPP

#include <efsw/base.hpp>

#if defined( EFSW_PLATFORM_POSIX )

#include <pthread.h>

namespace efsw {

class Thread;

namespace Platform {

class ThreadImpl
{
	public:
		ThreadImpl( Thread * owner );
		
		void wait();
		
		void terminate();
	protected:
		static void *	entryPoint( void* userData );

		pthread_t		mThread;
		bool			mIsActive;
};

}}

#endif

#endif
