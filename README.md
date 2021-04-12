# Auto Service
        
## Requirement

### General details (regardless of the chosen theme)

    1.	You can use STL, but for themes that invole data structures using STL for exactly the data 
        structure in the requirement would avoid the purpose of the theme.
        
    2.	Most of the requirements are partial, it is the student's job to decide and apply different 
        OOP concepts to solve the problem.
        
    3.	In the case of a requirement that is unclear, announce it on the group or we can disscuss at lab.
        
    4.	Plus 1p for templates usage.
    
    5.	Plus 1p for the implementation of a design pattern.
    
    6.	Try to use as many OOP techniques learned during this class and to implement everything in a
    	clean and correct manner (copy constructors, = operator, dynamic allocation, no memory leaks, etc...)
    
 ### Theme - Auto Service: 

   There are multiple vehicle categories (bike, motorcycle, car) that can pull up to the service to discover and repair multiple (possible) technical problems. Every type of 
vehicle can have multiple failures such as: brakes, direction, emissions, engine, body panels, etc.. . The possible failures differ in function of the vehicle type. Every failure has a technical solution that involves a certain raw material usage (different types) and a certain human effort (hours/man). Every material has a price as well as the human effort. After the inspection of the vehicle an estimate of the reppair price should be calculated. 
   
### Remarks: 

    1.	Failure types will include at least:
        Brakes - Worn brake pads (front/back - car/motorcycle), worn brake disks (any of the 4 at a car, any of the 2 at a motorcycle),
            blunt chain and/or missing chain (bike);
        Engine - Low oil (car/motorcycle), dirty carburettor (car), melted engine (car/motorcycle);
        Steering - Croocked handlebar (bike/motorcycle), croocked wheel (any), total defection (any); 
        Emissions - The vehicle is burning oil (car/motorcycle), Vehicle is older than 2000 (car/motorcycle)
        Body panels (Only car) - rusted bodywork, crooked bodywork (all body panels with multiple levels of affection.
    
    2.	The solutions involve a material consumption. Every material is to-piece.
        Front brake disks differ from the back ones.	
        Every brake disk is related to it's own wheel.
        Low oil level, melted engine and vehicle burning oil need oil change.

    3.	Every problem has a fix (except total defection)
        There can be common material types between different fixes.
        Every solution uses screws (at least 5).
       
    4.	The vehicle supports damaging operations (e.g. wear right-front brake disk or start burning oil).

    5.	Once connected to the tester (in the service) the vehicle will be checked and a list of problems will be returned to the user.

## Presentation:

 For the showcase example we're going to choose a vehicle from type A (luxury) from the main menu.
    
 <img src="Images/AA-Meniu.PNG">
   
 There are multiple damage operations available: 
    
 <img src="Images/AA-AplicareTraume.PNG">
 
 To score as some operations have a random outcome such as: choosing which brake plate to wear (first option from above picture) or how hard to crook a body part (option 8 from above picture)
 
 For our example we wore brake plates and fron disk brakes (first option from above picture), consumed the oil (second option from above picture). 
 Also the bodykit was damaged by hood corrosion and hitting other body panels (In the 2 images below is presented the bodykit damage menu and submenu). 
        
 <img src="Images/AA-AvariereCaroserie.PNG">
 <img src="Images/AA-AvariereCaroserie2.PNG">
 
 After introducing the vehicle to the tester we obtain the following results:
    
 <img src="Images/AA-RezultateTester.PNG">  
    
 Where we are provided with:
    
    1. Problems detected.
    2. Necessary materials for reparation: every fix require a certain amount of screws and some even require special materials.
    3. Fixing procedures of the vehicle and the time needed to apply them.
    4. Total costs. In this case, for a luxury car the following formula was used: Total = Costs * (2.15) + Work time * (50)
 
 To score: 
   
    Material cost value is calculated based on initial price of every piece multiplied by a wight (specific to the vehicle type).
    Cost of the working hours is calculated based on the applied fixing procedures multiplied by price/h (also specific to the vehicle type).

## Possible improvements:

  1. Adding GUI.
  
  2. Incresing complexity (e.g.):
  
         * The mark and the model of the vehicle to be taken into account. (The parts become afferent to the vehicle e.g: Mercedes AMG GT rear brake disk).
         * Keep a record of the parts in the shop (available or not); -> Involve adding a menu where the usser can add pieces in stock.
         * Adding new problems (and related fixes, e.g: Broken exhaust, broken spark plug, etc...).
     
