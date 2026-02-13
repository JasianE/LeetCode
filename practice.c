bool hasAlternatingBits(int n) {
    int prev = n & 1; // first bit
    n >>= 1;          // shift to next bit

    while (n > 0) {
        int curr = n & 1;
        if (curr == prev) // two consecutive bits are the same
            return false;
        prev = curr;
        n >>= 1;
    }
    return true;
}