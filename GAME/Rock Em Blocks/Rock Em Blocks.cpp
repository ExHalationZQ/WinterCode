#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;
using namespace std::chrono;
struct position
{
	int position_x = -1;
	int position_y = -1;
};
const int N = 10;
char plot[N][N];
bool judge = true;
int score = 0;
int tool1 = 0, tool2 = 0;
char GetRandom(void);
bool Judge(void);
void Print(void);
void Clear(int swh);
void Drop(void);
void Fill(void);
int Search(position arr[100], int i, int get_score);
void Tools(void);
bool operator==(position x, position y)
{
	if (x.position_x == y.position_x && x.position_y == y.position_y)
		return true;
	else
		return false;
}
void pause()
{
	std::this_thread::sleep_for(seconds(180));
	system("cls");
	cout << "timeout" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << '\a';
		Sleep(1000);
	}
	system("pause");
}
int main()
{
	//std::thread thread(pause);
	cout << "score:" << score << endl;
	cout << "输入坐标或输入10使用道具" << endl;
	cout << "单次消除6个及以上送道具2一个，单次消除8个及以上送道具1一个" << endl;
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
		int swh = 0;
		cin >> swh;
		if (swh >= 0 && swh <= 9)
			Clear(swh);
		else
			Tools();
		Drop();
		Fill();
		system("cls");
		cout << "score:" << score << endl;
		cout << "输入坐标或输入10使用道具" << endl;
		Print();
		judge = Judge();
	}
	return 0;
}
void Clear(int swh)
{
	int get_score = 0, last = -1;
	position arr[100];
	arr[0].position_x = swh;
	cin >> arr[0].position_y;
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
		{
			score += get_score >= 6 ? get_score + 3 + 1 : get_score + 1;
			if (get_score >= 5)
				tool2++;
			if (get_score >= 7)
				tool1++;
		}
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
		Clear(swh);
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
				cout << j - 1 << " ";
			else if (j == 0)
				cout << i - 1 << " ";
			else
				cout << plot[i - 1][j - 1] << " ";
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
void Tools(void)
{
	cout << "按1消除全部某色块，按2消除某列，按3消除某行,2、3共用道具2个数" << endl;
	cout << "道具1剩余:" << tool1 << "道具2剩余:"<<tool2 << endl;
	int choose, get_score = 0;
	cin >> choose;
	if (choose == 1)
	{
		if (tool1 >= 1)
		{
			char clear;
			cin >> clear;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					if (plot[i][j] == clear)
					{
						plot[i][j] = '\0';
						get_score++;
					}
				}
			score += get_score;
			tool1--;
			return;
		}
		else
		{
			cout << "no tool1 left"<<endl;
			system("pause");
			return;
		}
	}
	else if (choose == 2)
	{
		if (tool2 >= 1)
		{
			int column;
			cin >> column;
			for (int i = 0; i < N; i++)
				plot[i][column] = '\0';
			get_score += 10;
			score += get_score;
			tool2--;
			return;
		}
		else
		{
			cout << "no tool2 left" << endl;
			system("pause");
			return;
		}
	}
	else if (choose == 3)
	{
		if(tool2>=1)
		{
			int line;
			cin >> line;
			for (int i = 0; i < N; i++)
				plot[line][i] = '\0';
			get_score += 10;
			score += get_score;
			tool2--;
			return;
		}
		else 
		{
			cout << "no tool2 left" << endl;
			system("pause");
			return;
		}
	}
}
