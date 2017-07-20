//Text Based Door Simulator
//Made by Alex Huard

//Improved Edition
//2016

//This game is horribly written and I am sorry
//Still Making it better, 2017

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include "screen.h"
//#include "Turns.h" See line 803
#include <assert.h>
#include <fstream> 
#include <time.h>//For Logging things

using namespace std;
#include "BasicFunctions.cpp"
#include "Phrases.cpp"


bool newgameplus(bool iceoff);



bool logging = true; //For Logging things


//Every command should work



/*
********************************************************************
************************CURRENT THINGS TO DO************************
********************************************************************
	Change all instances of input to the new checkb and order *IMPORTANT*
	Make an actual parser **IMPORTANT(?)**
	Finish new game plus
	Finish Phrases.h *IMPORTANT*
	Fix Everything


*/
int main()
{
	//system("COLOR F0");

	int gamestyle = 0;
	bool gamebeaten = false;
	string subtitle = "A Tale of One Door";
	
	do
	{

		//variables and such
		bool left = false;//knob direction **BAD**
		bool right = false;//knob direction **BAD**
		bool firmness = false; //is the command firm
		bool stepback = false; //has the player stepped back **BAD**
		bool sword = false; //is the player holding a sword
		bool iceproof = false; //is the player iceproof
		bool open = false; //true if door is open **What?**
		bool lights = true; //true = on, false = off
		//Not important variables
		bool footpain = false;
		bool nosebleed = false;
		
		int turnstaken = 0;//Turns taken
		int handstate = 0;//The state of the player's hand
		int direction = 0;//Direction the player is looking, 0 is at the door and all other directions are clockwise relative to this
		
		
		
		string dummy;
		
		
		/*
		-1 - hand is on door but not on the knob
		0 - hand is not on door knob
		1 - hand is on door knob but not a firm grasp
		2 - hand is firmly on the door knob
		3 - hand has turned door knob
		*/
		
		opening(subtitle);
		
		ofstream fout;
			
		if (logging)
		{
			fout.open("Log.txt", ios::app);
		}
	
		if(gamestyle == 1)
		{
			NGPlus();
		}
		
		
		cout<<LookAtValue<<endl;
		
		//Game Loop
		do{
		
				//Prints the current value of lookAtValue
				
				/*if (look == true){
					cout<<LookAtValue<<endl;
					look = false;
				}
				cout<<endl;*/
			firmness = false;
			
			userInput = prompt();
			
			if (wordCheckB("tight")||wordCheckB("firm")||wordCheckB("force"))
			{
				firmness = true;
			}
			
			//One Word Commands
			
			
			
			if (wordCheckB("condition") || wordCheckB("status"))
			{
				cout<<status<<endl;
			}
			else if (wordCheckB("inventory"))
			{
				if (sword == true)
				{
					cout<<"You have a broadsword, capable of felling a whole enemy if need be the occasion\n";
				}
				else
				{
					cout<<"You have a small song of good feelings.\n";
					cout<<"You also have a signed copy of 'DOORS AND YOU: A BEGINNER'S GUIDE TO DOOR OPENING'";
				}
				
			}
			//looking at the door
			else if (wordOrder("look", "door"))
			{
				
				cout<<DoorState<<endl;
			}
			//Looking at the floor
			else if (wordOrder("look", "floor"))
			{
				cout<<Floorstate<<endl;
			}
			else if (wordCheckB("look"))
			{
				cout<<LookAtValue<<endl;
				//cout<<userInput.find("knob");
			}
			
			
			//KILL THE LICH
			
			else if (userInput == "killthelich")
			{
				
				cout<<"You feel a chill go through your body, as if some terrible evil is upon you.\n";
				system("COLOR 0A");
				gamestyle = 1;
			}
			
			else if (wordOrder("kick", "door"))
			{
				cout<<"You kick the door with all of your might!\nOuch!\n";
				cout<<"Your foot is now in pain.\n";
				if (footpain == false)
				{
					status = "Your foot is in pain\n"+status;
					footpain = true;
				}
			}
			
			else if (wordOrder("kill", "lich"))
			{
				cout<<"Now why would you want to do something like that?\n";
			}
			
			//get that sword
			
			else if ((wordCheckB("pick")|| (wordCheckB("get")) || (wordCheckB("take")) || (wordCheckB("grab"))) && ((wordCheckB("sword")) || wordCheckB("hilt")))
			{
				if ((wordCheckB("sword")))
				{
					if (gamestyle == 1)
					{
				
						if ((wordCheckB("handle")) || (wordCheckB("hilt")))
						{
							if (sword == false)
							{
								cout<<"You have picked up the sword, it is heavy yet swinging it feels almost effortless.\n";
								sword = true;
							}
							else
							{
								cout<<"You already have a sword, why replace your nice one with the non existent one \nthat you seem to think is on the floor?\n";
							}
						}
						else
						{
							cout<<"You grab the sword blade and cut yourself accidentally,\nYou have dropped the sword.\nYour hand is now bleeding.\n";
						}
					}
					else
					{
						cout<<"What sword?\nYou must be crazy or something to think theres a sword in this room.\n";
					}
				
				}
				else
				{
					cout<<"Grab the hilt of what?\n";
				}
			}
			else if (wordCheckB("timetoslam"))
			{
				if (iceproof == false)
				{
					if (gamestyle == 0)
					{
						cout<<"Barkley's words echo in your head...\n";
						stringOut("Theres a time and a place for everything, 111but not now.\n");
					}
					else
					{
						cout<<"Wind starts forming a small twister within the room, you hear a crowd \ncheering as the count down\n";
						keyp();
						delay(1000);
						cout<<"5\n\n";
						delay(1000);
						cout<<"4\n\n";
						delay(1000);
						cout<<"3\n\n";
						delay(1000);
						cout<<"2\n\n";
						delay(1000);
						cout<<"Just then as if by some spectral magic, Charles Barkley jumps out from\n"
							<<"the twister to do a slam dunk on the spectral wind hoop that had just\n"
							<<"formed behind you as a deafening buzzer goes off in the room.\n";
						keyp();
							
					
						cout<<"Charles looks to you and forms a new ball in his hands from the\n"
							<<"spectral winds of the twister.  He then yells\n";
						keyp();
						stringOut("\t'SPECTRAL SLAM OF ICE PROTECTION'\n");
						keyp();
						cout<<"and in a magnificent display of wind and lightning,\n"
							<<"Charles slams the ball through your head and you feel the magic fill your body.\n"
							<<"You begin to thank Charles but he is gone.\n";
						cout<<"You are now marginally immune to ice!\n";
						iceproof = true;
						
					}
				}
				else
				{
					cout<<"Barkly's words echo in your head-\n";
					stringOut("\t'There is a time and place for everything\n \tbut not now.'\n");
				}
			
			
			
			}
			
			
			else if (wordCheckB("read"))
			{
				if (wordCheckB("inscri") || (wordCheckB("wall")) || (wordCheckB("words")))
				{
					if (gamestyle == 1)
					{
						
						cout<<"You begin to read, unfortunately you are a very slow reader.\n";
						
						string inscription = "1111111111\tTo best 111t111he Li11111c111111h is a 11111chal111lenge\n\tthats 111im111111p111o1111s1111si111111b1111111le wi111111t111111h1111111111out some ma11111gi111111c.\n\tRe1111ci1111te the p11111h1111rase 11111T111111I11111M1111E111111T11111111O1111111111S1111L11111A11111111M\n\tor y1111o111u1111r end will be 11111tra111111g111ic\n";
						
						stringOut(inscription);
					
						
					}
					else
					{
						cout<<"Read what?\n";
					}
				}
				else if (wordCheckB("book") || wordCheckB("doors and you"))
				{
					guide();
				}
				else
				{
					cout<<"Read what?\n";
				}
				
			}
			
			else if (wordCheckB("search"))
			{
				if (gamestyle == 0)
				{
					cout<<"You look around the room but are unable to find much.\n";
				}
				else
				{
					if (sword == false)
					{
						cout<<"There is a sword on the floor and a small inscription on the wall.\n";
					}
					else
					{
						cout<<"There is a small inscription on the wall\n";
					}
				}
			}
			
			else if ((wordOrder("open", "door")) || (wordOrder("pull", "handle")))
			{
				switch(handstate)
				{
					case(-1):
					{
						cout<<"You pull your hand away from the door though the door does not follow suit.\nYour hand is no longer on the door.\n";
						handstate = 0;
						break;
					}
					case(0):
					{
						cout<<"Though your efforts vailant, you are unable to open the door through sheer willpower alone.\nIt feels as if you are missing some vital steps here.\n";
						break;
					}
					
					case(1):
					{
						cout<<"The door resists as if some strange mechanism was holding it shut\nIt feels as if you are missing some vital steps here.\n";
						break;
					}
					
					case(2):
					{
						cout<<"The door resists as if there was an opposing force, \ndesigned to hold said door shut.\n";
						break;
					}
					case(3):
					{
						if (stepback == false)
						{
							cout<<"The door comes towards you full force and unfortunately, \nyour face was in the path of it.\n"
								<<"The sudden stimulation of the collision causes you to let go of the knob \nas you grab your face in pain\n"
								<<"Your nose is bleeding and whats worse, the door has shut itself.\n";
							Floorstate = "The floor is cold and unforgiving, \nholding battlescars from the many who have walked across it and\nis now littered with your blood.";
							handstate = 0;
							if (nosebleed == false)
							{
								status = "Your nose is bleeding.\n"+status;
								nosebleed = true;
							}
						}
						else
						{
							system("CLS");
							cout<<"The door opens and nearly misses your face as you pull it inwards\n"
								<<"The door is now open\n";
								open = true;
						
						}
					}
				}
			}
			
			//Help
			
			else if (wordCheckB("help"))
			{
				help();
			}
			else if ((wordCheckB("dance")) || (wordCheckB("jig")))
			{
				cout<<"You attempt to do a small dance of sorts but there isn't enough room.\n";
			}
			
			else if (userInput.find("score") <1000)
			{
				cout<<"Turns taken: "<<turnstaken<<endl
					<<"Doors opened: "<<gamestyle<<endl
					<<"Maidens saved: 0"<<endl
					<<"Liches killed: 0"<<endl
					<<"Current alignment: ";
				if (left == true)
				{
					cout<<"Chaotic Evil\n";
				}
				else if (right == true)
				{
					cout<<"Lawful Good\n";
				}
				else
				{
						cout<<"Neutral\n";
				}
			
			}
			
			

			
			//***********************
			//**Walking on Sunshine**
			//***********************
			//This is all very bad and needs fixing
			else if ((userInput.find("step") <1000) || (userInput.find("walk") <1000))
			{
			
				if ((0<userInput.find("back") && ( userInput.find("back")<1000)))
				{
				
					
					switch(direction)
					{
						case(0):
						{
							if (stepback == false)
							{
								cout<<"You succsessfully take one step back.\n";
								stepback = true;
							}
							else
							{
								cout<<"There is a wall there that you so gracefully collide with.\n";
							}
							break;
						}
						case(1):
						{
							cout<<"The room is at such a small size that such an action is impossible.\n";
							break;
						}
						case(2):
						{
							if (stepback == true)
							{
								cout<<"You successfully take one step back.\n";
								stepback = false;
							}
							else
							{
								cout<<"You collide with the door as you back up...\nNope still not open.\n";
							}
							break;
						}
						case(3):
						{
							cout<<"You attempt such a feat but there is a wall behind you.\nbetter luck next time.\n";
							break;
						}
						
					}
					
					
					
				}
				else if ((0<userInput.find("forward") && ( userInput.find("forward")<1000)))
				{
				
					switch(direction)
					{
						case(0):
						{
							if (stepback == true)
							{
								cout<<"One small step for you...\nThats generally it I suppose\n";
								stepback = true;
							}
							else
							{
								cout<<"You would move closer to the door but you dont want to crowd it.\n";
							}
							break;
						}
						case(1):
						{
							cout<<"You start to walk towards the wall but unfortunately the wall enforces its physical being on your foot.\nYou now have hurt your foot.\n";
							break;
						}
						case(2):
						{
							if (stepback == true)
							{
								cout<<"You collide the wall...\nOuch!\n";	
							}
							else
							{
								cout<<"You walk towards the wall and away from the door.\n";
								stepback = false;
							}
							break;
						}
						case(3):
						{
							cout<<"The wall kindly reminds you of its existence as you collide with it.\n";
							break;
						}
						
					}
					
				}
				else if (0<userInput.find("left") && ( userInput.find("left")<1000))
				{
				
					switch(direction)
					{
						case(0):
						{
								cout<<"The wall kindly rejects your offer of affection for it by colliding with you quite rudely.\n";
							
							break;
						}
						case(1):
						{
							if (stepback == true)
							{
								cout<<"You sliiiiide to the door\n";
								stepback = false;
							}
							else
							{
								cout<<"You find that the door meets your physical contact with little to no reaction.\n";
							}
							break;
						}
						case(2):
						{
							cout<<"You find that the walls persist in their stance of keeping the room together\n";
							break;
						}
						case(3):
						{
							if (stepback == false)
							{
								cout<<"You shuffle to the leftward of your current positon,\naway from the glorious Door.\n";
								stepback = true;
							}
							else
							{
								cout<<"You offer the argument of your movement but unfortunately the walls have voted \nto persist.\n";
							}
							break;
						}
					}
					
				}
				else if (0<userInput.find("right") && ( userInput.find("right")<1000))
				{
					switch(direction)
					{
						case(0):
						{
							cout<<"There is a wall there that decides its existence is more\nimportant than your progression through it.\n";
							break;
						}
						case(1):
						{
							if (stepback == false)
							{
								cout<<"Right you go, away from any door shaped entities in the area.";
								stepback = true;
							}
							else
							{
								cout<<"Walls are hard to pass through in your current physical form\n";
							}
							break;
						}
						case(2):
						{
							cout<<"You slide so far to the right that in fact you haven't moved at all.\nMostly because of physical barriers such as walls.\n";
							break;
						}
						case(3):
						{
							if (stepback == true)
							{
								cout<<"You make your way right in search of the door.\nYou have achieved this goal";
								stepback = false;
							}
							else
							{
								cout<<"The door stands firm and prevents this from happening.\n";
							}
							break;
						}
					}
				}
				else
				{
					cout<<"Step where?\n";
				}
			}
			else if (wordCheckB("sing"))
			{
				cout<<"You begin to sing---\n\n";
				string song = "Of dangers and dragons and Liches and more1\nthere was never a challenge as fierce as the door.\n\n11Through legends and myth, with many to try,\n1the door was never the one who would die.\n\n11So for those who dare, to challenge its might,\n1just be sure to turn the knob right111\n\nor left.\n";
				stringOut(song);
			
			}
			//Grabbing
			
			else if (((userInput.find("grab") <1000) || (userInput.find("put") <1000) || (userInput.find("place") <1000) || (userInput.find("establish") <1000) || (userInput.find("lay") <1000) || (userInput.find("settle") <1000)|| (userInput.find("establish") <1000) || ((userInput.find("grasp") <1000)) || (userInput.find("hold") <1000)) && !((userInput.find("sword") <1000) || userInput.find("hilt") < 1000))
			{
			
			
				if ((0<userInput.find("hand") && ( userInput.find("hand")<1000)) || ((userInput.find("grasp") <1000)) || (userInput.find("hold") <1000) || (userInput.find("grab") <1000))
				{
					if ((userInput.find("hand")<userInput.find("door") || ((userInput.find("grasp") <1000)) || (userInput.find("hold") <1000) && ( userInput.find("door")<1000)) || ( userInput.find("knob")<1000) || ( userInput.find("handle")<1000))
					{
						if ( (userInput.find("knob")<1000) || ( userInput.find("handle")<1000)) // old one, mysteriously evaluates to true always(((userInput.find("door") <userInput.find("knob")) &&( userInput.find("knob")<1000)) || ((userInput.find("grasp") <1000) && ( userInput.find("knob")<1000)) || ((userInput.find("hold") <1000) && ( userInput.find("knob")<1000)) || ((userInput.find("door")) <userInput.find("knob")) || (((userInput.find("grasp") <1000)) &&( userInput.find("handle")<1000)) || ((userInput.find("hold") <1000) &&( userInput.find("handle")<1000)))
						{
						
							if (firmness == true)
							{
								if ((handstate != 2)) 
								{
									cout<<"You firmly grasp the door knob, \nthe full fury of eleven mountain lions in your grip\n";
									DoorState = "The door is still closed though the firmness of your grasp \nis causing the doorknob to tremble at your might\n ";
									handstate = 2;
								}
								else
								{
									cout<<"You would attempt to muster the strength of a twelfth mountain lion \nbut fear that it would destroy the door knob\n";
								}
							}
							
							
							
							
							else if ((handstate > 0))
							{
								cout<<"Your hand is already on the door's knob\n";
							}
							else
							{
								cout<<"You gently place your hand on the door knob\n"
									<<"It feels cold to the touch but quickly warms to your hand\n";
								handstate = 1;
								DoorState = "The door is currently in the factory default 'closed' version\nYour hand is gently holding the knob to the door.\n";
							}
						}
						else
						{
							if (handstate == -1)
							{
								cout<<"I understand your compulsive need to put your hand more on the door\n"
									<<"but your hand is about as on the door as it gets.\n";
							}
							else
							{
								handstate = -1;
								cout<<"Your hand is now placed upon the door.\n"
									<<"It seems as firm as the tree it once was, \n"
									<<"almost enveloping you as you bask in its majesty.\n";
								DoorState = "The door is currently in the factory default 'closed' version\nYour hand is on the door.\n";
							}
						}
					}
					else
					{
						cout<<"Closer but you need to add a location to put said 'Hand'\n";
					}
					
				}
				else
				{
					cout<<"Can I buy a noun?\n";
				}
			}
			
			
			
			//Rotating the door knob
			
			else if ((userInput.find("turn") < 1000) || (userInput.find("rotate") < 1000))
			{
				
				if (((userInput.find("turn")<userInput.find("knob") && ( userInput.find("knob")<1000)) || (userInput.find("turn")<userInput.find("handle") && ( userInput.find("handle")<1000))) || (userInput.find("rotate")<userInput.find("knob") && ( userInput.find("knob")<1000)) || (userInput.find("rotate")<userInput.find("handle") && ( userInput.find("handle")<1000)))
				{
					if ((userInput.find("knob")<userInput.find("left") && ( userInput.find("left")<1000)) || (userInput.find("knob")<userInput.find("right") && ( userInput.find("right")<1000)) || (userInput.find("handle")<userInput.find("left") && ( userInput.find("left")<1000)) || (userInput.find("handle")<userInput.find("right") && ( userInput.find("right")<1000)))
					{
					
						switch(handstate)
						{
							case(-1):
							case(0):
							{
								cout<<"Your hand is not on the door knob\n";
								break;
							}
							case(1):
							{
								cout<<"You attempt to rotate the door knob but you lose your gentle grip\n"
									<<"Your hand is no longer on the knob\n";
								handstate = 0;																		
								break;
							}
							case(2):
							{
								cout<<"You firmly turn the doorknob,\nthe mechanisms within the door make subtle noices of their mastery within.\n";
								handstate = 3;
								
								if (userInput.find("left")<1000)
								{
									left = true;
								}
								else if (userInput.find("right")<1000)
								{
									right = true;
								}
									
									
								break;
							}
							case(3):
							{
									
								if (userInput.find("left")<1000)
								{
									if (left == true)
									{
										cout<<"You cannot turn the doorknob any more left than it already is.\n";
										break;
									}
									else if (right == true)
									{
										cout<<"You have unturned the knob\n";
										right = false;
										handstate = 2;
										break;
										
									}
								}
								else if (userInput.find("right")<1000)
								{
								
									if (left == true)
									{
										cout<<"The doorknob has now returned to its unturned state.\n";
										left = false;
										handstate = 2;
										break;
									}
									else if (right == true)
									{
										cout<<"Trust me, it is not right to turn the knob right any more.\n";
										break;
									}
								
								}	
								
							}
							
						}
						
					}
					else
					{
						switch(handstate)
						{
							case(-1):
							case(0):
							{
								cout<<"Your hand is not on the door knob\n";
								break;
							}
							case(1):
							{
								cout<<"You attempt to rotate the door knob but you lose your gentle grip\n"
									<<"Your hand is no longer on the knob\n";
									handstate = 0;
									break;
							}
							case(2):
							{
								cout<<"Your hand rotates, but not in a direction that advances your quest to open a door\n";
								break;
							}
						
						}
					}
				}
				// ********************************
				// **FIX ALL OF THIS DO THIS SOON**
				// ********************************
				
				else if (wordOrder("turn", "left"))
				{
					//Spin
					
					direction -= 1;
					
					if (direction == -1)
					{
						direction = 3;
					}
						
					switch(direction)
					{
						case(0):
						{
							cout<<"You turn left to face door, the door is now in front of you again.\n";
							break;
						}
						case(1):
						{
							cout<<"You turn left to face the wall, the door is now on your left.\n";
							break;
						}
						case(2):
						{
							cout<<"You turn left to face the back wall, the door is now behind you.\n";
							break;
						}
						case(3):
						{
							cout<<"You turn left to face the wall, the door is now on your right.\n";
							break;
						}
						
					}
				}
				else if ((userInput.find("turn")<userInput.find("right")) && userInput.find("right")<1000)
				{
					direction += 1;
					if (direction == 4)
					{
						direction = 0;
					}
							
					switch(direction)
					{
						case(0):
						{
							cout<<"You turn right to face door, the door is now in front of you again.\n";
							break;
						}
						case(1):
						{
							cout<<"You turn right to face the wall, the door is now on your left.\n";
							break;
						}
						case(2):
						{
							cout<<"You turn right to face the back wall, the door is now behind you.\n";
							break;
						}
						case(3):
						{
							cout<<"You turn right to face the wall, the door is now on your right.\n";
							break;
						}
						
					}
				}
				else
				{
					cout<<"How can turn yes but no are direction?\n";
				}		
				
				
			}
		
			
			else if ((firmness == true && handstate == 1) || (firmness == true && handstate == 2) )
			{
				if (handstate == 1)
				{
					cout<<"You tighten your grip with the force of eleven mountain lions\n";
					handstate = 2;
				}
				else
				{
					cout<<"You attempt to tighten your hand further but alas it is impossible\n";
				}
			
			}
			
			else
			{
			cout<<userInput<<" is not a command I recognize.\n";
			fout<<userInput<<endl;
			}
			//removeme
			//cout<<direction<<endl;

			
			turnstaken++;
			
			/*
			if (turnstaken == 10)
			{
				turnstimesten++;
				turnstaken = 0;
			}
			*/
			if (gamestyle == 1)
			{
				switch(direction)
				{
					case(0):
					{
						LookAtValue = "You are in a small room, there is a door in front of you";
						break;
					}
					case(1):
					{
						LookAtValue = "You look at the wall, there is a small inscription here.";
						break;
					}
					case(2):
					{
						LookAtValue = "You look at the wall, there is a broadsword on the floor here";
						break;
					}
					case(3):
					{
						LookAtValue = "You look at the wall, there is not much to this one.";
						break;
					}
				
				
				
				}
			}
			

		}while(open==false);
		if (gamestyle == 0)
		{
			system("PAUSE");
			system("CLS");
			cout<<endl
				<<"          Congragitations                            ___________      \n"
				<<"              A winrar is you!                     /|           |     \n"
				<<"                                                  / |           |     \n"
				<<"                                                 /  |           |     \n"
				<<"                                                /   |           |     \n"
				<<"                                               |    |           |     \n"
				<<"                                               |    |           |     \n"
				<<"                                               |    |           |     \n"
				<<"                                               |    |           |     \n"
				<<"                                               |    |           |     \n"
				<<"                                               |0   |           |     \n"
				<<"                                               |    |___________|     \n"
				<<"                                               |   /                  \n"
				<<"                                               |  /                   \n"
				<<"                                               | /                    \n"
				<<"                                               |/                     \n"
				<<"It took you "<<turnstaken<<" turns to win the game                    \n"
				<<"                   Lowest possible score: 4                           \n\n\n";
				
				system("PAUSE");
				
				
				system("CLS");
				cout<<"                         A new day brings new adventure,\n"
					<<"                                 but for now...\n\n\n"
					<<"                                 rest easy heroes\n\n\n\n\n\n";
				system("PAUSE");
				system("CLS");
				cout<<"New game plus unlocked!\n\n";
				cout<<"Press any key to begin!";
				getch();
				system("COLOR 0A");
				subtitle = "Better Game Edition";
				gamestyle=1;
				system("CLS");
				
		}
		else
		{
			//calling endgame
			gamebeaten = newgameplus(iceproof);
		}
		
	
	}
	while (gamebeaten == false);
	system("CLS");
	cout<<endl
				<<"          Congratuitousulations                      ___________      \n"
				<<"              A REAL winrar is you!!!!!!           /|           |     \n"
				<<"                                                  / |           |     \n"
				<<"       Through challenges a many                 /  |           |     \n"
				<<"         With wisdom and might                  /   |           |     \n"
				<<"        the Lich has been bested               |    |           |     \n"
				<<"         So sleep easy tonight                 |    |           |     \n"
				<<"                                               |    |           |     \n"
				<<"        A new day shall dawn                   |    |           |     \n"
				<<"       A new challenge to fell                 |    |           |     \n"
				<<"       But for now fair heroes                 |0   |           |     \n"
				<<"         I bid you farewell.                   |    |___________|     \n"
				<<"                                               |   /                  \n"
				<<"                                               |  /                   \n"
				<<"                                               | /                    \n"
				<<"                                               |/                     \n";
	system("PAUSE");
	system("CLS");
	
	
	
	return 0;
}

