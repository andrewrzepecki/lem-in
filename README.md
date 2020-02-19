# Lem_in
Third Algo Project @ 42 Paris.

**Project score : [124 / 100]**

Lem-in is an algorithmic project that relies on graph theory to find the shortest paths from one point to another.
Each edge of the graph between two vertices has a maximum flow of one, so we used a variation of Edmund-Karp's algorithm to optimise our results.


## Installation and usage

The program recieves information about number of ants had to be leaded through path, room names with coordinates and links. Here is an example:

<img width="142" alt="screen shot 2017-07-16 at 7 23 13 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28254024-ea2c5eb6-6a5d-11e7-922c-5808975b2419.png" >

Comments "##start" and "##end" are provided to show the start and end room information. We don't care about any other comments.

```
git clone https://github.com/barthelemyleveque/lem_in && cd lem_in && make
./lem-in < maps/[ONE_OF_THE_MAPS]
```

For example, if you execute maps/big, the program output will be :
![lem-in](https://i.ibb.co/7pSmxPM/Screen-Shot-2019-10-28-at-1-20-03-PM.png)

L0 <=> first ant ; L1 <=> second ant ; up to L99 <=> hundredth ant

In the first line you have L0-99 which means the first ant goes to room "99", then L1-806 which means the second ant goes to room "806" etc. 

The rules of lem-in state that there can be only one ant in a room at a time. Which cause superposition problems that were fixed using a custon Edmond-Karps algorithm and graph theory.
