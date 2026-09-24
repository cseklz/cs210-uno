# Reflection Questions
> In `LinkedList::deleteFront()`, why does it take two separate `delete` calls instead of one?
> Name exactly what each one frees, and name the two `new` calls back in the program responsible
> for putting them on the heap in the first place.
>> `LinkedList::deleteFront()` takes two separate `delete` calls as it first frees the memory allocated
>> for the `data` pointer when `new int(...)` or `new data(...)` is called. The memory allocated for the
>> `Node` object by new Node<T>(value) inside `LinkedList::addFront()` is then deleted. These are both
>> separate objects on the heap.

> `ArrayList` never had a destructor before today. Explain, in your own words, why switching
> from `T data[CAPACITY]` to `T* data [CAPACITY]` is what made a destructor necessary, and what
> would happen if you forgot to write one. Would you get a compiler error? Why or why not?
>> With `T data[CAPACITY]`, the memory allocated for the array is automatically freed when the list is destroyed.
>> However, with 'T* data[CAPACITY]', the array is filled with only addresses. So, whenever a `new` object is created,
>> you must manually free the memory with some sort of destructor.

> `search()` and `addFront()` both take a `T*`, but they treat that pointer completely differently.
> Explain the difference in terms of ownership: which one is allowed to `delete` what you hand it,
> and which one is never allowed to?
>> `addFront()` takes ownership of the pointer and is allowed to `delete` it, while `search()` simply borrows
>> the pointer temporarily for comparison. `search()` is never allowed to `delete` the pointer.

> You swapped `LinkedList<T>` for `ArrayList<T>` inside `makeList()` and reran `main.cpp` without
> changing a single line there. What two mechanisms, by name, made that possible?
>> The function `makeList()` hides the implementation details of the list, returning a pointer to a `List<T>`.
>> The runtime polymorphism calls the correct override of the functions declared. This allows the caller to use
>> a common interface to interact with different implementations of the `List<T>` class.

> Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
> thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
> your own words and without copying the guide’s wording, the smallest example you can think
> of where leaving it out would cause a real problem.
>> I chose the keyword `override` as it allows the compiler to check that the function being overridden
>> actually exists in the base class. Without `override` if I accidentally left const off search(), the
>> compiler would catch the error and prevent the code from compiling.