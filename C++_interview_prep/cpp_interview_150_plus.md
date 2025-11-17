# C++ Interview Questions — 150+ Answers (Concise + Sample Code)

> Compact answers designed for placement prep (7–10 LPA). Each question is answered briefly; sample code included for common code questions.

---

## SECTION 1 — C++ BASICS

**1. What is C++?**  
C++ is a general-purpose, statically-typed, compiled programming language supporting procedural, object-oriented, and generic programming. It is an extension of C with classes, templates, and the Standard Library.

**2. Difference between C and C++?**  
C is procedural; C++ adds OOP, classes, exceptions, templates, function overloading, and stronger type safety.

**3. What is OOPS?**  
OOPS (Object-Oriented Programming) is a paradigm using objects and classes to model real-world entities via encapsulation, abstraction, inheritance, and polymorphism.

**4. What are the features of C++?**  
Compiled, fast, object-oriented, generic programming (templates), RAII, STL, low-level memory control.

**5. What is a compiler?**  
A program that translates source code into machine code or intermediate code.

**6. What is a linker?**  
A tool that combines object files and libraries to create an executable, resolving symbol references.

**7. What is the difference between compile-time error and runtime error?**  
Compile-time errors are detected during compilation (syntax/type errors). Runtime errors occur while the program runs (exceptions, segmentation faults).

**8. What is a header file?**  
A file (.h/.hpp) containing declarations (functions, classes, macros) to be included with `#include`.

**9. Why do we use `using namespace std`?**  
To avoid writing `std::` before names from the standard namespace. (Prefer explicit `std::` in production.)

**10. What is an inline function?**  
A request to the compiler to replace function calls with function body to reduce call overhead (compiler may ignore).

**11. What is a reference variable?**  
An alias for an existing variable. Syntax: `int &r = x;`. Cannot be null and must be initialized.

**12. Difference between pointer and reference?**  
Pointer can be null and reseated; reference must bind on init and cannot be reseated.

**13. What is the size of an empty class?**  
Typically 1 byte to ensure unique addresses for distinct objects.

**14. What is namespace?**  
A scope to group identifiers to avoid name collisions (`namespace ns { ... }`).

**15. What are static variables?**  
Variables with static storage duration; for class members they are shared among all objects.

**16. What is `const` keyword?**  
Specifies immutability — e.g., `const int`, `int * const`, `const char*`.

**17. Difference between `const int*` and `int* const`?**  
`const int*` = pointer to const int (value read-only). `int* const` = const pointer to int (pointer cannot change).

**18. What is function signature?**  
Function name + parameter types (not return type). Used for overload resolution.

**19. What are storage classes?**  
auto, static, extern, register (storage duration/linkage/visibility).

**20. What is the difference between stack and heap memory?**  
Stack: automatic, scoped, fast. Heap: dynamic, manual allocation, persistent until delete.

---

## SECTION 2 — OOPS BASICS

**21. What are the 4 pillars of OOPS?**  
Encapsulation, Abstraction, Inheritance, Polymorphism.

**22. What is Class?**  
A blueprint for objects; contains data members and member functions.

**23. What is Object?**  
An instance of a class occupying memory.

**24. What is Encapsulation?**  
Wrapping data and functions together and restricting direct access via access specifiers.

**25. What is Abstraction?**  
Hiding implementation details and exposing only necessary interfaces.

**26. Encapsulation vs Abstraction?**  
Encapsulation bundles data and methods; abstraction hides complexity. They overlap.

**27. What is Inheritance?**  
Mechanism for deriving a new class from an existing one to reuse code.

**28. What is Polymorphism?**  
Ability of one interface to have multiple implementations (compile-time and runtime).

**29. Types of polymorphism in C++?**  
Compile-time (overloading) and runtime (overriding via virtual functions).

**30. Why OOPS is important?**  
For modular, maintainable, reusable software design.

**31. What is data hiding?**  
Restricting access to internal object state (private/protected).

**32. What is reusability?**  
Using existing code (via inheritance, composition) to avoid duplication.

**33. What are access modifiers?**  
public, private, protected control visibility of members.

**34. Default access specifier in C++?**  
`class` → private, `struct` → public.

**35. What is an abstract class?**  
A class with at least one pure virtual function (`virtual void f() = 0;`); cannot be instantiated.

---

## SECTION 3 — CONSTRUCTORS & DESTRUCTORS

**36. What is a constructor?**  
Special member function called on object creation to initialize members.

**37. Types of constructors?**  
Default, parameterized, copy, move (C++11), delegating.

**38. Can constructor be private?**  
Yes (useful for Singleton or factory patterns).

