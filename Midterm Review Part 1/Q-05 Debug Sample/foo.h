// foo.h
 #ifndef FOO_H
 #define FOO_H
 class Foo
{
   char m_str[32];
 public:
   // return true if m_str is changed, false otherwise
   
	 //bool setStr(const char* theStr);
	bool setStr(const char* name);  //! Solution
};
#endif
