//
//  main.cpp
//  text610
//
//  Created by s20181105880 on 2019/6/12.
//  Copyright © 2019 s20181105880. All rights reserved.
//



#include<iostream>
#include<string>
using namespace std;
class Pet{
protected:
    string name;
    int length;
    int weight;
    int current;
public:
    Pet(){
        name="";
        length=0;
        weight=0;
        current=0;
    }
    virtual void display(int day)=0;
};
class Cat:public Pet{
public:
    Cat(string n,int l,int w,int c){
        name=n;
        length=l;
        weight=w;
        current=c;
    }
    void display(int day){
        cout<<name<<" "<<length+day-current<<" "<<weight+(day-current)*2<<endl;
    }
};
class Dog:public Pet{
public:
    Dog(string n,int l,int w,int c){
        name=n;
        length=l;
        weight=w;
        current=c;
    }
    void display(int day){
        cout<<name<<" "<<length+(day-current)*2<<" "<<weight+day-current<<endl;
    }
};
int main(){
    string name;
    Pet *p[10];
    int length,weight,current,day,x,count=0,i;
    while(1){
        cin>>x;
        if(x>10){
            for(i=0;i<count;i++)
                p[i]->display(x);
            break;
        }
        cin>>name>>length>>weight>>current;
        if(x==1)
            p[count]=new Cat(name,length,weight,current);
        else
            p[count]=new Dog(name,length,weight,current);
        count++;
    }
}
