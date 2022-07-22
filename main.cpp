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

int main()
{
    HANDLE hOut;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    srand(time(NULL));
    string n;
    int v=0;

    do{
    do{

    cout << "                                    WELCOME TO BLACKJACK, GOOD LUCK!" << endl;
    cout << endl;
    cout << "TO READ THE RULES OF THE GAME, TYPE 1: " << endl;
    cout << endl;
    cout << "TO SELECT PLAYERS, TYPE 2: " << endl;
    cout << endl;
    cout << "The best console settings are Window size 120|30 and buffer size 120|9001 in window!";
    cout << endl;

    cout <<": ";
    cin >> n;
     if(n=="1")
     {                                      // ZASADY
        system( "cls" );
        cout << "                                   BLACKJACK - rules" << endl;
        cout << endl;
        cout << "1. Blackjack, a casino card game in which the player tries to beat the croupier by getting as close as possible to 21\npoints without exceeding 21. ";
        cout << "Blackjack is the casino version of the eyecatch game. The players task is to reach\nas close as possible (but no more than) 21 points.\nThe highest hand is called blackjack, i. e. an ace and 10 or a piece for which the player receives 150% of the stake.";
        cout << endl<< endl;
        cout << "                                   CARDS SCORING" << endl;
        cout << endl;
        cout << "1. Cards from two to ten have a value corresponding to the card number.";
        cout << endl;
        cout << "2. Jack, Queen and King have a value of 10 points.\n3. Ass has a value of 11";
        cout << endl<< endl;
        cout << "3. Blackjack is played against the croupier. The player bets on a special table with chips.\nAfter that, the player and the croupier are dealt two cards each. Both of the players cards are turned up,\nwhile only one of the croupiers cards is shown to the player. The player can now make decisions about his next move.\nThe player has the following options:";
        cout << endl<< endl;
        cout << " HIT -> draw a card\n STAND -> dont draw cards\n DOUBLE DOWN -> only possible with the first two cards, then the player receives only one card.";
        cout << endl<< endl;
        cout << "                                   CROUPIER RULES" << endl;
        cout << endl;
        cout << " If the croupier has 16 points or less, he draws another card. If the dealer has 17 or more points, he makes a stand.";
        cout << endl<< endl;
        cout << "Type 1 to return to the main menu: ";
        cin >> n;
        system( "cls" );
     }
     else if(n!="1" && n!="2"){
        system( "cls" );
        cout << "                                    WELCOME TO BLACKJACK, GOOD LUCK!" << endl;
        cout << endl;
        cout << "TO READ THE RULES OF THE GAME, TYPE 1:" << endl;
        cout << endl;
        cout << "ZTO SELECT PLAYERS, TYPE 2: " << endl;
        cout << endl;
        cout << "The best console settings are Window size 120|30 and buffer size 120|9001 in window!";
        cout << endl;
        cout <<": WRONG ANSWER ";
        sleep(2);
        system( "cls" );
      }
      else if(n=="2")
      break;

    }while(n=="1" || (n!="1" && n!="2"));
      int m;






     while(m=2137)
     {                      // WYBOR ILU GRACZY
            system( "cls" );
            cout << "                                       CHOOSE HOW MANY PLAYERS 1 or 2" << endl;
            cout << endl;
            cout << ": ";
            cin >> m;
            if(m==1||m==2)
            {
                break;
            }
            else
            {
            system( "cls" );
            cout << "                                       CHOOSE HOW MANY PLAYERS 1 or 2" << endl;
            cout << endl;
            cout << ": WRONG ANSWER ";
            sleep(2);
            }
     }

     int counter_of_select=0;
     string n,pk;
     string k = "Croupier";
     string load;

        Player croupier(k,0,0,0,0,0);

               string line, name1,op;
                int number_of_line = 1;
                int money1;
                int balance_bb, bid_bb, bid_bc, win1;
                int orr;


        if(m==1){
            fstream file;
            cout << "Enter the name 1 player: ";
            cin >>n;
            system( "cls" );

            cout << "           DO YOU WANT TO LOAD YOUR PROGRESS? y/n";
            cout << endl;
            cout << ": ";
            cin >> load;
            if(load == "y")
            {
                file.open("blacjack_save.txt", ios::in);
                if(file.good() == false)
                {
            system( "cls" );
            cout << "           DO YOU WANT TO LOAD YOUR PROGRESS? y/n";
            cout << endl;
            cout << ": YOU DONT HAVE ANY SAVE";
            sleep(2);
            system( "cls" );
                }else{
                    orr = 1;
              while(getline(file, line))
              {
                  switch(number_of_line)
                  {
                      case 1: name1 = line; break;
                      case 2: money1 = atoi(line.c_str()); break;
                      case 3: win1 = atoi(line.c_str()); break;
                      case 4: win1 = atoi(line.c_str()); break;
                      case 5: balance_bb = atoi(line.c_str()); break;
                      case 6: bid_bc = atoi(line.c_str()); break;
                      case 7: bid_bb = atoi(line.c_str()); break;
                  }
                  number_of_line++;
              }
              }
            }
            file.close();
        }
        if(m==2)
        {
            cout << "Enter the name 1 player: ";
            cin >> n;
            Player p1(n,0,150,0,0,0);
            cout << endl;
            cout << "Enter the name 2 player: ";
            cin >> pk;
            Player p2(pk,0,150,0,0,0);
        }

        system( "cls" );
        int l;
        Player p1(n,0,150,0,0,0);
        Player p2(pk,0,150,0,0,0);

        Player p(n,0,150,0,0,0);

        if(orr == 1)
        {
            p.name = name1;
            p.load_money(money1);
            p.count_winnings(win1);
            p.balance_b = balance_bb;
            p.bid_b = bid_bb;
            p.bid_b_c = bid_bc;
        }
        do{

         int b,c,d = 0;
          int croupier_counter = 0;
            int bid, choice, choice_1, choice_2;
        if(m == 1)
        {
            system( "cls" );
            p.sum_of_cards = 0;
            croupier.sum_of_cards = 0;

            if(p.how_much_money() <=0)
            {
            int t;
            cout << "                              BANKRUPTCY! :(" << endl << endl;

            cout << "TYPE 0 TO START A NWE GAME" << endl;
            cout <<"TYPE 1 TO RETURN TO THE MAIN MENU\nTYPE 2 TO LOAD SAVE: ";
            cin >> t;
            if(t==0)
            {
             p.money_on_start();
             p.count_winnings(0);
             p.balance_b = 0;
             p.bid_b = 0;
             p.bid_b_c = 0;
             continue;
            }
            if(t==1)
            {
             p.count_winnings(0);
             p.balance_b = 0;
             p.bid_b = 0;
             p.bid_b_c = 0;
            system( "cls" );
                break;
            }
            if(t==2)
            {
                fstream file;
                file.open("blacjack_save.txt", ios::in);
                if(file.good() == false)
                {
            system( "cls" );
            cout << "           DO YOU WANT TO LOAD YOUR PROGRESS? y/n";
            cout << endl;
            cout << ": YOU DONT HAVE ANY SAVE";
            sleep(2);
            system( "cls" );
                break;
                }else{
                    number_of_line = 1;
              while(getline(file, line))
              {
                  switch(number_of_line)
                  {
                      case 1: name1 = line; break;
                      case 2: money1 = atoi(line.c_str()); break;
                      case 3: win1 = atoi(line.c_str()); break;
                      case 4: win1 = atoi(line.c_str()); break;
                      case 5: balance_bb = atoi(line.c_str()); break;
                      case 6: bid_bc = atoi(line.c_str()); break;
                      case 7: bid_bb = atoi(line.c_str()); break;
                  }
                  number_of_line++;
              }
              }

            p.name = name1;
            p.load_money(money1);
            p.count_winnings(win1);
            p.balance_b = balance_bb;
            p.bid_b = bid_bb;
            p.bid_b_c = bid_bc;
            file.close();
                continue;
            }
            else
            {
            system( "cls" );
            cout << "                              BANKRUPTCY! :(" << endl << endl;

            cout << "TYPE 0 TO START A NWE GAME" << endl;
            cout <<"TYPE 1 TO RETURN TO THE MAIN MENU\nTYPE 2 TO LOAD SAVE\n :WRONG ANSWER: ";
                sleep(2);
            continue;
            }
            }

            if(p.how_many_wins() >=10 && p.balance_b>=1 && p.bid_b_c >=1)
            {
                system( "cls" );
                cout <<"                          WIN! CONGRATULATION!";
                sleep(2);
                system( "cls" );
                cout <<"                          WIN! CONGRATULATION!";
                sleep(2);
                system( "cls" );
                cout <<"                          WIN! CONGRATULATION!!";
                sleep(2);
                system( "cls" );
                 break;
            }


            do{

            if(p.how_much_money() >= 10000)
            {
                p.balance_b++;
            }

            if(p.bid_b >= 7500)
            {
                p.bid_b_c++;
            }
           b=0;
          string sta;                               // WYSWIETLA ZAKLADY
            system( "cls" );
          p.display_bet_player(b);
          croupier.display_bet_croupier_good(croupier_counter);
          cin >> sta;

        if(sta == "save")
        {
          fstream file;
          file.open("blacjack_save.txt", ios::out);
          file << p.name << endl;
          file << p.how_much_money() << endl;
          file << p.how_many_wins() << endl;
          file << p.how_many_wins() << endl;
          file << p.balance_b << endl;
          file << p.bid_b_c << endl;
          file << p.bid_b << endl;
          file.close();
        }

      bid = atoi(sta.c_str());

      if(bid<=p.how_much_money() && bid > 0)
      {
        p.lose(bid);
        break;
      }
      else if(sta == "save")
      {
          system( "cls" );
          p.display_bet_player(b);
          croupier.display_bet_croupier_good(croupier_counter);
          cout << "SAVE CORRECTLY";
          sleep(1);
      }
        else
       {

        system( "cls" );
            p.display_bet_player(b);
            croupier.display_bet_croupier_bad(croupier_counter);
          sleep(2);
      continue;
      }
            }while(bid=-2137);

         p.black = 0;
  for(int i=0; i<2;i++)
  {

        int k = rand()%13+2;
        p.add_card(k,b);
        b++;
        p.sum_cards(b-1);

        if(k==14)
        {
            p.black = p.black + 1;
        }

  }


          int o = rand()%13+2;
          croupier.add_card(o,croupier_counter);
          croupier_counter++;
          croupier.sum_cards(croupier_counter-1);


          int x=0;
          int z=0;
          int y=0;
          int q=0;

       do{
              p.display_all_player(b,bid);
              croupier.display_all_croupier(croupier_counter);

            if(p.black == 1 && p.sum_of_cards == 21)
            {                       // win
                sleep(1);
                cout << "                       WIN!" << endl;
                p.win(bid);
                sleep(3);
                system( "cls" );
                p.count_win_sum();
                p.black=0;
                p.bid_b = p.bid_b + bid;
                p.black =0;
                 break;
            }


            if(p.black == 2)
            {
                p.sum_of_cards = 12;
            }

            if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p.sum_of_cards > croupier.sum_of_cards) && p.sum_of_cards <= 21)) || croupier.sum_of_cards > 21)
            {
                sleep(1);
                cout << "                       WIN!" << endl;
                p.win(bid);
                sleep(3);
                system( "cls" );
                p.count_win_sum();
                p.bid_b = p.bid_b + bid;
                 break;
            }

                                    // REMIS
            if((croupier.sum_of_cards == 21 && p.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p.sum_of_cards == 20))
              {
                  sleep(1);
                 cout << "                      DRAW!";
                 p.draw(bid);
                 sleep(3);
                 system( "cls" );
                 break;
              }

                                    // PRZEGRANA
            if(((y!=0) && (croupier.sum_of_cards > p.sum_of_cards) && croupier.sum_of_cards<=21) || (p.sum_of_cards > 21))
              {
                 if(p.sum_of_cards < croupier.sum_of_cards && q!=1){
                    cout << "kupka";
                 }else{
                 sleep(1);
                 cout << "                      LOSE :(";
                 sleep(3);
                 system( "cls" );
                 break;
                 }

              }

          cout << "To draw a card type 1: " << endl;
          cout << "To stand type 2: " << endl;
          cout << "To double down type 3 \(If you have only 2 cards): " << endl;
          cout << ": ";
          cin >> choice;
            if(choice == 1 && x>=0)
            {
            int k = rand()%13+2;
            p.add_card(k,b);
            b++;
            p.sum_cards(b-1);
            z++;
            y++;

            }
            if(choice == 2)
            {
                y++;
                q++;
              do{
              if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p.sum_of_cards > croupier.sum_of_cards) && p.sum_of_cards <= 21)) || croupier.sum_of_cards > 21)
            {
                system( "cls" );
                 break;
                 x=10;
            }if(x==10) break;

            if((croupier.sum_of_cards == 21 && p.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p.sum_of_cards == 20))
              {
                 system( "cls" );
                 x=10;
                 break;
              }
              if(croupier.sum_of_cards <=16)
              {
              system( "cls" );
              p.display_all_player(b,bid);
              croupier.display_all_croupier(croupier_counter);

                int o = rand()%13+2;
                croupier.add_card(o,croupier_counter);
                croupier_counter++;
                croupier.sum_cards(croupier_counter-1);

               sleep(1);

              }
              if(( croupier.sum_of_cards > p.sum_of_cards) || (p.sum_of_cards > 21))
              {
                 system( "cls" );
                 x=10;
                 break;
              }if(x==10) break;


              }while(x=99);
            }
            int f=0;
            if(choice ==3 && x>=0 && z==0 )
            {
                system( "cls" );
                if(p.how_much_money() >= bid){
                p.lose(bid);
                bid = bid + bid;

                  int k = rand()%13+2;
                  p.add_card(k,b);
                  b++;
                  p.sum_cards(b-1);

                while(croupier.sum_of_cards <= 17)
                 {
                        int o = rand()%13+2;
                        croupier.add_card(o,croupier_counter);
                        croupier_counter++;
                        croupier.sum_cards(croupier_counter-1);

                    p.display_all_player(b,bid);
                    croupier.display_all_croupier(croupier_counter);

                    sleep(1);

                    if(((croupier.sum_of_cards > p.sum_of_cards) && croupier.sum_of_cards<=21) || (p.sum_of_cards > 21)){
                            sleep(1);
                       cout << "                      LOSE :(";
                        sleep(3);
                        system( "cls" );
                        z=0;
                        f++;
                        break;
                    }if(f==1) break;
                    if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p.sum_of_cards > croupier.sum_of_cards) && p.sum_of_cards <= 21)) || croupier.sum_of_cards > 21){
                        sleep(1);
                       cout << "                      WIN!";
                        p.win(bid);
                        sleep(3);
                        system( "cls" );
                        z=0;
                        f++;
                        p.count_win_sum();
                        p.bid_b = p.bid_b + bid;
                        break;
                    }if(f==1) break;
                    if(croupier.sum_of_cards == p.sum_of_cards){
                        sleep(1);
                        cout << "                      DRAW!";
                        p.draw(bid);
                        sleep(3);
                        system( "cls" );
                        z=0;
                        f++;
                        break;
                   }if(f==1) break;
                 }
                }
             if(f==1) break;
            }
          }while(v=-1);
        }

        int bid_1, bid_2; bid;
     if(m == 2)       //-----------------------------------------------------------  2 players ---------------------------------------------------------------
     {
         system( "cls" );

            croupier.sum_of_cards = 0;

                // GRACZ 2 WYGRYWA

            if(p1.how_much_money() <=0)
            {
            int t;
            cout << "                              BANKRUPTCY! :(" << endl;
            cout << "                             WINS PLAYER 2!" << endl << endl;

            cout << "Type 1 to start a new game or type 0 to return to the main menu: ";
            cin >> t;

            if(t==1)
            {
                p1.implicitly();
                p2.implicitly();

                continue;
            }
            else if(t==0)
            {
                p1.implicitly();
                p2.implicitly();

                system( "cls" );
                break;
            }else
            {
            system( "cls" );
            cout << "                             BANKRUPTCY! :(" << endl;
            cout << "                             WINS PLAYER 2!" << endl << endl;

            cout << "Type 1 to start a new game or type 0 to return to the main menu\n: WRONG ANSWER ";
                sleep(2);
            continue;
            }
            }

            if(p2.how_many_wins() >=10 && p2.balance_b>=1 && p2.bid_b_c >=1)
            {
                system( "cls" );
                cout <<"                          PLAYER 2 WINS! CONGRATULATION!";
            }




            // GRACZ 1 WYGRYWA

            if(p2.how_much_money() <=0)
            {
            int t;
            cout << "                              BANKRUPTCY! :(" << endl;
            cout << "                             PLAYER 1 WINS!" << endl << endl;

            cout << "Type 1 to start a new game or type 0 to return to the main menu\n: ";
            cin >> t;

            if(t==1)
            {
                p1.implicitly();
                p2.implicitly();


                continue;
            }
            else if(t==0)
            {

                p1.implicitly();
                p2.implicitly();

                system( "cls" );
                break;
            }else
            {
            system( "cls" );
            cout << "                              BANKRUPTCY! :(" << endl;
            cout << "                             PLAYER 1 WINS!" << endl << endl;

            cout << "Type 1 to start a new game or type 0 to return to the main menu\n: WRONG ANSWER ";
                sleep(2);
            continue;
            }
            }

            if(p1.how_many_wins() >=10 && p1.balance_b>=1 && p1.bid_b_c >=1)
            {
                system( "cls" );
                cout <<"                          PLAYER 1 WINS! CONGRATULATION!";
            }

            d=0;
            c=0;
        do{

            if(p1.how_much_money() >= 10000)
            {
                p1.balance_b++;
            }

            if(p1.bid_b >= 7500)
            {
                p1.bid_b_c++;
            }
                                            // WYSWIETLA ZAKLADY
          system( "cls" );
          p1.display_bet_player(d);
          croupier.display_bet_croupier_good1(croupier_counter);
          cin >> bid_1;

      if(bid_1<=p1.how_much_money() && bid_1 > 0)
      {
        p1.lose(bid_1);
            break;


      }else
       {
        system( "cls" );
       p1.display_bet_player(d);
        croupier.display_bet_croupier_bad(croupier_counter);
        sleep(2);
        continue;
       }
            }while(bid_1 =-2137);


            do{

            if(p2.how_much_money() >= 10000)
            {
                p2.balance_b++;
            }

            if(p2.bid_b >= 7500)
            {
                p2.bid_b_c++;
            }

                                            // WYSWIETLA ZAKLADY
          system( "cls" );
          p2.display_bet_player(c);
          croupier.display_bet_croupier_good1(croupier_counter);
          cin >> bid_2;

      if(bid_2<=p2.how_much_money() && bid_2 > 0)
      {
        p2.lose(bid_2);
            break;


      }else
       {
        system( "cls" );
        p2.display_bet_player(c);
        croupier.display_bet_croupier_bad(croupier_counter);
        sleep(2);
        continue;
       }
            }while(bid_1 =-2137);


        p1.black = 0;
        p2.black = 0;

        p1.sum_of_cards = 0;
        p2.sum_of_cards = 0;

    for(int i=0; i<2;i++)
    {
        int k = rand()%13+2;
        p1.add_card(k,d);
        d++;
        p1.sum_cards(d-1);

         if(k==14)
         {
            p1.black = p1.black + 1;
         }
    }

    for(int i=0; i<2;i++)
    {
        int k = rand()%13+2;
        p2.add_card(k,c);
        c++;
        p2.sum_cards(c-1);

         if(k==14)
         {
            p2.black = p2.black + 1;
         }
    }



          int o = rand()%13+2;
          croupier.add_card(o,croupier_counter);
          croupier_counter++;
          croupier.sum_cards(croupier_counter-1);

          int x=0;
          int z=0;
          int y=0;
          int q=0;
          int f=0;
          int wygra_1=0;
          int wygra_2=0;
          int draw_1=0;
          int draw_2=0;
          int lose_1 =0;
          int lose_2=0;
       do{

         if(f>=1)
         {
            if((p1.black == 1 && p1.sum_of_cards == 21) || (p2.black == 1 && p2.sum_of_cards == 21))
            {                       // win

                if(p1.black == 1 && p1.sum_of_cards == 21)
                {
                p1.win(bid_1);
                system( "cls" );
                p1.count_win_sum();
                p1.black=0;
                p1.bid_b = p1.bid_b + bid_1;
                p1.black =0;
                wygra_1++;
                }

                if(p2.black == 1 && p2.sum_of_cards == 21)
                {
                p2.win(bid_2);
                p2.count_win_sum();
                p2.black=0;
                p2.bid_b = p2.bid_b + bid_2;
                p2.black =0;
                wygra_2++;
                }
            }


            if(p1.black == 2)
            {
                p1.sum_of_cards = 12;
            }

            if(p2.black == 2)
            {
                p2.sum_of_cards = 12;
            }

            if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p1.sum_of_cards > croupier.sum_of_cards) && p1.sum_of_cards <= 21)) || croupier.sum_of_cards > 21 && p1.sum_of_cards<=21)
                {
                    p1.win(bid_1);
                p1.count_win_sum();
                    p1.bid_b = p1.bid_b + bid_1;
                    wygra_1++;
                }

                if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p2.sum_of_cards > croupier.sum_of_cards) && p2.sum_of_cards <= 21)) || croupier.sum_of_cards > 21 && p2.sum_of_cards<=21 )
                {
                    p2.win(bid_2);
                p2.count_win_sum();
                    p2.bid_b = p2.bid_b + bid_2;
                    wygra_2++;
                }

                                    // REMIS
            if((croupier.sum_of_cards == 21 && p1.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p1.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p1.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p1.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p1.sum_of_cards == 20))
              {
                 p1.draw(bid_1);
                 draw_1++;
              }

              if((croupier.sum_of_cards == 21 && p2.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p2.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p2.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p2.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p2.sum_of_cards == 20))
              {
                 p2.draw(bid_2);
                 draw_2++;
              }

                                    // PRZEGRANA
            if(((y!=0) && (croupier.sum_of_cards > p1.sum_of_cards) && croupier.sum_of_cards<=21) || (p1.sum_of_cards > 21))
              {
                 if(p1.sum_of_cards < croupier.sum_of_cards && q!=1){
                      cout << " ";
                 }else{
                 lose_1++;
                 }

              }

            if(((y!=0) && (croupier.sum_of_cards > p2.sum_of_cards) && croupier.sum_of_cards<=21) || (p2.sum_of_cards > 21))
              {
                 if(p2.sum_of_cards < croupier.sum_of_cards && q!=1){
                    cout << " ";
                 }else{
                 lose_2++;
                 }

              }

            if(wygra_1 >= 1)
            {
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);
              cout << endl << endl;
              cout << "                             PLAYER 1 WIN!";
              sleep(3);
              q++;
            }

            if(wygra_2 >= 1)
            {
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);
              cout << endl << endl;
              cout << "                             PLAYER 2 WIN!";
              sleep(3);
              q++;
            }

              if(lose_1 >= 1)
            {
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);
              cout << endl << endl;
              cout << "                             PLAYER 1 LOSE!";
              sleep(3);
              q++;
            }

            if(lose_2 >= 1)
            {
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);
              cout << endl << endl;
              cout << "                             PLAYER 2 LOSE!";
              sleep(3);
              q++;
            }

            if(draw_1 >= 1)
            {
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);
              cout << endl << endl;
              cout << "                             PLAYER 1 DRAW!";
              sleep(3);
              q++;
            }

             if(draw_2 >= 1)
            {
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);
              cout << endl << endl;
              cout << "                             PLAYER 2 DRAW!";
              sleep(3);
              q++;
            }

            if(q>=2)
            {
                break;
            }
       }
            f++;
            y=0;
            z=0;
         while(y==0)
         {
            p1.display_all_player(d,bid_1);
            croupier.display_all_croupier(croupier_counter);
            p2.display_all_player2(c, bid_2);

          cout << endl << endl;
          cout << "Player 1" << endl;
          cout << "To draw a card type 1: " << endl;
          cout << "To stand type 2: " << endl;
          cout << "To double down type 3 \(If you have only 2 cards): " << endl;
          cout << ": ";
          cin >> choice_1;

          if(choice_1 == 1 && y==0)
            {
                int k = rand()%13+2;
                p1.add_card(k,d);
                d++;
                p1.sum_cards(d-1);
                z++;
            }

            if(choice_1 == 2)
            {
                y++;
            }

            if(choice_1 == 3 && z==0)
            {
                  y++;
                  int k = rand()%13+2;
                  p1.add_card(k,d);
                  d++;
                  p1.sum_cards(d-1);

                 if(p1.how_much_money() >= bid_1){
                p1.lose(bid_1);
                bid_1 = bid_1 + bid_1;
            }
       }
         if(y>=1)
            {
        while(y!=2)
          {
            z=0;
             system( "cls" );
             p1.display_all_player(d,bid_1);
             croupier.display_all_croupier(croupier_counter);
             p2.display_all_player2(c, bid_2);

          cout << endl << endl;
          cout << "Player 2" << endl;
          cout << "To draw a card type 1: " << endl;
          cout << "To stand type 2: " << endl;
          cout << "To double down type 3 \(If you have only 2 cards): " << endl;
          cout << ": ";
          cin >> choice_2;

           if(choice_2 == 1)
            {
                int k = rand()%13+2;
                p2.add_card(k,c);
                c++;
                p2.sum_cards(c-1);
                z++;
            }

         if(choice_2 == 2 && y>=0)
            {
                y++;
            }

         if(choice_2 == 3 && y>=0)
            {
                y++;
            }

            }


         if(choice_2 == 2 && y==2 || p2.sum_of_cards>21)
            {
                y++;
                q++;
              do{
              if((((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p1.sum_of_cards > croupier.sum_of_cards) && p1.sum_of_cards <= 21)) || croupier.sum_of_cards > 21) &&
                (((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p2.sum_of_cards > croupier.sum_of_cards) && p2.sum_of_cards <= 21)) || croupier.sum_of_cards > 21))
            {
                break;
            }

             if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p2.sum_of_cards > croupier.sum_of_cards) && p2.sum_of_cards <= 21)) || croupier.sum_of_cards > 21)
            {
                break;
            }

            if(((croupier.sum_of_cards == 21 && p1.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p1.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p1.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p1.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p1.sum_of_cards == 20)) &&
               ((croupier.sum_of_cards == 21 && p2.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p2.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p2.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p2.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p2.sum_of_cards == 20)))
              {
                break;
              }

            if((croupier.sum_of_cards == 21 && p2.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p2.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p2.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p2.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p2.sum_of_cards == 20))
              {
                break;
              }

            if(p1.sum_of_cards > 21 && p2.sum_of_cards > 21)
            {
                break;
            }


              if((croupier.sum_of_cards <=16 && (croupier.sum_of_cards< p1.sum_of_cards || croupier.sum_of_cards< p2.sum_of_cards)) && (p1.sum_of_cards <=21 || p2.sum_of_cards <=21))
              {
              system( "cls" );
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);

                int o = rand()%13+2;
                croupier.add_card(o,croupier_counter);
                croupier_counter++;
                croupier.sum_cards(croupier_counter-1);

               sleep(1);
              }else break;
              if(croupier.sum_of_cards > p1.sum_of_cards && croupier.sum_of_cards<=21)
              {
                lose_1++;
                q++;
              }

              if(croupier.sum_of_cards > p2.sum_of_cards && croupier.sum_of_cards<=21)
              {
                lose_2++;
                q++;
              }
              if(q>=2)
              {
                  q=0;
                  break;
              }

              }while(x=99);
            }

            if(choice_2 ==3 && p2.how_much_money() >= bid_2)
            {
                system( "cls" );

                p2.lose(bid_2);
                bid_2 = bid_2 + bid_2;

                int k = rand()%13+2;
                  p2.add_card(k,c);
                  c++;
                  p2.sum_cards(c-1);


              do{
              if((((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p1.sum_of_cards > croupier.sum_of_cards) && p1.sum_of_cards <= 21)) || croupier.sum_of_cards > 21) &&
                (((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p2.sum_of_cards > croupier.sum_of_cards) && p2.sum_of_cards <= 21)) || croupier.sum_of_cards > 21))
            {
                break;
            }

             if(((croupier.sum_of_cards >= 17 && croupier.sum_of_cards <= 21) && ((p2.sum_of_cards > croupier.sum_of_cards) && p2.sum_of_cards <= 21)) || croupier.sum_of_cards > 21)
            {
                break;
            }

            if(((croupier.sum_of_cards == 21 && p1.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p1.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p1.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p1.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p1.sum_of_cards == 20)) &&
               ((croupier.sum_of_cards == 21 && p2.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p2.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p2.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p2.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p2.sum_of_cards == 20)))
              {
                break;
              }

            if((croupier.sum_of_cards == 21 && p2.sum_of_cards == 21) || (croupier.sum_of_cards == 17 && p2.sum_of_cards == 17) || (croupier.sum_of_cards == 18 && p2.sum_of_cards == 18) ||
               (croupier.sum_of_cards == 19 && p2.sum_of_cards == 19) || (croupier.sum_of_cards == 20 && p2.sum_of_cards == 20))
              {
                break;
              }

            if(p1.sum_of_cards > 21 && p2.sum_of_cards > 21)
            {
                break;
            }


              if((croupier.sum_of_cards <=16 && (croupier.sum_of_cards< p1.sum_of_cards || croupier.sum_of_cards< p2.sum_of_cards)) && (p1.sum_of_cards <=21 || p2.sum_of_cards <=21))
              {
              system( "cls" );
              p1.display_all_player(d,bid_1);
              croupier.display_all_croupier(croupier_counter);
              p2.display_all_player2(c, bid_2);

                int o = rand()%13+2;
                croupier.add_card(o,croupier_counter);
                croupier_counter++;
                croupier.sum_cards(croupier_counter-1);

               sleep(1);
              }else break;
              if(croupier.sum_of_cards > p1.sum_of_cards && croupier.sum_of_cards<=21)
              {
                lose_1++;
                q++;
              }

              if(croupier.sum_of_cards > p2.sum_of_cards && croupier.sum_of_cards<=21)
              {
                lose_2++;
                q++;
              }
              if(q>=2)
              {
                  q=0;
                  break;
              }

              }while(x=99);
            }
             if(f==1) break;
            }
           }
          }while(v=-1);
      }

      }while(l= 1);

        }while(v=80);




    return 0;
}
