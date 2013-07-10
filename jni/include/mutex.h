#ifndef __MUTEX_H_
#define __MUTEX_H_

#include <pthread.h>

//--------------------------------------------------------------------------
// pthread mutex lock
//--------------------------------------------------------------------------
class ThreadMutex{
public:
	ThreadMutex(){
		pthread_mutex_init(&mutex, 0);
	}
	~ThreadMutex(){
		pthread_mutex_destroy(&mutex);
	}

	void lock(){
		pthread_mutex_lock(&mutex);
	}

	void unlock(){
		pthread_mutex_unlock(&mutex);
	}

private:
	pthread_mutex_t mutex;
};

//--------------------------------------------------------------------------
// auto mutex lock
//--------------------------------------------------------------------------
class AutoLock{
public:
	AutoLock(ThreadMutex &mux):mutex(mux){
		mutex.lock();
	}
	~AutoLock(){
		mutex.unlock();
	}

private:
	ThreadMutex& mutex;
};

#endif

