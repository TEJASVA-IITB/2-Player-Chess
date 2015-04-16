#include<simplecpp>
int getI(int y)
{
    int i=8;
    if(y>117.5&&y<182.5)i=1;
    if(y>182.5&&y<247.5)i=2;
    if(y>247.5&&y<312.5)i=3;
    if(y>312.5&&y<377.5)i=4;
    if(y>377.5&&y<442.5)i=5;
    if(y>442.5&&y<507.5)i=6;
    if(y>507.5&&y<572.5)i=7;
    if(y>572.5&&y<637.5)i=8;
    return i;
}
int getJ(int x)
{
    int j=8;
    if(x>132.5&&x<197.5)j=1;
    if(x>197.5&&x<262.5)j=2;
    if(x>262.5&&x<327.5)j=3;
    if(x>327.5&&x<392.5)j=4;
    if(x>392.5&&x<457.5)j=5;
    if(x>457.5&&x<522.5)j=6;
    if(x>522.5&&x<587.5)j=7;
    if(x>587.5&&x<652.5)j=8;
    return j;
}
int check(int x,int y,char list[10][10],int type)
{
    int i=0;
    int j;
    //Pawn
    if(type==2)
    {
        if(list[x][y]!='_')
        {
            if(list[x+1][y-1]=='P')i++;
            if(list[x+1][y+1]=='P')i++;
        }
        if(list[x][y]=='_')
        {
            if(list[x+1][y]=='P')i++;
            if(list[x+2][y]=='P'&&x==5)i++;
        }
    }
    if(type==1)
    {
        if(list[x+1][y-1]=='P')i++;
        if(list[x+1][y+1]=='P')i++;
    }
    //King
    if(type==1)
    {
        if(list[x+1][y+1]=='K'||list[x+1][y]=='K'||list[x+1][y-1]=='K'||list[x][y-1]=='K'||list[x-1][y-1]=='K'||list[x-1][y]=='K'||list[x-1][y+1]=='K'||list[x][y+1]=='K')
            i++;
    }
    //Elephant & Queen
    for(j=1;; j++)
    {
        if(list[x+j][y]=='E'||list[x+j][y]=='Q')
            i++;
        if(list[x+j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y]=='E'||list[x-j][y]=='Q')
            i++;
        if(list[x-j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y+j]=='E'||list[x][y+j]=='Q')
            i++;
        if(list[x][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y-j]=='E'||list[x][y-j]=='Q')
            i++;
        if(list[x][y-j]!='_')
            break;
    }
    /*Camel and Queen*/
    for(j=1;; j++)
    {
        if(list[x+j][y+j]=='C'||list[x+j][y+j]=='Q')
            i++;
        if(list[x+j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y+j]=='C'||list[x-j][y+j]=='Q')
            i++;
        if(list[x-j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x+j][y-j]=='C'||list[x+j][y-j]=='Q')
            i++;
        if(list[x+j][y-j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y-j]=='C'||list[x-j][y-j]=='Q')
            i++;
        if(list[x-j][y-j]!='_')
            break;
    }
    //Horse
    if(list[x-2][y-1]=='H')i++;
    if(list[x-2][y+1]=='H')i++;
    if(list[x-1][y+2]=='H')i++;
    if(list[x+1][y+2]=='H')i++;
    if(list[x+2][y+1]=='H')i++;
    if(list[x+2][y-1]=='H')i++;
    if(list[x+1][y-2]=='H')i++;
    if(list[x-1][y-2]=='H')i++;
    return i;
}
//For Second Player
int CHECK(int x,int y,char list[10][10],int type)
{
    int i=0;
    int j;
    //Pawn
    if(type==2)
    {
        if(list[x][y]!='_')
        {
            if(list[x-1][y-1]=='p')i++;
            if(list[x-1][y+1]=='p')i++;
        }
        if(list[x][y]=='_')
        {
            if(list[x-1][y]=='p')i++;
            if(list[x-2][y]=='p'&&x==4)i++;
        }
    }
    if(type==1)
    {
        if(list[x-1][y-1]=='p')i++;
        if(list[x-1][y+1]=='p')i++;
    }
    //King
    if(type==1)
    {
        if(list[x+1][y+1]=='k'||list[x+1][y]=='k'||list[x+1][y-1]=='k'||list[x][y-1]=='k'||list[x-1][y-1]=='k'||list[x-1][y]=='k'||list[x-1][y+1]=='k'||list[x][y+1]=='k')
            i++;
    }
    //Elephant & Queen
    for(j=1;; j++)
    {
        if(list[x+j][y]=='e'||list[x+j][y]=='q')
            i++;
        if(list[x+j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y]=='e'||list[x-j][y]=='q')
            i++;
        if(list[x-j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y+j]=='e'||list[x][y+j]=='q')
            i++;
        if(list[x][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y-j]=='e'||list[x][y-j]=='q')
            i++;
        if(list[x][y-j]!='_')
            break;
    }
    /*Camel and Queen*/
    for(j=1;; j++)
    {
        if(list[x+j][y+j]=='c'||list[x+j][y+j]=='q')
            i++;
        if(list[x+j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y+j]=='c'||list[x-j][y+j]=='q')
            i++;
        if(list[x-j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x+j][y-j]=='c'||list[x+j][y-j]=='q')
            i++;
        if(list[x+j][y-j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y-j]=='c'||list[x-j][y-j]=='q')
            i++;
        if(list[x-j][y-j]!='_')
            break;
    }
    //Horse
    if(list[x-2][y-1]=='h')i++;
    if(list[x-2][y+1]=='h')i++;
    if(list[x-1][y+2]=='h')i++;
    if(list[x+1][y+2]=='h')i++;
    if(list[x+2][y+1]=='h')i++;
    if(list[x+2][y-1]=='h')i++;
    if(list[x+1][y-2]=='h')i++;
    if(list[x-1][y-2]=='h')i++;
    return i;
}
int attackerx(int x,int y,char list[10][10])
{
    int i=9;
    int j;
    //Elephant & Queen
    for(j=1;; j++)
    {
        if(list[x+j][y]=='E'||list[x+j][y]=='Q')
            i=x+j;
        if(list[x+j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y]=='E'||list[x-j][y]=='Q')
            i=x-j;
        if(list[x-j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y+j]=='E'||list[x][y+j]=='Q')
            i=x;
        if(list[x][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y-j]=='E'||list[x][y-j]=='Q')
            i=x;
        if(list[x][y-j]!='_')
            break;
    }
    /*Camel and Queen*/
    for(j=1;; j++)
    {
        if(list[x+j][y+j]=='C'||list[x+j][y+j]=='Q')
            i=x+j;
        if(list[x+j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y+j]=='C'||list[x-j][y+j]=='Q')
            i=x-j;
        if(list[x-j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x+j][y-j]=='C'||list[x+j][y-j]=='Q')
            i=x+j;
        if(list[x+j][y-j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y-j]=='C'||list[x-j][y-j]=='Q')
            i=x-j;
        if(list[x-j][y-j]!='_')
            break;
    }
    return i;
}
int ATTACKERX(int x,int y,char list[10][10])
{
    int i=9;
    int j;
    //Elephant & Queen
    for(j=1;; j++)
    {
        if(list[x+j][y]=='e'||list[x+j][y]=='q')
            i=x+j;
        if(list[x+j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y]=='e'||list[x-j][y]=='q')
            i=x-j;
        if(list[x-j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y+j]=='e'||list[x][y+j]=='q')
            i=x;
        if(list[x][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y-j]=='e'||list[x][y-j]=='q')
            i=x;
        if(list[x][y-j]!='_')
            break;
    }
    /*Camel and Queen*/
    for(j=1;; j++)
    {
        if(list[x+j][y+j]=='c'||list[x+j][y+j]=='q')
            i=x+j;
        if(list[x+j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y+j]=='c'||list[x-j][y+j]=='q')
            i=x-j;
        if(list[x-j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x+j][y-j]=='c'||list[x+j][y-j]=='q')
            i=x+j;
        if(list[x+j][y-j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y-j]=='c'||list[x-j][y-j]=='q')
            i=x-j;
        if(list[x-j][y-j]!='_')
            break;
    }
    return i;
}
int attackery(int x,int y,char list[10][10])
{
    int i=9;
    int j;
    //Elephant & Queen
    for(j=1;; j++)
    {
        if(list[x+j][y]=='E'||list[x+j][y]=='Q')
            i=y;
        if(list[x+j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y]=='E'||list[x-j][y]=='Q')
            i=y;
        if(list[x-j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y+j]=='E'||list[x][y+j]=='Q')
            i=y+j;
        if(list[x][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y-j]=='E'||list[x][y-j]=='Q')
            i=y-j;
        if(list[x][y-j]!='_')
            break;
    }
    /*Camel and Queen*/
    for(j=1;; j++)
    {
        if(list[x+j][y+j]=='C'||list[x+j][y+j]=='Q')
            i=y+j;
        if(list[x+j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y+j]=='C'||list[x-j][y+j]=='Q')
            i=y+j;
        if(list[x-j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x+j][y-j]=='C'||list[x+j][y-j]=='Q')
            i=y-j;
        if(list[x+j][y-j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y-j]=='C'||list[x-j][y-j]=='Q')
            i=y-j;
        if(list[x-j][y-j]!='_')
            break;
    }
    return i;
}
int ATTACKERY(int x,int y,char list[10][10])
{
    int i=9;
    int j;
    //Elephant & Queen
    for(j=1;; j++)
    {
        if(list[x+j][y]=='e'||list[x+j][y]=='q')
            i=y;
        if(list[x+j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y]=='e'||list[x-j][y]=='q')
            i=y;
        if(list[x-j][y]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y+j]=='e'||list[x][y+j]=='q')
            i=y+j;
        if(list[x][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x][y-j]=='e'||list[x][y-j]=='q')
            i=y-j;
        if(list[x][y-j]!='_')
            break;
    }
    /*Camel and Queen*/
    for(j=1;; j++)
    {
        if(list[x+j][y+j]=='c'||list[x+j][y+j]=='q')
            i=y+j;
        if(list[x+j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y+j]=='c'||list[x-j][y+j]=='q')
            i=y+j;
        if(list[x-j][y+j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x+j][y-j]=='c'||list[x+j][y-j]=='q')
            i=y-j;
        if(list[x+j][y-j]!='_')
            break;
    }
    for(j=1;; j++)
    {
        if(list[x-j][y-j]=='c'||list[x-j][y-j]=='q')
            i=y-j;
        if(list[x-j][y-j]!='_')
            break;
    }
    return i;
}
int pathblock(int kx,int ky,int atx,int aty,char a[10][10])
{
    int i=0;
    int pb=0;
    //Elephant & Queen
    if(a[atx][aty]=='Q'||a[atx][aty]=='E')
    {
        if(atx<kx&&aty==ky)
        {
            for(i=1; kx-i>=atx; i++)
                if(CHECK(kx-i,ky,a,2)>0)
                    pb++;
        }
        if(atx>kx&&aty==ky)
        {
            for(i=1; kx+i<=atx; i++)
                if(CHECK(kx+i,ky,a,2)>0)
                    pb++;

        }
        if(atx==kx&&aty>ky)
        {
            for(i=1; ky+i<=aty; i++)
                if(CHECK(kx,ky+i,a,2)>0)
                    pb++;
        }
        if(atx==kx&&aty<ky)
        {
            for(i=1; ky-i>=aty; i++)
                if(CHECK(kx,ky-i,a,2)>0)
                    pb++;
        }
    }
    //Camel  & Queen
    if(a[atx][aty]=='Q'||a[atx][aty]=='C')
    {
        if(atx<kx&&aty<ky)
        {
            for(i=1; kx-i>=atx&&ky-i>=aty; i++)
                if(CHECK(kx-i,ky-i,a,2)>0)
                    pb++;
        }
        if(atx>kx&&aty>ky)
        {
            for(i=1; kx+i<=atx&&ky+i<=aty; i++)
                if(CHECK(kx+i,ky+i,a,2)>0)
                    pb++;
        }
        if(atx<kx&&aty>ky)
        {
            for(i=1; ky+i<=aty&&kx-i>=atx; i++)
                if(CHECK(kx-i,ky+i,a,2)>0)
                    pb++;
        }
        if(atx>kx&&aty<ky)
        {
            for(i=1; ky-i>=aty&&kx+i<=atx; i++)
                if(CHECK(kx+i,ky-i,a,2)>0)
                    pb++;
        }
    }
    cout<<"pb="<<pb;
    return pb;
}
int PATHBLOCK(int kx,int ky,int atx,int aty,char a[10][10])
{
    int i=0;
    int pb=0;
    //Elephant & Queen
    if(a[atx][aty]=='q'||a[atx][aty]=='e')
    {
        if(atx<kx&&aty==ky)
        {
            for(i=1; kx-i>=atx; i++)
                if(check(kx-i,ky,a,2)>0)
                    pb++;
        }
        if(atx>kx&&aty==ky)
        {
            for(i=1; kx+i<=atx; i++)
                if(check(kx+i,ky,a,2)>0)
                    pb++;

        }
        if(atx==kx&&aty>ky)
        {
            for(i=1; ky+i<=aty; i++)
                if(check(kx,ky+i,a,2)>0)
                    pb++;
        }
        if(atx==kx&&aty<ky)
        {
            for(i=1; ky-i>=aty; i++)
                if(check(kx,ky-i,a,2)>0)
                    pb++;
        }
    }
    //Camel  & Queen
    if(a[atx][aty]=='q'||a[atx][aty]=='c')
    {
        if(atx<kx&&aty<ky)
        {
            for(i=1; kx-i>=atx&&ky-i>=aty; i++)
                if(check(kx-i,ky-i,a,2)>0)
                    pb++;
        }
        if(atx>kx&&aty>ky)
        {
            for(i=1; kx+i<=atx&&ky+i<=aty; i++)
                if(check(kx+i,ky+i,a,2)>0)
                    pb++;
        }
        if(atx<kx&&aty>ky)
        {
            for(i=1; ky+i<=aty&&kx-i>=atx; i++)
                if(check(kx-i,ky+i,a,2)>0)
                    pb++;
        }
        if(atx>kx&&aty<ky)
        {
            for(i=1; ky-i>=aty&&kx+i<=atx; i++)
                if(check(kx+i,ky-i,a,2)>0)
                    pb++;
        }
    }
    cout<<"pb="<<pb;
    return pb;
}
bool checkmate(int kx,int ky,int atx,int aty,char arr[10][10],int chk)
{
    bool checkmte=false;
    int i=0;
    arr[kx][ky]='_';
    if(arr[kx][ky+1]!='*')
    {
        if(check(kx,ky+1,arr,1)>0||arr[kx][ky+1]=='p'||arr[kx][ky+1]=='c'||arr[kx][ky+1]=='e'||arr[kx][ky+1]=='h'||arr[kx][ky+1]=='q')
            i++;
    }
    else i++;
    if(arr[kx+1][ky+1]!='*')
    {
        if(check(kx+1,ky+1,arr,1)>0||arr[kx+1][ky+1]=='p'||arr[kx+1][ky+1]=='c'||arr[kx+1][ky+1]=='e'||arr[kx+1][ky+1]=='h'||arr[kx+1][ky+1]=='q')
            i++;
    }
    else i++;
    if(arr[kx+1][ky]!='*')
    {
        if(check(kx+1,ky,arr,1)>0||arr[kx+1][ky]=='p'||arr[kx+1][ky]=='c'||arr[kx+1][ky]=='e'||arr[kx+1][ky]=='h'||arr[kx+1][ky]=='q')
            i++;
    }
    else i++;
    if(arr[kx+1][ky-1]!='*')
    {
        if(check(kx+1,ky-1,arr,1)>0||arr[kx+1][ky-1]=='p'||arr[kx+1][ky-1]=='c'||arr[kx+1][ky-1]=='e'||arr[kx+1][ky-1]=='h'||arr[kx+1][ky-1]=='q')
            i++;
    }
    else i++;
    if(arr[kx][ky-1]!='*')
    {
        if(check(kx,ky-1,arr,1)>0||arr[kx][ky-1]=='p'||arr[kx][ky-1]=='c'||arr[kx][ky-1]=='e'||arr[kx][ky-1]=='h'||arr[kx][ky-1]=='q')
            i++;
    }
    else i++;
    if(arr[kx-1][ky-1]!='*')
    {
        if(check(kx-1,ky-1,arr,1)>0||arr[kx-1][ky-1]=='p'||arr[kx-1][ky-1]=='c'||arr[kx-1][ky-1]=='e'||arr[kx-1][ky-1]=='h'||arr[kx-1][ky-1]=='q')
            i++;
    }
    else i++;
    if(arr[kx-1][ky]!='*')
    {
        if(check(kx-1,ky,arr,1)>0||arr[kx-1][ky]=='p'||arr[kx-1][ky]=='c'||arr[kx-1][ky]=='e'||arr[kx-1][ky]=='h'||arr[kx-1][ky]=='q')
            i++;
    }
    else i++;
    if(arr[kx-1][ky+1]!='*')
    {
        if(check(kx-1,ky+1,arr,1)>0||arr[kx-1][ky+1]=='p'||arr[kx-1][ky+1]=='c'||arr[kx-1][ky+1]=='e'||arr[kx-1][ky+1]=='h'||arr[kx-1][ky+1]=='q')
            i++;
    }
    else i++;
    cout<<"i="<<i;
    arr[kx][ky]='k';
    if(chk>1&&i==8)checkmte=true;
    if(chk==1&&i==8&&pathblock(kx,ky,atx,aty,arr)==0)checkmte=true;
    return checkmte;
}
bool CHECKMATE(int kx,int ky,int atx,int aty,char arr[10][10],int chk)
{
    bool checkmte=false;
    int i=0;
    arr[kx][ky]='_';
    if(arr[kx][ky+1]!='*')
    {
        if(CHECK(kx,ky+1,arr,1)>0||arr[kx][ky+1]=='P'||arr[kx][ky+1]=='C'||arr[kx][ky+1]=='E'||arr[kx][ky+1]=='H'||arr[kx][ky+1]=='Q')
            i++;
    }
    else i++;
    if(arr[kx+1][ky+1]!='*')
    {
        if(CHECK(kx+1,ky+1,arr,1)>0||arr[kx+1][ky+1]=='P'||arr[kx+1][ky+1]=='C'||arr[kx+1][ky+1]=='E'||arr[kx+1][ky+1]=='H'||arr[kx+1][ky+1]=='Q')
            i++;
    }
    else i++;
    if(arr[kx+1][ky]!='*')
    {
        if(CHECK(kx+1,ky,arr,1)>0||arr[kx+1][ky]=='P'||arr[kx+1][ky]=='C'||arr[kx+1][ky]=='E'||arr[kx+1][ky]=='H'||arr[kx+1][ky]=='Q')
            i++;
    }
    else i++;
    if(arr[kx+1][ky-1]!='*')
    {
        if(CHECK(kx+1,ky-1,arr,1)>0||arr[kx+1][ky-1]=='P'||arr[kx+1][ky-1]=='C'||arr[kx+1][ky-1]=='E'||arr[kx+1][ky-1]=='H'||arr[kx+1][ky-1]=='Q')
            i++;
    }
    else i++;
    if(arr[kx][ky-1]!='*')
    {
        if(CHECK(kx,ky-1,arr,1)>0||arr[kx][ky-1]=='P'||arr[kx][ky-1]=='C'||arr[kx][ky-1]=='E'||arr[kx][ky-1]=='H'||arr[kx][ky-1]=='Q')
            i++;
    }
    else i++;
    if(arr[kx-1][ky-1]!='*')
    {
        if(CHECK(kx-1,ky-1,arr,1)>0||arr[kx-1][ky-1]=='P'||arr[kx-1][ky-1]=='C'||arr[kx-1][ky-1]=='E'||arr[kx-1][ky-1]=='H'||arr[kx-1][ky-1]=='Q')
            i++;
    }
    else i++;
    if(arr[kx-1][ky]!='*')
    {
        if(CHECK(kx-1,ky,arr,1)>0||arr[kx-1][ky]=='P'||arr[kx-1][ky]=='C'||arr[kx-1][ky]=='E'||arr[kx-1][ky]=='H'||arr[kx-1][ky]=='Q')
            i++;
    }
    else i++;
    if(arr[kx-1][ky+1]!='*')
    {
        if(CHECK(kx-1,ky+1,arr,1)>0||arr[kx-1][ky+1]=='P'||arr[kx-1][ky+1]=='C'||arr[kx-1][ky+1]=='E'||arr[kx-1][ky+1]=='H'||arr[kx-1][ky+1]=='Q')
            i++;
    }
    else i++;
    cout<<"i="<<i;
    arr[kx][ky]='K';
    if(chk>1&&i==8)checkmte=true;
    if(chk==1&&i==8&&PATHBLOCK(kx,ky,atx,aty,arr)==0)checkmte=true;
    return checkmte;
}
main_program
{
    initCanvas("Chess-The Game",1000,1000);
    beginFrame();
    Rectangle b(100,150,65,65);
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            b.move(65,0);
            b.setColor(COLOR("yellow"));
            if((i+j)%2==0)
            {
                b.setColor(COLOR(200,200,200));
                b.setFill(1);
            }
            else b.setFill(1);
            b.imprint();
        }
        if(i!=7) b.moveTo(100,215+65*i);
    }
