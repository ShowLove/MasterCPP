/*
 * XmlParser.cpp
 * Main Class to manage XML operations
 * Created by: Ozgur Pekcagliyan - 2014-10-05 12:28:32 PM EEST
 * Last edited by: Ozgur Pekcagliyan - 2015-03-07
 * Notes:
 *
*/

#include <string>
// #include <map>
#include <stack>
#include <iostream> // TODO:This will be romeved in working copy
#include "PrintFromXml/headers/XmlParser.h"

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::vector;
using namespace XmlSpace;


void XmlParser::vectorizeString (const string &str) // This will tokenize a string and fill a vector
{
    std::cout << "Started parsing XML data" << std::endl;
    deleteAll();//clean tree just in case
    int nodePtr = -1;
    string tempStr(str);
    string tempToken;
    size_t pos, posBeg, posSpace;
    stack<XmlNode *> nodeStack; //This will hold nodes and 
    bool comment = false;
    while((pos = tempStr.find(">")) != string::npos) //find a node
    {
        std::cout << "Found next end of node indicator >" << std::endl;
        tempToken = tempStr.substr(0, pos);
        if(nodeStack.empty())
        {
            std::cout << "Requested starting next tree" << std::endl;
            ++nodePtr;
        }
        if(tempToken.substr(0, 4) == "<!--")
        {
            std::cout << "Found comment in XML, will ignore next data" << std::endl;
            tempToken.erase(0, 4); //remove head part for not to find it twice
            std::cout << "Looking for end part for comment section" << std::endl;
            if( (posBeg = tempToken.find("--")) != string::npos)
            {
                std::cout << "Found comment end, data till here will be deleted" << std::endl;
                tempStr.erase(0, 4 + posBeg + 3);
                if(nodeStack.empty())
                {
                    std::cout << "This comment were itself a new tree, so, tree requested for this one has taken back" << std::endl;
                    --nodePtr;
                }
            }
            else
            {
                std::cout << "Removing entire block, since end of comment couldn't be found yet" << std::endl;
                comment = true;
                tempStr.erase(0, pos + 1);
            }
    }
    else if(tempToken.substr(pos - 2, pos) == "--" && comment)
    {
        std::cout << "End of comment section found, removing data till here" << std::endl;
        tempStr.erase(0, pos + 1);
        comment = false;
        if(nodeStack.empty())
        {
            std::cout << "This comment were itself a new tree, so, tree requested for this one has taken back" << std::endl;
            --nodePtr;
        }
    }
    else 
    {
        if(tempToken[pos - 1] == '/' && !comment) //<br/>
        {
            std::cout << "Found a node looking like <br/>" << std::endl;
            string nodeName;
            string tempSlashToken = tempToken;
            size_t c = 0;
            while ((posBeg = tempSlashToken.find("<")) != string::npos) //what if it is inside of another node, we don't want to mess with parrent node, so, we will try to find exact position which should be the last node
            {
                c += posBeg;
                tempSlashToken.erase(0, posBeg + 1);
            }
            std::cout << "Found exact position of node" << std::endl;
            tempSlashToken = tempToken.substr(c, string::npos);
            std::cout << "Looking for potential attributes" << std::endl;
            if ((posSpace = tempSlashToken.find(" ")) != string::npos)
            {
                std::cout << "There are spaces inside the node, this generally means attributes, calling attribute finder" << std::endl;
                nodeName = tempSlashToken.substr(0, posSpace);
                char buffer[256];
                sprintf(buffer, "Name of the node: %s", nodeName.c_str());
                attributeFinder(tempSlashToken, nodeStack, nodePtr, posSpace, "/" ); //this deletes first < char
            }
            else
            {
                nodeName = tempSlashToken.substr(1, tempSlashToken.size() - 2); // -2 because of />
                char buffer[256];
                sprintf(buffer, "Name of the node: %s", nodeName.c_str());
                XmlNode *temp = createNode(nodeName, nodePtr);
                nodeStack.top() -> subNodes.push_back(temp);
                std::cout << "Node as added as a child node to the top node in stack" << std::endl;
            }
            tempStr.erase(c, pos - c + 1); // just <asdasd/> part not the whole body
            std::cout << "Ndoe data removed from temp memeory" << std::endl;
        }

        else if ((posSpace = tempToken.find(" ")) != string::npos && tempToken.find("</") == string::npos && !comment) //<a href="sf">
        {
            std::cout << "Found a node which includes attributes" << std::endl;
            posBeg = tempToken.find("<");
            string nodeName = tempToken.substr(posBeg + 1, posSpace - posBeg - 1);
            char buffer[256];
            std::cout << buffer << std::endl;
            size_t tempPos = posSpace - posBeg;
            std::cout << "Calling attribute finder" << std::endl;
            attributeFinder(tempToken, nodeStack, nodePtr, posSpace);
            //Lets find its value and clear tags ;)
            std::cout << "Clearing tags to find its entire node value" << std::endl;
            XmlNode *node = nodeStack.top();
            node -> nodeName = nodeName; //fixing nodeName
            string endNode = "</";
            endNode += nodeName + ">";
            if((posSpace = tempStr.find(endNode.c_str())) == string::npos) //like <body color=#ffffff>.....................</body>
            {
                string log = "Node doesn't have an end: ";
                log += nodeName;
                std::cout<< log << std::endl;
                //FIXME: houston we got a probllem
            }
            string nodeVal = tempStr.substr(pos + 1, posSpace - pos - 1);
            nodeStack.top() -> nodeVal = nodeVal; //This is added into stack by attribute finder
            std::cout << "Node value updated inside of stack" << std::endl;
            tempStr.erase(0, pos + 1); //erase read part
            std::cout << "Ndoe data removed from temp memeory" << std::endl;
        }
        else if(!comment)//<asd> qwe </asd>
        {
            if(tempToken.find("</") != string::npos) // asd</asd>
            {
                std::cout << "Found end of a node and node removed from stack" << std::endl;
                //FIXME: Be sure stack is not empty and this XML is valid
                nodeStack.pop();
            }
            else // <asd>
            {
                std::cout << "Found a new node" << std::endl;
                std::cout << "Clearing tags to find its entire node value" << std::endl;
                posBeg = tempToken.find("<");
                string nodeName = tempToken.substr(posBeg + 1, string::npos); //0th element should be <
                char buffer[256];
                sprintf(buffer, "Name of the node: %s", nodeName.c_str());
                std::cout << buffer << std::endl;
                string endNode = "</";
                endNode += nodeName + ">";
                if((posSpace = tempStr.find(endNode.c_str())) == string::npos)//like <body>.....................</body>
                {
                    string log = "Node doesn't have an end: ";
                    log += nodeName;
                    std::cout <<"Node doesn't have an end: " << log << std::endl;
                    //FIXME: houston we got a probllem
                }
                string nodeVal = tempStr.substr(pos + 1, posSpace - pos - 1);
                XmlNode *temp = createNode(nodeName, nodePtr, nodeVal); //create an empty node
                std::cout << "New node created by create node function" << std::endl;
                if(temp == NULL) //we have just modified and this mmeans stack should also be empty
                {
                    nodeStack.push(head[nodePtr]); //insert firs element to stack
                    std::cout << "Stack is empty, so found is the head of a new tree and tree head added to stack" << std::endl;
                }
                else
                {
                    nodeStack.top() -> subNodes.push_back(temp);
                    std::cout << "Node added as a subnode of the top node in stack" << std::endl;
                    nodeStack.push(temp);
                    std::cout << "Node added as the top node into stack" << std::endl;
                }
            }
            tempStr.erase(0, pos + 1); //erase read part
            //tempStr.erase(posBeg, endNode.size()); //erase read part
        }
    }
}
    if(nodeStack.empty() == false)
    {
        std::cout << "Invalid XML data!" << std::endl;
        //Oh no we have an invalid XML and couldn't complete XML
    }
}

