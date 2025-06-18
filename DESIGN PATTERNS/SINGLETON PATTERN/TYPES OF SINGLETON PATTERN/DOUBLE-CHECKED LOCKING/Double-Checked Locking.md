# Double-Checked Locking in Singleton

## What is Double-Checked Locking?

🔐 Double-Checked Locking is a technique used in lazy initialization to reduce the cost of acquiring a mutex unnecessarily after the Singleton has already been created.

## Example Implementation

```cpp
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;
    
    Singleton() {
        cout << "Constructor Called!\n";
    }

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
    
    void show() {
        cout << "I am Singleton instance. Address: " << this << endl;
    }
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

void threadFunc() {
    Singleton* obj = Singleton::getInstance();
    obj->show();
}

int main() {
    thread t1(threadFunc);
    thread t2(threadFunc);
    thread t3(threadFunc);
    
    t1.join();
    t2.join();
    t3.join();
}
```

## Output Example

```
Constructor Called!
I am Singleton instance. Address: 0x7ffcb8500930
I am Singleton instance. Address: 0x7ffcb8500930
I am Singleton instance. Address: 0x7ffcb8500930
```

✅ Only one constructor call  
✅ All threads get the same instance

## Step-by-Step Backend Workflow

### 1. Program Starts – main() Begins
OS allocates a main stack and heap memory for your process.  
main() creates 3 threads using std::thread.

### 2. OS Schedules Threads
The OS schedules the 3 threads (t1, t2, t3) on CPU cores.  
These may run truly in parallel (on multicore CPUs) or interleaved (on single core via context switching).

### 🔄 For Each Thread:

### 3. All Threads Call Singleton::getInstance()
All 3 threads simultaneously enter:
```cpp
if (instance == nullptr)
```
This check is not protected by mutex, so all threads might pass if instance is still null.

### 4. One Thread Locks the Mutex First
```cpp
std::lock_guard<std::mutex> lock(mtx);
```
The first thread that gets CPU access locks the mutex (mtx).  
Other threads are now blocked at the mutex, waiting for the lock.

### 5. Singleton is Created (One Time)
```cpp
if (instance == nullptr)
    instance = new Singleton();
```
The first thread enters this and allocates memory using new:
- Allocates on the heap
- Returns a pointer to that memory
- Stores it in the static instance pointer

✅ Now instance is no longer nullptr.

### 6. Mutex Automatically Unlocks
lock_guard is a RAII class — when it goes out of scope, mutex is released automatically.

### 7. Waiting Threads Wake Up
Now thread 2 and thread 3:
- Acquire the lock one after another
- They check `if (instance == nullptr)` — it's not null now, so they skip creation
- They return the same singleton pointer
