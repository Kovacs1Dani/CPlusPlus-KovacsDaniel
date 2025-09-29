#include <iostream>
#include <random>

using namespace std;

const int MAX = 1000;
int main() {
    srand(time(NULL));
    int x[100];
    int n = 10;
    cout<<"x = [";
    for( int i=0; i<n; ++i ){
        x[i] = rand() % MAX;
        cout<<x[i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Legkisebb : " << *min_element(x, x+n) << endl;
    vector<int> v;
    v.reserve(100);
    cout<<"v = [";
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, MAX);
    for( int i=0; i<n; ++i ){
        v.emplace_back( dist(mt) );
        cout<<v[ i ]<<" ";
    }
    cout << "]" <<endl;
    cout << "Legnagyobb: " << *max_element(v.begin(),v.end()) << endl;
    return 0;
}