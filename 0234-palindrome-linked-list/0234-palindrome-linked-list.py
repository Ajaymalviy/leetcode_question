class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # If the list is empty or has only one node, it's a palindrome
        if not head or not head.next:
            return True
        
        # Find the middle of the list using the slow and fast pointers technique
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # Reverse the second half of the list
        prev = None
        while slow:
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        
        # Compare the first half of the list with the reversed second half
        while prev:
            if head.val != prev.val:
                return False
            head = head.next
            prev = prev.next
   
     
        return True
