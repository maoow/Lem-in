# Lem-in
program lemin as 42 project.
# __________________________________________________________________


##  Name
    lemin - find the fastest path for x ants to reach a room in a given
    map

##  Synopsys
    ./lemin -[options] < map
  
##  Description
     The lemin program take a number of ants and a map comporting a start
     and an end room, the program will output the fastest way for all the
     ants respecting that rules :
        - excpeting for the first and last room, only one ant can stand in a 
              specific rooom
        - each ant is only able to do one move by turn
        
       
##  Format of the lem-in map
        the first line is the quantity of ants
        room definition should be like : name x y
        room connection : name1-name2
        the first room is defined following the line : ##start
        the last room is defined following the line : ##end


 ###    example of a well formated map:
        25
        ##start
        1 23 3
        2 16 7
        3 16 3
        4 16 5
        5 9 3
        6 1 5
        7 4 8
        ##end
        0 9 5
        0-4
        0-6
        1-3
        4-3
        5-2
        3-5
        4-2
        2-1
        7-6
        7-2
        7-4
        6-5

      
##  Output
    if the map is well formated, the program will output
    the optimals move on the standard output, the 1st ant
    will be identified by the 'L1-newroom', the 2nd by a 'L2-newroom'...
    
###    example:
    ./lem-in < map
    3
    2 5 0
    ##start
    0 1 2
    ##end
    1 9 2
    3 5 4
    0-2
    0-3
    2-1
    3-1
    2-3
    L1-3 L2-2
    L1-1 L2-1 L3-3
    L3-1

                                
