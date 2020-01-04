# TuffyTravel-Complete
Final version of TuffyTravel program C++
_________________________________________________________

TuffyTravel Project Guide
CPSC 121
Fall 2019
(Rev. 1-20190809)

Learning objectives
Design and implement software that makes appropriate use of fundamental programming constructs and data structures (e.g., expressions, conditions, loops, functions, primitive data types, arrays).
Design and implement software that makes appropriate use of object-oriented concepts (e.g., classes, objects, methods, composition, inheritance, abstract classes, polymorphism).
Design and implement software that makes appropriate use of advanced programming concepts (e.g., recursion, pointers, memory allocation, STL, file input/output, exception handling).
Demonstrate proper use of encapsulation and decoupling.
Demonstrate proper use of coding standards.
Write appropriate inline comments to help other developers understand and reuse code.
Demonstrate the ability to utilize IDEs to optimize software development.
Project specifications
The goal of this project is to develop a travel planning application. Users will use a menu-based command-line interface to interact with the software. Its major features are the creation of travel routes, adding routes to a travel schedule, and saving and loading routes into text files. 

The software should be designed using the object-oriented programming paradigm so that the code can easily be modified, extended, and scaled by other developers. It is equally important to provide sufficient internal documentation to help other developers understand the code and encourage them to contribute to its development.

The software will be delivered in incremental versions or milestones over the course of the semester. Descriptions of the eight milestones are presented below, but technical details will be provided in your GitHub repositories for each milestone. The deadlines listed for each milestone may change depending on the class’ progress. In such cases, I will announce changes in class and/or through Piazza.
Grading
Each milestone will be graded separately using the same lab exercise checking stages, but with an additional reflection component. Your final project grade is the average of all your milestone grades.

Stage 1. Compilation (5%) will be assessed by checking whether your code compiles correctly assuming you put in sufficient effort in solving the problem. Minimal code or code that does not attempt to solve the problem will not get a compilation grade.

Stage 2. Functionality (40%) will be assessed by checking how much of the unit tests defined for the problem were passed by your solution. Unlike lab exercises, you will only have access to some test cases via the unit tests. You will need to think of other test cases and make sure that your program addresses them properly. My graders and I will use an instructor’s set of unit tests that we expect your programs to pass.

Stage 3. Design (40%) will be assessed by checking whether your code uses the appropriate constructs for solving the problem. Code that runs correctly does not guarantee a high grade. An example of bad code design is using a brute force approach like manually printing out every number from one to 100 instead of using a loop.