//pawn1
    Circle p1_1(165,203.83,10);
    p1_1.setColor(COLOR("white"));
    p1_1.setFill(1);
    Rectangle p1_2(165,225.16,10,20);
    p1_2.setColor(COLOR("white"));
    p1_2.setFill(1);
    Rectangle p1_3(165,235.16,20,10);
    p1_3.setColor(COLOR("white"));
    p1_3.setFill(1);
//pawn2
    Circle p2_1(230,203.83,10);
    p2_1.setColor(COLOR("white"));
    p2_1.setFill(1);
    Rectangle p2_2(230,225.16,10,20);
    p2_2.setColor(COLOR("white"));
    p2_2.setFill(1);
    Rectangle p2_3(230,235.16,20,10);
    p2_3.setColor(COLOR("white"));
    p2_3.setFill(1);
//pawn3
    Circle p3_1(295,203.83,10);
    p3_1.setColor(COLOR("white"));
    p3_1.setFill(1);
    Rectangle p3_2(295,225.16,10,20);
    p3_2.setColor(COLOR("white"));
    p3_2.setFill(1);
    Rectangle p3_3(295,235.16,20,10);
    p3_3.setColor(COLOR("white"));
    p3_3.setFill(1);
//pawn4
    Circle p4_1(360,203.83,10);
    p4_1.setColor(COLOR("white"));
    p4_1.setFill(1);
    Rectangle p4_2(360,225.16,10,20);
    p4_2.setColor(COLOR("white"));
    p4_2.setFill(1);
    Rectangle p4_3(360,235.16,20,10);
    p4_3.setColor(COLOR("white"));
    p4_3.setFill(1);
