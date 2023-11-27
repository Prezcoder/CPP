
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

struct Data {
	string s1;
	string s2;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data* data = new Data;
	data->s1 = "Hello";
	data->s2 = "World";

	cout << "Data: " << data->s1 << " " << data->s2 << endl;
	cout << "Data: " << &data->s1 << " " << &data->s2 << endl;

	uintptr_t raw = serialize(data);
	Data* data2 = deserialize(raw);

	cout << "Data2: " << data2->s1 << " " << data2->s2 << endl;
	cout << "Data2: " << &data2->s1 << " " << &data2->s2 << endl;

	delete data;
	return 0;
}