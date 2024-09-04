clear; clc; close all;

x = -5:0.01:5;

y = signal_sketch(x);

figure(1);
plot(x,y);
title("Original");

y = signal_sketch(x - 1);

figure(2);
plot(x,y);
title("(a)");

y = signal_sketch(2 - x);

figure(3);
plot(x,y);
title("(b)");

y = signal_sketch(2*x + 1);

figure(4);
plot(x,y);
title("(c)");

x = -1:0.01:14;
y = signal_sketch(4 - x/2);

figure(5);
plot(x,y);
title("(d)");

x = 0:0.01:5;
y = signal_sketch(x) + signal_sketch(-x);

figure(6);
plot(x,y);
title("(e)");

function ans = signal_sketch(j)
    for i = 1:length(j)
        if (j(i) < -2)
            ans(i) = 0;
        elseif (j(i) < -1)
            ans(i) = j(i) + 1;
        elseif (j(i) < 0)
            ans(i) = 1;
        elseif (j(i) < 1)
            ans(i) = 2;
        elseif (j(i) < 2)
            ans(i) = -j(i) + 2;
        else
            ans(i) = 0;
        end
    end
end