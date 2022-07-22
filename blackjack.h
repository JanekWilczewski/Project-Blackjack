#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Player
{
private:

   int money=150;
   int counter_winnings = 0;

 friend void count_winnings(Player&);
 friend void win(Player&);
 friend void money_on_start(Player&);
 friend void load_money(Player&);
 friend void count_win_sum(Player&);
public:
    int sum_of_cards=0;
    string name;
    int player_cards[100];
    int black = 0;
    int balance_b = 0;
    int bid_b = 0;
    int bid_b_c = 0;

    Player(string n, int s_cards, int m, int b, int b_b, int b_c);
    ~Player();

    void load_money(int a);
    int how_many_wins();
    void count_winnings(int a);
    void count_win_sum();
    void money_on_start();
    int how_much_money();
    void implicitly();
    void win(int a);
    void lose(int a);
    void draw(int a);
    void display_name();
    void display_money();
    void add_card(int a, int b);
    void display_sum_of_cards();
    void display_cards(int b);
    void sum_cards(int b);
    void display_all_player(int b, int c);
    void display_all_croupier(int croupier_counter);
    void display_bet_player(int b);
    void display_bet_croupier_good(int croupier_counter);
    void display_bet_croupier_good1(int croupier_counter);
    void display_bet_croupier_bad(int croupier_counter);
    void display_all_player2(int b, int c);
};
