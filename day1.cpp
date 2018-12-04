#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>


int freqReachedTwice(std::vector<int> values)
{
    auto sum {0};
    std::set<int> sums {sum};
    while (true) {
        for (auto& val : values) {
            sum += val;
            if (sums.find(sum) != sums.end()) {
                return sum;
            }
            sums.insert(sum);
        }
    }
}


void test()
{
    std::vector a {1, -1};
    if (freqReachedTwice(a) != 0) {
        std::cout << "a: fail\n";
    }
    std::vector b {3, 3, 4, -2, -4};
    if (freqReachedTwice(b) != 10) {
        std::cout << "b: fail\n";
    }
    std::vector c {-6, 3, 8, 5, -6};
    if (freqReachedTwice(c) != 5) {
        std::cout << "c: fail\n";
    }
    std::vector d {7, 7, -2, -7, -4};
    if (freqReachedTwice(c) != 5) {
        std::cout << "d: fail\n";
    }
}


int main(int argc, char const* argv[])
{

    // test();
    std::ifstream inputFile{"day1.txt"};
    std::vector<int> numbers {std::istream_iterator<int>{inputFile}, {}};
    std::cout << freqReachedTwice(numbers) << "\n";
    return 0;
}
