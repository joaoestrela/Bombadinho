# Calculates 
#   1! + 2! + 3! + ... + 7!
# using two while loops

n = 7;
sum = 0; 
i = 1;
while i <= n
  fact = 1;
  j = 1;
  while j <= i
    fact = fact * j; 
    j = j + 1;
  end
  sum = sum + fact;
  disp(fact);
  disp(sum);
  i = i + 1;
end

