clear all; % Clear all existing variables and figures from memory - fresh start

Kmax=10; % Setting the maximum value for k

k=-Kmax:Kmax; % Creating an array of values from -Kmax to Kmax = -10 to 10
% k index 1 = -10 
% k index 2 = -9 
% k index 3 = -8 
% k index 4 = -7 
% k index 5 = -6 
% k index 6 = -5 
% k index 7 = -4 
% k index 8 = -3 
% k index 9 = -2 
% k index 10 = -1 
% k index 11 = 0 
% k index 12 = 1 
% k index 13 = 2 
% k index 14 = 3 
% k index 15 = 4 
% k index 16 = 5 
% k index 17 = 6 
% k index 18 = 7 
% k index 19 = 8 
% k index 20 = 9 
% k index 21 = 10
% So we see that the length of k is 10-(-10)+1 = 21 - which is exactly how many indexes there are

ak = (sin(k*(pi/2)))./(pi*k); % The equation for ak's
% ./ is necessary because you want to perform element-wise division for each element in the array sin(k*(pi/2)) divided by the corresponding element in the array pi*k

ak(Kmax+1) = 1/2; % Setting the value of a0
% a0 had to be set manually because sin(0)/0 is undefined and requires applying L'ohpital's rule
% Kmax+1 is the index at which the value is 0, it is index 10+1 = 11 which is true according to the analysis above of how the array would be filled
% The reason why a0 is represented as the element at index (Kmax+1) is due to MATLAB's indexing convention which starts from 1. If k is ranging from -kmax to kmax then kmax+1 corresponds to the k=0 term.

% Doing the same process for Kmax = 50
Kmax1=50;
k1=-Kmax1:Kmax1; % The length of k1 is 50-(-50)+1 = 101
ak1 = (sin(k1*(pi/2)))./(pi*k1);
ak1(Kmax1+1) = 1/2;

% Doing the same process for Kmax = 100
Kmax2=100;
k2=-Kmax2:Kmax2; % The length of k2 is 100-(-100)+1 = 201
ak2 = (sin(k2*(pi/2)))./(pi*k2);
ak2(Kmax2+1) = 1/2;

% Create a (2 rows x 3 cols) tiled layout with no padding and compact tile spacing
tLayout = tiledlayout(2,3, 'Padding', 'none', 'TileSpacing', 'compact'); 
% Possible values from smallest to largest: none - tight - compact - loose
% Default is loose, which yields very big margins on the sides on theplots, which, consequently, makes the plots smaller

% Activate the first subplot
nexttile;
stem(k, abs(ak), 'filled','Color',[0.6350, 0.0780, 0.1840],'LineWidth',1); % A stem plot is similar to a scatter plot, but instead of points, vertical lines (stems) are used to represent data points. It is often used to visualize discrete data.
axis([-Kmax Kmax 0 0.5]); % axis [xmin, xmax, ymin, ymax]
grid on
xlabel('k');
ylabel('Magnitude of ak')

% Activate the second subplot
nexttile;
stem(k1, abs(ak1), 'filled','Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
axis([-Kmax1 Kmax1 0 0.5]); 
grid on
xlabel('k');
ylabel('Magnitude of ak')

% Activate the third subplot
nexttile;
stem(k2, abs(ak2), 'filled','Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
axis([-Kmax2 Kmax2 0 0.5]); 
grid on
xlabel('k');
ylabel('Magnitude of ak')

% Activate the fourth subplot
nexttile;
stem(k, angle(ak), 'filled','Color',[0.6350, 0.0780, 0.1840],'LineWidth',1)
axis([-Kmax Kmax -4 4])
grid on
xlabel('k');
ylabel('Phase Angle of ak (rad)')

% Activate the fifth subplot
nexttile;
stem(k1, angle(ak1), 'filled','Color',[0.6350, 0.0780, 0.1840],'LineWidth',1)
axis([-Kmax1 Kmax1 -4 4])
grid on
xlabel('k');
ylabel('Phase Angle of ak (rad)')

% Activate the sixth subplot
nexttile;
stem(k2, angle(ak2), 'filled','Color',[0.6350, 0.0780, 0.1840],'LineWidth',1)
axis([-Kmax2 Kmax2 -4 4])
grid on
xlabel('k');
ylabel('Phase Angle of ak (rad)')