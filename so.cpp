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
    printf("��������Ŀ������");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        printf("%d.\n",i);

   loop:a=rand()%100;
        b=rand()%100;
        c=rand()%100;
        m=rand()%4;
        n=rand()%4;
        //printf("aΪ%d\n",a);
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
                //printf("aΪ0\n");
                a=rand()%100;
                //printf("����a=%d\n",a);
            //v=(float)a/b;
            break;
        }
        //printf("aΪ%d\n",a);
                //printf("bΪ%d\n",b);
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
                //printf("qΪ%.2f\n",q);}
                else if(x=='-')
                {q=a-b;}
                //printf("qΪ%.2f\n",q);}
                else if(x=='*')
                {q=a*b;}
                //printf("qΪ%.2f\n",q);}
                if(q==0)
                {
                    a=rand()%100;
                    b=rand()%100;
                }
            }while(q==0);
            //q=q/c;
            break;
        }
        //printf("����aΪ%d\n",a);
                    //printf("����bΪ%d\n",b);
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
        //�Ⱥ�����˳��
        //��һ�����㲻��Ϊ�� ��һ�������������� ֻ������Ż�Ϊ�� ��һ�������Ǽ���ʱһ����˳���
        //���岻��?

        /*if(x=='-'||y=='-')
        {
            q=0;
            //printf("��֤ǰa=%d");
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
            //printf("���Ϊ�� �������\n");
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
    printf("�ο��𰸣�\n");
    for(i=1;i<=num;i++)
    {
        printf("%d.\n",i);
        printf("%d %c %d %c %d = ",formula[i][0],formula[i][1],formula[i][2],formula[i][3],formula[i][4]);
        printf("%.2f\n",result[i]);
    }
    //printf("%d",rand()%100);
}
