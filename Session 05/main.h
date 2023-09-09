

const int NG = 20;

class Student 
{
    int no;
    float grade[NG];
    int ng;
public:
    ~Student();
    void copyFrom(const Student& src);
    void set(int, const float*, int);
    void display() const;
};