//pawn5
    Circle p5_1(425,203.83,10);
    p5_1.setColor(COLOR("white"));
    p5_1.setFill(1);
    Rectangle p5_2(425,225.16,10,20);
    p5_2.setColor(COLOR("white"));
    p5_2.setFill(1);
    Rectangle p5_3(425,235.16,20,10);
    p5_3.setColor(COLOR("white"));
    p5_3.setFill(1);
//pawn6
    Circle p6_1(490,203.83,10);
    p6_1.setColor(COLOR("white"));
    p6_1.setFill(1);
    Rectangle p6_2(490,225.16,10,20);
    p6_2.setColor(COLOR("white"));
    p6_2.setFill(1);
    Rectangle p6_3(490,235.16,20,10);
    p6_3.setColor(COLOR("white"));
    p6_3.setFill(1);
//pawn7
    Circle p7_1(555,203.83,10);
    p7_1.setColor(COLOR("white"));
    p7_1.setFill(1);
    Rectangle p7_2(555,225.16,10,20);
    p7_2.setColor(COLOR("white"));
    p7_2.setFill(1);
    Rectangle p7_3(555,235.16,20,10);
    p7_3.setColor(COLOR("white"));
    p7_3.setFill(1);
//pawn8
    Circle p8_1(620,203.83,10);
    p8_1.setColor(COLOR("white"));
    p8_1.setFill(1);
    Rectangle p8_2(620,225.16,10,20);
    p8_2.setColor(COLOR("white"));
    p8_2.setFill(1);
    Rectangle p8_3(620,235.16,20,10);
    p8_3.setColor(COLOR("white"));
    p8_3.setFill(1);

//elephant1
    Rectangle e1_1(165,160,50,20);
    e1_1.setColor(COLOR("white"));
    e1_1.setFill(1);
    Rectangle e1_2(145,150,10,20);
    e1_2.setColor(COLOR("white"));
    e1_2.setFill(1);
    Rectangle e1_3(165,150,10,20);
    e1_3.setColor(COLOR("white"));
    e1_3.setFill(1);
    Rectangle e1_4(185,150,10,20);
    e1_4.setColor(COLOR("white"));
    e1_4.setFill(1);
//elephant2
    Rectangle e2_1(620,160,50,20);
    e2_1.setColor(COLOR("white"));
    e2_1.setFill(1);
    Rectangle e2_2(600,150,10,20);
    e2_2.setColor(COLOR("white"));
    e2_2.setFill(1);
    Rectangle e2_3(620,150,10,20);
    e2_3.setColor(COLOR("white"));
    e2_3.setFill(1);
    Rectangle e2_4(640,150,10,20);
    e2_4.setColor(COLOR("white"));
    e2_4.setFill(1);

//camel1
    Circle c1_1(295,140,12);
    c1_1.setColor(COLOR("white"));
    c1_1.setFill(1);
    Rectangle c1_2(295,128,7.5,10);
    c1_2.setColor(COLOR("white"));
    c1_2.setFill(1);
    Rectangle c1_4(295,160,10,20);
    c1_4.setColor(COLOR("white"));
    c1_4.setFill(1);
    Rectangle c1_3(295,170,30,10);
    c1_3.setColor(COLOR("white"));
    c1_3.setFill(1);
//camel2
    Circle c2_1(490,140,12);
    c2_1.setColor(COLOR("white"));
    c2_1.setFill(1);
    Rectangle c2_2(490,128,7.5,10);
    c2_2.setColor(COLOR("white"));
    c2_2.setFill(1);
    Rectangle c2_4(490,160,10,20);
    c2_4.setColor(COLOR("white"));
    c2_4.setFill(1);
    Rectangle c2_3(490,170,30,10);
    c2_3.setColor(COLOR("white"));
    c2_3.setFill(1);

//horse1
    Rectangle h1_1(230,150,10,30);
    h1_1.setColor(COLOR("white"));
    h1_1.setFill(1);
    Rectangle h1_2(225,135,20,10);
    h1_2.setColor(COLOR("white"));
    h1_2.setFill(1);
    Rectangle h1_3(230,165,30,10);
    h1_3.setColor(COLOR("white"));
    h1_3.setFill(1);
//horse2
    Rectangle h2_1(555,150,10,30);
    h2_1.setColor(COLOR("white"));
    h2_1.setFill(1);
    Rectangle h2_2(550,135,20,10);
    h2_2.setColor(COLOR("white"));
    h2_2.setFill(1);
    Rectangle h2_3(555,165,30,10);
    h2_3.setColor(COLOR("white"));
    h2_3.setFill(1);

//queen
    Rectangle q_1(425,165,50,30);
    q_1.setColor(COLOR("white"));
    q_1.setFill(1);
    Rectangle q_2(408.334,150,11.784,11.784);
    q_2.rotate(PI/4);
    q_2.setColor(COLOR("white"));
    q_2.setFill(1);
    Rectangle q_3(425,150,11.784,11.784);
    q_3.rotate(PI/4);
    q_3.setColor(COLOR("white"));
    q_3.setFill(1);
    Rectangle q_4(441.667,150,11.784,11.784);
    q_4.rotate(PI/4);
    q_4.setColor(COLOR("white"));
    q_4.setFill(1);

//king
    Circle k_1(350,160,20);
    k_1.setColor(COLOR("white"));
    k_1.setFill(1);
    Circle k_2(370,160,20);
    k_2.setColor(COLOR("white"));
    k_2.setFill(1);
    Rectangle k_3(360,130,20,5);
    k_3.setColor(COLOR("white"));
    k_3.setFill(1);
    Rectangle k_4(360,130,5,20);
    k_4.setColor(COLOR("white"));
    k_4.setFill(1);

//PAWN1
    Circle P1_1(165,528.83,10);
    P1_1.setFill(1);
    Rectangle P1_2(165,550.16,10,20);
    P1_2.setFill(1);
    Rectangle P1_3(165,560.16,20,10);
    P1_3.setFill(1);
//PAWN2
    Circle P2_1(230,528.83,10);
    P2_1.setFill(1);
    Rectangle P2_2(230,550.16,10,20);
    P2_2.setFill(1);
    Rectangle P2_3(230,560.16,20,10);
    P2_3.setFill(1);
//PAWN3
    Circle P3_1(295,528.83,10);
    P3_1.setFill(1);
    Rectangle P3_2(295,550.16,10,20);
    P3_2.setFill(1);
    Rectangle P3_3(295,560.16,20,10);
    P3_3.setFill(1);
//PAWN4
    Circle P4_1(360,528.83,10);
    P4_1.setFill(1);
    Rectangle P4_2(360,550.16,10,20);
    P4_2.setFill(1);
    Rectangle P4_3(360,560.16,20,10);
    P4_3.setFill(1);
//PAWN5
    Circle P5_1(425,528.83,10);
    P5_1.setFill(1);
    Rectangle P5_2(425,550.16,10,20);
    P5_2.setFill(1);
    Rectangle P5_3(425,560.16,20,10);
    P5_3.setFill(1);
//PAWN6
    Circle P6_1(490,528.83,10);
    P6_1.setFill(1);
    Rectangle P6_2(490,550.16,10,20);
    P6_2.setFill(1);
    Rectangle P6_3(490,560.16,20,10);
    P6_3.setFill(1);
//PAWN7
    Circle P7_1(555,528.83,10);
    P7_1.setFill(1);
    Rectangle P7_2(555,550.16,10,20);
    P7_2.setFill(1);
    Rectangle P7_3(555,560.16,20,10);
    P7_3.setFill(1);
//PAWN8
    Circle P8_1(620,528.83,10);
    P8_1.setFill(1);
    Rectangle P8_2(620,550.16,10,20);
    P8_2.setFill(1);
    Rectangle P8_3(620,560.16,20,10);
    P8_3.setFill(1);

//ELEPHANT1
    Rectangle E1_1(165,615,50,20);
    E1_1.setFill(1);
    Rectangle E1_2(145,605,10,20);
    E1_2.setFill(1);
    Rectangle E1_3(165,605,10,20);
    E1_3.setFill(1);
    Rectangle E1_4(185,605,10,20);
    E1_4.setFill(1);
//ELEPHANT2
    Rectangle E2_1(620,615,50,20);
    E2_1.setFill(1);
    Rectangle E2_2(600,605,10,20);
    E2_2.setFill(1);
    Rectangle E2_3(620,605,10,20);
    E2_3.setFill(1);
    Rectangle E2_4(640,605,10,20);
    E2_4.setFill(1);

//CAMEL1
    Circle C1_1(295,595,12);
    C1_1.setFill(1);
    Rectangle C1_2(295,583,7.5,10);
    C1_2.setFill(1);
    Rectangle C1_4(295,615,10,20);
    C1_4.setFill(1);
    Rectangle C1_3(295,625,30,10);
    C1_3.setFill(1);
//CAMEL2
    Circle C2_1(490,595,12);
    C2_1.setFill(1);
    Rectangle C2_2(490,583,7.5,10);
    C2_2.setFill(1);
    Rectangle C2_4(490,615,10,20);
    C2_4.setFill(1);
    Rectangle C2_3(490,625,30,10);
    C2_3.setFill(1);


//HORSE1
    Rectangle H1_1(230,605,10,30);
    H1_1.setFill(1);
    Rectangle H1_2(225,590,20,10);
    H1_2.setFill(1);
    Rectangle H1_3(230,620,30,10);
    H1_3.setFill(1);
//HORSE2
    Rectangle H2_1(555,605,10,30);
    H2_1.setFill(1);
    Rectangle H2_2(550,590,20,10);
    H2_2.setFill(1);
    Rectangle H2_3(555,620,30,10);
    H2_3.setFill(1);

//QUEEN
    Rectangle Q_1(425,620,50,30);
    Q_1.setFill(1);
    Rectangle Q_2(408.334,605,11.784,11.784);
    Q_2.rotate(PI/4);
    Q_2.setFill(1);
    Rectangle Q_3(425,605,11.784,11.784);
    Q_3.rotate(PI/4);
    Q_3.setFill(1);
    Rectangle Q_4(441.667,605,11.784,11.784);
    Q_4.rotate(PI/4);
    Q_4.setFill(1);

