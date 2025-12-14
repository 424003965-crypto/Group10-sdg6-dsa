# Smart pH Monitoring System for Water Quality Using IoT

**SDG Goal:** United Nations Sustainable Development Goal 6 (SDG 6) – Clean Water and Sanitation  

---

## Project Overview

Access to clean drinking water is a global challenge, with over 2 billion people lacking safe water. This project addresses:

- Health risks from unsafe water (e.g., diarrhea causing 485,000 deaths annually).  
- High cost of standard water testing kits ($20–$50).  
- Difficulty detecting unsafe pH levels in communities without equipment.  

The system is implemented in C++ and allows users to input pH and water color data, automatically classify water quality, provide safety tips, and store results in multiple data structures for easy access and analysis.

---

## Data Structures Used

1. **Array** – Central storage for all water test records; allows fast indexing, traversal, sorting, and searching.  
2. **Stack** – Implements undo functionality using LIFO; keeps track of recent tests.  
3. **String** – Stores human-readable classifications (“Filtered”, “Not Filtered”) and safety tips.  
4. **Sorting** – Bubble sort organizes tests by pH for easy comparison.  
5. **Trees (BST)** – Stores water tests hierarchically by pH; enables sorted traversal and efficient search.

---

## Installation / Setup

1. Clone the repository:  
```bash
git clone https://github.com/424003965-crypto/Group10-sdg6-dsa.git
```
Here’s a clean **Usage Instructions** section focused only on **array, sorting, string, stack, and trees**:

---

## Usage Instructions

### Array (All Tests)

* Displays all water test records stored in the array.
* Records are shown in insertion order.
* Supports searching by ID using linear or binary search.

### Stack (Recent Tests / Undo Feature)

* Stores the most recent water tests in LIFO order.
* Shows recent tests first.
* Undo the last test by popping it from the stack and removing it from the array.

### String (Status & Tips)

* Stores water classification (`"Filtered"` / `"Not Filtered"`) and safety tips.
* Dynamically displays advice based on pH and color code.

### Sorting (By pH)

* Sorts the array of water tests in ascending order of pH using Bubble Sort.
* Helps users compare water quality from lowest to highest pH.

### Trees (BST View)

* Organizes water tests in a Binary Search Tree based on pH.
* Allows sorted traversal from lowest to highest pH values.


## Contributors

* **Jervy Arandia, Angelo Nario** – Presentation (PPT)
* **Alquin Ferrer** – Documentation (DOCU)
* **Christian James Cayetano, Jhon Seena Swing** – Coding (CODE)

