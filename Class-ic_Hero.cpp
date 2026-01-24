#include <iostream>
#include <string>
#include <random> 
#include <ctime>

using namespace std;

class Userhero {
private:
    string name;
    int strength;
    int courage;

public:
    Userhero(const string& heroName)
        : name(heroName)
    {
        // Assign random values
        strength = rand() % 100 + 1;
        courage = rand() % 100 + 1;
    }

    // Getter for name
    string getName() const { return name; }

    // Getter for strength
    int getStrength() const { return strength; }

    // Getter for courage
    int getCourage() const { return courage; }

    // Function to attend training
    void attendTraining(int time) {
        strength += time * 2; // Increase strength proportionally to time (e.g., 2 points per unit of time)
    }

    // Function to attend therapy
    void attendTherapy() {
        int courageBoost = rand() % 10 + 1; // Random increase between 1 and 10
        courage += courageBoost;
    }

    void reduceCourage(int amount) {
        courage -= amount;
        if (courage < 0) courage = 0; // make sure courage doesnt go negative.

    }
};

void sendHeroOnQuest(Userhero& hero) {

    int strength = hero.getStrength();
    int outcome = rand() % 100 + 1;

    string result;
    int courageLoss;

    //the more negative the result the more courage is lost more strength means better chances of sucess for next quest.
    if (outcome <= strength) {
        result = "Sucess!";
        courageLoss = 5;

    }
    else if (outcome <= strength + 30) {
        result = "Neutral.";
        courageLoss = 10;

    }
    else if (outcome <= strength + 60) {
        result = "Failure!";
        courageLoss = 20;
    }
    hero.reduceCourage(courageLoss);


    //Print result
    cout << hero.getName() << " Went on a quest. Result: " << result << endl;


}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    Userhero hero("Torvic");
    cout << "Name: " << hero.getName() << endl;
    cout << "Strength: " << hero.getStrength() << endl;
    cout << "Courage: " << hero.getCourage() << endl;

    // Hero attends training for 5 units of time
    hero.attendTraining(5);
    cout << "After training, Strength: " << hero.getStrength() << endl;


    // Hero attends therapy
    hero.attendTherapy();
    cout << "After therapy, Courage: " << hero.getCourage() << endl;


    //send hero on a quest
    sendHeroOnQuest(hero);
    cout << "after quest, Courage: " << hero.getCourage() << endl;


    return 0;
}