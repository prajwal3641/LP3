#include <iostream>
#include <vector>

using namespace std;

int steps = 0;

int fibonacci(int n) {
    steps++;
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciIteration(int n) {
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int stepCountIteration(int n) {
    int count = 0;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci numbers to calculate: ";
    cin >> n;

    int stepsIteration = stepCountIteration(n);
    
    cout << "Fibonacci Recursion: " << fibonacci(n) << endl;
    cout << "Fibonacci Recursion Steps: " << steps << endl;
    cout << "Fibonacci Iteration: " << fibonacciIteration(n) << endl;
    cout << "Fibonacci Iteration Steps: " << stepsIteration << endl;

    return 0;
}

/*
Explanation:

- The `fibonacci` function calculates the nth Fibonacci number recursively and increments a global `steps` variable to count recursion calls.
- The `fibonacciIteration` function calculates the nth Fibonacci number iteratively using a vector for storage, which is more efficient.
- The `stepCountIteration` function mimics the iterative process, but only counts the steps (loop iterations) needed for comparison.
- In `main`, we prompt the user for `n`, compute both Fibonacci results, and display the number of recursive and iterative steps.
*/
