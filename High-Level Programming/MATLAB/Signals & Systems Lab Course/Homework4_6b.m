clear all;
t=[0:0.01:1];
ht=-2*exp(-7*t)+6*exp(-11*t);
plot(t,ht,'r');
grid on;
xlabel('Time t');
ylabel('h(t)');