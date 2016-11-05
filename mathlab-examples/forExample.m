# Calculates 
#   5! = 5 x 4 x 3 x 2 x 1 = 120
# using a for loop

n = 5;
fact = 1; 

for i=1:n
  fact = fact * i;
end

disp(fact);
