# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            #if not having more than one node than directly return this 
            return head

        odd, even = head, head.next #create two variables one is odd and anothe is even which is next of odd
        even_head = even # all the evens are be even_head

        while even and even.next: # we have atlest 3 nodes then move into this loop
            odd.next = even.next
            odd = odd.next   # remove the middel of two odds and add 3rd node with first 
            even.next = odd.next
            even = even.next
#and at last the last odd is points to even_head is contain all evens
        odd.next = even_head
#then return head at last which mean current node
        return head
   
    