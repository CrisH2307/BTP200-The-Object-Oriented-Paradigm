//! Class and Resources


/*
Resource Instance Pointers
A C++ obj refers to a resource through a resource instance ptr. A ptr holds the address of the resource.

*/

//! Case Study
#include <iostream>
using namespace std;

class Student {
    int no;
    float* grade;
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    Student(const Student&);            //! Copy Constructor
    Student& operator=(const Student&); //! Copy Assignment Operator
    ~Student();
    void display() const;
    void init(const Student& source);   //! Private Member Function on Localization
};

Student::Student() {
    no = 0;
    ng = 0;
    grade = nullptr;
}

Student::Student(int sn) {
    float g[] = { 0.0f };
    grade = nullptr;            //! Assign Temporary Obj
    *this = Student(sn, g, 0); 
}

Student::Student(int sn, const float* g, int ng_) {
    bool valid = sn > 0 && g != nullptr && ng_ >= 0;
    if (valid)
        for (int i = 0; i < ng_ && valid; i++)
            valid = g[i] >= 0.0f && g[i] <= 100.0f;

    if (valid) {
        // accept the client's data 
        no = sn;
        ng = ng_;
        // allocate dynamic memory
        if (ng > 0) {
            grade = new float[ng];
            for (int i = 0; i < ng; i++)
                grade[i] = g[i];
        }
        else {
            grade = nullptr;
        }
    }
    else {
        grade = nullptr;    //! Assign Temporary Obj
        *this = Student();
    }
}

Student::Student(const Student& src) 
{
    // shallow copies
    no = src.no;
    ng = src.ng;

    if (src.grade != nullptr) 
    {
        grade = new float[ng];  // allocate dynamic memory for grades
        
        for (int i = 0; i < ng; i++)
            grade[i] = src.grade[i]; // copy data from the source resource to the newly allocated resource
    }
    else
    {
        grade = nullptr;    
    }


    //! Or we can call init function
    //! 
    //! init(source);
    //! 
    //! DONE !! :)))
    //! 
    

    //! Direct Call
    grade = nullptr;
    *this = src; // calls assignment operator
}

Student& Student::operator=(const Student& source)
{

    if (this != &source) // check for self-assignment
    {
        // shallow copy non-resource variables
        no = source.no;
        ng = source.ng;
        
        delete[] grade;  // deallocate previously allocated dynamic memory 


        
        if (source.grade != nullptr) 
        {
            grade = new float[ng]; // allocate new dynamic memory, if needed

            for (int i = 0; i < ng; i++)
                grade[i] = source.grade[i];   // copy the resource data
            /*
            To trap a self assignment from the client code (a = a). We compare the address of the current obj
            to the address of the source obj. If the addresses match, we skip the assignment logic altogether.
            If we neglect to check for self assignment, the deallocation statement would release the memory holding
            the resource data and we would lost access to the source resource resulting in our logic
            */
        }
        else 
        {
            grade = nullptr;
        }
    }
    return *this;

    //! Or we can call init function
    //! 
    //! 
    //! if (this != &source)  // check for self-assignment
    //! {  
    //! delete[] grade;   -> deallocate previously allocated dynamic memory 
    //! init(source);
    //! }
    //! return *this;
}


Student::~Student() 
{
    delete[] grade;
}

void Student::display() const
{
    if (no > 0) {
        cout << no << ":\n";
        cout.setf(ios::fixed);
        cout.precision(2);
        for (int i = 0; i < ng; i++) 
        {
            cout.width(6);
            cout << grade[i] << endl;
        }
        cout.unsetf(ios::fixed);
        cout.precision(6);
    }
    else {
        cout << "no data available" << endl;
    }
}

void Student::init(const Student& source) 
{
    no = source.no;
    ng = source.ng;
    if (source.grade != nullptr) {
        grade = new float[ng];
        for (int i = 0; i < ng; i++)
            grade[i] = source.grade[i];
    }
    else {
        grade = nullptr;
    }
}

int main() {
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3);
    harry.display();
}

/*
Deep Copies and Assignments


                    Source Obj --> Recipient Obj                            Source Obj --> Recipient Obj
                                                                                |               |
                      => Shallow Copy                                           V               V
                                                                          Source Resource --> Recipient Resource
     
                                                                                    => Deep Copy

If we change the resource data in an obj, we expect the resource data in the other obj to remain unchanged
Deep copying and deep assigning involve copying the resource data
Shallow copying and assigning involve copying the instance variable only and are only appropriate for non-resorce instance variable


Two Special member functions manage allocations and deallocations associated with deep copying and deep copy assigning
1. Copy Constructor:
_ Contains the logic for copying from a source obj to a newly created obj of the same type.
    + Creates an obj by initializing it to an existing obj
    + Copies an obj by value in a function call
    + Returns an obj by value from a function

    Declaration:
    Type(const Type&);
    Ex: Student(const Student&);

    Definition:
    1. Perform a shallow copy on all non-resource instance variables
    2. Allocate memory for each new resource
    3. Copy data from the source resource to the newly created resource

2. Copy Assignment Operator
_ Contains the logic for copying data from an existing obj to another existing obj

    Declaration:
    identifier = identifier;
    Type& operator= (const Type&);    -> The left Type is the return type and right Type is the source operand
    Ex: Student& operator=(const Student&); 




Localization
_ The code in the definition of the copy constructor is identical the most of the code in our definition of the assignment operator
Purpose: To avoid duplication and improve maintainability
    + Private member function: Localize the common code in a private member function and call that member function
    from both the copy constructor and the copy assignment operator

    + Direct call: Call the assignment operator directly from the copy constructor


Assigning Temporary Obj
Assigning Temporary Obj to the current obj requires additional code if the object manage resources.
Purpose: To prevent the assignment operator from releasing not-as-yet-acquired resources, initialize 
each resource instance variable to nullptr (empty value)


Copies Prohibited
Certain class designs require prohibiting clinet code from copying or copy assingning any instance of a class.
Purpose: To prohibit copying and copy assigning, declare copy constructor and the copy assignmnent operator as deleted members of our class


Summary: 
+ A class with resources requires custom definitions of a copy constructor, copy assignment operator and destructor
+ The copy constructor copies data from an existing object to a newly created object
+ The copy assignment operator copies data from an existing object to an existing object
+ Initialization, pass by value, and return by value client code invokes the copy constructor
+ The copy constructor and copy assignment operator should shallow copy only the non-resource instance variables
+ The copy assignment operator should check for self-assignment

*/