Bit manipulation 
# Question1 Multiply a number by 10 without using multiplcation operator
# Q2 How to swap adjacent bit pair
    // Iterate through each pair of adjacent bits
    for (i = 0; i < bitCount; i += 2) {
        // Get the values of the two adjacent bits
        int bit1 = (num >> i) & 1;
        int bit2 = (num >> (i + 1)) & 1;
        
        // Set the swapped bits in the result
        result |= (bit2 << i);
        result |= (bit1 << (i + 1));
    }
    
    return result;


//Better approach 
    // Get all even bits of x 
    unsigned int even_bits = N & 0xAAAAAAAA; 
 
    // Get all odd bits of x 
    unsigned int odd_bits = N & 0x55555555; 
     
      // Right shift even bits 
    even_bits >>= 1;
   
      // Left shift odd bits 
    odd_bits <<= 1; 
 
      // Combine even and odd bits 
    return (even_bits | odd_bits); 
