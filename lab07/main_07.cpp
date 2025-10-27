#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    //Elso feladat
    vector<string> fruits {
        "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
        };

    string substr = "berry";

    auto iterator =
        find_if(fruits.begin(), fruits.end(),[&substr](const string& fruit){return fruit.find(substr) != string::npos;});


    if (iterator != fruits.end()) {
        cout << "Theres a fruit like: " << substr << " at position: " << *iterator;
    }
    else {
        cout << "Theres no such fruit as:" << substr;
    }
    //Masodik feladat
    vector<int> numbers {2, 4, 6, 8, 10};

    bool allEven = all_of(numbers.begin(), numbers.end(), [](int n) {return n % 2 == 0;});

    if (allEven) {
        cout << "\nMinden elem paros." << endl;
    }else {
        cout << "\nNem minden elem paros." << endl;
    }
    //Harmadik feladat
    vector<int> nums {1,2,3,4,5,6};

    auto doubledNums = for_each(nums.begin(), nums.end(), [](int &n){return n *= 2;});

    for (auto d : nums) {
        cout << d << " ";
    }
    cout << endl;
    //Negyedik feladat
    vector<string> months {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
        };

    int countFive = count_if(months.begin(), months.end(), [](const string& month) {return month.size() == 5;});


    cout << "The number of months with 5 letters: " << countFive << endl;
    //Otodik feladat
    vector<double> nums2 {3.14, 5.66, 4.32, 5.56, 7.54, 9.99};

    sort(nums2.begin(), nums2.end(),
        [](double a, double b) { return a > b; });

    cout << "Csokkeno sorrend (lambda): ";
    for (double n : nums2) {
        cout << n << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end(), greater<double>());

    cout << "Descending order (greater): ";
    for (float n : nums2) {
        cout << n << " ";
    }
    cout << endl;
    //Hatodik feladat
    vector<pair<string, double>> monthsTemp = {
        {"January", 0.5},
        {"February", 2.1},
        {"March", 6.4},
        {"April", 12.3},
        {"May", 17.5},
        {"June", 20.4},
        {"July", 22.1},
        {"August", 21.6},
        {"September", 17.2},
        {"October", 11.2},
        {"November", 5.0},
        {"December", 1.2}
    };

    sort(monthsTemp.begin(), monthsTemp.end(), [](const pair<string, double>& a, const pair<string, double>& b ) {return a.second < b.second;});
    for (const auto& p : monthsTemp) {
        cout << p.first << " - " << p.second << " °C\n";
    }
    return 0;
}