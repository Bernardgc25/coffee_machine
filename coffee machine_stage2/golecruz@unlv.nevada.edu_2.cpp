// Bernard J. Gole Cruz, CS 202-2002, Assignment 2 stage2
// This program is a continuation of CoffeeMachine class  with additional MilkCoffeemachine class
// an implementation of class inheritance

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//global constant
const int DEFAULT_CAPACITY = 10;

//class declaration
class CoffeeMachine{
public:
	//default constructor
	CoffeeMachine(){
		this->curr_water = 0;
		this->curr_coffee = 0;
		this->water_capacity = DEFAULT_CAPACITY;
		this->coffee_capacity = DEFAULT_CAPACITY;
	    this->coffee_spoons_per_cup = 1;
		this-> name = "UNTITLED";
        cout << "created coffee machine" << right << setw(9) << name << right << setw(22) << "with empty resources." << endl;
	}
	//second constructor with coffee machine name
	CoffeeMachine(string name){
		this->curr_water = 0;
		this->curr_coffee = 0;
		this->water_capacity = DEFAULT_CAPACITY;
		this->coffee_capacity = DEFAULT_CAPACITY;
	    this->coffee_spoons_per_cup = 1;
		this-> name = "DECAF";
        cout << "created coffee machine" << right << setw(6) << name << right << setw(22) << "with empty resources." << endl;
	}
	//third constructor with coffee machine, water capacity, coffee capacity parameter
	CoffeeMachine(string name, int x, int y){
        this->curr_water = 0;
        this->curr_coffee = 0;
        this->coffee_spoons_per_cup = 1;
        this-> name = "BLEND";
        cout << "Starting up Coffee Machine" << right << setw(6) << name << right << setw(37) << "with empty resources and capacities:" << endl;
        this->water_capacity = x;
        this->coffee_capacity = y;
        cout << right << setw(22) << "water_capacity=" << water_capacity << endl;
        cout << right << setw(23) << "coffee_capacity=" << coffee_capacity << endl;
		cout << endl;
	}
	//destructor
	~CoffeeMachine(){
		cout << "shutting down Coffee Machine " << name << " with the following resources left:" << endl;
		cout << right << setw(7) << "water:" << curr_water << endl;
		cout << right << setw(8) << "coffee:" << curr_coffee << endl;
        cout << endl;
	}

	string name;
	int makeCups(int);
	void addWater(int);
	void addCoffee(int);
	void setCoffeeSpoonsPerCup(int);
	void displayCM();

protected:
	int coffee_spoons_per_cup;

private:
	int water_capacity;
	int coffee_capacity;
	int curr_water;
	int curr_coffee;
	void makeSingleCup();

};

//Functions
//mutator function, set water
void CoffeeMachine::addWater(int w){
        int water_overflow;
        curr_water = w;

        //nothing happen
        if (curr_water <= 0){
            return;
            }

        //fills water to full if request amount is more than default capacity
        if (curr_water > water_capacity){
            water_overflow = curr_water - water_capacity;
            curr_water = curr_water - water_overflow;
            }
};

//mutator function, set coffee
void CoffeeMachine::addCoffee(int c){
        int coffee_overflow;
        curr_coffee = c;

        //nothing happen
        if (curr_coffee <= 0){
            return;
            }

        //fills coffee to full if request amount is more than the default capacity
        if (curr_coffee > coffee_capacity){
            coffee_overflow = curr_coffee - coffee_capacity;
            curr_coffee = curr_coffee - coffee_overflow;
            }
};


//check if resources are enough before making a cup
int CoffeeMachine::makeCups(int cups){

        //will not make coffee if resources are not enough
        if (cups > curr_water || cups > curr_coffee ){
            cout << right << setw(3) << "ordered " << cups << " cups of coffee of strength 1" << endl;
            cout <<"NOT ENOUGH RESOURCES!" ;
            cout << endl;
            }

        //will make coffee if resources are enough base on number of order
        else{
            cout <<"ordered " << cups << " cups of coffee of strength 1" << endl;
                int i = 0;
                while (i < cups ){
                    makeSingleCup();
                    i++;
                    }

        //update the status of current water/coffee level in container
        curr_water = curr_water - cups;
        curr_coffee = curr_coffee - cups;
        cout << endl;
            }
};

//make coffee per cup
void CoffeeMachine::makeSingleCup(){
  cout << "...made cup of coffee " << name << "..." << endl;
};

//display current state
void CoffeeMachine::displayCM(){
    //update status depending on the coffee machine created
    cout <<"Current state of CM: " << name <<endl;
    cout << right << setw(7) << "WATER:" << right << setw(3) << curr_water << right << setw(2) << "/" << right << setw(3) << water_capacity << right << setw(7) << "(cups)" << endl;
    cout << right << setw(8) << "COFFEE:" << right << setw(2) << curr_coffee << right << setw(2) << "/" << right << setw(3) << coffee_capacity << right << setw(9) << "(spoons)" << endl;
    cout << right << setw(10) << "STRENGTH:" << right << setw(2) << coffee_spoons_per_cup << right << setw(22) << "coffee spoons per cup" << endl;

};

