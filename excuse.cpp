#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

/*
 Function: personalizeExcuse
 Purpose : Replaces all occurrences of "{name}" in the excuse template
           with the actual student name entered by the user.
*/
string personalizeExcuse(string excuse, const string& name) {
    size_t pos = excuse.find("{name}");

    // Loop to replace ALL occurrences of {name}
    while (pos != string::npos) {
        excuse.replace(pos, 6, name); // 6 = length of "{name}"
        pos = excuse.find("{name}");
    }

    return excuse;
}

int main() {
    // Seed the random number generator using current time
    // Ensures different output every time the program runs
    srand(static_cast<unsigned int>(time(0)));

    string name;

    // Take input from user
    cout << "Enter student name: ";
    getline(cin, name);

    // Vector storing excuse templates
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the internet stopped working suddenly.",
        "{name} was about to submit the work, but the laptop battery died unexpectedly.",
        "{name} had a family emergency and couldn't focus on studies.",
        "{name}'s notebook was accidentally taken by a friend.",
        "{name} forgot the deadline due to a misunderstanding of the schedule.",
        "{name} was not feeling well and had to rest all day.",
        "{name} faced technical issues while uploading the assignment.",
        "{name}'s file got corrupted just before submission.",
        "{name} had to attend an urgent function at home.",
        "{name} was preparing hard but couldn't finish on time due to unforeseen issues."
    };

    // Generate a random index within valid range
    int randomIndex = rand() % excuses.size();

    // Select a random excuse
    string selectedExcuse = excuses[randomIndex];

    // Personalize the excuse with user's name
    string finalExcuse = personalizeExcuse(selectedExcuse, name);

    // Display result
    cout << "\n📚 Student Excuse Generator 📚\n";
    cout << finalExcuse << endl;

    return 0;
}