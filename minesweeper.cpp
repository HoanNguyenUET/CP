#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std ;
int **mine = NULL;
bool **open = NULL;
bool lose,win;
int cnt_blank;
int mov[3] = {-1, 0, 1};
void gMap(int &depth, int &width, int &k)
{
     mine = new int*[depth+1];
    for(int i = 0 ; i < depth; i++)
            mine[i] = new int[width+1];
    open = new bool*[depth+1];
    for(int i = 0 ; i < depth; i++)
        open[i] = new bool[width+1];
    for(int i =0 ; i < depth; i++)
        for(int j = 0; j < width; j++) {mine[i][j] = 0; open[i][j] = 0;}

}
void generate_mine(int &depth, int &width, int &k)
{
    cnt_blank = depth * width;
    gMap(depth, width, k);
    srand(time(NULL));
    int x, y, cnt = 0;
    while(cnt < k)
    {
        x = rand() % depth ;
        y = rand() % width ;
        if(mine[x][y] != -1)
        {
        mine[x][y]=-1;
        cnt_blank-- ;
        cnt++;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(x + mov[i] >= 0 && x + mov[i] < depth && y + mov[j] >= 0 && y + mov[j] < width)
                if(mine[x + mov[i]][y + mov[j]] != -1) mine[x + mov[i]][y + mov[j]]++ ;
        }
    }
}
/*
void open0(int x, int y, int &depth, int &width)
{

}*/
void process_n_render(int &depth, int &width, int &k)
{
    /*for(int i =0 ; i < depth; i++)
    {
        for(int j = 0; j < width; j++)
        cout<<mine[i][j]<<' ';
        cout<<endl;
    }*/
    int x , y, cnt_opened=0;
    for(int i = 0; i < depth; i++)
    {
        for(int j = 0; j < width; j++)
        if(open[i][j] == 1) {
            cout << mine[i][j] << ' ';
            cnt_opened++;
        }
        else
        cout<<"_" << ' ';
        cout<<endl;
    }
    if(cnt_opened == cnt_blank)
    {
        win = 1;
        cout<<"You win!";
    }
    if(!win)
    {
    cout << "Open location :";
    cin >> x >> y;
    x--;y--;
    //if(mine[x][y] == 0) open0(x, y, depth, width);else
    open[x][y] = 1;
    if(mine[x][y] == -1)
        {
        system("cls");
        for(int i = 0; i < depth; i++)
            {
            for(int j = 0; j < width; j++)
                if(mine[i][j]==-1) cout<<"*"<<' ';
                else
                    if(open[i][j] == 1)cout<<mine[i][j]<<' '; else cout<<"_"<<' ';
            cout<<endl;
            }
            cout<<"YOU NOOBED YOU LOSED"<<endl;
            lose = 1;
        }
    }
}
int main()
{
    int depth, width, k ;
    cin >> depth>> width >> k;
    generate_mine(depth, width, k);
    while(!lose && !win)
    {
        system("cls");
        process_n_render(depth, width, k);
    }
    return 0;
}
