#include <iostream>  
#include <vector>  
#include <functional>  
using namespace std;

int Cmax, N, Sp, M;
int bikes[505] = { 0 };
int Road[505][505] = { 0 };
bool visited[505] = { false };
vector<int> result;
vector<int> CurrResult;
int CurrWei = 0;
int MinWei = 1 << 30;
int SendBike = 0;
int GetBike = 0;
int MinSendBike = 1 << 30;
int MinGetBike = 1 << 30;



void dfs(int curr)
{
	if (curr == Sp)
	{
		
		SendBike = 0;
		GetBike = 0;
		for (int i = 0; i<CurrResult.size(); i++)
		{
			if (GetBike + bikes[CurrResult[i]] >= Cmax / 2)
			{
				GetBike = GetBike + bikes[CurrResult[i]] - Cmax / 2;
			}
			else
			{
				SendBike += Cmax / 2 - GetBike - bikes[CurrResult[i]];
				GetBike = 0;
			}
		}

		if (MinWei > CurrWei ||
			(MinWei == CurrWei && SendBike < MinSendBike) ||
			(MinWei == CurrWei && MinSendBike == SendBike && MinGetBike > GetBike))
		{
			MinSendBike = SendBike;
			MinGetBike = GetBike;
			result = CurrResult;
			MinWei = CurrWei;
		}
		return;
	}
	int i;
	for (i = 0; i <= N; i++)
	{
		if (curr != i && Road[curr][i] && !visited[i])
		{
			visited[i] = true;
			CurrResult.push_back(i);
			CurrWei += Road[curr][i];
			dfs(i);
			visited[i] = false;
			CurrResult.pop_back();
			CurrWei -= Road[curr][i];
		}
	}
}

int main(void)
{
#ifdef ONLINE_JUDGE  
#else     
	freopen("d:\\1.txt", "r", stdin);
	freopen("d:\\2.txt", "w", stdout);
#endif  

	cin >> Cmax >> N >> Sp >> M;

	int i;
	for (i = 1; i <= N; i++)
	{
		cin >> bikes[i];
	}

	int i1, i2, tmp;
	for (i = 0; i<M; i++)
	{
		cin >> i1 >> i2 >> tmp;
		Road[i1][i2] = tmp;
		Road[i2][i1] = tmp;
	}

	visited[0] = true;
	dfs(0);
	cout << MinSendBike << " 0";
	for (i = 0; i<result.size(); i++)
	{
		cout << "->" << result[i];
	}
	cout << " " << MinGetBike;
	return 0;
}