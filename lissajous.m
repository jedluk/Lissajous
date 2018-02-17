close all;
clear;
clc;

% time vector
t = linspace(0,20,1000);

% MODELLING TO BELOW EQUATIONS
% x(t) = A cos (w_xt - s_x)
% y(t) = B cos (w_yt - s_y)

iterations = 20;
A = 1;
B = 2;
w_x =  pi;
w_y = pi/2;
s_x = pi/6;
s_y = pi/3;

coefficients = [A w_x s_x B w_y s_y];


for i = 1:iterations
    x = coefficients(1) * cos(coefficients(2).*t - coefficients(3));
    y = coefficients(4) * cos(coefficients(5).*t - coefficients(6));
    coefficients = updateValues(coefficients, 2*rand(1), 5*rand(1));
    figure()
    plot(x,y)
end



function coefficients = updateValues(coefficients, step_x, step_y)
   coefficients(1:3) = coefficients(1:3) * step_x;
   coefficients(4:6) = coefficients(4:6) * step_y;
end
