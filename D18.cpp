#include<iostream>
#include<algorithm>
using namespace std;
#define size 20
class OBST{

    public:
    int n;
    int p[size];
    int q[size];
    int a[size];
    int w[size][size];
    int r[size][size];
    int c[size][size];
    void get_data();
    int min_val(int i,int j);
    void build_tree();
    void build_obst(); 
} ;

void OBST::get_data(){

    cout<<"Enter no of nodes"<<endl;
    cin>>n;

    cout<<"Enter key values of data"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<"a["<<i<<"] :";
        cin>>a[i];
    }

    cout<<"Enter the probalility of the found keys"<<endl;
    for (int i = 1; i <=n; i++)
    {
        cout<<"p["<<i<<"] :";
        cin>>p[i];
    }
    
    cout<<"Enter the probalility of the not found "<<endl;
    for (int i = 0; i <=n; i++)
    {
        cout<<"q["<<i<<"] :";
        cin>>q[i];
    }
    
}

int OBST:: min_val(int i,int j){

    int min=9999;
    int k;
    for (int m = r[i][j-1]; m <= r[i+1][j]; m++)
    {
        if(c[i][m-1]+c[m][j]<min){
            min=c[i][m-1]+c[m][j];
            k=m;
        }
    }
    return k;
    
}

void OBST::build_tree(){

    for (int i = 0; i < n; i++)
    {
        w[i][i]=q[i];
        r[i][i]=c[i][i]=0;
        
        //second row
        w[i][i+1]=q[i]+q[i+1]+p[i+1];
        c[i][i+1]=q[i]+q[i+1]+p[i+1];
        r[i][i+1]=i+1;
    }

    w[n][n]=q[n];
    r[n][n]=c[n][n]=0;

    int k;

    for (int m =2; m <= n; m++)
    {
        for (int i = 0; i <= n-m; i++)
        {
            int j=i+m;
            w[i][j]=w[i][j-1]+q[i]+p[i];
            // 
            k=min_val(i,j);
            c[i][j]=c[i][k-1]+c[k][j]+w[i][j];
            r[i][j]=k;
        }
        
    }
    
}

void OBST::build_obst(){

    int queue[size];
    int front=-1;
    int rear=-1;
    q[rear++]=0;
    q[rear++]=n;
    int i,j,k;

    while (front!=rear)
    {
        i=q[front++];
        j=q[front++];

        k=r[i][j];
        cout<<a[k];
        if(c[i][k-1]!=0){
            cout<<"\t"<<a[r[i][k-1]];
            q[rear++]=i;
            q[rear++]=k-1;
        }
        else{
            cout<<"\t";
        }
        if(c[k][j]!=0){
            cout<<"\t"<<a[r[k][j]];
            q[rear++]=k;
            q[rear++]=j;
        }
        else{
            cout<<"\t";
        }
        cout<<endl;
    }
    

}
int main(){
     
    OBST h;
    h.get_data();
    h.build_tree();
    h.build_obst();
    return 0;

}
