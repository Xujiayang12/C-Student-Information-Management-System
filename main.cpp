#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
void function();
typedef struct Student{
    long id;
    string name;
    int math;
    int ccc;
    int sum;
}stuit;
bool cmp(Student a,Student b) 
{
    if(a.sum != b.sum) return a.sum>b.sum; 
    else return a.id<b.id; 
}
bool cmp2(Student a,Student b)
{
    return a.id<b.id;
}
bool cmpmath(Student a,Student b)
{
    return a.math>b.math;
}
bool cmpcc(Student a,Student b)
{
    return a.ccc>b.ccc;
}
string filename,strfile;
const char *file;
void print()
{
    system("color 07");
    system("cls");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※            ——录入学生成绩信息※"<<endl;
    cout<<"工程名:"<<filename<<endl<<endl;
}
void input()
{
    system("color 07");
    system("cls");
    print();
    ofstream fout(file,ios::app);
    ifstream fin(file);
    vector<stuit> allstu;
    long id;
    string name;
    int math;
    int ccc;
    int sum;
    char yn;
    while (fin>>id>>name>>math>>ccc>>sum)
    {
        stuit one;
        one.id=id;
        one.name=name;
        one.math=math;
        one.ccc=ccc;
        one.sum=sum;
        allstu.push_back(one);
    }
    cout<<"是否开始请输入第"<<allstu.size()+1<<"个学生的成绩信息？: y/n";
    while (cin>>yn)
    {
        if(yn=='n')
        {
            fout.close();
            function();
            break;
        } else if(yn=='y')
        {
            stuit one;
            cout<<"请输入学生学号:";
            while(cin>>id)
            {
                if (allstu.size()==0)
                {
                    one.id=id;
                    break;
                }
                else{
                    int exist=0;
                    for(int i=0;i<=allstu.size()-1;i++)//检验工程中是否已经存在此学号
                    {
                        if(allstu[i].id==id)
                        {
                            exist=1;
                            break;
                        }
                    }
                    if(exist==1)
                    {
                        cout<<"此学生已存在，请重新输入"<<endl;
                    }
                    else
                    {
                        one.id=id;
                        break;
                    }
                }
            }
            cout<<"请输入学生姓名:"; cin>>one.name;
            cout<<"请输入学生数学成绩:";
            while(cin>>math)
            {
                if(math>100 || math<0)
                {
                    cout<<"输入成绩错误，请重新输入"<<endl;
                }
                else
                {
                    one.math=math;
                    break;
                }
            }
            cout<<"请输入学生程序设计成绩:";
            while(cin>>ccc)
            {
                if(ccc>100 || ccc<0)
                {
                    cout<<"输入成绩错误，请重新输入"<<endl;
                }
                else
                {
                    one.ccc=ccc;
                    break;
                }
            }
            one.sum=one.math+one.ccc;
            cout<<"  学号  |  名字  |  数学成绩  |  程序设计成绩  |  总分  "<<endl;
            cout<<"————————————————————————————"<<endl;
            const char *name=one.name.c_str();//转换string数据类型到char
            printf(" %6d   %6s      %3d            %3d         %3d\n",one.id,name,one.math,one.ccc,one.sum);
            cout<<"是否插入此学生成绩：y/n";
            char ynn;
            cin>>ynn;
            if(ynn=='y')
            {
                fout<<one.id<<" "<<one.name<<" "<<one.math<<" "<<one.ccc<<" "<<one.sum<<endl;
                allstu.push_back(one);
                cout<<endl<<"插入成功！是否继续请输入第"<<allstu.size()+1<<"个学生的成绩信息？: y/n"<<endl;
            }
            if(ynn=='n')
            {
            	system("cls");
                print();
                cout<<"是否开始请输入第"<<allstu.size()+1<<"个学生的成绩信息？: y/n"<<endl<<endl;
            }
        }
    }
}
void search()
{
    system("color 07");
    system("cls");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※            ——查询学生成绩信息※"<<endl<<endl;
    cout<<"工程名:"<<filename<<endl<<endl;
    ifstream fin(file);
    vector<stuit> allstu;
    long id;
    string name;
    int math;
    int ccc;
    int sum;
    int searchnum;
    while (fin>>id>>name>>math>>ccc>>sum)
    {
        stuit one;
        one.id=id;
        one.name=name;
        one.math=math;
        one.ccc=ccc;
        one.sum=sum;
        allstu.push_back(one);
    }
    if(allstu.size()==0)
    {
        cout<<endl<<"此工程没有任何记录，输入任意字符返回:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<"请输入学号查询：";
    while(cin>>searchnum)
    {
        int iff=0;
        if(searchnum==0)
        {
            fin.close();
            function();
        }
        else{
            for(int i=0;i<=allstu.size()-1;i++)
            {
                if(allstu[i].id==searchnum)
                {
                    cout<<"  学号  |  名字  |  数学成绩  |  程序设计成绩  |  总分  "<<endl;
                    cout<<"————————————————————————————"<<endl;
                    const char *name=allstu[i].name.c_str();
                    printf(" %6ld   %6s      %3d            %3d         %3d\n",allstu[i].id,name,allstu[i].math,allstu[i].ccc,allstu[i].sum);
                    cout<<"继续输入学号查询，或者输入0返回主界面:";
                    iff=1;
                    break;
                } else{
                    continue;
                }
            }
            if(iff==0)
            {
                cout<<"未找到该学生，请检查学号是否正确并重新输入，或者输入0返回主界面:";
            }
        }
    }
}
void summ()
{
    system("color 07");
    system("cls");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※            ——统计所有学生成绩※"<<endl<<endl;
    cout<<"工程名:"<<filename;
    ifstream fin(file);
    vector<stuit> allstu;
    long id;
    string name;
    int math;
    int ccc;
    int sum;
    float all=0.0;
    while (fin>>id>>name>>math>>ccc>>sum)
    {
        stuit one;
        one.id=id;
        one.name=name;
        one.math=math;
        one.ccc=ccc;
        one.sum=sum;
        all+=float(sum);
        allstu.push_back(one);
    }
    if(allstu.size()==0)
    {
        cout<<endl<<"此工程没有任何记录，输入任意字符返回:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<endl<<"请输入排序的方式:"<<endl<<" 1.按总分由大到小"<<endl<<" 2.按学号由小到大"<<endl<<" 3.按数学成绩由大到小"<<endl<<" 4.按程序设计成绩由大到小"<<endl;
    int way;
    while(cin>>way)
    {
        if(way==1)
        {
            sort(allstu.begin(),allstu.end(),cmp);
            break;
        }
        else if(way==2)
        {
            sort(allstu.begin(),allstu.end(),cmp2);
            break;
        }
        else if(way==3)
        {
            sort(allstu.begin(),allstu.end(),cmpmath);
            break;
        }
        else if(way==4)
        {
            sort(allstu.begin(),allstu.end(),cmpcc);
            break;
        } else{
            cout<<"没有此选项，请重新输入！"<<endl;
        }
    }
    cout<<"                   全部学生总分平均分:"<<all/(allstu.size())<<endl<<endl;
    cout<<"  学号  |  名字  |  数学成绩  |  程序设计成绩  |  总分  "<<endl;
    cout<<"—————————————————————————————"<<endl;
    for(int i=0;i<=allstu.size()-1;i++)
    {
        const char *name=allstu[i].name.c_str();
        printf(" %6d   %6s      %3d            %3d         %3d\n",allstu[i].id,name,allstu[i].math,allstu[i].ccc,allstu[i].sum);
    }
    cout<<endl<<endl<<"输入y返回主界面:";
    char func;
    while(cin>>func)
    {
        if(func=='y')
        {
            system("cls");
            fin.close();
            function();
            break;
        }
    }
}
void del()
{
    system("color 07");
    system("cls");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※            ——删除学生成绩信息※"<<endl<<endl;
    cout<<"工程名:"<<filename<<endl<<endl;
    ifstream fin(file);
    vector<stuit> allstu;
    long id;
    string name;
    int math;
    int ccc;
    int sum;
    int searchnum;
    while (fin>>id>>name>>math>>ccc>>sum)
    {
        stuit one;
        one.id=id;
        one.name=name;
        one.math=math;
        one.ccc=ccc;
        one.sum=sum;
        allstu.push_back(one);
    }
    if(allstu.size()==0)
    {
        cout<<endl<<"此工程没有任何记录，输入任意字符返回:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<"请要删除的学号：";
    while(cin>>searchnum)
    {
        int iff=0;
        if(searchnum==0)
        {
            fin.close();
            function();
        }
        else{
            for(int i=0;i<=allstu.size()-1;i++)
            {
                if(allstu[i].id==searchnum)
                {
                    cout<<"  学号  |  名字  |  数学成绩  |  程序设计成绩  |  总分  "<<endl;
                    cout<<"————————————————————————————"<<endl;
                    const char *name=allstu[i].name.c_str();
                    printf(" %6d   %6s      %3d            %3d         %3d\n",allstu[i].id,name,allstu[i].math,allstu[i].ccc,allstu[i].sum);
                    cout<<"是否删除该学生的信息：y/n "<<endl;
                    char ynn;
                    while(cin>>ynn)
                    {
                        if(ynn=='y')
                        {
                            allstu.erase(allstu.begin()+i);
                            ofstream fout(file);
                            fout.close();
                            ofstream fout2(file,ios::app);
                            if(allstu.size()==0) break; 
                            for(int i=0;i<=allstu.size()-1;i++)
                            {
                                fout2<<allstu[i].id<<" "<<allstu[i].name<<" "<<allstu[i].math<<" "<<allstu[i].ccc<<" "<<allstu[i].sum<<endl;
                            }
                            break;
                        } else break;
                    }
                    cout<<"继续输入学号删除，或者输入0返回主界面:";
                    iff=1;
                    break;
                } else{
                    continue;
                }
            }
            if(iff==0)
            {
                cout<<"未找到该学生，请检查学号是否正确并重新输入，或者输入0返回主界面:";
            }
        }
    }
}
void generate()
{
    system("color 07");
    system("cls");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※            ——生成Excle表格  ※"<<endl<<endl;
    cout<<"工程名:"<<filename;
    ifstream fin(file);
    vector<stuit> allstu;
    long id;
    string name;
    int math;
    int ccc;
    int sum;
    while (fin>>id>>name>>math>>ccc>>sum)
    {
        stuit one;
        one.id=id;
        one.name=name;
        one.math=math;
        one.ccc=ccc;
        one.sum=sum;
        allstu.push_back(one);
    }
    if(allstu.size()==0)
    {
        cout<<endl<<"此工程没有任何记录，输入任意字符返回:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<endl<<"请输入保持成表格的名字:"<<endl;
    string newfn1,newfn2;
    cin>>newfn1;
    newfn2=newfn1+".csv";
    const char *newfn=newfn2.c_str();
    ofstream fout(newfn);
    cout<<"请选择保存时的排序方式："<<endl<<"  1.按成绩由高到低"<<endl<<"  2.按学号由小到大"<<endl<<endl;
    int way;
    while (cin>>way)
    {
        if(way==1)
        {
            sort(allstu.begin(),allstu.end(),cmp);
            break;
        } else if(way==2)
        {
            sort(allstu.begin(),allstu.end(),cmp2);
            break;
        } else
        {
            cout<<endl<<"输入编号错误，请重新输入！"<<endl;
        }
    }
    fout<<"学号"<<","<<"名字"<<","<<"数学成绩"<<","<<"程序设计成绩"<<","<<"总分"<<endl;
    for(int i=0;i<=allstu.size()-1;i++)
    {
        fout<<allstu[i].id<<","<<allstu[i].name<<","<<allstu[i].math<<","<<allstu[i].ccc<<","<<allstu[i].sum<<endl;
    }
    cout<<endl<<"保存成功，文件位于程序同目录下，请使用Excle打开，输入y退出 :"<<endl;
    char ynn;
    while(cin>>ynn)
    {
        if(ynn=='y')
        {
            function();
            break;
        }
    }
}
void function()//主菜单函数
{
    system("cls");
    system("color 17");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl<<endl;
    cout<<"工程名:"<<filename<<endl<<endl;
    cout<<"    1.录入学生成绩信息"<<endl;
    cout<<"    2.删除学生成绩信息"<<endl;
    cout<<"    3.查询所有学生信息"<<endl;
    cout<<"    4.统计所有学生信息"<<endl;
    cout<<"    5.生成Excle表格"<<endl;
    cout<<"    6.退出程序"<<endl<<endl;
    cout<<"请输入功能相应的编号"<<endl;
    int func;//要输入的功能的编号
    cin>>func;
    switch (func)
    {
        case 1:input();break;
        case 2:del();break;
        case 3:search();break;
        case 4:summ();break;
        case 5:generate();break;
        case 6:exit(0);
        default: cout<<"请输入正确的编号 y/n "<<endl; char ynn[3]; cin>>ynn; function(); break;
    }
}
int main() {
    system("color 07");
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<"         ※  欢迎使用学生成绩信息管理系统  ※"<<endl;
    cout<<"         ※※※※※※※※※※※※※※※※※※"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"请输入你将要创建或打开的工程文件名:"<<endl;
    cin>>filename;
    strfile=filename+".txt";
    file=strfile.c_str();
    ofstream fout(file,ios::app);
    function();
    return 0;
}
