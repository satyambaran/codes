#include <bits/stdc++.h>
using namespace std;
// class Ride {};
class Ride {};
class Person {
	public: 
		string name;
};
class Rider : private Person {};
// inherits all the//?public property of class Person as private property
class Driver : private Person { public: int k; Driver(string name) {
     this->name = name; int k=5; this->k=5;
     vector<int> v;};
};
int main() { 
    int * j;
    return 0; }