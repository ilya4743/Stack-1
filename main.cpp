#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>

using namespace std;

struct List //����
{
	int x;
	List *Next; //��������� �� ��������� �������
};
void Make(struct List *MyList)
{
	MyList = NULL;
}
void Push(int x, List **MyList) //���������� � ����
{
	List *temp = new List;
	temp->x = x;
	temp->Next = *MyList;
	*MyList = temp;
}
int CountElements(List *MyList) //������� ���������� ��������� � �����
{
	int c = 0;
	while (MyList)
	{
		c++;
		MyList = MyList->Next;
	}
	return c;
}
List * Pop(List *MyList)  //�������� �������� �����
{
	if (CountElements(MyList) > 0)
	{
		List *temp = MyList->Next;
		delete MyList;
		MyList = temp;
		return MyList;
	}
	else
		cout << "���� ����!" << endl;
}

void Show(List *MyList) //����� �����
{
	if (CountElements(MyList) > 0)
		while (MyList)
		{
			cout << MyList->x << " ";
			MyList = MyList->Next;
		}
	else
		cout << "���� ����!";
}

bool IsEmpty(List *MyList) //�������� �� �������
{
	if (MyList == NULL) return false;
	else
		return true;
}

void ClearList(List *MyList)//�������� �����
{
	while (MyList)
	{
		List *temp = MyList->Next; //��������� ���������� ��� �������� ������ ���������� ��������
		delete MyList;
		MyList = temp; //������ ����� �� ���������
	}
}
List* GetTop(List *MyList) //��������� �������� �������� ����� ��� ��� ��������
{
	List *temp = MyList;
	if (temp->Next != NULL)
		return temp->Next;
	else return temp;
}
void FlipFile(List **MyList) //����������� ����
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
	cout << "���� ���������:" << endl;
	cout << "������� 1, ����� ������� ����" << endl;
	cout << "������� 2, ����� �������� ������� � ����" << endl;
	cout << "������� 3, ����� ������� ������� �����" << endl;
	cout << "������� 4, ����� ������� �������������� ����� ����� � �������� �������" << endl;
	cout << "������� 5, ����� ������� ���������� ��������� � �����" << endl;
	cout << "������� 6, ����� ��������� ���� �� �������" << endl;
	cout << "������� 7, ����� ����������� ���� ��� ������ �����" << endl;
	cout << "������� 8, ����� ������� ���� � ��� ��� ��������" << endl;
	cout << "������� 10, ����� ������� ���������" << endl;
	cout << endl;
	while (O != 10)
	{
		cout << "������� �������� ��� �������� �� ����: ";
		cin >> O;
		switch (O)
		{
		case 1:Make(MyList);
			cout << "���� ������" << endl;
			break;
		case 2:
			for (int i = 0; i<10; i++)
				Push(i, &MyList);
			cout << "�������� ��������� � ����" << endl;
			break;
		case 3:MyList = Pop(MyList);
			cout << "������� ����� ������" << endl;
			break;
		case 4: cout << "����� ����� � �������� �������: " << endl;
			Show(MyList);
			cout << endl;
			break;
		case 5:cout << "���������� ��������� � �����: " << CountElements(MyList) << endl;
			break;
		case 6: if (IsEmpty(MyList) == true) cout << "���� �� ������" << endl;
				else
					cout << "���� ������" << endl;
			break;
		case 7:FlipFile(&MyList);
			cout << "���� my.txt ���������� � ������� � my_new.txt" << endl;  break;
		case 8:ClearList(MyList);
			MyList = NULL;
			cout << "���� ������" << endl;;
			break;
		}
		cout << endl;
	}
	if (!IsEmpty(MyList))
		ClearList(MyList); //������� ������.
	return 0;
}
