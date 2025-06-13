# 💡 Dependency Injection in C++ (SOLID - Dependency Inversion Principle)

## 📘 What is Dependency Inversion Principle (DIP)?

> High-level modules should not depend on low-level modules.  
> Both should depend on **abstractions** (interfaces or abstract classes).  
> Abstractions should not depend on details.  
> Details should depend on **abstractions**.

DIP is the 'D' in the SOLID principles of object-oriented design, focusing on decoupling software modules to make systems more maintainable and extensible.

## 🧩 Problem Without DIP

In traditional tightly-coupled design, a `Switch` directly controls a `Light`. You cannot easily reuse the `Switch` for other devices like a `Fan`.

### ❌ Tightly Coupled Example:

```cpp
class Light {
public:
    void turnOn() {
        cout << "Light is ON\n";
    }
    
    void turnOff() {
        cout << "Light is OFF\n";
    }
};

class Switch {
    Light light; // Tightly coupled to Light class
public:
    void operate() {
        // Switch can only operate a Light
        light.turnOn();
    }
};
```

Problems with this approach:
- `Switch` class is permanently bound to `Light`
- Cannot reuse `Switch` for other devices
- Changes to `Light` interface might require changes to `Switch`
- Difficult to test `Switch` in isolation

## ✅ Solution: Use Dependency Injection

We create a base class `Device`, and both `Light` and `Fan` implement it. The `Switch` only depends on this `Device` interface, not on specific devices.

### ✅ Loosely Coupled Example (with DIP):

```cpp
#include <iostream>
using namespace std;

// Abstract class (interface)
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() = default;
};

// Light class
class Light : public Device {
public:
    void turnOn() override {
        cout << "Light is ON\n";
    }
    
    void turnOff() override {
        cout << "Light is OFF\n";
    }
};

// Fan class
class Fan : public Device {
public:
    void turnOn() override {
        cout << "Fan is ON\n";
    }
    
    void turnOff() override {
        cout << "Fan is OFF\n";
    }
};

// Switch depends on abstract Device
class Switch {
    Device* device; // Depends on abstraction, not concrete class
    bool state = false;
    
public:
    // Constructor injection
    Switch(Device* d) : device(d) {}
    
    void operate() {
        if (state) {
            device->turnOff();
            state = false;
        } else {
            device->turnOn();
            state = true;
        }
    }
};

int main() {
    Light light;
    Fan fan;
    
    Switch lightSwitch(&light);
    lightSwitch.operate();  // Output: Light is ON
    lightSwitch.operate();  // Output: Light is OFF
    
    Switch fanSwitch(&fan);
    fanSwitch.operate();    // Output: Fan is ON
    
    return 0;
}
```

## 🎯 Benefits of Dependency Injection

* **✅ Loosely coupled design**: Components depend on abstractions, not concrete implementations
* **🔁 Easy to switch or add new devices**: Any class implementing the `Device` interface can be used
* **🧪 Easier testing and maintenance**: Can test components in isolation using mock objects
* **📦 Follows the SOLID principle**: Specifically, the Dependency Inversion Principle (D in SOLID)

## 🔄 Tight Coupling vs. Loose Coupling

| Aspect | Tight Coupling | Loose Coupling |
|--------|---------------|----------------|
| **Definition** | Classes depend directly on concrete implementations | Classes depend on abstractions (interfaces) |
| **Change Impact** | Changes in one class often require changes in dependent classes | Changes in implementations don't affect classes using the abstraction |
| **Reusability** | Low - components are designed for specific use cases | High - components can be reused across different contexts |
| **Testing** | Difficult - dependencies must be instantiated together | Easy - can use mock implementations for testing |
| **Code Maintenance** | Harder - changes ripple through the system | Easier - isolated changes |
| **Scalability** | Limited - difficult to extend | Good - new implementations can be added without changing existing code |



## 📝 Conclusion

Dependency Injection is a powerful technique that implements the Dependency Inversion Principle. By depending on abstractions rather than concrete implementations, we create more flexible, maintainable, and testable code.
