# Thread-Safe Singleton using Mutex (Lazy + Safe) — Summary

## 🔷 Goal

- Ensure that **only one instance** of the Singleton class is created
- Make it **thread-safe**
- Create the instance **lazily** (only when needed)

## 🔧 Key Components

### 1. **Static Pointer**

```cpp
static Singleton* instance;
```

- Stores the one-and-only Singleton instance
- Shared across threads (since it's `static`)

### 2. **Static Mutex**

```cpp
static std::mutex mtx;
```

- Used to prevent race conditions between threads during instance creation

### 3. **Private Constructor**

```cpp
Singleton() {}
```

- Blocks external instantiation
- Enforces controlled creation via `getInstance()`

### 4. **Thread-Safe getInstance()**

```cpp
static Singleton* getInstance() {
    std::lock_guard<std::mutex> lock(mtx);
    if (instance == nullptr)
        instance = new Singleton();
    return instance;
}
```

- Uses `std::lock_guard` to **lock mutex automatically**
- Only **one thread** can enter this section at a time
- Safely checks and creates the Singleton instance if not already done

### 5. **Outside-Class Definitions**

```cpp
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;
```

- Define static members outside the class

## ⚙️ Characteristics

| Feature | Description |
|---------|-------------|
| **Lazy Loading** | Instance created only when first requested |
| **Thread-Safe** | Mutex ensures only one thread can create the instance |
| **RAII Locking** | `std::lock_guard` automatically manages lock/unlock |
| **Safe in Exceptions** | Lock is released even if exceptions occur |
| **Slight Overhead** | Slightly slower due to locking every time `getInstance()` is called |

## 🧠 Real-World Use Cases

- Config manager in a web app backend
- Logger instance in a multithreaded server
- Database connection pool manager
