///Turns.h
//A header file to fix the ongoing mess that is turning and moving the character

bool turns()
{
	if (wordorder("turn", "left"))
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
	else if ((userinput.find("turn")<userinput.find("right")) && userinput.find("right")<1000)
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