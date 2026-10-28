#include<iostream>
using namespace std;
#define Total 10
#define Max 5
struct SuperBlock
{
       int list[Max];
       int count;
       int rem;
};
int inode [Total] = {0};
SuperBlock sb;
void refill()
{
       sb.count = 0;
       for(int i= sb.rem; i<Total && sb.count < Max; i++)
       {
              if (inode[i] == 0)
                     sb.list[sb.count++] = i+1;
              sb.rem = i+1;
       }
       cout<<"\nSuperBlock ReFilled!!..\n";
}
void ialloc()
{
       if(sb.count == 0)
              refill();

       if(sb.count== 0)
       {
              cout<<"\n No Free Inode Available..\n";
              return;
       }
       int n = sb.list[0];
       for(int i=0;i< sb.count-1; i++)
              sb.list[i]= sb.list[i+1];

       sb.count--;
       inode[n-1] =1;
       cout<<"\nInode "<<n<<" allocated.\n";
}
void ifree(int n)
{
       if (n<1 || n>Total || inode[n-1]==0)
       {
              cout<<"\nInvalid or Already free inode\n";
              return;
       }
       inode[n-1]=0;
       if(sb.count < Max)
       {
              sb.list[sb.count++]= n;
              cout<<"\nInode "<<n<<" inserted in superblock\n";
       }
       else
              cout<<"\nSuperBlock full; inode "<<n<< "is free on disk.\n";
}
void display()
{
    cout << "\n\nFree count = \n" << sb.count;
    cout << "\nFree list = \n";

    for(int i = 0; i < sb.count; i++)
        cout << sb.list[i] << " ";

    cout << "\nRemembered index = \n" << sb.rem + 1;
}

int main()
{
    int ch, n;

    /* Initially fill superblock */
    refill();

    while(1)
    {
        cout << "\n\n1. Display";
        cout << "\n2. ialloc()";
        cout << "\n3. ifree()";
        cout << "\n4. Exit";
        cout << "\nChoice: ";
        cin >> ch;

        if(ch == 1)
            display();

        else if(ch == 2)
            ialloc();

        else if(ch == 3)
       {
            cout << "Enter inode number: ";
            cin >> n;
            ifree(n);
       }
       else if (ch = 4)
              break;
       }
       return 0;
}