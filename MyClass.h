#ifndef __MYCLASS_H
#define __MYCLASS_H
#include <iostream>
#include <cmath>
#include <float.h> 
#include <conio.h>
#include <typeinfo.h> 

using namespace std;

static char* Error_NumP="!������������ ��� ���������� ���������!";
static char* Error_Zero="!������� �� ���� ����������!";
static char* Chisl = "��������� ��������� �������� double !!!!!!!!!";
static char* Log="�������� <=0! ������! \n";
static char* CONTINUE="\n ������� ����� ������� - �����������    ��� ESC - ����� .....\n"; 
static char* Error_INT="\n �� �� ������ ������� ��� ���������� (int) \n";
static char* Error_Float="\n �� �� ������ ������� ��� ���������� (float) \n";
static char* Result="\n ����� ��������� �������������� ������!\n �������� ������ ������!!! \n";
static char* Smisl="\n ����� ����������, ���� ���� ��� ����� 0?... \n";


template <class Ta,class Tb, class Tc,  class Tres >
class Lab3
{
private:
	
	Ta *pa;
	Tb *pb; 
	Tc *pc;
	Tres *py;

	void num_dem()
	{
	  long double ab, bb, cb, res, num, dem; 
      ab=*pa; bb=*pb; cb=*pc; 
      cout<<typeid(*pa).name()<<" a = " << ab << "; "<<endl
		  <<typeid(*pb).name()<<" b = " << bb << ";"<<endl
		  <<typeid(*pc).name()<<" c = " << cb <<";"<<endl;
	 
	  if (bb<=-33) throw Log;  else if (bb==0) throw Error_Zero; else {
	  // ���������		  
	  num = cb-log(33.0+bb)/4;
	  if(fabsl(num)>DBL_MAX) throw Chisl;
	  else 
	  if(fabsl(num)>DBL_MAX) throw Error_NumP;

	  else 
#ifdef _DEBUG
        cout<<"��������� =  "<<num<<endl;
#endif 
	 { if ((ab-cb/bb-1)==0) throw Error_Zero;
	  else
      if (num!=0){
	 
	  // �����������
	  if ((bb==0)) throw Error_Zero; 
	  else
	  {long double resu;
	  if ((ab-cb/bb-1)==0) throw Error_Zero;
	  else	 { dem = ab-cb/bb-1;
	  if(fabsl(dem)>DBL_MAX) throw Chisl; 
	  }}
	  } else throw Smisl;

#ifdef _DEBUG
            cout<<"�����������  =  "<<dem<<endl;
#endif      }

	  res=num/dem;

	  if(fabsl(res)>DBL_MAX)
		 throw Error_NumP;
	  
	  if (typeid(Tres)==typeid(float))
		if(fabsl(res)>FLT_MAX)
			cout<<Error_Float<<Result<<endl;

	  if (typeid(Tres)==typeid(int))
		if((fabsl(res)>INT_MAX)||(res!=(int)res))
			cout<<Error_INT<<Result<<endl;

	  *py=(Tres)res;
		  }  }
};



public:

	Lab3(Ta at, Tb bt, Tc ct )
	{
#ifdef _DEBUG
    cout << "=======������ ������-����� ������ " << endl;
#endif
	pa=new Ta(at); 
	pb=new Tb(bt);
	pc=new Tc(ct);
	py=new Tres;
	};

	~Lab3()
	{
#ifdef _DEBUG
	 cout << "~~~~~~~~��������� ������-����� ������" << endl;
#endif
	 delete pa;
	 delete pb;
	 delete pc;
	 delete py;
	};

	int show()
	{ try
	  {
		num_dem();
		cout << "\n��������� y  = " << *py<<" ���������� �� ������ "<<py<<"\n" <<"� ��������: "<<typeid(*py).name()<<CONTINUE;}
	catch(char* v)
	{
	  cout << "\n !!!��������� ����������. \n" << endl;
      cout << "������: ";
      cout << v << CONTINUE << endl;
	}
	 catch(...) 
     {
      cout << "\n!!!!! ��������� ����������������� �������������� ��������." << endl;
      throw;
      }
	 
	  return (_getch());
	};
};

#endif 