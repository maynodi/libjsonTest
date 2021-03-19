//
//  main.cpp
//  libjson_test1
//
//  Created by CD-hj0949 on 2021/03/19.
//

#include <iostream>
#include "tinyxml.h"

int main(int argc, const char * argv[]) {
    // insert code here...
  
//    //xml 선언
//    TiXmlDocument doc;
//    TiXmlDeclaration* pDec1 = new TiXmlDeclaration("1.0", "", "");
//    doc.LinkEndChild(pDec1);
//
//    //루트 노드 추가
//    TiXmlElement* pRoot = new TiXmlElement("DB");
//    doc.LinkEndChild(pRoot);
//
//    //주석 문장 추가
//    TiXmlComment* pComment = new TiXmlComment();
//    pComment->SetValue("This is score DB");
//    pRoot->LinkEndChild(pComment);
//
//    // 하위노드 및 데이터 추가
//    TiXmlElement* pElem = new TiXmlElement("class1");
//    pRoot->LinkEndChild(pElem);
//    TiXmlElement* pElem0 = new TiXmlElement("Teacher");
//    pElem0->LinkEndChild(new TiXmlElement("JJJ"));
//    pElem->LinkEndChild(pElem0);
//
//    //하위노드 및 속성 추가
//    TiXmlElement* pSubElem = new TiXmlElement("English");
//    pElem->LinkEndChild(pSubElem);
//    pSubElem->SetAttribute("name", "score");
//    pSubElem->SetAttribute("aa", 100);
//    pSubElem->SetAttribute("bb", 50);
//    pSubElem->SetAttribute("cc", 90);
//
//    pSubElem = new TiXmlElement("Math");
//    pElem->LinkEndChild(pSubElem);
//    pSubElem->SetAttribute("name", "score");
//    pSubElem->SetAttribute("aa", 90);
//    pSubElem->SetAttribute("bb", 70);
//    pSubElem->SetAttribute("cc", 95);
//
//    pElem = new TiXmlElement("class2");
//    pRoot->LinkEndChild(pElem);
//    pElem0 = new TiXmlElement("Teacher");
//    pElem0->LinkEndChild(new TiXmlElement("SSS"));
//    pElem->LinkEndChild(pElem0);
//
//    pSubElem = new TiXmlElement("English");
//    pElem->LinkEndChild(pSubElem);
//    pSubElem->SetAttribute("name", "score");
//    pSubElem->SetAttribute("ab", 70);
//    pSubElem->SetAttribute("vc", 90);
//    pSubElem->SetAttribute("ds", 30);
//
//    pSubElem = new TiXmlElement("Math");
//    pElem->LinkEndChild(pSubElem);
//    pSubElem->SetAttribute("name", "score");
//    pSubElem->SetAttribute("ab", 60);
//    pSubElem->SetAttribute("vc", 70);
//    pSubElem->SetAttribute("ds", 25);
//
//   doc.SaveFile("Test.xml");
    
    
    ///////======================
    TiXmlDocument ReadDoc;
    ReadDoc.LoadFile("Test.xml");// xml 파일 로드
        //"DB"라는 노드를 찾는다
    TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
    //ReadRoot("DB")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
        TiXmlElement* sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("Teacher");
    TiXmlHandle handle(0);// 노드를 다루기 위한 핸들
    handle = TiXmlHandle(sub);
    //ReadRoot->Value() ReadRoot의 노드 명을 반환한다 "DB"
        std::cout << ReadRoot->Value() << std::endl;
        //핸들에 저장된 노드 하위에 존재하는 노드를 찾는다. 그 노드명을 반환한다.
    TiXmlElement* tmp = handle.FirstChildElement().Element();
    std::cout << tmp->Value() << std::endl;

    sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("English");
    //sub(class1->english의 속성을 읽어온다.
        TiXmlAttribute *pAttrib;
    pAttrib = sub->FirstAttribute();
    while (pAttrib)
    {
        std::cout << pAttrib->Name() <<"  " << pAttrib->Value() << std::endl;
        pAttrib = pAttrib->Next();
    }
    
    return 0;
}
