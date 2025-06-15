// ✅ What Is Lazy Initialization?

// It means delaying the creation of an object until it’s actually needed.
// You don’t waste memory or processing time if the object is never used.

#include<bits/stdc++.h>
using namespace std;

class Logger {
private:
    static Logger* instance;

    // 🔒 Constructor is private to prevent external instantiation
    Logger() {
        cout << "Logger instance created" << endl;
    }

public:
    // ✅ 🔥 Lazy Initialization happens here
    static Logger* getInstance() {
        if (instance == nullptr) {         // <-- 🔹 Lazy check
            instance = new Logger();       // <-- 🔹 Object  here, created whenever needed
        }
        return instance;
    }

    void display() {
        cout << "LOG initiated" << endl;
    }
};

// 🔹 Static member initialization (no object yet)
Logger* Logger::instance = nullptr;

int main() {
    // 🔥 First use of Singleton
    Logger* logger1 = Logger::getInstance();  // <-- Object created here
    logger1->display();

    // 🔁 Reusing existing instance
    Logger* logger2 = Logger::getInstance();  // <-- No new object created
    logger2->display();

    if (logger1 == logger2) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
// Note: Most cases in Lazy Intialization we use Pointer ,EG: static Logger* getInstance()
