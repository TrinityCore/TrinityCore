#include <efsw/Thread.hpp>
#include <efsw/platform/platformimpl.hpp>

namespace efsw {

Thread::Thread() : mThreadImpl( NULL ), mEntryPoint( NULL ) {}

Thread::~Thread() {
	wait();

	efSAFE_DELETE( mEntryPoint );
}

void Thread::launch() {
	wait();

	mThreadImpl = new Platform::ThreadImpl( this );
}

void Thread::wait() {
	if ( mThreadImpl ) {
		mThreadImpl->wait();

		efSAFE_DELETE( mThreadImpl );
	}
}

void Thread::terminate() {
	if ( mThreadImpl ) {
		mThreadImpl->terminate();

		efSAFE_DELETE( mThreadImpl );
	}
}

void Thread::run() {
	if ( mEntryPoint )
		mEntryPoint->run();
}

} // namespace efsw
