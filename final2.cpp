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

            // we need to check if there is anyone in line
            bool isEmpty(){
                return head == nullptr; // this checks if the string is empty and returns true or false
            }

            // now we need to add someone to the back of the line
            

};
