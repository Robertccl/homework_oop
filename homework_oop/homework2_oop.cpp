#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class UniversityObject
{
public:

	virtual string getSummary() = 0;

};

class Student : public UniversityObject
{
public:

	Student(string n, string r)
	{
		name = n;
		registrationNum = r;
	}

	string getSummary()
	{
		return "学号 " + registrationNum + ", " + name;

	}


	~Student()
	{
		name = "";
		registrationNum = "";
	}

private:
	string name;
	string  registrationNum;
};

class LectureTheatre : public UniversityObject
{
public:

	LectureTheatre(double r, double s)
	{
		roomNum = r;
		seatNum = s;

	}

	string  getRoomNum()
	{
		double temp = roomNum;
		int building = (int)temp;
		temp = temp - building;
		int room = (int)temp;

		while (temp - room > 1e-6)
		{
			temp *= 10;
			room = (int)temp;
		}
		string s= to_string(building) + "号楼" + to_string(room);
		return  s;
	}

	string getSummary()
	{
		string result = getRoomNum() + ", 共";
		result += to_string(seatNum) + "个座位";
		return result;

	}

	~LectureTheatre()
	{
		roomNum = 0.0;
		seatNum = 0;

	}

private:
	double roomNum;
	int seatNum;
};

class Module : public UniversityObject
{
public:

	Module(string t, string c, int num)
	{
		title = t;
		code = c;
		personNum = num;
	}

	string getSummary()
	{
		string result = "编号 " + code + ", 《" + title + "》, ";
		result += to_string(personNum) + "人选修";
		return  result;

	}

	~Module()
	{
		title = "";
		code = "";
		personNum = 0;
	}



private:
	string title;
	string code;
	int personNum;
};

//int main()
//{
//
//	UniversityObject *a1 = (UniversityObject *) new Student("张三", "0320121113"),
//		*a2 = (UniversityObject *) new LectureTheatre(3.205, 186),
//		*a3 = (UniversityObject *) new Module("面向对象技术", "0321011", 185);
//	cout << "汇总结果：" << endl;
//	cout << "\t学生：" << a1->getSummary() << endl;
//	cout << "\t教室：" << a2->getSummary() << endl;
//	cout << "\t课程：" << a3->getSummary() << endl;
//	getchar();
//	//printf("汇总结果:\n 学生: %s\n 教室: %s\n 课程: %s\n", a1->getSummary().c_str(), a2->getSummary().c_str(), a3->getSummary().c_str());
//	return 0;
//}