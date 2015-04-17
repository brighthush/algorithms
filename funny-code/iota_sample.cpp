
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

template <class ForwardIterator, class T>
void iota_n (ForwardIterator first, int n, T value)
{
    for(int i=0; i<n; ++i)
    {
        *first++ = value++;
    }
}

int main (int argc, char *argv[])
{
    vector<int> container(6);
    iota(container.begin(), container.end(), 1);
    random_shuffle(container.begin(), container.end());
    copy(container.begin(), container.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;

    vector<int> v;
    v.push_back(6);
    istream_iterator<int> is_start(cin);
    istream_iterator<int> is_end;
    //copy(is_start, is_end, v.begin());
    back_insert_iterator< vector<int> > back_i = back_inserter(v);
    copy(is_start, is_end, back_i);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;

    iota_n(back_inserter(v), 5, 1);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    random_shuffle(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    return 0;
}
