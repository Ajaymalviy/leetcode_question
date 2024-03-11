class Solution:
    def customSortString(self, order: str, s: str) -> str:
        # Count the occurrences of each character in s
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # Construct the sorted string based on the order specified
        sorted_s = ''
        for char in order:
            if char in char_count:
                sorted_s += char * char_count[char]
                # Remove the character from char_count after adding it to sorted_s
                del char_count[char]
        
        # Append remaining characters from s (not in order) to sorted_s
        for char, count in char_count.items():
            sorted_s += char * count
        
        return sorted_s