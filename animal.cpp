#include <iostream>
#include <fstream>
#include "Time.h"
#include <string>
using namespace std;
const int MAXNUM = 30;
class Animal
{
public:
    // change
    void change_name();
    void change_age();
    void change_health();
    // input basic messages;
    void input_name();
    void input_age();
    void input_health();
    // judge health of animal;
    void judge_health();
    // output
    virtual void output_all();
    string output_name();
    string output_age();
    string output_health();
    long delta_time();

private:
    string name;
    string age;
    string health;
    long eating_time;
};

void Animal::change_age(){
    cout << "Enter the age you need to change: ";
    cin >> age;
}

void Animal::change_health(){
    cout << "Enter the health you need to change: ";
    cin >> health;
}
string Animal::output_name() {
    return name;
}

string Animal::output_age() {
    return age;
}

string Animal::output_health() {
    return health;
}

long Animal::delta_time() {
    long now_time = Time().getTimep();
    long delta_time = now_time - eating_time;
    return delta_time;
}

void Animal::output_all() {
    cout << "\033[31;1mName: \033[0m" << name << endl;
    cout << "Age: " << age << endl;
    cout << "Health: " << health << endl;
}

void Animal::change_name(){
    cout << "Please input new name: ";
    cin >> name;
    cout << "sucessfully input!" << endl;
}


void Animal::judge_health()
{
    long _delta_time = delta_time();
    if (_delta_time >= 28800){
        cout << "\033[33;1mThe animal is hunger, please feed!\033[0m" << endl;
        health = "bad"; // change the health
    }else if(_delta_time <= 14400){
        cout << "\033[33;1mYou don't need to feed.\033[0m" << endl;
    }else{
        cout << "\033[33;1mYou're ready to feed, Please feed as soon as possible.\033[0m" << endl;
    }
}
void Animal::input_name()
{
    cout << "please input name of animal: ";
    cin >> name;
}

void Animal::input_age()
{
    cout << "please input age of animal: ";
    cin >> age;
}

void Animal::input_health()
{
    cout << "Please input health of animal: ";
    cin >> health;
    cout << "If you always feed the animal? You can input y or q to quit." << endl;
    string buttom;
    cin >> buttom;
    if (buttom == "y" || buttom == "Y"){
        cout << "Eating time is: ";
        Time().acquireTime();
        eating_time = Time().getTimep();
    }
    else if(buttom == "q"){
        cout << "Sucessfully input!" << endl;
    }
    else{
        cout << "Please input correct alphabet!" << endl;
    }
    judge_health();
}

class TerrestrialAnimal:public Animal
{
public:
    virtual void output_all();
    void output_breathe();
private:
    const string BREATHE = "lung";
};

void TerrestrialAnimal::output_breathe()
{
    cout << "Terrestrial animal is lung to breathe." << endl;
}

void TerrestrialAnimal::output_all() {
    cout << "\033[30;1m===============================================\033[0m" << endl;
    Animal::output_all();
    output_breathe();
    judge_health();
    cout << "\033[30;1m===============================================\033[0m" << endl;
}

class AquaticAnimal:public Animal
{
public:
    virtual void output_all();
    void output_breathe();
private:
    const string BREATHE = "lung";
};

void AquaticAnimal::output_breathe()
{
    cout << "Aquatic animal is cheek to breathe." << endl;
}

void AquaticAnimal::output_all() {
    cout << "\033[30;1m===============================================\033[0m" << endl;
    Animal::output_all();
    output_breathe();
    judge_health();
    cout << "\033[30;1m===============================================\033[0m" << endl;
}

class Amphibians:public Animal
{
public:
    virtual void output_all();
    void output_breathe();
private:
    const string BREATHE = "lung";
};

void Amphibians::output_breathe()
{
    cout << "Amphibians is lung to breathe." << endl;
}

void Amphibians::output_all() {
    cout << "\033[30;1m===============================================\033[0m" << endl;
    Animal::output_all();
    output_breathe();
    judge_health();
    cout << "\033[30;1m===============================================\033[0m" << endl;
}

TerrestrialAnimal * terr_arr[MAXNUM];
int terr_idx = 0;
AquaticAnimal * aqu_arr[MAXNUM];
int aqu_idx = 0;
Amphibians * amp_arr[MAXNUM];
int amp_idx = 0;

