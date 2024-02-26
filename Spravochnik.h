#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
class Spravochnik {
private:
    vector<string> firm;
    vector<string> name;
    vector<int> number;
    vector<string> adress;
    vector<string> rodd;
public:
    Spravochnik() {
        readFromDisk();
    }
    Spravochnik(vector<string> firm, vector<string> name, vector<int> number, vector<string> adress, vector<string> rodd) {
        Spravochnik::firm = firm;
        Spravochnik::name = name;
        Spravochnik::number = number;
        Spravochnik::adress = adress;
        Spravochnik::rodd = rodd;
        this->readFromDisk();
    }
    void print(vector<int> in) {
        for (auto& i : in) {
            cout << "Firm: " << this->firm[i] << endl;
            cout << "Name: " << this->name[i] << endl;
            cout << "Phone number: " << this->number[i] << endl;
            cout << "Adress: " << this->adress[i] << endl;
            cout << "Occupation: " << this->rodd[i] << endl;
            cout << "-------------------------------" << endl;
        }
    }
    void searchbyfirm(string s) {
        vector<int> ind;
        for (int i = 0; i < this->firm.size(); ++i) {
            if (this->firm[i] == s) {
                ind.push_back(i);
            }
        }
        if (ind.empty()) {
            cout << "User is not found" << endl;
            return;
        }
        else {
            std::cout << "User(s) was found: " << endl;
            this->print(ind);
        }
    }
    void searchbyname(string s) {
        vector<int> ind;
        for (int i = 0; i < this->name.size(); ++i) {
            if (this->name[i] == s) {
                ind.push_back(i);
            }
        }
        if (ind.empty()) {
            cout << "User is not found" << endl;
            return;
        }
        else {
            std::cout << "User(s) was found: " << endl;
            this->print(ind);
        }
    }
    void searchbynumber(int n) {
        vector<int> ind;
        for (int i = 0; i < this->number.size(); ++i) {
            if (this->number[i] == n) {
                ind.push_back(i);
            }
        }
        if (ind.empty()) {
            cout << "User is not found" << endl;
            return;
        }
        else {
            std::cout << "User(s) was found: " << endl;
            this->print(ind);
        }
    }
    void searchbyrod(string s) {
        vector<int> ind;
        for (int i = 0; i < this->rodd.size(); ++i) {
            if (this->rodd[i] == s) {
                ind.push_back(i);
            }
        }
        if (ind.empty()) {
            cout << "User is not found " << endl;
            return;
        }
        else {
            std::cout << "User(s) was found: " << endl;
            this->print(ind);
        }
    }
    void adduser(int kolvo) {
        for (int i = 1; i <= kolvo; ++i) {
            string vrem;
            int n;
            cout << "Enter firm: ";
            cin >> vrem;
            this->firm.push_back(vrem);

            cout << "Enter name: ";
            cin >> vrem;
            this->name.push_back(vrem);


            cout << "Enter phone number: ";
            cin >> n;
            this->number.push_back(n);

            cout << "Enter adress: ";
            cin >> vrem;
            this->adress.push_back(vrem);

            cout << "Enter occupation: ";
            cin >> vrem;
            this->rodd.push_back(vrem);

            cout << "User was added successfully." << endl;
            this->writeToDisk();
        }
    }
    void printall() {
        vector<int> index;
        for (int i = 0; i < this->name.size(); ++i) {
            index.push_back(i);
        }
        print(index);
    }
    void readFromDisk() {
        ifstream file("contacts.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                string token;
                vector<string> tokens;
                istringstream tokenStream(line);
                while (getline(tokenStream, token, ',')) {
                    tokens.push_back(token);
                }
                if (tokens.size() == 5) {
                    firm.push_back(tokens[0]);
                    name.push_back(tokens[1]);
                    number.push_back(stoi(tokens[2]));
                    adress.push_back(tokens[3]);
                    rodd.push_back(tokens[4]);
                }
            }
            file.close();
        }
    }
    void writeToDisk() {
        ofstream file("contacts.txt");
        if (file.is_open()) {
            for (size_t i = 0; i < name.size(); ++i) {
                file << firm[i] << "," << name[i] << "," << number[i] << "," << adress[i] << "," << rodd[i] << endl;
            }
            file.close();
        }
    }
    ~Spravochnik() {
        cout << "Destructor. Ending the work..." << endl;
    }
};