#include <stdio.h>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int nfiled[11][11];
int nvisit[11][11];
int n, nRet;
int check;

int dirx[] = { 0, 0, 1, -1 };
int diry[] = { 1, -1, 0, 0 };


int visit_check(int posx, int posy, int flag)
{
	int next_posx = 0;
	int next_posy = 0;
	
	if (flag)
	{
		for (int i = 0; i < 4; i++)
		{
			next_posx = posx + dirx[i];
			next_posy = posy + diry[i];

			if (nvisit[next_posy][next_posx]){
				return -1;
			}
		}
	}
	int cur_money = nfiled[posy][posx];

	nvisit[posy][posx] = flag; // ¾¾¾Ñ Ç¥½Ã
	for (int i = 0; i < 4; i++)
	{
		next_posx = posx + dirx[i];
		next_posy = posy + diry[i];

		nvisit[next_posy][next_posx] = flag;
		cur_money += nfiled[next_posy][next_posx];
	}
	return cur_money;
}



void dfs(int x, int y, int cnt, int money)
{
	if (cnt == 3)
	{
		nRet = min(nRet, money);
		return;
	}

	for (int i = y; i < n - 1; i++){
		for (int j = 1; j < n - 1; j++){ // 1ºÎÅÍ ½ÃÀÛ
			
			check = visit_check(j, i, 1);

			if (check != -1)
			{
				check += money;
				if (j == n - 2)
					dfs(1, i + 1, cnt + 1, check);
				else
					dfs(j + 1, i, cnt + 1, check);

				visit_check(j, i, 0);
			}
		}
	}
}


int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &nfiled[i][j]);
			nvisit[i][j] = 0;
		}
	}
	nRet = 987654321;
	dfs(1, 1, 0, 0);

	printf("%d\n", nRet);

	return 0;
}