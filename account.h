
class Account{
    private: char name[20]; long balance; int acno;
    public:
        void read();
        void show();
        void show2(){cout<<endl<<setw(10)<<acno<<setw(20)<<name<<setw(10)<<balance;}
        void withdraw();
        void deposit();
        void setbalance(long b){balance=b;}
        long getbalance(){return balance;}
        void setname(char n[]){strcpy(name,n);}
        char* getName(){return name;}
        int getAcno(){return acno;}

};
void Account::read(){
cout<<"Enter account number: "; cin>>acno; cin.ignore();
cout<<"Enter name: "; cin.getline(name,20);
cout<<"Enter Balance: "; cin>>balance;
}
void Account::show(){
cout<<"\nAcno. "<<acno<<"\nName "<<name<<"\nbalance "<<balance;
}
void Account::deposit(){
long amount;
begin: cout<<"Enter amount to deposit: "; cin>>amount;
 if(amount<100||amount>49999L){
    cout<<"Invalid amount try again...";
    goto begin;
 }
 balance=balance+amount;
}
void Account::withdraw(){
long amount;
begin:
    cout<<"Enter amount to withdraw: "; cin>>amount;
    if(amount>balance||amount<100||amount>49999L){
        cout<<"invalid amount, try again...";
        goto begin;
    }
    balance=balance-amount;
}

