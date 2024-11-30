int complexFunction(int input) {
    int result;
    int i;
    int j;
    int k;

    result = 0; // Initialize result
    i = 0;

    // Outer loop
    while (i < 10) {
        j = 0;

        // Nested loop
        while (j < 5) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    if (input > 50) {
                        result = result + i * j;
                        k = 0;
                        // Deeply nested while loop
                        while (k < 3) {
                            if (k % 2 == 0) {
                                result = result + k;
                            } else {
                                result = result - k;
                            }
                            k = k + 1;
                        }
                    } else {
                        result = result - i + j;
                    }
                } else {
                    if (input < 30) {
                        k = 0;
                        // Another nested while loop
                        while (k < 4) {
                            if (input % k == 0) {
                                result = result + k * 2;
                            } else {
                                result = result - k;
                            }
                            k = k + 1;
                        }
                    } else {
                        if (i < 5) {
                            result = result - input / 2;
                        } else {
                            result = result + input / 3;
                        }
                    }
                }
            } else {
                if (j == 3) {
                    if (input == 42) {
                        result = result * 3;
                    } else {
                        result = result - 1;
                    }
                } else {
                    if (input < 20) {
                        k = 0;
                        // Nested while loop for odd `i`
                        while (k < 2) {
                            result = result + k * j;
                            k = k + 1;
                        }
                    } else {
                        result = result / 2;
                    }
                }
            }

            // Additional nested checks
            if (result > 100) {
                if (i > 5) {
                    result = result - 50;
                } else {
                    result = result + 10;
                }
            } else if (result < 0) {
                if (j > 2) {
                    result = result + 25;
                } else {
                    result = result - 5;
                }
            }

            j = j + 1; // Increment inner loop counter
        }

        // Outer loop nested conditionals
        if (i % 3 == 0) {
            if (input < 25) {
                result = result * 2;
            } else {
                result = result - 5;
            }
        }

        if (i % 4 == 0) {
            if (result > 200) {
                result = result / 3;
            } else if (result < 50) {
                result = result + 15;
            } else {
                result = result - 10;
            }
        }

        i = i + 1; // Increment outer loop counter
    }

    // Final adjustment
    if (result > 100) {
        if (input > 40) {
            result = result - 100;
        } else {
            result = result + 50;
        }
    } else if (result < 0) {
        if (input < 10) {
            result = 0;
        } else {
            result = result + input;
        }
    }

    return result; // Single exit block
}
