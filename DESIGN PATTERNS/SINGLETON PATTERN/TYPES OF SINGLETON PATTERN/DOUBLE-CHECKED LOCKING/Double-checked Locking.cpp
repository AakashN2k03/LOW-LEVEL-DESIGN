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
        if (instance == nullptr) {          //avoids locking if instance already exists
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {     //ensures only one thread creates the instance
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
