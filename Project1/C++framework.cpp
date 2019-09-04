#include<iostream>
using namespace std;
class  C++{
权限：
	public:公有成员，多作为外部接口。
	private: 私有成员, 在类的内部才可以访问。
	protected: 保护成员，该类内部和继承类中可以访问。
行为：
	void 抽象()；
	void 封装(整体、隐藏、安全性、实现)；
	void 继承(层次、复用)；
	void 多态()；
测试：
	断言（assert）；
	异常处理（try，throw，catch）；
}；

void C++::抽象() {
	概念（提取本质属性）{}
	方法（数据抽象(描述属性)、方法or代码抽象(描述共有行为) ）{}
	实现（通过类的声明）{}
}

void C++::封装(整体、隐藏、安全性、实现) {

	构造（）{}
	析构（）{}
	复制构造函数（）{}

	内联（）{
		内联函数（inline限定返回值类型）		定义： inline void Clock::func();
	}

	静态（静态变量类外初始化，调用无需对象）{
		静态成员函数（属于所有类共有的）        定义： static void func()；    访问： ClassName::func();
		静态数据成员（无需对象就可访问）		定义： static int val；		访问： ClassName::val();
	}

	友元（单向，不继承，不传递）{
		友元函数（访问权限扩大到其他类的私有）   定义： friend float dist(Point & a, Point & b);
		友元类									 定义： friend class B;
	}

	常(非成员函数不可用const) {
		常对象      A const a(3, 4); //a是常对象，不能被更新,等价于const  A a(3,4);
		常成员函数（重载函数）{
			//凡是不会改变对象状态的函数，都应当声明为常成员函数。
			//mutable关键字使得被修饰的成员对象无视“常对象的成员对象被视为常对象”这一语言原则
			/*mutable double len;
			double Line::getLen() const {
			if (len < 0) {
			double x = p1.getX() - p2.getX();
			double y = p1.getY() - p2.getY();
			len = sqrt(x * x + y * y); */
		}

		常引用（）{ const  类型说明符 & 引用名 }

		常数组（）{
			Point a[2] = { Point(1,2),Point(3,4) };
			Point a[2] = { Point(1,2) };    //缺省
		}

		常指针(指针本身为常量，指针指向常量类型) {
			指针本身为常量(const 指针本身值(地址值), const 指向关系) {
				定义： int a = 0;
				int* const p = &a;
				访问：* p = 1;  //  a的值由0变成1
				p = &b;//错误 指针本身是常量，指针值不能改变
			}

			指针指向常量类型(const 指针指向值, 可变地址值, 可变指向关系) {
				定义： int a = 0;
				const  int* p = &a;
				访问： int b = 0;
				p = &b;	//正确，p1本身的值可以改变
				*p = 1;	//编译时出错，不能通过p1改变所指的对象
				b = 1；    // b的值能改变么？？？ ；

			}
		}
	}

	泛型程序（函数模板，类模板）{

		函数模板：
			定义   template <模板参数表>  
		//模板参数表形式：      class 类型参数  或  typename  类型参数
				   <类型> <函数名>(<参数表>)    
			//1）至少有一个参数的类型为模板的类型参数，函数的返回值的类型也可以是该类型参数
			//2）模板中可以带有多个参数类型。		
											template <class T1, class T2, class T3>
											void func1(T1 arg1，T2 arg2, T3 arg3)
			//3）函数可以带有模板参数表中未给出的、已存在的数据类型的参数。
											template <class T>
		/									T func2(T arg1，int arg2)

		类模板：
			定义	template <模板参数表>
					class 类名
			//1）类模板以外定义其成员函数基本形式	
											template <模板参数表>
											类型名 类名<模板参数标识符列表>::函数名（参数表）
			//例子：
			Vector() {
				定义： vector<元素类型>  数组对象名(数组长度);
					   vector<int> arr(5)      //建立大小为5的int动态数组
					   vector<ClassName> arr(count) //建立大小为count的point动态数组
			}

	}
}

void C++::继承(层次、复用) {
	继承方式（公有继承，私有继承(默认)，保护继承） { }
	
	类型兼容规则（对象隐含转换，引用，指针）{
		派生类的对象在使用上可以被当作基类的对象，反之则禁止。
		通过基类对象名、指针只能使用从基类继承的成员
		基类对象出现的场合可以使用派生类对象进行替代，替代之后，派生类仅仅只能发挥出基类的作用
	}

	同名隐藏规则（隐藏规则，就近原则）{
		派生类在内层
		当派生类与基类中有相同成员时：
		派生类对象使用的是派生类中的成员
		如果一定要通过派生类对象访问基类中被隐藏的同名成员，应使用基类名base::限定   e.g. Object.base::func();
	}

	二义性（基类和派生类同时出现同名成员，一个基类-> 多个基类 -> 一个派生类）{ 

		情况一（虚函数或同名隐藏规则）{
			解决方法1：用类名::来限定c1.A::f()    或    c1.B::f()
			解决方法2：同名隐藏在C 中声明一个同名成员函数f()，f()再根据需要调用  A::f()    或    B::f()
		}

		情况二（虚基类）{
			解决方法1：class Base1 : virtual public Base0    //Base0为虚基类，让最远派生类只有唯一副本
		}
	}
}
void C++::多态() {
	重载（函数重载，运算符重载）{

		函数重载（形参类型，个数，有无const）{}

		运算符重载（用户自定义类型）{
			定义： 函数类型  operator 运算符（形参）
			重载为类成员函数时  参数个数 = 原操作数个数 - 1	（后置++、--除外）
			重载为非成员函数时	 参数个数 = 原操作数个数，且至少应该有一个自定义类型的形参
		}
	}

	绑定（静态绑定，动态绑定）{
		静态绑定（）{
			使用对象名访问函数，一定是静态绑定
		}

		动态绑定（）{
			A)虚函数
			B)访问形式：指针或者引用
			两者缺一不可！！！
		}
	}

	虚（虚函数，虚析构函数，纯虚函数，虚基类）{

		虚函数（和指针访问实现动态绑定）{
			virtual 类型 函数名(参数表)
		}

		虚析构函数（基类必备析构）{
			通过基类的指针删除派生类对象时，首先调用派生类的析构函数，然后调用基类的析构函数。
		}

		纯虚函数（生成抽象类）{
			定义： virtual 类型 函数名(参数表) = 0;
			抽象类（至少含有一个纯虚函数的类称为抽象类）{
				基类
				只提供接口的框架，不提供任何实现的代码
				具体类的实现，交给派生类来完善     //抽象类不能实例化，不能声明抽象类的对象，可以定义抽象类的指针和引用
			}
		}

		虚基类（处理二义性）{
			class Base1 : virtual public Base0    //Base0为虚基类，让最远派生类只有唯一副本
		}
	}
}


异常处理（try，throw，catch）{
	try {
		//复合语句
		……
		throw 表达式1;
		……
	    throw 表达式n;
	 }

	catch (异常类型说明1){
		//复合语句
		 ...... 
	}
}

int main()
{
	C++ *pc = new C++[100];	//对每一个C++类初始化
	delete[] pc;

	C++ *pc = new C++[100](); 
	delete[] pc;

	pc = new C++[100]();
	delete[] pc;

	vector<int>Cap(100);

	return ;
}