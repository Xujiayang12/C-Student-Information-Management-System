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
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ��            ����¼��ѧ���ɼ���Ϣ��"<<endl;
    cout<<"������:"<<filename<<endl<<endl;
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
    cout<<"�Ƿ�ʼ�������"<<allstu.size()+1<<"��ѧ���ĳɼ���Ϣ��: y/n";
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
            cout<<"������ѧ��ѧ��:";
            while(cin>>id)
            {
                if (allstu.size()==0)
                {
                    one.id=id;
                    break;
                }
                else{
                    int exist=0;
                    for(int i=0;i<=allstu.size()-1;i++)//���鹤�����Ƿ��Ѿ����ڴ�ѧ��
                    {
                        if(allstu[i].id==id)
                        {
                            exist=1;
                            break;
                        }
                    }
                    if(exist==1)
                    {
                        cout<<"��ѧ���Ѵ��ڣ�����������"<<endl;
                    }
                    else
                    {
                        one.id=id;
                        break;
                    }
                }
            }
            cout<<"������ѧ������:"; cin>>one.name;
            cout<<"������ѧ����ѧ�ɼ�:";
            while(cin>>math)
            {
                if(math>100 || math<0)
                {
                    cout<<"����ɼ���������������"<<endl;
                }
                else
                {
                    one.math=math;
                    break;
                }
            }
            cout<<"������ѧ��������Ƴɼ�:";
            while(cin>>ccc)
            {
                if(ccc>100 || ccc<0)
                {
                    cout<<"����ɼ���������������"<<endl;
                }
                else
                {
                    one.ccc=ccc;
                    break;
                }
            }
            one.sum=one.math+one.ccc;
            cout<<"  ѧ��  |  ����  |  ��ѧ�ɼ�  |  ������Ƴɼ�  |  �ܷ�  "<<endl;
            cout<<"��������������������������������������������������������"<<endl;
            const char *name=one.name.c_str();//ת��string�������͵�char
            printf(" %6d   %6s      %3d            %3d         %3d\n",one.id,name,one.math,one.ccc,one.sum);
            cout<<"�Ƿ�����ѧ���ɼ���y/n";
            char ynn;
            cin>>ynn;
            if(ynn=='y')
            {
                fout<<one.id<<" "<<one.name<<" "<<one.math<<" "<<one.ccc<<" "<<one.sum<<endl;
                allstu.push_back(one);
                cout<<endl<<"����ɹ����Ƿ�����������"<<allstu.size()+1<<"��ѧ���ĳɼ���Ϣ��: y/n"<<endl;
            }
            if(ynn=='n')
            {
            	system("cls");
                print();
                cout<<"�Ƿ�ʼ�������"<<allstu.size()+1<<"��ѧ���ĳɼ���Ϣ��: y/n"<<endl<<endl;
            }
        }
    }
}
void search()
{
    system("color 07");
    system("cls");
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ��            ������ѯѧ���ɼ���Ϣ��"<<endl<<endl;
    cout<<"������:"<<filename<<endl<<endl;
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
        cout<<endl<<"�˹���û���κμ�¼�����������ַ�����:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<"������ѧ�Ų�ѯ��";
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
                    cout<<"  ѧ��  |  ����  |  ��ѧ�ɼ�  |  ������Ƴɼ�  |  �ܷ�  "<<endl;
                    cout<<"��������������������������������������������������������"<<endl;
                    const char *name=allstu[i].name.c_str();
                    printf(" %6ld   %6s      %3d            %3d         %3d\n",allstu[i].id,name,allstu[i].math,allstu[i].ccc,allstu[i].sum);
                    cout<<"��������ѧ�Ų�ѯ����������0����������:";
                    iff=1;
                    break;
                } else{
                    continue;
                }
            }
            if(iff==0)
            {
                cout<<"δ�ҵ���ѧ��������ѧ���Ƿ���ȷ���������룬��������0����������:";
            }
        }
    }
}
void summ()
{
    system("color 07");
    system("cls");
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ��            ����ͳ������ѧ���ɼ���"<<endl<<endl;
    cout<<"������:"<<filename;
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
        cout<<endl<<"�˹���û���κμ�¼�����������ַ�����:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<endl<<"����������ķ�ʽ:"<<endl<<" 1.���ܷ��ɴ�С"<<endl<<" 2.��ѧ����С����"<<endl<<" 3.����ѧ�ɼ��ɴ�С"<<endl<<" 4.��������Ƴɼ��ɴ�С"<<endl;
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
            cout<<"û�д�ѡ����������룡"<<endl;
        }
    }
    cout<<"                   ȫ��ѧ���ܷ�ƽ����:"<<all/(allstu.size())<<endl<<endl;
    cout<<"  ѧ��  |  ����  |  ��ѧ�ɼ�  |  ������Ƴɼ�  |  �ܷ�  "<<endl;
    cout<<"����������������������������������������������������������"<<endl;
    for(int i=0;i<=allstu.size()-1;i++)
    {
        const char *name=allstu[i].name.c_str();
        printf(" %6d   %6s      %3d            %3d         %3d\n",allstu[i].id,name,allstu[i].math,allstu[i].ccc,allstu[i].sum);
    }
    cout<<endl<<endl<<"����y����������:";
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
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ��            ����ɾ��ѧ���ɼ���Ϣ��"<<endl<<endl;
    cout<<"������:"<<filename<<endl<<endl;
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
        cout<<endl<<"�˹���û���κμ�¼�����������ַ�����:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<"��Ҫɾ����ѧ�ţ�";
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
                    cout<<"  ѧ��  |  ����  |  ��ѧ�ɼ�  |  ������Ƴɼ�  |  �ܷ�  "<<endl;
                    cout<<"��������������������������������������������������������"<<endl;
                    const char *name=allstu[i].name.c_str();
                    printf(" %6d   %6s      %3d            %3d         %3d\n",allstu[i].id,name,allstu[i].math,allstu[i].ccc,allstu[i].sum);
                    cout<<"�Ƿ�ɾ����ѧ������Ϣ��y/n "<<endl;
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
                    cout<<"��������ѧ��ɾ������������0����������:";
                    iff=1;
                    break;
                } else{
                    continue;
                }
            }
            if(iff==0)
            {
                cout<<"δ�ҵ���ѧ��������ѧ���Ƿ���ȷ���������룬��������0����������:";
            }
        }
    }
}
void generate()
{
    system("color 07");
    system("cls");
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ��            ��������Excle���  ��"<<endl<<endl;
    cout<<"������:"<<filename;
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
        cout<<endl<<"�˹���û���κμ�¼�����������ַ�����:"<<endl;
        char a;
        while(cin>>a)
        {
            function();
            break;
        }
    }
    cout<<endl<<"�����뱣�ֳɱ�������:"<<endl;
    string newfn1,newfn2;
    cin>>newfn1;
    newfn2=newfn1+".csv";
    const char *newfn=newfn2.c_str();
    ofstream fout(newfn);
    cout<<"��ѡ�񱣴�ʱ������ʽ��"<<endl<<"  1.���ɼ��ɸߵ���"<<endl<<"  2.��ѧ����С����"<<endl<<endl;
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
            cout<<endl<<"�����Ŵ������������룡"<<endl;
        }
    }
    fout<<"ѧ��"<<","<<"����"<<","<<"��ѧ�ɼ�"<<","<<"������Ƴɼ�"<<","<<"�ܷ�"<<endl;
    for(int i=0;i<=allstu.size()-1;i++)
    {
        fout<<allstu[i].id<<","<<allstu[i].name<<","<<allstu[i].math<<","<<allstu[i].ccc<<","<<allstu[i].sum<<endl;
    }
    cout<<endl<<"����ɹ����ļ�λ�ڳ���ͬĿ¼�£���ʹ��Excle�򿪣�����y�˳� :"<<endl;
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
void function()//���˵�����
{
    system("cls");
    system("color 17");
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ������������������������������������"<<endl<<endl;
    cout<<"������:"<<filename<<endl<<endl;
    cout<<"    1.¼��ѧ���ɼ���Ϣ"<<endl;
    cout<<"    2.ɾ��ѧ���ɼ���Ϣ"<<endl;
    cout<<"    3.��ѯ����ѧ����Ϣ"<<endl;
    cout<<"    4.ͳ������ѧ����Ϣ"<<endl;
    cout<<"    5.����Excle���"<<endl;
    cout<<"    6.�˳�����"<<endl<<endl;
    cout<<"�����빦����Ӧ�ı��"<<endl;
    int func;//Ҫ����Ĺ��ܵı��
    cin>>func;
    switch (func)
    {
        case 1:input();break;
        case 2:del();break;
        case 3:search();break;
        case 4:summ();break;
        case 5:generate();break;
        case 6:exit(0);
        default: cout<<"��������ȷ�ı�� y/n "<<endl; char ynn[3]; cin>>ynn; function(); break;
    }
}
int main() {
    system("color 07");
    cout<<"         ������������������������������������"<<endl;
    cout<<"         ��  ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ  ��"<<endl;
    cout<<"         ������������������������������������"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"�������㽫Ҫ������򿪵Ĺ����ļ���:"<<endl;
    cin>>filename;
    strfile=filename+".txt";
    file=strfile.c_str();
    ofstream fout(file,ios::app);
    function();
    return 0;
}
