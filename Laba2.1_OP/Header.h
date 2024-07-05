#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//реализаци€ списка
template<class T>
class List
{
public:
	List();
	~List();
	int GetSize() { return Size; }
	void push_back(T data);
	void pop_front();
	void clear();
	void pop_back();

	T& operator[](const int index);
	void removeAt(int index);
	//возвращает данные из списка, которые наход€тс€ под этим индексом

private:
	template<class T>
	class Node //хранит данные нашего списка
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
	
};
class Engineer {
private:
	string name;
	string specialization;
	string educationLevel;
	int age;
	int experience;

	int Size;

	template<class T>
	class Node //хранит данные нашего списка
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

public:
	void setName(string _newName);
	void setSpecialization(string _newSpecialization);
	void setEducationLevel(string _newEducationLevel);
	void setAge(int _newAge);
	void setExperienxe(int _newExperience);
	void SaveToFile();
	void OpenFromFile(List<Engineer>& engineer);
	void Print();
	void Test(List<Engineer>& engineer);


	

	string getName();
	string getSpecialization();
	string getEducationLevel();
	int getAge();
	int getExperienxe();

	Engineer()   //  онструктор по умолчанию
	{
		name = "empty";
		specialization = "empty";
		educationLevel = "empty";
		age = 0;
		experience = 0;
	}
	Engineer(string name, string specialization, string educationLevel, int age, int experience) //  онструктор с параметрами
	{
		this->name = name;
		this->specialization = specialization;
		this->educationLevel = educationLevel;
		this->age = age;
		this->experience = experience;
	}
};



template<class T>
List<T>::List()
{
	Size = 0;//хранение количества элементов в односв€зном списке
	head = nullptr;//указывает на нулевой элемент списка
}

template<class T>
List<T>::~List()
{
	cout << "¬ызвалс€ деструктор" << endl;
	clear();
}
template<class T>
void List<T>::push_back(T data)//добавление элемента в конец списка
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<class T>
void List<T>::pop_front()//метод удалени€
{
	Node<T> *temp = head;//присваиваем temp значение первого элемента в списке

	head = head->pNext;//присваиваем значение следующего элемента
	delete temp;

	Size--;
}

template<class T>
inline void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index) {//поиск элементов в списке
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;	// хранит данные предыдущего элемента в виде указател€ на удал€емый

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;

	}
}
template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

//void fillEngineer(Engineer& engineer);
//void OpenFromFile(List<Engineer>& engineer);
void Print();
//void loadFromFile(Engineer&);