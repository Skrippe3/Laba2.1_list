#include"Header.h"

void Engineer::setName(string newName) {
	name = newName;
}
void Engineer::setSpecialization(string newSpecialization) {
	specialization = newSpecialization;
}
void Engineer::setEducationLevel(string newEducationLevel) {
	educationLevel = newEducationLevel;
}
void Engineer::setAge(int newAge) {
	age = newAge;
}
void Engineer::setExperienxe(int newExperienxe) {
	experience = newExperienxe;
}

string Engineer::getName() { return name; }
string Engineer::getSpecialization() { return specialization; }
string Engineer::getEducationLevel() { return educationLevel; }
int Engineer::getAge() { return age; }
int Engineer::getExperienxe() { return experience; }

void Engineer::SaveToFile()
{
	ofstream Fout("EngineerData.txt", ios::app);
	if (!Fout.is_open())
		cout << "\nФайл не открылся" << endl;
	else {
		Fout << getName() << endl;
		Fout << getAge() << endl;
		Fout << getSpecialization() << endl;
		Fout << getEducationLevel() << endl;
		Fout << getExperienxe() << endl;
	};
	Fout.close();
	cout << "Запись прошла успешно." << endl;
};

void Engineer::OpenFromFile(List<Engineer>& engineer)
{
	ifstream Fin("EngineerData.txt");
	if (!Fin.is_open())
		cout << "\nФайл не открылся" << endl;
	else {
		string line;
		Engineer temp;

		while (!Fin.eof())
		{

			getline(Fin, line);
			temp.setName(line);

			getline(Fin, line);
			temp.setSpecialization(line);

			getline(Fin, line);
			temp.setEducationLevel(line);

			Fin >> age;
			Fin.ignore();
			temp.setAge(age);

			Fin >> experience;
			Fin.ignore();
			temp.setExperienxe(experience);

			engineer.push_back(temp);
		}
	}
	Fin.close();
	cout << "Чтение прошло успешно." << endl;
};

void Engineer::Print() {
	cout << "///////////////////////// ///////////////////////// /////////////////////////" << endl;
	cout << getName() << endl;
	cout << getAge() << endl;
	cout << getSpecialization() << endl;
	cout << getEducationLevel() << endl;
	cout << getExperienxe() << endl;
}

void Engineer::Test(List<Engineer>& engineer) {

	Engineer buffer;
	buffer.OpenFromFile(engineer); // ввод с клавиатуры для сравнения с последним элементом списка

	if (buffer.getName() == getName() &&
		buffer.getAge() == getAge() &&
		buffer.getSpecialization() == getSpecialization() &&
		buffer.getEducationLevel() == getEducationLevel() &&
		buffer.getExperienxe() == getExperienxe())
	{
		cout << "Тестирование прошло успешно. Ошибок нет." << endl;
	}
	else {
		cout << "Поля не соответствуют считанным повторно: " << endl;
		if (!(buffer.getName() == getName()))
		{
			cout << "Обнаружена ошибка поля имени: " << buffer.getName() << endl;
		}
		if (!(buffer.getAge() == getAge()))
		{
			cout << "Обнаружена ошибка поля возраст: " << buffer.getAge() << endl;
		}
		if (!(buffer.getSpecialization() == getSpecialization()))
		{
			cout << "Обнаружена ошибка поля специальность: " << buffer.getSpecialization() << endl;
		}
		if (!(buffer.getEducationLevel() == getEducationLevel()))
		{
			cout << "Обнаружена ошибка поля образование: " << buffer.getEducationLevel() << endl;
		}
		if (!(buffer.getExperienxe() == getExperienxe()))
		{
			cout << "Обнаружена ошибка поля опыт: " << buffer.getExperienxe() << endl;
		}
	}
}




