#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>


std::vector<std::string> getInput(std::string fileName)
{
    std::ifstream inputStream {fileName};
    std::vector<std::string> ids {std::istream_iterator<std::string>(inputStream), {}};
    return ids;
}


std::set<int> letterCounts(std::string s)
{
    std::set<char> letters {s.begin(), s.end()};
    std::set<int> counts;
    for (auto& letter : letters) {
        auto count = std::count(s.begin(), s.end(), letter);
        counts.insert(count);
    }
    return counts;
}


std::string commonLetters(std::vector<std::string> ids)
{
    auto size = ids.size();
    std::string sameLetters = "";
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            auto difference {0};
            for (int s = 0; s < ids[i].length(); s++) {
                bool condition = ids[i][s] == ids[j][s];
                if (condition) {
                    sameLetters += ids[i][s];
                } else if (!condition and difference == 0) {
                    difference++;
                } else {
                    sameLetters = "";
                    break;
                }
            }
            if (!sameLetters.empty()) {
                return sameLetters;
            }
        }
    }
    return sameLetters;
}


int product(std::vector<std::string> ids)
{
    auto times_two {0};
    auto times_three {0};
    for (auto& id : ids) {
        auto counts = letterCounts(id);
        if (counts.count(2)) {
            times_two += 1;
        }
        if (counts.count(3)) {
            times_three += 1;
        }
    }
    return times_two * times_three;
}


void test()
{
    std::string a = "aaabbbcccccdddd";
    auto counts = letterCounts(a);
    if (!counts.count(2)) {
        std::cout << "pass\n";
    }
    if (counts.count(3)) {
        std::cout << "pass\n";
    }
    if (counts.count(4)) {
        std::cout << "pass\n";
    }

    std::vector<std::string> b = {"abcde", "fghij", "klmno", "pqrst", "fguij", "axcye", "wvxyz"};
    auto x = commonLetters(b);
    std::cout << "x: " << x << "\n";
    if (x != "fgij") {
        std::cout << "fail\n";
    }

}


int main(void)
{
    test();
    auto ids = getInput("day2.txt");
    std::cout << product(ids) << "\n";
    auto c = commonLetters(ids);
    std::cout << c << "\n";
}
