//Adventure Game Assignment, Lukas Schoenhofer


//incorporate a sleep function to change the pace of the game and not have it come out all at once.
//create a separate mode that doesn't display numerical values and make current one debug mode. Ask player if they wish to use debug mnode or original.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
int health=10;
int attack, block,turns=0;

int my_rand(static_cast<unsigned int>(time(0))); 
int turn_randomizer=my_rand;
int total_turns=(turn_randomizer%10) + 2;




void sleep ()
{
      bool valid_input;  
            do

            {
        
            string rest="";
            cout<<"Sleeping will restore health to full but add an additional three rounds to the fight. Would you like to go to sleep? ";
            cin>>rest;
            if (rest=="yes"||rest=="y")
            {
                health=10;
                total_turns=total_turns+3;
                cout<<"You slept and are at full health ";
                valid_input=true;

            }
            else if(rest=="no"||rest=="n")
            {
                cout<<"you decide to continue fighting.\n ";
                valid_input=true;
            }
            else
            {
                cout<<"invalid input. ";
                valid_input=false;
            }
            }
            while(!valid_input);
}

void vanilla()
{

while (health>0 && turns <=total_turns-2)
    {
        
        ++turns;
        string fight="";
        





        cout<<"Prepare to brawl. Type 'fight' to begin.\n";
        cin>>fight;
        while (fight!="fight")
            {
            cout<<"Prepare to brawl. Type 'fight' to begin.\n";
            cin>>fight;
            }
        
        
              
        int attack_d = rand();
        int block_d = rand();
        attack=(attack_d % 4) + 1;
        block=(block_d % 4) + 1;
        if (block>=attack)
            {   
             cout<<"successfully blocked!";
            }
        else
            {
            health-=attack;    
            cout<<"You failed to dodge or block.";
            }
           if (health<=4 && health>0)
        {
            bool valid_input;  
            do

            {
        
            string heal="";
            cout<<"Would you like to heal before the next round? ";
            cin>>heal;
            if (heal=="yes"||heal=="y")
            {
                health+=2;
                cout<<"You healed for two points before the next round. ";
                valid_input=true;

            }
            else if(heal=="no"||heal=="n")
            {
                cout<<"you decide to continue fighting.\n ";
                valid_input=true;
            }
            else
            {
                cout<<"invalid input. ";
                valid_input=false;
            }
            }
            while(!valid_input);
        }
        if (turns==total_turns-4)
        {
            sleep();
        }
    
          
    }
    if(health>0)
    {
         cout<<"You won the match. Well done!";
    }
    else 
    {
        cout<<"You were knocked out. Mission failed, we'll get em next time.";
    }

}


void debug_mode()
{

while (health>0 && turns <=total_turns-2)
    {
        
        ++turns;
        string fight="";
        





        cout<<" Prepare to brawl. There are " <<total_turns-turns<<" rounds left. Type 'fight' to begin.\n";
        cin>>fight;
        while (fight!="fight")
            {
            cout<<"Prepare to brawl. There are " <<total_turns-turns<<" rounds left.\n\n Type 'fight' to begin.\n";
            cin>>fight;
            }
        
        
              
        int attack_d = rand();
        int block_d = rand();
        attack=(attack_d % 4) + 1;
        block=(block_d % 4) + 1;
        if (block>=attack)
            {   
             cout<<"successfully blocked! "<<health<<" health remaining\n";
            }
        else
            {
            health-=attack;    
            cout<<"You failed to dodge or block, and got hit for "<<attack<<" damage. "<<health<<" health remaining. \n";
            }
           if (health<=4 && health>0)
        {
            bool valid_input;  
            do

            {
        
            string heal="";
            cout<<"Would you like to heal before the next round? ";
            cin>>heal;
            if (heal=="yes"||heal=="y")
            {
                health+=2;
                cout<<"You healed for two points for a total of "<<health<<" health before the next round. ";
                valid_input=true;

            }
            else if(heal=="no"||heal=="n")
            {
                cout<<"you decide to continue fighting.\n ";
                valid_input=true;
            }
            else
            {
                cout<<"invalid input. ";
                valid_input=false;
            }
            }
            while(!valid_input);
        }
        if (turns==total_turns-4)
        {
            sleep();
        }
    
          
    }
    if(health>0)
    {
         cout<<"You won the match. Well done!";
    }
    else 
    {
        cout<<"You were knocked out. Mission failed, we'll get em next time.";
    }

}


int main()
{ 
    cout<<"Welcome to Punch!\n"; 
    
          bool valid_input;  
            do

            {
        
            string d_mode="";
            cout<<"Debug mode will display all numerical values while you play. Start the game in debug mode?";
            cin>>d_mode;
            if (d_mode=="yes"||d_mode=="y")
            {
               cout<<"starting debug mode... ";
               valid_input=true;
                debug_mode();

            }
            else if(d_mode=="no"||d_mode=="n")
            {
                cout<<"Starting standard mode...\n ";
                valid_input=true;
                vanilla();

            }
            else
            {
                cout<<"invalid input. ";
                valid_input=false;
            }
            }
            while(!valid_input);

    return 0;
}

    

        
            
        





