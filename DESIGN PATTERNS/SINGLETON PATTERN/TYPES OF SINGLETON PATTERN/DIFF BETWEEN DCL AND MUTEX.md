# Basic Mutex Locking vs Double-Checked Locking (DCL) Comparison

## Feature Comparison

| 🔸 Feature | 🔒 Basic Mutex Locking | ⚡ Double-Checked Locking (DCL) |
|------------|------------------------|--------------------------------|
| **Locking behavior** | Always locks the mutex | Locks the mutex **only if instance is `nullptr`** |
| **Performance after initialization** | Slower (due to always locking) | Faster (skips locking once instance is created) |
| **Thread safety** | ✅ Yes | ✅ Yes (with proper implementation) |
| **Instance check** | Only once (after acquiring lock) | Checked twice (before & after locking) |
| **Use of resources** | More CPU usage due to unnecessary locking | More optimized CPU usage |
| **Code complexity** | Simple and easy to read | Slightly more complex (requires understanding DCL) |
| **Ideal for** | Simple apps where performance isn't critical | Performance-sensitive, multi-threaded applications |
| **Risk of race condition** | None | None (if lock is correctly applied) |
