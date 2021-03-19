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

class JsonUtils
{
public:
    static int getInt(const std::string& key, const JSONNode& node, int defaultData = 0)
    {
        JSONNode::const_iterator it = node.find(key);
        if(it == node.end())
            return defaultData;
        
        int data = (int)it->as_int();
        return data;
    }
    
    static float getFloat(const std::string& key, const JSONNode& node, float defaultData = 0)
    {
        JSONNode::const_iterator it = node.find(key);
        if(it == node.end())
            return defaultData;
        
        float data = it->as_float();
        return data;
    }
    
    static std::string getString(const std::string& key, const JSONNode& node)
    {
        JSONNode::const_iterator it = node.find(key);
        if(it == node.end())
            return "";
        
        std::string data = it->as_string();
        return data;
    }
    
    template <typename T>
    static std::vector<std::shared_ptr<T>> getArray(const std::string& key, const JSONNode& node)
    {
        std::vector<std::shared_ptr<T>> vecData;
        
        JSONNode::const_iterator it = node.find(key);
        if(it == node.end())
            return vecData;

        for(auto iter = it->begin(); iter != it->end(); ++iter)
        {
            std::shared_ptr<T> ptr = std::make_shared<T>(*iter);
            vecData.emplace_back(ptr);
        }
        
        return vecData;
    }
};

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
    
public:
    Person(const JSONNode& node)
    {
        name_ = JsonUtils::getString("이름", node);
        sex_ = JsonUtils::getString("성별", node);
        age_ = JsonUtils::getInt("나이", node);
        time_ = JsonUtils::getFloat("시간", node);
        friends_ = JsonUtils::getArray<Person>("친구", node);
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
    

    return 0;
}
