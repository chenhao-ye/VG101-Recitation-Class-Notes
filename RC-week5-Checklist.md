## Week5 Checklist
### File I/O
- what is file?
- `fid`
- `fid = fopen(filename, permission);`
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
- What's the difference?

### Newline
- Windows: `\r\n`
- Mac OS X, Linux: `\n`

### Rubber Duck Debugging