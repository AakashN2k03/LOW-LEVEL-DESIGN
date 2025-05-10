# 🧑‍💻 User Management System — Applying SOLID Principles

This is a basic **User Management System** that allows you to:

- ➕ Add a user  
- ❌ Delete a user  
- 🔄 Update user info  
- 📋 Show all users  

We apply the **5 SOLID Principles** to make the design clean, flexible, and maintainable.

---

## 🔸 S — Single Responsibility Principle (SRP)

**Rule:** A class should do only one job.

### ✅ Applied As:
- `UserService`: Handles add, delete, and update operations.
- `UserPrinter`: Responsible only for displaying user info.

> 📌 Why?  
> If display logic changes, you only modify `UserPrinter`, not the whole service.

---

## 🔸 O — Open/Closed Principle (OCP)

**Rule:** Code should be open for extension, but closed for modification.

### ✅ Applied As:
- You want to sort users by name or age.
- Instead of changing `UserPrinter`, create:
  - `NameSorter`
  - `AgeSorter`

> 📌 Why?  
> You add new features without touching existing code.

---

## 🔸 L — Liskov Substitution Principle (LSP)

**Rule:** Subclasses should work wherever their base class is expected.

### ✅ Applied As:
- `User` is the base class.
- `AdminUser` is a subclass.

> Both can be used with `UserService` without causing bugs or unexpected behavior.

> 📌 Why?  
> Child classes should **not break** the logic or assumptions made for the parent class.

---

## 🔸 I — Interface Segregation Principle (ISP)

**Rule:** Don’t force classes to implement methods they don’t use.

### ✅ Applied As:
- Break `IUserOperations` into:
  - `IBasicUserOperations`: `addUser()`, `updateUser()`
  - `IEmailSender`: `sendEmail()`

> 📌 Why?  
> `GuestUser` doesn’t need `sendEmail()`, so it shouldn’t be forced to implement it.

---

## 🔸 D — Dependency Inversion Principle (DIP)

**Rule:** High-level modules should depend on abstractions, not concrete implementations.

### ✅ Applied As:
- `UserService` depends on an interface `IDatabase`, not directly on `MySQLDatabase`.

> This allows plugging in:
> - `MySQLDatabase`
> - `MongoDatabase`

> 📌 Why?  
> Makes the code more flexible, testable, and swappable.

---

## ✅ Summary Table

| Principle | Simple Meaning                     | Our Example                                  |
|-----------|-------------------------------------|----------------------------------------------|
| **SRP**   | One class, one job                  | Split `UserService` and `UserPrinter`        |
| **OCP**   | Add features without changing code  | Create new sorter classes                    |
| **LSP**   | Subclass should behave like parent  | `AdminUser` behaves like `User`              |
| **ISP**   | Small, specific interfaces          | Split interfaces: `IBasicUserOperations`, `IEmailSender` |
| **DIP**   | Use interfaces, not concrete classes| Use `IDatabase`, not `MySQLDatabase`         |

---
