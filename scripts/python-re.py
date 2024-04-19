import re

pat = "a*b"
re.search(pat,"fooaaabcde")
re.match(pat,"fooaaabcde")
