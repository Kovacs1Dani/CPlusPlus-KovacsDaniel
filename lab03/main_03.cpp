#include <iomanip>
#include <iostream>
#include <random>

#include "PointSet.h"

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

    int m = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"
    <<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( m );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        m = m << 1;
    }

    return 0;
}