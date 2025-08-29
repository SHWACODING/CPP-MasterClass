#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dpp(arr, val) memset(arr, val, sizeof(arr))
#define ll long long
#define ull long long
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair


using namespace std;

//----------------------------------------------------------------------

//ll arithmetic_sum (ll a1, ll an, ll n)
//{
//    return ((a1 + an) * n) / 2;
//}

//----------------------------------------------------------------------

//ld geometric_sum (ll a, ll r, ll n)
//{
//    return (a * pow(r, n - 1));
//}
//
//ld geometric_term(ll a, ll r, ll n)
//{
//    return (a * (1 - pow(r, n))) / (1 - r);
//}

//----------------------------------------------------------------------

//int arr[(int)1e6];
//int sum[1000000];
//vector<int> sum;

//----------------------------------------------------------------------

//const int sz = 1e6 + 10;
//int arr[sz];
//int sum[sz];

//----------------------------------------------------------------------

//const int sz = 1e6 + 10;
//int arr[sz];

//----------------------------------------------------------------------

//ll Addition (ll a, ll b, ll c)
//{
//    return ((a%c) + (b%c)) % c;
//}
//
//ll Subtraction (ll a, ll b, ll c)
//{
//    return ((a%c) - (a%c) + c) % c;
//}
//
//ll Multiplication (ll a, ll b, ll c)
//{
//    return ((a%c) * (b%c)) % c;
//}
//
//ll Division (ll a, ll b, ll c)
//{
//    return ((a%b) * ((1/b)%c)) % c;
//}

//----------------------------------------------------------------------

//ll IterativePower (ll x, ll n)
//{
//    ll result = 1;
//
//    while (n > 0)
//    {
//        result = result * x;
//        n--;
//    }
//    return result;
//}

//----------------------------------------------------------------------

//ll BinaryExponential (ll x, ll n)
//{
//    ll result = 1;
//
//    while (n > 0)
//    {
//        result *= x;
//        x *= x;
//        n /= 2;
//    }
//    return result;
//}

//----------------------------------------------------------------------
//
//ll ModularExponential (ll x, ll n, ll M)
//{
//    ll result = 1;
//
//    while (n > 0)
//    {
//        if (n % 2 == 1) (result = (result * x) % M);
//        x = Multiplication(x, x, M);
//        n /= 2;
//    }
//    return result;
//}

//----------------------------------------------------------------------

//ll FastPower (ll b, ll p)
//{
//    ll ans = 1;
//
//    while (p)
//    {
//        if (p % 2)
//            ans *= b;
//        b *= b;
//        p /= 2;
//    }
//    return ans;
//}

//----------------------------------------------------------------------

// Greatest Common Divisor GCD() ??

//ll gcd (ll a, ll b)
//{
//    // gcd(a, b) = gcd(a, a%b)
//    // Stopping Condition If (b == 0){return a;}
//
//    while (b)
//    {
//        ll a2 = a;
//        a = b;
//        b = a2 % b;
//    }
//    return a;
//}

//----------------------------------------------------------------------

// Greatest Common Divisor Of Two Factorials GCD(A!, B!) ((Time Limit)) ??

//ll gcdFact(ll a, ll b)
//{
//    ll fact_a = 1, fact_b = 1;
//
//    for (ll i = 1; i <= a; ++i)
//        fact_a *= i;
//
//    for (ll i = 1; i <= b; ++i)
//        fact_b *= i;
//
//    while(fact_b)
//    {
//    ll fact_a2 = fact_a;
//    fact_a = fact_b;
//    fact_b = fact_a2 % fact_b;
//    }
//
//    return fact_a;
//}

//----------------------------------------------------------------------

// Least Common Multiple LCM() ???

//ll lcm(ll a, ll b)
//{
////    return (a * b) / gcd(a, b); // More Time Consuming ??
//
//    return ( a / gcd(a, b) ) * b; // Less Time Consuming ?? ✅
//}

//----------------------------------------------------------------------

// Extended Euclidean Algorithm Recursively ??

//int ExtendedEuclidean_Recursive(int a, int b, int& x, int& y)
//{
//    if (b == 0)
//    {
//        // Base Statement of Extended Euclidean Algorithm
//        // Is : a*y1 + b * (x1 - floor(a / b) * y1) = gcd(a, b)
//        // But ::
//        x = 1;
//        y = 0;
//        return a;
//    }
//    int x1, y1;
//
//    int d = ExtendedEuclidean_Recursive(b, a % b, x1, y1);
//
//    x = y1;
//    y = x1 - y1 * (a / b);
//
//    return d;
//}

