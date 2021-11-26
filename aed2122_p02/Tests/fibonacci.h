//Time Complexity: O(2^N)
unsigned fibonacci_1(unsigned n) {
    if (n <= 1)
        return n;
    return fibonacci_1(n-1) + fibonacci_1(n-2);
}

//Time Complexity: O(N);
//Space Complexity: O(1)
unsigned fibonacci_2(unsigned n) {
    unsigned valPrevPrev = 0, valPrev = 1;
    if (n == 0)
        return valPrevPrev;
    if (n == 1)
        return valPrev;
    unsigned val;
    for (unsigned i = 2; i <= n; i++)
    {
        val = valPrevPrev + valPrev;
        valPrevPrev = valPrev;
        valPrev = val;
    }
    return val;
}

