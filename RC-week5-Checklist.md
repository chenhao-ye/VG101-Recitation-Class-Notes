## Week5 Checklist
### Tips for HW/Lab
- Indent your code and name your variables properly! It can save you from shot by your future colleague.
- **Test your code!** Don't leave it there after finishing coding and hope it works.
- When accessing elements in a matrix, make sure the index is valid.
```matlab
b = [];
b(1:3) = [3,4,5]; % it actually works, but don't use it
```


### String





### File I/O
- what is file?
- `fid` (file descriptor)
- `fid = fopen(filename, permission)`
	- where the file will be read/written
	- permission:

| Permission | Explanation |
| :----------: | ------------- |
| 'r' | Open file for reading. |
| 'w' | Open or create new file for writing. Discard existing contents, if any. |
| 'a' | Open or create new file for writing. Append data to the end of the file. |
| 'r+' | Open file for reading and writing. |
| 'w+' | Open or create new file for reading and writing. Discard existing contents, if any. |
| 'a+' | Open or create new file for reading and writing. Append data to the end of the file. |

- `fclose(fid)`
- `fprintf(fid, format, A, ...)`
	- `stdout`, `stderr`
	- `fprintf(1, 'hello\n')`
	- `fprintf(2, 'hello\n')`
	- Formatting Operator: A formatting operator starts with a percent sign, %, and ends with a conversion character. The conversion character is required. Optionally, you can specify identifier, flags, field width, precision, and subtype operators between % and the conversion character. (Spaces are invalid between operators and are shown here only for readability).

	![](./pic/string_format.png)

	- Identifier, Flags, Subtype (skip)
	- Field Width: Minimum number of characters to print. The field width operator can be a number, or an asterisk (\*) to refer to an input argument.
	- Precision: 
		- For `%f`, `%e`, or `%E` : Number of digits to the right of the decimal point. Example: `'%.4f'` prints pi as `'3.1416'`
		- For `%g` or `%G` : Number of significant digits. Example: `'%.4g'` prints pi as `'3.142'`
	- Conversion Character

| Conversion | Details |
| :--------: | ------- |
| %d or %i | Base 10 |
| %u | Base 10 |
| %o | Base 8 (octal) |
| %x | Base 16 (hexadecimal), lowercase letters a–f |
| %X | Same as %x, uppercase letters A–F |
| %f | Fixed-point notation (Use a precision operator to specify the number of digits after the decimal point.) |
| %e | Exponential notation, such as 3.141593e+00 (Use a precision operator to specify the number of digits after the decimal point.) |
| %E | Same as %e, but uppercase, such as 3.141593E+00 (Use a precision operator to specify the number of digits after the decimal point.) |
| %g | The more compact of %e or %f, with no trailing zeros (Use a precision operator to specify the number of significant digits.) |
| %G | The more compact of %E or %f, with no trailing zeros (Use a precision operator to specify the number of significant digits.) |
| %c | Single character |
| %s | Character vector or string array. The type of the output text is the same as the type of `format`.|

Reference: https://www.mathworks.com/help/releases/R2018a/matlab/ref/fprintf.html

- `[A count] = fscanf(fid, format, sizeA)`
- `[A count] = fscanf(fid, format)`
	- Reads data from an open text file into *column vector* `A` (with dimensions `sizeA`) and interprets values in the file according to the format specified by `format`. The `fscanf` function reapplies the format throughout the entire file and positions the file pointer at the end-of-file marker (or `sizeA` is reached).
	- If `fscanf` cannot match `format` to the data, it reads only the portion that matches and stops processing.

Numeric Field：

| Conversion Specifier | Details |
| :------------------: | ------- |
| %d | Base 10 |
| %i | (Too complicated. Please refer to the document page) |
| %ld or %li | 64-bit values, base 10, 8, or 16 | 
| %u | Base 10 |
| %o | Base 8 (octal) | 
| %x | Base 16 (hexadecimal) |
| %lu, %lo, %lx | 64-bit values, base 10, 8, or 16 |
| %f, %e, %g | Floating-point fields can contain any of the following (not case sensitive): Inf, -Inf, NaN, or -NaN. |

Character Fields:

| Conversion Specifier | Details |
| :------------------: | ------- |
| %s | Read all characters *excluding white spaces*. |
| %c | Read any single character, including white space. To read multiple characters at a time, specify field width. |

Reference: https://www.mathworks.com/help/releases/R2018a/matlab/ref/fscanf.html

```matlab
x = 1:1:5;
y = [x;rand(1,5)];
fileID = fopen('nums2.txt','w');
fprintf(fileID,'%d %4.4f\n',y);
fclose(fileID);
% 1 0.8147
% 2 0.9058
% 3 0.1270
% 4 0.9134
% 5 0.6324

fileID = fopen('nums2.txt','r');
formatSpec = '%d %f';
sizeA = [2 Inf];
A = fscanf(fileID,formatSpec,sizeA)
%A = 2×5
%
%    1.0000    2.0000    3.0000    4.0000    5.0000
%    0.8147    0.9058    0.1270    0.9134    0.6324
fclose(fileID);
```

- Difference between *Text File* and *Binary File*.
- `[count, errmsg] = fwrite(fid ,A, precision)`
- `A = fread(fid, count, precision)`
	- Notice that, these two are for binary file.
	- Read with the same format that you write
	- If another format wanted, read in the format as written and then do transfer

```matlab
fid = fopen('alphabet.txt', 'r');
c = fread(fid, 5)
fclose(fid);
% c = [65; 66; 67; 68; 69]

fid = fopen('alphabet.txt', 'r');
d = fread(fid, 5, 'uint8=>char')'
fclose(fid);
% d = 'ABCDE'
```
- `status = fseek(fid,offset,origin)`
- `position = ftell(fid)`

```matlab
A = 1:5; 
fid = fopen('five.bin','w'); 
fwrite(fid, A,'short'); 
status = fclose(fid);

% Read the third number:
fid = fopen('five.bin','r'); 
fseek(fid, 4,'bof'); % why 4?
a = fread(fid,1,'short'); % a == 3
% Instead:
% fseek(fid, 3,'bof');
% a = fread(fid, 1,'short');
% a == 768. Why?

ftell(fid) % ans == 6

% read the second number
fseek(fid,-4,'cof'); % why -4?
a = fread(fid,1,'short');

fclose(fid);
```

- `fgetl(fid)`: read lines
- `feof(fid)`

```matlab
% In fgetl_demo.m:
fid = fopen('fgetl_demo.m', 'r');
n = 0;
while feof(fid) == 0
	tline = fgetl(fid);
	n = n+1;
	disp(sprintf('%d:%s',n,tline));
end
fclose(fid);
% 1:clc
% 2:clear
% 3:fid = fopen('fgetl_demo.m', 'r');
% 4:n = 0;
% 5:while feof(fid) == 0
% 6:tline = fgetl(fid);
% 7:n = n+1;
% 8:fprintf('%d:%s\n',n,tline);
% 9:end
% 10:fclose(fid);
```


### Use file I/O and string manipulation to extract information from a file

### Newline
- Windows: `\r\n`
- Mac OS X, Linux: `\n`
- When in MATLAB, it will be decided by MATLAB setting, so `\n` should be fine


## What should I do when my code doesn’t work?
- Pray. The God will help me to make it work.
- Stare at the code. It will fear me and fix itself.
- Send an email to TA saying that “Oh TA, my code doesn’t work.”
- Look through the code to find what is wrong.
- Rubber Duck Debugging.
- Use debugger (breakpoint).