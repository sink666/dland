## dland - digital land
book deal with urbanomic and a cult twitter following in 10 seconds

This writes new sections of Meltdown using a dictionary of all the made up words
in Meltdown. Strings words together in similar shape and form to the real one.
Randomly, but with disturbing accuracy.

#### instructions
requires libbsd
compiled with:
```
    gcc -std=gnu99 -O2 -Os -Wall -Wextra -Werror -pedantic -lbsd
```

you can get a prettier output using ``fold``:
```
    fold -w 80 -s dland-out.txt > example-output.txt
```

#### future updates?
* make it mimick a real philosopher
* arguments to take input from any file, output to a named file
* spend less time writing a sassy readme