void XmlParser::attributeFinder(string tempToken, stack<XmlNode *> &nodeStack, int &nodePtr, size_t &posSpace, string delim)
{
    std::cout << "Strated looking for attributes" << std::endl;
    string nodeName = tempToken.substr(1, posSpace - 1); //0th element should be <
    size_t posTemp;
    XmlNode *temp = createNode(nodeName, nodePtr);
    if(temp == NULL)
    {
        //TODO: be sure stack is empty!
        std::cout << "Added head of tree into nodeStack" << std::endl;
        nodeStack.push(head[nodePtr]); //insert firs element to stack
        temp = nodeStack.top();
    }
    else
    {
        nodeStack.top() -> subNodes.push_back(temp);
        std::cout << "Node added as a subnode of the top node in stack" << std::endl;
        nodeStack.push(temp);
        std::cout << "Node added to stack" << std::endl;
    }
    if (delim == "/")
    {
        std::cout << "This is just a single node, so it is removed from stack ex: <br/> or <br test=1/>" << std::endl;
        nodeStack.pop();//node cloased
    }
    tempToken.erase(0, posSpace + 1);
    string attrName, attrValue;
    bool hasQuote;
    std::cout << "Strated scanning for attributes" << std::endl;
    while((posTemp = tempToken.find("=")) != string::npos)
    {
        hasQuote = false;
        attrName = tempToken.substr(0, posTemp); //range between space and = sign like //<a href=
        std::cout << "Found attribute name" << std::endl;
        if(tempToken[posTemp + 1] == '\"')
        {
            std::cout << "Attribute has quotes so moved posSpace pointer accordingly" << std::endl;
            hasQuote = true;
            ++posTemp; //Move to other side of quote
            posSpace = tempToken.substr(posTemp + 1, string::npos).find("\"") + posTemp + 1; // FIXME:So expensive
        }
        else
        {
            std::cout << "Attribute doesn't have any quotes so moved posSpace pointer accordingly" << std::endl;
            if((posSpace = tempToken.find(" ")) == string::npos)
            {
                if(delim.empty() == false)
                {
                    posSpace = tempToken.find(delim);
                }
                else
                {
                    posSpace = tempToken.size();
                }
            }
        }
        attrValue = tempToken.substr(posTemp + 1, posSpace - posTemp - 1);
        std::cout << "Found attribute value" << std::endl;
        if(hasQuote)
        {
            tempToken.erase(0, posSpace + 2);
        }
        else
        {
            tempToken.erase(0, posSpace + 1);
        }
        std::cout << "Removed attribute from temp memory" << std::endl;
        XmlAttribute *tempAttr = new XmlAttribute();
        tempAttr -> attrName = attrName;
        tempAttr -> attrVal = attrValue;
        temp -> attributes.push_back(tempAttr);
        std::cout << "Saved attribute into node memory" << std::endl;
    }
}

