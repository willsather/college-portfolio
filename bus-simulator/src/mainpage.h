/**
 * @file mainpage.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! \mainpage Project Documentation
 *
 * \section intro_sec Introduction
 *
 * The Transit Simulation Project is an online simulator replicating the University of Minnesota’s transit system.
 * This uses a combination of C++, Javascript, and a variety of other languages to produce a working
 * front and backend simulation. Below are the easy steps to download and compile said project.
 *
 * To first obtain the project, one must either download the compressed package or clone the GitHub so you have a
 * local copy of the program. Once you have obtained the program, one can use this is a step by step
 * instruction to running and compiling the Transit Simulation Project.
 *
 *   1. The first step to run and compile the Transit Simulation Project is to navigate to
 *     the /project/src directory and using the terminal, run make.
 *
 *   2. Secondly, navigating to just the /project directory, ./build/bin/vis_sim <port_number>
 *   where the port number is a number above 8000, along with the number including at least
 *   3 digits of a UMN x500.
 *
 *   3. The final step is the go into a Google Chrome browser and navigate to
 *    http://127.0.0.1:<port_number>/web_graphics/project.html and start the simulation
 *    using the buttons.
 *
 * After following these steps, you can view the simulation on Google Chrome and view/manipulate the simulation.
 *
 * \image html ../image/Simulation.png "Bus Simulation Visualization" width=1000px 
 *
 * \section factory Concrete vs. Abstract
 *
 * One implementation difference worth discussing is the possibilities of bus_factory either being
 * a concrete factory or an abstract factory.  To back up, using a factory allows the project to streamline
 * the creation of an object. This allows the implementation and creation of memory to be hidden to a user.
 * It also allows for different ways of creating a bus or deploying a bus while not changing how you create a bus,
 * but only the parameters passed into the factory. This allows for “Open to extension, closed to change” which
 * goes to show my points earlier. For Iteration 1, a pro for implementing a concrete factory is the sheer simplicity.
 * The fact of the matter is, it is just easier to implement a concrete factory.  However, a reason not to do this is
 * that is becomes more difficult to enact change in the future.  Whether it is changes to the Bus classes or visualization
 * simulator, it isn't as malleable to change. On the contrary, an abstract class would have been able to provide the adaptability
 * that a concrete class could not.  However, an abstract class is more difficult and tedious to build on the front-end.  This
 * decision will ultimately have to come down to the cost in the short-term vs long-term and what is more valuable for your specific
 * project and the amount of changes you expect to see in the future.
 *
 * For this project, I have chosen a concrete class to simplify my first iteration.  It is present in both bus_factory.h
 * and bus_factory.cc
 *
 *
 * \section observer Designing and Implementing the Observer Pattern 
 *
 * One of the big priorities for iteration 2 is designing and implementing the observer pattern.  For a simple description,
 * the observer pattern is the white side bar on the visualization which, once a bus is clicked, provides said bus's information
 * like how many passengers are onboard, or what the longitude/latitude are.  This is useful for an individual watching the simulation.
 * Very briefly, this pattern is implemented using two basic elements: 1. The Observer interface  2.  The Subject interface along with
 * a handful of other functions.  Essentially, the observer interface is a top level implementation used to represent the viewer (in this
 * case, our Bus Web Observer).  On the other hand, the subject interface (called our IObservable) is used to represent the object being
 * which is being viewed (in this scenario, a bus object).  Some other functions that have been implemented assist visual simulator
 * add listener objects and remove them, along with functions to clear the vector that holds the observers.  All in all, this observer
 * pattern is a great tool to view and utilize the simulation, and allows for greater clarity of information about busses.
 *
 *
 *
 * \image html ../image/Observer_Pattern.jpeg "Observer Pattern" width=1000px 
 *
 *
 *
 *
 * \section bus_depot Designing and Implementing the Bus depot
 *
 * The third and final priority for iteration 2 was designing and implementing the bus depot.  To simplify the bus depot's
 * new features, this simulates three strategies for deploying bussees.  Instead of deciding using a random number generated,
 * the bus factory is implemented using C++'s standard time library.  This is used to deploys different strategies depending on
 * the time of day.  For example, between 6AM and 8AM, it switches between Small and Regular busses being deployed.  To see a description
 * of each strategy, refer to the bus_factory.cc class for more documentation.
 *
 *
 *
 * \section bus_depot Designing and Implementing the Decorator Pattern
 *
 * In the last iteration, iteration 3, we were askd to design and implement a decorator pattern that styles the bus icons.  This
 * allows for busses to be customized using any number of parameters, allowing for the highest level of customization.  For example,
 * this iteration required us to style the busses gold/yellow for outbound busses and maroon for inbound busses.  Priority 5 also
 * stipulates the insenity (or gradient) of color should be determined by the total number of passengers on the bus.  This was accomplished
 * using a decorator pattern, not just a hierarchy of class dependencies.  This means it follows the design methodologies discussed in
 * class.  This current class organization allows for an easy way to change the parameters for the opacity of the bus, also called
 * "Open To Extension".  Although this class organization was difficult up front to get implemented, it is worth the cost to be able
 * to have such an easy way to change in the future.
 *
 * \section conclusion Conclusion
 * This is a quick overview on how to navigate to the project, along with compiling and being able to use it.
 * The most difficult aspect of this project is understanding how the different objects and classes are utilizing each other,
 * along with utilizing different data structs and the web side. The raw C++ isn’t too unwieldy; however,
 * the visual aspects of producing an HTML page with the ports can be quite confusing.   Since finishing iteration 1, I feel considerably
 * more comfortable with the visualization aspects of the code along with the general layout.  I believe I have a better understanding
 * of the command pattern layout and how the JSON is sending information through the socket.  I think something that still confuses me
 * that I will need to learn better for iteration 3 is general use of templates.  Although I haven't implemented any templates in iteration 2,
 * I know that I will be soon enough.  I look forward to further improving this product as well as continuing my learning, but for now, I am
 * proud of the work I have accomplished so far.
 */

#endif  // SRC_MAINPAGE_H_
