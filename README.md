# plcFramework

C++ microcontroller library for universal block-base programming. Used by my WEB programmer and compiller module.

## Block IOs

---

### **Logical Blocks**

<p>In the case of non-binary input values (where defined), a logical conversion takes place first [^1].<p>

**_AND/NAND_**

> Description: Logical AND operator between 2 input value, return result and inverted result.

| ID  | Inputs     | Dynamic | Constans | Range (Preferd) |
| :-: | ---------- | :-----: | :------: | :-------------: |
|  0  | Parameter1 |    X    |    X     |  Any (Binary)   |
|  1  | Parameter2 |    X    |    X     |  Any (Binary)   |

| ID  | Outputs         |
| :-: | --------------- |
|  0  | Result          |
|  1  | Inverted result |

---

**_OR/NOR_**

> Description: Logical OR operator between 2 input value, return result and inverted result.

| ID  | Inputs     | Dynamic | Constans | Range (Preferd) |
| :-: | ---------- | :-----: | :------: | :-------------: |
|  0  | Parameter1 |    X    |    X     |  Any (Binary)   |
|  1  | Parameter2 |    X    |    X     |  Any (Binary)   |

| ID  | Outputs         |
| :-: | --------------- |
|  0  | Result          |
|  1  | Inverted result |

---

**_NOT_**

> Description: Logical NOT operator, invert the input value.

| ID  | Inputs     | Dynamic | Constans | Range (Preferd) |
| :-: | ---------- | :-----: | :------: | :-------------: |
|  0  | Parameter1 |    X    |    X     |  Any (Binary)   |

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

**_SELECTOR_**

> Description: The output gives the input values ​​fulfilled on the basis of the selective condition.

| ID  | Inputs              | Dynamic | Constans | Range (Preferd) |
| :-: | ------------------- | :-----: | :------: | :-------------: |
|  0  | Parameter1          |    X    |    X     |       Any       |
|  1  | Parameter2          |    X    |    X     |       Any       |
|  2  | Selection condition |    X    |    X     |       Any       |

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

**_COUNTER_**

> Description: The output gives the input values ​​fulfilled on the basis of the selective condition.

| ID  | Inputs                  | Dynamic | Constans | Range (Preferd) |
| :-: | ----------------------- | :-----: | :------: | :-------------: |
|  0  | Counting pulse          |    X    |    X     |  Any (Binary)   |
|  1  | Counting detaction mode |    X    |    X     |  Any (Binary)   |
|  2  | Start number            |    X    |    X     |       Any       |
|  3  | Count step              |    X    |    X     |       Any       |
|  4  | Reset pulse             |    X    |    X     |  Any (Binary)   |
|  5  | Reset detaction mode    |    X    |    X     |  Any (Binary)   |

_Notes:\
Counting detaction mode value: 0: low to high; 1: high to low\
Reset detaction mode value: 0: low to high; 1: high to low_

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

[^1]: Everything that is exactly zero is 0. Anything else is 1
