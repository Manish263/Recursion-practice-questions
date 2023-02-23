int myAtoi(string s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Step 1: Ignore leading whitespace
    while (s[i] == ' ') {
        i++;
    }

    // Step 2: Determine sign of integer
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i++] == '-') ? -1 : 1;
    }

    // Step 3: Read in digits
    while (isdigit(s[i])) {
        // Step 4: Convert digits to integer
        int digit = s[i++] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            // integer overflow
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
    }

    // Step 5: Clamp to 32-bit signed integer range
    result *= sign;
    if (result < INT_MIN) {
        result = INT_MIN;
    } else if (result > INT_MAX) {
      result = INT_MAX;
    }
    // Step 6: Return final result
    return result;
}
