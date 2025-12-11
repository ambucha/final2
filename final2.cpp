#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

// Milestone 1

// seems this time the isntructions did not say to not write comments so i will just write them
// ok so lets start off by making the struct that has the customer name and drink order
// im also gonna just put the custumer struct inside the double linked list
// ok but now we can make a struct to sue in the deque as i believe that is easier
struct Muffin{
    string name;
    string muffin;
}

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

                // if has nodes
                if(head){
                    head->prev = nullptr;
                }
                else{
                    tail = nullptr;
                }

                // free the og head
                delete temp;
                return true;
            }

            // destructor
            ~Coffee() {
                while (head) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
            }
};

// main functino time
int main() {

    srand(time(0));

    // lemme get some names and drink names for to pull randomly into the coffee line
    vector<string> names = {
        "Ava", "Mateo", "Noah", "Mia", "Sofia", "Liam", "Kai", "Zoe",
        "Ethan", "Aria", "Leo", "Nora", "Jayden", "Ivy", "Owen", "Luna",
        "Lucas", "Amelia", "Elijah", "Isabella", "Benjamin", "Charlotte"
    };
    
    vector<string> drinks = {
        "Latte", "Cappuccino", "Americano", "Mocha", "Cold Brew",
        "Espresso", "Iced Coffee", "Vanilla Latte", "Caramel Latte"
    };

    vector<string> muffins = {
        "Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin",
        "Corn Muffin", "Pumpkin Muffin", "Bran Muffin", "Lemon Poppy Muffin"
    };

    Coffee coffeeLine;
    
    // muffin booth here, needs to store both name and drink
    deque<Muffin> muffinLine; 

    // ok now i gotta excercise the things done in this milestone, so i can just add liek 2 random customers and then serve one to test
    // milestone 2 i needa add 3 people to the line, now we need to add three to bnoth the muffin and coffee both
    for(int i = 0; i < 3; i++){
        string n = names[rand() % names.size()];
        string d = drinks[rand() % drinks.size()];
        coffeeLine.push_back(n, d);
        // since later imma have different booths lemme be more specific here
        cout << "Waiting at the coffee booth: " << n << " [" << d << "]" << endl;
    }

    // i need to run the sim for 10 rounds now so lets get a for loop going
    for(int i = 1; i <= 10; i++){
        // changin the formatting a bit here to look a little nicer
        cout << "------|Round #" << i << "|------" << endl;

        // gotta add a 50% chance for someone joining, so mod 2 == 1 should simulate that 
        if(rand() % 2 == 1){
            string n = names[rand() % names.size()];
            string d = drinks[rand() % drinks.size()];
            coffeeLine.push_back(n, d);
            cout << "\tJoined the coffee booth line: " << n << " [" << d << "]" << endl;
        }
        else {
            cout << "\tJoined the coffee booth line: No one" << endl;
        }

        // every round the first person in line needs to be served
        string cName;
        string cDrink;
        if(coffeeLine.pop_front(cName, cDrink)){
            cout << "\tServed at the coffee booth: " << cName << " [" << cDrink << "]" << endl;
        }
        else{
            cout << "\tServed at the coffee booth: No one" << endl;
        }
    }
    
    return 0;
}

