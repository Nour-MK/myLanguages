clear all; % Clear all existing variables and figures from memory - fresh start
T0=1; % The fundamental period

Kmax=4;
k=-Kmax:Kmax; % k= 1=-4 2=-3 3=-2 4=-1 5=0 6=1 7=2 8=3 9=4
% NOTE that the first k has index 1 but the value inside it is -4 which is even
% This means that for odd indexes of k the actual value of k is even
% This indirectess is happening because my kmax is an even number 

ak=(-1)./(2*k.^2*pi^2); % ak with non-zero values everywhere
ak(1:2:2*Kmax+1)=0; % Rewriting the value of k at specific indices to be 0
% (1:2:2*Kmax+1) generates a sequence of indices starting from 1, incrementing by 2, and ending at 2*Kmax+1 = 2*4+1 = 9
% This is to choose all the odd indices of k where it has an even value, which means that all the even k's are now = 0 as per the given coefficient definition
[x4,t4]=ctfs_synthesis(T0,ak);
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t4,x4,'g','LineWidth',5)
axis([-1 1 -0.15 0.15]);
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
grid on;
hold on;


Kmax=10; % even
k=-Kmax:Kmax;
ak=(-1)./(2*k.^2*pi^2);
ak(1:2:2*Kmax+1)=0;
[x10,t10]=ctfs_synthesis(T0,ak);
plot(t10,x10,'b','LineWidth',4);
axis([-1 1 -0.15 0.15]);
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
grid on;
hold on;


Kmax=20; % even
k=-Kmax:Kmax;
ak=(-1)./(2*k.^2*pi^2);
ak(1:2:2*Kmax+1)=0;
[x20,t20]=ctfs_synthesis(T0,ak);
plot(t20,x20,'c','LineWidth',3);
axis([-1 1 -0.15 0.15]);
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
grid on;
hold on;


Kmax=50; % even
k=-Kmax:Kmax;
ak=(-1)./(2*k.^2*pi^2);
ak(1:2:2*Kmax+1)=0;
[x50,t50]=ctfs_synthesis(T0,ak);
plot(t50,x50,'r','LineWidth',2);
axis([-1 1 -0.15 0.15]);
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
grid on;
hold off;

title('Reconstructed signal x(t)');
legend('x(t) when Kmax = 4', 'x(t) when Kmax = 10', 'x(t) when Kmax = 20', 'x(t) when Kmax = 50');