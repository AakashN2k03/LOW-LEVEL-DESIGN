#include<iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx; // mutex is a datatype. A mutex (mutual exclusion) is a lock that allows only one thread to access a critical section of code.
    Singleton() {}

public:
    static Singleton* getInstance() {
      // lock_guard -> 	A C++ template class that automatically locks a mutex when created and unlocks it when destroyed. 
        lock_guard<mutex> lock(mtx); //lock(mtx)	Creates the lock and locks the mutex mtx
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx; //here mutex is an object, and it initializes itself, 
//whereas Singleton* is a pointer, which must be manually initialized to  nullptr else might point to some undefined memory, and accessing it will cause a segmentation fault or crash.

int main()
{
    Singleton* obj=Singleton::getInstance();
}

// NOTE:1 -> Using mutex we must need to use lock and unlock methods..where lock_guard is a wrapper which dies automatically
// NOTE:2 -> Lock_guard is a template - meaning it is defined generically to work with any type of mutex (like std::mutex, std::recursive_mutex, etc.)
// eg: template<class _Mutex>
// class lock_guard;
