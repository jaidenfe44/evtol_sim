# Electric Vertical Takeoff and Landing (eVTOL) Simulation

## Build and Run

A `build.sh` script is supplied in the top most directory. To build and execute the simulator, run `./build.sh -t sim`. This builds the simulator and runs the simulator executable. The simulator executable is stored at `build/sim`. To run the test suite, run `./build.sh -t test`. Similarly, this builds and runs the test suite executable. The test suite executable is stored at `build/test`. In addition, to access the help menu, simply add the `-h` flag.

## Objective

Show us your awesome skills! We want to see your design, coding, documentation, testing, and communication abilties first hand!

## Details

This work must be coded in C++, and submitted through GitHub, BitBucket, or Gitlab. Upload the documented code to your personal account and send us a link. We may look at the git history to see how you use version control.

Please exercise the basic tenets of OOP, using relevant principles where appropriate. We’re looking for robust, testable, modular, and well-documented code.

Unit Testing is a big part of our development process. Please include just a few examples of unit tests or how your code is testable. Tests don't necessarily need to run in any test framework, but please be ready to talk about what and how you tested your code.  To dos and notes are OK. If you want to incorporate an idea that makes sense in a real project, but would take too much time to implement, just leave a note. For example: 

```
// Todo: Refactor database to use hashmap rather than raw array for
// <xyz> reasons.. 
```

## Problem Statement

There are five companies developing eVTOL aircraft. The vehicle produced by each manufacturer has different characteristics. Six distinct properties are laid out in the below table:

| Company Name    | Cruise Speed (mph) | Battery Capacity (kWh) | Time to Charge (hours) | Energy use at Cruise (kWh/mile) | Passenger Count | Probability of fault per hour |
|-----------------|--------------------|------------------------|------------------------|---------------------------------|-----------------|-------------------------------|
| Alpha Company   |                120 |                    320 |                   0.6  |                             1.6 |               4 |                          0.25 |
| Bravo Company   |                100 |                    100 |                   0.2  |                             1.5 |               5 |                          0.10 |
| Charlie Company |                160 |                    220 |                   0.8  |                             2.2 |               3 |                          0.05 |
| Delta Company   |                 90 |                    120 |                   0.62 |                             0.8 |               2 |                          0.22 |
| Echo Company    |                 30 |                    150 |                   0.3  |                             5.8 |               2 |                          0.61 |



You will simulate using these vehicle for 3 hours. Of course your simulation should take much less time than that. 20 total vehicles should be deployed, and a random number of each type of vehicle should be used (with the total between all five types being 20).

There are only three chargers available for all 20 vehicles! A single charger can only be used by one vehicle at a time. Assume the chargers can charge the batteries in the Time to Charge time listed for each vehicle. 

## Statistics (Per Vehicle Type):
  - Average flight time per flight
   - Average distance traveled per flight
  - Average time charging per charge session
  -  Total number of faults
  - Total number of passenger miles
      - i.e. if there are 2 vehicles carrying 4 passengers on a vehicle that cruises for 1 hour at 100 mph, the total number of passenger miles is 2 * 4 * 1 * 100 = 800

## Assumptions:
- Each vehicle starts the simulation with a fully-charged battery
-  Each vehicle instantaneously reaches Cruise Speed
- Each vehicle is airborne for the full use of the battery, and is immediately in line for the charger after running out of battery power

Please include the statistics recorded during at least one run of the simulation in your submission.

<br><br>

# Design Scratchpad

This section is used as a scratch pad space for notes and design considerations to describe my though process when approaching the exercise.

## Main Loop Design

The sim main loop will be in charge of system count and stepping through the simulator. The `system count` represents seconds the simulation is running. In this approach the sim runtime is `10800 seconds (3 hours)`. The main.cpp file implements the system runtime loop (in seconds) and calls the `Port::step()` function for every simulation second.

The following is a flow diagram representing the design of the simulation main loop.

![eVtol_sim_main_flow_diagram](https://github.com/user-attachments/assets/ac0cfc8c-c012-4701-b366-e71c4d729ae7)


## Port Design

TODO


## Charger Design

TODO


## eVTOL Vehicle Design

TODO


---

# Execution Results

TODO


# Test Suite Results

TODO
