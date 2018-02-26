//�Ŷ��� ����������� DFS ��6.8
#include <stdio.h>

char co [8][8];
int go[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int a,b,t;//�Թ���Χ ʱ��Ҫ��
bool success;//�ܷ��߳�
//ȫ��
void DFS(int x,int y,int time)//x,y�ǵ�ǰ����㡱����Ϊ�ݹ���ã����� time�����ʱ��
{//�޷���ֵ ȫ�ֵ�success�������
    //printf("һ��DFS\n");
    int i;
    for(i=0; i<4; i++)
    {
        int nx,ny;
        nx = x + go[i][0];
        ny = y + go[i][1];
        //printf("��һ�����꣺%d %d\n",nx,ny);

        if(nx < 0 || nx > a || ny < 0 || ny > b)
            continue;

        if(co[nx][ny] == 'X') // ��λ����ǽ
           continue;

        if(co[nx][ny] == 'D')//��λ�����յ�
        {
            printf("���յ��ˣ�\n");
            if((time + 1) == t)
            {
                printf("�ҵ��ˣ�\n");
                success = true;
                return;//�ݹ��������
            }
            else continue;//���յ��˵���������· ��Ҫ����
        }
        co[nx][ny] = 'X';//�����λ�ñ�Ϊǽ��
        DFS(nx, ny, time + 1);//�µ�һ�������ݹ� ����DFSʱ ����ı���������״̬һ����ǽ ���λ��������չ �����ٱ�����

        co[nx][ny] = '.';//�ݹ�����λ��״̬�����ͨ�� �Ѿ���nx ny��չ���� �´��µ��������չ���Ծ������λ����

        if(success == true) return;//�б�Ҫ��

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

    //���յ� ������У�����յ���������ż�����߹��Ĳ����ܷ����
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
    //�����
    for(i = 0; i < a; i++)
    {
        for(j = 0;j < b; j++)
        {
            if( (co[i][j] == 'S') && ((i + j)%2 == ((dx + dy)%2 + t%2)%2) )//%2���ᱻ��������Ľ�� �����ü���û����
            //if(co[i][j] == 'S')
            {
                co[i][j] = 'X';//�ҵ���� DFS֮ǰ���õ�ֵΪǽ
                DFS(i,j,0);
            }
        }
    }
    if(success == true) printf("YES\n");
    else printf("NO\n");

    }
    return 0;
}
