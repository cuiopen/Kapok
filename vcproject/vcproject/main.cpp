#include <array>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "kapok/Kapok.hpp"

void test()
{
	Serializer sr;
	DeSerializer dr;

	auto tp = std::make_tuple(10, 12, string("test"));
	sr.Serialize(tp, "tuple");
	dr.Parse(sr.GetString());
	std::tuple<int, int, string> p;
	dr.Deserialize(p, "tuple");
}

template<class T>
void test_array( T& arr)
{
	Serializer sr;
	sr.Serialize(arr, "test");
	std::cout << sr.GetString() << std::endl;

	DeSerializer dr;
	dr.Parse(sr.GetString());
	T de_arr;
	dr.Deserialize(de_arr, "test");
}

template<class T>
void test_map( T& map)
{
	Serializer sr;
	sr.Serialize(map, "test");
	std::cout << sr.GetString() << std::endl;

	DeSerializer dr;
	dr.Parse(sr.GetString());
	T de_map;
	dr.Deserialize(de_map, "test");
}

struct person 
{
	int age;
	std::string name;
	META(age, name);
};

template<class T>
void test_object(T& t)
{
	Serializer sr;
	sr.Serialize(t, "test");
	std::cout << sr.GetString() << std::endl;

	DeSerializer dr;
	dr.Parse(sr.GetString());
	T de_t;
	dr.Deserialize(de_t, "test");
}

int main()
{
	std::array<std::string, 5> arr = { "a","b","c", "d", "e" };
	test_array(arr);

	std::vector<std::string> vt = { "a","b","c", "d", "e" };
	test_array(vt);

	int int_arr[5] = { 1,2,3,4,5 };
	test_array(int_arr);

	std::string str_arr[5] = { "a","b","c", "d", "e" };
	test_array(str_arr);

	std::queue<std::string> que_arr;
	que_arr.emplace("a");
	que_arr.emplace("b");
	test_array(que_arr);

	std::deque<std::string> deque_arr;
	deque_arr.push_back("a");
	deque_arr.push_back("b");
	test_array(deque_arr);

	std::priority_queue<std::string> priodeque_arr;
	priodeque_arr.push("a");
	priodeque_arr.push("b");
	test_array(priodeque_arr);

	std::set<std::string> set_arr;
	set_arr.emplace("a");
	set_arr.emplace("b");
	test_array(set_arr);
	std::multiset<std::string> multiset_arr;
	multiset_arr.emplace("a");
	multiset_arr.emplace("b");
	test_array(multiset_arr);
	std::unordered_set<std::string> unordset_arr;
	unordset_arr.emplace("a");
	unordset_arr.emplace("b");
	test_array(unordset_arr);

	std::stack<std::string> stack_arr;
	stack_arr.emplace("a");
	stack_arr.emplace("b");
	test_array(stack_arr);

	std::map<int, std::string> map = { {1, "a"},{2, "b"} };
	test_map(map);
	std::multimap<int, std::string> multimap = { { 1, "a" },{ 2, "b" } };
	test_map(multimap);
	std::unordered_map<int, std::string> unodermap = { { 1, "a" },{ 2, "b" } };
	test_map(unodermap);

	person p = { 20, "test" };
	test_object(p);

	return 0;
}