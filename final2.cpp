#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Milestone 1

// seems this time the isntructions did not say to not write comments so i will just write them
// ok so lets start off by making the struct that has the customer name and drink order
// im also gonna just put the custumer struct inside the double linked list

// lemme try to find an old project with a linked list so i can modify that code
// found a doubly linked list from my lab-22 repo, gonna modify it to fit this assignment
// imma honestly keep it as a DLL
class Coffee{
    private:
    // make the struct for the customer data and connections
        struct Node{
            string name;
            string drink;
            Node* prev;
            Node* next;

            // difference here is that there are more variables, also i can tuse n for the node since i am using it for the string now
            Node(string n, string d, Node* p = nullptr, Node* x = nullptr){
                name = n;
                drink = d;
                prev = p;
                next = x;
            }
        };

        Node* head;
        Node* tail;

        public:
            Coffee(){ head = nullptr; tail = nullptr;}

            // i was reading over my DLL and there actually isnt a need for an isempty function since i check before i do anything to it anyways

            // now we need to add someone to the back of the line
            void push_back(string n, string d){
                Node* newNode = new Node(n, d);
                if(!tail){// if no tail then empty
                    head = tail = newNode;
                } 
                else {
                    tail->next = newNode;
                    newNode -> prev = tail;
                    tail = newNode;
                }
            }

            // now we add something for serving people, i can make this a bool so that if the string is empty then noone is served
            // using variables here will allow us to be able to actually print who got served, initially i was gonna leave it out but then realized it would be hard to say who got served each round that way
            bool pop_front(string &n, string &d){
                if(!head){
                    return false; // here is where using a bool function si good so later in the main function we can use it as a conditional for if someone is served
                }

                Node* temp = head;
                n = temp->name;
                d = temp->drink;

                head = temp->next;

};
