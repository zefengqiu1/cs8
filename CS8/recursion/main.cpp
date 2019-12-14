#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int rec1_level(int start,int level);

int rec2_box(string prefix,int level);

int rec3_first_second(string first,string second);

int rec4_inBox(int numBox,string label);

double rec5_sumover(unsigned int n);

void rec6_binary_search(int left,int right);

void test_1();

void test_2();

void test_3();

void test_4();

void test_5();

void test_6();

int main()
{
//    test_1();
  //  test_2();
//    test_3();
    test_4();
//    test_5();
//    test_6();
    return 0;
}

void test_1()
{
    rec1_level(1,10);
}

void test_2()
{
    rec2_box("BOX",3);
}

void test_3()
{
    rec3_first_second("CAT","MAN");
}

void test_4()
{
     int numbox=0;
     int sum=0;
     string label;
     cout<<"please enter how many unnumber boxes can you see "<<endl;
     cin>>numbox;
     sum+=rec4_inBox(numbox,label);
     sum+=numbox;
      cout<<"the sum of box is "<<sum<<endl;
}

void test_5()
{
    int num=0;
    cout<<"please enter the positive number you want to calculate!"<<endl;
    cin>>num;
    cout<<rec5_sumover(num)<<endl;
}

void test_6()
{
    rec6_binary_search(1,10000);
}


int rec3_first_second(string first,string second)//cat man
{

    if(first.length()==0)
    {
        cout<<second<<endl;
        return 0;
    }

    for(int i=0;i<first.length();i++)
    {
        string str1=first;
        string str2=second;

        str2.insert(0,1,first[i]);
        str1.erase(i,1);
        rec3_first_second(str1,str2);

    }

    return 0;
}

void rec6_binary_search(int left,int right)
{
    char ans;
    char answer;
   int mid=(left+right)/2;
   cout<<mid<<" is it your number ? y/n"<<endl;
   cin>>ans;
   if(ans=='y'||ans=='Y')
   {
       cout<<mid<<" is your correct answer"<<endl;
   }else
   {
       cout<<"is it larger or smaller than midpoint, press s for smaller and l for larger"<<endl;
       cin>>answer;
       if(answer=='s'||answer=='S')
       {
           rec6_binary_search(left,mid-1);
       }else
       {
           rec6_binary_search(mid+1,right);
       }
   }

}

double rec5_sumover(unsigned int n)
{
    if(n==0) return 0;
    return (1.0/n)+rec5_sumover(n-1);
}

int rec4_inBox(int numBox,string label)
{
    if(numBox<=0) return 0;
        string current=label;
        int total=0;
        int boxes=0;
        for(int i=1;i<=numBox;i++)
        {
            label+=char('0'+i);
            cout<<"how many boxes you see in box number "<<label<<endl;
            cin>>boxes;
            label+='.';
            total+=rec4_inBox(boxes,label);
            total+=boxes;
            label=current;
        }
        return total;
}



int rec2_box(string prefix,int level)
{
    if(level==0) return 0;
    string s;
   rec2_box(prefix,level-1);

   for(int i=1;i<=9;i++)
   {
       s = prefix;
       s +=':';
       s +=char('0'+level);
       s += '.';
       s += char('0' + i);
       cout<<s<<endl;
   }
   return 0;
}


int rec1_level(int start,int level)
{
    if(start>level) return 0;
    cout<<"This was written by call number"<<start<<endl;
    rec1_level(start+1,level);
    cout<<"This ALSO written by call number"<<start<<endl;
    return 0;
}





