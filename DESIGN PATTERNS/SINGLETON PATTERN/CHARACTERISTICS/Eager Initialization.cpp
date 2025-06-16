// In Eager Initialization, the singleton object is created at the time of class loading — even if the application might never use it.

#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Instance Created" << endl;
    }

public:
    static Singleton* getInstance() {
        return instance;
    }

    void show() {
        cout << "I am a singleton instance." << endl;
    }
};

// 🔸 Create the object eagerly (at program load)
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* obj1 = Singleton::getInstance();
    obj1->show();
}

// Eager: new Singleton() happens outside getInstance().
// Lazy: new Singleton() happens inside getInstance() after checking for null.
