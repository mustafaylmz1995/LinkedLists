# LinkedLists

**Linked List Implementations in C — Singly, Doubly, and Circular Variants**

![C](https://img.shields.io/badge/Language-C-blue)
![DSA](https://img.shields.io/badge/DSA-Data_Structures-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## 📖 Overview

Complete linked list library in C. Implements singly linked, doubly linked, and circular linked list variants with full CRUD operations, sorting, and traversal algorithms.

## 📦 Repository Structure

```
LinkedLists/
├── src/           # Source implementations (.c)
├── include/       # Header files (.h)
└── examples/      # Usage examples
```

## 📚 Operations

| Operation | Singly | Doubly | Circular | Time Complexity |
|:----------|:------:|:------:|:--------:|:---------------:|
| Insert at head | ✅ | ✅ | ✅ | O(1) |
| Insert at tail | ✅ | ✅ | ✅ | O(n) |
| Delete by value | ✅ | ✅ | ✅ | O(n) |
| Search | ✅ | ✅ | ✅ | O(n) |
| Reverse | ✅ | ✅ | ❌ | O(n) |
| Sort (bubble) | ✅ | ✅ | ✅ | O(n\u00b2) |

## 🚀 Quick Start

```c
#include \"linked_list.h\"

int main() {
    LinkedList* list = ll_create();
    ll_insert_head(list, 42);
    ll_insert_tail(list, 7);
    ll_print(list);  // 42 -> 7 -> NULL
    ll_free(list);
    return 0;
}
```

## 🛠 Requirements

- C99 compiler (GCC, Clang, MSVC)
- Make or CMake

## 📄 License

MIT License.

## 📬 Contact

**Mustafa YILMAZ** — Embedded Software Engineer

[![GitHub](https://img.shields.io/badge/GitHub-Follow-black)](https://github.com/mustafaylmz1995)
