# 🧩 Interface Segregation Principle (ISP)

## 📘 What is ISP?

The **Interface Segregation Principle** is the fourth principle in the SOLID principles of object-oriented design, introduced by Robert C. Martin.
 
### 💡 Definition

> No client should be forced to depend on interfaces it does not use.

In simpler terms: **Create smaller, more focused interfaces rather than large, general-purpose ones.**

## 🎯 Core Concept

Classes should only have to implement methods that they actually need. If a class needs to implement an interface with methods it doesn't use, that interface should be split into smaller, more specific interfaces.

## ✅ Benefits

- **🔄 Reduced coupling**: Classes only depend on the interfaces they actually use
- **🧹 Clean architecture**: Systems become more modular and easier to refactor
- **🛠️ Easier maintenance**: Changes to one interface don't affect unrelated classes
- **📈 Improved scalability**: New functionality can be added without disrupting existing code
- **🧪 Better testability**: More focused interfaces make unit testing simpler
- **📝 Clearer contracts**: Smaller interfaces communicate intent more clearly

## 🚫 Common Mistakes

- **Creating "fat" interfaces** that force classes to implement unnecessary methods
- **Not separating concerns** in interfaces, mixing unrelated functionality
- **Designing interfaces around implementations** instead of client needs
- **Over-segregating interfaces** to the point of increased complexity

## 🧪 Code Examples

### ❌ Violating ISP

```cpp
#include <iostream>
using namespace std;

// Large interface that includes unrelated methods
class Machine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
    virtual void copy() = 0;
};

// Printer class only needs printing functionality
class Printer : public Machine {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
    void scan() override {
        // Not used, but forced to implement
    }
    void fax() override {
        // Not used, but forced to implement
    }
    void copy() override {
        // Not used, but forced to implement
    }
};

int main() {
    Printer p;
    p.print();  // Prints document
    return 0;
}
```

### ✅ Following ISP

```cpp
#include <iostream>
using namespace std;

// Smaller, specific interfaces
class Printable {
public:
    virtual void print() = 0;
};

class Scannable {
public:
    virtual void scan() = 0;
};

class Faxable {
public:
    virtual void fax() = 0;
};

class Copyable {
public:
    virtual void copy() = 0;
};

// Printer class only implements Printable interface
class Printer : public Printable {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
};

// Scanner class only implements Scannable interface
class Scanner : public Scannable {
public:
    void scan() override {
        cout << "Scanning document..." << endl;
    }
};

// All-in-one machine implements multiple interfaces
class AllInOneMachine : public Printable, public Scannable, 
                        public Faxable, public Copyable {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
    
    void scan() override {
        cout << "Scanning document..." << endl;
    }
    
    void fax() override {
        cout << "Faxing document..." << endl;
    }
    
    void copy() override {
        cout << "Copying document..." << endl;
    }
};

int main() {
    Printer p;
    p.print();  // Prints document
    
    Scanner s;
    s.scan();  // Scans document
    
    AllInOneMachine aio;
    aio.print();  // Uses all functionality
    aio.scan();
    aio.fax();
    aio.copy();
    
    return 0;
}
```

## 🧠 Key Takeaways

- **📏 Size matters**: Prefer many small interfaces over few large ones
- **🎯 Client-focused**: Design interfaces around client needs, not implementations
- **🔄 Composition over inheritance**: Use multiple interfaces to compose behavior

## 💡 Final Tip

** When applying ISP, always think from the perspective of the client class. 
** What functionality does it really need? If an interface requires methods that don’t apply to the class, 
** it's a sign to split it into more relevant, smaller interfaces. 
By doing this, you'll create code that is cleaner, more maintainable, and adaptable to future changes.
