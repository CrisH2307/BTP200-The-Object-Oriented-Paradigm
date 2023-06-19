 // foo.h
  #ifndef FOO_H
  #define FOO_H
  
class Foo
{
    char m_str[32];
public:
    Foo() { m_str[0] = '\0'; }
    // return "true" if m_str is changed, "false" otherwise
    bool setStr(const char* theStr = nullptr);
};
#endif
