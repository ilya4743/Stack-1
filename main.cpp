#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>

using namespace std;

struct List //стек
{
	int x;
	List *Next; //указатель на следующий элемент
};
void Make(struct List *MyList)
{
	MyList = NULL;
}
void Push(int x, List **MyList) //Добавление в стек
{
	List *temp = new List;
	temp->x = x;
	temp->Next = *MyList;
	*MyList = temp;
}
int CountElements(List *MyList) //Подсчет количества элементов в стеке
{
	int c = 0;
	while (MyList)
	{
		c++;
		MyList = MyList->Next;
	}
	return c;
}
List * Pop(List *MyList)  //Удаление элемента стека
{
	if (CountElements(MyList) > 0)
	{
		List *temp = MyList->Next;
		delete MyList;
		MyList = temp;
		return MyList;
	}
	else
		cout << "Стек пуст!" << endl;
}

void Show(List *MyList) //Вывод стека
{
	if (CountElements(MyList) > 0)
		while (MyList)
		{
			cout << MyList->x << " ";
			MyList = MyList->Next;
		}
	else
		cout << "Стек пуст!";
}

bool IsEmpty(List *MyList) //Проверка на пустоту
{
	if (MyList == NULL) return false;
	else
		return true;
}

void ClearList(List *MyList)//Удаления стека
{
	while (MyList)
	{
		List *temp = MyList->Next; //Временная переменная для хранения адреса следующего элемента
		delete MyList;
		MyList = temp; //Меняем адрес на следующий
	}
}
List* GetTop(List *MyList) //Получение верхнего элемента стека без его удаления
{
	List *temp = MyList;
	if (temp->Next != NULL)
		return temp->Next;
	else return temp;
}
void FlipFile(List **MyList) //Перевернуть файл
{
	FILE *fp;
	char name1[] = "my.txt";
	char name2[] = "new_my.txt";
	int ch;
	fp = fopen(name1, "r");
	while ((ch = fgetc(fp)) != EOF)
		Push(ch, MyList);
	fclose(fp);
	fp = fopen(name2, "w");
	int c = CountElements(*MyList); List *temp = *MyList;
	while (c != 0)
	{
		fputc((temp)->x, fp);
		temp = GetTop(temp);
		c--;
	}
	fclose(fp);
}

int main()
{
	setlocale(LC_ALL, "rus");
	List *MyList = NULL;
	int O = 0;
	cout << "Меню программы:" << endl;
	cout << "Нажмите 1, чтобы создать стек" << endl;
	cout << "Нажмите 2, чтобы добавить элемент в стек" << endl;
	cout << "Нажмите 3, чтобы удалить элемент стека" << endl;
	cout << "Нажмите 4, чтобы вывести информационные части стека в обратном порядке" << endl;
	cout << "Нажмите 5, чтобы вывести количество элементов в стеке" << endl;
	cout << "Нажмите 6, чтобы проверить стек на пустоту" << endl;
	cout << "Нажмите 7, чтобы перевернуть файл при помощи стека" << endl;
	cout << "Нажмите 8, чтобы удалить стек и все его элементы" << endl;
	cout << "Нажмите 10, чтобы закрыть программу" << endl;
	cout << endl;
	while (O != 10)
	{
		cout << "Введите значение для перехода по меню: ";
		cin >> O;
		switch (O)
		{
		case 1:Make(MyList);
			cout << "Стек создан" << endl;
			break;
		case 2:
			for (int i = 0; i<10; i++)
				Push(i, &MyList);
			cout << "Элементы добавлены в стек" << endl;
			break;
		case 3:MyList = Pop(MyList);
			cout << "Элемент стека удален" << endl;
			break;
		case 4: cout << "Вывод стека в обратном порядке: " << endl;
			Show(MyList);
			cout << endl;
			break;
		case 5:cout << "Количество элементов в стеке: " << CountElements(MyList) << endl;
			break;
		case 6: if (IsEmpty(MyList) == true) cout << "Стек не пустой" << endl;
				else
					cout << "Стек пустой" << endl;
			break;
		case 7:FlipFile(&MyList);
			cout << "Файл my.txt перевернут и записан в my_new.txt" << endl;  break;
		case 8:ClearList(MyList);
			MyList = NULL;
			cout << "Стек удален" << endl;;
			break;
		}
		cout << endl;
	}
	if (!IsEmpty(MyList))
		ClearList(MyList); //Очищаем память.
	return 0;
}
