#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Correct replacement function (no bug here)
string personalizeRoast(string roast, string name) {
    size_t pos = roast.find("{name}");
    
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }
    
    return roast;
}

int main() {
    srand(time(0));

    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    vector<string> roasts = {
        "{name}, you're not stupid—you just have bad luck thinking.",
        "{name}, you bring everyone joy… when you leave.",
        "{name}, you're like a cloud—when you go away, it's a good day.",
        "{name}, I'd explain it to you, but I left my crayons at home.",
        "{name}, you're proof that evolution can go in reverse.",
        "{name}, your brain is on airplane mode.",
        "{name}, you don't need a mirror—you already disappoint yourself.",
        "{name}, even Google can't understand you.",
        "{name}, your logic took a holiday and never came back.",
        "{name}, if common sense were money, you'd be broke."
    };
    int randomIndex = rand() % (roasts.size() - 1);

    string selectedRoast = roasts[randomIndex];

    string finalRoast = personalizeRoast(selectedRoast, name);

    cout << "\n🔥 Roast Generator 🔥\n";
    cout << finalRoast << endl;

    return 0;
}