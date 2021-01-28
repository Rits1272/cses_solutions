#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];

int previousStep[1000][1000];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

bool valid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m && A[x][y] != '#');
}

int main() {
    cin >> n >> m;
    queue<ii> q;
    ii begin, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                begin = {i, j};
            } else if (A[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    q.push(begin);
	A[begin.f][begin.s] = '#';

    while (q.size()) {
        ii u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ii v = {u.f + dx[i], u.s + dy[i]};
            if(!valid(v.f, v.s)){
				continue;
			}
            A[v.f][v.s] = '#';
            previousStep[v.f][v.s] = i;
            q.push(v);
        }
    }

    if (A[end.f][end.s] == '#') {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != begin) {
            int p = previousStep[end.f][end.s];
            steps.push_back(p);
            end = {end.f - dx[p], end.s - dy[p]};
        }
        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (char c : steps) {
            cout << stepDir[c];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
