#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

void cdBack(string & str){
	int found = str.find_last_of("/\\");
	str = str.substr(0,found);

}
bool gavePath(string str){
	size_t found = str.find_last_of('.');
	found = str.find_last_of('/',found);
	if(found == string::npos )
		return 0;
	return 1;
}
void changeCommand(string str, string dir, string& newCommand){
	dir = dir + "/";
	int found = str.find_last_of(' ');
	 newCommand = str.insert(found+1, dir);
	//return newCommand;
}
void changeGPP(string str, string dir, string org, string& newCommand){
	dir = dir + "/";
	int found = str.find_last_of(' ');
	newCommand = str.insert(found+1,dir);

	found = str.find_first_of(' ');
	//org =  org + "/";
	newCommand = str.insert(found+1,dir);
}
bool isGPP(string cmd){
	size_t found = cmd.find("g++", 0);
	if(found == string::npos)
		return 0;
	return 1;
}
int main(){
	char orgPath[300];
	//string currentDir = "/home/xinliu/project1";
	string currentDir = "";
	string current = "";
	string command;
	string gofile = "";
	string cd = "";
	string str="";
	string cdstr=""; 
	string histories[50];
	//string run = "";
	//char *argv[20];
	int index = 0;
	
	
	for(int i = 0; i < 50; i ++){
		histories[i].clear();
	}
	//for(int i = 0; i < 20; i ++){
	//	argv[i] = NULL;
	//}
	if(getcwd(orgPath,sizeof(orgPath)) != NULL){
		currentDir = orgPath;
		current = "#" + currentDir;
	}else{
		cout << "Error!\n";
		return 1;
	}

while(command != "exit"){
		if(command == "list"){
			str = "ls /"+ currentDir;
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
			if(command[5] != ' '){
				cout << "Error!\n";
			}
			else if(gofile != ".."){						                string temp = currentDir + "/" + gofile;
				int isError = chdir(temp.c_str());
				if(isError == 0){
					currentDir = currentDir + "/" +  gofile;
					if(gofile != ".."){
						current= current + "/" + gofile;
					}
				}else{
				 cout << "Can't chdir to " + gofile <<endl;
					chdir(currentDir.c_str());
				}
							}
			else{
				cdBack(currentDir);
				cdBack(current);	
			}
		}
		//else if(system(command.c_str()) == -1 ){
		//	cout << "Error: exec falied\n";
		//}
		else if(command != "\0"){
			if(gavePath(command) == 0){
			   if(!isGPP(command))
   				changeCommand(command,currentDir,command);
				//cout << currentDir <<endl;
			   else
			    changeGPP(command,currentDir,orgPath,command);
			    //cout << command<<endl;
			 }
			if(system(command.c_str()))
				cout << "ERROR\n";
		}
		
		cout << current << "-->: ";
		getline(cin,command);
		histories[index] = command;
		index++;
		cd =command.substr(0,5);
		//run = command.substr(0,6);
		if(command.size() > 6){
			 gofile = command.substr(6, command.length()-5);
		}else{
			gofile = "";
		}
}
  

	return 0;
}


