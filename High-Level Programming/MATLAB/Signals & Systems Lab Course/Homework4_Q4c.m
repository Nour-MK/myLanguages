clear all;
t=[-3:0.001:3];
x1=8+10*cos(2*pi*t);
x2=(10./(pi*t)) .* (sin(82*pi*t) - sin(78*pi*t));

figure;
plot(t,x1,'r', 'linewidth', 2);
grid on;
xlabel('Time t (sec)');
ylabel('X1(t)');

figure;
plot(t,x2,'k');
grid on;
xlabel('Time t (sec)');
ylabel('X2(t)');