**39. Can constructor return value?**  
No.

**40. What is a copy constructor?**  
Constructor initializing object from another object: `Class(const Class&)`.

**41. Deep Copy vs Shallow Copy?**  
Shallow: copies pointers (shared memory). Deep: allocates new memory and copies content.

**42. Default copy constructor behaviour?**  
Member-wise shallow copy (bitwise for POD).

**43. When is copy constructor called?**  
Object initialization from another, passing by value, returning by value (may be elided).

**44. What is a destructor?**  
Special member `~Class()` called when object lifetime ends to release resources.

**45. Can destructor be overloaded?**  
No; only one destructor per class.

**46. Can destructor be virtual?**  
Yes, when deleting derived objects via base pointer to ensure proper cleanup.

**47. Why destructor should NOT throw exception?**  
Throwing during stack unwinding can call `terminate()`. Use `noexcept`.

---

## SECTION 4 — INHERITANCE

**48. What are types of inheritance?**  
Single, multilevel, multiple, hierarchical, hybrid.

**49. What is single inheritance?**  
One base, one derived.

**50. What is multilevel inheritance?**  
A → B → C chain.

**51. What is multiple inheritance?**  
A class inherits from multiple base classes.

**52. What is hierarchical inheritance?**  
One base, multiple derived.

**53. What is hybrid inheritance?**  
Combination of types.

**54. What is diamond problem?**  
Multiple inheritance where base appears multiple times via different paths causing ambiguity.

**55. How to solve diamond problem?**  
Use virtual inheritance (`class B : virtual public A`).

**56. What is virtual inheritance?**  
Ensures single shared base subobject across derived chain.

**57. Does constructor get inherited?**  
Constructors are not inherited, but base constructors are called during derived construction.

**58. Order of constructor/destructor calls in inheritance?**  
Constructors: base → derived. Destructors: derived → base.

**59. Can private members be inherited?**  
Yes but not accessible in derived classes.

**60. What is protected inheritance?**  
Access specifier where public/protected base members become protected in derived.

**61. What is override keyword?**  
C++11 keyword to indicate a virtual function overrides base virtual; compiler checks signature.

**62. What is final keyword?**  
Prevents further overriding (`virtual void f() final;`) or inheritance (`class A final`).

---

## SECTION 5 — POLYMORPHISM

**63. What is function overloading?**  
Multiple functions with same name different parameter lists.

**64. Rules of function overloading?**  
Different parameter types/number/order. Return type alone doesn't suffice.

**65. Can we overload based on return type only?**  
No.

**66. What is operator overloading?**  
Defining operator behavior for user-defined types via `operator+`, etc.

**67. Which operators cannot be overloaded?**  
`:: . .* ?: sizeof typeid` (some implementation-defined); also cannot create new operators.

**68. What is function overriding?**  
Derived provides implementation for base virtual function (same signature).

**69. Overloading vs Overriding?**  
Overloading = same scope, different signatures. Overriding = base+derived same signature at runtime.

**70. What is virtual function?**  
A function declared `virtual` in base to allow runtime dispatch.

**71. Why virtual functions?**  
To achieve runtime polymorphism/dynamic binding.

**72. Runtime vs Compile-time polymorphism?**  
Runtime: virtual/overriding. Compile-time: overloading/templates/inline.

**73. What is pure virtual function?**  
`virtual void f() = 0;` — no definition, makes class abstract.

**74. What is abstract class?**  
Class that cannot be instantiated; used to define interface.

**75. Can we create object of abstract class?**  
No.

**76. What is VTable?**  
Compiler-generated table of addresses for virtual functions used for dynamic dispatch.

**77. What is vptr?**  
Per-object hidden pointer pointing to the class VTable.

**78. When is VTable created?**  
At compile/link time for classes with virtual functions.

**79. When is vptr created?**  
Embedded in each object at runtime; set during construction.

**80. What is dynamic binding?**  
Resolving calls at runtime using vtable.

**81. What is static binding?**  
Compile-time resolution of function calls.

**82. Why constructor cannot be virtual?**  
Because virtual dispatch needs an object; constructor creates object.

---

## SECTION 6 — POINTERS & MEMORY

**83. What is pointer?**  
A variable storing memory address.

**84. Null pointer kya hota hai?**  
Pointer with value `nullptr` indicating it points to nothing.

**85. Dangling pointer kya hota hai?**  
Pointer pointing to deallocated/freed memory.

**86. Void pointer?**  
`void*` generic pointer that can point to any data type; needs cast to dereference.

**87. Function pointer?**  
Pointer referencing function address: `int (*fp)(int)`.

