👥 Group Members

J.J. Banu (2023t01852)
W.G.N.T. Premarathne (2023t01890)

📌 Description
This project implements a Reverse Polish Calculator using stack data structure in C.

⚙️ Features
Supports +, -, *, /
Handles invalid expressions
Handles division by zero

📖 Introduction
Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical representation where operators come after operands.
Example:
a + b * c → a b c * +

🧠 Method
Stack is used (LIFO)
Tokens processed one by one
Numbers → push to stack
Operators → pop, calculate, push result

🧪 Test Cases

| Input                        | Output |
| -----------------            | ------ |
| 4 3  +                       | 7.00   |
| 75 5 /                       | 15.00   |
| 8 2 5 * + 1 3 2 * + 4 - /    | 6.00  |

🏁 Conclusion
This project successfully evaluates postfix expressions using stack.