//KING
    Circle K_1(350,615,20);
    K_1.setFill(1);
    Circle K_2(370,615,20);
    K_2.setFill(1);
    Rectangle K_3(360,585,20,5);
    K_3.setFill(1);
    Rectangle K_4(360,585,5,20);
    K_4.setFill(1);
    endFrame();
    char arr[10][10];
    int num[10][10];
    arr[1][1]='e';
    arr[1][2]='h';
    arr[1][3]='c';
    arr[1][4]='k';
    arr[1][5]='q';
    arr[1][6]='c';
    arr[1][7]='h';
    arr[1][8]='e';
    for(j=1; j<9; j++)
        arr[2][j]='p';
    for(j=1; j<9; j++)
        arr[7][j]='P';
    arr[8][1]='E';
    arr[8][2]='H';
    arr[8][3]='C';
    arr[8][4]='K';
    arr[8][5]='Q';
    arr[8][6]='C';
    arr[8][7]='H';
    arr[8][8]='E';
    for(i=3; i<7; i++)
    {
        for(j=1; j<9; j++)
            arr[i][j]='_';
    }
    for(i=0; i<10; i++)
        arr[0][i]='*';
    for(i=0; i<10; i++)
        arr[9][i]='*';
    for(i=1; i<9; i++)
        arr[i][0]='*';
    for(i=1; i<9; i++)
        arr[i][9]='*';
//Filling num array
    int alpha=1;
    for(i=1; i<3; i++)
    {
        for(j=1; j<9; j++)
        {
            num[i][j]=alpha;
            alpha++;
        }
    }
    for(i=7; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            num[i][j]=alpha;
            alpha++;
        }
    }
    for(i=3; i<7; i++)
    {
        for(j=1; j<9; j++)
            num[i][j]=0;
    }
    for(i=0; i<10; i++)
        num[0][i]=-1;
    for(i=0; i<10; i++)
        num[9][i]=-1;
    for(i=1; i<9; i++)
        num[i][0]=-1;
    for(i=1; i<9; i++)
        num[i][9]=-1;
//Display of arrays
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
            cout<<num[i][j]<<" ";
        cout<<endl;
    }
    int player;
    while(1)
    {
        int chk,kx,ky,atx=9,aty=9;
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                if(arr[i][j]=='k')
                {
                    kx=i;
                    ky=j;
                }
        }
        chk=check(kx,ky,arr,1);
        if(chk>0)
        {
            if(chk==1)
            {
                atx=attackerx(kx,ky,arr);
                aty=attackery(kx,ky,arr);
            }
            if(checkmate(kx,ky,atx,aty,arr,chk)==false)
            {
                cout<<"Player1 CHECK"<<endl;
                Text tchk(300,50,"Player 1 CHECK!");
                wait(2);
            }
            else
            {
                player=1;
                goto en;
            }
        }
a:
        cout<<"Player1 Select a Character";
        Text t1(200,100,"Player 1 Select");
        int selx,sely,w;
        w=getClick();
        selx=getI(w%65536);
        sely=getJ(w/65536);
        Text t3(200,100,"                                       ");
        if(selx>8||sely>8||selx<1||sely<1)
        {
            cout<<"Invalid input"<<endl;
            Text t2(400,100,"Invalid Input");
            wait(1);
            goto a;
        }
        char k;
        int k1;
        k=arr[selx][sely];
        k1=num[selx][sely];
        if(k=='_'||k1<1||k1>16)
        {
            cout<<"Invalid input"<<endl;
            Text t2(400,100,"Invalid Input");
            wait(1);
            goto a;
        }
        else cout<<k<<endl;
