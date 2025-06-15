#include<bits/stdc++.h>
using namespace std;

class Logger {
private:
    static Logger* instance;

    Logger() {
        cout << "Logger instance created" << endl;
    }

public:
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger(); 
        }
        return instance;
    }

    void display() {
        cout << "LOG initiated" << endl;
    }
};

Logger* Logger::instance = nullptr;

int main() {
    Logger* logger1 = Logger::getInstance();
    logger1->display();

    Logger* logger2 = Logger::getInstance();
    logger2->display();

    if (logger1 == logger2) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
