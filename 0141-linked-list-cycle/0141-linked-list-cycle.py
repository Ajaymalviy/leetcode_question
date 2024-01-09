# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        self.slow=head #create a variable name slow point at head
        self.fast=head #same with name fast
        while self.fast is not None and self.fast.next is not None:
            #now check the condition again that if nodes are never get null then it must be in cycle
            self.fast = self.fast.next.next
            #where fast variable increment by two nodes and slow with one 
            self.slow=self.slow.next
            # there is a method floyed cycle finding alogrithm ,where if both are in same place then we can say that this are in loop
            if self.fast==self.slow:
                return True
            # and return true 
        return False  
    # else retrun False
        