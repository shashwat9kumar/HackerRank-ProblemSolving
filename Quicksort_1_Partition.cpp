/*


The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm with a running time of . In these next few challenges, we're covering a divide-and-conquer algorithm called Quicksort (also known as Partition Sort). This challenge is a modified version of the algorithm that only addresses partitioning. It is implemented as follows:

Step 1: Divide
Choose some pivot element, , and partition your unsorted array, , into three smaller arrays: , , and , where each element in , each element in , and each element in .

For example: Assume 
The pivot is at 
 is divided into , , and .
Putting them all together, you get . Another valid solution is .

Given  and , partition  into , , and  using the Divide instructions above. Then print each element in  followed by each element in , followed by each element in  on a single line. Your output should be space-separated and does not have to maintain ordering of the elements within the three categories.

Function Description

Complete the quickSort function in the editor below. It should return an array of integers as described above.

quickSort has the following parameter(s):

arr: an array of integers where  is the pivot element
Input Format

The first line contains , the size of the array .
The second line contains  space-separated integers describing  (the unsorted array). The first integer (corresponding to ) is your pivot element, .

Constraints

 where 
All elements will be unique.
Output Format

On a single line, print the partitioned numbers (i.e.: the elements in , then the elements in , and then the elements in ). Each integer should be separated by a single space.

Sample Input

5
4 5 3 7 2
Sample Output

3 2 4 5 7
Explanation

 Pivot: .
; ; 

, so it's added to .
; ; 

, so it's added to .
; ; 

, so it's added to .
; ; 

, so it's added to .
; ; 

We then print the elements of , followed by , followed by , we get: 3 2 4 5 7.

You don't need to maintain ordering, so another valid solution would be 2 3 4 5 7.



*/