int main()
{
    bool flag = true;
    while (flag){
        string menu();
        string button = menu();
        if (button == "9"){
            flag = false;
            cout << "Sucessfully quit!" << endl;
            break;
        } else if(button == "1"){
            void add_menu();
            add_menu();
        }else if(button == "2"){
            void show_animal();
            show_animal();
        }else if(button == "3"){
            void change_animal();
            change_animal();
        }else if(button == "4"){
            void search_animal();
            search_animal();
        }else if(button == "5"){
            void delete_animal();
            delete_animal();
        }else if(button == "6"){
            void feed_animal();
            feed_animal();
        }else if(button == "7"){
            void read_file();
            read_file();
        }else if(button == "8"){
            void get_file();
            get_file();
        }else{
            cout << "\033[31;1mPlease input correct number!\033[0m" << endl;
        }
        cout << "\033[34;1mcontinue...Enter any number to return: \033[0m";
        cin >> button;
    }
}

string menu(){
    string button;
    system("cls");
    cout << "\t\t\033[31;1mZoo Management System\033[0m" << endl;
    cout << "\033[30;1m===============================================\033[0m" << endl;
    cout << "#\t\033[30;1m[1] Add animals\033[0m" << endl;
    cout << "#\t\033[30;1m[2] Show all animals\033[0m" << endl;
    cout << "#\t\033[30;1m[3] Changing the animal's information\033[0m" << endl;
    cout << "#\t\033[30;1m[4] search the animal's information\033[0m" << endl;
    cout << "#\t\033[30;1m[5] Delete the animal's information\033[0m" << endl;
    cout << "#\t\033[30;1m[6] Inquire about animals to be fed\033[0m" << endl;
    cout << "#\t\033[30;1m[7] read a file\033[0m" << endl;
    cout << "#\t\033[30;1m[8] Save a new file\033[0m" << endl;
    cout << "#\t\033[30;1m[9] Log out of the system\033[0m" << endl;
    cout << "\033[30;1m===============================================\033[0m" << endl;
    cout << "\033[34;1mPlease select a function: \033[0m";
    cin >> button;
    return button;
}

void add_menu(){
    string button;
    cout << endl;
    system("cls");
    cout << "\t\t\033[31;1mAdd animals\033[0m" << endl;
    cout << "\t\033[32;1mSelect the species of animal\033[0m" << endl;
    cout << "\033[30;1m===============================================\033[0m" << endl;
    cout << "#\t\033[30;1m[1] Terrestrial Animal\033[0m" << endl;
    cout << "#\t\033[30;1m[2] Aquatic Animal\033[0m" << endl;
    cout << "#\t\033[30;1m[3] Amphibians\033[0m" << endl;
    cout << "#\t\033[30;1m[4] Log out of the system\033[0m" << endl;
    cout << "\033[30;1m===============================================\033[0m" << endl;
    cout << "\033[34;1mPlease select a function: \033[0m";
    cin >> button;
    if (button == "1"){
        TerrestrialAnimal *p = new TerrestrialAnimal();
        p->input_name();
        p->input_age();
        p->input_health();
        terr_arr[terr_idx] = p;
        terr_idx ++;
    }else if (button == "2"){
        AquaticAnimal *p = new AquaticAnimal();
        p->input_name();
        p->input_age();
        p->input_health();
        aqu_arr[aqu_idx] = p;
        aqu_idx ++;
    }else if (button == "3"){
        Amphibians *p = new Amphibians();
        p->input_name();
        p->input_age();
        p->input_health();
        amp_arr[amp_idx] = p;
        amp_idx ++;
    }
}

void show_animal(){
    system("cls");
    for (int i = 0; i < terr_idx; i ++){
        terr_arr[i]->output_all();
    }
    for (int i = 0; i < aqu_idx; i ++){
        aqu_arr[i]->output_all();
    }
    for (int i = 0; i < amp_idx; i ++){
        amp_arr[i]->output_all();
    }
}

void delete_animal(){
    system("cls");
    string _name;
    cout << endl;
    cout << "\033[33;1mNote:At least one of each type of animal is retained!\033[0m" << endl;
    cout << "\033[32;1mPlease enter the name of the animal you need: \033[0m";
    cin >> _name;
    Animal *p = 0x0;
    int idx = 0;
    int flag = 0;
    for (int i = 0; i < terr_idx; i ++){
        if (terr_arr[i]->output_name() == _name){
            p = terr_arr[i];
            idx = i;
            flag = 1;
        }
    }
    for (int i = 0; i < aqu_idx; i ++){
        if (aqu_arr[i]->output_name() == _name){
            p = aqu_arr[i];
            idx = i;
            flag = 2;
        }
    }
    for (int i = 0; i < amp_idx; i ++){
        if (amp_arr[i]->output_name() == _name){
            p = amp_arr[i];
            idx = i;
            flag = 2;
        }
    }
    if (flag == 1){
        for (int i = idx; i < terr_idx - 1; i ++){
            terr_arr[i] = terr_arr[i + 1];
        }
        terr_idx --;
    }else if (flag == 2){
        for (int i = idx; i < terr_idx - 1; i ++){
            aqu_arr[i] = aqu_arr[i + 1];
        }
        aqu_idx --;
    }else if (flag == 3){
        for (int i = idx; i < terr_idx - 1; i ++){
            amp_arr[i] = amp_arr[i + 1];
        }
        amp_idx --;
    }
    if (p == 0x0){
        cout << "\033[31;1mThe animal is not added!\033[0m" << endl;
    }else{
        cout << flag;
        p->output_all();
    }
}

