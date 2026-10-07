# Reflection Questions

> 1. Why does `concat` only need to work between two lists of the same representation? What would you
     have to do differently, or what would go wrong, if you tried to make it work between a `LinkedList`
     and an `ArrayList`?
> >  `concat` only needs to work between lists of the same representation because it is designed as a
     transfer that directly accesses private details `head_` or `data_` that are specific to each type
     using `dynamic_cast`. If we tried to concatenate a `LinkedList` and an `ArrayList`, we could not move
     pointers or copy the array. We would have to unpack the data from one type of list and allocate
     individual elements into the other. Concatenating an `Arraylist` to a `LinkedList` would require a
     new `Node<T>` for every element, breaking the $O(1)$ concatenation function. If done in reverse, we
     risk capacity overflow since LinkedList doesn't store size.

> 2. Walk through `reverse()` on your linked list: name the three pointers you need alive at once, and
     explain why losing track of any one of them mid-loop corrupts the list.
> >  We have the three pointers `previous`, `current`, and `next` in order to `reverse()` the linked list.
     In each loop iteration, we save `next = current->next`, flip the `Node<T>` pointer that `current` is
     pointing to with `current->next = previous`, and advance both `previous = current` and `current = next`.
     Losing track of `next` before redirecting `current->next` would orphan and leak the rest of the
     unvisited list on the heap. Losing track of `previous` would leave no target for current to point
     backward to.

> 3. `addAnywhere` and `deleteAnywhere` both need a bounds check. What’s the valid range for position in
     each, and what does your implementation do if a caller passes a position outside it?
> >  For `addAnywhere`, the valid range of position is `[0, size_]` inclusive. For `deleteAnywhere`, the
     valid range is `[0, size_ - 1]` inclusive, because 0-based indexing makes `size_` past the last element.
     If the caller passes a position outside of these bounds, both functions print the error message `"Position
     out of bounds."` and return immediately.

> 4. In `LinkedList::concat`, why did you need to walk to the end of the list first, when `addFront` and
     `deleteFront` never needed to? What would change about concat’s performance if `LinkedList` still
     tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?
> >  `addFront` and `deleteFront` operate directly on `head_` with no tail pointer implemented. These two
     functions are $O(1)$ time. The only way to find the last node to attach `other->head_` is to walk from
     `head_` using a `while (current->next !- nullptr)` loop. This makes `concat` an $O(n)$ operation.
     If we tracked a `tail_` pointer, `concat` would run in $O(1)$ time, however adding it would require
     maintaining it in `addFront`, `deleteFront`, `addAnywhere`, `deleteAnywhere`, and `reverse`.

> 5. Pick either `addAnywhere` or `deleteAnywhere` in `ArrayList` and explain, in your own words, what has
     to shift and in which direction, and why shifting in the wrong direction would overwrite data you
     still need.
> >  For `deleteAnywhere` in `ArrayList`, all elements to the right of the deleted index must shift one
     slot to the left to fill the vacated space. This shift puts `position = position + 1` until `size_
     - 1` leaving the extra value outside the array in its slot. We have to shift from left to right by
     copying `data_[i + 1]` into `data_[i]`. If we shifted in the wrong direction, we would overwrite
     the data after the first iteration making every value the same.

> 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play,
     and explain what would visibly break in the game if that call were missing.
> >  In `main.cpp`, line 73 `players->reverse();` is the exact line where the Reverse card changes the
     direction of play. It flips the order of the `LinkedList` from `Luca -> Angel -> Adele -> Kai -> Julie` to `Julie
     -> Kai -> Adele -> Angel -> Luca`. If `reverse` was missing, the game would continue in the same order,
     making the turn order the appears not match up with the turn order of the game logic. Angel would not
     be positioned in the stack properly for it to be his turn.