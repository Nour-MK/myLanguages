% Observing the effect of the value of zeta (the damping factor) on changing the location of the poles

clear all;

wn = 10; % Natural frequency

figure(1); % On it, I will plot all the poles for different values of zeta
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
zeta1 = 1/4; % Damping factor
H1=[1 2*zeta1(1)*wn wn^2]; % Corresponds to (1.s^0) + (2.zeta.wn.s^1) + (wn^2.s^2)
p1=roots(H1); % The poles of the system are found from the roots of the denominator of H(s)
plot(real(p1),imag(p1), 'Color', '#0069b9', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
% Plotting the real part on the x axis and the imaginary part on the y axis
grid on;
hold on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1);
zeta2=0; % Changing the value of zeta
H2=[1 2*zeta2(1)*wn wn^2]; % Recalculating the denominator after changing the value of zeta
p2=roots(H2);
plot(real(p2),imag(p2), 'Color', '#c90c47', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1); 
zeta3=1;
H3=[1 2*zeta3(1)*wn wn^2];
p3=roots(H3);
plot(real(p3),imag(p3), 'Color', '#1da14b', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
figure(1);
zeta4=3;
H4=[1 2*zeta4(1)*wn wn^2];
p4=roots(H4);
plot(real(p4),imag(p4),'Color', '#f7771d', 'Marker', 'x','LineStyle', 'none', 'linewidth', 2);
grid on;
hold off;

xlabel('real(p)');
ylabel('imag(p)');
legend('Poles when ζ = 1/4', 'Poles when ζ = 0', 'Poles when ζ = 1', 'Poles when ζ = 3');
title({'Location of Poles of the System for Different values of ζ', '(All plotted on the same graph)'}); 