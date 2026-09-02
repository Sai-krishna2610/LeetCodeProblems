#include<iostream>
using namespace std;
int main()
{
    //pattern1
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 1 -----------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }



    //Patern 2
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 2 -----------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }



    //patern 3
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 3-----------------------"<<endl;
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }



    //patern 4
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 4 -----------------------"<<endl;
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }



    //pattern 5
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 5 -----------------------"<<endl;
    for(int i=5;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }



    //pattern 6
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 6 -----------------------"<<endl;
    for(int i=5;i>=0;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        cout<<endl;
    }



    //pattern 7
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 7 -----------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5-i;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<=(2*i)+1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }



    //pattern 8
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 8 -----------------------"<<endl;
    for(int i=5;i>0;i--)
    {
        for(int j=5-i;j>0;j--)
        {
            cout<<" ";
        }
        for(int k=0;k<=(2*i)-1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }




    //Pattern 9
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 9 -----------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5-i;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<=(2*i)+1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=5;i>0;i--)
    {
        for(int j=5-i;j>0;j--)
        {
            cout<<" ";
        }
        for(int k=0;k<=(2*i)-1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }




    //pattern 10
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 10 -----------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    int k=5-1;
    for(int i=k;i>0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }




    //pattern 11
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 11 -----------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if((i+j)%2==0)
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }




    //Pattern 12
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 12 -----------------------"<<endl;
    for(int i=1;i<5;i++)
    {
        int k=1;
        while(k<=i)
        {
            cout<<k;
            k++;
        }
        for(int j=0;j<(2*i)+1;j++)
        {
            cout<<" ";
        }
        while(k>0)
        {
            cout<<k;
            k--;
        }
        cout<<endl;
    }




    //pattern 13
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 13 -----------------------"<<endl;
    int inc=1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<inc++;
        }
        cout<<endl;
    }




    //pattern 14
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 14 -----------------------"<<endl;
     for (int i = 1; i <= 5; i++) {
        for (char ch = 'A'; ch < 'A' + i; ch++) {
            cout << ch;
        }
        cout << endl;
    }



    //pattern 15
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 15 -----------------------"<<endl;
    for (int i = 5; i >= 1; i--) {
        for (char ch = 'A'; ch < 'A' + i; ch++) {
            cout << ch;
        }
        cout << endl;
    }




    //pattern 16
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 16 -----------------------"<<endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char('A' + i - 1);
        }
        cout << endl;
    }



    //pattern 17
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 17 -----------------------"<<endl;
    for (int i = 1; i <= 4; i++) {
        // Spaces
        for (int j = 1; j <= 4 - i; j++) {
            cout << " ";
        }
        // Increasing characters
        for (int j = 1; j <= i; j++) {
            cout << char('A' + j - 1);
        }
        // Decreasing characters
        for (int j = i - 1; j >= 1; j--) {
            cout << char('A' + j - 1);
        }
        cout << endl;
    }



    //pattern 18
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 19 -----------------------"<<endl;
    for (int i = 5; i >= 1; i--) {
        for (char ch = 'A' + i - 1; ch <= 'E'; ch++) {
            cout << ch;
        }
        cout << endl;
    }



    //pattern 19
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 19 -----------------------"<<endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 5 - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 4; i >= 1; i--) {
        for (int j = 1; j <= 5 - i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 5 - i; j++) {
            cout << "*";
        }
        cout << endl;
    }



    //pattern 20
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 20 -----------------------"<<endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++)
            cout << "*";
        for (int j = 1; j <= 9 - 2 * i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
    for (int j = 1; j <= 9; j++)
        cout << "*";
    cout << endl;
    for (int i = 4; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            cout << "*";
        for (int j = 1; j <= 9 - 2 * i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }




    //patern 21
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 21 -----------------------"<<endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (i == 1 || i == 4 || j == 1 || j == 4)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }




    //pattern 22
    cout<<endl;
    cout<<endl;
    cout<<"---------------- Pattern 22 -----------------------"<<endl;
    int size = 7;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = max(
                abs(i - size / 2),
                abs(j - size / 2)
            ) + 1;
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}