**88. `new` vs `malloc`?**  
`new` calls constructor and returns typed pointer; `malloc` allocates raw memory and returns void*, no ctor.

**89. `delete` vs `free`?**  
`delete` calls destructor then frees memory; `free` only releases memory allocated by malloc.

**90. What is memory leak?**  
Allocated memory not freed, causing resource loss.

**91. What is double delete?**  
Calling delete twice on same memory leading to undefined behavior.

**92. What is segmentation fault?**  
Accessing illegal memory causing OS to terminate program.

**93. What is smart pointer?**  
Class template that manages dynamic memory automatically (`unique_ptr`, `shared_ptr`, `weak_ptr`).

**94. Types of smart pointers?**  
unique_ptr, shared_ptr, weak_ptr (and older auto_ptr deprecated).

**95. unique_ptr vs shared_ptr?**  
unique_ptr = sole ownership; shared_ptr = shared ownership with refcount.

**96. What is weak_ptr?**  
Non-owning observer of object managed by shared_ptr to avoid cyclic references.

**97. What is cyclic reference?**  
Two objects hold shared_ptrs to each other causing refcount never reaching zero.

**98. How weak_ptr solves cyclic reference?**  
weak_ptr doesn't increase refcount; breaks cycle so objects can be destroyed.

**99. What is RAII?**  
Resource Acquisition Is Initialization — tie resource lifetime to object lifetime.

**100. How smart pointers use RAII?**  
Constructor allocates resource; destructor frees it automatically.

**101. What is placement new?**  
Allocate object in pre-allocated memory: `new (ptr) T(args)`.

**102. `sizeof` vs `strlen`?**  
`sizeof` returns compile-time size in bytes; `strlen` returns length of C-string at runtime.

---

## SECTION 7 — EXCEPTION HANDLING

**103. What is exception?**  
An error condition that can be thrown and caught to manage runtime errors.

**104. What is try-catch?**  
`try` encloses risky code; `catch` handles thrown exceptions.

**105. What is throw?**  
Statement to signal an exception: `throw expr;`.

**106. Can constructors throw exceptions?**  
Yes; if constructor throws, object is not created and destructors of fully constructed members run.

**107. Can destructors throw exceptions?**  
Should not; throwing during stack unwinding triggers `terminate()`.

**108. What is catch(...)?**  
Catch-all handler for any exception type.

**109. What is stack unwinding?**  
Process of destroying local objects as control exits from `try` block to `catch`.

**110. What is rethrowing exception?**  
`throw;` inside catch rethrows same exception.

**111. What is standard exception class?**  
`std::exception` base class with `what()` method; derived types like `runtime_error`.

**112. Difference between error and exception?**  
Error: serious problem (hardware/OS). Exception: manageable runtime situation.

---

## SECTION 8 — TEMPLATES

**113. What are templates?**  
BluePrints for generating functions/classes for different types at compile time.

**114. Class template?**  
`template <typename T> class MyClass { T val; };`.

**115. Function template?**  
`template <typename T> T add(T a, T b) { return a + b; }`.

**116. Template specialization?**  
Provide special implementation for certain type `template<> class MyClass<char*> { ... };`.

**117. Can constructors be templated?**  
Yes, constructors can be templates inside class templates or normal classes (C++11).

**118. What is STL?**  
Standard Template Library — containers, algorithms, iterators implemented using templates.

**119. Why STL is based on templates?**  
For generic, type-safe, zero-overhead abstractions.

**120. Difference between macro and template?**  
Macro = preprocessor text substitution, no type safety. Template = type-safe, compiler-checked.

**121. What is type inference?**  
Compiler deduces template types from call (e.g., `add(1,2.0)` deduces mixed types via template argument deduction rules).

**122. What is auto keyword?**  
C++11 feature to deduce variable type from initializer.

---

## SECTION 9 — STL

**123. Difference between vector and array?**  
vector is dynamic and has methods; array (C-style or std::array) has fixed size at compile time (std::array fixed but object-like).

**124. How vector grows internally?**  
Allocates more capacity (often double) when size exceeds capacity; amortized O(1) push_back.

**125. vector capacity vs size?**  
size = number of elements; capacity = allocated storage amount.

**126. vector erase complexity?**  
O(n) (elements shifted).

**127. vector push_back complexity?**  
Amortized O(1), worst-case O(n) when resizing.

**128. What is pair?**  
`std::pair<T1,T2>` holds two heterogeneous values.

**129. map vs unordered_map?**  
map = ordered (balanced tree) O(log n); unordered_map = hash-based average O(1), no order.

**130. set vs unordered_set?**  
set ordered, O(log n); unordered_set hash-based average O(1).