//----------------------------------------------------------------------

// Multiplication Mod. ??

//ll Mod(ll a, ll b, ll m)
//{
//    return ((a % m) * (b % m)) % m;
//}

//----------------------------------------------------------------------

// Addition Mod. ??

//ll Add(ll a, ll b, ll m)
//{
//    return ((a % m) + (b % m)) % m;
//}

//----------------------------------------------------------------------

// Extended Euclidean Algorithm Iteratively ??

//int ExtendedEuclidean_Iterative(int a, int b, int& x_prev, int& y_prev)
//{
//    x_prev = 1, y_prev = 0;
//
//    int x = 0, y = 1;
//
//    while(b)
//    {
//        int q = a / b;
//        tie(x, x_prev) = make_tuple(x_prev - q * x, x);
//        tie(y, y_prev) = make_tuple(y_prev - q * y, y);
//        tie(a, b) = make_tuple(b, a % b);
//    }
//    return a;
//}

//----------------------------------------------------------------------

//// Sieve Of Eratosthenes Theory ???
//
//const ll sz = 1e6 + 10;
//
//bool composite[sz];
//
//void Sieve_Of_Eratosthenes()
//{
//    composite[0] = composite[1] = 1;
//
//    for (ll i = 2; i * i <= sz; ++i)
//    {
//        if (!composite[i]) // The composite[rest...(until 0, 1)] == null
//            for(int j = i * i; j <= sz; j += i)
//                composite[j] = 1;
//    }
//}

//----------------------------------------------------------------------

//// Linear Sieve Of Eratosthenes ???
//
//vector<ll> prime;
//
//const ll sz = 1e6 + 10;
//
//bool composite[sz];
//
//void Linear_Sieve_Of_Eratosthenes(ll n)
//{
//    composite[0] = composite[1] = 1;
//
//    for (ll i = 2; i < n; ++i)
//    {
//        if (!composite[i])
//            prime.push_back(i);
//
//        for(ll j = 0; j < prime.size() && i * prime[j] < n; ++j)
//        {
//            composite[i * prime[j]] = true;
//
//            if (i % prime[j] == 0)
//                break;
//        }
//    }
//}


//----------------------------------------------------------------------

//// Segmented Sieve Of Eratosthenes Theory ???

//const int sz = 1e6 + 10;
//
//bool composite[sz + 1];
//
//void Segmented_Sieve_Of_Eratosthenes_NoPreGen (ll L, ll R)
//{
//    ll lim = sqrt(R);
//
//    for (ll i = 2; i <= lim; ++i)
//    {
//        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
//            composite[j - L] = true;
//    }
//
//    if(L == 1)
//        composite[0] = true;
//}

// -------------------Other Method Optimized-----------------------------

//vector<bool> Segmented_Sieve_Of_Eratosthenes (ll L, ll R)
//{
//    ll lim = sqrt(R);
//
//    vector<bool> mark(lim + 1, false);
//
//    vector<ll> primes;
//
//    for(ll i = 2; i <= lim; ++i)
//    {
//        if(!mark[i])
//        {
//            primes.emplace_back(i);
//            for(ll j = i * i; j <= lim; j += i)
//                mark[j] = true;
//        }
//    }
//
//    vector<bool>iscomposite(R - L + 1, false);
//
//    for(ll i : primes)
//    {
//        for(ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
//            iscomposite[j - L] = true;
//    }
//
//    if (L == 1)
//        iscomposite[0] = true;
//    return iscomposite;
//}

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

