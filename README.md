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

 ###    example of a well formated map:
        ###.
        .#..
        ....
        ....
      
##  Output
    if the source_file is well formated, the program will output
    the optimal disposition on the standard output, the 1st tetrimino
    will be identified by the 'A' letter, the 2nd by a 'B' ...
    
###    example:
    $> cat source_file | cat -e
    ...#$
    ...#$
    ...#$
    ...#$
    $
    ....$
    ....$
    ....$
    ####$
    $
    .###$
    ...#$
    ....$
    ....$
    $
    ....$
    ..##$
    .##.$
    ....$
    $
    ....$
    .##.$
    .##.$
    ....$
    $
    ....$
    ....$
    ##..$
    .##.$
    $
    ##..$
    .#..$
    .#..$
    ....$
    $
    ....$
    ###.$
    .#..$
    ....$
    $> ./fillit source_file | cat -e
    ABBBB.$
    ACCCEE$
    AFFCEE$
    A.FFGG$
    HHHDDG$
    .HDD.G$
    $>
                                
