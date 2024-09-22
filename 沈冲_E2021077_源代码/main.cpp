#include <iostream>
#include <vector>
#include <filesystem>
#include "SmartCar.h"
using namespace std;

int main()
{
    const int numCars = 10;
    vector<SmartCar> cars;
    string choice;

    int txtCount = 0;
    string current_path = "./";

    for (const auto &entry : std::filesystem::directory_iterator(current_path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            txtCount++;
        }
    }

    if (txtCount != numCars)
    {
        for (int i = 0; i < numCars; ++i)
        {
            string id = "cqusn000000000A" + to_string(i);
            SmartCar car(id);
            string stuId;
            string stuName;

            cout << "请输入学生" + to_string(i + 1) + "的ID：" << endl;
            cin >> stuId;
            cout << "请输入学生" + to_string(i + 1) + "的姓名：" << endl;
            cin >> stuName;

            car.setStudentId(stuId);
            car.setStudentName(stuName);
            cout << "学生" + to_string(i + 1) + "分配小车成功！" << endl;
            cout << "" << endl;
            string fileName = "car" + to_string(i + 1) + ".txt";
            car.saveToFile(fileName);
            cars.push_back(car);
        }
        cout << "全部信息录入完成！" << endl;
        cout << "您是否想查看录入的信息(y/n)" << endl;
        cin >> choice;
    }

    if (choice == "y" || txtCount == 10)
    {
        for (int i = 0; i < numCars; ++i)
        {
            string fileName = "car" + to_string(i + 1) + ".txt";
            SmartCar car = SmartCar::loadFromFile(fileName);
            cars.push_back(car);
        }

        int currentIndex = 0;
        while (true)
        {
            cout << "************************************" << endl;
            cout << "n 显示下一辆小车信息" << endl;
            cout << "p 显示上一辆小车信息" << endl;
            cout << "q 退出" << endl;
            cout << "************************************" << endl;
            cars[currentIndex].display();

            char ch;
            cin >> ch;

            if (ch == 'n')
            {
                if (currentIndex < numCars - 1)
                {
                    ++currentIndex;
                }
            }
            else if (ch == 'p')
            {
                if (currentIndex > 0)
                {
                    --currentIndex;
                }
            }
            else if (ch == 'q')
            {
                break;
            }
        }
    }

    return 0;
}