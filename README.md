# Sudoku-solver
a sudoku solver using brute-force

# How does it works?
The former algorithm:
function solve()

  if no more cells to explore
  
    return true;
    
  for each cell
  
    if this cell is empty
    
      try one choice i;
      
      if  i is a valid choice
      
        return solve()
      
      unmake the choice i;
    
  return false;
  
  Actually, it works, but too slow. I searched on the Internet, and then I realised that my algorithm could be improved:
  instead of this:
  
  for each cell
  
    if this cell is empty
    ...
    
  
  THIS (inspired by this one:https://www.tutorialspoint.com/sudoku-solver-in-cplusplus):
  
    At the first cell available (with function findEmpty() that will modify two variables, x and y, where is the first 0 in the grid)
    
    ...
    
 Resulting algorithm:
 
 function solve()
 
  if no more cells to explore
  
    return true;
  
  At the first 0 in the grid
  
    try one choice i;
    
    if  i is a valid choice
    
      return solve()
    
    unmake the choice i;
  
  return false;

