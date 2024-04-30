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
	if (Head->next == End)cout << "链表中没有节点" << endl;
	else {
		cout << "链表中的节点为:" << endl;
		show_nodes(Head);
	}
	string a;
	cout << "输入需要头插的元素" << endl;
	cout << "输入q结束" << endl;
	while (1)
	{
		cin >> a;
		if (a == "q")return;
		else {
			system("cls");
			add_head(Head, stn(a));
			cout << "现在链表中的节点为" << endl;
			show_nodes(Head);
		}
	}
}
void welcome()
{
	while (1)
	{
		system("cls");
		if (if_init == 0)cout << "未初始化,无法进行操作" << endl;
		else cout << "已初始化" << endl;
		cout << "1.头插法插入节点" << endl;
		cout << "2.初始化" << endl;
		cout << "3.显示所有节点" << endl;
		cout << "4.退出" << endl;
		cout << "5.删除节点" << endl;
		cout << "6.在n后添加节点" << endl;
		cout << "7.修改节点数据" << endl;
		int a = 0;
		cin >> a;
		if ((a != 2 && a != 4) && if_init == 0)
		{
			cout << "初始化！！！！";
			system("pause");
			continue;
		}
		if (a == 1)add_head_user();
		if (a == 2)
		{
			if (if_init == 1)
			{
				cout << "已初始化过！" << endl;
				system("pause");
			}
			else init();
		}
		if (a == 3)
		{
			if (Head->next == End)
			{
				cout << "无元素！" << endl;
				system("pause");
			}
			else
			{
				cout << "现有节点为:" << endl;
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
					cout << "无元素！" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "现有节点为:" << endl;
					show_nodes_num(Head);
					cout << "删除哪个节点？" << endl;
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
					cout << "无元素！" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "现有节点为:" << endl;
					show_nodes_num(Head);
					cout << "输入插入元素以及位置" << endl;
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
					cout << "无元素！" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "现有节点为:" << endl;
					show_nodes_num(Head);
					cout << "输入需要修改元素的序号以及修改后的值" << endl;
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