**131. When to use priority_queue?**  
For retrieving maximum/minimum efficiently (heaps) — Dijkstra, streaming k-largest.

**132. min-heap priority_queue kaise banate?**  
`priority_queue<int, vector<int>, greater<int>> pq;`

**133. stack vs queue?**  
stack LIFO, queue FIFO.

**134. BFS me queue kyu use hota hai?**  
Queue ensures level-order traversal (FIFO).

**135. DFS me stack kyu use hota hai?**  
Stack (explicit or call stack) supports LIFO needed for depth-first traversal.

**136. lower_bound vs upper_bound?**  
lower_bound returns first not less than key; upper_bound returns first greater than key.

**137. What is comparator?**  
A callable that defines custom ordering for algorithms/containers.

**138. How to sort using custom comparator?**  
`sort(v.begin(), v.end(), [](int a,int b){return a>b;});`

**139. What is iterators in STL?**  
Objects that point to elements and allow traversal (like pointers).

**140. iterator vs pointer?**  
Iterator abstract interface; pointer is a kind of iterator.

**141. What is multimap?**  
Associative container allowing multiple elements with same key.

**142. What is multiset?**  
Set that allows duplicate keys.

---

## SECTION 10 — ADVANCED C++

**143. What are lambda functions?**  
Anonymous functions with capture list, parameters, and body.

**144. What is capture list?**  
Indicates which outer-scope variables are captured and how (`[]`, `[&]`, `[=]`, `[x]`, `[&x]`).

**145. What is mutable lambda?**  
Allows modification of captured-by-value variables inside lambda.

**146. How to use lambda in sort()?**  
`sort(v.begin(), v.end(), [](int a,int b){ return a<b; });`

**147. What is move semantics?**  
Mechanism to transfer resources from temporary (rvalue) to new object without copying.

**148. What is lvalue and rvalue?**  
lvalue refers to an object with identity (can take address). rvalue is temporary prvalue expression.

**149. What is rvalue reference (&&)?**  
Reference that can bind to rvalues for move semantics.

**150. What is std::move?**  
Casts to rvalue reference to enable move operations (doesn't move by itself).

**151. What is deep copy constructor?**  
Copy constructor that allocates separate resources to avoid shared mutable state.

**152. What is rule of 3?**  
If a class needs custom destructor, copy constructor or copy assignment operator, it probably needs all three.

**153. What is rule of 5?**  
With move semantics, if you define destructor, copy/move ctor, copy/move assignment, define all five.

**154. What is rule of 0?**  
Prefer types that manage resources (RAII) so you don't need to define special members.

**155. What is memory alignment?**  
Arrangement of data in memory so objects' addresses meet alignment constraints for performance/architecture.

**156. What is static binding?**  
Compile-time binding of function calls.

**157. What is dynamic binding?**  
Runtime resolution via virtual functions.

**158. Virtual destructor kya hota hai?**  
Destructor declared virtual in base so deleting derived object via base pointer calls derived destructor.

**159. Why “override” keyword is important?**  
Ensures function overrides a base virtual; compiler error on mismatch.

**160. How VTable works internally?**  
Compiler creates table of function pointers for virtual functions and sets object's vptr to proper table; calls use indirection via vptr.

---

## Final Notes & Sample Code Index

Below are small, ready-to-run snippets for common concepts.

### A. Basic class, constructor, destructor, copy constructor example
```cpp
#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    string name;
    int *marks;
    Student(string n, int m) : name(n), marks(new int(m)) {}
    // Copy constructor (deep copy)
    Student(const Student &s) : name(s.name), marks(new int(*s.marks)) {}
    ~Student() { delete marks; }
};
int main() {
    Student s1("Satyam", 85);
    Student s2 = s1; // deep copy
    cout << *s1.marks << " " << *s2.marks << endl;
}
```

### B. Virtual function / VTable example
```cpp
#include <iostream>
using namespace std;
class Base { public: virtual void f(){ cout<<"Base
"; } };
class Derived : public Base { public: void f() override { cout<<"Derived
"; } };
int main() { Base* p = new Derived(); p->f(); delete p; }
```

### C. unique_ptr / shared_ptr example
```cpp
#include <memory>
#include <iostream>
using namespace std;
int main(){
    auto p = make_unique<int>(10);
    auto s1 = make_shared<int>(20);
    auto s2 = s1;
    cout<<*p<<' '<<*s1<<' '<<s1.use_count()<<endl;
}
```

---

*If you’d like, I can also:*
- Expand each question into a longer explanation with more sample code.
- Produce a printable PDF or a one-page cheat sheet.
- Create targeted mock interview flashcards from these Q&As.

