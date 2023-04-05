# Strategy Pattern

- **Strategy** defines a family of algorithms, encapsulates each of them and makes them interchangeable. The strategy allows you to change algorithms independently of the clients
who use them.
- The **Specific strategies** are inherited from the abstract **Strategy** class.
- The **Specific strategy** is passed to the **Context** class, after which it calls a function **DoAlgorithm()** that common to the all strategies.
![image](https://user-images.githubusercontent.com/107110699/230052834-747f9d4e-b730-4686-97a7-73391b292262.png)