//Defining posx,posy,yes arrays and movex&movey
        int posx[30],posy[30],yes[30],flag=0,movey,movex;
        char swp;
        for(i=0; i<30; i++)yes[i]=0;
        if(k=='p')
        {
            Text t2(400,100,"White Pawn Selected");
            wait(0.5);
            if(arr[selx+1][sely]=='_')
            {
                posx[0]=selx+1;
                posy[0]=sely;
                yes[0]=1;
            }
            if(arr[selx+1][sely+1]=='P'||arr[selx+1][sely+1]=='E'||arr[selx+1][sely+1]=='C'||arr[selx+1][sely+1]=='H'||arr[selx+1][sely+1]=='K'||arr[selx+1][sely+1]=='Q')
            {
                posx[1]=selx+1;
                posy[1]=sely+1;
                yes[1]=1;
            }
            if(arr[selx+1][sely-1]=='P'||arr[selx+1][sely-1]=='E'||arr[selx+1][sely-1]=='C'||arr[selx+1][sely-1]=='H'||arr[selx+1][sely-1]=='K'||arr[selx+1][sely-1]=='Q')
            {
                posx[2]=selx+1;
                posy[2]=sely-1;
                yes[2]=1;
            }
            if(arr[selx+2][sely]=='_'&&selx==2)
            {
                posx[3]=selx+2;
                posy[3]=sely;
                yes[3]=1;
            }
        }
        if(k=='e')
        {
            Text t2(400,100,"White Rooke Selected");
            wait(0.5);
            i=1;
            j=1;
            int i1=0;
            while(arr[selx+i][sely]=='_'||arr[selx+i][sely]=='P'||arr[selx+i][sely]=='E'||arr[selx+i][sely]=='C'||arr[selx+i][sely]=='H'||arr[selx+i][sely]=='K'||arr[selx+i][sely]=='Q')
            {
                if(selx+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely]=='P'||arr[selx+i][sely]=='E'||arr[selx+i][sely]=='C'||arr[selx+i][sely]=='H'||arr[selx+i][sely]=='K'||arr[selx+i][sely]=='Q')
                    break;
                i++;
            }
            while(arr[selx][sely+j]=='_'||arr[selx][sely+j]=='P'||arr[selx][sely+j]=='E'||arr[selx][sely+j]=='C'||arr[selx][sely+j]=='H'||arr[selx][sely+j]=='K'||arr[selx][sely+j]=='Q')
            {
                if(sely+j<9)
                {
                    posx[i1]=selx;
                    posy[i1]=sely+j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely+j]=='P'||arr[selx][sely+j]=='E'||arr[selx][sely+j]=='C'||arr[selx][sely+j]=='H'||arr[selx][sely+j]=='K'||arr[selx][sely+j]=='Q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely]=='_'||arr[selx-i][sely]=='P'||arr[selx-i][sely]=='E'||arr[selx-i][sely]=='C'||arr[selx-i][sely]=='H'||arr[selx-i][sely]=='K'||arr[selx-i][sely]=='Q')
            {
                if(selx-i>0)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely]=='P'||arr[selx-i][sely]=='E'||arr[selx-i][sely]=='C'||arr[selx-i][sely]=='H'||arr[selx-i][sely]=='K'||arr[selx-i][sely]=='Q')
                    break;
                i++;
            }
            while(arr[selx][sely-j]=='_'||arr[selx][sely-j]=='P'||arr[selx][sely-j]=='E'||arr[selx][sely-j]=='C'||arr[selx][sely-j]=='H'||arr[selx][sely-j]=='K'||arr[selx][sely-j]=='Q')
            {
                if(sely-j>0)
                {
                    posx[i1]=selx;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely-j]=='P'||arr[selx][sely-j]=='E'||arr[selx][sely-j]=='C'||arr[selx][sely-j]=='H'||arr[selx][sely-j]=='K'||arr[selx][sely-j]=='Q')
                    break;
                j++;
            }
        }
        if(k=='c')
        {
            Text t2(400,100,"White Bishop Selected");
            wait(0.5);
            i=1;
            j=1;
            int i1=0;
            while(arr[selx+i][sely+i]=='_'||arr[selx+i][sely+i]=='P'||arr[selx+i][sely+i]=='E'||arr[selx+i][sely+i]=='C'||arr[selx+i][sely+i]=='H'||arr[selx+i][sely+i]=='K'||arr[selx+i][sely+i]=='Q')
            {
                if(selx+i<9&&sely+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely+i]=='P'||arr[selx+i][sely+i]=='E'||arr[selx+i][sely+i]=='C'||arr[selx+i][sely+i]=='H'||arr[selx+i][sely+i]=='K'||arr[selx+i][sely+i]=='Q')
                    break;
                i++;
            }
            while(arr[selx+j][sely-j]=='_'||arr[selx+j][sely-j]=='P'||arr[selx+j][sely-j]=='E'||arr[selx+j][sely-j]=='C'||arr[selx+j][sely-j]=='H'||arr[selx+j][sely-j]=='K'||arr[selx+j][sely-j]=='Q')
            {
                if(selx+j<9&&sely-j>0)
                {
                    posx[i1]=selx+j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+j][sely-j]=='P'||arr[selx+j][sely-j]=='E'||arr[selx+j][sely-j]=='C'||arr[selx+j][sely-j]=='H'||arr[selx+j][sely-j]=='K'||arr[selx+j][sely-j]=='Q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely+i]=='_'||arr[selx-i][sely+i]=='P'||arr[selx-i][sely+i]=='E'||arr[selx-i][sely+i]=='C'||arr[selx-i][sely+i]=='H'||arr[selx-i][sely+i]=='K'||arr[selx-i][sely+i]=='Q')
            {
                if(selx-i>0&&sely+i<9)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely+i]=='P'||arr[selx-i][sely+i]=='E'||arr[selx-i][sely+i]=='C'||arr[selx-i][sely+i]=='H'||arr[selx-i][sely+i]=='K'||arr[selx-i][sely+i]=='Q')
                    break;
                i++;
            }
            while(arr[selx-j][sely-j]=='_'||arr[selx-j][sely-j]=='P'||arr[selx-j][sely-j]=='E'||arr[selx-j][sely-j]=='C'||arr[selx-j][sely-j]=='H'||arr[selx-j][sely-j]=='K'||arr[selx-j][sely-j]=='Q')
            {
                if(sely-j>0&&selx-j>0)
                {
                    posx[i1]=selx-j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-j][sely-j]=='P'||arr[selx-j][sely-j]=='E'||arr[selx-j][sely-j]=='C'||arr[selx-j][sely-j]=='H'||arr[selx-j][sely-j]=='K'||arr[selx-j][sely-j]=='Q')
                    break;
                j++;
            }
        }
        if(k=='h')
        {
            Text t2(400,100,"White Knight Selected");
            wait(0.5);
            i=0;
            if(arr[selx+2][sely+1]=='_'||arr[selx+2][sely+1]=='P'||arr[selx+2][sely+1]=='C'||arr[selx+2][sely+1]=='E'
                    ||arr[selx+2][sely+1]=='H'||arr[selx+2][sely+1]=='K'||arr[selx+2][sely+1]=='Q')
            {
                if(selx+2<9&&sely+1<9)
                {
                    posx[i]=selx+2;
                    posy[i]=sely+1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx+2][sely-1]=='_'||arr[selx+2][sely-1]=='P'||arr[selx+2][sely-1]=='E'||arr[selx+2][sely-1]=='H'
                    ||arr[selx+2][sely-1]=='C'||arr[selx+2][sely-1]=='Q'||arr[selx+2][sely-1]=='K')
            {
                if(selx+2<9&&sely-1>0)
                {
                    posx[i]=selx+2;
                    posy[i]=sely-1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx+1][sely+2]=='_'||arr[selx+1][sely+2]=='P'||arr[selx+1][sely+2]=='E'||arr[selx+1][sely+2]=='H'
                    ||arr[selx+1][sely+2]=='C'||arr[selx+1][sely+2]=='Q'||arr[selx+1][sely+2]=='K')
            {
                if(selx+1<9&&sely+2<9)
                {
                    posx[i]=selx+1;
                    posy[i]=sely+2;
                    yes[i]=1;
                    i++;
                }
            }
            if(arr[selx+1][sely-2]=='_'||arr[selx+1][sely-2]=='P'||arr[selx+1][sely-2]=='E'||arr[selx+1][sely-2]=='H'
                    ||arr[selx+1][sely-2]=='C'||arr[selx+1][sely-2]=='Q'||arr[selx+1][sely-2]=='K')
            {
                if(selx+1<9&&sely-2>0)
                {
                    posx[i]=selx+1;
                    posy[i]=sely-2;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-2][sely+1]=='_'||arr[selx-2][sely+1]=='P'||arr[selx-2][sely+1]=='E'||arr[selx-2][sely+1]=='H'
                    ||arr[selx-2][sely+1]=='C'||arr[selx-2][sely+1]=='Q'||arr[selx-2][sely+1]=='K')
            {
                if(selx-2>0&&sely+1<9)
                {
                    posx[i]=selx-2;
                    posy[i]=sely+1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-2][sely-1]=='_'||arr[selx-2][sely-1]=='P'||arr[selx-2][sely-1]=='E'||arr[selx-2][sely-1]=='H'
                    ||arr[selx-2][sely-1]=='C'||arr[selx-2][sely-1]=='Q'||arr[selx-2][sely-1]=='K')
            {
                if(selx-2>0&&sely-1>0)
                {
                    posx[i]=selx-2;
                    posy[i]=sely-1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-1][sely+2]=='_'||arr[selx-1][sely+2]=='P'||arr[selx-1][sely+2]=='E'||arr[selx-1][sely+2]=='H'
                    ||arr[selx-1][sely+2]=='C'||arr[selx-1][sely+2]=='Q'||arr[selx-1][sely+2]=='K')
            {
                if(selx-1>0&&sely+2<9)
                {
                    posx[i]=selx-1;
                    posy[i]=sely+2;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-1][sely-2]=='_'||arr[selx-1][sely-2]=='P'||arr[selx-1][sely-2]=='E'||arr[selx-1][sely-2]=='H'
                    ||arr[selx-1][sely-2]=='C'||arr[selx-1][sely-2]=='Q'||arr[selx-1][sely-2]=='K')
            {
                if(selx-1>0&&sely-2>0)
                {
                    posx[i]=selx-1;
                    posy[i]=sely-2;
                    yes[i]=1;
                    i++;
                }
            }
        }
        if(k=='q')
        {
            Text t2(400,100,"White Queen Selected");
            wait(0.5);
            i=1;
            j=1;
            int i1=0;
            while(arr[selx+i][sely]=='_'||arr[selx+i][sely]=='P'||arr[selx+i][sely]=='E'||arr[selx+i][sely]=='C'||arr[selx+i][sely]=='H'||arr[selx+i][sely]=='K'||arr[selx+i][sely]=='Q')
            {
                if(selx+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely]=='P'||arr[selx+i][sely]=='E'||arr[selx+i][sely]=='C'||arr[selx+i][sely]=='H'||arr[selx+i][sely]=='K'||arr[selx+i][sely]=='Q')
                    break;
                i++;
            }
            while(arr[selx][sely+j]=='_'||arr[selx][sely+j]=='P'||arr[selx][sely+j]=='E'||arr[selx][sely+j]=='C'||arr[selx][sely+j]=='H'||arr[selx][sely+j]=='K'||arr[selx][sely+j]=='Q')
            {
                if(sely+j<9)
                {
                    posx[i1]=selx;
                    posy[i1]=sely+j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely+j]=='P'||arr[selx][sely+j]=='E'||arr[selx][sely+j]=='C'||arr[selx][sely+j]=='H'||arr[selx][sely+j]=='K'||arr[selx][sely+j]=='Q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely]=='_'||arr[selx-i][sely]=='P'||arr[selx-i][sely]=='E'||arr[selx-i][sely]=='C'||arr[selx-i][sely]=='H'||arr[selx-i][sely]=='K'||arr[selx-i][sely]=='Q')
            {
                if(selx-i>0)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely]=='P'||arr[selx-i][sely]=='E'||arr[selx-i][sely]=='C'||arr[selx-i][sely]=='H'||arr[selx-i][sely]=='K'||arr[selx-i][sely]=='Q')
                    break;
                i++;
            }
            while(arr[selx][sely-j]=='_'||arr[selx][sely-j]=='P'||arr[selx][sely-j]=='E'||arr[selx][sely-j]=='C'||arr[selx][sely-j]=='H'||arr[selx][sely-j]=='K'||arr[selx][sely-j]=='Q')
            {
                if(sely-j>0)
                {
                    posx[i1]=selx;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely-j]=='P'||arr[selx][sely-j]=='E'||arr[selx][sely-j]=='C'||arr[selx][sely-j]=='H'||arr[selx][sely-j]=='K'||arr[selx][sely-j]=='Q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx+i][sely+i]=='_'||arr[selx+i][sely+i]=='P'||arr[selx+i][sely+i]=='E'||arr[selx+i][sely+i]=='C'||arr[selx+i][sely+i]=='H'||arr[selx+i][sely+i]=='K'||arr[selx+i][sely+i]=='Q')
            {
                if(selx+i<9&&sely+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely+i]=='P'||arr[selx+i][sely+i]=='E'||arr[selx+i][sely+i]=='C'||arr[selx+i][sely+i]=='H'||arr[selx+i][sely+i]=='K'||arr[selx+i][sely+i]=='Q')
                    break;
                i++;
            }
            while(arr[selx+j][sely-j]=='_'||arr[selx+j][sely-j]=='P'||arr[selx+j][sely-j]=='E'||arr[selx+j][sely-j]=='C'||arr[selx+j][sely-j]=='H'||arr[selx+j][sely-j]=='K'||arr[selx+j][sely-j]=='Q')
            {
                if(selx+j<9&&sely-j>0)
                {
                    posx[i1]=selx+j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+j][sely-j]=='P'||arr[selx+j][sely-j]=='E'||arr[selx+j][sely-j]=='C'||arr[selx+j][sely-j]=='H'||arr[selx+j][sely-j]=='K'||arr[selx+j][sely-j]=='Q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely+i]=='_'||arr[selx-i][sely+i]=='P'||arr[selx-i][sely+i]=='E'||arr[selx-i][sely+i]=='C'||arr[selx-i][sely+i]=='H'||arr[selx-i][sely+i]=='K'||arr[selx-i][sely+i]=='Q')
            {
                if(selx-i>0&&sely+i<9)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely+i]=='P'||arr[selx-i][sely+i]=='E'||arr[selx-i][sely+i]=='C'||arr[selx-i][sely+i]=='H'||arr[selx-i][sely+i]=='K'||arr[selx-i][sely+i]=='Q')
                    break;
                i++;
            }
            while(arr[selx-j][sely-j]=='_'||arr[selx-j][sely-j]=='P'||arr[selx-j][sely-j]=='E'||arr[selx-j][sely-j]=='C'||arr[selx-j][sely-j]=='H'||arr[selx-j][sely-j]=='K'||arr[selx-j][sely-j]=='Q')
            {
                if(sely-j>0&&selx-j>0)
                {
                    posx[i1]=selx-j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-j][sely-j]=='P'||arr[selx-j][sely-j]=='E'||arr[selx-j][sely-j]=='C'||arr[selx-j][sely-j]=='H'||arr[selx-j][sely-j]=='K'||arr[selx-j][sely-j]=='Q')
                    break;
                j++;
            }
        }
        if(k=='k')
        {
            Text t2(400,100,"White KING Selected");
            wait(0.5);
            int i1=0;
            if(arr[selx+1][sely]=='_'||arr[selx+1][sely]=='P'||arr[selx+1][sely]=='E'||arr[selx+1][sely]=='C'||arr[selx+1][sely]=='H'||arr[selx+1][sely]=='K'||arr[selx+1][sely]=='Q')
            {
                posx[i1]=selx+1;
                posy[i1]=sely;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx+1][sely+1]=='_'||arr[selx+1][sely+1]=='P'||arr[selx+1][sely+1]=='E'||arr[selx+1][sely+1]=='C'||arr[selx+1][sely+1]=='H'||arr[selx+1][sely+1]=='K'||arr[selx+1][sely+1]=='Q')
            {
                posx[i1]=selx+1;
                posy[i1]=sely+1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx+1][sely-1]=='_'||arr[selx+1][sely-1]=='P'||arr[selx+1][sely-1]=='E'||arr[selx+1][sely-1]=='C'||arr[selx+1][sely-1]=='H'||arr[selx+1][sely-1]=='K'||arr[selx+1][sely-1]=='Q')
            {
                posx[i1]=selx+1;
                posy[i1]=sely-1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx][sely+1]=='_'||arr[selx][sely+1]=='P'||arr[selx][sely+1]=='E'||arr[selx][sely+1]=='C'||arr[selx][sely+1]=='H'||arr[selx][sely+1]=='K'||arr[selx][sely+1]=='Q')
            {
                posx[i1]=selx;
                posy[i1]=sely+1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx][sely-1]=='_'||arr[selx][sely-1]=='P'||arr[selx][sely-1]=='E'||arr[selx][sely-1]=='C'||arr[selx][sely-1]=='H'||arr[selx][sely-1]=='K'||arr[selx][sely-1]=='Q')
            {
                posx[i1]=selx;
                posy[i1]=sely-1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx-1][sely+1]=='_'||arr[selx-1][sely+1]=='P'||arr[selx-1][sely+1]=='E'||arr[selx-1][sely+1]=='C'||arr[selx-1][sely+1]=='H'||arr[selx-1][sely+1]=='K'||arr[selx-1][sely+1]=='Q')
            {
                posx[i1]=selx-1;
                posy[i1]=sely+1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx-1][sely-1]=='_'||arr[selx-1][sely-1]=='P'||arr[selx-1][sely-1]=='E'||arr[selx-1][sely-1]=='C'||arr[selx-1][sely-1]=='H'||arr[selx-1][sely-1]=='K'||arr[selx-1][sely-1]=='Q')
            {
                posx[i1]=selx-1;
                posy[i1]=sely-1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx-1][sely]=='_'||arr[selx-1][sely]=='P'||arr[selx-1][sely]=='E'||arr[selx-1][sely]=='C'||arr[selx-1][sely]=='H'||arr[selx-1][sely]=='K'||arr[selx-1][sely]=='Q')
            {
                posx[i1]=selx-1;
                posy[i1]=sely;
                yes[i1]=1;
                i1++;
            }
        }
//Display of Possible Moves
        for(i=0; i<30; i++)
        {
            if(yes[i]==1)
                cout<<"("<<posx[i]<<","<<posy[i]<<")";
        }
//Entering the move
        Text t4(200,100,"Player 1 Move");
        w=getClick();
        movex=getI(w%65536);
        movey=getJ(w/65536);
        for(i=0; i<30; i++)
        {
            if(posx[i]==movex&&posy[i]==movey&&yes[i]==1)
            {
                swp=arr[movex][movey];
                arr[movex][movey]=arr[selx][sely];
                arr[selx][sely]='_';
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<"Invalid Input"<<endl;
            Text t2(400,100,"Invalid Input");
            wait(1);
            goto a;
        }
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                if(arr[i][j]=='k')
                {
                    kx=i;
                    ky=j;
                }
        }
        chk=check(kx,ky,arr,1);
        if(chk>0)
        {
            cout<<"UNSAFE MOVE!"<<endl;
            Text t2(400,100,"  Unsafe Move!  ");
            wait(1);
            arr[selx][sely]=arr[movex][movey];
            arr[movex][movey]=swp;
            goto a;
        }
        Text t5(200,100,"                                  ");
