// document.h
#include <iostream>
namespace cpp
{
    class Document
    {
        char* m_title;
        char m_author[30];
    public:
        Document(const char* title, const char* author);
        ~Document();
    };
}