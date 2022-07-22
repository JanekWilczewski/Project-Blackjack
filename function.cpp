#include <windows.h>
#include "blackjack.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


Player::Player(string n, int s_cards, int m, int b, int b_b, int b_c)
{
    name = n; sum_of_cards = s_cards; money = m; balance_b = b; bid_b = b_b; bid_b_c = b_c;
}

Player::~Player()
{

}

void Player::load_money(int a)
{
    this -> money = a;
}

int Player::how_many_wins()
{
    return this -> counter_winnings;
}

void Player::count_winnings(int a)
{
    this -> counter_winnings = a;
}

void Player::count_win_sum()
{
    this -> counter_winnings = this -> counter_winnings + 1;
}


void Player::money_on_start()
{
    this -> money = 150;
}

int Player::how_much_money()
{
    return this -> money;
}

void Player::implicitly()
{
     this -> money = 150;
     this -> counter_winnings = 0;
     this -> balance_b = 0;
     this -> bid_b = 0;
     this -> bid_b_c = 0;
}

 void Player::win(int a)
 {
    this -> money = money + a*2;
 }

void Player::lose(int a)
 {
    this -> money = money - a;
 }

void Player::draw(int a)
 {
    this -> money = money + a;
 }

void Player::display_name()
 {
     cout << this -> name;
 }

void Player::display_money()
 {
     cout << this -> money;
 }

void Player::add_card(int a, int b)
 {
     this -> player_cards[b] = a;
 }

void Player::display_sum_of_cards()
 {
     cout << this -> sum_of_cards;
 }

void Player::display_cards(int b)
 {
     for(int i=0; i<b; i++)
     {
           if(this -> player_cards[i] == 11)
        cout << "Q ";
        else if(this -> player_cards[i] == 12)
        cout << "J ";
        else if(this -> player_cards[i] == 13)
        cout << "K ";
        else if(this -> player_cards[i] == 14)
        cout << "AS ";
        else cout << this -> player_cards[i] << " ";
     }
 }

void Player::sum_cards(int b)
{
         if(this -> player_cards[b] == 11)
            this -> sum_of_cards = this -> sum_of_cards + 10;
         else if(this -> player_cards[b] == 12)
            this -> sum_of_cards = this -> sum_of_cards + 10;
         else if(this -> player_cards[b] == 13)
            this -> sum_of_cards = this -> sum_of_cards + 10;
         else if(this -> player_cards[b] == 14)
            this -> sum_of_cards = this -> sum_of_cards + 11;
         else this -> sum_of_cards = this -> sum_of_cards + this -> player_cards[b];
}

void Player::display_all_player(int b, int c)
{
            system( "cls" );
          cout << "                            BLACKJACK" << endl;
          cout << endl;
          cout << "Player 1: ";
          this -> display_name();
          cout << endl;
          cout << "Balance: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          this ->display_money();
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Bid: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          cout << c;
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Cards: ";
          this -> display_cards(b);
          cout << endl;
          cout << "Sum of cards: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          this -> display_sum_of_cards();
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void Player::display_all_croupier(int croupier_counter)
{
          cout << "                                                     Croupier" << endl;
          cout << "                                                        Cards: ";
          this -> display_cards(croupier_counter);
          cout << endl;
          cout << "                                                        Sum of cards: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          this -> display_sum_of_cards();
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << endl;
}

void Player::display_bet_player(int b)
{
              cout << "                            BLACKJACK";
          cout <<"                                         FINISH TO WIN: " << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Player: ";
          this -> display_name();
          cout << "                                                                ";
           if(this -> how_many_wins() == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                cout << "1.Win once: 0/1";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }else if(this ->how_many_wins() >= 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout << "1.Win once: 1/1";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
          cout << endl;
          cout << "Balance: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          display_money();
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

          if(this -> how_many_wins() <10)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout << "                                                                2.Wins 10 times: ";
            cout << this -> how_many_wins();
            cout <<"/10";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }else if(this -> how_many_wins() == 10)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << "                                                                2.Wins 10 times: ";
            cout << this -> how_many_wins();
            cout <<"/10";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }

          cout << endl;
          cout << "Cards: ";
          this ->display_cards(b);

          if(this -> balance_b == 0 )
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout << "                                                         3.Achieve a balance 1000$ or more: ";
            cout << money;
            cout <<"/10000";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
          else if(this -> balance_b >= 1)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << "                                                          3.Achieve a balance 1000$ or more";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            this -> balance_b++;
            }


          cout << endl;
          cout << "                                                     Croupier   ";
          if(this -> bid_b < 7500)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout << "        4.Win total 7500$: ";
            cout << bid_b;
            cout <<"/7500";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
          else if(this -> bid_b_c >= 1)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << "        4.Win total 7500$ ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            cout << endl;

}

void Player::display_bet_croupier_good(int croupier_counter)
{
          cout << "                                               Cards: ";
          this -> display_cards(croupier_counter);
          cout << endl;
          cout << endl;
          cout << "How much you want to bet? /Type 'save' to save the progress";
          cout << endl;
          cout << ": ";
}

void Player::display_bet_croupier_good1(int croupier_counter)
{
          cout << "                                               Cards: ";
          this -> display_cards(croupier_counter);
          cout << endl;
          cout << endl;
          cout << "How much you want to bet?";
          cout << endl;
          cout << ": ";
}


void Player::display_bet_croupier_bad(int croupier_counter)
{
          cout << "                                               Cards: ";
          this -> display_cards(croupier_counter);
          cout << endl;
          cout << endl;
          cout << "How much you want to bet?";
          cout << endl;
          cout << ": WRONG ANSWER";
}

void Player::display_all_player2(int b, int c)
{
          cout << endl;
          cout << "Player 2: ";
          this -> display_name();
          cout << endl;
          cout << "Balance: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          this -> display_money();
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Bid: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          cout << c;
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Cards: ";
          this -> display_cards(b);
          cout << endl;
          cout << "Sum of cards: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          this -> display_sum_of_cards();
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

