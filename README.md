# Recursed

## Description
'Recursed' is a graphical utility for global pattern replace in text files recursively. Pattern should be defined as regular expression.

## Compilation

1. (Required) Install GTK 3.0, GNU make 4.3+ and Doxygen 1.8.19+

2. Switch to the folder created by 'git clone' and run make

```
$ cd Recursed
$ make
```

Expected results:
- Binary file 'recursed' will be created in target subfolder.
- Documentation created in src/html subfolder

## Usage

1. Run 'recursed' binary

2. Provide values in the form
    Path - path to the file or folder to be processed
    Find - pattern (regular expression) to be replaced
    Replace - string to be used as replacement

3. Press OK button
    Files will be searched recursively starting from 'Path'. 'Find' pattern will be replaced globally in each modified file with 'Replace' string.
    In current version of utility notifications are not supported. GUI will be closed once files processing complete.

## License
[MIT](https://choosealicense.com/licenses/mit/)