//moving of character
        j=movex-selx;
        i=movey-sely;
        int n=num[selx][sely];
        {
            if(n==1)
            {
                e1_1.move(65*i,65*j);
                e1_2.move(65*i,65*j);
                e1_3.move(65*i,65*j);
                e1_4.move(65*i,65*j);
            }
            if(n==2)
            {
                h1_1.move(65*i,65*j);
                h1_2.move(65*i,65*j);
                h1_3.move(65*i,65*j);
            }
            if(n==3)
            {
                c1_1.move(65*i,65*j);
                c1_2.move(65*i,65*j);
                c1_3.move(65*i,65*j);
                c1_4.move(65*i,65*j);
            }
            if(n==4)
            {
                k_1.move(65*i,65*j);
                k_2.move(65*i,65*j);
                k_3.move(65*i,65*j);
                k_4.move(65*i,65*j);
            }
            if(n==5)
            {
                q_1.move(65*i,65*j);
                q_2.move(65*i,65*j);
                q_3.move(65*i,65*j);
                q_4.move(65*i,65*j);
            }
            if(n==6)
            {
                c2_1.move(65*i,65*j);
                c2_2.move(65*i,65*j);
                c2_3.move(65*i,65*j);
                c2_4.move(65*i,65*j);
            }
            if(n==7)
            {
                h2_1.move(65*i,65*j);
                h2_2.move(65*i,65*j);
                h2_3.move(65*i,65*j);
            }
            if(n==8)
            {
                e2_1.move(65*i,65*j);
                e2_2.move(65*i,65*j);
                e2_3.move(65*i,65*j);
                e2_4.move(65*i,65*j);
            }
            if(n==9)
            {
                p1_1.move(65*i,65*j);
                p1_2.move(65*i,65*j);
                p1_3.move(65*i,65*j);
            }
            if(n==10)
            {
                p2_1.move(65*i,65*j);
                p2_2.move(65*i,65*j);
                p2_3.move(65*i,65*j);
            }
            if(n==11)
            {
                p3_1.move(65*i,65*j);
                p3_2.move(65*i,65*j);
                p3_3.move(65*i,65*j);
            }
            if(n==12)
            {
                p4_1.move(65*i,65*j);
                p4_2.move(65*i,65*j);
                p4_3.move(65*i,65*j);
            }
            if(n==13)
            {
                p5_1.move(65*i,65*j);
                p5_2.move(65*i,65*j);
                p5_3.move(65*i,65*j);
            }
            if(n==14)
            {
                p6_1.move(65*i,65*j);
                p6_2.move(65*i,65*j);
                p6_3.move(65*i,65*j);
            }
            if(n==15)
            {
                p7_1.move(65*i,65*j);
                p7_2.move(65*i,65*j);
                p7_3.move(65*i,65*j);
            }
            if(n==16)
            {
                p8_1.move(65*i,65*j);
                p8_2.move(65*i,65*j);
                p8_3.move(65*i,65*j);
            }
        }
//disappearing of character
        n=num[movex][movey];
        {
            if(n==25)
            {
                E1_1.scale(0.0001);
                E1_2.scale(0.0001);
                E1_3.scale(0.0001);
                E1_4.scale(0.0001);
            }
            if(n==26)
            {
                H1_1.scale(0.0001);
                H1_2.scale(0.0001);
                H1_3.scale(0.0001);
            }
            if(n==27)
            {
                C1_1.scale(0.0001);
                C1_2.scale(0.0001);
                C1_3.scale(0.0001);
                C1_4.scale(0.0001);
            }
            if(n==28)
            {
                K_1.scale(0.0001);
                K_2.scale(0.0001);
                K_3.scale(0.0001);
                K_4.scale(0.0001);
            }
            if(n==29)
            {
                Q_1.scale(0.0001);
                Q_2.scale(0.0001);
                Q_3.scale(0.0001);
                Q_4.scale(0.0001);
            }
            if(n==30)
            {
                C2_1.scale(0.0001);
                C2_2.scale(0.0001);
                C2_3.scale(0.0001);
                C2_4.scale(0.0001);
            }
            if(n==31)
            {
                H2_1.scale(0.0001);
                H2_2.scale(0.0001);
                H2_3.scale(0.0001);
            }
            if(n==32)
            {
                E2_1.scale(0.0001);
                E2_2.scale(0.0001);
                E2_3.scale(0.0001);
                E2_4.scale(0.0001);
            }
            if(n==17)
            {
                P1_1.scale(0.0001);
                P1_2.scale(0.0001);
                P1_3.scale(0.0001);
            }
            if(n==18)
            {
                P2_1.scale(0.0001);
                P2_2.scale(0.0001);
                P2_3.scale(0.0001);
            }
            if(n==19)
            {
                P3_1.scale(0.0001);
                P3_2.scale(0.0001);
                P3_3.scale(0.0001);
            }
            if(n==20)
            {
                P4_1.scale(0.0001);
                P4_2.scale(0.0001);
                P4_3.scale(0.0001);
            }
            if(n==21)
            {
                P5_1.scale(0.0001);
                P5_2.scale(0.0001);
                P5_3.scale(0.0001);
            }
            if(n==22)
            {
                P6_1.scale(0.0001);
                P6_2.scale(0.0001);
                P6_3.scale(0.0001);
            }
            if(n==23)
            {
                P7_1.scale(0.0001);
                P7_2.scale(0.0001);
                P7_3.scale(0.0001);
            }
            if(n==24)
            {
                P8_1.scale(0.0001);
                P8_2.scale(0.0001);
                P8_3.scale(0.0001);
            }
        }
        num[movex][movey]=num[selx][sely];
        num[selx][sely]=0;
//printing of arrays
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                cout<<num[i][j]<<" ";
            cout<<endl;
        }
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                if(arr[i][j]=='K')
                {
                    kx=i;
                    ky=j;
                }
        }
        chk=CHECK(kx,ky,arr,1);
        if(chk>0)
        {
            if(chk==1)
            {
                atx=ATTACKERX(kx,ky,arr);
                aty=ATTACKERY(kx,ky,arr);
            }
            if(CHECKMATE(kx,ky,atx,aty,arr,chk)==false)
            {
                cout<<"Player2 CHECK"<<endl;
                Text TCHK(300,680,"Player 2 CHECK!");
                wait(2);
            }
            else
            {
                player=2;
                goto en;
            }
        }
b:
        cout<<"Player2 Select a Character";
        Text T1(200,650,"Player 2 Select");
        w=getClick();
        selx=getI(w%65536);
        sely=getJ(w/65536);
        Text T3(200,650,"                                       ");
        if(selx>8||sely>8||selx<1||sely<1)
        {
            cout<<"Invalid input"<<endl;
            Text T2(400,650,"Invalid Input");
            wait(1);
            goto b;
        }
        k=arr[selx][sely];
        k1=num[selx][sely];
        if(k=='_'||k1<17||k1>32)
        {
            cout<<"Invalid input"<<endl;
            Text T2(400,650,"Invalid Input");
            wait(1);
            goto b;
        }
        else cout<<k<<endl;
