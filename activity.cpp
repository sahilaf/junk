#include<bits/stdc++.h>
using namespace std;
struct Activity{
    int s,e;
};

bool compare(Activity a1,Activity a2){
    return a1.e<a2.e;
}

void Activity_Selection(Activity a[],int n){
    sort(a,a+n,compare);

    Activity k=a[0];
    cout<<"Activity 1:"<<"  "<<k.s<<"   "<<k.e<<endl;

    for(int i=1;i<n;i++){
        if(a[i].s>=k.e){
            cout<<"Activity "<<i+1<<": "<<"  "<<a[i].s<<"   "<<a[i].e<<endl;
            k=a[i];
        }
    }
}


struct Item{
    float weight,price,price_per_kg;
};

bool compare(Item i1,Item i2){
    return i1.price_per_kg>i2.price_per_kg;
}

float frac_knap(Item a[],int n,float maxCapacity){
    sort(a,a+n,compare);
    float remWeight=maxCapacity,profitValue=0.0;

    for(int i=0;i<n;i++){
        if(remWeight>=a[i].weight){
            profitValue+=a[i].price;
            remWeight-=a[i].weight;
        }
        else{
            profitValue+=(remWeight*a[i].price_per_kg);
            break;
        }
    }
    return profitValue;

}