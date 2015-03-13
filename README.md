# funny-code
I store funny code in this repository.  

## Brief introduciton for each file  
*aba-value-min.cpp* : Using binary search to find the minimum abstract value in a sorted array. We know that the minimum abstract value always in the area when negative integers changed to non-negative integers. We can find the fist positive integer or find the last negative integer. Then we can try the left and the right elements of the current integer by 1 offset. So we can find the minimum abstract value in O(log(n)) time complexity.  
*determine-mem-end.cpp* : Write a programm to determine whether the memory of your machine is big end or little end. We know in big end memory, the low bits of a integer are stored in high address. In little end memory, the low bits of integers are put in low address. So if we have a union only with a char and a int in it. If we set the int value of this union to be 0. Then if we change the value of the char to be 1. Then we get the value of the int in this union, if its value is 1, then we
can detemine that this machine is little end machine. Other wise it means this machine is big end because the low address stored high bit of a integer, in another word the low bits of integers are stored in high address.  
*iota_sample.cpp* :  
