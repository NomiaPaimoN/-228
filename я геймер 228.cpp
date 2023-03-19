#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimesRecursive(int x, int i) {
    if (i > x) {
        return 0;
    }
    if (isPrime(i)) {
        return 1 + countPrimesRecursive(x, i+1);
    }
    return countPrimesRecursive(x, i+1);
}

int countPrimes(int x) {
    int count = 0;
    for (int i = 2; i <= x; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int x;
    cout << "Введите число x: ";
    cin >> x;

    int count1 = countPrimes(x);
    int count2 = countPrimesRecursive(x, 2);

    cout << "Количество простых чисел не превосходящих " << x << " (нерекурсивный): " << count1 << endl;
    cout << "Количество простых чисел не превосходящих " << x << " (рекурсивный): " << count2 << endl;

    return 0;
}
