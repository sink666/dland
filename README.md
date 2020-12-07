## dland - digital land
book deal with urbanomic and a cult twitter following in 10 seconds

this writes new sections of Meltdown using a dictionary of all the made up words
in Meltdown. It's pretty accurate to the writing style in terms of general shape
about 80% of the time.

#### instructions
compiled with:
```
    gcc -std=gnu99 -O2 -Os -Wall -Wextra -Werror -pedantic
```

you can get a prettier output using ``fold``:
```
    fold -w 80 -s dland-out.txt > example-output.txt
```

#### future updates?
* make it mimick a real philosopher
* arguments to take input from any file, output to a named file
* make up new words; staple words together with dashes and add K- to things.
