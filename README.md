Reverse Polish Calculator
👥 Group Members
M.H.F. Hafsa (2023t01860)
B.S. Amana (2023t01846)
📌 Description
This project implements a Reverse Polish Calculator using stack data structure in C.

⚙️ Features
Supports +, -, *, /
Handles invalid expressions
Handles division by zero
📖 Introduction
Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical representation where operators come after operands.

Example: a + b * c → a b c * +

🧠 Method
Stack is used (LIFO)
Tokens processed one by one
Numbers → push to stack
Operators → pop, calculate, push result
🧪 Test Cases
Input	Output
7 2 +	9.00
15 5 /	3.00
9 1 8 + 4 * + 3 -	42.00
🏁 Conclusion
This project successfully evaluates postfix expressions using stack.

