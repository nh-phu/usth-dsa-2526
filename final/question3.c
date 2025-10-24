/*
 - Start from the root = 10, insert 10 into a stack. Now the stack not empty with 
the node 10 in stack but it is also the only and the top element, pop the the 
node 10, dispaly value 10, push left children 6 and right. Pop and display the top, 31
Push 31 left and right node. Pop and display 17, push 17 left and right node. Pop
and display 22, pop and display 14. Pop and display 110. Pop and display 6 then 1.

10 31 110 17 22 14 6  1

 - From largest to the smallest values:
 Start from the root node:
 1. Go to its right node
 2. Display itself if it has no right node.
 3. Go to its left node
 The process:
 Start from 10, go to its right node, node 31 has  right node, go to its right node.
 Node 110 has none, display it self. 31 dont have right node anymore, display itself
 and go to the left. Continue and we have 110 31 22 17 14 10 6 1.
*/
