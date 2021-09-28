#include <iostream>
using namespace std;

class Term{
    public:
        int coef;
        int exp;
};

class Poly{
    public:
        int n;
        class Term *terms;
};

void create(class Poly *p){
    int i;
    cout<<"Number of terms?";
    cin>>p->n;
    p->terms=new Term[p->n];

    cout<<"Enter terms\n";
    for(i=0;i<p->n;i++)
        cin>>p->terms[i].coef>>p->terms[i].exp;
}

void display(class Poly p){
    int i;
    for(i=0;i<p.n;i++)
        cout<<p.terms[i].coef<<"x"<<p.terms[i].exp<<"+";
    cout<<"\n";
}

class Poly *add(class Poly *p1,class Poly *p2){
    int i,j,k;
    class Poly *sum;

    sum=new Poly;
    sum->terms=(class Term *)malloc((p1->n+p2->n)*sizeof(class Term));
    i=j=k=0;

    while(i<p1->n && j<p2->n){
        if(p1->terms[i].exp>p2->terms[j].exp)
            sum->terms[k++]=p1->terms[i++];
        else if(p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++]=p2->terms[j++];
        else{
            sum->terms[k].exp=p1->terms[i].exp;
            sum->terms[k++].coef=p1->terms[i++].coef+p2->terms[j++].coef;
        }
    }
    
    for(;i<p1->n;i++)
        sum->terms[k++]=p1->terms[i];

    for(;j<p2->n;j++)
        sum->terms[k++]=p2->terms[j];

    sum->n=k;
    return sum;
}

int main(){
    class Poly p1,p2,*p3;

    create(&p1);
    create(&p2);

    p3=add(&p1,&p2);

    cout<<"\n";
    display(p1);
    cout<<"\n";
    display(p2);
    cout<<"\n";
    display(*p3);

    return 0;
}