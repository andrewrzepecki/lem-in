# Lem_in
Third Algo Project @ 42 Paris.

**Project score : [124 / 100]**

Lem-in is an algorithmic project that relies on graph theory to find the shortest path or paths from one point to another.
Each vertex has a maximum capicity of one, so we used a variation of Edmund-Karp's algorithm to optimise our results.


## Installation and usage

```
git clone https://github.com/andrewrzepecki/lem-in && cd lem-in && make
./lem-in < maps/[ONE_OF_THE_MAPS]
```

The program recieves information about number of ants to be passed through the graph, room names with coordinates and links. Here is an example:

<img width="142" alt="screen shot 2017-07-16 at 7 23 13 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28254024-ea2c5eb6-6a5d-11e7-922c-5808975b2419.png" >

Comments "##start" and "##end" are necessary for defining the start and end points of the graph, and must be linked together.

**Example:**

```
./lem-in < maps/big
```
![lem-in](https://i.ibb.co/7pSmxPM/Screen-Shot-2019-10-28-at-1-20-03-PM.png)

[[ant number]-[current vertex]]

Each line of the output corresponds to a step: 
 - The first entry of the first line is [L0-99], meaning that the first ant goes to room "99" and then second [L1-806], the second ant goes to room "806"... 

The rules of lem-in state that there can be only one ant in a room at a time and one can only visit a vertex once, which caused superposition problems that were fixed using a variation of Edmond-Karp's algorithm and graph theory.