void search_animal(){
    system("cls");
    string _name;
    cout << "\033[32;1mPlease enter the name of the animal you need: \033[0m";
    cin >> _name;
    Animal *p = 0x0;
    for (int i = 0; i < terr_idx; i ++){
        if (terr_arr[i]->output_name() == _name){
            p = terr_arr[i];
        }
    }
    for (int i = 0; i < aqu_idx; i ++){
        if (aqu_arr[i]->output_name() == _name){
            p = aqu_arr[i];
        }
    }
    for (int i = 0; i < amp_idx; i ++){
        if (amp_arr[i]->output_name() == _name){
            p = amp_arr[i];
        }
    }
    if (p == 0x0){
        cout << "\033[31;1mThe animal is not added!\033[0m" << endl;
    }else{
        p->output_all();
    }
}

void feed_animal(){
    system("cls");
    string name_arr[MAXNUM * 3];
    int name_idx = 0;
    for (int i = 0; i < terr_idx; i ++){
        // if > 8h => remind feed
        if (terr_arr[i]->delta_time() >= 28800){
            name_arr[name_idx] = terr_arr[i]->output_name();
            name_idx ++;
        }
    }
    for (int i = 0; i < aqu_idx; i ++){
        if (aqu_arr[i]->delta_time() >= 28800){
            name_arr[name_idx] = aqu_arr[i]->output_name();
            name_idx ++;
        }
    }
    for (int i = 0; i < amp_idx; i ++){
        if (amp_arr[i]->delta_time() >= 28800){
            name_arr[name_idx] = amp_arr[i]->output_name();
            name_idx ++;
        }
    }
    cout << "\t\t\033[31;1mHungry animals have:\033[0m" << endl;
    for (int i = 0; i < name_idx; i ++){
        cout << name_arr[i] << " ";
    }
    cout << endl;
}

void get_file(){
    // open file
    std::ofstream outFile;
    outFile.open("animal.txt");
    outFile << "name:\t" << "age:\t" << "health:\t" << "\n";
    // writer
    for (int i = 0; i < terr_idx; i ++){
        outFile << terr_arr[i]->output_name() <<  "\t" << terr_arr[i]->output_age() << "\t" <<terr_arr[i]->output_health() << "\n";
        
    }
    for (int i = 0; i < aqu_idx; i ++){
        outFile << aqu_arr[i]->output_name() <<  "\t" <<aqu_arr[i]->output_age() << "\t" <<aqu_arr[i]->output_health() << "\n";
    }
    for (int i = 0; i < amp_idx; i ++){
        outFile << amp_arr[i]->output_name() <<  "\t" <<amp_arr[i]->output_age() << "\t" <<amp_arr[i]->output_health() << "\n";
    }
    outFile.close();
    cout << "The file was successfully written!" << endl;
}

void read_file(){
	ifstream infile;
	infile.open("animal.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	//第二种读取方法
	char buf[1024];
	while (infile.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
}

void change_animal(){
    system("cls");
    string _name;
    cout << "\033[32;1mPlease enter the name of the animal you need: \033[0m";
    cin >> _name;
    Animal *p = 0x0;
    for (int i = 0; i < terr_idx; i ++){
        if (terr_arr[i]->output_name() == _name){
            p = terr_arr[i];
        }
    }
    for (int i = 0; i < aqu_idx; i ++){
        if (aqu_arr[i]->output_name() == _name){
            p = aqu_arr[i];
        }
    }
    for (int i = 0; i < amp_idx; i ++){
        if (amp_arr[i]->output_name() == _name){
            p = amp_arr[i];
        }
    }
    if (p == 0x0){
        cout << "\033[31;1mThe animal is not added!\033[0m" << endl;
    }else{
        p->output_all();
        cout << "\033[31;1mPlease select the information you want to change\033[0m" << endl;
        cout << "\033[30;1m===============================================\033[0m" << endl;
        p->change_age();
        p->change_health();
    }
}