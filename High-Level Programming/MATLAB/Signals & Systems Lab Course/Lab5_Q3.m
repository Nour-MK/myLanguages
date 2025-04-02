% Step response s(t) of a 2nd order system using a theoretically derived formula and using MATLAB's impulse function for different values of the damping factor

clear all;
wn=1;
t=0:0.01:30;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 1 - Will be heavily commentated to explain the steps and the rest of the cases will be just the same process repeated so they will have minimal comments 
zt=0.5; % Damping factor

% Theoretical step response formula for 0<ζ<1
st= 1 - ((zt/sqrt(1-zt^2))*exp(-zt*wn*t).*sin(wn*sqrt(1-zt^2)*t)) - (exp(-zt*wn*t).*cos(wn*sqrt(1-zt^2)*t)); % st means s theory, with s being the step response

% MATLAB step response calculation
% b and a are the coefficients of the Laplace variable s of the transfer function
b=wn^2; % The coefficient of s^0 in the numerator of the transfer function
a=[1 2*zt*wn wn^2]; % The coefficients of s^2, s^1, and s^0 in the denominator of the transfer function - there is a single empty space between each coefficient
% Notice that the coefficients are defined in descending order; meaning that the coefficient of highest power s will go first
H=tf(b,a); % tf creates a transfer function model based on the numerator and denominator coefficients
ss=step(H,t); % ss means s simulation, with s being the step response

figure(1); % Plotting the obtained step response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
tLayout = tiledlayout(3, 3, 'Padding', 'none', 'TileSpacing', 'compact'); % Create a 3x3 tile layout
nexttile;
plot(t, st, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey step response with respect to time
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation step response with respect to time
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = 0.5');
title(tLayout, 'The step response s(t) for different values of the damping factor ζ');
hold off;

figure(2); % Plotting the MATLAB-obtained step responses to all the different damping factors on one plot 
% (Only using MATLAB since we already verified the validity of both methods in figure 1)
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t, ss, 'Color', 'cyan', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
title(tLayout, 'The step response s(t) for different values of the damping factor ζ');
xlabel('Time t');
ylabel('Step Response s(t)');
grid on;
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 2
zt=2; % New value for the damping factor

% Theoretical step response formula for 1<ζ
st = 1 - exp(-zt*wn*t).*cosh(wn*sqrt(zt^2 - 1)*t) - ((zt)/(sqrt(zt^2-1))).*exp(-zt*wn*t).*sinh(wn*sqrt(zt^2-1)*t) ;

% MATLAB step response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
ss=step(H,t);

figure(1);
nexttile;
plot(t, st, 'Color', '#0069b9', 'linewidth', 2);
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2);
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = 2');
hold off;

figure(2); 
plot(t, ss, 'Color', 'green', 'linewidth', 2)
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 3
zt=0; % New value for the damping factor

% Theoretical step response formula for ζ=0
st = 1 - cos(wn*t); 

% MATLAB step response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
ss=step(H,t);

figure(1);
nexttile;
plot(t, st, 'Color', '#0069b9', 'linewidth', 2);
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2);
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = 0');
hold off;

figure(2);
plot(t, ss, 'Color', 'red', 'linewidth', 2)
hold on;
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 4
zt=0.2; % New value for the damping factor

% Theoretical step response formula for 0<ζ<1
st= 1 - ((zt/sqrt(1-zt^2))*exp(-zt*wn*t).*sin(wn*sqrt(1-zt^2)*t)) - (exp(-zt*wn*t).*cos(wn*sqrt(1-zt^2)*t));

% MATLAB step response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
ss=step(H,t);

figure(1); 
nexttile;
plot(t, st, 'Color', '#0069b9', 'linewidth', 2);
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2);
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = 0.2');
hold off;

figure(2);
plot(t, ss, 'Color', 'blue', 'linewidth', 2)
hold on;
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 5
zt=1; % New value for the damping factor

% Theoretical step response formula for ζ=1
st = 1 - exp(-wn.*t) - wn.*t.*exp(-wn.*t);

% MATLAB step response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
ss=step(H,t);

figure(1);
nexttile;
plot(t, st, 'Color', '#0069b9', 'linewidth', 2);
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2);
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = 1');
hold off;

figure(2);
plot(t, ss, 'Color', 'magenta', 'linewidth', 2);
legend('MATLAB-obtained s(t) when ζ = 0.5', 'MATLAB-obtained s(t) when ζ = 2','MATLAB-obtained s(t) when ζ = 0','MATLAB-obtained s(t) when ζ = 0.2','MATLAB-obtained s(t) when ζ = 1');
hold off;
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 6
zt=-0.2; % New value for the damping factor
% Note that The damping ratio ζ cannot be less than zero; it is typically in the range of 0 to 1 for underdamped systems, exactly 1 for critically damped systems, and greater than 1 for overdamped systems.
% So, this will actually result in the same behavior as just zt = 0.2 but inversed in time and a lot stretched in amplitude

% Theoretical step response formula for 0<ζ<1
st= 1 - ((zt/sqrt(1-zt^2))*exp(-zt*wn*t).*sin(wn*sqrt(1-zt^2)*t)) - (exp(-zt*wn*t).*cos(wn*sqrt(1-zt^2)*t));

% MATLAB step response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
ss=step(H,t);

figure(1);
nexttile;
plot(t, st, 'Color', '#0069b9', 'linewidth', 2);
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2);
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = -0.2');
hold off;

figure(3); % Plotting the MATLAB-obtained step responses to all the different damping factors on one plot 
% Had to do this in a separate figure because the amplitude is very large compared to the other step responses that they appear as a straight line, so they are not compatible to be placed on the same graph
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t, ss, 'Color', 'green', 'linewidth', 2);
title('The step response s(t) for different values of the damping factor ζ');
xlabel('Time t');
ylabel('Step Response s(t)');
grid on;
hold on;
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 7
zt=-0.25; % New value for the damping factor

% Theoretical step response formula for 0<ζ<1
st= 1 - ((zt/sqrt(1-zt^2))*exp(-zt*wn*t).*sin(wn*sqrt(1-zt^2)*t)) - (exp(-zt*wn*t).*cos(wn*sqrt(1-zt^2)*t));

% MATLAB step response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
ss=step(H,t);

figure(1); 
nexttile([1, 3]);
plot(t, st, 'Color', '#0069b9', 'linewidth', 2);
grid on;
hold on;
plot(t, ss, 'Color', '#A2142F', 'linewidth', 2);
xlabel('Time t');
ylabel('Step Response s(t)');
legend('Theoretically-obtained s(t)', 'MATLAB-obtained s(t)');
title('When ζ = -0.25');
hold off;

figure(3);
plot(t, ss, 'Color', 'red', 'linewidth', 2)
legend('MATLAB-obtained s(t) when ζ = -0.2','MATLAB-obtained s(t) when ζ = -0.25');
hold off;