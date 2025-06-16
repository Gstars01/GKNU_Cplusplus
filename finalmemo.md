# CPP final exam note

### class with smart pointer
```cpp
#include<iostream>
using namespace std;

class CPloy {
protected:
	int x, y;
public:
	CPloy(int x, int y) :x(x), y(y) {}
	virtual int Area() =0;
};

class CRect : public CPloy {
public:
	CRect(int x, int y) :CPloy(x, y) {}
	int Area() override {
		return x * y;
	}
};

class CTri : public CPloy {
public:
	CTri(int x, int y) :CPloy(x, y) {}
	int Area() override {
		return (x * y) / 2;
	}
};

int main() {
	unique_ptr<CRect> r1 = make_unique<CRect>(3, 4);
	unique_ptr<CTri> t1 = make_unique<CTri>(3, 4);
	cout << r1->Area() << endl;
	cout << t1->Area() << endl;

}
```
### template
```cpp
#include<iostream>
using namespace std;
template<typename T>
T add(T a, T b) {
	return a + b;
}

template<>
string add<string>(string a,string b){return a+ " " + b; }

int main() {
	cout << add(3, 7) << endl;
	cout << add(2.5, 4.3) << endl;
	cout << add(string("Hello"), string("world!")) << endl;
}
```
### file input/output <fstream> <ifstream> <ofstream>
```cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main() {
	ofstream of("my.txt");
	if (of.is_open()) { of << "GKNU!";of.close(); }
	ifstream in("my.txt");
	if (in.is_open()) {
		string line;
		while (getline(in, line)) { cout << line << endl; }
		in.close();
	}
	return 0;
}
```
win32 , mfc , winui 출시년도 순서
