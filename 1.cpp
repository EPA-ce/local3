#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int if_init = 0;
void welcome();
struct node
{
	int num;
	node* next;
};
node* Head = NULL;
node* End = NULL;
int stn(string a)
{
	int num = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		num += (a[i] - '0') * pow(10, a.size() - 1 - i);
	}
	return num;
}
void change(int pos, int nums)
{
	node* cur = Head;
	for (int i = 1; i <= pos; i++)
	{
		cur = cur->next;
	}
	cur->num = nums;
}
void add_pos(node* head, int pos, int nums)
{
	node* Node = new node;
	Node->num = nums;
	node* pre = head;
	for (int i = 1; i <= pos; i++)
	{
		pre = pre->next;
	}
	Node->next = pre->next;
	pre->next = Node;
}
void add_head(node* head, int Num)
{
	node* Node = new node;
	Node->num = Num;
	Node->next = head->next;
	head->next = Node;
}
void del(node* head, int num)
{
	node* pre = NULL;
	node* cur = head;
	node* nExt = head->next;
	for (int i = 1; i <= num; i++)
	{
		pre = cur;
		cur = cur->next;
		nExt = nExt->next;
	}
	pre->next = nExt;
	free(cur);
}
node* init()
{
	node* head = new node;
	node* end = new node;
	head->next = end;
	end->next = NULL;
	if_init = 1;
	Head = head;
	End = end;
	return head;
}
void show_nodes(node* head)
{
	node* show = new node;
	show = head->next;
	while (show->next != NULL)
	{
		cout << show->num << ' ';
		show = show->next;
	}
	cout << endl;
}
void show_nodes_num(node* head)
{
	node* show = new node;
	show = head->next;
	int cnt = 1;
	while (show->next != NULL)
	{
		cout << cnt << '.' << show->num << "  ";
		show = show->next;
		cnt++;
	}
	cout << endl;
}
void add_head_user()
{
	if (Head->next == End)cout << "������û�нڵ�" << endl;
	else {
		cout << "�����еĽڵ�Ϊ:" << endl;
		show_nodes(Head);
	}
	string a;
	cout << "������Ҫͷ���Ԫ��" << endl;
	cout << "����q����" << endl;
	while (1)
	{
		cin >> a;
		if (a == "q")return;
		else {
			system("cls");
			add_head(Head, stn(a));
			cout << "���������еĽڵ�Ϊ" << endl;
			show_nodes(Head);
		}
	}
}
void welcome()
{
	while (1)
	{
		system("cls");
		if (if_init == 0)cout << "δ��ʼ��,�޷����в���" << endl;
		else cout << "�ѳ�ʼ��" << endl;
		cout << "1.ͷ�巨����ڵ�" << endl;
		cout << "2.��ʼ��" << endl;
		cout << "3.��ʾ���нڵ�" << endl;
		cout << "4.�˳�" << endl;
		cout << "5.ɾ���ڵ�" << endl;
		cout << "6.��n����ӽڵ�" << endl;
		cout << "7.�޸Ľڵ�����" << endl;
		int a = 0;
		cin >> a;
		if ((a != 2 && a != 4) && if_init == 0)
		{
			cout << "��ʼ����������";
			system("pause");
			continue;
		}
		if (a == 1)add_head_user();
		if (a == 2)
		{
			if (if_init == 1)
			{
				cout << "�ѳ�ʼ������" << endl;
				system("pause");
			}
			else init();
		}
		if (a == 3)
		{
			if (Head->next == End)
			{
				cout << "��Ԫ�أ�" << endl;
				system("pause");
			}
			else
			{
				cout << "���нڵ�Ϊ:" << endl;
				show_nodes_num(Head);
				system("pause");
			}
		}
		if (a == 4)return;
		if (a == 5)
		{
			while (1)
			{
				system("cls");
				if (Head->next == End)
				{
					cout << "��Ԫ�أ�" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "���нڵ�Ϊ:" << endl;
					show_nodes_num(Head);
					cout << "ɾ���ĸ��ڵ㣿" << endl;
					string a;
					cin >> a;
					if (a == "q")break;
					del(Head, stn(a));
				}
			}
		}
		if (a == 6)
		{
			while (1)
			{
				system("cls");
				if (Head->next == End)
				{
					cout << "��Ԫ�أ�" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "���нڵ�Ϊ:" << endl;
					show_nodes_num(Head);
					cout << "�������Ԫ���Լ�λ��" << endl;
					string num, pos;
					cin >> num >> pos;
					if (num == "q" || pos == "q")break;
					add_pos(Head, stn(pos), stn(num));
				}
			}
		}
		if (a == 7)
		{
			while (1)
			{
				system("cls");
				if (Head->next == End)
				{
					cout << "��Ԫ�أ�" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "���нڵ�Ϊ:" << endl;
					show_nodes_num(Head);
					cout << "������Ҫ�޸�Ԫ�ص�����Լ��޸ĺ��ֵ" << endl;
					string pos, num;
					cin >> pos >> num;
					if (pos == "q" || num == "q")break;
					change(stn(pos), stn(num));
				}
			}
		}
	}
}
int main()
{
	welcome();
	return 0;
}
