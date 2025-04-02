clear all;
t=[0:0.01:2];
yt=4*(exp(-6*t)-exp(-7*t));
plot(t,yt,'r');
grid on;
xlabel('Time t');
ylabel('y(t)');