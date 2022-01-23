int findDuplicate(int array[]) {
    int slow, fast;
    slow = array[0];
    fast = array[0];
    while (true) {
        slow = array[slow];
        fast = array[array[fast]];
        if (slow == fast) {
            break;
        }
    }
    
    // once slow and fast meet, return one of them to the head of the array and name it as pointer 1
    int ptr1 = array[0], ptr2 = fast;
    while (ptr1 != ptr2) {
        ptr1 = array[ptr1];
        ptr2 = array[ptr2];
    }
    return ptr1;
}
