#include<iostream>
#include<string>
using namespace std;
typedef string* strPtr;

class Subscriber {
public:
	Subscriber() :name(""), numChannels(0), channelList(nullptr) {  }//default structor
	void setDate();
	void output();//output data
	string getUser()const;//get user name
	int getNum()const;//get channel number
	string getList(int index)const;//get channel list
	void resetChannel();//reset channel number and list
	Subscriber& operator =(const Subscriber& rightSide);//overloaded assignment operator
	~Subscriber();//desturctor
private:
	string name;
	int numChannels;
	strPtr channelList;
};

int main(void) {
	Subscriber sub, subcpy;
	sub.setDate();
	sub.output();

	cout << "Copy and reset" << endl;
	subcpy = sub;
	sub.resetChannel();
	sub.output();
	subcpy.output();

	return 0;
}

void Subscriber::setDate() {
	cout << "Enter user name: ";
	cin >> name;
	cout << "Enter the number of subscribed channels: ";
	cin >> numChannels;
	if (getNum() == 0) {
		channelList = nullptr;
	}
	else {
		cout << "Enter the list of channel names" << endl;
		channelList = new string[numChannels];
		for (int i = 0; i < numChannels; i++) {
			cout << i + 1 << ": ";
			cin >> channelList[i];
		}
	}
}
void Subscriber::output() {
	cout << "User name: " << getUser() << endl;
	cout << "Number of subscribed channels: " << getNum() << endl;
	if (getNum() != 0) {
		cout << "List:" << endl;
		for (int i = 0; i < getNum(); i++) {
			cout << getList(i) << endl;
		}
	}
}
string Subscriber::getUser()const { return name; }
int Subscriber::getNum()const { return numChannels; }
string Subscriber::getList(int index)const { return channelList[index]; }
void Subscriber::resetChannel() {
	numChannels = 0;
	if (channelList != nullptr) {
		delete [] channelList;
		channelList = nullptr;
	}
}
Subscriber& Subscriber::operator =(const Subscriber& rightSide) {
	if (numChannels != rightSide.numChannels) {
		delete [] channelList;
		channelList = new string[rightSide.numChannels];
	}
	numChannels = rightSide.numChannels;
	for (int i = 0; i < getNum(); i++) {
		channelList[i] = rightSide.channelList[i];
	}
	return *this;
}
Subscriber::~Subscriber() {
	delete[] channelList;
}