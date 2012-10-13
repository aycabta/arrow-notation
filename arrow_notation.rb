
def arrow(base, exponent, arrows)
  result = nil
  if arrows == 1
    result = 1
    (1..exponent).each do |n|
      result *= base
    end
  else
    temp_exponent = base
    (1..(exponent - 1)).each do
      result = arrow(base, temp_exponent, arrows - 1)
      temp_exponent = result
    end
  end
  result
end

base = 2
arrows = 2
exponent = 5

result = arrow(base, exponent, arrows)

puts "#{result}\n"

digit = 0
while result > 1
  digit += 1
  result /= 10
end

puts "#{digit} digits\n"

