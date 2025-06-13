# SOLID Principles Application Guide

## ✅ Example: Designing a Small Feature

Let's say you're building a simple Quiz App.

- You might use **SRP** to keep QuestionGenerator, ScoreTracker, and UserInterface separate.
- If you expect new question types later (MCQ, True/False), use **OCP**.
- If you use inheritance for Question, apply **LSP** to ensure subclasses behave well.
- If you're designing interfaces, and not all classes need every method, apply **ISP**.
- If you want your logic to not depend directly on MySQL or MongoDB, apply **DIP**.

## ✅ Rule of Thumb

Use SOLID principles when your code smells — not just to show off design theory.

**If:**
- **Your class keeps changing** — use **SRP**
- **You're always rewriting existing logic to add a new type** — use **OCP**
- **A subclass breaks something** — fix with **LSP**
- **Interfaces are bloated** — clean with **ISP**
- **Your logic tightly depends on third-party libs** — break with **DIP**

## 🔚 Final Takeaway:

Use the principles wisely, not blindly.

Good design is not about "using all 5" — it's about using the right one at the right time to keep your code clean, robust, and change-friendly.
