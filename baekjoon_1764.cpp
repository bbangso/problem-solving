#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	set<string> list1;
	set<string> list2;

	string name;

	while (n--) {
		cin >> name;
		list1.insert(name);
	}

	while (m--) {
		cin >> name;
		
		if (list1.count(name))
			list2.insert(name);
	}

	cout << list2.size() << '\n';
	for (auto iter = list2.begin(); iter != list2.end(); iter++) {
		cout << *iter << '\n';
	}
}