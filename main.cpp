/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/


#include <iostream>
#include <stdlib.h>

// UDT 1:
struct Student 
{
    int grade;
    std::string name;
    int courseID = 0;
    int age;
    int studentID;

    Student(std::string givenName)
    {
        grade = 50;
        name = givenName;
        age = 18;
        studentID = 123456;
    }
    ~Student();

    void printStudentID();
    void printStudentName();
    void printStudentGrade();
};

Student::~Student() {}

void Student::printStudentID() 
{
    std::cout << "Student ID: " << studentID << std::endl;
}

void Student::printStudentName() 
{
    std::cout << "Student Name: " << name << std::endl;
}

void Student::printStudentGrade() 
{
    for(int i = 0; i < 4; i++)
    {
        grade += 10; 
    }
    std::cout << "Student Grade: " << grade << std::endl;
}

// UDT 2:
struct Guitarist
{
    int age;
    std::string favoriteStyle;
    std::string name;
    std::string favoriteGuitarBrand;
    float height;

    Guitarist();
    ~Guitarist();

    struct Guitar
    {
        std::string brand;
        std::string model;
        int numberOfStrings;
        float volume;
        bool isConnected;

        Guitar() :
            brand{"Fender"},
            model{"Stratocaster"},
            numberOfStrings{6},
            volume{5.0f},
            isConnected{false}
        {
            std::cout << "The guitar for the guitarrist has been created!" << std::endl;
        }
        ~Guitar();

        void volumeUp(float);
        void volumeDown(float);
        void connect();
        void disconnect();
    };

    Guitar myGuitar;

    void connectGuitar();
    void disconnectGuitar();
    void turnVolumeUp(float);
    void turnVolumeDown(float);
};

Guitarist::Guitarist() : age(35), favoriteStyle("Metal"), name("John"), favoriteGuitarBrand("Schecter"), height(6.2f) {}

Guitarist::~Guitarist() {}

Guitarist::Guitar::~Guitar() {}

void Guitarist::Guitar::volumeUp(float value)
{
    volume += value;
}

void Guitarist::Guitar::volumeDown(float value)
{
    volume -= value;
}

void Guitarist::Guitar::connect()
{
    isConnected = true;
}

void Guitarist::Guitar::disconnect()
{
    isConnected = false;
}

void Guitarist::connectGuitar()
{
    myGuitar.connect();
}

void Guitarist::disconnectGuitar()
{
    myGuitar.disconnect();
}

void Guitarist::turnVolumeUp(float value = 0.1f)
{
    myGuitar.volumeUp(value);
}

void Guitarist::turnVolumeDown(float value = 0.1f)
{
    myGuitar.volumeDown(value);
}

// UDT 3:
struct Bassist
{
    int age;
    std::string favoriteStyle = "Jazz";
    std::string name;
    std::string favoriteBassBrand;
    float height;

    Bassist(int, float);
    ~Bassist();

    struct Bass
    {
        std::string brand;
        std::string model;
        int numberOfStrings;
        float volume;
        bool isConnected;

        Bass(int, std::string, std::string, bool);
        ~Bass();

        void volumeUp(float);
        void volumeDown(float);
        void connect();
        void disconnect();
    };

    Bass myBass = Bass(5, "Fender", "Player", true);

    void turnVolumeUp(float);
    void turnVolumeDown(float);
    void slapTheBass();
};

Bassist::Bassist(int givenAge, float givenHeight)
{
    age = givenAge;
    height = givenHeight;
    name = "Carol";
    favoriteBassBrand = "Fender";
}

Bassist::~Bassist() {}

Bassist::Bass::Bass(int givenNumberOfStrings, std::string givenBrand, std::string givenModel, bool givenIsConnected)
{
    numberOfStrings = givenNumberOfStrings;
    brand = givenBrand;
    model = givenModel;
    isConnected = givenIsConnected;
    volume = 0.0f;
}

Bassist::Bass::~Bass() {}

void Bassist::Bass::volumeUp(float value)
{
    while (volume < 50.0f)
    {
        volume += value;
    }
}

void Bassist::Bass::volumeDown(float value)
{
    volume -= value;
}

void Bassist::Bass::connect()
{
    isConnected = true;
}

void Bassist::Bass::disconnect()
{
    isConnected = false;
}

void Bassist::turnVolumeUp(float value)
{
    myBass.volumeUp(value);
}

void Bassist::turnVolumeDown(float value)
{
    myBass.volumeDown(value);
}

void Bassist::slapTheBass()
{
    std::cout << "Slapping the bass!" << std::endl;
}

// new UDT 4:
struct GuitarClass
{
    Student guitarStudent = Student("Joe");
    Guitarist guitarTeacher;

    GuitarClass();
    ~GuitarClass();

    std::string getStudentName();
    std::string getTeacherFavoriteStyle();
};

GuitarClass::GuitarClass()
{
    std::cout << "Guitar class created!" << std::endl;
}

GuitarClass::~GuitarClass() 
{
    std::cout << "Guitar class was destructed!" << std::endl;
}

std::string GuitarClass::getStudentName()
{
    return guitarStudent.name;
}

std::string GuitarClass::getTeacherFavoriteStyle()
{
    return guitarTeacher.favoriteStyle;
}

// new UDT 5:
struct JamSession
{
    Guitarist leadGuitarist;
    Bassist bassPlayer = Bassist(21, 5.9f);

    JamSession();
    ~JamSession();

    bool isGuitaristConnected();
    bool isBassistConnected();
};

JamSession::JamSession()
{
    std::cout << "Jam Session Created!" << std::endl;
}

JamSession::~JamSession()
{
    std::cout << "Jam Session Destructed!" << std::endl;
}

bool JamSession::isGuitaristConnected()
{
    return leadGuitarist.myGuitar.isConnected;
}

bool JamSession::isBassistConnected()
{
    return bassPlayer.myBass.isConnected;
}

int main() {
    GuitarClass firstClass = GuitarClass();
    JamSession secondClass = JamSession();

    std::string studentName = firstClass.getStudentName();
    std::string teacherFavoriteStyle = firstClass.getTeacherFavoriteStyle();
    
    std::cout << "Student name is: " << studentName << std::endl;
    std::cout << "Teacher favorite style is: " << teacherFavoriteStyle << std::endl;
    std::cout << "The guitarist is : " << (secondClass.isGuitaristConnected() ? "connected" : "disconnected") << std::endl;
    std::cout << "The bass player is : " << (secondClass.isBassistConnected() ? "connected" : "disconnected") << std::endl;
    std::cout << "good to go!" << std::endl;
}