bool newgameplus(bool iceoff)
{
	system("CLS");
	cout<<"A cold breeze blows across your face as you open the door.\n"
		<<"It is the Lich!\n"
		<<"'I see you escaped the room!' \nhe states as he raises his hands up.\n"
		<<"'Its a shame that this will be your last triumph'\n";
	system("PAUSE");
	system("CLS");
	cout<<"You have one chance before you are frozen, make it count!\n\n";
	bool NGPend = false;
	bool FinalAttack = false;
	do
	{
		
		string userInput = prompt();
		
		if ((userInput.find("shut") < 1000 || userInput.find("close")<1000 || userInput.find("slam")<1000) && userInput.find("door")<1000)
			{
				cout<<"You slam the door in the Lich's face and see ice cover the entire inner portion of the door\n"
					<<"The door is no longer usable now that the magical ice has covered it.\n\n";
				cout<<"Game over\n\n";
				cout<<"Press any key to door again.\n";
				NGPend = true;
				getch();
			 
			}
		else if ((userInput.find("step")< 1000 ) || (userInput.find("walk")< 1000 ))
		{
			if (iceoff == false)
			{
			cout<<"You attempt to move but unfortunately you are frozen before you can move\n";
			cout<<"Thats about it...\n";
			cout<<"Uhh...";
			delay(500);
			cout<<"Game over I guess\n"
				<<"Press any key to door again\n.";
			getch();
			NGPend = true;
			
			}
			else if (iceoff == true)
			{
				cout<<"You attempt to move but are frozen by Lichy ice magic\n";
				cout<<"The Lich looks upon you confused at what you were attempting when suddenly\n"
					<<"You hear a voice.>>\n";
					getch();
				stringOut("'Its not the slam in your game\n");
				stringOut("its the slam in your heart'\n");
				cout<<">>\n";
					getch();
				cout<<"You begin to thaw but the Lich realizes and quickly stops it using more\n"
					<<"ice magic to cover you futher though not touching you any more.\n"
					<<"You can move but are now trapped in a small sphere of ice.\n";
				cout<<"Game Over\n";
				cout<<"Press any door to key again\n";
				getch();
				NGPend = true;
				
			}
			
			
		}
		else if (userInput.find("timetoslam") < 1000)
		{
			if (iceoff == false)
			{
			cout<<"You begin to shout \n'TIME TO' \nJust then, the Lich freezes you.\n";
			cout<<"Maybe you should have ice protected sooner\n";
			cout<<"Game Over\n";
			cout<<"Press any key to try to again the game\n";
			getch();
			NGPend = true;
			
			
			
			}
			else
			{
				cout<<"You begin to shout \n'TIME TO' \nJust then, the Lich freezes you.\n";
				cout<<"Just then, you hear a voice.\n"
					<<"'Its not the slam in your game\n"
					<<"its the slam in your heart'\n";
				cout<<"You muster all of your strength to shout the final word\n"
					<<"'SLAM'\n"
					<<"you scream toward the Lich as the melted ice forms a vortex \n"
					<<"around you.  The Lich holds up his staff as to cast another\n"
					<<"spell.  Just then, a buzzer goes off as a hoop forms over\n"
					<<"the Lich's staff.  Charles Barkley shatters it with a\n"
					<<"ball made of pure Spectral Slam Energy.\n";
				cout<<"The Lich cries out as his source of energy is destroyed\n";
				stringOut("'You fool!'\n");
				cout<<"he shouts at Charles as he crumbles to the ground.\n"
					<<"Charles begins to speak\n";
					//finish this dialog
			}
		
		}
		else if (userInput.find("swing")< 1000 )
		{
			if (userInput.find("sword") < 1000)
			{
				if (userInput.find("lich") < 1000)
				{
					if (FinalAttack == false)
					{
						if (iceoff == false)
						{
							cout<<"You begin to strike the Lich but he unfortunately freezes you before you can \nland your blow.\n"
								<<"Better luck next time\n"
								<<"Game Over.\n"
								<<"Press any key to try again\n";
								getch();
								NGPend = true;
						}
						else
						{
							cout<<"You begin to strike as the Lich freezes you solid with your blade mid-swing\n"
								<<"'Hahaha' \nThe Lich begins to cackle\n"
								<<"Just then the ice begins to feel warm as it starts to melt around you.\n"
								<<"You hear a voice.>>\n";
							getch();
							stringOut("'Its not the slam in your game\n");
							stringOut("its the slam in your heart'\n");
							cout<<">>\n";
							getch();
							cout<<"The Lich is too busy laughing to notice that you are out of the ice\n"
								<<"You must think quick before the Lich realizes you are free!\n"
								<<"What will you do?\n";
								FinalAttack = true;
						}
					}
					else
					{
						cout<<"The Lich looks up to see not the icecube of a man which he expected,\n"
							<<"but instead a hero holding his sword valiantly in the air as\n"
							<<"the sword decsends to make the final strike.\n"
							<<"He attempts to freeze you again but the sword cuts his magical beam of ice in half.\n"
							<<"The Lich attempts to speak another spell but unfortunately all he is able to muster\n"
							<<"is a screech as the sword slices through him, cutting him in two.\n\n"
							<<"Press any key to continue\n\n";
							getch();
							NGPend = true;
							return true;
					}
				}
				else
				{
				
				cout<<"You swing your sword wildly but unfortunately not at the Lich\n"
					<<"Instead of risking freezing you and having the beam deflect\n"
					<<"off the sword, he decides to simply let you tire yourself out.\n\n"
					<<"6 hours later you died from exhaustion after overswinging your arm\n"
					<<"Game Over\n"
					<<"Press any key to door again.";
					getch();
					NGPend= true;
				
				}
			}
		}
		else
		{
			cout<<"I said one chance and you couldn't even input a valid command?\n"
				<<"Do you think this is some kind of joke?\n"
				<<"Well heres a funny joke,\n"
				<<"Game Over\n\n"
				<<"Press any key to door again\n";
				getch();
				NGPend = true;
		}
	}
	while (NGPend==false);
	system("CLS");
	
}





