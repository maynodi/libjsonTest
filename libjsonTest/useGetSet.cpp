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

class Person : public std::enable_shared_from_this<Person>
{
private:
    std::vector<std::shared_ptr<Person>> friends_;
    std::string name_;
    std::string sex_;
    int age_;
    float time_;
    
public:
    void setName(std::string name) { name_ = name; }
    void setSex(std::string sex) { sex_ = sex; }
    void setAge(int age) { age_ = age; }
    void setTime(float time) { time_ = time; }
    
public:
    void addFriends(std::shared_ptr<Person> person) { friends_.emplace_back(person); }
    
public:
    std::string getName() { return name_; }
    std::string getSex() { return sex_; }
    int getAge() { return age_; }
    float getTime() { return time_; }
    std::vector<std::shared_ptr<Person>>& getFriends() { return friends_; }
};

void parseJSON(JSONNode& node, Person* person)
{
//    JSONNode::iterator iter = node.begin();
//    while(node.end() != iter)
//    {
//
//        if( JSON_ARRAY == iter->type())
//        {
//            parseJSON(*iter, <#Person *person#>)
//        }
//
//        std::string nodeName = iter->name();
//
//        if("이름" == nodeName)
//        {
//            person->setName(iter->as_string());
//        }
//        else if("나이" == nodeName)
//        {
//            person->setAge((int)iter->as_int());
//        }
//        else if("성별" == nodeName)
//        {
//            person->setSex(iter->as_string());
//        }
//        else if("시간" == nodeName)
//        {
//            person->setTime((float)iter->as_float());
//        }
//
//        ++iter;
//    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::string strJSON = "{\"이름\": \"윤병훈\", \
    \"나이\": 30, \
    \"성별\": \"남\", \
    \"친구\": [{\"이름\": \"윤병훈\"}, {\"이름\": \"엘리자베스\"}], \
    \"시간\": \"0.25\" }";
    
    JSONNode node = libjson::parse(strJSON);
    
    Person person;
    
    JSONNode::iterator iter = node.begin();
    while(node.end() != iter)
    {
        if( JSON_ARRAY == iter->type())
        {
            if("친구" == iter->name())
            {
                JSONNode arrfriend = iter->as_array();
                for(auto& arr : arrfriend)
                {
                    std::shared_ptr<Person> person_friend1 = std::make_shared<Person>();
                    
                    person_friend1->setName(arr.as_string());
                    person_friend1->setAge(0);
                    person_friend1->setSex("");
                    person_friend1->setTime(0);
                    
                    person.addFriends(person_friend1);
                }

            }
        }
        
        std::string nodeName = iter->name();
        
        if("이름" == nodeName)
        {
            person.setName(iter->as_string());
        }
        else if("나이" == nodeName)
        {
            person.setAge((int)iter->as_int());
        }
        else if("성별" == nodeName)
        {
            person.setSex(iter->as_string());
        }
        else if("시간" == nodeName)
        {
            person.setTime((float)iter->as_float());
        }
        
        ++iter;
    }
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
