#ifndef __MYCLASS_H
#define __MYCLASS_H
#include <iostream>
#include <cmath>
#include <float.h> 
#include <conio.h>
#include <typeinfo.h> 

using namespace std;

static char* Error_NumP="!Переполнение при вычислении числителя!";
static char* Error_Zero="!Деление на ноль невозможно!";
static char* Chisl = "Числитель превышает диапазон double !!!!!!!!!";
static char* Log="Логарифм <=0! Ошибка! \n";
static char* CONTINUE="\n Нажмите любую клавишу - ПРОДОЛЖЕНИЕ    или ESC - ВЫХОД .....\n"; 
static char* Error_INT="\n Вы не удачно выбрали тип результата (int) \n";
static char* Error_Float="\n Вы не удачно выбрали тип результата (float) \n";
static char* Result="\n Будет выполнено преобразование данных!\n Возможна потеря данных!!! \n";
static char* Smisl="\n Смысл выполнения, если итог все равно 0?... \n";


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
	  // числитель		  
	  num = cb-log(33.0+bb)/4;
	  if(fabsl(num)>DBL_MAX) throw Chisl;
	  else 
	  if(fabsl(num)>DBL_MAX) throw Error_NumP;

	  else 
#ifdef _DEBUG
        cout<<"Числитель =  "<<num<<endl;
#endif 
	 { if ((ab-cb/bb-1)==0) throw Error_Zero;
	  else
      if (num!=0){
	 
	  // знаменатель
	  if ((bb==0)) throw Error_Zero; 
	  else
	  {long double resu;
	  if ((ab-cb/bb-1)==0) throw Error_Zero;
	  else	 { dem = ab-cb/bb-1;
	  if(fabsl(dem)>DBL_MAX) throw Chisl; 
	  }}
	  } else throw Smisl;

#ifdef _DEBUG
            cout<<"Знаменатель  =  "<<dem<<endl;
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
    cout << "=======Создаю данные-члены класса " << endl;
#endif
	pa=new Ta(at); 
	pb=new Tb(bt);
	pc=new Tc(ct);
	py=new Tres;
	};

	~Lab3()
	{
#ifdef _DEBUG
	 cout << "~~~~~~~~Уничтожаю данные-члены класса" << endl;
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
		cout << "\nРезультат y  = " << *py<<" находиться по адресу "<<py<<"\n" <<"С форматом: "<<typeid(*py).name()<<CONTINUE;}
	catch(char* v)
	{
	  cout << "\n !!!Обработка исключения. \n" << endl;
      cout << "Ошибка: ";
      cout << v << CONTINUE << endl;
	}
	 catch(...) 
     {
      cout << "\n!!!!! Обработка незапланированной исключительной ситуации." << endl;
      throw;
      }
	 
	  return (_getch());
	};
};

#endif 