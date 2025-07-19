#include <efsw/platform/win/MutexImpl.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

namespace efsw { namespace Platform {

MutexImpl::MutexImpl() {
	InitializeCriticalSection( &mMutex );
}

MutexImpl::~MutexImpl() {
	DeleteCriticalSection( &mMutex );
}

void MutexImpl::lock() {
	EnterCriticalSection( &mMutex );
}

void MutexImpl::unlock() {
	LeaveCriticalSection( &mMutex );
}

}} // namespace efsw::Platform

#endif