//Assigning Value to yes[i]
        for(i=0; i<30; i++)yes[i]=0;
        flag=0;
        if(k=='P')
        {
            Text T2(400,650,"Black Pawn Selected");
            wait(0.5);
            if(arr[selx-1][sely]=='_')
            {
                posx[0]=selx-1;
                posy[0]=sely;
                yes[0]=1;
            }
            if(arr[selx-1][sely+1]=='p'||arr[selx-1][sely+1]=='e'||arr[selx-1][sely+1]=='c'||arr[selx-1][sely+1]=='h'||arr[selx-1][sely+1]=='k'||arr[selx-1][sely+1]=='q')
            {
                posx[1]=selx-1;
                posy[1]=sely+1;
                yes[1]=1;
            }
            if(arr[selx-1][sely-1]=='p'||arr[selx-1][sely-1]=='e'||arr[selx-1][sely-1]=='c'||arr[selx-1][sely-1]=='h'||arr[selx-1][sely-1]=='k'||arr[selx-1][sely-1]=='q')
            {
                posx[2]=selx-1;
                posy[2]=sely-1;
                yes[2]=1;
            }
            if(arr[selx-2][sely]=='_'&&selx==7)
            {
                posx[3]=selx-2;
                posy[3]=sely;
                yes[3]=1;
            }
        }
        if(k=='H')
        {
            Text T2(400,650,"Black Knight Selected");
            wait(0.5);
            i=0;
            if(arr[selx+2][sely+1]=='_'||arr[selx+2][sely+1]=='p'||arr[selx+2][sely+1]=='c'||arr[selx+2][sely+1]=='e'
                    ||arr[selx+2][sely+1]=='h'||arr[selx+2][sely+1]=='k'||arr[selx+2][sely+1]=='q')
            {
                if(selx+2<9&&sely+1<9)
                {
                    posx[i]=selx+2;
                    posy[i]=sely+1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx+2][sely-1]=='_'||arr[selx+2][sely-1]=='p'||arr[selx+2][sely-1]=='e'||arr[selx+2][sely-1]=='h'
                    ||arr[selx+2][sely-1]=='c'||arr[selx+2][sely-1]=='q'||arr[selx+2][sely-1]=='k')
            {
                if(selx+2<9&&sely-1>0)
                {
                    posx[i]=selx+2;
                    posy[i]=sely-1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx+1][sely+2]=='_'||arr[selx+1][sely+2]=='p'||arr[selx+1][sely+2]=='e'||arr[selx+1][sely+2]=='h'
                    ||arr[selx+1][sely+2]=='c'||arr[selx+1][sely+2]=='q'||arr[selx+1][sely+2]=='k')
            {
                if(selx+1<9&&sely+2<9)
                {
                    posx[i]=selx+1;
                    posy[i]=sely+2;
                    yes[i]=1;
                    i++;
                }
            }
            if(arr[selx+1][sely-2]=='_'||arr[selx+1][sely-2]=='p'||arr[selx+1][sely-2]=='e'||arr[selx+1][sely-2]=='h'
                    ||arr[selx+1][sely-2]=='c'||arr[selx+1][sely-2]=='q'||arr[selx+1][sely-2]=='k')
            {
                if(selx+1<9&&sely-2>0)
                {
                    posx[i]=selx+1;
                    posy[i]=sely-2;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-2][sely+1]=='_'||arr[selx-2][sely+1]=='p'||arr[selx-2][sely+1]=='e'||arr[selx-2][sely+1]=='h'
                    ||arr[selx-2][sely+1]=='c'||arr[selx-2][sely+1]=='q'||arr[selx-2][sely+1]=='k')
            {
                if(selx-2>0&&sely+1<9)
                {
                    posx[i]=selx-2;
                    posy[i]=sely+1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-2][sely-1]=='_'||arr[selx-2][sely-1]=='p'||arr[selx-2][sely-1]=='e'||arr[selx-2][sely-1]=='h'
                    ||arr[selx-2][sely-1]=='c'||arr[selx-2][sely-1]=='q'||arr[selx-2][sely-1]=='k')
            {
                if(selx-2>0&&sely-1>0)
                {
                    posx[i]=selx-2;
                    posy[i]=sely-1;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-1][sely+2]=='_'||arr[selx-1][sely+2]=='p'||arr[selx-1][sely+2]=='e'||arr[selx-1][sely+2]=='h'
                    ||arr[selx-1][sely+2]=='c'||arr[selx-1][sely+2]=='q'||arr[selx-1][sely+2]=='k')
            {
                if(selx-1>0&&sely+2<9)
                {
                    posx[i]=selx-1;
                    posy[i]=sely+2;
                    yes[i]=1;
                    i++;
                }
            }

            if(arr[selx-1][sely-2]=='_'||arr[selx-1][sely-2]=='p'||arr[selx-1][sely-2]=='e'||arr[selx-1][sely-2]=='h'
                    ||arr[selx-1][sely-2]=='c'||arr[selx-1][sely-2]=='q'||arr[selx-1][sely-2]=='k')
            {
                if(selx-1>0&&sely-2>0)
                {
                    posx[i]=selx-1;
                    posy[i]=sely-2;
                    yes[i]=1;
                    i++;
                }
            }
        }
        if(k=='E')
        {
            Text T2(400,650,"Black Rooke Selected");
            wait(0.5);
            i=1;
            j=1;
            int i1=0;
            while(arr[selx+i][sely]=='_'||arr[selx+i][sely]=='p'||arr[selx+i][sely]=='e'||arr[selx+i][sely]=='c'||arr[selx+i][sely]=='h'||arr[selx+i][sely]=='k'||arr[selx+i][sely]=='q')
            {
                if(selx+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely]=='p'||arr[selx+i][sely]=='e'||arr[selx+i][sely]=='e'||arr[selx+i][sely]=='h'||arr[selx+i][sely]=='k'||arr[selx+i][sely]=='q')
                    break;
                i++;
            }
            while(arr[selx][sely+j]=='_'||arr[selx][sely+j]=='p'||arr[selx][sely+j]=='e'||arr[selx][sely+j]=='c'||arr[selx][sely+j]=='h'||arr[selx][sely+j]=='k'||arr[selx][sely+j]=='q')
            {
                if(sely+j<9)
                {
                    posx[i1]=selx;
                    posy[i1]=sely+j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely+j]=='p'||arr[selx][sely+j]=='e'||arr[selx][sely+j]=='c'||arr[selx][sely+j]=='h'||arr[selx][sely+j]=='k'||arr[selx][sely+j]=='q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely]=='_'||arr[selx-i][sely]=='p'||arr[selx-i][sely]=='e'||arr[selx-i][sely]=='c'||arr[selx-i][sely]=='h'||arr[selx-i][sely]=='k'||arr[selx-i][sely]=='q')
            {
                if(selx-i>0)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely]=='p'||arr[selx-i][sely]=='e'||arr[selx-i][sely]=='c'||arr[selx-i][sely]=='h'||arr[selx-i][sely]=='k'||arr[selx-i][sely]=='q')
                    break;
                i++;
            }
            while(arr[selx][sely-j]=='_'||arr[selx][sely-j]=='p'||arr[selx][sely-j]=='e'||arr[selx][sely-j]=='c'||arr[selx][sely-j]=='h'||arr[selx][sely-j]=='k'||arr[selx][sely-j]=='q')
            {
                if(sely-j>0)
                {
                    posx[i1]=selx;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely-j]=='p'||arr[selx][sely-j]=='e'||arr[selx][sely-j]=='c'||arr[selx][sely-j]=='h'||arr[selx][sely-j]=='k'||arr[selx][sely-j]=='q')
                    break;
                j++;
            }
        }
        if(k=='C')
        {
            Text T2(400,650,"Black Bishop Selected");
            wait(0.5);
            i=1;
            j=1;
            int i1=0;
            while(arr[selx+i][sely+i]=='_'||arr[selx+i][sely+i]=='p'||arr[selx+i][sely+i]=='e'||arr[selx+i][sely+i]=='c'||arr[selx+i][sely+i]=='h'||arr[selx+i][sely+i]=='k'||arr[selx+i][sely+i]=='q')
            {
                if(selx+i<9&&sely+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely+i]=='p'||arr[selx+i][sely+i]=='e'||arr[selx+i][sely+i]=='c'||arr[selx+i][sely+i]=='h'||arr[selx+i][sely+i]=='k'||arr[selx+i][sely+i]=='q')
                    break;
                i++;
            }
            while(arr[selx+j][sely-j]=='_'||arr[selx+j][sely-j]=='p'||arr[selx+j][sely-j]=='e'||arr[selx+j][sely-j]=='c'||arr[selx+j][sely-j]=='h'||arr[selx+j][sely-j]=='k'||arr[selx+j][sely-j]=='q')
            {
                if(selx+j<9&&sely-j>0)
                {
                    posx[i1]=selx+j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+j][sely-j]=='p'||arr[selx+j][sely-j]=='e'||arr[selx+j][sely-j]=='c'||arr[selx+j][sely-j]=='h'||arr[selx+j][sely-j]=='k'||arr[selx+j][sely-j]=='q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely+i]=='_'||arr[selx-i][sely+i]=='p'||arr[selx-i][sely+i]=='e'||arr[selx-i][sely+i]=='c'||arr[selx-i][sely+i]=='h'||arr[selx-i][sely+i]=='k'||arr[selx-i][sely+i]=='q')
            {
                if(selx-i>0&&sely+i<9)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely+i]=='p'||arr[selx-i][sely+i]=='e'||arr[selx-i][sely+i]=='c'||arr[selx-i][sely+i]=='h'||arr[selx-i][sely+i]=='k'||arr[selx-i][sely+i]=='q')
                    break;
                i++;
            }
            while(arr[selx-j][sely-j]=='_'||arr[selx-j][sely-j]=='p'||arr[selx-j][sely-j]=='e'||arr[selx-j][sely-j]=='c'||arr[selx-j][sely-j]=='h'||arr[selx-j][sely-j]=='k'||arr[selx-j][sely-j]=='q')
            {
                if(sely-j>0&&selx-j>0)
                {
                    posx[i1]=selx-j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-j][sely-j]=='p'||arr[selx-j][sely-j]=='e'||arr[selx-j][sely-j]=='c'||arr[selx-j][sely-j]=='h'||arr[selx-j][sely-j]=='k'||arr[selx-j][sely-j]=='q')
                    break;
                j++;
            }
        }
        if(k=='Q')
        {
            Text T2(400,650,"Black Queen Selected");
            wait(0.5);
            i=1;
            j=1;
            int i1=0;
            while(arr[selx+i][sely]=='_'||arr[selx+i][sely]=='p'||arr[selx+i][sely]=='e'||arr[selx+i][sely]=='c'||arr[selx+i][sely]=='h'||arr[selx+i][sely]=='k'||arr[selx+i][sely]=='q')
            {
                if(selx+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely]=='p'||arr[selx+i][sely]=='e'||arr[selx+i][sely]=='e'||arr[selx+i][sely]=='h'||arr[selx+i][sely]=='k'||arr[selx+i][sely]=='q')
                    break;
                i++;
            }
            while(arr[selx][sely+j]=='_'||arr[selx][sely+j]=='p'||arr[selx][sely+j]=='e'||arr[selx][sely+j]=='c'||arr[selx][sely+j]=='h'||arr[selx][sely+j]=='k'||arr[selx][sely+j]=='q')
            {
                if(sely+j<9)
                {
                    posx[i1]=selx;
                    posy[i1]=sely+j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely+j]=='p'||arr[selx][sely+j]=='e'||arr[selx][sely+j]=='c'||arr[selx][sely+j]=='h'||arr[selx][sely+j]=='k'||arr[selx][sely+j]=='q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely]=='_'||arr[selx-i][sely]=='p'||arr[selx-i][sely]=='e'||arr[selx-i][sely]=='c'||arr[selx-i][sely]=='h'||arr[selx-i][sely]=='k'||arr[selx-i][sely]=='q')
            {
                if(selx-i>0)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely]=='p'||arr[selx-i][sely]=='e'||arr[selx-i][sely]=='c'||arr[selx-i][sely]=='h'||arr[selx-i][sely]=='k'||arr[selx-i][sely]=='q')
                    break;
                i++;
            }
            while(arr[selx][sely-j]=='_'||arr[selx][sely-j]=='p'||arr[selx][sely-j]=='e'||arr[selx][sely-j]=='c'||arr[selx][sely-j]=='h'||arr[selx][sely-j]=='k'||arr[selx][sely-j]=='q')
            {
                if(sely-j>0)
                {
                    posx[i1]=selx;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx][sely-j]=='p'||arr[selx][sely-j]=='e'||arr[selx][sely-j]=='c'||arr[selx][sely-j]=='h'||arr[selx][sely-j]=='k'||arr[selx][sely-j]=='q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx+i][sely+i]=='_'||arr[selx+i][sely+i]=='p'||arr[selx+i][sely+i]=='e'||arr[selx+i][sely+i]=='c'||arr[selx+i][sely+i]=='h'||arr[selx+i][sely+i]=='k'||arr[selx+i][sely+i]=='q')
            {
                if(selx+i<9&&sely+i<9)
                {
                    posx[i1]=selx+i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+i][sely+i]=='p'||arr[selx+i][sely+i]=='e'||arr[selx+i][sely+i]=='c'||arr[selx+i][sely+i]=='h'||arr[selx+i][sely+i]=='k'||arr[selx+i][sely+i]=='q')
                    break;
                i++;
            }
            while(arr[selx+j][sely-j]=='_'||arr[selx+j][sely-j]=='p'||arr[selx+j][sely-j]=='e'||arr[selx+j][sely-j]=='c'||arr[selx+j][sely-j]=='h'||arr[selx+j][sely-j]=='k'||arr[selx+j][sely-j]=='q')
            {
                if(selx+j<9&&sely-j>0)
                {
                    posx[i1]=selx+j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx+j][sely-j]=='p'||arr[selx+j][sely-j]=='e'||arr[selx+j][sely-j]=='c'||arr[selx+j][sely-j]=='h'||arr[selx+j][sely-j]=='k'||arr[selx+j][sely-j]=='q')
                    break;
                j++;
            }
            i=1;
            j=1;
            while(arr[selx-i][sely+i]=='_'||arr[selx-i][sely+i]=='p'||arr[selx-i][sely+i]=='e'||arr[selx-i][sely+i]=='c'||arr[selx-i][sely+i]=='h'||arr[selx-i][sely+i]=='k'||arr[selx-i][sely+i]=='q')
            {
                if(selx-i>0&&sely+i<9)
                {
                    posx[i1]=selx-i;
                    posy[i1]=sely+i;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-i][sely+i]=='p'||arr[selx-i][sely+i]=='e'||arr[selx-i][sely+i]=='c'||arr[selx-i][sely+i]=='h'||arr[selx-i][sely+i]=='k'||arr[selx-i][sely+i]=='q')
                    break;
                i++;
            }
            while(arr[selx-j][sely-j]=='_'||arr[selx-j][sely-j]=='p'||arr[selx-j][sely-j]=='e'||arr[selx-j][sely-j]=='c'||arr[selx-j][sely-j]=='h'||arr[selx-j][sely-j]=='k'||arr[selx-j][sely-j]=='q')
            {
                if(sely-j>0&&selx-j>0)
                {
                    posx[i1]=selx-j;
                    posy[i1]=sely-j;
                    yes[i1]=1;
                    i1++;
                }
                if(arr[selx-j][sely-j]=='p'||arr[selx-j][sely-j]=='e'||arr[selx-j][sely-j]=='c'||arr[selx-j][sely-j]=='h'||arr[selx-j][sely-j]=='k'||arr[selx-j][sely-j]=='q')
                    break;
                j++;
            }
        }
        if(k=='K')
        {
            Text T2(400,650,"Black KING Selected");
            wait(0.5);
            int i1=0;
            if(arr[selx+1][sely]=='_'||arr[selx+1][sely]=='p'||arr[selx+1][sely]=='e'||arr[selx+1][sely]=='c'||arr[selx+1][sely]=='h'||arr[selx+1][sely]=='k'||arr[selx+1][sely]=='q')
            {
                posx[i1]=selx+1;
                posy[i1]=sely;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx+1][sely+1]=='_'||arr[selx+1][sely+1]=='p'||arr[selx+1][sely+1]=='e'||arr[selx+1][sely+1]=='c'||arr[selx+1][sely+1]=='h'||arr[selx+1][sely+1]=='k'||arr[selx+1][sely+1]=='q')
            {
                posx[i1]=selx+1;
                posy[i1]=sely+1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx+1][sely-1]=='_'||arr[selx+1][sely-1]=='p'||arr[selx+1][sely-1]=='e'||arr[selx+1][sely-1]=='c'||arr[selx+1][sely-1]=='h'||arr[selx+1][sely-1]=='k'||arr[selx+1][sely-1]=='q')
            {
                posx[i1]=selx+1;
                posy[i1]=sely-1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx][sely+1]=='_'||arr[selx][sely+1]=='p'||arr[selx][sely+1]=='e'||arr[selx][sely+1]=='c'||arr[selx][sely+1]=='h'||arr[selx][sely+1]=='k'||arr[selx][sely+1]=='q')
            {
                posx[i1]=selx;
                posy[i1]=sely+1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx][sely-1]=='_'||arr[selx][sely-1]=='p'||arr[selx][sely-1]=='e'||arr[selx][sely-1]=='c'||arr[selx][sely-1]=='h'||arr[selx][sely-1]=='k'||arr[selx][sely-1]=='q')
            {
                posx[i1]=selx;
                posy[i1]=sely-1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx-1][sely+1]=='_'||arr[selx-1][sely+1]=='p'||arr[selx-1][sely+1]=='e'||arr[selx-1][sely+1]=='c'||arr[selx-1][sely+1]=='h'||arr[selx-1][sely+1]=='k'||arr[selx-1][sely+1]=='q')
            {
                posx[i1]=selx-1;
                posy[i1]=sely+1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx-1][sely-1]=='_'||arr[selx-1][sely-1]=='p'||arr[selx-1][sely-1]=='e'||arr[selx-1][sely-1]=='c'||arr[selx-1][sely-1]=='h'||arr[selx-1][sely-1]=='k'||arr[selx-1][sely-1]=='q')
            {
                posx[i1]=selx-1;
                posy[i1]=sely-1;
                yes[i1]=1;
                i1++;
            }
            if(arr[selx-1][sely]=='_'||arr[selx-1][sely]=='p'||arr[selx-1][sely]=='e'||arr[selx-1][sely]=='c'||arr[selx-1][sely]=='h'||arr[selx-1][sely]=='k'||arr[selx-1][sely]=='q')
            {
                posx[i1]=selx-1;
                posy[i1]=sely;
                yes[i1]=1;
                i1++;
            }
        }
