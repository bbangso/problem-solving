#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	set<string> people;
	int n;
	
	cin >> n;

	string name, op;

	while (n--) {
		cin >> name >> op;

		if (op[0] == 'e') {
			people.insert(name);
		}
		else {
			people.erase(people.find(name));
		}
	}


	for (auto iter = people.rbegin(); iter != people.rend(); iter++) {
		cout << *iter << '\n';
	}
}