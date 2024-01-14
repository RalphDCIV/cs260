#include <iostream>
#include <string>
#include <random>


//creating the bag structure
struct bag {
std::string color;
bool occupation; 
int slot;
};

//creating the array
const int bagspace = 1000;
bag bagsize[bagspace];

int pull() {
    //setting up the random number gen 
    std::random_device rd;
    std::mt19937 rng(rd());

    //getting the upper bound for the ran number generator
    int upperbound = 0;
     for (int i = 0; i < bagspace; i+=1 ){
        if (bagsize[i].slot > upperbound){
           upperbound = bagsize[i].slot;
        }


    }
    //Check if there are any marbles in the bag.
    if (upperbound == 0) {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "no marbles in the bag" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        return 0;
    }
    //setting the random number
    std::uniform_int_distribution<int> distribution( 1, upperbound);
    int removal = distribution(rng);
    //std::cout << "TESTINGTESTINGTESTINGTESTINGTESTINGTESTING: " << removal << std::endl;
    

    //removing the marble
    for (int i = 0; i < bagspace; i+=1 ){
        if (bagsize[i].slot == removal) {
            std::cout << "------------------------------- " << std::endl;
            std::cout << "You took out a " << bagsize[i].color << " Marble." << std::endl;
            std::cout << "------------------------------- " << std::endl;
            bagsize[i].color = "" ;
            bagsize[i].occupation = false;
            bagsize[i].slot = 0;
            return 0;
        }

    }




    //std::cout <<  removal << std::endl;

    return 0;
}




int add(){
    for (int i = 0; i < bagspace; i+=1 ){
        //find an empty spot in the bag
        if (bagsize[i].occupation == false){
            //set up variable
            std::string marblecolor;

            //get user input
            std::cout << std::endl;
            std::cout << "what color is your marble?: ";
            std::getline(std::cin, marblecolor);
            //set the marbles variable.
            bagsize[i].color = marblecolor ;
            bagsize[i].occupation = true;
            return 0;
        }



    }
    std::cout << "your bag is full, try taking some out first";
    return 0;
}







int look(){
    for (int i = 0; i < bagspace; i+=1 ) {
        // print out all spots in the array that have a marble in them
        if (bagsize[i].occupation == true) {
            std::cout << "------------------------------- " << std::endl;
            std::cout << "Marble slot: " << bagsize[i].slot << std::endl;
            std::cout << "Marble Color: " << bagsize[i].color << std::endl;
        }
    }
    std::cout << "------------------------------- " << std::endl;
    return 0;
}

//sets the marble slot (which determines what spot its in with ignoring blank spaces)
int setslot(){
    int slot = 1;
    for (int i = 0; i < bagspace; i+=1 ) {
        if (bagsize[i].occupation == true) {
            bagsize[i].slot = slot;
            slot+=1;
        }

    }
    return 0;
}
//main function
int main() {
    std::string userchoice;
    bool on = true;

    /// setup the spaces in the bag
    for (int i = 0; i < bagspace; i+=1 ) {
        bagsize[i].color = "" ;
        bagsize[i].occupation = false;
        bagsize[i].slot = 0;

    }


    while (on == true) {
        //call the setslot function
        setslot();


        //Menu
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "type 'ADD' to add a marble to the bag" << std::endl;
        std::cout << "type 'PULL' to remove a marble from the bag at random" << std::endl;
        std::cout << "type 'LOOK' to see what marbles are in the bag" << std::endl;
        std::cout << "Type 'EXIT' to exit the program" << std::endl;
        
        
        //get user input
        std::getline(std::cin, userchoice);
        for (char& c : userchoice) {
        c = std::tolower(c);
        }


        //process user input
        if (userchoice == "add") {
            add();
        } else if (userchoice == "pull") {
            pull();
        } else if (userchoice == "look") {
            look();
        } else if (userchoice == "exit") {
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "-Exiting the program have an above average day!-" << std::endl;
            std::cout << "------------------------------------------------" << std::endl;
            return 1;
        } else {
            std::cout << "please type a valid command, cause that one wasn't" << std::endl;
        }
        
    }




    return 0;

};