# Dynamic Decorator Pattern

- The **Decorator (Wrapper)** adds new responsibilities and capabilities to the object.
It is an alternative to generating subclasses in order to extend functionality.
- The **Dynamic Decorator** inherits the base class of the object it is going to wrap to have the same interface.
The wrapped class is contained in the class member fields.
- However, when adding functionality to the wrapped class, the decorator does not inherit its interface, which is a problem.
![Decorator](https://user-images.githubusercontent.com/107110699/230770874-6926420c-67f2-4d93-8132-c0cef807d9ca.png)