Stage 4. Readability (10%) will be assessed by checking whether your code passess the style and format check, as well as how well it follows the proper naming conventions, and provides sufficient internal documentation for complex code. Documentation is often an art, but Google’s style guide is a good starting point (https://google.github.io/styleguide/cppguide.html). Coding styles will be discussed in class and shown in our code samples.
Reflection (5%) will be assessed by checking whether you appropriately accomplished the reflection form. The form will ask you to provide information about your submission such as a description of your program, the test cases that you identified, and a discussion about the issues you encountered while developing your program.


Milestone 1
Deadline: September 20, 11:59 pm

Create a program that asks the user to input three bus departure times. The system should also ask the user to provide the name of the route to make it easy to distinguish. It should also ask the passenger what time they want to leave. Use conditions to identify the bus route that the passenger should take if they want to leave by the time they specified.


Milestone 2
Deadline: October 11, 11:59 pm

Design and implement a Route object that will store the name of the route, its departure time and its arrival time. For example, the 57 Brea Mall - State College-Nutwood route has a departure time of 9:45am and arrival time of 9:56am. Create a display member function that will print on screen the name of the route, its departure time and arrival time.

Create a function called create_route that asks the user to provide the name of the route, the departure time, and the arrival time. Use the information provided by the user to create a Route object and return it.

Modify your Milestone 1 program so that it calls the create_route function to instantiate three Route objects. Use the accessors and mutators of each Route object to figure out which one will allow the passenger to leave by the time they specified. Call the selected Routes object’s display member function to show the information on screen.

The code should be organized so that class and function prototypes are placed in header files (.hpp) while their implementations are placed in source files (.cpp)


Milestone 3
Deadline: October 21, 11:59 pm

Create a menu-based interface that allows the user to add routes, display all routes, and exit the program. Specifically, the user presses either R to create routes, D to display the routes, or X to exit.

Create an array of Route objects in the main function. Whenever the user adds a route, call the create_route function to instantiate a Route object and store it on the first available space in the array.

Create a display_routes function that accepts the array and its size as a parameter, then displays information about each Route object in the array. Take note that you can also call each Route object’s display function instead of its accessor and mutator functions. The display_routes function should be called whenever the user asks to display routes.


Milestone 4
Deadline: November 4, 11:59 pm

Update the menu to allow the user to find the route they should take given their time to leave. Specifically, F to find a route.

Create a find_route function that accepts the Route object array, its size, and the time to leave. The function should return the appropriate Route object whose departure time is closest to the user’s time to leave. The route’s departure time should only be equal to or after the passenger’s given time.

When F is selected on the menu, it should ask the user to provide their time to leave and call the find_route function with the appropriate parameter values.


Milestone 5
Deadline: November 22, 11:59 pm

Update the menu-based interface to also allow the user to save and load routes. Specifically, S to save all added routes and L to load a route file.

Create a save_routes function that accepts the array, its size, and a file name. The function should save each element of the array into a file named according to the file name parameter.

Create a load_routes function that accepts tha array, a size reference, and a file name. The function should open the appropriate file using the file name parameter and update the size reference according to the data in the file. Take note that the reference is linked to the size variable in the main function that tracks the total number of Route objects in the array. Instantiate the appropriate Route objects based on the file and store them in the given array.

The save_routes and load_routes functions should be called with the appropriate parameter values when the user requests to save or load the routes through the menu. Make sure that the functionality for adding and displaying bus routes continue to work for this Milestone.


Milestone 6
Deadline: December 6, 11:59 pm

Refactor your code so that it uses an object-oriented design. Refactor is a term that refers to restructuring existing code so that it follows a different design but retains the initial code’s behavior. Specifically, you need to create a RouteManager object that will contain all the Route objects added by the user. The functions created from previous Milestones will be refactored into member functions in the appropriate classes. As a result, codes that call the refactored functions will now use the RouteManager and Route objects’ member functions.

Specifically, the RouteManager object should now contain the array of Route objects and the variable that keeps track of the number of objects in the array. It should also now contain the refactored create_route, add_route, display_routes, find_routes, save_routes, and load_routes member functions. Take note that these member functions should use the class’ member variables instead of requiring parameters.

The menu should be updated to use objects and call their appropriate member functions.


Milestone 7
Deadline: December 19, 11:59 pm

Add a new route type called CheckedRoute. In addition to information stored in a Route object, this new route type also keeps track of the number of hours the passenger needs to arrive before the departure time. In airlines for example, users would need to arrive at least an hour before a domestic flight and three hours before an international flight. A possible CheckedRoute object might be a Delta flight from LAX - ATL whose time for take off is 6:35am, arrival time is 11:01am, and passengers are required to arrive 1 hour before the flight. 

Create a create_checked_route member function in the RouteManager class that asks the user to provide all necessary values and return a CheckedRoute object using those values.

Apply inheritance and polymorphism so that Route and CheckedRoute objects can be stored in the same array inside the RouteManager. The other functionalities such as adding, displaying, finding, saving, and loading routes should still work as expected.

Update the menu to create a checked route when the user presses C. Call the create_checked_route function and pass all necessary parameter values.


Milestone 8 (Extra credit)
Deadline: December 19, 11:59 pm

Create another Route type called ConnectionRoute. It is a special type of Route that stores the name of a source route and destination route that are names of other routes. Take for example the case when the user needs to walk after they take a bus to the airport. A ConnectionRoute might require the passenger to walk from the source route, LAX Terminal 1 stop, to the destination route, the LAX airport, that departs at 12:33pm and arrives at 12:34pm.

Create a create_connection_route member function in the RouteManager class that asks the user to provide all necessary values and return a ConnectionRoute object using those values.

Apply inheritance and polymorphism so that Route, CheckedRoute, and ConnectionRoute objects can be stored in the same array inside the RouteManager. The other functionalities such as adding, displaying, finding, saving, and loading routes should still work as expected.

Update the menu to create a connection route when the user presses T. Call the create_connection_route function and pass all necessary parameter values.
