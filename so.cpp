#include<stdio.h>
//#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i=1;
    int num,a,b,c,m,n;
    float p,q,r,v,w;
    char x,y;
    float result[100];
    char formula[100][5];
    srand((int)time(0));
    printf("请输入题目数量：");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        printf("%d.\n",i);

   loop:a=rand()%100;
        b=rand()%100;
        c=rand()%100;
        m=rand()%4;
        n=rand()%4;
        //printf("a为%d\n",a);
        //a=0;
        //m=3;
        //m=2;
        //b=0;
        //n=3;
        switch(m)
        {
        case 0:
            x='+';
            //p=a+b;
            break;
        case 1:
            x='-';
            //p=a-b;
            break;
        case 2:
            x='*';
            //v=a*b;
            break;
        case 3:
            x='/';
            if(a==0)
                //printf("a为0\n");
                a=rand()%100;
                //printf("现在a=%d\n",a);
            //v=(float)a/b;
            break;
        }
        //printf("a为%d\n",a);
                //printf("b为%d\n",b);
        switch(n)
        {
        case 0:
            y='+';
            //q=p+c;
            break;
        case 1:
            y='-';
            //q=p-c;
            break;
        case 2:
            y='*';
            //q=q*c;
            break;
        case 3:
            y='/';
            do
            {
                if(x=='+')
                {q=a+b;}
                //printf("q为%.2f\n",q);}
                else if(x=='-')
                {q=a-b;}
                //printf("q为%.2f\n",q);}
                else if(x=='*')
                {q=a*b;}
                //printf("q为%.2f\n",q);}
                if(q==0)
                {
                    a=rand()%100;
                    b=rand()%100;
                }
            }while(q==0);
            //q=q/c;
            break;
        }
        //printf("现在a为%d\n",a);
                    //printf("现在b为%d\n",b);
        //do while p>=0
        /*do
        {
            switch(x)
            {
            case '*':
                p=a*b;
                break;
            case '/':
                p=a/b;
                break;
            case '+':
            case '/':
                if(y=='*')
                    p=b*c;
                if(y=='/')
                    p=b/c;
                break;
            }

        }while(p<0);*/
        //先后运算顺序
        //第一次运算不能为负 第一次两个都是正数 只有相减才会为负 第一次运算是减法时一定是顺序的
        //意义不大?

        /*if(x=='-'||y=='-')
        {
            q=0;
            //printf("验证前a=%d");
            do
            {
                if(y=='+')
                {p=a-b;}
                //if(y=='-')
                //{p=a-b-c;}
                if(y=='*')
                {p=a-(b*c);}
                if(y=='/');
                {p=a-(b/c);}

                if(x=='+')
                {p=a+b-c;}
                if(x=='-'&&y=='-')
                {
                    q=a-b;
                    p=q-c;
                }
                if(x=='*')
                {p=a-(b*c);}
                if(x=='/')
                {p=a-((float)b/c);}

                if(p<0||q<0)
                {
                    a=rand()%100;
                    b=rand()%100;
                    c=rand()%100;
                }
            }while(p<0||q<0);
        }*/




        switch(x)
            {
            case '*':
                v=a*b;
                break;
            case '/':
                v=(float)a/b;
                break;
            case '+':
                if(y!='*'&&y!='/')
                {v=a+b;}
                break;
            case '-':
                //if(y=='*')
                //    v=b*c;
                //if(y=='/')
                //    v=b/c;
                if(y!='*'&&y!='/')
                {v=a-b;}
                break;
            }
        switch(y)
        {
        case '+':
            w=v+c;
            break;
        case '-':
            w=v-c;
            break;
        case '*':
            if(x=='+')
            {w=a+(b*c);}
            else if(x=='-')
            {w=a-(b*c);}
            else
            {w=v*c;}
            break;
        case '/':
            if(x=='+')
            {w=a+((float)b/c);}
            else if(x=='-')
            {w=a-((float)b/c);}
            else
            {w=v/c;}
        }
        if(w<0)
        {
            //printf("结果为负 重新随机\n");
            goto loop;
        }
        result[i]=w;
        formula[i][0]=a;
        formula[i][1]=x;
        formula[i][2]=b;
        formula[i][3]=y;
        formula[i][4]=c;
        printf("%d %c %d %c %d = \n\n",a,x,b,y,c);//%.2f w
        //printf("%.2f\n\n",result[i]);
    }

    printf("\n-------------\n");
    printf("参考答案：\n");
    for(i=1;i<=num;i++)
    {
        printf("%d.\n",i);
        printf("%d %c %d %c %d = ",formula[i][0],formula[i][1],formula[i][2],formula[i][3],formula[i][4]);
        printf("%.2f\n",result[i]);
    }
    //printf("%d",rand()%100);
}
