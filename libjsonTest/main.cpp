//
//  main.cpp
//  newtest
//
//  Created by CD-hj0949 on 2021/03/18.
//  Copyright © 2021 CD-hj0949. All rights reserved.
//

#include <iostream>
#include "libjson/libjson.h"

#include "JSONOptions.h"
#include <vector>
#include <string.h>

class Person
{
private:
    std::vector<std::shared_ptr<Person>> friends_;
    std::string name_;
    std::string sex_;
    int age_;
    float time_;
    
public:
    std::string getName() { return name_; }
    std::string getSex() { return sex_; }
    int getAge() { return age_; }
    float getTime() { return time_; }
    std::vector<std::shared_ptr<Person>>& getFriends() { return friends_; }
    ///////
public:
    Person(const JSONNode& node)
    {
        name_ = (node.find("이름"))->as_string();
        
        if(node.end() != node.find("성별"))
        {
            sex_ = (node.find("성별"))->as_string();
        }
        else
        {
            sex_ = "";
        }
        
        if(node.end() != node.find("나이"))
        {
            age_ = (int)(node.find("나이"))->as_int();
        }
        else
        {
            age_ = 0;
        }
        
        if(node.end() != node.find("시간"))
        {
            time_ = (float)(node.find("시간"))->as_float();
        }
        else
        {
            age_ = 0.f;
        }
        
        JSONNode::const_iterator nodeIter = node.find("친구");
        if(node.end() != nodeIter)
        {
            JSONNode::const_iterator iter_begin = nodeIter->begin();
            for(; iter_begin != nodeIter->end(); ++iter_begin)
            {
                std::shared_ptr<Person> ptr = std::make_shared<Person>(*iter_begin);
                friends_.emplace_back(ptr);
            }
        }
    }

    ~Person(){};
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::string strJSON = "{\"이름\": \"윤병훈\", \
    \"나이\": 30, \
    \"성별\": \"남\", \
    \"친구\": [{\"이름\": \"안녕\"}, {\"이름\": \"엘리자베스\"}], \
    \"시간\": \"0.25\" }";
    
    JSONNode node = libjson::parse(strJSON);
    Person person(node);
    
    printf("%s\n", person.getName().c_str());
    printf("%d\n", person.getAge());
    printf("%s\n", person.getSex().c_str());
    printf("%f\n", person.getTime());

    std::vector<std::shared_ptr<Person>> person_vec = person.getFriends();
    for(auto& vec : person_vec)
    {
        printf("%s\n", vec->getName().c_str());
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
