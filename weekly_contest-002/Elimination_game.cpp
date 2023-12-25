// Q2 You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

// Starting from left to right, remove the first number and every other number afterward until you reach the end of the list. Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers. Keep repeating the steps again, alternating left to right and right to left, until a single number remains. Given the integer n, return the last number that remains in arr.

// Method-1 using recursion

/* class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) {
            return 1;
        }
        return 2*(n/2 +1 - lastRemaining(n/2));
    }
}; */

// Method-2 using double pointer approach

/* class Solution {
public:
    bool changeBothPtr(int& left, int& right, int& step) {
        return !((right - left) % step);
    }

    int lastRemaining(int n) {
        int left = 1, right = n, step = 2, pos = 0;

        while (left < right) {
            if (changeBothPtr(left, right, step)) {
                left+= (step / 2);
                right-= (step / 2);
            }
            else {
                if (pos) right-= (step / 2);
                else left+= (step / 2);
            }
            pos = 1 - pos;
            step*= 2;
        }
        return left;
    }
}; */

// Method-3 binary search
/* class Solution {
public:
    int lastRemaining(int n) {
        bool left=true;
       int head=1,step=1;
       while(n>1){
           if(left || n&1){//left to right or odd numbers then head shift
                head+=step;
           }
           step*=2;//every time strp has 2
           n/=2;//every time n is halfed
           left=!left; // means convert left to right and vice-versa
       }

       return head;
    }
}; */

// Method-4 using bit manipulation in recursion

/* class Solution {
public:
    int lastRemaining(int n) {        
        return n == 1 ? n 
                    : ((n >> 1ul) - lastRemaining(n >> 1ul) + 1) << 1ul;
    }
}; */