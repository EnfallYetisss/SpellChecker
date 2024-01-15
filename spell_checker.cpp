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
    }
    void suggestAlternatives(const string& misspelledWord) {
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
        return distance;
    }
    map<char, Point2D> layout; // Your existing layout map
    set<string> dictionary;
};

int main()
{
}