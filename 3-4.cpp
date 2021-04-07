#include<iostream>
#include <string>
using namespace std;

class Time
{
public:
	Time(int hour = 0, int second = 0)
		:_hour(hour)
		, _second(second)
	{
		cout << "Time(int hour = 0, int second = 0)" << endl;
	}

	Time& operator=(const Time& t)
	{
		cout << "Time& operator=(const Time& t)" << endl;
		return *this;
	}

private:
	int _hour;
	int _second;
};

//class Date
//{
//public:
//	// 函数体内初始化
//	//int i;
//	//i = 10;
//	//Date(int year, int month, int day, int hour)
//	//	:_n(10)
//	//	, _ref(day)
//	//	, _t(hour)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	// int i = 10;
//	// 初始化列表--可以认为是对象每个成员变量定义初始化的地方
//	Date(int year, int month, int day, int hour, int second)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _n(10)
//		, _ref(day)
//		, _t(hour, second)
//		{}
//
//private:
//	int _year; // 声明
//	int _month;
//	int _day;
//
//	// 以下对象必须在定义的时候初始化
//	const int _n;
//	int& _ref;
//	Time _t; // 没有默认构造函数(不用参数调用的那个)的对象
//};
//
//int main()
//{
//	Date d1(2021, 3, 4, 10, 1); // 整个对象定义的位置
//	//const int n;
//	//n = 10;
//
//
//	return 0;
//}


//class Date
//{
//public:
//	// 推荐初始化列表写法
//	Date(int year, int month, int day, int hour, int second)
//		:_t(hour, second)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		//Time t(hour, second);
//		//_t = t;
//	}
//
//
//private:
//	int _year; // 声明
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d(2020, 1, 1, 1, 1);
//
//	return 0;
//}

// 
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//
//class Solution {
//public:
//	int StrToInt(string str) {
//		int n = str.size();
//		if (n < 1)
//			return 0;
//		int flag = 1;
//		int ret = 0;
//		if (str[0] == '-')
//		{
//			flag = -1;
//		}
//		else if (str[0] == '+')
//		{
//			flag = 1;
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			if (str[i] >= '0'&&str[i] <= '9')
//			{
//				ret = ret * 10 + str[i] - '0';
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		return ret*flag;
//	}
//};

//int main()
//{
//	A aa1(1);  // 他的生命周期在main函数域
//	A(2);  // 匿名对象，他的生命周期在这一行
//
//	Solution s;
//	cout << s.StrToInt("1234") << endl;
//
//	// 这个调用对象其他地方都不用，就这一行用，那么就可以用匿名对象
//	cout << Solution().StrToInt("1234") << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	explicit A(int a)
//		:_a(a)
//	{}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//	A aa2 = 2; 
//	// 结果调用构造函数 
//	// 隐式类型转换-》 先构造一个A(2)匿名临时对象，再用这个临时对象去拷贝构造aa2
//	// 最后呢，编译器把这两个过程优化合并了，直接调了构造函数
//
//	aa1.Print();
//	aa2.Print();
//
//	//int i = 0;
//	//const double& d = i;
//
//
//	return 0;
//}

//class string
//{
//  string(const char* str)
//  {}
//private:
//	// ...
//};

//int main()
//{
//	string s1("hello");
//	string s2 = "world";
//
//	string str("1234");
//	cout << Solution().StrToInt(str) << endl;
//
//	cout << Solution().StrToInt(string("1234")) << endl;
//
//	cout << Solution().StrToInt("1234") << endl;
//
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		++_countA;
//	}
//
//	A(const A& aa)
//	{
//		++_countA;
//	}
//
//	// 相比非静态成员函数，静态成员函数没有this指针
//	// 所以他不能访问其他的非静态成员
//	static int GetCountA()
//	{
//		//x = 10;
//		return _countA;
//	}
//
////private:
//	// 静态成员变量属于类的所有对象，属于整个类，声明
//	static int _countA;
//
//	int x;
//};
//
//// 定义初始化
//int A::_countA = 0;
//
//int main()
//{
//	//cout << sizeof(A) << endl;
//	A a1;
//	A a2;
//	A a3;
//	A a4(a1);
//	A a5(a1);
//	A();
//
//	// 如果没有访问限定符的限制，指定类域就可以访问静态成员
//	// 指定类域有两种方式，对象. 或者 类型::
//	//cout << a1._countA << endl;
//	//cout << A::_countA << endl;
//
//	cout << a1.GetCountA() << endl;
//	cout << A::GetCountA() << endl;
//
//	A * p = nullptr;
//	cout << p->_countA << endl;
//	//p->PrintA();
//	p->GetCountA();
//
//	return 0;
//}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//
//	int _b;
//};
//
//// C++11
//class A
//{
//public:
//	/*A(int a)
//		:_a(a)
//		{}*/
//
//	void Print()
//	{
//		cout << _a << endl;
//		cout << bb._b << endl;
//		cout << p << endl;
//	}
//
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值。
//	// 强调一下，这里不是初始化，这里是给的缺省值，
//	// 构造函数在没给值的情况下,就会用这里的缺省值
//	// 弥补C++98中默认构造函数，内置类型默认不处理的问题
//	int _a = 1;
//	B bb = 2;
//	int* p = (int*)malloc(4);
//};
//
//class Sum
//{
//public:
//	Sum()
//	{
//		_ret += _i;
//		++_i;
//	}
//
//	static int GetRet()
//	{
//		return _ret;
//	}
//
//private:
//	static int _i;
//	static int _ret;
//};
//
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum arr[n];
//		Sum* p = new Sum[n];
//
//		return Sum::GetRet();
//	}
//};
//
//int main()
//{
//	//A aa1(5);
//	/*A aa1;
//	aa1.Print();*/
//
//	cout << Solution().Sum_Solution(5) << endl;
//
//	return 0;
//}

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	/*void operator<<(ostream& out)
	{
	out << _year << "-" << _month << "-" << _day << endl;
	}*/

private:
	int _year;
	int _month;
	int _day;
};

//istream& operator>>(istream& in, Date& d);
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

int main()
{
	Date d1;
	Date d2(2020, 3, 4);
	//cin >> d1;
	operator<<(cout, d1);
	cout << d1 << d2;

	//d1.operator<<(cout);
	//d1 << cout;


	return 0;
}