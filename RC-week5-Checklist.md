## Week5 Checklist
### Tips for HW/Lab
- Indent your code and name your variables properly! It can save you from shot by your future colleague.
- **Test your code!** Don't leave it there after finishing coding and hope it works.
- When accessing elements in a matrix, make sure the index is valid.
```matlab
b = [];
b(1:3) = [3,4,5]; % it actually works, but don't use it
```

### File I/O
- what is file?
- `fid` (file descriptor)
- `fid = fopen(filename, permission)`
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
	- stdout, stderr
	- `fprintf(1, 'hello\n')`
	- `fprintf(2, 'hello\n')`
- `[A count] = fscanf(fid, format, size)`
- `[count, errmsg] = fwrite(fid ,A, precision)`
- `A = fread(fid, count, precision)`
- `status = fseek(fid,offset,origin)`
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
- `position = ftell(fid)`

### Text File vs. Binary File

- what is the difference?
- 

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