#include<iostream>
#include<time.h>
using namespace std;
struct position
{
	int position_x = -1;
	int position_y = -1;
};
bool operator ==(position x, position y)
{
	if (x.position_x == y.position_x && x.position_y == y.position_y)
		return true;
	else
		return false;
}
const int N = 10;
char plot[N][N];
bool judge = true;
int score = 0;
char GetRandom(void);
bool Judge(void);
void Print(void);
void Clear(void);
void Drop(void);
void Fill(void);
int Search(position arr[], int i, int get_score);
int main()
{
	cout <<"score:" <<score << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			plot[i][j] = GetRandom();
		}
	}
	Print();
	judge = Judge();
	while (judge)
	{
		Clear();
		Drop();
		Fill();
		system("cls");
		cout <<"score:"<< score << endl;
		Print();
		judge = Judge();
	}
	return 0;
}
void Clear()
{
	int get_score = 0, last = -1;
	position arr[100];
	cin >> arr[0].position_x >> arr[0].position_y;
	if (arr[0].position_x >= 0 && arr[0].position_x <= 9 && arr[0].position_y >= 0 && arr[0].position_y <= 9)
	{
		while (last != get_score)
		{
			last = get_score;
			for (int i = 0; i < 100; i++)
			{
				get_score += Search(arr, i, get_score);
			}
		}
		if (get_score >= 1)
			score += get_score >= 6 ? get_score + 3 + 1 : get_score + 1;
		else
		{
			cout << "wrong answer" << endl;
			system("pause");
			return;
		}
		int k = 0;
		while (arr[k].position_x != -1)
		{
			plot[arr[k].position_x][arr[k].position_y] = '\0';
			k++;
		}
	}
	else
	{
		cout << "please input correct position" << endl;
		Clear();
	}
}
int Search(position arr[100], int i, int get_score)
{
	int add = 0;
	if (arr[i].position_x != -1)
	{
		if (arr[i].position_x - 1 >= 0 && plot[arr[i].position_x - 1][arr[i].position_y] == plot[arr[i].position_x][arr[i].position_y])
		{
			bool judge2 = true;
			position temp;
			temp.position_x = arr[i].position_x - 1;
			temp.position_y = arr[i].position_y;
			for (int j = 0; j < 100; j++)
				if (temp == arr[j])
					judge2 = false;
			if (judge2)
			{
				add++;
				arr[get_score + add].position_x = arr[i].position_x - 1;
				arr[get_score + add].position_y = arr[i].position_y;
			}
		}
		if (arr[i].position_y - 1 >= 0 && plot[arr[i].position_x][arr[i].position_y - 1] == plot[arr[i].position_x][arr[i].position_y])
		{
			bool judge2 = true;
			position temp;
			temp.position_x = arr[i].position_x;
			temp.position_y = arr[i].position_y - 1;
			for (int j = 0; j < 100; j++)
				if (temp == arr[j])
					judge2 = false;
			if (judge2)
			{
				add++;
				arr[get_score + add].position_x = arr[i].position_x;
				arr[get_score + add].position_y = arr[i].position_y - 1;
			}
		}
		if (arr[i].position_x + 1 <= N - 1 && plot[arr[i].position_x + 1][arr[i].position_y] == plot[arr[i].position_x][arr[i].position_y])
		{
			bool judge2 = true;
			position temp;
			temp.position_x = arr[i].position_x + 1;
			temp.position_y = arr[i].position_y;
			for (int j = 0; j < 100; j++)
				if (temp == arr[j])
					judge2 = false;
			if (judge2)
			{
				add++;
				arr[get_score + add].position_x = arr[i].position_x + 1;
				arr[get_score + add].position_y = arr[i].position_y;
			}
		}
		if (arr[i].position_y + 1 <= N - 1 && plot[arr[i].position_x][arr[i].position_y + 1] == plot[arr[i].position_x][arr[i].position_y])
		{
			bool judge2 = true;
			position temp;
			temp.position_x = arr[i].position_x;
			temp.position_y = arr[i].position_y + 1;
			for (int j = 0; j < 100; j++)
				if (temp == arr[j])
					judge2 = false;
			if (judge2)
			{
				add++;
				arr[get_score + add].position_x = arr[i].position_x;
				arr[get_score + add].position_y = arr[i].position_y + 1;
			}
		}
		return add;
	}
	else
		return 0;
}
char GetRandom(void)
{
	int i = (rand() + 1) % 3;
	if (i == 0)
		return 'o';
	else if (i == 1)
		return 'x';
	else
		return '$';
}
void Print(void)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == 0 && j == 0)
				cout << "  ";
			else if (i == 0)
				cout << j-1 << " ";
			else if (j == 0)
				cout << i-1 << " ";
			else
				cout << plot[i-1][j-1] << " ";
		}
		cout << endl;
	}
	return;
}
void Drop(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (plot[j][i] == '\0')
			{
				for (int k = j - 1; k >= 0; k--)
					if (plot[k][i] != '\0')
					{
						plot[j][i] = plot[k][i];
						plot[k][i] = '\0';
						break;
					}
			}
		}
	}
}
void Fill(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (plot[i][j] == '\0')
				plot[i][j] = GetRandom();
		}
}
bool Judge(void)
{
	int same = 0;
	for (int i = 1; i < N - 1; i++)
		for (int j = 1; j < N - 1; j++)
		{
			if (plot[i - 1][j] == plot[i][j])
				same++;
			if (plot[i + 1][j] == plot[i][j])
				same++;
			if (plot[i][j - 1] == plot[i][j])
				same++;
			if (plot[i][j + 1] == plot[i][j])
				same++;
			if (same >= 2)
				return true;
			same = 0;
		}
	for (int i = 1; i < N - 1; i++)
	{
		if (plot[0][i - 1] == plot[0][i])
			same++;
		if (plot[0][i + 1] == plot[0][i])
			same++;
		if (plot[1][i] == plot[0][i])
			same++;
		if (same >= 2)
			return true;
		same = 0;
	}
	for (int i = 1; i < N - 1; i++)
	{
		if (plot[N - 1][i - 1] == plot[N - 1][i])
			same++;
		if (plot[N - 1][i + 1] == plot[N - 1][i])
			same++;
		if (plot[N - 2][i] == plot[N - 1][i])
			same++;
		if (same >= 2)
			return true;
		same = 0;
	}
	for (int j = 1; j < N - 1; j++)
	{
		if (plot[j + 1][0] == plot[j][0])
			same++;
		if (plot[j - 1][0] == plot[j][0])
			same++;
		if (plot[j][1] == plot[j][0])
			same++;
		if (same >= 2)
			return true;
		same = 0;
	}
	for (int j = 1; j < N - 1; j++)
	{
		if (plot[j + 1][N - 1] == plot[j][N - 1])
			same++;
		if (plot[j - 1][N - 1] == plot[j][N - 1])
			same++;
		if (plot[j][N - 2] == plot[j][N - 1])
			same++;
		if (same >= 2)
			return true;
		same = 0;
	}
	same += plot[0][0] == plot[1][0] ? 1 : 0;
	same += plot[0][0] == plot[0][1] ? 1 : 0;
	if (same >= 2)
		return true;
	same = 0;
	same += plot[N - 1][0] == plot[N - 2][0] ? 1 : 0;
	same += plot[N - 1][0] == plot[N - 1][1] ? 1 : 0;
	if (same >= 2)
		return true;
	same = 0;
	same += plot[0][N - 1] == plot[0][N - 2] ? 1 : 0;
	same += plot[0][N - 1] == plot[1][N - 1] ? 1 : 0;
	if (same >= 2)
		return true;
	same = 0;
	same += plot[N - 1][N - 1] == plot[N - 2][N - 1] ? 1 : 0;
	same += plot[N - 1][N - 1] == plot[N - 1][N - 2] ? 1 : 0;
	if (same >= 2)
		return true;
	same = 0;
	return false;
}