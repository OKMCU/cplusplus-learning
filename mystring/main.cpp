#include "mystring.h"
#include <iostream>

using namespace::std;
using namespace::OKMCU;

int main( int argc, char** argv )
{
    char str[] = "C++ String Class.\n";
    MyString *p_str1 = new MyString("Hey!");
    MyString *p_str2 = new MyString("Hello");
    MyString *p_str3 = new MyString("This is a self-defined");
    MyString *p_str4 = new MyString();

    p_str1->append( " " );
    p_str1->append( *p_str2 );
    p_str1->append( " " );
    p_str1->append( "World! " );
    p_str3->append( " " );
    p_str3->append( str );
    p_str1->append( *p_str3 );

    cout << "String length = " << p_str1->getLength() << endl;
    cout << "String 1 print(): " << endl;
    p_str1->print();
    
    cout << "String length = " << strlen( p_str1->getString() ) << endl;
    cout << "String 1 getString(): " << endl;
    cout << p_str1->getString() << endl;
    
    *p_str4 = *p_str1;

    cout << "String 4 length = " << p_str4->getLength() << endl;
    cout << "String 4 getString(): " << endl;
    cout << p_str4->getString() << endl;
    
    *p_str4 = "Hello World again!\n";
    cout << "String 4 length = " << p_str4->getLength() << endl;
    cout << "String 4 print(): " << endl;
    p_str4->print();

    *p_str1 = "Hello ";
    *p_str2 = "World ";
    *p_str3 = "again!\n";
    p_str1->append( *p_str2 );
    p_str1->append( *p_str3 );

    if( *p_str1 == *p_str4 )
    {
        cout << "String 1 == String 4" << endl;
    }
    else
    {
        cout << "String 1 != String 4" << endl;
    }

    delete p_str1;
    p_str1 = NULL;
    delete p_str2;
    p_str2 = NULL;
    delete p_str3;
    p_str3 = NULL;
    delete p_str4;
    p_str4 = NULL;

    return 0;
}



