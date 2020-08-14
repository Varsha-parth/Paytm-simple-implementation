#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<ctime>
#include<fstream>
#include <string>
using namespace std;

class login
{
protected:

        time_t now;
        char* dt;
        long long phoneNo;
        string  name;
        long int bal;
        int accNum;
        int pin;
        int walMoney;
public:
    login()
    {
        now = time(0);
        dt = ctime(&now);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void sign_up()
    {
           label1:cout<<"\nEnter your name:";
            cin>>name;
            label:cout<<"\nEnter your 4 digit pin:";
            int i=0,l;
            char p[5];
            p[i]=getch();
            if (!(p[i]>='1' && p[i]<='9'))
            {
                cout<<"\nEnter a valid pin.(NOTE:Pin must not start 0)\nEnter any key to retry";
                goto label;

            }
            while(p[i]!=13)
            {
                cout<<"*";
                i++;
                p[i]=getch();
                if(p[i]==13)
                {
                    --i;
                    l=i+1;
                    break;
                }
                else if (!(p[i]>='0' && p[i]<='9'))
                {
                    cout<<"\nEnter a valid pin.Pin must always be a number\nEnter any key to retry";
                    goto label;
                }
                l=i;

            }
            p[l]='\0';
            cout<<endl;
            if(l!=4)
            {
                cout<<"\nPin size is incorrect.\n\n";
                goto label;
            }
            pin=atoi(p);
            scanf("%*c");
            ph:cout<<"\nEnter your 10 digit phone number:";
            cin>>phoneNo;
            long long n=phoneNo;
            int digit = 0;
            while (n != 0)
            {
                n = n / 10;
                ++digit;
            }
            if(digit!=10)
            {
                 cout<<"\nIncorrect Phone Number.\n:";
                 goto ph;
            }
            cout<<"\nEnter your bank account number:";
            cin>>accNum;
            cout<<"\nPress Enter key";
            getch();
            system("CLS");
            int m;
            m=check();
            if(m==1)
            {
                cout<<"\nSuccessfully signed in\n";
                cout<<"\nPress any key\n";
                getch();
                Bankdetails();
            }
            else
            {
                int f;
                 cout<<"\nThis phone number has already been signed up.\nPress 0 to exit and 1 to retry\n";
                 cin>>f;
                 if(f==0)
                    exit(0);
                 else
                 {
                     system("CLS");
                     goto label1;
                 }
            }
            getch();
            system("CLS");
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Bankdetails()
    {
        int i=0,l;
        system("CLS");
        int acc;
        char password[10];
        l:cout<<"\n\t\t\t\tBank Details\n";
        cout<<"\nEnter your account number:";
        cin>>acc;
        label:cout<<"\nEnter your 4 digit pin:";
        i=0;
        password[i]=getch();
        if (!(password[i]>='1' && password[i]<='9'))
        {
            cout<<"\nEnter a valid pin.(NOTE:Pin must not start 0)\nEnter any key to retry";
            goto label;
        }
        while(password[i]!=13)
        {
            cout<<"*";
            i++;
            password[i]=getch();
            if(password[i]==13)
            {
                --i;
                l=i+1;
                break;
            }
            else if (!(password[i]>='0' && password[i]<='9'))
            {
                cout<<"\nEnter a valid pin.Pin must be a number\nEnter any key to retry";
                goto label;
            }
            l=i;
        }
        password[l]='\0';
        cout<<endl;
        if(l!=4)
        {
            cout<<"\n\nPin size is incorrect.\n\n";
            goto label;
        }
        int p=atoi(password);
        cout<<"\nPress any key\n";
        getch();
        if(accNum!=acc || p!=pin)
        {
            cout<<"\nAuthorization failed. \nPress any key to retry";
            getch();
            system("CLS");
            goto l;

        }
        system("CLS");
        cout<<"\n\t\t\t\t~~BANK GATEWAY~~\n\n\t\tEnter your bank balance:";
        cin>>bal;
        l3:cout<<"\nEnter the amount that you want to transfer to your wallet:";
        cin>>walMoney;
        if(walMoney<bal)
            bal-=walMoney;
        else
        {
            cout<<"\nInsufficient balance.Enter a smaller amount\n";
            goto l3;
        }
        cout<<"\nPress any key\n";
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void logging_in()
    {
        l2:long long phn;
        d1:cout<<"\nEnter your Phone Number:";
        cin>>phn;
        int d=floor(log10(phn)+1);
        if(d!=10)
        {
            cout<<"\nINVALID PHONE NUMBER\n";
            goto d1;
        }
        l1:cout<<"\nEnter your 4 digit pin:";
        int i=0;
        char ppin[15];
        ppin[i]=getch();
        if (!(ppin[i]>='1' && ppin[i]<='9'))
        {
            cout<<"\nEnter a valid pin.(NOTE:Pin must not start 0)\nEnter any key to retry";
            goto l1;
        }
        while(ppin[i]!=13)
        {
            cout<<"*";
            i++;
            ppin[i]=getch();
            if(ppin[i]==13)
            {
                --i;
                break;
            }
            else if (!(ppin[i]>='0' && ppin[i]<='9'))
            {
                cout<<"\nEnter a valid pin.Pin must be an integer.\nEnter any key to retry";
                goto l1;
            }
        }
        ppin[i+1]='\0';
        int p;
        p=atoi(ppin);
        int counts=check(phn,p);
        if(counts==1)
        {
             cout<<"\n\t\t\tSuccessfully logged in\n\nPress any key to continue\n";
             getch();
        }
        else
        {
            char f;
            cout<<"\nIncorrect name or pin";
            cout<<"\nPress 0 to exit.Press any other key to retry\n";
            f=getch();
            if(f=='0')
                exit(0);
            else
            {
                system("CLS");
                goto l2;
            }

        }
    }
    int check()
    {
        ifstream r;
        int flag;
        r.open("Name_doc.txt");
        if(!r)
        {
            flag=1;
            return 1;
        }
        else
        {
            while(!r.eof())
            {
                long long num=0;
                char ch;
                ch=r.get();
                while(ch!='/')
                {
                      if(ch==EOF)
                        break;
                     ch=r.get();
                }
                int c=1;
                cout<<endl;
                while(c<=10)
                {
                    ch=r.get();
                    if(c==1)
                         num=ch-'0';
                    else if(ch==10)
                        num+=(ch-'0');
                    else
                    {
                        num*=10;
                        num=num+(ch-'0');
                    }
                    c++;
                    if(ch==EOF)
                        break;
                }
                if(ch==EOF)
                    break;
                if(num==phoneNo)
                 {
                     flag=1;
                     return 0;
                 }
            }
        }
        if(flag!=1)
            return 1;
    }
    int check(long long phn,int pswd)
    {
        ifstream p;
        long long fphone;
        p.open("UserInfo2.dat",ios::in|ios::binary);
        if(!p)
            return 0;
        int i=0,fipin;
        char ch,fpin[10];
        while(!p.eof())
        {
            ch=p.get();
            if(ch==EOF)
                return 0;
            while(ch!='/')
            {
                int c=1;
                while(c<=10)
                {
                    if(c==1)
                         fphone=ch-'0';
                    else if(ch==10)
                        fphone+=(ch-'0');
                    else
                    {
                        fphone*=10;
                        fphone=fphone+(ch-'0');
                    }
                    c++;
                    ch=p.get();
                    if(ch==EOF)
                        break;
                }
            }
            if(fphone==phn)
            {
                i=0;
                ch=p.get();
                while(ch!='/')
                {
                   fpin[i]=ch;
                   i++;
                   ch=p.get();
                }
                fpin[i]='\0';
                i=0;
                fipin=atoi(fpin);
                if(fipin==pswd)
                {
                    pin=pswd;
                    phoneNo=phn;
                    ch=p.get();
                    i=0;
                    char temp[25];
                    while(ch!='/')
                    {
                        temp[i]=ch;
                        temp[i+1]='\0';
                        ch=p.get();
                        i++;
                    }
                    accNum=atoi(temp);
                    ch=p.get();
                    i=0;
                    while(ch!='/')
                    {
                        temp[i]=ch;
                        temp[i+1]='\0';
                        i++;
                        ch=p.get();
                    }
                    bal=atoi(temp);
                    ch=p.get();
                    i=0;
                    while(ch!='/')
                    {
                        temp[i]=ch;
                        temp[i+1]='\0';
                        i++;
                        ch=p.get();
                    }
                    walMoney=atoi(temp);
                    return 1;
                }
                else
                     return 0;
            }
            else
            {
                while(ch!='\n' && ch!=EOF)
                {
                    if(ch==EOF)
                        return 0;
                    ch=p.get();
                    if(ch==EOF)
                        return 0;
                }
                if(ch==EOF)
                    return 0;
            }
            if(ch==EOF)
                return 0;
        }

    }
    void Write()
    {
        ofstream w,t;
        w.open("UserInfo2.dat",ios::app|ios::binary);
        w<<phoneNo<<'/';
        w<<pin<<'/';
        w<<accNum<<'/';
        w<<bal<<'/';
        w<<walMoney<<'/';
        w<<'\n';
        w.close();
        t.open("Name_doc.txt",ios::app);
        t<<name<<'/';
        t<<phoneNo;
        t<<'\n';
        t.close();
    }


};



class Wallet:public login
{
    char id[10];
public:
    void options()
    {
        system("CLS");
        int choice;
        cout<<"\nEnter  your choice:\n1.Add Money to your wallet\n2.transfer money\n3.View Wallet\n4.View Transaction History\n5.Log out\n";
        cin>>choice;
        switch(choice)
        {
            case 1: addMoney();
                    break;
            case 2: transfer();
                    break;
            case 3: viewwallet();
                    break;
            case 4: viewtrans();
                    break;
            default: exit(0);
                    break;
        }
    }

    void addMoney()
    {
        int i=0,cash;
        system("CLS");
        cout<<"\nEnter the money to add to wallet:";
        cin>>cash;
        ofstream transfile;
        transfile.open("Transaction.txt",ios::app);
//        uniqueID();
        if(cash<bal)
        {
            bal-=cash;
            walMoney+=cash;
            transfile<<phoneNo<<" - "<<id<<" - "<<cash<<" added to wallet at "<<dt;
            cout<<"\nWallet:"<<walMoney<<endl;
        }
        else
        {
            cout<<"\nInsufficient Bank Balance";
            transfile<<phoneNo<<" - "<<id<<" - "<<cash<<" transaction failed at "<<dt;
        }
        transfile.close();
        cout<<"\nPress any key\n";
        getch();
        options();
    }
    void transfer()
    {
        system("CLS");
        long long phone;
        int money;
//        uniqueID();
        cout<<"\nEnter the phone number to whom you want to transfer :";
        cin>>phone;
        cout<<"\nEnter the amount that you want to transfer";
        cin>>money;
        int flag=0;
        if(flag==0)
            cout<<"\nPhone number not enrolled in PayTM\n";
        else
        {
            ofstream transfile;
            transfile.open("Transaction.txt",ios::app);
            if(walMoney>money)
            {
                walMoney-=money;
                //add money in his wallet
                transfile<<id<<" - "<<phoneNo<<" - "<<money<<" transfered to "<<phone<<" at "<<dt;
                transfile<<id<<" - "<<phone<<" - "<<money<<" transfered from "<<phoneNo<<" at "<<dt;
                cout<<"\nWALLET BALANCE:"<<walMoney<<endl;
            }
            else
            {
                cout<<"\nInsufficient Balance in wallet\n";
                transfile<<id<<" - "<<phoneNo<<" - "<<money<<" transaction failed at "<<dt;
            }
            transfile.close();
        }
        cout<<"\nPress any key \n";
        getch();
        options();
    }
    void viewwallet()
    {
        system("cls");
        cout<<"\nWallet Money:"<<walMoney<<endl;
        cout<<"\nPress any key \n";
        getch();
        options();
    }
    void viewtrans()
    {
        system("cls");
        long long phone;
        cout<<"TRANSCATION HISTORY"<<endl;
        ifstream transf;
        transf.open("Transaction.txt");
        char ch;
        ch=transf.get();
        int flag=0;
        while(ch!=EOF)
        {
            while(ch!='-')
            {
                int c=1;
                while(c<=10)
                {
                    if(c==1)
                         phone=ch-'0';
                    else if(ch==10)
                        phone+=(ch-'0');
                    else
                    {
                        phone*=10;
                        phone=phone+(ch-'0');
                    }
                    c++;
                    ch=transf.get();
                    if(ch==EOF)
                        break;
                }
            }
            if(phone==phoneNo)
            {
                flag++;
                cout<<endl;
                while(ch!='\n' && ch!=EOF)
                {
                    cout<<ch;
                    ch=transf.get();
                }
                if(ch==EOF)
                    break;
            }
            else
            {
                while(ch!='\n')
                {
                    ch=transf.get();
                    if(ch==EOF)
                        break;
                }

                if(ch==EOF)
                    break;
            }
            if(ch=='\n')
            {
                phone=0;
                ch=transf.get();
            }
        }
        if(flag==0)
        cout<<"No transactions yet";
        transf.close();
        cout<<"\nPress any key \n";
        getch();
        options();

    }

};
int main()
{
    Wallet l;
    int choice;
   //do
   //{

        system("CLS");
        cout<<"\n\t\t\tPAYTM\n";
        cout<<"\t\t1.Sign-Up\n\t\t2.Logging in\n\t\t3.Exit\n\t\t";
        cin>>choice;
        switch(choice)
        {
            case 1:
                    l.sign_up();
                    l.Write();
                    l.options();
                    break;
            case 2:
                    l.logging_in();
                    l.options();
                    break;
            default:
                    exit(0);
        }

       //}while(choice<3);
    return 0;
}
