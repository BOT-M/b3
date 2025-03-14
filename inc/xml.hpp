#pragma once

#include <iostream>
#include <tinyxml2.h>
#include <unordered_map>
#include <vector>

using namespace tinyxml2;
using namespace std;

// 存储消息结构信息
struct FieldInfo
{
    string name;
    string type;
};

unordered_map<int, vector<FieldInfo>> messageSchema;

void ParseTypes(XMLElement *types)
{
    // 解析 composite 类型
    for (XMLElement *composite = types->FirstChildElement("composite");
         composite;
         composite = composite->NextSiblingElement("composite"))
    {

        cout << "\nComposite: " << composite->Attribute("name")
             << " - " << composite->Attribute("description") << endl;

        for (XMLElement *type = composite->FirstChildElement("type");
             type;
             type = type->NextSiblingElement("type"))
        {

            cout << "  Type: " << type->Attribute("name")
                 << " (" << type->Attribute("primitiveType") << ")"
                 << endl;
        }
    }

    // 解析枚举类型
    for (XMLElement *enm = types->FirstChildElement("enum");
         enm;
         enm = enm->NextSiblingElement("enum"))
    {

        cout << "\nEnum: " << enm->Attribute("name")
             << " - " << enm->Attribute("description") << endl;

        for (XMLElement *validValue = enm->FirstChildElement("validValue");
             validValue;
             validValue = validValue->NextSiblingElement("validValue"))
        {

            cout << "  " << validValue->Attribute("name")
                 << " = " << validValue->GetText()
                 << endl;
        }
    }
}

void ParseMessages(XMLElement* messages) {
    for (XMLElement* msg = messages->FirstChildElement("message");
         msg;
         msg = msg->NextSiblingElement("message")) {
        
        cout << "\nMessage: " << msg->Attribute("name")
             << " (ID:" << msg->Attribute("id") << ")"
             << " - " << msg->Attribute("description") << endl;

        // 解析字段
        for (XMLElement* field = msg->FirstChildElement("field");
             field;
             field = field->NextSiblingElement("field")) {
            
            cout << "  Field: " << field->Attribute("name")
                 << " (ID:" << field->Attribute("id") << ")"
                 << " Type: " << field->Attribute("type")
                 << endl;
        }
    }
}

void loadSchema(const string &filename)
{
    XMLDocument doc;
    if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
    {
        cerr << "无法加载 XML 文件: " << filename << endl;
        return;
    }

    XMLElement* root1 = doc.RootElement();
    
    // 解析类型定义
    if (XMLElement* types = root1->FirstChildElement("types")) {
        ParseTypes(types);
    }

    // 解析消息定义
    if (XMLElement* messages = root1->FirstChildElement("message")) {
        ParseMessages(messages);
    }

    XMLElement *root = doc.FirstChildElement("sbe:messageSchema");
    if (!root)
    {
        cerr << "XML 结构错误: 缺少 messageSchema" << endl;
        return;
    }

    for (XMLElement *child = root->FirstChildElement(); child != nullptr;
         child = child->NextSiblingElement())
    { // 遍历子元素[2,4,7](@ref)
        // 处理每个子节点
        const char *text = child->GetText(); // 获取节点文本[4,7](@ref)
        if (text)
        {
            std::cout << "Text: " << text << std::endl;
        }
    }

    for (XMLElement *msg = root->FirstChildElement("sbe:message"); msg; msg = msg->NextSiblingElement("sbe:message"))
    {
        int id = msg->IntAttribute("id");
        vector<FieldInfo> fields;

        for (XMLElement *field = msg->FirstChildElement("field"); field; field = field->NextSiblingElement("field"))
        {
            FieldInfo info;
            info.name = field->Attribute("name");
            info.type = field->Attribute("type");
            fields.push_back(info);
        }
        messageSchema[id] = fields;
    }

    cout << "📥 成功加载 " << messageSchema.size() << " 个消息模板！" << endl;
}