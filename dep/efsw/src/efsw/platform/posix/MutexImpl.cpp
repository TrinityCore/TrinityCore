#include <efsw/platform/posix/MutexImpl.hpp>

#if defined( EFSW_PLATFORM_POSIX )

namespace efsw { namespace Platform {

MutexImpl::MutexImpl() {
	pthread_mutexattr_t attributes;
	pthread_mutexattr_init( &attributes );
	pthread_mutexattr_settype( &attributes, PTHREAD_MUTEX_RECURSIVE );
	pthread_mutex_init( &mMutex, &attributes );
}

MutexImpl::~MutexImpl() {
	pthread_mutex_destroy( &mMutex );
}

void MutexImpl::lock() {
	pthread_mutex_lock( &mMutex );
}

void MutexImpl::unlock() {
	pthread_mutex_unlock( &mMutex );
}

}} // namespace efsw::Platform

#endif
