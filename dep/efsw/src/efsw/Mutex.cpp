#include <efsw/Mutex.hpp>
#include <efsw/platform/platformimpl.hpp>

namespace efsw {

Mutex::Mutex() :
	mMutexImpl( new Platform::MutexImpl() )
{
}

Mutex::~Mutex()
{
	efSAFE_DELETE( mMutexImpl );
}

void Mutex::lock()
{
	mMutexImpl->lock();
}

void Mutex::unlock()
{
	mMutexImpl->unlock();
}

}
