1.Design a stack using a single queue as an instance variable,and only constant additional local memory within the method bodies.

2.Suppose you have a stack S containing n elements and a queue Q that is initially empty. Write function that use Q to scan S to see if it contains a certain element x, with the additional constraint that your algorithm must return the elements back to S in their original order. You may use S, Q and a constant number of other variables.

3.Design a queue using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.

4.Implement a function with signature transfer(S,T) that transfers all elements from Stack S onto Stack T, so that that elements that starts at the top of S is the first to be inserted into T, and element at the bottom of S ends up at the top of T. 

5.Implement a function that reverses a list of elements by pushing them onto a stack in one order, and write them back to the list in reversed order.

6.Modify ArrayStack implementation so that the stack’s capacity is limited to maxlen elements. If push is called when the stack is at full capacity, throw a Full exception.

7.Implement a transfer function and two temporary stacks, to replace the contents of a given stack S with those same elements, but in reverse order.

8. Suppose you have three nonempty stacks R, S and T. Describe a sequence of operations that results in S storing all elements originally in T below of S’s original elements, with both sets of those elements in their original configuration. For example, if R= [1,2,3], S = [4, 5] and T = [6, 7, 8, 9], the final configuration should have R = [1, 2, 3] and S = [6, 7, 8,  9, 4, 5].

9. In certain applications of the queue, it is common to repeatedly dequeue an element, process it in some way, and then immediately enqueuer the same element. Modify ArrayQueue implementation to include a rotate( ) method that has semantics identical to the combination,Q.enqueue (Q.dequeue()). However, your implementation should be more efficient than making two separate calls.

10. Implement LeakyStack. This stack should be of fixed size. When push is invoked with the stack at full capacity, rather than throwing a Full exception, accept the pushed element at the top while “leaking” the oldest element from the bottom of the stack to make a room.
