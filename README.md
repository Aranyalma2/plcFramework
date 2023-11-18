# plcFramework

C++ microcontroller library for universal block-base programming. Used by SzomorXVigyor programmer and compiller module.

## IOs of Blocks

---

### **Logical Blocks**

<p>In the case of non-binary input values (where defined), a logical conversion takes place first. (Everything that is exactly zero is 0. Anything else is 1)<p>

**_AND/NAND_**

> Description: Logical AND operator between 2 input value, return result and inverted result.

| ID  | Inputs     | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | ---------- | :-----: | :------: | :-------------: | :-----------: |
|  0  | Parameter1 |    X    |    X     |  Any (Binary)   |       0       |
|  1  | Parameter2 |    X    |    X     |  Any (Binary)   |       0       |

| ID  | Outputs         |
| :-: | --------------- |
|  0  | Result          |
|  1  | Inverted result |

---

**_OR/NOR_**

> Description: Logical OR operator between 2 input value, return result and inverted result.

| ID  | Inputs     | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | ---------- | :-----: | :------: | :-------------: | :-----------: |
|  0  | Parameter1 |    X    |    X     |  Any (Binary)   |       0       |
|  1  | Parameter2 |    X    |    X     |  Any (Binary)   |       0       |

| ID  | Outputs         |
| :-: | --------------- |
|  0  | Result          |
|  1  | Inverted result |

---

**_NOT_**

> Description: Logical NOT operator, invert the input value.

| ID  | Inputs     | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | ---------- | :-----: | :------: | :-------------: | :-----------: |
|  0  | Parameter1 |    X    |    X     |  Any (Binary)   |       0       |

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

**_SELECTOR_**

> Description: The output gives the selected input value by selection value (0/1)

| ID  | Inputs          | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | --------------- | :-----: | :------: | :-------------: | :-----------: |
|  0  | Parameter1      |    X    |    X     |       Any       |       0       |
|  1  | Parameter2      |    X    |    X     |       Any       |       0       |
|  2  | Selection value |    X    |    X     |  Any (Binary)   |       0       |

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

**_COUNTER_**

> Description: The output gives the input values ​​fulfilled on the basis of the selective condition.

| ID  | Inputs                  | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | ----------------------- | :-----: | :------: | :-------------: | :-----------: |
|  0  | Counting pulse          |    X    |    X     |  Any (Binary)   |       0       |
|  1  | Counting detaction mode |    X    |    X     |  Any (Binary)   |       0       |
|  2  | Start number            |    X    |    X     |       Any       |       0       |
|  3  | Count step              |    X    |    X     |       Any       |       0       |
|  4  | Reset pulse             |    X    |    X     |  Any (Binary)   |       0       |
|  5  | Reset detaction mode    |    X    |    X     |  Any (Binary)   |       0       |

_Notes:\
Counting detaction mode value: 0: low to high; 1: high to low\
Reset detaction mode value: 0: low to high; 1: high to low_

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

### **Math Blocks**

**_BASIC MATH_**

> Description: Performs the selected mathematical operation on the inputs and places it on the output

| ID  | Inputs        | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | ------------- | :-----: | :------: | :-------------: | :-----------: |
|  0  | Parameter1    |    X    |    X     |       Any       |       0       |
|  1  | Parameter2    |    X    |    X     |       Any       |       0       |
|  2  | Opertion mode |    X    |    X     |       Any       |       0       |

_Notes:\
Opertion mode table_
| Value | Operand |
| :---: | -------- |
| 0 | ADD |
| 1 | SUBTRACT |
| 2 | MULTIPLY |
| 3 | DIVIDE |

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

### **Controller Blocks**

**_PID_**

> Description: A proportional–integral–derivative controller (PID controller) attempts to correct the error between a measured process variable and a desired set point by calculating and then outputting a corrective action that can adjust the process accordingly.

| ID  | Inputs       | Dynamic | Constans | Range (Preferd) | Default value |
| :-: | ------------ | :-----: | :------: | :-------------: | :-----------: |
|  0  | Actual value |    X    |    X     |       Any       |       0       |
|  1  | Set point    |    X    |    X     |       Any       |       0       |
|  2  | Proportional |    X    |    X     |       Any       |       0       |
|  3  | Integral     |    X    |    X     |       Any       |       0       |
|  4  | Derivative   |    X    |    X     |       Any       |       0       |
|  5  | WorkMode     |    X    |    X     |  Any (Binary)   |       0       |

_Notes:\
Counting detaction mode value: 0: low to high; 1: high to low\
Reset detaction mode value: 0: low to high; 1: high to low_

| ID  | Outputs |
| :-: | ------- |
|  0  | Result  |

---

### **Hardware programable IO**

**_Analog Input_**

> Description: Read the specified hardware input interface to read in data in analog format

| ID  | Inputs       | Dynamic | Constans |    Range (Preferd)     |  Default value   |
| :-: | ------------ | :-----: | :------: | :--------------------: | :--------------: |
|  0  | Hardware pin |    -    |    X     | Any (Pre-Defined list) | Not user defined |

| ID  | Outputs   |
| :-: | --------- |
|  0  | Read data |

**_Digital Input_**

> Description: Read the specified hardware input interface to read in data in digital format

| ID  | Inputs       | Dynamic | Constans |    Range (Preferd)     |  Default value   |
| :-: | ------------ | :-----: | :------: | :--------------------: | :--------------: |
|  0  | Hardware pin |    -    |    X     | Any (Pre-Defined list) | Not user defined |

| ID  | Outputs   |
| :-: | --------- |
|  0  | Read data |

**_Analog Output_**

> Description: Write pwm (analog) value to hardware pin

| ID  | Inputs        | Dynamic | Constans |    Range (Preferd)     |  Default value   |
| :-: | ------------- | :-----: | :------: | :--------------------: | :--------------: |
|  0  | Hardware pin  |    -    |    X     | Any (Pre-Defined list) | Not user defined |
|  1  | PWM value     |    X    |    X     |          Any           |        0         |
|  2  | Range minimum |    X    |    X     |          Any           |        0         |
|  3  | Range maximum |    X    |    X     |          Any           |       100        |

_Notes:
The "Range minimum" and "Range maximum" refers to the value range of "PWM value"._

| ID  | Outputs |
| :-: | ------- |

**_Digital Output_**

> Description: Write digital value to hardware pin

| ID  | Inputs       | Dynamic | Constans |    Range (Preferd)     |  Default value   |
| :-: | ------------ | :-----: | :------: | :--------------------: | :--------------: |
|  0  | Hardware pin |    -    |    X     | Any (Pre-Defined list) | Not user defined |

| ID  | Outputs |
| :-: | ------- |
