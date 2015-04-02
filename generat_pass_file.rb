#!/usr/bin/ruby
file = 'passwords.txt'

i = 0
stop = 10000

while i < stop do
  out = ''
  if i < 10
    out = '000' + i.to_s
  elsif i < 100
    out = '00' + i.to_s
  elsif i < 1000
    out = '0' + i.to_s
  else
    out = i.to_s
  end

  open(file, 'a'){ |f|
    f.puts out
  }
  i = i + 1
end
