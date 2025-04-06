/* nまでの素数を集める。*/
using namespace std;
using ll = long long;

vector<ll> primes(int N)
{

    vector<ll> prime(1, 2);
    vector<ll> is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (ll i = 2; i * 2 <= N; i++)
        is_prime[i * 2] = false;

    for (ll i = 3; i <= N; i += 2)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            for (ll j = 3; i * j <= N; j += 2)
                is_prime[i * j] = false;
        }
    }

    return prime;
}