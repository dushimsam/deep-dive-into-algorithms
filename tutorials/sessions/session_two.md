
AMORTIZED APPROACHES

1. left-pointer is used for adding more elements
2. right-pointer is used for removing the elements
3. until we reach to the target.fd
4. If the right-pointer reaches the end still less than or greater than target 
we end the process.

2SUM PROBLEM

NOTE: first sort the array.

1. right-pointer starts at the end of the array.
2. left-pointer starts at the begining of the array.
3. We mantain the sum of the right and the left value to 
be atmost -target.

NEAREST SMALLER ELEMENT

1. Make a stack
2. Iterate through the stack until the top element is less than the current one. 
3. Print the element and pop it from the stack.
4. Add the current element into the stack.

SLIDING WINDOW

1. Make a deque dsa
2. Check two condtions 
    i. The size of the window has not ended. 
       if so , pop the first element
    ii. The back element is greater than the current one.
        pop back 
3. Add element in the queue.
4. After it has made the k_window size , print the top element.


 ADDONS
 1. QUEUE DSA - FIFO (first in first out)
 2. STACK DSA - LIFO (last in last out)
 3. DEQUE DSA - DOUBLE ENDED QUEUE
 