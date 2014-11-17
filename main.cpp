Бога нет
 #include <time.h>
 
 using namespace std;
 ]ние переменной "<<prm<<" типа "<<typeid(x).name()<<"===>"; 
    if (typeid(R)==typeid(float))
		my_inp>>e;
	else
		my_inp>>x;
	
	switch (my_inp.rdstate())
	{case ios_base::goodbit:;
	 case ios_base::eofbit:;
		 if (typeid(R)==typeid(float))
			 x=(R)e;
		  return 0;
	 case ios_base::failbit: 
	 case ios_base::badbit:	
     cout << "\n!Введены некоректные данные!" 
            << "\n Повторите ввод" << endl;
	  return 1;
	 default: return 1;
	}  
   };


 int generator()
 {srand((unsigned)time(NULL));
 switch (rand()%10)
   {case 0:
      {float a,b,c;
	   while(Input (a, "a"));
	   while(Input (b, "b"));
	   while(Input (c, "c"));
	   Lab3 <float, float, float, float> Object(a,b,c);
	   return Object.show();
	  }

   case 1:
	   {double a,b,c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
	    Lab3 <double, double, double, double> Object(a,b,c);
	    return Object.show();
	  }

   case 2:
	    {float a,b;
		double c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
	    Lab3 <float, float,double, double> Object(a,b,c);
	    return Object.show();
	  }

	case 3:
	    {double a,b;
		int c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
	    Lab3 <double, double, int, double> Object(a,b,c);
	    return Object.show();
	  }

	case 4:
	    {float a,b;
		int c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
	    Lab3 <float, float, int, double> Object(a,b,c);
	    return Object.show();
	  }

	case 5:
	    {int a,b;
		double c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
		Lab3 < int, int, double, double> Object(a,b,c);
	    return Object.show();
	  }

	case 6:
	    {float a;
		int b;
		double c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c")); 
	    Lab3 < float, int, double, double> Object(a,b,c);
	    return Object.show();
	  }

	case 7:
	    {double a;
		int b;
		float c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
	    Lab3 < double, int, float,double> Object(a,b,c);
	    return Object.show();
	  }

	case 8:
	    {int a, b, c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
	    Lab3 < int, int, int, int> Object(a,b,c);
	    return Object.show();
	  }

	case 9:
	    {int a, b, c;
	    while(Input (a, "a"));
	    while(Input (b, "b"));
	    while(Input (c, "c"));
		Lab3 < int, int, int, float> Object(a,b,c);
	    return Object.show();
	  }

   default:
	   cout<<"Где-то ошибка!"<<endl;
	   return 0;
   }
 }

 
 
 int main()
 {  int ESC=27, est, t=0;
    cout << setprecision(16); 
   setlocale(LC_ALL, "Russian"); 
#ifdef _DEBUG
	 cout << " = Работает режим Debug =" << endl;
#endif
    for(;;)    
    {
     cout << "\n--------- Выполняю #" << ++t << " раз-----------" << endl;
		cout << "  Вычисляем вариант: 38" << endl;
		cout << "         c - ln(33 + b)/4 " << endl;
		cout << "    y = --------------" << endl;
		cout << "        a - c / b - 1" << endl;
	 
	 est=generator();
	 if ( est==ESC)
		 break;
    } 

   return 0;
 }