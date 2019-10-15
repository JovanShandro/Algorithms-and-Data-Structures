%% clears the figure
clf;
%% Initialize the values
size  =    [     1      5      10    100 1000 2000 5000  10000 50000 100000 500000 1000000];
time1_ms = [0.0017  0.004  0.00755 0.092  0.1  0.2 0.9    1.3  6.5   11.4    65.8  156.5];
time2_ms = [0.0017  0.0057 0.0093  0.098  0.24 0.3 1.008  1.4  4.7   10.1    63.8  135];
%% make the plots 
hold on;
plot(size, time1_ms, 'LineWidth', 3);
plot(size, time2_ms, 'LineWidth', 3);
title('Heap sorts performance');
legend('Normal Heap sort','The other version');
xlabel('Array size');
ylabel('Time(s)');
hold off;

