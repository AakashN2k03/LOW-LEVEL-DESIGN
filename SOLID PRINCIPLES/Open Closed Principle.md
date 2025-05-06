# 🧱 Open/Closed Principle (OCP) – SOLID Design Principle

## 📘 What is OCP? 
**Open/Closed Principle** is the second of the SOLID principles of object-oriented design.

> 💡 A class should be **open for extension** but **closed for modification**.  

This means you should be able to add new features to a class **without modifying** the existing code.

---

## 🔍 Real-World Analogy: Music Player Plugin System

Imagine a **music player application** that initially supports playing **MP3 files**. Later, users request support for additional file formats like **WAV**, **FLAC**, and **AAC**.

### **Without OCP**:
To support a new file format, you would need to go into the **MusicPlayer** class and add more `if-else` statements to handle each new format.

```cpp
class MusicPlayer {
public:
    void play(string fileType) {
        if (fileType == "MP3") {
            cout << "Playing MP3 file\n";
        } else if (fileType == "WAV") {
            cout << "Playing WAV file\n";
        } else if (fileType == "FLAC") {
            cout << "Playing FLAC file\n";
        }
        // New formats require modifications to this class
    }
};
```

This approach is **not open for extension**, and you need to **modify the existing code** every time a new format is introduced.

### Following OCP: Extending the Music Player

Now, to follow OCP, instead of modifying the existing `MusicPlayer` class, you **create new classes** for each format that extends a common interface.

```cpp
// Base class
class MusicPlayer {
public:
    virtual void play() = 0;  // Pure virtual function
};

// Concrete classes for different formats
class MP3Player : public MusicPlayer {
public:
    void play() override {
        cout << "Playing MP3 file\n";
    }
};

class WAVPlayer : public MusicPlayer {
public:
    void play() override {
        cout << "Playing WAV file\n";
    }
};

class FLACPlayer : public MusicPlayer {
public:
    void play() override {
        cout << "Playing FLAC file\n";
    }
};

// Usage
void playMusic(MusicPlayer* player) {
    player->play();
}
```

Here, you don't modify the existing code when adding a new format. You **extend the system** by creating new classes that implement the `MusicPlayer` interface.

---

## 🧠 Benefits of OCP
* 🔄 **Easier to extend** with new features without modifying existing code
* 💣 **Reduces the risk** of breaking functionality in old code
* 📏 **Encourages cleaner and modular code** that is easier to test

---

## 🛑 Common Mistakes
* ❌ **Over-complicating things** by abstracting too early or too much.
* ❌ **Misunderstanding OCP**: It doesn't mean never modifying anything, it means **extending** it rather than modifying the original logic.

---

## 📌 Final Tip
OCP is a great principle for building scalable systems. As you build your software, try to design it in such a way that new requirements can be **plugged in** without modifying existing code, keeping your application **flexible** and **maintainable**.

**NOTE:**
* **Modular Code**: Organizes your system into **independent, reusable units** that can be developed, tested, and maintained independently.
* **Over-abstraction**: Can complicate things unnecessarily by abstracting before it's needed or creating too many abstractions. Focus on simplicity first.

**KEY POINT**
- For better design use both SRP and OCP
