from collections import deque

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        # Sort the deck in increasing order
        deck.sort()
        
        # Initialize a deque with indices
        indices = deque(range(len(deck)))
        
        # Initialize the result array
        result = [0] * len(deck)
        
        # Iterate through the sorted deck
        for card in deck:
            # Assign the current card to the index at the front of the deque
            result[indices.popleft()] = card
            
            # If there are still indices left, move the index at the front to the back
            if indices:
                indices.append(indices.popleft())
        
        return result
