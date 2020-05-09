#pragma once
#include <string>
using namespace std;

class Donnees {
private:
	string id = "";
	string desc_textuelle = "";
	double prix = 0;
public:
	Donnees() {};

	string getId() const { return this->id; };
	string getDesc() const { return this->desc_textuelle; };
	double getPrix() const { return this->prix; };

	void setId(string _id) { this->id = _id; };
	void setDesc(string _desc_textuelle) { this->desc_textuelle = _desc_textuelle; };
	void setPrix(double _prix) { this->prix = _prix; };
};
