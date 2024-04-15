#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>
#include <sstream>
#include <fstream>
using namespace std;
struct accounts_data {

	string name, nationality, Date_of_birth, gender;
	int NIC, account_no;
	unsigned long int deposit;


};

int money_fun(int size, accounts_data search[]);

int withDraw1(int proM1, accounts_data search[]);


void Create_account(accounts_data arrray[], int i, int size)
{
	//accounts_data arrray[size];
	string read;

	for (int j = i - 1; j < size; j++)
	{
		cout << " Enter name" << endl;
		//krta ja ja
		cin.ignore();

		getline(cin, read);
		arrray[j].name = read;

		cout << " Enter nationality" << endl;

		getline(cin, read);
		
		arrray[j].nationality = read;


		cout << " Date_of_birth" << endl;
		
		getline(cin, read);
		
		arrray[j].Date_of_birth = read;

		cout << " Enter Gender" << endl;
		
		getline(cin, read);
		
		arrray[j].gender = read;
		

		cout << " Enter NIC number" << endl;
		
		cin >> arrray[j].NIC;

		cout << " Generate account Number" << endl;

		cin >> arrray[j].account_no;
		break;
	}

}




void customer_list(accounts_data arrray[], int size) {
	cout << endl<<"\033[33m" << "Loading " << "\033[0m";
	for (int i = 0; i < 10; i++) {
		cout << ".";
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(150));
	}
	cout << endl<<endl;
	cout << setw(18) <<  "\033[33m" <<"Name" << setw(22) << "Nationality" << setw(24) << "Date Of Birth" << setw(17) << "Gender" << setw(27) << "NIC Number" << setw(24) << "Account Number" << "\033[0m" << endl;

	for (int j = 0; j < size; j++) {

		cout << setw(18) << arrray[j].name << setw(22) << arrray[j].nationality << setw(24) << arrray[j].Date_of_birth << setw(17) << arrray[j].gender;

		cout << setw(27) << arrray[j].NIC;
		cout << setw(24) << arrray[j].account_no;
			cout << endl;

	}


}



int nic_search(int size, accounts_data search[]);

void search_account(int size, accounts_data search[]) {
	cout << setw(2) << " press 1 for Search by name" << endl << "or 2 for search by NIC number" << endl;
	int prompt, nic, c = 0;
	string Name;
	cin >> prompt;
	switch (prompt) {

	case 1:
		cout << "enter name" << endl;
		cin >> Name;
		for (int j = 0; j < size; j++) {

			if (Name == search[j].name) {


				cout << ".)found, with " << Name << endl;
				cout << setw(18) <<  "\033[33m" <<"Name" << setw(22) << "Nationality" << setw(24) << "Date Of Birth" << setw(17) << "Gender" << setw(27) << "NIC Number" << setw(24) << "Account Number" << "\033[0m" << endl;

cout << setw(18) << search[j].name << setw(22) << search[j].nationality << setw(24) << search[j].Date_of_birth << setw(17) << search[j].gender;

		cout << setw(27) << search[j].NIC;
		cout << setw(24) << search[j].account_no;
			cout << endl;
			}
		}
		//think for options for user

		break;

	case 2:
		//nested function
		int c;
		c = nic_search(size, search);
		break;

	default:
		break;
	}
	return;

}



void Update_account(int size, accounts_data search[]) {
	//calling nested function
	 int ans;
	int c = nic_search(size, search);  //receieve index where  data of intrest was placed
	if (c != -1) {
		cout << endl << " Just enter 1 if u not want to change something  " << endl << " Enter name" << endl;

		cin.ignore();
		string rea;
		getline(cin, rea);
		cout << rea << endl;
		if (rea != "1") {
			search[c].name = rea;
		}

		cout << "Enter nationality" << endl;

		getline(cin, rea);
		if (rea != "1") {
			search[c].nationality = rea;
		}

		cout << "Date_of_birth" << endl;
		getline(cin, rea);
		if (rea != "1") {
			search[c].Date_of_birth = rea;
		}
		ans = search[c].NIC;
		cout << "Enter NIC number" << endl;
		cin >> search[c].NIC;
		if (search[c].NIC == 1) {
			search[c].NIC = ans;
		}
		ans = search[c].account_no;
		cout << "Generate account Number" << endl;
		cin >> search[c].account_no;
		if (search[c].account_no == 1) {
			search[c].account_no = ans;
		}

	}
	else {
		cout << "Account not found " << endl;
	}

}




