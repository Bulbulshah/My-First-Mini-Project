#include<iostream>
#include<vector>
using namespace std;

class BankAccount{ 
  private:
  	  string name;
  	  int accountnum;
  	  double balance; 
  public:
  		 // Constructor to initialize name, account number, and balance
  		BankAccount(string n, int acc, double bal){
  			name = n;
  			accountnum	= acc;
  			balance = bal;
		  }
  		 
  		 string getname(){
  		 	return name;
		   }
		   int getaccountnum(){
		   	return accountnum;
		   }
		   double getbalance(){
		   	return balance;
		   	
		   }
		   void deposit(double amount)
		{
			balance= balance+ amount;
		}
		void Withdraw(double amount)
		{
			if(balance>=amount)
			{
				balance= balance-amount;
				cout<<"\t\tWithdraw successfully...."<<endl;
			}
			else{
		       cout<<"\t\tinsufficent balance..."<<endl;
			}
		}
};
class BankManagement{
	private:
		vector<BankAccount> accounts;
	public:
		void addaccount(string name, int accountnum, double balance ){
			accounts.push_back(BankAccount(name,accountnum,balance));
		}
		void showallaccounts(){
			cout<<"\n\nAll Account Holders"<<endl;
			for(int i= 0; i<accounts.size();i++)
			cout<<"name "<<accounts[i].getname()<<"Account Number "<<accounts[i].getaccountnum()<<"Balance: "<<accounts[i].getbalance()<<endl;
		}
		void searchAccount(int account){
			cout<<"\t\t Account Holders"<<endl;
			for(int i=0; i<accounts.size(); i++){
				if(accounts[i].getaccountnum()==account){

				cout<<"name "<<accounts[i].getname()<<"Account Number "<<accounts[i].getaccountnum()<<"Balance: "<<accounts[i].getbalance()<<endl;
				
				}
			}
			
		}
		
		BankAccount* findaccount(int accountnum){
			for(int i=0; i<accounts.size();i++){
				if(accounts[i].getaccountnum()==accountnum)
				return &accounts[i];
				
			}
		}
		
		
		
		
};
int main(){
	BankManagement bank;
	int choice;
	char op;
	do{
		system("cls");
		cout<<"\t\t::Bank Management System "<<endl;
		cout<<"\t\t\tMain Menu"<<endl;
		cout<<"\t\t1. Create New Account "<<endl;
		cout<<"\t\t2. Show All Accounts "<<endl;
		cout<<"\t\t3. Search Account "<<endl;
		cout<<"\t\t4. Deposit Money "<<endl;
		cout<<"\t\t5. Withdraw Money "<<endl;
		cout<<"\t\t6. Exit \n"<<endl;
		cout<<"\t\t Enter Your Choice : ";
		cin>>choice;
	switch(choice){
	    	case 1:{
		
				string name;
				int accountnum;
				double balance;
				
				cout<<"\t\tEnter name ";
				cin>>name;
				
				cout<<"\t\tEnter accountnum ";
				cin>>accountnum;
				
				cout<<"\t\tEnter Initial balance ";
				cin>>balance;
				bank.addaccount(name,accountnum,balance);
				cout<<"\t\tAccount created Successfully"<<endl;
				
	     	break;
	 }
	 case 2:{
	 	bank.showallaccounts();
		break;
	 }
	 case 3:{
	 	int accountnum;
	 	cout<<"\t\tEnter Account number: ";
	 	cin>>accountnum;
	 	bank.searchAccount(accountnum);
		break;
	 }
	 case 4:{
	 	int accountnum;
	 	double amount;
	 	cout<<"\t\tEnter account number to deposit money: ";
	 	cin>>accountnum;
	 	BankAccount*account = bank.findaccount(accountnum);
	 	if(account != NULL)
	 	{
	 		cout<<" Enter amount to deposit: ";
	 		cin>>amount;
	 			account->deposit(amount);
	 			cout<<"\t\t"<<amount<<"deposit sucessfully...."<<endl;
	 		}
	 		else
	 			{
	 				cout<<"\t\tAccount Not Found";
				 }
		break;
	 }
	 case 5:{
	 		int accountnum;
	 	double amount;
	 	cout<<"\t\tEnter account number to withdraw money: ";
	 	cin>>accountnum;
	 	BankAccount*account = bank.findaccount(accountnum);
	 	if(account != NULL)
	 	{
	 		cout<<"\t\t Enter amount to withdraw: ";
	 		cin>>amount;
	 			account->Withdraw(amount);
	 		
	 		}
	 		else
	 			{
	 				cout<<"\t\tAccount Not Found";
				 }
	 	
		break;
	 }
	    case 6:{
	    	exit(1);
			break;
		}
	}	
	
			cout<<"\t\tDo you want to Countinue [yes/no] ?? ";
		cin>>op;
		
	} while(op=='y' || op=='Y');
	
	
	
	
	return 0;
}