//coffee spoon per cup
void CoffeeMachine::setCoffeeSpoonsPerCup(int cspc){
     coffee_spoons_per_cup = cspc;
};


//Derived class
class MilkCoffeeMachine: public CoffeeMachine{
public:
    //MilkCoffeeMachine(int m): CoffeeMachine("DECAF", x,y)
    MilkCoffeeMachine(string name, int x, int y, int m):CoffeeMachine(name, x, y){
        this->name = name;
        this->curr_milk = 0;
        this->milk_capacity = m;
        this->milk_spoons_per_cup = 1;
    }

    ~MilkCoffeeMachine(){
        cout << "shutting down Coffee Machine" << right << setw(6) << name << right << setw(35) << "with the following resources left:" << endl;
		cout << right << setw(6) << "milk:" << curr_milk - curr_milk << endl;
        cout << endl;
    }

    void addMilk(int);
    void setMilkSpoonsPerCup(int);
    //override
    int makeCups(int);
    //override
    void displayCM();


protected:
    int milk_spoons_per_cup;
private:
    int milk_capacity;
    int curr_milk;
};

//functions
void MilkCoffeeMachine::addMilk(int m)
{
 int mil_overflow;
        curr_milk = m;

        if (curr_milk <= 0){
        //nothing happen
            return;
            }

        //fills milk to full if amount is more than the default capacity
        if (curr_milk > milk_capacity){
            mil_overflow = curr_milk - milk_capacity;
            curr_milk = curr_milk - mil_overflow;
            }
};

void MilkCoffeeMachine::setMilkSpoonsPerCup(int mspc){
milk_spoons_per_cup = mspc;
};

//override version
int MilkCoffeeMachine::makeCups(int cups){

  //call makeCups function from CoffeeMachine class
  CoffeeMachine::makeCups(cups);

  //coffee with milk
  int with_milk = curr_milk;

  //coffee without milk
  int without_milk = milk_capacity - curr_milk;


  //display the number of coffee with and without milk
  cout << with_milk << right << setw(4) << "of" << right
  << setw(3) << milk_capacity << right << setw(44) << "cups have milk added. insufficient milk for"
  << right << setw(3) << without_milk << right << setw(6) << "cups" << endl ;
  cout << endl;
};

 //override version
void MilkCoffeeMachine::displayCM(){
CoffeeMachine::displayCM();
cout << right << setw(6) << "MILK:" << right << setw(4) << curr_milk << right << setw(2) << "/" << right << setw(3) << milk_capacity << right << setw(9) << "(spoons)" << endl;
cout << right << setw(11) << "MILK PART:" << right << setw(2) << milk_spoons_per_cup << right << setw(20) << "milk spoons per cup" << endl;
cout << endl;
};



int main(){
/////////////////////////////////////////////////////////////////////////////////
    //test run for stage 1, results are different due to overridden functions
    //proceed to stage 2

/*
	CoffeeMachine cm1; //activate UNTITLED coffee machine
      //cm1 objects
    cm1.addWater(8); //add water
    cm1.addCoffee(8);//add coffee
    cm1.displayCM(); //display current state
    cm1.makeCups(5); //make a cup
    cm1.displayCM();


    CoffeeMachine cm2("DECAF"); //activate DECAF coffee machine
      //cm2 objects
    cm2.addWater(10); //add water
    cm2.addCoffee(10);//add coffee
    cm2.displayCM();  //display current state
    cm2.makeCups(14); //make a cup
    cout << endl;
    cout << endl;

    CoffeeMachine cm3("BLEND",15,20); // activate BLEND coffee machine
     //cm3 objects
    cm3.addWater(14); //add water
    cm3.addCoffee(20);//add coffee
    cm3.displayCM();  //display current state
    cm3.makeCups(12); //make a cup
    cm3.displayCM();
    cm3.makeCups(5);  //make a cup
    cout << right << setw(7) << "ABORT." << endl;
*/


//////////////////////////////////////////////////////////////////////////////////
     //test run of stage 2, result is based on the assignment

     //cm1 objects
    MilkCoffeeMachine cm1("DECAF",8,8,8); //active DECAF milk coffee machine
    cm1.addWater(8); //add water
    cm1.addCoffee(8);//add coffee
    cm1.addMilk(8);  //add milk
    cm1.makeCups(8); //make a cup

     //cm2 objects
    MilkCoffeeMachine cm2("BLEND",15,30,26); //activate BLEND milk coffee machine
    cm2.setMilkSpoonsPerCup(2); //set milk spoon per cup
    cm2.displayCM(); //display current state
    cm2.makeCups(10);//make a cup
    cm2.displayCM(); //display current state
    cm2.makeCups(5); //make a cup
    cm2.displayCM(); //display current state

	system("pause");
	return 0;
}