void Account_Details(int size, accounts_data search[]) {
	//calling nested function

	int c = nic_search(size, search);

}
void dePosit(accounts_data search[], int i) {
	int ANS = 0;
	cout << "For amount to Deposit ";
	ANS = nic_search(i, search);
	if (ANS == -1) {
		cout << " account NOT found!" << endl;
	}
	else {
		cout << endl << "enter amount to Deposit" << endl;
		cin >> search[ANS].deposit;

	}
}
void withDraw(accounts_data search[], int i) {
	int prom1;
	cout << " Before withdraw  " << endl;
	prom1 = money_fun(i, search);
	if (prom1 != -1) {

		withDraw1(prom1, search);

	}
}

int withDraw1(int proM1, accounts_data search[]) {     //used by transFer & withDraw functions
	double prom2, l;
	cout << "enter amount " << endl;
	cin >> prom2;
	l = prom2;
	prom2 = search[proM1].deposit - prom2;
	if (prom2 > 0) {
		//cout << "comes";
		search[proM1].deposit = prom2;
		cout << " Amount withdrawn successfully" << endl << "  remaning amount in " << search[proM1].name << " is $ " << search[proM1].deposit<<endl;
		return l;
	}
	else {
		cout << " Not enough balance";
		return -1;
	}

}

void transFer(accounts_data search[], int i) {
	int prom1, prom2;
	cout << " enter NIC of member, from where amount to be transered" << endl;

	prom1 = money_fun(i, search);
	if (prom1 != -1) {
		cout << "enter NIC Where amount to be transfer" << endl;
		prom2 = money_fun(i, search);
		if (prom2 != -1) {

			prom1 = withDraw1(prom1, search);
			if (prom1 != -1) {

				search[prom2].deposit = prom1;

				cout << "\033[33m" << "Transfering amount" << "\033[0m";

				for (int i = 0; i < 10; i++) {
					cout << ".";
					cout.flush();
					this_thread::sleep_for(chrono::milliseconds(150));
				}

				cout << endl << " Amount transfered" << endl;
			}
		}
		else {
			cout << " account not found " << endl;
		}
	}
	else {
		cout << " account not found " << endl;
	}

}

void de_lete(accounts_data ARR[], int& k) {
	cout << " For Delete" << endl;
	int l;
	l = nic_search(k, ARR);

	if (l != -1) {
		for (int j = l; j < k - 1; j++) {
			ARR[j].name = ARR[j + 1].name;
			ARR[j].nationality = ARR[j + 1].nationality;
			ARR[j].Date_of_birth = ARR[j + 1].Date_of_birth;
			ARR[j].gender = ARR[j + 1].gender;
			ARR[j].NIC = ARR[j + 1].NIC;
			ARR[j].account_no = ARR[j + 1].account_no;

			cout << " Account Deleted successfuly" << endl;

		}
		k--;

	}

	else {
		cout << " Account not found" << endl;
	}

}
void save_data(accounts_data arrray[], int len) {
	ofstream WRITE;
	WRITE.open("save.txt", ios::out);
	for (int j = 0; j < len; j++) {
		WRITE << arrray[j].name << endl << arrray[j].nationality << endl << arrray[j].Date_of_birth << endl << arrray[j].gender << endl << arrray[j].NIC << endl << arrray[j].account_no << endl << arrray[j].deposit << endl << "." << endl;
		cout << endl;

	}
	cout<<endl<<"Data saved to save.txt"<<endl;
	WRITE.close();

}


void load_data(accounts_data arrray[],int &size) {
    int anS;
    unsigned long int ans2;
	ifstream reAd,READ;
	int j = 0, n, count = 0;
	reAd.open("save.txt", ios::in);

	if (reAd.is_open()) {
		string lin;
		// cout << "s";
		while (getline(reAd, lin)) {
			for (char c : lin) {
				if (c == '.') {
					count++;
				}
			}
		}
		cout<< "\033[33m"<< "Data Loaded successfuly"<< "\033[0m"<<endl;
	}
	
	else {
		cout << "Unable to open file for reading." << endl;
	}
	size=count;
	reAd.close();
	READ.open("save.txt",ios::in);
		string line;
		do{
		    READ>>line;
		    
		    arrray[j].name = line;
		   
		     READ>>line;
		     
		     arrray[j].nationality = line;
		   
		    READ>>line; 
		    
		    arrray[j].Date_of_birth = line;
		    
		    READ>>line;
		    
		    arrray[j].gender = line;
		  
		    READ>>line;  //5
		    
		    anS=stoi(line);
		    
		    arrray[j].NIC =anS; 
		    
		   
		    
		    READ>>line;
		    
		    anS=stoi(line);
		    
		    arrray[j].account_no = anS;
		    
		   
		    READ>>line;  
		    
		    ans2=stol(line);
		    
		    arrray[j].deposit =ans2;
		   
		    READ>>line;     
		  //  cout<<line;
		    j++;
		    
		}while(j<count);
	
}











