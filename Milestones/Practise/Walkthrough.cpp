//#include <iostream>
//using namespace std;
//
//class Counter
//{
//public:
//    Counter()
//    {
//        //cout << "A" << endl;
//    }
//
//    Counter(const Counter& Obj)
//    {
//        cout << "C" << endl;
//    }
//
//    void operator=(const Counter& Obj)
//    {
//        cout << "D" << endl;
//    }
//};
//
//class Assistant : public Counter
//{
//public:
//    Assistant()
//    {
//        cout << "B" << endl;
//    }
//
//    Assistant(const Assistant& obj) : Counter(obj)
//    {
//        cout << "E" << endl;
//    }
//
//    void operator=(const Assistant& obj)
//    {
//        Counter::operator=(obj);
//        cout << "F" << endl;
//    }s
//};
//
//int main()
//{
//    Assistant Obj1, Obj2, Obj3;
//
//    Obj2 = Obj1;
//    Obj3 = Obj2;
//
//    return 0;
//}


#include <iostream>

using namespace std;

class Counter
{
	int no;

public:

	Counter(int var = 1)
	{
		no = var;
	}

	void inc()
	{
		no++;
	}

	void print()
	{
		cout << no << endl;
	}

	void fun(Counter obj)
	{
		obj.inc();
		obj.inc();
	}
};
