def length_of_longest_substring(s):
    # Create a dictionary to store the last seen index of each character
    char_index = {}
    start = 0  # Start index of the current substring
    max_length = 0  # Maximum length of substring without repeating characters

    for i, char in enumerate(s):
        # If the character is already in the substring, update the start index
        if char in char_index and char_index[char] >= start:
            start = char_index[char] + 1

        # Update the last seen index of the character
        char_index[char] = i

        # Update the maximum length if the current substring is longer
        max_length = max(max_length, i - start + 1)

    return max_length

# Example usage:
s = "abcabcbb"
result = length_of_longest_substring(s)
print(result)
