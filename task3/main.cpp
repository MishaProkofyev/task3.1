#include <iostream>
#include <cmath>
using namespace std;
struct spisok
{
    int deg;
    int c;
    spisok *next;
};
spisok *A=NULL;

void push(spisok* &sp)
{
    int x,y;
    cout << "vvedite stepen"<<endl;
    cin >> x;
    cout << "vvedite coefficient"<<endl;
    cin >> y;
    spisok *tmp= new spisok;
    tmp->deg=x;
    tmp->c=y;
    tmp->next=sp;
    sp=tmp;
}
void write(spisok *sp)
{
    if(sp->c<0) cout<<"-";
    while(sp!=NULL)
    {
        if(sp->next!=NULL&&abs(sp->c)!=1)
        {
            if(sp->deg==0&&sp->next->c>0)cout<< abs(sp->c)<<"+";
            if(sp->deg==0&&sp->next->c<0)cout<< abs(sp->c)<<"-";
            if(sp->deg==1&&sp->next->c>0)cout<< abs(sp->c)<<"x+";
            if(sp->deg==1&&sp->next->c<0)cout<< abs(sp->c)<<"x-";
            if(sp->deg>1&&sp->next->c>0)cout<< abs(sp->c)<<"x^"<<sp->deg<<"+";
            if(sp->deg>1&&sp->next->c<0)cout<< abs(sp->c)<<"x^"<<sp->deg<<"-";
        }
        if(sp->next!=NULL&&abs(sp->c)==1)
        {
            if(sp->deg==0&&sp->next->c>0)cout<< abs(sp->c)<<"+";
            if(sp->deg==0&&sp->next->c<0)cout<< abs(sp->c)<<"-";
            if(sp->deg==1&&sp->next->c>0)cout<< "x+";
            if(sp->deg==1&&sp->next->c<0)cout<< "x-";
            if(sp->deg>1&&sp->next->c>0)cout<< "x^"<<sp->deg<<"+";
            if(sp->deg>1&&sp->next->c<0)cout<< "x^"<<sp->deg<<"-";
        }
        if(sp->next==NULL&&abs(sp->c)!=1)
        {
            if(sp->deg==0)cout<< abs(sp->c);
            if(sp->deg==1)cout<< abs(sp->c)<<"x";
            if(sp->deg>1)cout<< abs(sp->c)<<"x^"<<sp->deg;
        }
        if(sp->next==NULL&&abs(sp->c)==1)
        {
            if(sp->deg==0)cout<< abs(sp->c);
            if(sp->deg==1)cout<< "x";
            if(sp->deg>1)cout<< "x^"<<sp->deg;
        }
        sp=sp->next;
    }
    cout<<endl;

}
int power(int x,int deg)
{
    int i,t;
    t=x;
    for(i=1; i<deg; i++) x=x*t;
    if(deg>0)return x;
    else
        return 1;
}

void value(spisok *sp)
{
    int x,v=0;
    cout << "vvedite znachenie"<<endl;
    cin >> x;
    while(sp!=NULL)
    {
        v=v+sp->c*power(x,sp->deg);
        sp=sp->next;

    }
    cout<<"znachenie v tochke:"<<v<<endl;
}

void menu(int a)
{
    int x,y;

    switch(a)
    {
    case 1:
        push(A);
        break;
    case 2:
        write(A);
        break;
    case 3:
        value(A);
        break;

    }
    cin >>a;
    if(a==0)return;
    else
        menu(a);


}
int main()
{
    int b;
    cin >> b;
    menu(b);
    return 0;
}
