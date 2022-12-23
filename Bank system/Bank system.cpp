#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


class Card
{
public:
	
	Card(int balance,
	string type,
	string number,
	string CVV,
	string date,
	string owner,
	int credit_limit) 
	
	{

		this->balance = balance;
		this->type = type;
		this->number = number;
		this->CVV = CVV;
		this->date = date;
		this->owner = owner;
		this->credit_limit = credit_limit;

	};

	Card() {


	}

	void set_number() {
		cout << "type number" << endl;
		cin >> number;
	}

	string get_number() {
		return number;
	}


	void set_CVV() {
		cout << "type CVV" << endl;
		cin >> CVV;
	}

	string get_CVV() {
		return CVV;
	}


	void set_date() {
		cout << "type date" << endl;
		cin >> date;
	}

	string get_date() {
		return date;
	}



	void set_owner() {
		cout << "type owner" << endl;
		cin >> owner;
	}

	string get_owner() {
		return owner;
	}


	void set_type() {
		cout << "type type" << endl;
		cin >> type;
	}

	string get_type() {
		return type;
	}

	void set_balance() {
		balance = 0;
	}

	int get_balance() {
		return balance;
	}

	void set_limit(int credit_limit) {
		this->credit_limit = credit_limit;
	}

	int get_limit() {
		return credit_limit;
	}

	void Show() {
		cout << endl;

		cout << "type of card : " << type << endl;
		cout << "number  : " << number << endl;
		cout << "balance : " << balance << endl;
		cout << "credit limit : " << credit_limit << endl;
		cout << "CVV : " << CVV << endl;
		cout << "date : " << date << endl;
		cout << "owner : " << owner << endl;

		cout << endl;
	}

	void Save(vector<Card> pocket) {

		ofstream out;

		out.open("bank_system.txt");

		if (out.is_open()) {

			for (size_t i = 0; i < pocket.size(); i++)
			{
				out << pocket[i].balance<<" ";
				out << pocket[i].type << " ";
				out << pocket[i].number << " ";
				out << pocket[i].CVV << " ";
				out << pocket[i].date << " ";
				out << pocket[i].owner << " ";
				out << pocket[i].credit_limit << " ";
			}

		}

		out.close();

	}


	void Read(vector<Card> pocket) {

		ifstream in("bank_system.txt");



		if (in.is_open()) {

			

			while (in >> balance >> type >> number >> CVV >> date >> owner >> credit_limit) {

				pocket.push_back(Card(balance,type,number,CVV,date,owner,credit_limit));

			}

		}

		in.close();

	}


	void credit_spend(){
	
	}

	void debit_spend() {

	}

	void top_up() {
		int top_up;
		int tmp_balance = balance;
		cout << "how much u wanna add?" << endl;
		cin >> top_up;
			
		if (top_up<0)
		{
			cout << "top up can't be bellow than 0";
		}
		else
		{
			tmp_balance += top_up;

			balance = tmp_balance;
		}

	}

	Card create() {

		Card* card = new Card;

		card->set_type();

		if (card->type == "debit") {

			card->set_limit(0);
			
		}
		else if(card->type=="credit")
		{
			card->set_limit(10000);
		}


			card->set_number();
			card->set_CVV();
			card->set_date();
			card->set_owner();
			card->set_balance();

		return *card;
	}

private:

	string type;
	string number;
	string CVV;
	string date;
	string owner;
	int credit_limit;
	int balance;

};







int main()
{
	vector<Card> pocket;

	Card tmp_card;

	
	int choose;
	bool No_exit = true;

	tmp_card.Read(pocket);

tryAgain:

	string tmp_number;

	while (No_exit) {

		cout << "1 add card\n";
		cout << "2 top up card\n";
		cout << "3 show pocket\n";


		cin >> choose;
		switch (choose)
		{
		case 1:
			pocket.push_back(tmp_card.create());
			break;
		case 2:

			cout << "type nomber of card for top up \n";
			cin >> tmp_number;
			for (size_t i = 0; i < pocket.size(); i++)
			{
				if (pocket[i].get_number()==tmp_number)
				{
					pocket[i].top_up();
					goto tryAgain;
				}

			}
			break;
		case 3:
			
			for (size_t i = 0; i < pocket.size(); i++)
			{
				pocket[i].Show();
			}
			break;
		case 4:
			tmp_card.Save(pocket);
			No_exit = false;
			
			break;
		default:
			cout << "error\n";
			goto tryAgain;
			
			break;
		}
	}
	
}

