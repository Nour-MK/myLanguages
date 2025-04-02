clear all; % Clear all existing variables and figures from memory - fresh start

T0=4; % The fundamental period

Kmax=5;
k=-Kmax:Kmax;
ak = (j.^k).*(sin(k*(pi/4))./(pi*k)); 
ak(Kmax+1)= 0;

[x5,t5]=ctfs_synthesis(T0,ak);

tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t5,x5,'g','LineWidth',4);
axis([-4 4 -0.5 1.2]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold on;


Kmax=20; % Overwriting the value in Kmax
k=-Kmax:Kmax; % Overwriting the value in k
ak = (j.^k).*(sin(k*(pi/4))./(pi*k)); % Overwriting the values in ak
ak(Kmax+1)= 0; % Overwriting the value in ak(Kmax+1)

[x20,t20]=ctfs_synthesis(T0,ak);

plot(t20,x20,'b','LineWidth',3);
axis([-4 4 -0.5 1.2]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold on;


Kmax=50; % Overwriting the value in Kmax
k=-Kmax:Kmax; % Overwriting the value in k
ak = (j.^k).*(sin(k*(pi/4))./(pi*k)); % Overwriting the values in ak
ak(Kmax+1)= 0; % Overwriting the value in ak(Kmax+1)

[x50,t50]=ctfs_synthesis(T0,ak);

plot(t50,x50,'r','LineWidth',2);
axis([-4 4 -0.5 1.2]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold off;

title('Reconstructed signal x(t)');
legend('x(t) when Kmax = 5', 'x(t) when Kmax = 20', 'x(t) when Kmax = 50');