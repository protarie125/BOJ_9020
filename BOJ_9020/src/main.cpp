#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int maxN{ 10'000 };

    vb sieve(maxN + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i <= maxN; ++i)
    {
        if (sieve[i]) {
            int j{ i + i };
            while (j <= maxN) {
                sieve[j] = false;
                j += i;
            }
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;

        int a{ n / 2 };
        int b{ n / 2 };
        while (0 < a) {
            if (sieve[a] && sieve[b]) {
                cout << a << ' ' << b << '\n';
                break;
            }

            a -= 1;
            b += 1;
        }
    }

    return 0;
}