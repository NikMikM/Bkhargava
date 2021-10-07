#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <exception>
#include <deque>
#include <iterator>
#include <set>
#include <sstream>
using namespace std;

#define PRINT(x) {\
	PrintVector(x,#x);\
}
template <typename T>
void PrintVector(const vector<T>& vec,const string& name_of_vector){
	cout << name_of_vector << "  =  {";
	for (size_t i = 0; i < vec.size();++i){
		cout << vec[i] << " ," ;
	}
	cout << "}" << endl;
}
int BinarySearch(vector<int> &v, const int &x) {
	sort(begin(v),end(v));
	int low = 0, mid = 0;
	int high = static_cast<int>(v.size() - 1);

	while (low <= high) {
		mid = (low + high) / 2;
		int guess = v[mid];

		if (x > guess) {
			low = mid + 1;
		}
		if (x < guess) {
			high = mid - 1;
		}
		if (x == guess) {
			return mid;
		}
	}
	throw runtime_error("no element");
}

vector<int> SelectionSort(vector<int> &v) {
	vector<int> NewArr(static_cast<int>(v.size()));
	vector<int> V = v;
	int smallest;
	for (size_t i = 0; i < v.size(); i++) {
		auto it = min_element(begin(V), end(V));
		smallest = *it;
		NewArr[i] = smallest;
		V.erase(it);

	}
	return NewArr;
}

//vector<int> QuickSort(vector<int> &v) {
//	if (v.size() < 2) {
//		return v;
//	} else {
//	vector<int> greater, lesser;
//	vector<int> all;
//	int point = v[0];
//	for (size_t i = 0; i < v.size(); i++) {
//		if (v[i] <= point) {
//			lesser.push_back(v[i]);
//		} else {
//			greater.push_back(v[i]);
//		}
//	}
//	vector<int> les = QuickSort(lesser);
//	vector<int> gre = QuickSort(greater);
//
////	all.insert(end(all),begin(QuickSort(lesser)),end(QuickSort(lesser)));
////	all.push_back(point);
////	all.insert(end(all), begin(QuickSort(greater)), end(QuickSort(greater)));
//	all.insert(end(all),begin(les),end(les));
//	all.push_back(point);
//	all.insert(end(all), begin(gre), end(gre));
//	return all;
//	}
//
//}
bool CheckGraph (const string& s){
	if (s.back() == '5'){
		return true;
	} else {
		return false;
	}
}
string GraphSearch(map<string,vector<string>> graph){
	deque<string> deq;
	set<string> checked;
	deq.push_back("1");
	while(!deq.empty()){
		string current = deq.front();
		string next = graph[current].front();
		for (auto i : graph[current]){
			deq.push_back(i);

		}
		if ((CheckGraph(next)) && (checked.find(next) == end(checked))){
			return next;
		}else{
			checked.insert(next);
			if (!graph[current].empty()){
			graph[current].erase(begin(graph[current]));
			}
			deq.pop_front();
		}
	}
	return "Was never found";

}
int main() {
	//test for Binary search
	try {
		vector<int> v = { 5, 2, 3, 1, 16, 7, 5, 4, 8 };
		cout << "BinarySearch for 2 : position = " << BinarySearch(v, 2) << endl;
		cout << "BinarySearch for 5 : position = " << BinarySearch(v, 5) << endl;
		cout << "BinarySearch for 10 : position = " << BinarySearch(v, 10) << endl;
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	//test for Selection sort
	vector<int> nums;//= {9,8,7,6,5,4,3,2,1};
	int i = 0;
	string input;
	getline(cin,input);
	istringstream ss(input);
	int number;
	while(ss >> number){
		nums.push_back(number);
		i++;
	}
	vector<int> sorted = SelectionSort(nums);
	for (size_t i = 0; i < sorted.size();i++){
		cout << "Printing sorted: " << sorted[i] << endl;
	}
//	//test for Quick sort
//		vector<int> q_nums = {9,8,7,6,5,4,3,2,1};
//		vector<int> q_sorted= QuickSort(q_nums);
//		for (size_t i = 0; i < q_sorted.size();i++){
//			cout << sorted[i] << endl;
//		}
	map<string,vector<string>> graph = {{"1",{"21","22"}},
										{"21",{"31","32","33"}},
										{"22",{"32","42"}},
										{"31",{"41","42","45"}},
										{"32",{"22"}},
										{"33",{"41","43"}},
										{"42",{"55"}}};
	cout << GraphSearch(graph);
	return 0;
}
