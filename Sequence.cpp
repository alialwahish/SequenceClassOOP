// Name: Ali Bayati 
// sequence template class

#include<iostream>
#include<string>
#include"Header.h"

using namespace std;
using namespace main_savitch_3;

int main()
{
	
	sequence<int> tt;
	sequence<float> ff(4.4f);
	sequence<string> ss("Ali");

	cout << "Testing Integer sequence :" << endl;
	tt.insert(8);
	tt.insert(9);
	tt.start();
	tt.attach(6);
	tt.print();
	cout <<"the current item :"<< tt.current()<<endl;
	tt.start();
	tt.remove_current();
	tt.print();
	cout << "the size of sequence :" << tt.size() << endl<<endl;
	cout << "Testing Float sequence :" << endl ;
	ff.attach(7.232);
	ff.insert(8.8);
	ff.insert(6.6);
	
	ff.print();
	cout << "the current item :" << ff.current() << endl;
	ff.start();
	ff.remove_current();
	ff.print();
	cout << "the size of sequence :" << ff.size() << endl << endl;

	cout << "Testing String sequence :" << endl;
	ss.attach("Ryan");
	ss.insert("Rawasi");
	ss.insert("Safaa");

	ss.print();
	cout << "the current item :" << ss.current() << endl;
	ss.start();
	ss.remove_current();
	ss.print();
	cout << "the size of sequence :" << ss.size() << endl;

	return 0;
}

/*Output
Testing Integer sequence :
{9, 6, 8, 0}
the current item :6
{6, 8, 0}
the size of sequence :3

Testing Float sequence :
{4.4, 6.6, 8.8, 7.232}
the current item :6.6
{6.6, 8.8, 7.232}
the size of sequence :3

Testing String sequence :
{Ali, Safaa, Rawasi, Ryan}
the current item :Safaa
{Safaa, Rawasi, Ryan}
the size of sequence :3
Press any key to continue . . .
*/