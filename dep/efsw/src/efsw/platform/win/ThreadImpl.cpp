#include <assert.h>
#include <efsw/Thread.hpp>
#include <efsw/platform/win/ThreadImpl.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#include <efsw/Debug.hpp>

namespace efsw { namespace Platform {

ThreadImpl::ThreadImpl( efsw::Thread* owner ) {
	mThread = reinterpret_cast<HANDLE>(
		_beginthreadex( NULL, 0, &ThreadImpl::entryPoint, owner, 0, &mThreadId ) );

	if ( !mThread ) {
		efDEBUG( "Failed to create thread\n" );
	}
}

ThreadImpl::~ThreadImpl() {
	if ( mThread ) {
		CloseHandle( mThread );
	}
}

void ThreadImpl::wait() {
	// Wait for the thread to finish, no timeout
	if ( mThread ) {
		assert( mThreadId != GetCurrentThreadId() ); // A thread cannot wait for itself!

		WaitForSingleObject( mThread, INFINITE );
	}
}

void ThreadImpl::terminate() {
	if ( mThread ) {
		TerminateThread( mThread, 0 );
	}
}

unsigned int __stdcall ThreadImpl::entryPoint( void* userData ) {
	// The Thread instance is stored in the user data
	Thread* owner = static_cast<Thread*>( userData );

	// Forward to the owner
	owner->run();

	// Optional, but it is cleaner
	_endthreadex( 0 );

	return 0;
}

}} // namespace efsw::Platform

#endif