//Display of Possible Moves
        for(i=0; i<30; i++)
        {
            if(yes[i]==1)
                cout<<"("<<posx[i]<<","<<posy[i]<<")";
        }
// Entering of move
        Text T4(200,650,"   Player 2 Move    ");
        w=getClick();
        movex=getI(w%65536);
        movey=getJ(w/65536);
        for(i=0; i<30; i++)
        {
            if(posx[i]==movex&&posy[i]==movey&&yes[i]==1)
            {
                swp=arr[movex][movey];
                arr[movex][movey]=arr[selx][sely];
                arr[selx][sely]='_';
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<"Invalid Input"<<endl;
            Text T2(400,650,"Invalid Input");
            wait(1);
            goto b;
        }

        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                if(arr[i][j]=='K')
                {
                    kx=i;
                    ky=j;
                }
        }
        chk=CHECK(kx,ky,arr,1);
        if(chk>0)
        {
            cout<<"UNSAFE MOVE!"<<endl;
            Text T2(400,650,"   Unsafe Move!   ");
            wait(1);
            arr[selx][sely]=arr[movex][movey];
            arr[movex][movey]=swp;
            goto b;
        }
        Text T5(200,650,"                                  ");
//MOVING OF CHARACTER
        j=movex-selx;
        i=movey-sely;
        n=num[selx][sely];
        {
            if(n==25)
            {
                E1_1.move(65*i,65*j);
                E1_2.move(65*i,65*j);
                E1_3.move(65*i,65*j);
                E1_4.move(65*i,65*j);
            }
            if(n==26)
            {
                H1_1.move(65*i,65*j);
                H1_2.move(65*i,65*j);
                H1_3.move(65*i,65*j);
            }
            if(n==27)
            {
                C1_1.move(65*i,65*j);
                C1_2.move(65*i,65*j);
                C1_3.move(65*i,65*j);
                C1_4.move(65*i,65*j);
            }
            if(n==28)
            {
                K_1.move(65*i,65*j);
                K_2.move(65*i,65*j);
                K_3.move(65*i,65*j);
                K_4.move(65*i,65*j);
            }
            if(n==29)
            {
                Q_1.move(65*i,65*j);
                Q_2.move(65*i,65*j);
                Q_3.move(65*i,65*j);
                Q_4.move(65*i,65*j);
            }
            if(n==30)
            {
                C2_1.move(65*i,65*j);
                C2_2.move(65*i,65*j);
                C2_3.move(65*i,65*j);
                C2_4.move(65*i,65*j);
            }
            if(n==31)
            {
                H2_1.move(65*i,65*j);
                H2_2.move(65*i,65*j);
                H2_3.move(65*i,65*j);
            }
            if(n==32)
            {
                E2_1.move(65*i,65*j);
                E2_2.move(65*i,65*j);
                E2_3.move(65*i,65*j);
                E2_4.move(65*i,65*j);
            }
            if(n==17)
            {
                P1_1.move(65*i,65*j);
                P1_2.move(65*i,65*j);
                P1_3.move(65*i,65*j);
            }
            if(n==18)
            {
                P2_1.move(65*i,65*j);
                P2_2.move(65*i,65*j);
                P2_3.move(65*i,65*j);
            }
            if(n==19)
            {
                P3_1.move(65*i,65*j);
                P3_2.move(65*i,65*j);
                P3_3.move(65*i,65*j);
            }
            if(n==20)
            {
                P4_1.move(65*i,65*j);
                P4_2.move(65*i,65*j);
                P4_3.move(65*i,65*j);
            }
            if(n==21)
            {
                P5_1.move(65*i,65*j);
                P5_2.move(65*i,65*j);
                P5_3.move(65*i,65*j);
            }
            if(n==22)
            {
                P6_1.move(65*i,65*j);
                P6_2.move(65*i,65*j);
                P6_3.move(65*i,65*j);
            }
            if(n==23)
            {
                P7_1.move(65*i,65*j);
                P7_2.move(65*i,65*j);
                P7_3.move(65*i,65*j);
            }
            if(n==24)
            {
                P8_1.move(65*i,65*j);
                P8_2.move(65*i,65*j);
                P8_3.move(65*i,65*j);
            }
        }
//DISAPPEARING OF CHARACTER
        n=num[movex][movey];
        {
            if(n==1)
            {
                e1_1.scale(0.0001);
                e1_2.scale(0.0001);
                e1_3.scale(0.0001);
                e1_4.scale(0.0001);
            }
            if(n==2)
            {
                h1_1.scale(0.0001);
                h1_2.scale(0.0001);
                h1_3.scale(0.0001);
            }
            if(n==3)
            {
                c1_1.scale(0.0001);
                c1_2.scale(0.0001);
                c1_3.scale(0.0001);
                c1_4.scale(0.0001);
            }
            if(n==4)
            {
                k_1.scale(0.0001);
                k_2.scale(0.0001);
                k_3.scale(0.0001);
                k_4.scale(0.0001);
            }
            if(n==5)
            {
                q_1.scale(0.0001);
                q_2.scale(0.0001);
                q_3.scale(0.0001);
                q_4.scale(0.0001);
            }
            if(n==6)
            {
                c2_1.scale(0.0001);
                c2_2.scale(0.0001);
                c2_3.scale(0.0001);
                c2_4.scale(0.0001);
            }
            if(n==7)
            {
                h2_1.scale(0.0001);
                h2_2.scale(0.0001);
                h2_3.scale(0.0001);
            }
            if(n==8)
            {
                e2_1.scale(0.0001);
                e2_2.scale(0.0001);
                e2_3.scale(0.0001);
                e2_4.scale(0.0001);
            }
            if(n==9)
            {
                p1_1.scale(0.0001);
                p1_2.scale(0.0001);
                p1_3.scale(0.0001);
            }
            if(n==10)
            {
                p2_1.scale(0.0001);
                p2_2.scale(0.0001);
                p2_3.scale(0.0001);
            }
            if(n==11)
            {
                p3_1.scale(0.0001);
                p3_2.scale(0.0001);
                p3_3.scale(0.0001);
            }
            if(n==12)
            {
                p4_1.scale(0.0001);
                p4_2.scale(0.0001);
                p4_3.scale(0.0001);
            }
            if(n==13)
            {
                p5_1.scale(0.0001);
                p5_2.scale(0.0001);
                p5_3.scale(0.0001);
            }
            if(n==14)
            {
                p6_1.scale(0.0001);
                p6_2.scale(0.0001);
                p6_3.scale(0.0001);
            }
            if(n==15)
            {
                p7_1.scale(0.0001);
                p7_2.scale(0.0001);
                p7_3.scale(0.0001);
            }
            if(n==16)
            {
                p8_1.scale(0.0001);
                p8_2.scale(0.0001);
                p8_3.scale(0.0001);
            }
        }
        num[movex][movey]=num[selx][sely];
        num[selx][sely]=0;
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                cout<<num[i][j]<<" ";
            cout<<endl;
        }
    }
en:
    if(player==1)
    {
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        cout<<"CHECKMATE...Player2 Wins";
        Text chkmt(300,50,"CHECKMATE....Player 2 WINS!!!");
        wait(10);
    }
    if(player==2)
    {
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        cout<<"CHECKMATE...Player1 Wins";
        Text chkmt(300,680,"CHECKMATE....Player 1 WINS!!!");
        wait(10);
    }
}



