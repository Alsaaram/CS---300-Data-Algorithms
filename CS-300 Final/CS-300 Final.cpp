{\rtf1\ansi\ansicpg1252\cocoartf2639
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <fstream>\
#include <sstream>\
#include <vector>\
#include <algorithm>\
\
struct Course \{\
    std::string number;\
    std::string title;\
    std::vector<std::string> prereqs;\
\};\
\
void loadCourses(const std::string& fileName, std::vector<Course>& courses) \{\
    std::ifstream file(fileName);\
    if (!file.is_open()) \{\
        std::cerr << "Error: Could not open file " << fileName << std::endl;\
        return;\
    \}\
\
    std::string line;\
    while (std::getline(file, line)) \{\
        std::stringstream ss(line);\
        Course course;\
        std::getline(ss, course.number, ',');\
        std::getline(ss, course.title, ',');\
        std::string prereq;\
        while (std::getline(ss, prereq, ',')) \{\
            course.prereqs.push_back(prereq);\
        \}\
        courses.push_back(course);\
    \}\
\
    file.close();\
\}\
\
void printCourse(const Course& course) \{\
    std::cout << "Course Number: " << course.number << std::endl;\
    std::cout << "Course Title: " << course.title << std::endl;\
    std::cout << "Prerequisites: ";\
    for (const auto& prereq : course.prereqs) \{\
        std::cout << prereq << ", ";\
    \}\
    std::cout << std::endl;\
\}\
\
int main() \{\
    std::vector<Course> courses;\
    std::string fileName;\
    std::cout << "Enter the file name: ";\
    std::cin >> fileName;\
\
    loadCourses(fileName, courses);\
\
    int choice;\
    while (true) \{\
        std::cout << "Menu:\\n";\
        std::cout << "1. Print Course List\\n";\
        std::cout << "2. Print Course Information\\n";\
        std::cout << "3. Exit\\n";\
        std::cout << "Enter your choice: ";\
        std::cin >> choice;\
\
        switch (choice) \{\
            case 1:\
                for (const auto& course : courses) \{\
                    std::cout << course.number << ", " << course.title << std::endl;\
                \}\
                break;\
            case 2: \{\
                std::string courseNumber;\
                std::cout << "Enter the course number: ";\
                std::cin >> courseNumber;\
                auto it = std::find_if(courses.begin(), courses.end(),\
                                       [&courseNumber](const Course& c) \{ return c.number == courseNumber; \});\
                if (it != courses.end()) \{\
                    printCourse(*it);\
                \} else \{\
                    std::cout << "Course not found.\\n";\
                \}\
                break;\
            \}\
            case 3:\
                std::cout << "Exiting the program. Goodbye!\\n";\
                return 0;\
            default:\
                std::cout << "Invalid choice. Please try again.\\n";\
                break;\
        \}\
    \}\
\
    return 0;\
\}\
}