XmlNode * XmlParser::createNode (const string &nodeName, int nodePtr, const string nodeVal)
{
    std::cout << "Started creating a new node" << std::endl;
    XmlNode *newNode = new XmlNode(); // TODO: This should be deleted by destructor/
    newNode -> nodeName = nodeName;
    newNode -> nodeVal = nodeVal;
    if(currNode.empty() == true)
    {
        currNode.push(newNode);
    }
    if(head.size() <= nodePtr)
    {
        std::cout << "Started a new tree" << std::endl;
        head.push_back(newNode);
        return NULL; //indicates that we have initialized new tree and modified head.
    }
    return newNode;
}

void XmlParser::printTree(XmlNode *node)
{
    std::cout << "This function is only for debug purposes and it won't be supported in the future" << std::endl;
    static int nodePtr = 0;
    if(head.size() > nodePtr)
    {
        if(node == NULL)
        {
            node = head[nodePtr];
        }
        int attrSize = node -> attributes.size();
        int subNodesize = node -> subNodes.size();
        int i;
        cout<<"Node name: "<<node -> nodeName<<endl;
        for( i = 0; i < attrSize; ++i)
        {
            cout<<node -> attributes[i] -> attrName<<" = "<<node -> attributes[i] -> attrVal<<endl;
        }
        cout<<"Node Value: "<<node -> nodeVal<<endl<<"-------------------"<<endl;
        for(i = 0; i < subNodesize; ++i)
        {
            printTree(node -> subNodes[i]);
        }
        if(node == head[nodePtr])
        {
            ++nodePtr;
            printTree();
        }
    }
    else
    {
        cout<<"End of tree"<<endl;
    }
}

XmlParser::XmlParser()
{
    nodePtr = 0;
}

XmlParser::~XmlParser()
{
    deleteAll();
}

void XmlParser::deleteAll(XmlNode *node)
{
    static int nodePtr = 0;
    string log = "Strated destroying all nodes with current tree ";
    log += nodePtr;
    std::cout << log << std::endl;
    static stack<XmlNode *> nodeStack;
    if(head.size() > nodePtr)
    {
        if(node == NULL)
        {
            node = head[nodePtr];
        }
        int attrSize = node -> attributes.size();
        int subNodesize = node -> subNodes.size();
        int i;
        std::cout << "Strated destroying all attributes" << std::endl;
        for( i = attrSize - 1; i >= 0; --i)
        {
            delete node -> attributes[i];
            //cout<<node -> attributes[i] -> attrName<<" = "<<node -> attributes[i] -> attrVal<<endl;
        }
        //cout<<"Node Value: "<<node -> nodeVal<<endl<<"-------------------"<<endl;
        std::cout << "Strated saving all subnodes to memeory to destroy them" << std::endl;
        for(i = 0; i < subNodesize; ++i)
        {
            nodeStack.push(node -> subNodes[i]);
            deleteAll(node -> subNodes[i]);
        }
        std::cout << "Current tree stored in memory and starting actual delete operations" << std::endl;
        if(node == head[nodePtr])
        {
            //head.clear();
            std::cout << "Deleting all nodes in memory for current tree" << std::endl;
            while(!nodeStack.empty())
            {
                node = nodeStack.top();
                nodeStack.pop();
                delete node;
            }
            ++nodePtr;
            string log = "Current tree destroyed, starting next tree ";
            log += nodePtr;
            std::cout << log << std::endl;
            deleteAll();
        }
    }
    else
    {
        head.clear();
    }
}

