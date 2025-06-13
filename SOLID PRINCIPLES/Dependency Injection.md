# Dependency Inversion Principle (DIP)

## 🧠 What is Dependency Inversion Principle (DIP)?

"High-level modules should not depend on low-level modules. Both should depend on abstractions."

"Abstractions should not depend on details. Details should depend on abstractions."

## 🤯 Simple Explanation

Let's break that down:

- **High-level module** = Main logic (e.g., OrderService)
- **Low-level module** = Helper or dependency (e.g., MySQLDatabase)
- **Abstraction** = Interface or base class (e.g., IDatabase)

## 🔁 Without DIP (Tightly Coupled):

```cpp
class MySQLDatabase {
public:
    void saveOrder() {
        cout << "Order saved in MySQL\n";
    }
};

class OrderService {
public:
    void placeOrder() {
        MySQLDatabase db;
        db.saveOrder(); // ❌ tightly coupled to MySQL
    }
};
```

**Problems:**
- Can't switch to MongoDB or PostgreSQL easily
- Hard to test with mock DB
- Breaks OCP and DIP

## ✅ With DIP (and Dependency Injection)

We invert the dependency:

- High-level (OrderService) doesn't know which DB it's using.
- It depends on an abstraction (IDatabase), not a concrete DB class.

```cpp
// Abstraction
class IDatabase {
public:
    virtual void saveOrder() = 0;
};

// Low-level modules
class MySQLDatabase : public IDatabase {
public:
    void saveOrder() override {
        cout << "Order saved in MySQL\n";
    }
};

class MongoDB : public IDatabase {
public:
    void saveOrder() override {
        cout << "Order saved in MongoDB\n";
    }
};

// High-level module
class OrderService {
private:
    IDatabase* database;
public:
    OrderService(IDatabase* db) {  // ✅ Dependency Injection
        database = db;
    }
    
    void placeOrder() {
        database->saveOrder();
    }
};
```

## 🔁 Usage

```cpp
MySQLDatabase mySQL;
OrderService order1(&mySQL);
order1.placeOrder();  // Outputs: Order saved in MySQL

MongoDB mongo;
OrderService order2(&mongo);
order2.placeOrder();  // Outputs: Order saved in MongoDB
```

## ✅ Benefits of DIP

| Benefit | Why it matters |
|---------|----------------|
| ✅ Decoupled | You can swap MySQL with MongoDB or even mock DB. This makes the system more testable, extensible, and loosely coupled. |
| ✅ Testable | Easily test OrderService by injecting a fake DB |
| ✅ Extensible | Add new DB types without touching OrderService |
| ✅ SRP Friendly | OrderService focuses only on business logic, not DB logic |

## Coupling Types

| Coupling Type | Meaning |
|---------------|---------|
| Tightly Coupled | Classes or modules are strongly dependent on each other. Change in one affects the other. |
| Loosely Coupled | Classes or modules are minimally dependent on each other. They interact through abstractions. |
