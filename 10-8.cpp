#include <iostream>
#include <string>
using namespace std;

typedef string* strPtr;

class Television {
public:
    Television();
    Television(string type, double inch, strPtr modes, int modesNum);
    Television(const Television& other);
    Television& operator=(const Television& other);
    ~Television();

    string getType() const;
    double getInches() const;
    string getModes(int index) const;
    void output() const;

private:
    string displayType;
    double dimension;
    strPtr connectivitySupport;
    int numConnectivityModes;
};

int main() {
    string defaultType;
    double defaultDimension;
    int defaultModesNum;

    cout << "Enter the default display type: ";
    cin >> defaultType;
    cout << "Enter the default dimension (in inches): ";
    cin >> defaultDimension;
    cout << "Enter the number of default connectivity modes: ";
    cin >> defaultModesNum;

    strPtr defaultConnectivity = new string[defaultModesNum];
    cout << "Enter the default connectivity modes: " << endl;
    for (int i = 0; i < defaultModesNum; ++i) {
        cout << i + 1 << ": ";
        cin >> defaultConnectivity[i];
    }

    Television defaultTV(defaultType, defaultDimension, defaultConnectivity, defaultModesNum);
    defaultTV.output();

    int TVnum;
    cout << "Enter the number of televisions: ";
    cin >> TVnum;

    Television* TVList = new Television[TVnum];
    for (int i = 0; i < TVnum; ++i) {
        TVList[i] = Television(defaultTV);
    }

    int id;
    cout << "Customize TV (1 to " << TVnum << ", -1 to quit): ";
    while (cin >> id && id != -1) {
        if (id >= 1 && id <= TVnum) {
            string customType;
            double customDimension;
            strPtr customConnectivity = new string[defaultModesNum];

            cout << "Enter the custom display type: ";
            cin >> customType;
            cout << "Enter the custom dimension (in inches): ";
            cin >> customDimension;
            cout << "Enter the custom connectivity modes: " << endl;
            for (int i = 0; i < defaultModesNum; ++i) {
                cout << i + 1 << ": ";
                cin >> customConnectivity[i];
            }

            TVList[id - 1] = Television(customType, customDimension, customConnectivity, defaultModesNum);

            delete[] customConnectivity;
        }
        else {
            cout << "Invalid index." << endl;
        }
        cout << "Customize TV (1 to " << TVnum << ", -1 to quit): ";
    }

    for (int i = 0; i < TVnum; ++i) {
        TVList[i].output();
    }

    delete[] defaultConnectivity;
    delete[] TVList;

    return 0;
}

Television::Television() : displayType(""), dimension(0.0), connectivitySupport(nullptr), numConnectivityModes(0) {}

Television::Television(string type, double inch, strPtr modes, int modesNum)
    : displayType(type), dimension(inch), numConnectivityModes(modesNum) {
    connectivitySupport = new string[numConnectivityModes];
    for (int i = 0; i < numConnectivityModes; ++i) {
        connectivitySupport[i] = modes[i];
    }
}

Television::Television(const Television& other)
    : displayType(other.displayType), dimension(other.dimension), numConnectivityModes(other.numConnectivityModes) {
    connectivitySupport = new string[numConnectivityModes];
    for (int i = 0; i < numConnectivityModes; ++i) {
        connectivitySupport[i] = other.connectivitySupport[i];
    }
}

Television& Television::operator=(const Television& other) {
    if (this == &other) {
        return *this;
    }
    delete[] connectivitySupport;

    displayType = other.displayType;
    dimension = other.dimension;
    numConnectivityModes = other.numConnectivityModes;
    connectivitySupport = new string[numConnectivityModes];
    for (int i = 0; i < numConnectivityModes; ++i) {
        connectivitySupport[i] = other.connectivitySupport[i];
    }

    return *this;
}

Television::~Television() {
    delete[] connectivitySupport;
}

string Television::getType() const {
    return displayType;
}

double Television::getInches() const {
    return dimension;
}

string Television::getModes(int index) const {
    return connectivitySupport[index];
}

void Television::output() const {
    cout << "Display type: " << getType() << endl
        << "Dimension: " << getInches() << endl
        << "Connectivity support: " << endl;
    for (int i = 0; i < numConnectivityModes; ++i) {
        cout << "- " << getModes(i) << endl;
    }
}
