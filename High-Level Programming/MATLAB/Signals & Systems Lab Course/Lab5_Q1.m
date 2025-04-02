% Observing the effect of the value of zeta (the damping factor) on changing the location of the poles

clear all;

wn = 1; % Natural frequency

figure(1); % On it, I will plot all the poles for different values of zeta
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
zeta1 = 0; % Damping factor
H1=[1 2*zeta1(1)*wn wn^2]; % Corresponds to (1.s^0) + (2.zeta.wn.s^1) + (wn^2.s^2)
% The system is defined by the denominator of its transfer function H(s), which is a second-order polynomial
% Note that, in the context of transfer functions and system analysis, the Laplace variable s is often implicit.
p1=roots(H1); % The poles of the system are found from the roots of the denominator of H(s)
plot(real(p1),imag(p1), 'Color', '#0069b9', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
% Plotting the real part on the x axis and the imaginary part on the y axis
% LineStyle to 'none' indicates that no lines should connect the markers. 
grid on;
hold on;

figure(2); % On it, I will plot the poles for each zeta separately in their own tile
tLayout = tiledlayout(2,3, 'Padding', 'none', 'TileSpacing', 'loose'); 
nexttile; % no 1
plot(real(p1),imag(p1), 'Color', '#0069b9', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
xlabel('real(p)');
ylabel('imag(p)');
title({'Pole locations when ζ = 0', '\color{gray}p1 = 0.0000 + 1.0000i', 'p1 = 0.0000 - 1.0000i'});
title(tLayout, {'Location of Poles of the System for Different values of ζ', '(Each plotted on a separate plot)'});

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1); % Switching back to figure 1 on which I draw all the poles together
zeta2=0.2; % Changing the value of zeta
H2=[1 2*zeta2(1)*wn wn^2]; % Recalculating the denominator after changing the value of zeta
p2=roots(H2);
plot(real(p2),imag(p2), 'Color', '#c90c47', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold on;

figure(2); % Switching back to figure 2 on which I draw the poles of different zetas separately
nexttile; % no 2
plot(real(p2),imag(p2), 'Color', '#c90c47', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
xlabel('real(p)');
ylabel('imag(p)');
title({'Pole locations when ζ = 0.2', '\color{gray}p2 = -0.2000 + 0.9798i', 'p2 = -0.2000 - 0.9798i'});

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1); % Switching back to figure 1 on which I draw all the poles together
zeta3=0.5;
H3=[1 2*zeta3(1)*wn wn^2];
p3=roots(H3);
plot(real(p3),imag(p3), 'Color', '#1da14b', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold on;

figure(2); % Switching back to figure 2 on which I draw the poles of different zetas separately
nexttile; % no 3
plot(real(p3),imag(p3), 'Color', '#1da14b', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
xlabel('real(p)');
ylabel('imag(p)');
title({'Pole locations when ζ = 0.5', '\color{gray}p3 = -0.5000 + 0.8660i', 'p3 = -0.5000 - 0.8660i'});

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1); % Switching back to figure 1 on which I draw all the poles together
zeta4=1;
H4=[1 2*zeta4(1)*wn wn^2];
p4=roots(H4);
plot(real(p4),imag(p4),'Color', '#f7771d', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold on;

figure(2); % Switching back to figure 2 on which I draw the poles of different zetas separately
nexttile; % no 4
plot(real(p4),imag(p4),'Color', '#f7771d', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
xlabel('real(p)');
ylabel('imag(p)');
title({'Pole locations when ζ = 1', '\color{gray}p4 = -1', 'p4 = -1'});

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1); % Switching back to figure 1 on which I draw all the poles together
zeta5=2;
H5=[1 2*zeta5(1)*wn wn^2];
p5=roots(H5);
plot(real(p5),imag(p5),'Color', '#f72d93', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold on;

figure(2); % Switching back to figure 2 on which I draw the poles of different zetas separately
nexttile; % no 5
plot(real(p5),imag(p5),'Color', '#f72d93', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
xlabel('real(p)');
ylabel('imag(p)');
title({'Pole locations when ζ = 2', '\color{gray}p5 = -3.7321', 'p5 = -0.2679'});

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

figure(1); % Switching back to figure 1 on which I draw all the poles together
zeta6=-0.2;
H6=[1 2*zeta6(1)*wn wn^2];
p6=roots(H6);
plot(real(p6),imag(p6),'Color', '#7925c7', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold off;

ylim([-2 2]); % Setting the y-axis bounds
xlim([-4 4]); % Setting the x-axis bounds

xlabel('real(p)');
ylabel('imag(p)');
legend('Poles when ζ = 0', 'Poles when ζ = 0.2', 'Poles when ζ = 0.5', 'Poles when ζ = 1', 'Poles when ζ = 2', 'Poles when ζ = -0.2');
title({'Location of Poles of the System for Different values of ζ', '(All plotted on the same graph)'}); 
% Allows you to write the title on 2 lines instead of just 1

figure(2); % Switching back to figure 2 on which I draw the poles of different zetas separately
nexttile; % no 6
plot(real(p6),imag(p6),'Color', '#7925c7', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
xlabel('real(p)');
ylabel('imag(p)');
title({'Pole locations when ζ = -0.2', '\color{gray}p6 = 0.2000 + 0.9798i', 'p6 = 0.2000 - 0.9798i'});