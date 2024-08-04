#include <iostream>
#include <ctime>
#include <cstdlib>

char user_input();
char pc_input();
std::string show_choice(char input_value);
std::string game_logic(char one, char two);

int main(){
    std::cout<<"\t\t\t******************************"<<std::endl;
    std::cout<<"\t\t\t   Rock-Paper-Scissor Game"<<std::endl;
    std::cout<<"\t\t\t******************************"<<std::endl;

    char user=user_input();
    char pcinput=pc_input();
    std::cout<<"Your choice : "<<show_choice(user)<<std::endl;
    std::cout<<"Computer's choice : "<<show_choice(pcinput)<<std::endl;
    std::cout<<"\t\t\tGame status : "<<game_logic(user,pcinput)<<std::endl;

    system("pause");

    return 0;
}

char user_input(){
    char player;
    do{
    std::cout<<"Choose one following"<<std::endl;
    std::cout<<"********************"<<std::endl;
    std::cout<<"\t\t\t'R' for Rock"<<std::endl;
    std::cout<<"\t\t\t'P' for Paper"<<std::endl;
    std::cout<<"\t\t\t'S' for Scissor"<<std::endl;

    std::cin>>player;
    player=toupper(player);
    }while(player != 'R' && player != 'P' && player != 'S');
    return player;
};
char pc_input(){
    char pc;
    time_t t;
    srand((unsigned)time(&t));
    int num = rand()%3 +1;
    switch (num)
    {
    case 1:
        pc='R';
        break;
    case 2:
        pc='P';
        break;
    case 3:
        pc='S';
        break;
    }
    return pc;
};
std::string show_choice(char input_value){
   std::string value_for_char;
   switch (input_value)
   {
   case 'R':
      return value_for_char="Rock";
   case 'P':
      return value_for_char="Paper";
   case 'S':
      return value_for_char="Scissor";
   }
};
std::string game_logic(char one, char two){
    std::string winner;
    switch (one)
    {
    case 'S':
         if(two=='S'){
            return winner="Draw";
         }else if(two=='P'){
            return winner="You win!";
         }else if(two=='R'){
            return winner="Computer wins!";
         }
        break;
    case 'P':
         if(two=='S'){
            return winner="Computer wins!";
         }else if(two=='P'){
            return winner="Draw";
         }else if(two=='R'){
            return winner="You win!";
         }
        break;
    case 'R':
         if(two=='S'){
            return winner="You win!";
         }else if(two=='P'){
            return winner="Computer wins!";
         }else if(two=='R'){
            return winner="Draw";
         }
        break;
    }
};