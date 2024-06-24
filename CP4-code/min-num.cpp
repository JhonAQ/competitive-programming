#include <iostream>
#include <algorithm>
#include <iterator>

int main() {
    using namespace std;
    cout << *min_element(istream_iterator<int>(cin), istream_iterator<int>()) << endl;
    return 0;
}
