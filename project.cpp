#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void cdBack(string & str){
	int found = str.find_last_of("/\\");
	str = str.substr(0,found);

}
int main(){
	string currentDir = "/home/xinliu/project1";
	string current = "#shell";
	string command;
	string gofile = "";
	string cd = "";
	string str="";
	string cdstr=""; 
	string histories[10];
	int index = 0;
	for(int i = 0; i < 10; i ++){
		histories[i].clear();
	}
while(command != "exit"){
		if(command == "list"){
			str = "ls "+ currentDir;
		       const char *list = str.c_str();	
			system(list);
				
		}
		else if(command == "history"){
			for(int i = 0; i <= index; i++){
				if(!histories[i].empty())
				cout << "History command" << i << ": " << histories[i] << endl; 
			}

		}
		else if(command == "printwd"){
			cout << currentDir << endl;
		}
		else if(cd == "chdir"){
			if(gofile != ".."){
				currentDir = currentDir + "/" +  gofile;
				current = current + "/"+gofile;
			}
			else{
				cdBack(currentDir);
				cdBack(current);

