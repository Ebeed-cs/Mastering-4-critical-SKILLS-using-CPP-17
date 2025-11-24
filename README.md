# 🚀 Mastering 4 Critical Skills using Modern C++ (C++11/14/17) with Dr. Moustafa Saad

## 📌 Overview
This is **not just another C++ course** – it’s a **complete mastery program** focused on **4 critical skills** that every software engineer and competitive programmer must develop:

1️⃣ **Programming Skills** – Learn C++ deeply, from **fundamentals to advanced topics**.  
2️⃣ **Problem-Solving Skills** – Strengthen **your algorithmic thinking** with **real-world challenges**.  
3️⃣ **Project-Building Skills** – Work on **6 real projects**, scaling up to **1300+ lines of code**.  
4️⃣ **Software Design & Optimization Skills** – Gain **object-oriented design principles & best coding practices**.

🔥 If you're serious about **competitive programming, software engineering, or game development**, this course will set you on the right path.

---

## 🎯 What Will You Learn?

### 🔹 **C++ Programming Fundamentals**
✔️ Variables, Data Types, Loops, Functions, Recursion  
✔️ Debugging, Error Handling, and Performance Optimization  

### 🔹 **Advanced C++ Concepts**
✔️ Pointers & Dynamic Memory Allocation  
✔️ Templates & STL (Vectors, Sets, Maps, Queues, etc.)  
✔️ Exception Handling & Compilation Process  

### 🔹 **Object-Oriented Programming (OOP)**
✔️ Classes & Objects, Encapsulation, Abstraction  
✔️ Inheritance, Polymorphism, Operator Overloading  

### 🔹 **Modern C++ (C++11/14/17)**
✔️ Move Semantics, Smart Pointers, Variadic Templates  
✔️ Lambda Expressions & Functional Programming  
✔️ Advanced STL Features (Unordered Maps, Forward Lists, etc.)  

### 🔹 **Competitive Programming & Problem-Solving**
✔️ **170+ problems** ranging from **easy → hard**  
✔️ Focus on **algorithmic thinking** and **time complexity optimization**  
✔️ Learn techniques used in **Codeforces, AtCoder, and ICPC** competitions  

### 🔹 **Real-World Projects**
✔️ **6 Full Projects** from **basic (50 lines) to advanced (1300+ lines)**  
✔️ Topics include **data processing, memory management, and real-world applications**  
✔️ **Gradual scaling** to prepare for **software development & competitive programming**  

---

## 🧩 My Projects from the Course

### 📘 Project 1: Hospital System Project
Uncover the C++ Hospital System, a powerful project designed to simulate real-world healthcare operations. It manages 20 medical specializations, each with a 5-patient queue, providing structured control over patient admission and doctor interactions.

**🛠️ Features:**
- Multi-Specialization Handling:
Supports up to 20 medical departments, each with a dedicated queue.

- Queue Management:
Efficient patient queuing with dynamic array shifting to manage:

- Regular admissions

- Urgent cases (prioritized at the front)

- Doctor-Patient Interaction:
Allows doctors to pick up patients from their specialization’s queue.

- Patient Information Display:
Neatly prints patient details per specialization, aiding system transparency.

