clear; clc; close all

t = linspace(-5, 5, 1000);

u = 0.5*(sign(t) + 1);

figure(1);
plot(t,u);
title("Unit step")