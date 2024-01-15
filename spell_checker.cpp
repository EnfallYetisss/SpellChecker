//https://github.com/EnfallYetisss/SpellChecker
#include<algorithm>
#include<fstream>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;
class Point2D {
public:
    // Constructors
    Point2D() : x(0.0), y(0.0) {}
    Point2D(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Accessors
    double getX() const { return x; }
    double getY() const { return y; }

    // Mutators
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }
    double distanceTo(const Point2D& other) const {
        double deltaX = x - other.x;
        double deltaY = y - other.y;
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
    }

private:
    double x, y;
};
class SpellChecker {
public:
    // Function to suggest alternatives for a misspelled word
    SpellChecker()
    {
        layout['q'] = Point2D(0, 0);
        layout['w'] = Point2D(1, 0);
        layout['e'] = Point2D(2, 0);
        layout['r'] = Point2D(3, 0);
        layout['t'] = Point2D(4, 0);
        layout['y'] = Point2D(5, 0);
        layout['u'] = Point2D(6, 0);
        layout['i'] = Point2D(7, 0);
        layout['o'] = Point2D(8, 0);
        layout['p'] = Point2D(9, 0);
        layout['a'] = Point2D(0, 1);
        layout['s'] = Point2D(1, 1);
        layout['d'] = Point2D(2, 1);
        layout['f'] = Point2D(3, 1);
        layout['g'] = Point2D(4, 1);
        layout['h'] = Point2D(5, 1);
        layout['j'] = Point2D(6, 1);
        layout['k'] = Point2D(7, 1);
        layout['l'] = Point2D(8, 1);
        layout['z'] = Point2D(0.5, 2);
        layout['x'] = Point2D(1.5, 2);
        layout['c'] = Point2D(2.5, 2);
        layout['v'] = Point2D(3.5, 2);
        layout['b'] = Point2D(4.5, 2);
        layout['n'] = Point2D(5.5, 2);
        layout['m'] = Point2D(6.5, 2);
    }
    void suggestAlternatives(const string& misspelledWord) {
        const double threshold = 2.0; // You can adjust this threshold based on your preference
        vector<pair<string, double>> suggestions;

        for (const auto& dictWord : dictionary) {
            double distance = calculateDistance(misspelledWord, dictWord);
            suggestions.push_back({ dictWord, distance });
        }

        // Sort suggestions based on distance and absolute difference in string length
        sort(suggestions.begin(), suggestions.end(),
            [misspelledWord](const auto& a, const auto& b) {
                double diffA = std::abs(static_cast<int>(a.first.length()) - static_cast<int>(misspelledWord.length()));
                double diffB = std::abs(static_cast<int>(b.first.length()) - static_cast<int>(misspelledWord.length()));

                if (a.second != b.second) {
                    return a.second < b.second;
                }
                else {
                    // If distances are the same, prioritize by absolute difference in string length
                    return diffA < diffB;
                }
            });

        // Display the top 3 closest suggestions
        cout << "Suggestions:\n";
        for (size_t i = 0; i < std::min<size_t>(3, suggestions.size()); ++i) {
            //cout << suggestions[i].first << " (Distance: " << suggestions[i].second << ")\n";
            cout << suggestions[i].first << endl;
        }
    }
    // Function to add a word to the dictionary
    void addToDictionary(const string& word) {
        dictionary.insert(word);
    }

    // Function to check if a word is in the dictionary
    bool isInDictionary(const string& word) const {
        return dictionary.count(word) > 0;
    }
private:
    
    double calculateDistance(const string& word1, const string& word2) const {
        double distance = 0.0;

        // Ensure both words have the same length
        size_t minLen = std::min<size_t>(word1.length(), word2.length());

        for (size_t i = 0; i < minLen; ++i) {
            char char1 = word1[i];
            char char2 = word2[i];

            // Check if characters are in the layout map
            if (layout.count(char1) > 0 && layout.count(char2) > 0) {
                distance += layout.at(char1).distanceTo(layout.at(char2));
            }
        }

        return distance;
    }
    map<char, Point2D> layout; // Your existing layout map
    set<string> dictionary;
};

int main()
{
    SpellChecker sc;
    string temp;
    ifstream file("words.txt");
    sc.addToDictionary("a");
    while (!file.eof())
    {
        file >> temp;
        //cout << temp << endl;
        if (temp.length() != 1)
        {
            sc.addToDictionary(temp);
        }
        //words to store in dictionary
    }
    file.close();
    string word;
    cout << "enter word\n";
    cin >> word;
    for (char& c : word) {
        c = std::tolower(c);
    }

    if (sc.isInDictionary(word))
    {
        cout << "it is present in dictionary";
    }
    else
    {
        sc.suggestAlternatives(word);
    }
}
