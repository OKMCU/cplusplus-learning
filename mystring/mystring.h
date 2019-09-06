#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <stdio.h>
#include <string.h>

namespace OKMCU
{
    class StringNode
    {
        public:
        StringNode( const char* ps, StringNode* pp = NULL, StringNode* pn = NULL );
        ~StringNode();
        size_t getLength( void ) const;
        void setPrevNode( StringNode* pp );
        void setNextNode( StringNode* pn );
        StringNode* getPrevNode( void ) const;
        StringNode* getNextNode( void ) const;
        char* getString( void ) const;
        void print( void ) const;

        private:
        char* p_str;
        size_t length;
        StringNode* p_prev;
        StringNode* p_next;
    };

    class MyString
    {
        public:
        MyString( const char* pstr = NULL );
       ~MyString();
      //MyString( String& str );
        
        size_t getLength( void ) const;
        char* getString( void ); 
        void append( const char* pstr );
        void append( MyString &rstr );
        void print( void ) const;
        //MyString& operator=( const MyString& );
        //MyString& operator=( const char * );
        //operator==
        //operator!=

        private:
        size_t length;
        StringNode* p_head;
        StringNode* p_tail;
    };
};


#endif

