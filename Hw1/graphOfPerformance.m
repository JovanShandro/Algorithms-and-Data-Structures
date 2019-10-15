%% Clear the figure 
clf;
%% Initialize data we got from our java program to plot them
sizes = [10 50 100 500 1000 5000 10000];
avg_times   = [0.004  0.025  0.085 0.1  2  11 29];
best_times  = [0.0008 0.0013 0.035 0.09 0.25 5.9  22];
worst_times = [0.008  0.0022 0.056 0.12 3    12.5   48];
%% Drawing the scatter graphs to compare average best and worst cases
hold on;
scatter(sizes, avg_times)
scatter(sizes, best_times)
scatter(sizes, worst_times)
legend('Average','Best','Worst');
xlabel('Size');
ylabel('Time (s)');
hold off;