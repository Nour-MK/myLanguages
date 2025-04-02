t=[0:0.001:2]; % Creates a time vector ranging from 0 to 2 seconds with a step size of 0.001 

y1=5-(3*exp(-2*t)); % Plotting the capacitor voltage output obtained due to input x1(t)
y2=2*(1+3*t).*exp(-2*t); % Plotting the capacitor voltage output obtained due to input x2(t)

plot(t,y1,'r', 'LineWidth',1.5);
hold on; % To overlap both plots on the same figure
plot(t,y2,'b', 'LineWidth',1.5);