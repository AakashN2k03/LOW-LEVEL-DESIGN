# Thread-Safe Singleton using Mutex (Lazy + Safe)

A Thread-Safe Singleton using Mutex (Lazy + Safe) is a common way to implement a singleton pattern where:

- **Lazy Initialization**: The object is created only when needed, not at program start.
- **Thread-Safe**: Multiple threads can call the getInstance() method safely, without creating multiple objects.
- **Mutex**: A mutual exclusion lock ensures that only one thread can create the instance at a time.

## Why We Need This

In multithreaded programs, lazy singletons can result in multiple instances if two threads enter getInstance() simultaneously. To avoid that, we use a mutex (or std::mutex in C++) to lock the code that creates the instance.

## C++ Example

```cpp
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;
    Singleton() {}

public:
    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;
```

## What std::lock_guard<std::mutex> Does

- Locks the mutex mtx as soon as it is constructed.
- Automatically unlocks it when the function/block exits (RAII – Resource Acquisition Is Initialization).

## Real-Time Analogy

Imagine a printer (singleton) in a company. Many employees (threads) try to access it, but only one person can set it up if it's not already initialized. A mutex acts like a room key, allowing only one employee inside to set it up.

## Performance Note

Every call to getInstance() locks the mutex—even after the instance is created. This can affect performance in high-concurrency environments. For better performance, use Double-Checked Locking (next level optimization).
