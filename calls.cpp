#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// list();
// history();
// printwd();
//chdir();

int main(){
	string command;//store command inputs
	string cd = "";//if user type "chdir", cd = "chdir"
	string gofile = "";//store destination file
	
	while(command != "exit"){
		if(command == "list"){
			//list();				
		}
		else if(command == "history"){
			//history();
		}
		else if(command == "printwd"){
			//printwd();
		}		
		else if(cd == "chdir"){
			//chdir();
		}
		else if(){
			//run an external program
		}
		else if(command != "\0"){
			cout << "ERROR\n";
		}	
		
		getline(cin,command);
		cd =command.substr(0,5);
	
		if(command.size() > 6){
			 gofile = command.substr(6, command.length()-5);
		}else{
			gofile = "";
		}

	}
  

	return 0;
}


