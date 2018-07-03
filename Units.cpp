//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

//定义一个总的单位类
class Danwei{
public:
	double chuzhi;
	string firstdanwei;
	string seconddanwei;
	
	Danwei(double n,string first, string second)
	{
		chuzhi = n;
		firstdanwei = first;
		seconddanwei = second;
	}
	double get_chuzhi()
	{
		return chuzhi;
	}	
	string get_first()
	{
		return firstdanwei;
	}
	string get_second()
	{
		return seconddanwei;
	}
	
}; 

//定义一个单位为长度的类 
class Length : public Danwei
{
public:
	Length(double n,string first, string second):Danwei(n,first,second)	{}
	
	double to_middle()
	{
		if(firstdanwei == "m")
		    return chuzhi;
		else if(firstdanwei == "km")
		    return chuzhi*pow(10,3);
		else if(firstdanwei == "dm")
			return chuzhi*pow(10,-1);
		else if(firstdanwei == "cm")
			return chuzhi*pow(10,-2);
		else if(firstdanwei == "mm")
		    return chuzhi*pow(10,-3);
		else if(firstdanwei == "nm")
		    return chuzhi*pow(10,-9);
	}
	double to_second()
	{
		string s = seconddanwei;
		if(s == "m")
		    return to_middle();
		else if(s == "km")
		    return to_middle()*pow(10,-3);
		else if(s == "dm")
		    return to_middle()*pow(10,1);
		else if(s == "cm")
		    return to_middle()*pow(10,2);
		else if(s == "mm")
		    return to_middle()*pow(10,3);
		else if(s == "nm")
		    return to_middle()*pow(10,9);
	}
	void length_out()
	{
		cout << to_second() << " " << seconddanwei << endl;
	}
}; 

//定义一个单位为质量的类
class Mass : public Danwei
{
public:
	
	Mass(double n,string first,string second):Danwei(n,first,second){}
	
	double to_middle()
	{
		if(firstdanwei == "g")
		    return chuzhi;
		else if(firstdanwei == "kg")
		    return chuzhi*pow(10,3);
		else if(firstdanwei == "mg")
		    return chuzhi*pow(10,-3);
		else if(firstdanwei == "t")
		    return chuzhi*pow(10,9);
	}
	double to_second()
	{
		string s = seconddanwei;
		if(s == "m")
		    return to_middle();
		else if(s == "kg")
		    return to_middle()*pow(10,-3);
		else if(s == "mg")
		    return to_middle()*pow(10,3);
		else if(s == "t")
		    return to_middle()*pow(10,-9);
	}
	void mass_out()
	{
		cout << to_second() << " " << seconddanwei << endl;
	}
};  

//定义一个单位为时间的类
class Time : public Danwei
{
public:
	
	Time(double n,string first,string second):Danwei(n,first,second){}
	
	double to_middle()
	{
		if(firstdanwei == "second")
		    return chuzhi;
		else if(firstdanwei == "minute")
		    return chuzhi*60;
		else if(firstdanwei == "hour")
		    return chuzhi*60*60;
		else if(firstdanwei == "day")
		    return chuzhi*60*60*24;
		else if(firstdanwei == "month")
		    return chuzhi*60*60*24*30;
		else if(firstdanwei == "year")
		    return chuzhi*60*60*24*30*12;
	}
	double to_second()
	{
		string s = seconddanwei;
		if(s == "second")
		    return to_middle();
		else if(s == "minute")
		    return to_middle()/60;
		else if(s == "hour")
		    return to_middle()/60/60;
		else if(s == "day")
		    return to_middle()/60/60/24;
		else if(s == "month")
		    return to_middle()/60/60/24/30;
		else if(s == "year")
		    return to_middle()/60/60/24/30/12;
	}
	void time_out()
	{
		cout << to_second() << " " << seconddanwei << endl;
	}
};  

 
//判断是不是长度单位 
bool is_length(string s)
{
	if(s == "m" || s == "km" || s == "dm" || s == "cm" || s == "mm" || s == "nm")
	    return true;
	else
	    return false;
}

//判断是不是质量单位
bool is_mass(string s)
{
	if(s == "g" || s == "kg" || s == "mg" || s == "t")
	    return true;
	else
	    return false;
} 

//判断是不是时间单位
bool is_time(string s)
{
	if(s == "second" || s == "minute" || s == "hour" || s == "day" || s == "month" || s == "year")
	    return true;
	else
	    return false;
}  

/*判断输入的单位是属于哪种单位 
0表示长度单位；1表示重量单位；2表示时间单位；*/ 
int judge(Danwei d)
{
	if(is_length(d.firstdanwei))
	    return 0;
	else if(is_mass(d.firstdanwei))
		return 1;
	else if(is_time(d.firstdanwei))
	    return 2;
}

int main()
{
	double chuzhi;
	string firstdanwei;
	string seconddanwei;
	cout << "请输入初值：" << endl;
	cin >> chuzhi;
	cout << "请输入初始单位：" << endl;
	cin >> firstdanwei;
	cout << "请输入转化后的单位：" << endl;
	cin >> seconddanwei;
	cout << "转化后的值为：" << endl;
	Danwei d1(chuzhi,firstdanwei,seconddanwei);
	switch (judge(d1))
	{
		case 0:
			{
				Length l1(chuzhi,firstdanwei,seconddanwei);
			    l1.length_out();
				break;
			}
			
		case 1:
			{
				Mass m1(chuzhi,firstdanwei,seconddanwei);
				m1.mass_out();
				break;	
			}
		case 2:
			{
				Time t1(chuzhi,firstdanwei,seconddanwei);
				t1.time_out();
				break;
			}
		default:
			break;
	}
	return 0;	
}

