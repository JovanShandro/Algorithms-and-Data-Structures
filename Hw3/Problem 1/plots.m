%% clears the figure
clf;
%% Initialize the values
n_naive =    [1 2 3 4 5 6 7 10 13      18 25     30 35];
time_naive = [0 0 0 0 0 0 0  0  0  0.016 0.066 0.4 4.8];

n_bottom =    [1 2 3 4 5 6 7 10 13 18 25 30 35 50 100 500 1000 10000 15000 20000 30000 50000 70000];
time_bottom = [0 0 0 0 0 0 0 0  0   0  0  0  0  0   0   0    0  0.001 0.034 0.059 0.1177 0.3 0.625];

n_closed =    [1 2 3 4 5 6 7 10 13 18 25 30 35 50 100 500 1000 10000 15000 20000 30000 50000 70000];
time_closed = [0 0 0 0 0 0 0  0  0  0  0  0  0  0   0   0    0  0.003 0.04 0.06 0.123 0.305 0.56];

n_matrix    = [1 2 3 4 5 6 7 10 13 18 25 30 35 50 100 500 1000 10000 15000 20000 30000 50000 70000];
time_matrix = [0 0 0 0 0 0 0  0  0  0  0  0  0  0   0   0   0.013 0.028 0.045 0.06 0.1 0.34 0.576];
%% make the plots
hold on;
plot(n_naive, time_naive, 'LineWidth', 3);
plot(n_bottom, time_bottom, 'LineWidth', 3);
plot(n_closed, time_closed, 'LineWidth', 3);
plot(n_matrix, time_matrix, 'LineWidth', 3);
title('Non naive Plots');
legend('Naive','Bottom up','Closed form','Matrix form');
xlabel('n');
ylabel('Time(s)');
hold off;

