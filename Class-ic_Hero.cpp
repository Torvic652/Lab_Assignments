#include <iostream>
#include <string>
#include <vector> // For managing multiple heroes
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
        if (courage < 0) courage = 0; // Ensure courage doesn't go negative
    }
};

void sendHeroOnQuest(Userhero& hero) {
    int strength = hero.getStrength();
    int outcome = rand() % 100 + 1;

    string result;
    int courageLoss;

    // The more negative the result, the more courage is lost. More strength means better chances of success.
    if (outcome <= strength) {
        result = "Success!";
        courageLoss = 5;
    } else if (outcome <= strength + 30) {
        result = "Neutral.";
        courageLoss = 10;
    } else {
        result = "Failure!";
        courageLoss = 20;
    }
    hero.reduceCourage(courageLoss);

    // Print result
    cout << hero.getName() << " went on a quest. Result: " << result << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Create multiple heroes
    vector<Userhero> heroes = {
        Userhero("Torvic"),
        Userhero("David"),
        Userhero("Hulk"),
        Userhero("Muny")
    };

    // Display initial stats for all heroes
    for (const auto& hero : heroes) {
        cout << "Name: " << hero.getName() << ", Strength: " << hero.getStrength()
             << ", Courage: " << hero.getCourage() << endl;
    }

    cout << endl;

    // Train all heroes
    for (auto& hero : heroes) {
        hero.attendTraining(5); // Train each hero for 5 units of time
    }

    // Display stats after training
    cout << "After training:" << endl;
    for (const auto& hero : heroes) {
        cout << "Name: " << hero.getName() << ", Strength: " << hero.getStrength()
             << ", Courage: " << hero.getCourage() << endl;
    }

    cout << endl;

    // Send all heroes on quests
    for (auto& hero : heroes) {
        sendHeroOnQuest(hero);
    }

    // Display stats after quests
    cout << "After quests:" << endl;
    for (const auto& hero : heroes) {
        cout << "Name: " << hero.getName() << ", Strength: " << hero.getStrength()
             << ", Courage: " << hero.getCourage() << endl;
    }

    return 0;
}