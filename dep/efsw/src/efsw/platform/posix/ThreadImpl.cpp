#include <efsw/platform/posix/ThreadImpl.hpp>
#include <efsw/Thread.hpp>

#if defined( EFSW_PLATFORM_POSIX )

#include <cassert>
#include <iostream>
#include <efsw/Debug.hpp>

namespace efsw { namespace Platform {

ThreadImpl::ThreadImpl( Thread * owner ) :
	mIsActive(false)
{
	mIsActive = pthread_create( &mThread, NULL, &ThreadImpl::entryPoint, owner ) == 0;

	if ( !mIsActive )
	{
		efDEBUG( "Failed to create thread\n" );
	}
}

void ThreadImpl::wait()
{
	// Wait for the thread to finish, no timeout
	if ( mIsActive )
	{
		assert( pthread_equal( pthread_self(), mThread ) == 0 );

		pthread_join( mThread, NULL );

		mIsActive = false; // Reset the thread state
	}
}

void ThreadImpl::terminate()
{
	if ( mIsActive )
	{
		#if !defined( __ANDROID__ ) && !defined( ANDROID )
			pthread_cancel( mThread );
		#else
			pthread_kill( mThread , SIGUSR1 );
		#endif

		mIsActive = false;
	}
}

void * ThreadImpl::entryPoint( void * userData )
{
	// The Thread instance is stored in the user data
	Thread * owner = static_cast<Thread*>( userData );

	// Tell the thread to handle cancel requests immediatly
	#ifdef PTHREAD_CANCEL_ASYNCHRONOUS
		pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, NULL );
	#endif

	// Forward to the owner
	owner->run();

	return NULL;
}

}}

#endif
