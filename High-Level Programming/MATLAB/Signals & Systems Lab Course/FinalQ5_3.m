clear all;
wn=10;
t=0:0.01:5;

zt=1/4; % Damping factor

% b and a are the coefficients of the Laplace variable s of the transfer function
b=wn^2; % The coefficient of s^0 in the numerator of the transfer function
a=[1 2*zt*wn wn^2]; % The coefficients of s^2, s^1, and s^0 in the denominator of the transfer function - there is a single empty space between each coefficient
% Notice that the coefficients are defined in descending order; meaning that the coefficient of highest power s will go first
H=tf(b,a); % tf creates a transfer function model based on the numerator and denominator coefficients
hs=step(H,t); % hs means h simulation, with h being the impulse response

figure(2);
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t, hs, 'Color', 'magenta', 'linewidth', 2);
title(tLayout, 'The step response s(t) for different values of the damping factor ζ');
grid on;
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 2
zt=0; % New value for the damping factor

b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=step(H,t);

figure(2); 
plot(t, hs, 'Color', 'green', 'linewidth', 2)
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 3
zt=1; % New value for the damping factor

b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=step(H,t);

figure(2); 
plot(t, hs, 'Color', 'red', 'linewidth', 2)
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 4
zt=3; % New value for the damping factor

b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=step(H,t);

figure(2);
plot(t, hs, 'Color', 'blue', 'linewidth', 2)
xlabel('Time t');
ylabel('Step Response s(t)');
legend('s(t) when ζ = 1/4', 's(t) when ζ = 0', 's(t) when ζ = 1', 's(t) when ζ = 3');
hold off;