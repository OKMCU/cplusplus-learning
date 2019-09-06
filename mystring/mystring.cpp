#include "mystring.h"
#include <iostream>

using namespace::std;
using namespace::OKMCU;


StringNode::StringNode( const char *ps, StringNode *pp, StringNode *pn )
{
    this->p_prev = pp;
    this->p_next = pn;
    if( ps != NULL )
    {
        this->length = strlen( ps );
        this->p_str = new char[this->length + 1];
        strcpy( this->p_str, ps );
    }
    else
    {
        this->length = 0;
        this->p_str = NULL;
    }
}

StringNode::~StringNode()
{
    if( this->p_str != NULL )
    {
        delete[] this->p_str;
    }
}

size_t StringNode::getLength( void ) const
{
    return this->length;
}

void StringNode::setPrevNode( StringNode *pp )
{
    this->p_prev = pp;
}

void StringNode::setNextNode( StringNode *pn )
{
    this->p_next = pn;
}

StringNode* StringNode::getPrevNode( void ) const
{
    return this->p_prev;
}

StringNode* StringNode::getNextNode( void ) const
{
    return this->p_next;
}

char* StringNode::getString( void ) const
{
    return this->p_str;
}

void StringNode::print( void ) const
{
    printf( "%s", this->p_str );
}

MyString::MyString( const char *pstr )
{
    if( pstr != NULL )
    {
        this->p_head = new StringNode( pstr, NULL, NULL );
        this->p_tail = this->p_head;
        this->length = this->p_head->getLength();
    }
    else
    {
        this->length = 0;
        this->p_head = NULL;
        this->p_tail = NULL;
    }
}

MyString::~MyString()
{
    StringNode* p;
    while( this->p_head != NULL )
    {
        p = this->p_head;
        this->p_head = this->p_head->getNextNode();
        delete p;
    }
}

size_t MyString::getLength( void ) const
{
    return this->length;
}


char* MyString::getString( void )
{
    char* p_str = new char[this->length + 1];
    size_t ptr = 0;
    StringNode* p;
    while( this->p_head != NULL )
    {
        p = this->p_head;
        strcpy( p_str+ptr, p->getString() );
        ptr += p->getLength();
        this->p_head = this->p_head->getNextNode();
        delete p;
    }
    
    this->p_head = new StringNode( p_str );
    this->p_tail = this->p_head;
    
    delete[] p_str;

    return this->p_head->getString();
}

void MyString::append( const char* pstr )
{
    size_t len;
    
    if( pstr != NULL )
    {
        len = strlen( pstr );
        if( len )
        {
            StringNode* p_node = new StringNode( pstr, this->p_tail, NULL );
            this->p_tail->setNextNode( p_node );
            this->p_tail = p_node;
            this->length += len;
        }
    }
}

void MyString::append( MyString &other )
{
    if( &other != NULL )
    {
        char *pstr = other.getString();
        if( other.getLength() > 0 )
        {
            StringNode* p_node = new StringNode( pstr, NULL, NULL );
            p_node->setPrevNode( this->p_tail );
            this->p_tail->setNextNode( p_node );
            this->p_tail = p_node;
            this->length += other.getLength();
        }
    }
}

void MyString::print( void ) const
{
    StringNode* p;
    p = this->p_head;
    while( p != NULL )
    {
        p->print();
        p = p->getNextNode();
    }
}

//MyString7 operator=( const MyString& other)
//{

//}
