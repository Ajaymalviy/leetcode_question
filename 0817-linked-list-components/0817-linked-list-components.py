# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        new_set=set(nums) # first we create set for remove duplicates
        count=0
        while head is not None: 
            if head.val in new_set: # if val of current node is be in set then increment count with one
                count +=1
                while head and head.val in new_set:
                    #and also increament head to the next of head
                    head=head.next
            else:
                head=head.next # if value is not found in newset then directly go to the next node 
        return count    # and at last return count