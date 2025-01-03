<h1>Sorting Algorithm Project 🚀</h1>
In this exercise, we were tasked with sorting a certain number of values while staying under a total number of operations to arrange them. The challenge comes from the specific operations allowed on the list of numbers.

<h2>Requirements</h2>
<h3>✨ Validation Criteria ✨</h3>
Minimal Validation<br> For a minimal grade (at least 80), the algorithm must be able to sort 100 random numbers in fewer than 700 operations.<br>
Maximal Validation<br> To achieve the maximum grade and bonuses, the algorithm must fulfill the minimal validation, but for 500 random numbers, the sorting must be completed in no more than 5500 operations.
<h3>🛠️ Allowed Operations 🛠️</h3>
The project limits the operations we could perform on the numbers in the stack. Here’s a description of the allowed operations:

- sa (swap a): Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
- ss: Perform sa and sb at the same time.
- pa (push a): Take the first element from stack b and put it at the top of stack a. Do nothing if stack b is empty.
- pb (push b): Take the first element from stack a and put it at the top of stack b. Do nothing if stack a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr: Perform ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr: Perform rra and rrb at the same time.

<h2> ❔ What Algorithm to use ❔</h2>
When exploring sorting algorithms, you'll find there are plenty of options, each with its own strengths and weaknesses. Personally, I chose the Butterfly Sort, named for the shapes it produces in a visualizer.

The concept is straightforward (it's part of the "divide and conquer" family). Each number is assigned an index that represents its final position in the sorted list. Then, the stack is divided into 4 parts (or more, depending on the total number of numbers to sort). Each part corresponds to a range of indices. For example, if we have 200 numbers to sort and divide them into 4 parts:

- Part 1: Indices 0–50<br>
- Part 2: Indices 51–100<br>
- Part 3: Indices 101–150<br>
- Part 4: Indices 151–200<br>

Each part is further divided into two subgroups based on the median of its indices. When pushing numbers into the second stack, a number's index determines the operation:

- If the index is greater than the median, use pb (push to stack B).
- If the index is less than or equal to the median, use pb followed by rb (rotate stack B).

Example:<br>
Let’s consider Part 4 with indices 151–200, where the median is 175:

- For index 156: Since 156 < 175, the operation would be pb, rb.
- For index 184: Since 184 > 175, the operation would be just pb.

By applying this systematic division and sorting process, the algorithm organizes numbers efficiently while maintaining the visual "butterfly" pattern.
Now, all that's left is to move the numbers back into stack A in order, from the highest index to the lowest.