int main(){
	cout << " Cout Enter Password to Login" << endl;

	string pass = "eme_bank", enter;
	cin >> enter;
	if (pass == enter) {
	     cout << "\033[7m" <<"          Welcome to         " <<"\033[0m" <<endl<<endl;
    cout <<           "\033[31m" << "*****    *****   *     *  *   * "<<endl;
    cout <<                         "*    *   *    *  **    *  *  * "<<endl;
    cout <<                         "*****    ******  * *   *  * *"<<endl;
    cout <<                         "*    *   *    *  *  *  *  *  *"<<endl;
    cout <<  "\033[4m"<<            "*****    *    *  *   * *  *   *"<< "\033[0m" <<endl<<endl;

     
		int p, i = 0;
		const unsigned long int size = 7000;
		string	te=   "1. Create account\n2.Update account\n3.Deposit Ammount\n4.Transfer Ammount\n5.Withdraw Ammount\n6.Customers list\n7.Check Balance\n8.Search Account\n9.Delete Account\n10. Save data\n 11. Load data\n";
	    for(char c:te){
		cout<<c<<flush;
		this_thread::sleep_for(chrono::milliseconds(8));
	    }
	    cin >> p;
		accounts_data Array[size];
		while (p != -1) {
			switch (p)
			{
			case 1:
				i++;

				Create_account(Array, i, size);

				cout << "Account created successfuly!" << endl;

				break;

			case 2:

				Update_account(size, Array);
				cout << endl;
				cout << "Account Updated successfuly!" << endl;
				break;

			case 3:
				dePosit(Array, i);
				cout << "Ammount Deposited successfuly!" << endl;
				break;

			case 4:
				transFer(Array, i);

				break;
			case 5:
				withDraw(Array, i);

				break;

			case 6:

				cout << "Showing customers lists  " << endl;

				customer_list(Array, i);

				break;

			case 7:
				int found;
				cout << "Checking  Balance  " << endl;
				found = money_fun(i, Array);
				if (found != -1) {
					cout << "$" << Array[found].deposit;
				}
				else {
					cout << " A not found" << endl;
				}


				break;

			case 8:
				search_account(size, Array);
				//option for user if interested in multiple opeartions
				break;

			
			case 9:
				de_lete(Array, i);

				break;
			case 10:
				save_data(Array, i);
				
				break;
				
			case 11:
				load_data(Array,i);
				break;

			default:
				cout << "Error";
				
				break;
			}
			cout << endl << endl;
			
			string	te=   "1. Create account\n2.Update account\n3.Deposit Ammount\n4.Transfer Ammount\n5.Withdraw Ammount\n6.Customers list\n7.Check Balance\n8.Search Account\n9.Delete Account\n10. Save data\n 11. Load data\n";
	    for(char c:te){
		cout<<c<<flush;
		this_thread::sleep_for(chrono::milliseconds(10));
	    }
			cin >> p;
		}
	}
	else {
		cout << " Wrong password" << endl;
	}

	return 0;
}
//nested functions are blow the main for ease to read

int money_fun(int size, accounts_data search[]) {
    
	cout << " Enter NIC to search account" << endl;
	
	 int nic;
	 
	cin >> nic;
	
	int l = -1;
	
	
	for (int j = 0; j < size; j++) {
	    
		if (nic == search[j].NIC) {
		    
			return j;
		}
	}
	return l;
}
int nic_search(int size, accounts_data search[]) {

	cout << " Enter NIC to search account" << endl;
	
	 int nic;
	cin >> nic;
	int l = -1;
	
	cout << "\033[33m" << "Searching " << "\033[0m";
	
	for (int i = 0; i < 10; i++) {
		cout << ".";
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(150));
	}
	
	
	cout << endl;
	for (int j = 0; j < size; j++) {
	    
		if (nic == search[j].NIC) {
		    
			cout << " .)found, with " << nic << endl;
			
			cout << setw(18) << "Name" << setw(22) << "Nationality" << setw(24) << "Date Of Birth" << setw(17) << "Gender" << setw(27) << "NIC Number" << setw(24) << "Account Number" << endl;
			
			cout << setw(18) << search[j].name << setw(22) << search[j].nationality << setw(24) << search[j].Date_of_birth << setw(17) << search[j].gender;
			
			cout << setw(27) << search[j].NIC << setw(24) << search[j].account_no;
			
			return j;
		}
	}

	return l;
}









