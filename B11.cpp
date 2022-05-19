#include<iostream>
#include<cstring>
using namespace std;
struct node{
    char k[20];
    char m[20];
    node* left;
    node* right;

};
class dict{
    public:
    node* root;
    void create();
    void disp(node* );
    void insertk(node* root,node* temp);
    int searchk(node*,char[]);
    int update(node* ,char[]);
    node* del(node*,char[]);
    node* min(node *);

};
void dict::create(){
    node* temp;
    int ch;
    do{
        temp=new node();
        cout<<"Enter the keyword:";
        cin>>temp->k;
        cout<<"Enter the meaning:";
        cin>>temp->m;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL){
            root=temp;
        }
        else{
            insertk(root,temp);
        }
        cout<<"Do you want to add key(y=1/n=0): ";
        cin>>ch;


    }while(ch==1);
}
void dict::insertk(node* root,node* temp){
    if(strcmp(temp->k,root->k)<0){  //// temp->k < root->k
        if(root->left==NULL){
            root->left=temp;
        }
        else{
            insertk(root->left,temp);
        }
    }
    else{
        if(root->right==NULL){
            root->right=temp;
        }
        else{
            insertk(root->right,temp);
        }
    }

}
void dict::disp(node* root){
    if(root!=NULL){
        disp(root->left);
        cout<<"\n Key word:"<<root->k;
        cout<<"\n Meaning:"<<root->m;
        node* min(node* );
        disp(root->right);
    }
}
int dict::searchk(node* root,char k[20]){
    int c=0;
    while(root!=NULL){
        c++;
        if(strcmp(k,root->k)==0){
            cout<<"\n No of Comparisons:"<<c;
            return 1;
        }
        if(strcmp(k,root->k)<0){
            root=root->left;
        }
        if(strcmp(k,root->k)>0){
            root=root->right;

        }
        
    }
    return -1;
}
int dict::update(node* root,char k[20]){
    while(root!=NULL){
        if(strcmp(k,root->k)==0){
            cout<<"Enter the New Meaning of keyword "<<root->k<<":";
            cin>>root->m;
            return 1;
        }
        if(strcmp(k,root->k)<0){
            root=root->left;
        }
        if(strcmp(k,root->k)>0){
            root=root->right;
        }
        
    }
    return -1;
}
node* dict::del(node* root,char k[20]){
    node* temp;
    if(root==NULL){
        cout<<"\n Element Not found";
        return root;
    }
    if(strcmp(k,root->k)<0){
        root->left=del(root->left,k);
        return root;
    }
    if(strcmp(k,root->k)>0){
        root->right=del(root->right,k);
        return root;
    }
    if(root->right==NULL && root->left==NULL){
        temp=root;
        delete temp;
        return NULL;
    }
    if(root->right==NULL){
        temp=root;
        root=root->left;
        delete temp;
        return root;


    }
    if(root->left==NULL){
        temp=root;
        root=root->right;
        delete temp;
        return root;

    }
    //Node with Two child
    temp=min(root->right);
    strcpy(root->k,temp->k);
    root->right=del(root->right,temp->k);
    return root; 
}
node* dict::min(node* q){
    while(q->left!=NULL){
        q=q->left;

    }
    return q;
}
int main(){
    int ch;
    dict d;
    d.root=NULL;
    do{
        cout<<"\n Menu \n 1.Create \n 2.Display \n 3.Search\n 4.Update\n 5 Delete \n Enter ur ch:";
        cin>>ch;
        switch(ch){
            case 1:d.create();
                  break;
            case 2:if(d.root==NULL){
                cout<<"\N No any keyword";
            }else{
                d.disp(d.root);
            }
            break;
            case 3:if(d.root==NULL){
                cout<<"\n Dictionary is Empty .First add keywords then try again ";
            }else{
                cout<<"\n Enter Keyword which u want to search:";
                char k[20];
                cin>>k;
                if(d.searchk(d.root,k)==1){
                    cout<<"\n Keyword Found";
                }
                else{
                    cout<<"\n Keyword Not Found";
                }
            break;
            case 4:
               if(d.root==NULL){
                   cout<<"\n Dictionary is Empty.First add keywords then try again";
               }
               else{
                   cout<<"\n Enter keyword which meaning want to update:";
                   char k[20];
                   cin>>k;
                   if(d.update(d.root,k)==1){
                       cout<<"Meaning Updated";
                   }
                   else{
                       cout<<"\n Meaning not Found";
                   }
                   
               }
               break;
            case 5:
              if(d.root==NULL){
                  cout<<"\n Dictionary is Empty .First add keywords then try again";
              }
              else{
                  cout<<"\n Enter keyword which u want to delete:";
                  char k[20];
                  cin>>k;
                  if(d.root==NULL){
                      cout<<"\n No any keyword";
                  }    
                  else{
                      d.root=d.del(d.root,k);
                  }          

            }
        }
    }
    while(ch<=5);
    return 0;

}
