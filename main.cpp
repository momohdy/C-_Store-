#include <iostream>

using namespace std;

class item {
    public :
        int ID ;
        string Name ;
        float Price ;
        int Quantity ;
        item *next;
};
item *top ;

void Push(int I , string N , float P, int Q)
{
    item *p = new item() ;
    p->ID = I ;
    p->Name = N ;
    p->Price = P ;
    p->Quantity = Q ;
    p->next = top  ;
    top = p ;
    cout<<"ITEM ADDED SUCCESSFULLY"<<endl;
}

bool isEmpty(){
    return top==NULL ;
}

void Pop()
{
    if(isEmpty()){
        cout<<"COULDN'T DELETE BEACAUSE LIST OF ITEMS IS EMPTY"<<endl;
    }
    else{
        item *p = top ;
        top = top->next;
        delete(p);
        cout<<"ITEM DELETED"<<endl;
    }
}



void Display()
{
    if(isEmpty()){
        cout<<"COULDN'T DISPLAY BEACAUSE LIST OF ITEMS IS EMPTY"<<endl;
    }
    else{
        item *p = top ;
        while(p!=NULL){
            cout<<"ID = "<<p->ID;
            cout<<" , NAME = "<<p->Name;
            cout<<" , PRICE = "<<p->Price;
            cout<<" , QUANTITY = "<<p->Quantity<<endl;
            p = p->next ;
        }
    }
}

void Search(int I)
{
    if(isEmpty()){
        cout<<"COULDN'T SEARCH BEACAUSE LIST OF ITEMS IS EMPTY"<<endl;
    }
    else{
        item *p = top ;
        while(p!=NULL){
            if(p->ID == I){
                cout<<p->Name<<" ITEM"<<endl;
                cout<<"ID = "<<p->ID;
                cout<<" , NAME = "<<p->Name;
                cout<<" , PRICE = "<<p->Price;
                cout<<" , QUANTITY = "<<p->Quantity<<endl;
                break;
            }
            if(p->next==NULL){
                cout<<"ITEM NOT FOUND"<<endl;
                break;
            }else{
                p = p->next ;
            }
        }
    }
}


int main()
{
    int choose ,I , Q ; string N ; float P ;

    while(1){
        cout<<"1- ADD NEW ITEM "<<endl;
        cout<<"2- DELETE ITEM "<<endl;
        cout<<"3- DISPLAY ITEMS "<<endl;
        cout<<"4- SEARCH ITEM "<<endl;
        cout<<"ENTER YOUR CHOOSE : "; cin>>choose;
        cout<<endl;
        switch(choose){
            case 1 :
                cout<<"ENTER ITEM ID : " ; cin>>I;
                cout<<"ENTER ITEM NAME : " ; cin>>N;
                cout<<"ENTER ITEM PRICE : " ; cin>>P;
                cout<<"ENTER ITEM QUANTITY : " ; cin>>Q;
                cout<<endl;
                Push(I,N,P,Q);
                break ;
            case 2 :
                Pop();
                break ;
            case 3 :
                Display();
                break ;
            case 4 :
                cout<<"ENTER ITEM ID : " ; cin>>I;
                cout<<endl;
                Search(I);
                break ;
        }
    cout<<endl<<"//\n"<<endl;
    }

    return 0;
}
