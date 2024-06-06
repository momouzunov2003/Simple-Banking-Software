
<h1>Simple Banking Software</h1>

A simple banking software, made for the "Introduction to programming" course at the Faculty Of Mathematics And Informatics Sofia University, that uses a file as a database and is able to log and register new users, make deposits into your "bank balance", make withdrawals, make transfer between users of the bank and more.

<h2>Documentation</h2>

Below I've listed all the headers I've made to help me with the project and the functions they're consisted of:

1.PRINT MENUS HEADER

  - printHomeMenu function that prints the starting menu.
	
  - printMainMenu function that prints the main menu after logging in with the user's info.

2.REGISTRATION  AND LOGIN  HEADER

  - Log In functions:
	  - A function that checks wether a given username already exists in the "database".
	
    - A function that checks wether a given password matches the password that the already entered username is linked to.
	
	 - A function that gets the row in the text file where the data for the given user exists.
	
	 - isLoginSuccessful is a boolean function that uses functions 1,2 and 3 to check wether a user has logged in successfuly.

- Registration functions:
  - isRegistrationSuccessful is a boolean function that uses the already created function to check wether the given username and password meet the requirements for the user to get registered into the system.
	


3.VERIFICATIONS HEADER
	
- Registration verification:
  - The bool function isRegisterUsernameCorrect takes a string as a parameter and checks wether the given username is valid and returns wether it is or not valid.
  - The bool function isRegisterPassCorrect takes a string as a parameter and checks wether the given strings is within the given parameters. The functions returns wether that is true or not.
		
- LogIn verification:
  - isValidUsername functions that checks the validity of entered username.
	
  - All needed functions for checking the correctnes of the given parameters are also included in this library.
	
4.FILE FUNCTIONS HEADER

  - fillArraysWithInfo function takes as parameters the name of the file that contains all the information, an array that has to be filled with all the usernames, an array that has to be filled with all the passwords and an array that has to be filled with all the balances.

  - appendToFile function takes as parameters the name of the file that has to be appended to, the username, password and ballance that have to be added to the file.

  - getFileLength function.

  - deleteLineFromFile function deletes a particular "user" from the file, containing the information.

  - rewriteBalance function changes the value of the "balance" in a particular line from the file, containing the information.

5.BANKING FUNCTIONS HEADER:

- cancelAccount function that deletes a user from the "database" if his balance is 0.

- depositSuccessful function that checks wether a deposit in the user's profile is possible, and if it is, does it.

- transferSuccessful function that checks wether a transfer from one user's account to another user's is possible, and if it is, does it.

- withdrawalSuccessful function that checks wether a withdrawal is possible, and if so, does it.

6.MAIN FILE:

- The main file contains all the logic behind the successful execution of the whole program.

P.S. I know there's a lot of C style goto in the main function but at that point of time and skill I thought it was very convenient :D