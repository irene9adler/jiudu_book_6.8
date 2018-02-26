//九度书 深度优先搜索 DFS 例6.8
#include <stdio.h>

char co [8][8];
int go[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int a,b,t;//迷宫范围 时间要求
bool success;//能否走出
//全局
void DFS(int x,int y,int time)//x,y是当前“起点”（因为递归调用）坐标 time是起点时间
{//无返回值 全局的success决定结果
    //printf("一次DFS\n");
    int i;
    for(i=0; i<4; i++)
    {
        int nx,ny;
        nx = x + go[i][0];
        ny = y + go[i][1];
        //printf("下一点坐标：%d %d\n",nx,ny);

        if(nx < 0 || nx > a || ny < 0 || ny > b)
            continue;

        if(co[nx][ny] == 'X') // 该位置是墙
           continue;

        if(co[nx][ny] == 'D')//该位置是终点
        {
            printf("到终点了！\n");
            if((time + 1) == t)
            {
                printf("找到了！\n");
                success = true;
                return;//递归结束条件
            }
            else continue;//到终点了但不是这条路 还要继续
        }
        co[nx][ny] = 'X';//将这个位置变为墙？
        DFS(nx, ny, time + 1);//下第一点做起点递归 调用DFS时 传入的本次起点参数状态一定是墙 这个位置往下扩展 不能再被经过

        co[nx][ny] = '.';//递归后将这个位置状态变回普通？ 已经用nx ny扩展过了 下次新的起点做扩展可以经过这个位置了

        if(success == true) return;//有必要？

    }
}

int main()
{
    while(scanf("%d%d%d",&a,&b,&t)!=EOF){
    if( a == 0 && b == 0 && t == 0)
       break;

    int i,j;
    success = false;

    /*for(i = 0; i < a; i++)
    {
        for(j = 0;j < b; j++)
        {
            scanf("%c",&co[i][j]);
        }
    }*/
    for(i=0;i<a;i++)
        scanf("%s",co[i]);

    for(i = 0; i < a; i++)
    {
        for(j = 0;j < b; j++)
        {
            printf("%c ",co[i][j]);
        }
        printf("\n");
    }

    //找终点 作用是校验起终点坐标差的奇偶性与走过的步数能否对上
    int dx,dy;
    for(i = 0; i < a; i++)
    {
        for(j = 0;j < b; j++)
        {
            if(co[i][j] == 'D')
            {
                dx = i;
                dy = j;
                break;
            }
        }
    }
    //找起点
    for(i = 0; i < a; i++)
    {
        for(j = 0;j < b; j++)
        {
            if( (co[i][j] == 'S') && ((i + j)%2 == ((dx + dy)%2 + t%2)%2) )//%2不会被处理成正的结果 所以用减号没进来
            //if(co[i][j] == 'S')
            {
                co[i][j] = 'X';//找到起点 DFS之前将该点值为墙
                DFS(i,j,0);
            }
        }
    }
    if(success == true) printf("YES\n");
    else printf("NO\n");

    }
    return 0;
}
