% Impulse response h(t) of a 2nd order system using a theoretically derived formula and using MATLAB's impulse function for different values of the damping factor

clear all;
wn=1;
t=0:0.01:30;

% Recall that the * operator alone is for matrix multiplication, and, for that to be valid, the number of columns in the first matrix must be equal to the number of rows in the second matrix. 
% On the other hand, .* operator performs an element-wise multiplication, and, for that to be valid, the dimensions of the matrices must be the same. 
% There is no concept of rows and columns in the element-wise multiplication.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 1 - Will be heavily commentated to explain the steps and the rest of the cases will be just the same process repeated so they will have minimal comments 
zt=0.5; % Damping factor

% Theoretical impulse response formula for 0<ζ<1
ht=(wn*exp(-zt*wn*t)./sqrt(1-zt^2)).*sin(wn*sqrt(1-zt^2)*t); % ht means h theory, with h being the impulse response

% MATLAB impulse response calculation
% b and a are the coefficients of the Laplace variable s of the transfer function
b=wn^2; % The coefficient of s^0 in the numerator of the transfer function
a=[1 2*zt*wn wn^2]; % The coefficients of s^2, s^1, and s^0 in the denominator of the transfer function - there is a single empty space between each coefficient
% Notice that the coefficients are defined in descending order; meaning that the coefficient of highest power s will go first
H=tf(b,a); % tf creates a transfer function model based on the numerator and denominator coefficients
hs=impulse(H,t); % hs means h simulation, with h being the impulse response

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
tLayout = tiledlayout(3, 3, 'Padding', 'none', 'TileSpacing', 'compact'); % Create a 3x3 tile layout
nexttile;
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = 0.5');
title(tLayout, 'The impulse response h(t) for different values of the damping factor ζ');
hold off;

figure(2); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
% (Only using MATLAB since we already verified the validity of both methods in figure 1)
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t, hs, 'Color', 'cyan', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
title(tLayout, 'The impulse response h(t) for different values of the damping factor ζ');
xlabel('Time t');
ylabel('Impulse Response h(t)');
grid on;
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 2
zt=2; % New value for the damping factor

% Theoretical impulse response formula for 1<ζ
ht = (wn./(2*sqrt(zt^2-1))) .* (exp(-t*(zt*wn - wn*sqrt(zt^2-1))) - exp(-t*(zt*wn + wn*sqrt(zt^2-1))));

% MATLAB impulse response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=impulse(H,t);

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
nexttile;
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = 2');
hold off;

figure(2); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
plot(t, hs, 'Color', 'green', 'linewidth', 2)
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 3
zt=0; % New value for the damping factor

% Theoretical impulse response formula for ζ=0
ht = wn*sin(wn*t);

% MATLAB impulse response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=impulse(H,t);

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
nexttile;
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = 0');
hold off;

figure(2); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
plot(t, hs, 'Color', 'red', 'linewidth', 2)
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 4
zt=0.2; % New value for the damping factor

% Theoretical impulse response formula for 0<ζ<1
ht=(wn*exp(-zt*wn*t)./sqrt(1-zt^2)).*sin(wn*sqrt(1-zt^2)*t);

% MATLAB impulse response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=impulse(H,t);

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
nexttile;
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = 0.2');
hold off;

figure(2); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
plot(t, hs, 'Color', 'blue', 'linewidth', 2)
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 5
zt=1; % New value for the damping factor

% Theoretical impulse response formula for ζ=1
ht = (wn^2) * t .* exp(-wn * t);

% MATLAB impulse response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=impulse(H,t);

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
nexttile;
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = 1');
hold off;

figure(2); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
plot(t, hs, 'Color', 'magenta', 'linewidth', 2);
legend('MATLAB-obtained h(t) when ζ = 0.5', 'MATLAB-obtained h(t) when ζ = 2','MATLAB-obtained h(t) when ζ = 0','MATLAB-obtained h(t) when ζ = 0.2','MATLAB-obtained h(t) when ζ = 1');
hold off;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 6
zt=-0.2; % New value for the damping factor
% Note that The damping ratio ζ cannot be less than zero; it is typically in the range of 0 to 1 for underdamped systems, exactly 1 for critically damped systems, and greater than 1 for overdamped systems.
% So, this will actually result in the same behavior as just zt = 0.2 but inversed in time and a lot stretched in amplitude

% Theoretical impulse response formula for 0<ζ<1
ht=(wn*exp(-zt*wn*t)./sqrt(1-zt^2)).*sin(wn*sqrt(1-zt^2)*t);

% MATLAB impulse response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=impulse(H,t);

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
nexttile;
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = -0.2');
hold off;

figure(3); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
% Had to do this in a separate figure because the amplitude is very large compared to the other impulse responses that they appear as a straight line, so they are not compatible to be placed on the same graph
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t, hs, 'Color', 'green', 'linewidth', 2);
title(tLayout, 'The impulse response h(t) for different values of the damping factor ζ');
xlabel('Time t');
ylabel('Impulse Response h(t)');
grid on;
hold on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 7
zt=-0.25; % New value for the damping factor

% Theoretical impulse response formula for 0<ζ<1
ht=(wn*exp(-zt*wn*t)./sqrt(1-zt^2)).*sin(wn*sqrt(1-zt^2)*t);

% MATLAB impulse response calculation
b=wn^2; 
a=[1 2*zt*wn wn^2];
H=tf(b,a); 
hs=impulse(H,t);

figure(1); % Plotting the obtained impulse response of both the theoretical and simulation methods on the same plot to see if they overlap; to verify the validity of both methods
nexttile([1, 3]);
plot(t, ht, 'Color', '#0069b9', 'linewidth', 2) % Plotting the theorey impulse response with respect to time
grid on;
hold on;
plot(t, hs, 'Color', '#A2142F', 'linewidth', 2) % Plotting the simulation impulse response with respect to time
xlabel('Time t');
ylabel('Impulse Response h(t)');
legend('Theoretically-obtained h(t)', 'MATLAB-obtained h(t)');
title('When ζ = -0.25');
hold off;

figure(3); % Plotting the MATLAB-obtained impulse responses to all the different damping factors on one plot 
plot(t, hs, 'Color', 'red', 'linewidth', 2)
legend('MATLAB-obtained h(t) when ζ = -0.2','MATLAB-obtained h(t) when ζ = -0.25');
hold off;