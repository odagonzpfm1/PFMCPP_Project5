/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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
    void printStudentName();
    void printTeacherFavoriteStyle();
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

void GuitarClass::printStudentName()
{
    std::cout << "Student name is: " << this->guitarStudent.name << std::endl;
}

void GuitarClass::printTeacherFavoriteStyle()
{
    std::cout << "Teacher favorite style is: " << this->guitarTeacher.favoriteStyle << std::endl;
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
    void printIsGuitarConnected();
    void printIsBassistConnected();
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

void JamSession::printIsGuitarConnected()
{
    std::cout << "The guitarist is : " << (this->leadGuitarist.myGuitar.isConnected ? "connected" : "disconnected") << std::endl;
}

void JamSession::printIsBassistConnected()
{
    std::cout << "The bass player is : " << (this->bassPlayer.myBass.isConnected ? "connected" : "disconnected") << std::endl;
}

int main() {
    GuitarClass firstClass = GuitarClass();
    JamSession secondClass = JamSession();

    std::string studentName = firstClass.getStudentName();
    std::string teacherFavoriteStyle = firstClass.getTeacherFavoriteStyle();

    std::cout << "**********************" << std::endl;
    
    std::cout << "Student name is: " << studentName << std::endl;
    std::cout << "Teacher favorite style is: " << teacherFavoriteStyle << std::endl;
    std::cout << "The guitarist is : " << (secondClass.isGuitaristConnected() ? "connected" : "disconnected") << std::endl;
    std::cout << "The bass player is : " << (secondClass.isBassistConnected() ? "connected" : "disconnected") << std::endl;

    std::cout << "**********************" << std::endl;

    firstClass.printStudentName();
    firstClass.printTeacherFavoriteStyle();
    secondClass.printIsGuitarConnected();
    secondClass.printIsBassistConnected();

    std::cout << "**********************" << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