int main()
{
    IOS
//------------------------------------------------------------------------------------------------------
//    ll n;
//    cin >> n;
//    cout << ((1+n)*n)/2 << endl; // Arithmetic Progression ??
//
//    cout << arithmetic_sum(1, n, n);
//------------------------------------------------------------------------------------------------------

// https://codeforces.com/problemset/problem/598/A
// < === جامدة جداااا ===== >

//    int T;
//    cin >> T;
//
//    while (T--)
//    {
//        ll n;
//        cin >> n;
//
//        ll ans = arithmetic_sum(1, n, n);
//
//        vector<ll>power;
//        power.push_back(1);
//
//        for (int i = 1; i < 32; ++i)
//            power.push_back(power[i - 1] * 2);
//
//        ll sum = 0;
//
//        for (int i = 0; i < 32; ++i)
//            if (power[i] <= n)
//                sum += power[i];
//
//        ans -= 2 * sum;
//
//        cout << ans << endl;
//    }

//------------------------------------------------------------------------------------------------------

//    double a, r, n;
//    cin >> a >> r >> n;
//
//    cout << "Directly Calculated : " << (a * pow(r, n-1)) << "\t My Own Function : " << geometric_sum(a, r, n) << endl;
//
//    cout << "Directly Calculated : " << (a * (1 - pow(r, n))) / (1 - r) << "\t My Own Function : " << geometric_term(a, r, n) << endl;

//------------------------------------------------------------------------------------------------------

// https://codeforces.com/contest/328/problem/A
// < === جامدة جداااا ===== >

//    int a1, a2, a3, a4;
//    cin >> a1 >> a2 >> a3 >> a4;
//
//    ll d = a2 - a1;
//
//    double r = double(a2) / double(a1);
//
//    if (a3 - a2 == d && a4 - a3 == d)
//        cout << a4 + d << endl;
//
//    else if (double(a3)/double(a2) == r && double(a4)/double(a3) == r && (ll)(a4*r) == a4*r)
//        cout << a4 * r << endl;
//
//    else
//        cout << 42 << endl;

// ===================== Another Solution ============================

//    int a1, a2, a3, a4;
//    cin >> a1 >> a2 >> a3 >> a4;
//
//    ll d = a2 - a1;
//
//    if (a3 - a2 == d && a4 - a3 == d)
//        cout << a4 + d << endl;
//
//    else if (a1*a3 == a2*a2 && a2*a4 == a3*a3 && (a4*a4)%a3 == 0)
//        cout << a4 * a4 / a3 << endl;
//
//    else
//        cout << 42 << endl;

//------------------------------------------------------------------------------------------------------

// https://codeforces.com/contest/328/problem/B
// < === جامدة جداااا ===== >

////////////////// Not Completed ??????????????????????
//    int fav, seq;
//    cin >> fav >> seq;
//
//    int last, cnt = 0;
//    for (int i = 0; i < 8; ++i)
//    {
//        last = seq % 10;
//
//        if (last == 5 || last == 2 || last == 9 || last == 6)
//            cnt++;
//
//    cout << cnt << endl;

// ===================== Another Solution ============================

//    string n, p;
//    int a[10]={0} ,b[10]={0} ,k ,m=10000000;
//
//    cin >> n;
//    cin >> p;
//
//    for(int i = 0; i< n.size(); i++)
//    {
//        k = int(n[i]-'0');
//        if (k == 9)
//            b[6]++;
//        else if (k == 5)
//            b[2]++;
//        else
//            b[k]++;
//    }
//
//    for(int i = 0; i< p.size(); i++)
//    {
//        k = int(p[i] - '0');
//        if(k == 9)
//            a[6]++;
//        else if (k == 5)
//            a[2]++;
//        else
//            a[k]++;
//    }
//
//    for(int i = 0; i < 10; i++)
//    {
//        if(i!= 5 && i != 9 && b[i] != 0)
//        {
//            k = a[i] / b[i];
//            if(k < m)
//                m = k;
//        }
//    }
//
//    cout << m << endl;

//------------------------------------------------------------------------------------------------------
// Cumulative Sum ???

//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//
//    for (int i = 0; i < n; ++i)
//    {
//        sum[i] += arr[i];
//        if (i)
//            sum[i] += sum[i - 1];
//    }
//
//    int T;
//    cin >> T;
//
//    while (T--)
//    {
//        int l, r;
//        cin >> l >> r;
//        l--; r--;
//
//        if (l != 0)
//            cout << sum[r] - sum[l - 1] << endl;
//        else
//            cout << sum[r] << endl;
//    }

// ===================== Another Solution ============================

//    sum.resize(1000000);
//
//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//
//    for (int i = 0; i < n; ++i)
//    {
//        sum[i] += arr[i];
//        if (i)
//            sum[i] += sum[i - 1];
//    }
//
//    int T;
//    cin >> T;
//
//    while (T--)
//    {
//        int l, r;
//        cin >> l >> r;
//        l--; r--;
//
//        if (l != 0)
//            cout << sum[r] - sum[l - 1] << endl;
//        else
//            cout << sum[r] << endl;
//    }

//------------------------------------------------------------------------------------------------------

// https://codeforces.com/problemset/problem/363/B
// < === جامدة جداااا ===== >

//    int n, k;
//    cin >> n >> k;
//
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> arr[i];
//        sum[i] += arr[i];
//        if (i)
//            sum[i] += sum[i - 1];
//    }
//
//    int mn = 1e9;
//    int idx = 0;
//
//    for (int i = k - 1; i < n; ++i)
//    {
//        int r = i;
//        int l = r - (k - 1);
//
//        int ans = sum[r];
//
//        if (l)
//            ans -= sum[l - 1];
//
//        if (ans < mn)
//        {
//            mn = ans;
//            idx = l;
//        }
//    }
//
//    cout << idx + 1 << endl;

//------------------------------------------------------------------------------------------------------

// Ranged Sum ???

//    int n, T;
//    cin >> n >> T;
//
//    while (T--)
//    {
//        int l, r;
//        cin >> l >> r;
//        arr[l] += 1;
//        arr[r + 1] -= 1;
//    }
//
//    for (int i = 1; i <= n; ++i)
//        arr[i] += arr[i - 1];
//
//    for (int i = 1; i <= n; ++i)
//        cout << arr[i] << " ";


//------------------------------------------------------------------------------------------------------

// https://codeforces.com/problemset/problem/816/B
// < === جامدة جداااااااااا ===== >

//    ll arr[2000000];
//
//    ll n, k, q;
//    cin >> n >> k >> q;
//
//    for (int i = 0; i < n; ++i)
//    {
//        int li, ri;
//        cin >> li >> ri;
//        arr[li]++;
//        arr[ri + 1]--;
//    }
//
//    for (int i = 1; i < 2000000; ++i)
//        arr[i] += arr[i - 1];
//
//    for (int i = 0; i < 2000000; ++i)
//    {
//        if (arr[i] >= k)
//            arr[i] = 1;
//        else
//            arr[i] = 0;
//    }
//
//    for (int i = 1; i < 2000000; ++i)
//        arr[i] += arr[i - 1];
//
//    for (int i = 0; i < q; ++i)
//    {
//        int li, ri;
//        cin >> li >> ri;
//
//        cout << arr[ri] - arr[li - 1] << endl;
//    }

//------------------------------------------------------------------------------------------------------

// Modular Arithmetic ??

//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < n; ++i)
//        cout << i << " -------> " << i%m << endl;

//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//
//        cout << "Addition Function : " << Addition(a, b, c) << endl;
//        cout << "Subtraction Function : " << Subtraction(a, b, c) << endl;
//        cout << "Multiplication Function : " << Multiplication(a, b, c) << endl;
//        cout << "Division Function : " << Division(a, b, c) << endl;
//    }

//------------------------------------------------------------------------------------------------------

// Modular Exponential ??
//
//    int T;
//    cin >> T;
//
//    while (T--)
//    {
//        int x, n, M;
//        cin >> x >> n >> M;
//
//        cout << "IterativePower Is : " << IterativePower(x, n) << endl;
//        cout << "BinaryExponential Is : " << BinaryExponential(x, n) << endl;
//        cout << "ModularExponential Is : " << ModularExponential(x, n, M) << endl;
//    }


//------------------------------------------------------------------------------------------------------

// https://codeforces.com/problemset/problem/913/A
// < === جامدة جداااااااااا ===== >

//    cin.tie(NULL);
//    ll n, m;
//    cin >> n >> m;
//
//    if (n <= 40)
//        cout << m % FastPower(2, n) << endl;
//    else
//        cout << m << endl;


//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

// Factorization ??

//    int n;
//    cin >> n;
//
//    for (int i = 2; i*i <= n; ++i)
//        if (n % i == 0)
//        {
//            cout << i << " ";
//            if (i * i != n)
//            cout << n / i << " " << endl;
//        }

//------------------------------------------------------------------------------------------------------

// https://codeforces.com/problemset/problem/893/B
// < === جامدة جداااااااااا ===== >

//    int n;
//    cin >> n;
//
//    vector<ll>powers;
//    for (int i = 0; i <= 32; ++i)
//        powers.push_back((ll)pow(2, i));
//
//    vector<ll>divisors;
//    for (int i = 1; i*i <= n; ++i)
//    {
//        if (n % i == 0)
//        {
//            divisors.push_back(i);
//            if (i * i != n)
//                divisors.push_back(n/i);
//        }
//    }
//
//    sort(divisors.rbegin(), divisors.rend());
//
//    for (ll i = 0; i < divisors.size(); ++i)
//    {
//        for (ll j = 1; j < powers.size(); ++j)
//            if (((powers[j] - 1) * (powers[j-1])) == divisors[i])
//            {
//                cout << divisors[i];
//                return 0;
//            }
//    }

//------------------------------------------------------------------------------------------------------

// Prime Factorization ??

//    int n;
//    cin >> n;
//
//    vector<int> PrimeFactors;
//
//    for (int i = 2; i*i <= n; ++i)
//    {
//        while (n %  i == 0)
//        {
//            n /= i;
//            PrimeFactors.push_back(i);
//        }
//    }
//
//    if (n != 1)
//        PrimeFactors.push_back(n);
//
//    for (int i = 0; i < PrimeFactors.size(); ++i)
//        cout << PrimeFactors[i] << " ";
//    cout << endl;

//------------------------------------------------------------------------------------------------------

//    int n, k;
//    cin >> n >> k;
//
//    vector<ll> PrimeFactors;
//
//    for (int i = 2; i <= n; ++i)
//    {
//        while (n %  i == 0)
//        {
//            PrimeFactors.push_back(i);
//            n /= i;
//        }
//    }
//
//    if (PrimeFactors.size() < k)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    for (int i = 0; i < k-1; ++i)
//        cout << PrimeFactors[i] << " ";
//
//    ll ans = 1;
//
//    for (ll i = k-1; i < PrimeFactors.size(); ++i)
//        ans *= PrimeFactors[i];
//
//    cout << ans;


//------------------------------------------------------------------------------------------------------

// Greatest Common Divisor GCD() ??

//    ll a, b;
//    cin >> a >> b;
//
//    cout << "Greatest Common Divisor OF : " << a << ", " << b << " Is : " << gcd(a, b) << endl;

//------------------------------------------------------------------------------------------------------

// Greatest Common Divisor Of Factorial A, B GCD(A!, B!) (( Time Limit )) ??
// https://codeforces.com/problemset/problem/822/A

//    ll a, b;
//    cin >> a >> b;
//
//    cout << "Greatest Common Divisor OF Factorial Of A!, B! IS : " << gcdFact(a, b) << endl;

// ===================== Another Solution ============================

// The Best ??

//    ll a, b;
//
//    cin >> a >> b;
//
//    ll ans = 1;
//
//    for (int i = 1; i <= min(a, b); ++i)
//        ans *= i;
//
//    cout << ans << endl;

//------------------------------------------------------------------------------------------------------

// Least Common Multiplier LCM() ??

//    ll a, b;
//    cin >> a >> b;
//
//    cout << "Least Common Multiple OF : " << a << ", " << b << " Is : " << lcm(a, b) << endl;

//------------------------------------------------------------------------------------------------------

// Find The LCM TO Numbers From 1 To N lcm(1, 2, ..., N) ???

//    int T;
//    cin >> T;
//
//    while(T--)
//    {
//        int n;
//        cin >> n;
//
//        ll LCM = 1;
//
//        for (int i = 1; i <= n; ++i)
//            LCM = lcm(i, LCM);
//
//        cout << "Least Common Multiple To Numbers From 1 TO " << n << " Is : " << LCM << endl;
//    }

//------------------------------------------------------------------------------------------------------

// Extended Euclidean Algorithm Recursively ??

//    int a, b;
//    cin >> a >> b;
//
//    int x, y;
//
//    cout << "Euclidean Distance Recursive ==> " << ExtendedEuclidean_Recursive(a, b, x, y) << endl;
//    cout << "X ==> " << x << endl;
//    cout << "Y ==> " << y << endl;


//------------------------------------------------------------------------------------------------------

// Extended Euclidean Algorithm Iteratively ??

//    int a, b;
//    cin >> a >> b;
//
//    int x, y;
//
//    cout << "Euclidean Distance Iterative ==> " << ExtendedEuclidean_Iterative(a, b, x, y) << endl;
//    cout << "X ==> " << x << endl;
//    cout << "Y ==> " << y << endl;

//------------------------------------------------------------------------------------------------------

// Modular Multiplicative Inverse To Solve  (A^B / c) % M ??

//    ll A, B, C, M;
//    cin >> A >> B >> C >> M;
//
//    int x, y;
//
//    ll A_Power_B_Mod_M = ModularExponential(A, B, M);
//
//    ExtendedEuclidean_Iterative(C, M, x, y);
//
//    x = (x % M + M) % M;
//
//    ll C_inverse = x;
//
//    cout << ((A_Power_B_Mod_M) * (C_inverse % M)) % M;

//------------------------------------------------------------------------------------------------------

// Sieve Of Eratosthenes Theory ???

//    Sieve_Of_Eratosthenes();
//
//    for (int i = 0; i <= 120; ++i)
//        if (!composite[i])
//            cout << i << endl;

//------------------------------------------------------------------------------------------------------

// Linear Sieve Of Eratosthenes Theory ???

//    int n;
//    cin >> n;
//
//    Linear_Sieve_Of_Eratosthenes(n);
//
//    for (int i = 0; i <= n; ++i)
//        if (!composite[i])
//            cout << i << endl;

//------------------------------------------------------------------------------------------------------

// Segmented Sieve Of Eratosthenes Theory ???

//    ll l, r;
//    cin >> l >> r;
//
//    vector<bool> iscomposite = Segmented_Sieve_Of_Eratosthenes(l, r);
//
//    for(ll i = 1; i <= r; ++i)
//        if (!iscomposite[i - l])
//            cout << i << endl;


//------------------------------------------------------------------------------------------------------

//// Bit Manipulation ??

//    int A = 10;
//    int B = 9;
//
//    cout << "A : " << A << " ----> A In Binary : " << bitset<4>(A).to_string() << endl;
//    cout << "B : " << B << " ----> B In Binary : " << bitset<4>(B).to_string() << endl;
//
//    cout << "Not A => " << ~(A) << endl;
//    cout << "Not B => " << ~(B) << endl;
//    cout << "A and B => " << (A & B) << endl;
//    cout << "A or B => " << (A | B) << endl;
//    cout << "A Xor B => " << (A ^ B) << endl;
//    cout << "A Left Shift With 1 => " << (A << 1) << endl;
//    cout << "A Left Shift With 3 => " << (A << 3) << endl;
//    cout << "A Right Shift With 1 => " << (A >> 1) << endl;
//    cout << "A Right Shift With 3 => " << (A >> 3) << endl;

// ---------------------------------------------------------------

//// Even or Odd ?? ==> The Last Bit Determines Even or Odd
// 1  0001  ==> Last Bit = 1 => ODD
// 2  0010  ==> Last Bit = 0 => Even
// 3  0011  ==> Last Bit = 1 => ODD
// 4  0100  ==> Last Bit = 0 => Even
// 5  0101  ==> Last Bit = 1 => ODD
// 6  0110  ==> Last Bit = 0 => Even

//// Last Bit ==> Number & 1 ??

//    int n;
//    cin >> n;
//
//    int lastbit = n & 1;
//    if (lastbit == 1)
//        cout << n << " IS ODD ??" << endl;
//    else
//        cout << n << " IS Even ??" << endl;

// ---------------------------------------------------------------

//// Power of 2 ??

//    int n;
//    cin >> n;
//
//    if (n == 0 || (n & (n - 1)) == 0)
//        cout << n << " Is Power Of Two ??" << endl;
//    else
//        cout << n << " Is Not A Power Of Two ??" << endl;

// ---------------------------------------------------------------

//// Number of Ones (Set Bits) ??

//    int n;
//    cin >> n;
//
//    cout << "Number of Ones In " << n << " IS ";
//
//    int cnt = 0;
//
//    while (n) {
//        int lastbit = n & 1;
//
//        if (lastbit == 1) { cnt++; }
//
//        n = n >> 1;
//    }
//
//    cout << cnt << endl;

//------------------------------------------------------------------------------------------------------

//// Binary Search Implementation ??

//    int n, wanted;
//    cin >> n >> wanted;
//
//    vector<int> v;
//    for (int i = 0; i < n; ++i) {
//        int x;
//        cin >> x;
//        v.push_back(x);
//    }
//
//    int L = 0, R = n-1, ans = -1;
//
//    while (L <= R) {
//        int M = (L + R) / 2;
//
//        if (wanted == v[M]) {
//            ans = M;
//            break;
//        }
//        else if (wanted < v[M])
//            R = M - 1;
//        else if (wanted > v[M])
//            L = M + 1;
//    }
//
//    cout << ans << endl;

// ----------------------------------------------------------

//// https://codeforces.com/problemset/problem/706/B

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int q;
    cin >> q;

    while (q--) {
        int m;
        cin >> m;

        int L = 0, R = n-1;

        while (L <= R) {
            int M = L + (R - L) / 2;

            if (m == v[M])
                L = M + 1;
            else if (m < v[M])
                R = M - 1;
            else
                L = M + 1;
        }
        cout << L << endl;
    }

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------

    return 0;
}
