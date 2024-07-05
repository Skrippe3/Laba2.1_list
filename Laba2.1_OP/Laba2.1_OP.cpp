#include"Header.h"

//односвязный список реализация

int main()
{
    system("chcp 1251");

    List<Engineer> engineer;

    /*List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
    lst.push_back(22);

    cout << lst.GetSize() << endl;//размер списка

    cout << lst[2] << endl;

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }*/
    bool flag = true;
    int choice;
    do
    {
        cout << "\nВыбирайте № операции:" << endl << "0) Выйти" << endl << "1) Добавить инженера в список"
            << endl << "2) Вывести всех инженеров" << endl
            << "4) Удалить инженера из списка" << endl << "5) Сохранить в файл" << endl << "6) Загрузить из файла" << endl << "7) Очистить список" << endl << "8) Поиск инженера" << endl << "9) Размер списка" << endl;
        cin >> choice;
        switch (choice)
        {
        default:
            break;
        case(0):
            flag = false;
            break;
        case(1):
        {
            Engineer newEngineer;
            string Name;
            string Specialization;
            string EducationLevel;
            int Age;
            int Experience;

            cout << "Введите имя инженера: ";

            cin >> Name;
            newEngineer.setName(Name);

            cout << "Введите возраст инженера: ";

            cin >> Age;
            newEngineer.setAge(Age);

            cout << "Введите опыт инженера в годах: ";

            cin >> Experience;
            newEngineer.setExperienxe(Experience);

            cout << "Введите специальность инженера: ";

            cin >> Specialization;
            newEngineer.setSpecialization(Specialization);

            cout << "Введите уровень образования: ";

            cin >> EducationLevel;
            newEngineer.setEducationLevel(EducationLevel);

            engineer.push_back(newEngineer);
        }
        break;
        case(2):
            for (int i = 0; i < engineer.GetSize(); i++)
            {
                engineer[i].Print();
            }
            break;
        case(3):
        {
            string searchName;
            cout << "Введите имя инженера:\t" << endl;
            cin >> searchName;
            //engineer[searchName];
        }
        break;
        case(4):
            engineer.pop_back();
            cout << "Инженер удален" << endl;
            break;
        case(5):
            for (int i = 0; i < engineer.GetSize(); i++)
            {
                engineer[i].SaveToFile();
            }
            break;
        case(6): {
            Engineer newEngineer;
            newEngineer.OpenFromFile(engineer);
            newEngineer.Test(engineer);
            break;
        }
        case(7):
        {
            engineer.clear();
            cout << "Список очищен" << endl;
            break;
        }
        case(8): {
            string searchName;
            bool search = true;

            cout << "Введите имя: " << endl;
            cin >> searchName;
            while (search)
            {
                for (int i = 0; i <= engineer.GetSize(); i++) {
                    if (searchName == engineer[i].getName()) {
                        engineer[i].Print();
                        search = false;
                        break;
                    }
                    else {
                        cout << "Инженер не найден" << endl;
                        continue;
                    }
                }
            }
            break;
        }
        case(9):
            cout << "Размер списка: \t" << engineer.GetSize() << endl << endl;//размер списка
            break;
        }  
    } while (flag);
    return 0;
}