bool XmlParser::loadXmlTree(const string &data) //This will generate a tree and load it into memeory
{
    std::cout << "Loading XML Data..." << std::endl;
    vectorizeString(data);
    return true;
}

string XmlParser::operator[](int num) //This will return attributes value.
{
    std::cout << "Atrribute requested with [number]" << std::endl;
    string result;
    if(num > 0)
    {
        getAttributeValue(result, num);
    }
    return result;
}

string XmlParser::operator[](const string &attr) //This will return attributes value.
{
    std::cout << "Attribute reequested with [string]" << std::endl;
    string result;
    getAttributeValue(result, attr);
    return result;
}

bool XmlParser::getNodeValue(std::string &result) //This will nodes attributes value.
{
    std::cout << "Node value requested" << std::endl;
    XmlNode *node = currNode.top();
    if(node -> nodeName.size() > 0)
    {
        result = node -> nodeVal;
        return true;
    }
    std::cout << "Error with current node, can not return its value. Size of the name of the node is <= 0" << std::endl;
    return false;
}

bool XmlParser::getAttributeValue(string &result, const string &attr) //This will return attributes value.
{
    string log  = "Looking for an attribute value... ";
    log += attr;
    std::cout << log << std::endl;
    XmlNode *node = currNode.top();
    int attrSize = node -> attributes.size();
    for(int i = 0; i < attrSize; ++i)
    {
        if(node -> attributes[i] -> attrName == attr)
        {
            result = node -> attributes[i] -> attrVal;
            std::cout << "Attribute found" << std::endl;
            return true;
        }
    }
    std::cout << "Attribute can not be found" << std::endl;
    return false;
}

bool XmlParser::getAttributeValue(string &result, int num) //This will return attributes value.
{
    string log  = "Looking for an attribute value by number... ";
    log += num;
    std::cout << log << std::endl;
    XmlNode *node = currNode.top();
    if(node -> attributes.size() >= num)
    {
        result = node -> attributes[num - 1] -> attrVal;
        std::cout << "Attribute found" << std::endl;
        return true;
    }
    std::cout << "Attribute can not be found" << std::endl;
    return false;
}

bool XmlParser::findNode (const string &nodeName) // This is the function which we will show to user
{
    string log  = "Looking for a node... ";
    log += nodeName;
    std::cout << log << std::endl;
    stack <XmlNode *>tempHead = currNode;
    if( findNode (NULL, nodeName) == false)
    {
        std::cout << "Node can not be found" << std::endl;
        currNode = tempHead;
        return false;
    }
    std::cout << "Node found" << std::endl;
    return true;
}

bool XmlParser::findNode (XmlNode *head, const string &nodeName) //This is the real traverse function and every other function will call it
{
    //FIXME: Add an algorithm to keep searching from beginning until reaches to start point
    std::cout << "Started main node finding function..." << std::endl;
    static int nodePtr = 0;
    XmlNode *sNode = currNode.top();
    //if(this -> head.size() > nodePtr)
    //{
        if(head == NULL)
        {
            currNode.pop();
            if(currNode.empty() == true && this -> head.size() > nodePtr)
            {
                std::cout << "Jumping next tree" << std::endl;
                currNode.push(this -> head[nodePtr++]);
            }
            else if(this -> head.size() < nodePtr)
            {
                return false;
            }
            head = currNode.top();
        //if(sNode != head[0])
        //{
            //printTree(node -> subNodes[i]);
        // }
        // node = head[nodePtr];
        }
        //int attrSize = head -> attributes.size();
        int subNodesize = head -> subNodes.size();
        int i;
        std::cout << "Checking current node" << std::endl;
        if(nodeName == head -> nodeName && head != sNode)
        {
            std::cout << "Node found here" << std::endl;
            currNode.push(head);
            return true;
        }
        std::cout << "Started looking for sub nodes" << std::endl;
        for(i = 0; i < subNodesize; ++i)
        {
            if(head != sNode)
            {
                currNode.push(head);
            }
            if(findNode(head -> subNodes[i], nodeName) == true) //found it don't search any more
            {
                return true;
            }
        }
        std::cout << "Completed looking to sub nodes, will try next tree" << std::endl;
        if(head == sNode)
        {
            //currHead.pop();
            if(findNode(NULL, nodeName) == true) //found it don't search any more
            {
                return true;
            }
        }
    //}
    std::cout << "Node can not be found" << std::endl;
    //else
    //{
    return false;
    //}
}
