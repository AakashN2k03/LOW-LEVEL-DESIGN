# 🪢 Liskov Substitution Principle (LSP)

## 📘 What is LSP?

The **Liskov Substitution Principle** is the third principle in the SOLID principles of object-oriented design, introduced by computer scientist **Barbara Liskov** in 1987.

### 💡 Definition

> If class `S` is a subtype of class `T`, then objects of type `T` should be replaceable with objects of type `S` without altering the correctness of the program.

In simple terms: **A child class should be able to substitute its parent class without breaking the program.**

## 🎯 Core Concept

If I have a function that uses a base class, it should work just fine even if I pass an object of its subclass — without breaking functionality or introducing bugs.

## ✅ Advantages

- **Improved code reliability**: By ensuring subtypes work correctly in place of their parent types
- **Better abstraction**: Forces you to think clearly about class responsibilities and relationships
- **Facilitates unit testing**: Classes that follow LSP are easier to test independently
- **Prevents unexpected behavior**: Clients using base classes won't break when new derived classes are introduced

## 🛑 Common Mistakes

- Forcing a subclass to override methods it shouldn't (like `fly()` for `Ostrich`)
- Using inheritance when **composition** or **interfaces** would be a better choice
- Changing the behavior of inherited methods in ways that break client expectations

## 🧪 C++ Code Example

### ❌ Violating LSP

```cpp
class Bird {
public:
    virtual void fly() {
        cout << "Flying..." << endl;
    }
};

class Sparrow : public Bird {
    // Fine
};

class Penguin : public Bird {
public:
    void fly() override {
        throw runtime_error("Penguins can't fly!");
    }
};

void makeBirdFly(Bird* b) {
    b->fly();  // Throws exception if Penguin
}
```

### ✅ Following LSP

```cpp
class Bird {
    // Common bird behavior
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        cout << "Sparrow flying!" << endl;
    }
};

class Penguin : public Bird {
    // No fly() here — it's not a FlyingBird
};

void makeFly(FlyingBird* bird) {
    bird->fly();
}
```

## 🔍 When to Use LSP

- When designing class hierarchies and inheritance relationships
- When creating frameworks that will be extended by other developers
- When working with polymorphism and abstract types
- When refactoring code to reduce tight coupling
- When designing interfaces or abstract classes

## 🧠 Final Tip

Ask yourself:
"Can I replace the parent class with the subclass and the program still works as expected?"

If **yes**, you're following LSP. If **no**, reconsider your inheritance strategy.
