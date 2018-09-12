i = 10;
while 1
    i = i - 1;
    if i == 8 || i == 7
        continue;
    end
    if i < 3
        break;
    end
    disp(i);
end