🔗 **[Demo Link](https://youtu.be/aw9oV1O3YEA)**

---

### 📗 Project 2: Library System Project
A console-based application to manage books and users in a small-scale library. It features book search, sorted listings, borrowing/return tracking, and static-capacity storage using arrays.

**🛠️ Features:**

- **Console-Based Menu System**  
  Interactive, menu-driven interface that continuously displays main options after each operation, streamlining admin navigation.

- **Book Data Management**  
  Allows admins to add books, each identified by a unique integer ID, name, and available copy count.

- **Book Search by Name Prefix**  
  Supports flexible book lookups using name prefixes (e.g., searching "Cpp" returns "CppHowToProgram", "CppForDummies").

- **Sorted Book Listings**  
  Enables listing all books sorted either by ID or alphabetically by name.

- **User Data Management**  
  Allows addition of users with unique integer IDs and names for tracking borrowing activity.

- **Book Borrowing Functionality**  
  Users can borrow books only if copies are available. The system reduces the quantity and records the loan per user.

- **Book Return Handling**  
  Increases the available quantity and removes the loan record when a user returns a borrowed book.

- **Borrowed Book Inquiry**  
  Admins can list all users who have borrowed a specific book by providing its name.

- **User Overview with Borrowed Books**  
  Displays all registered users with their IDs, names, and a sorted list of book IDs they have borrowed.

- **Fixed Capacity Storage**  
  Uses static-size arrays (e.g., MAX_BOOKS = 10, MAX_USERS = 10) to manage data, limiting the number of books and users the system can handle.

🔗 **[Demo Link](https://youtu.be/YL3g0Osch2A)**

---

### 📙 Project 3: Ask Me Project
A terminal-based Q&A system with file persistence, user authentication, threaded discussions, and STL-based data management.

**🛠️ Features:**
- **Persistent Data Storage:**  
  Stores users and questions in `users.txt` and `questions.txt`, auto-loaded and saved using helper functions.

- **User Authentication & Management:**  
  Supports Sign Up, Login, and Sign Out with full user info and anonymous-question option. Users stored in `std::map` for fast access.

- **Question & Answer Functionality:**  
  Users can ask/answer targeted questions (anonymously or not), respecting recipient settings.

- **Threaded Conversation Model:**  
  Supports nested replies with parent-child relationships using `std::map<int, std::vector<int>>`.

- **Comprehensive Views:**  
  View questions "To You", "From You", and global answered question feed.

- **Thread-Aware Deletion:**  
  Users can delete their own questions. Deleting a parent question removes the entire thread.

- **Unique ID Generation:**  
  Each user and question has a unique ID for efficient tracking and referencing.

- **Robust Input Validation:**  
  Ensures safe inputs and prevents unauthorized actions (e.g., deleting others’ questions).

- **Efficient STL Usage:**  
  Uses `std::map` and `std::vector` for scalable, fast data operations (O(log N)).

- **Concurrency Limitation (Acknowledged):**  
  Parallel users may receive same IDs due to non-thread-safe generation — noted for future improvement.

🔗 **[Demo Link](https://youtu.be/CVA3948iE2A)**


---

### 📕 Project 4: OOing AskMe System Project
A complete object-oriented refactoring of the original AskMe system, transforming struct-based procedural code into a fully encapsulated, modular architecture. This advanced Q&A platform demonstrates professional OOP principles while maintaining all original functionality with significantly improved maintainability and extensibility.

**🛠️ Features:**

- **Complete OOP Architecture Transformation:**  
  Full refactoring from struct-based design to proper class hierarchies with strict private/public encapsulation, eliminating procedural dependencies and implementing clean object-oriented design patterns.

- **Multi-Manager Class System:**  
  Implements specialized manager classes (`UsersManager`, `QuestionsManager`) alongside core entities (`User`, `Question`), each with single responsibility and minimal coupling for maximum maintainability.

- **Advanced Threaded Discussion Architecture:**  
  Sophisticated conversation threading using `std::map<Question*, std::vector<Question*>>` for efficient parent-child relationships, supporting unlimited nested replies with O(log N) access complexity.

- **Encapsulated User Management System:**  
  Complete user lifecycle with private data members, controlled access through getters, authentication validation, and configurable privacy settings for anonymous question handling.

- **Object-Oriented File Persistence:**  
  Dedicated file I/O operations encapsulated within manager classes, maintaining data integrity across sessions with automatic loading/saving and proper error handling.

- **Professional Memory Management:**  
  Robust constructor/destructor implementation with RAII principles, dynamic memory allocation for scalable collections, and proper cleanup to prevent memory leaks.

- **Enhanced Input Validation & Safety:**  
  Comprehensive bounds checking, null pointer validation, user permission verification, and graceful error recovery with informative feedback messages.

- **Modular File Architecture:**  
  Clean separation across multiple files with organized namespaces (`inAndOutFiles`, `Utils`), proper header guards, and logical component grouping for professional codebase structure.

- **Const-Correct Implementation:**  
  Extensive use of const parameters and methods where data shouldn't be modified, following modern C++ best practices for compile-time safety and optimization.

- **View-Model Separation:**  
  Clear architectural distinction between business logic (model classes) and presentation layer (display methods), implementing MVC-like patterns for better code organization.

- **STL-Driven Data Management:**  
  Heavy utilization of Standard Template Library containers with proper iterators, algorithms, and modern C++ idioms for efficient and readable code.

- **Intelligent ID Generation System:**  
  Smart auto-incrementing identifier system that parses existing file data to generate unique IDs for users and questions, preventing conflicts and maintaining data consistency.

- **Thread-Safe Design Foundation:**  
  Architecture designed with future concurrency in mind, using proper encapsulation and access patterns that can easily accommodate multi-threading enhancements.

🔗 **[Demo Link](https://youtu.be/7YtzbhBO2TE)**

---
### 📘 Project 5: Expedia-Style Booking System (Advanced OOP, UML & System Design)
A large-scale, production-style travel booking system built in Modern C++ (C++17).  
This is the most advanced project in the series — **2000+ lines**, full **OOP architecture**, **UML-driven design**, **real-world workflows**, and **multi-service integrations** inspired by platforms like Expedia.

This project pushes engineering skills beyond syntax exercises into real **system design**, **API abstraction**, **architecture thinking**, and **scalability**.


## 🛠️ Features

### 🌍 **Real-World Functional Domains**
- **Flight Booking Integrations:**  
  AirCanadaOnlineAPI, TurkishAirlinesOnlineAPI  
  Supports full search → filter → select → reserve workflow.

- **Hotel Booking Integrations:**  
  Hilton, Marriott  
  Complete listing, filtering, and reservation pipeline.


### 👤 **User & Payment Infrastructure**
- Secure authentication & session management  
- User profile handling  
- Payment module with masked card display  
- Strong validation & clean workflow control


### ⚙️ **Atomic Transaction System**
Guarantees **all-or-nothing** booking consistency across flights + hotels.  
Prevents corrupted, partial, or inconsistent reservations—critical for multi-service systems.


### 🏗️ **Architecture (OOP + UML)**  
- Fully **UML-driven** modeling and design  
- Interface-based scalability  
- Strict **Single Responsibility Principle (SRP)**  
- Clean separation of concerns between booking, payment, users, and API layers


### 🧩 **Design Patterns Implemented**
- **Adapter Pattern** – unify external APIs under one interface  
- **Template Method** – define shared reservation steps  
- **Prototype Pattern** – cloneable booking objects  
- **Manager / Facade Pattern** – orchestrates high-level system operations


### 🔗 **JSON & API Backbone**
- Uses full JSON parser (`json.hpp`)  
- Structured JSON requests/responses for all API interactions  
- Clean mapping between data, domain, and parsing layers


## 🖼️ UML Diagram    
![Expedia_UML](https://github.com/user-attachments/assets/2bdd3236-1ec9-4e51-beef-4ddac4e9ba79)


## 🔗 Demo  
**[Demo Link](https://youtu.be/2RhSnndd2tE)**

---


## 🔥 Why This Course?
✅ **7X More Practice** than traditional courses  
✅ **Not Just Learning – You Build & Solve!**  
✅ **Perfect for Competitive Programmers & Software Engineers**  
✅ **Clear, Structured, and Short Lectures for Easy Learning**  

---

## 🎓 Course Certificate  
🟦 **Udemy Certificate:**  
<img width="1600" height="1190" alt="image" src="https://github.com/user-attachments/assets/cb1f65cb-c131-431d-b44e-bfdc153bc1bf" />


---

## ⭐ Support
If you find this repository helpful, star ⭐ it and share it with others!

