List of requirements and where to find them:

1.) Header files, abstract classes, subclasses, virtual functions, and inheritance can all be found within the Character class and the classes that extend from it.

2.) Pointers and polymorphism can be found in the functions that characters use to interact with each other (each one must take a pointer or reference to a Character or a class derived from it).

3.) Overloaded Operator++: Basically levels up a character (though at the moment, I'm not keeping track of levels) by randomly increasing stats. Right now, it's used in the Monster class, as the special ability of Monsters. 
When they attack a dead party member, they heal and grow stronger by feasting on the corpse. 

4.) Overloaded << Operator: In the Character class. Prints a character to output. Pretty standard stuff.

5.) Static Member Variable and Function: The Character Class keeps track of the number of instances and there's a getter for that. I had a really cool idea that didn't pan out, unfortunately. :(
If you're bored and curious, I left the Skill class included in the source folder, though it wasn't used in the project.

6.) File I/O: There's a brief little story intro that is read in from a file to the program. Had wanted to write more to that, but then I'd have to plan it out more.
Additionally, at the end of the demo, since characters and monsters are randomly generated, it prints to a file that keeps track of your wins/losses and prints character stats. 

7.) Exceptions: I didn't really end up getting to use any (as I mentioned to you earlier, the one part I really could have used them for an exception I can't actually catch or handle properly),
so I did throw one into the Encounter function. To be honest, I'm still not really in the habit of using exceptions. 

8.) Templates: I use one to delete each pointer in the vector before clearing the vector itself. 

9.) Coolness: ALLLLLLL OVER THE PLACE. I know there's points for that *wink wink.*

BONUS POINTS:

Recursion: Can be found in the Rogue class, via the MultiStrike function. It takes, as arguments, a pointer to an enemy to attack, and a default argument for a random number of attacks (between 2-5). 
It then calls the Attack function (with a damage reduction applied), followed by calling itself with numhits - 1. The function stops either when you've done x amount of attacks, or when the enemy has died.

Friend Function (In progress): The Group Attack function takes an enemy as an argument, along with a vector to the team that the character using it is a part of. 
What it does, for the sake of simplicity, is take the number of party members and use it as the damage factor. This effectively increases damage by x party members. 
However, as a drawback, each member who participates in the attack loses their next turn. (Actually, turns out I don't really need this right now since I'm passing around so many pointers and I have appropriate setters.)
