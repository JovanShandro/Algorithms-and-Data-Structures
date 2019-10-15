%% Clear the figure 
clf;
%% Initialize data we got from our java program to plot them
sizes =   [10       50        100      500      1000     5000       10000   20000    50000    100000];
sizes1 =  [10       50        100      500      1000     5000       10000];

avg_timesSel   =[0.004  0.025  0.085 0.1  2  11 29];
best_timesSel = [0.0008 0.0013 0.035 0.09 0.25 5.9  22];
worst_timesSel =[0.008  0.0022 0.056 0.12 3    12.5   48];

avg_timesk10   = [0.005333 0.014222  0.018222 0.149778 0.418667 1.697335  3.412003 2.128446 5.205783 11.116009 ];
best_timesk10  = [8.89E-4  0.003  0.002667 0.008444 0.023111 0.108445 0.171334 0.088888 0.222667  0.400445];
worst_timesk10 = [0.001333 0.002667  0.006667 0.078666 0.057778 0.363111 0.515112 1.357335 2.591557  5.50445 ];

avg_timesk15=    [0.004889 0.012888  0.02      0.125333 0.310667 1.630668  3.784448 2.433779 4.73956 10.612898];
best_timesk15 =  [8.89E-4  0.061778  0.001333  0.007111 0.022667 0.098222 0.242667 0.117333 0.166667 0.277333];
worst_timesk15 = [8.89E-4  0.001778  0.006666  0.026222 0.114667 0.300444 0.503556  1.136445 2.432891 3.500448];

avg_timesk40=   [0.007111 0.018223 0.031555 0.201334  0.458222 2.414224  1.216445 2.50578  6.352006 11.634233];
best_timesk40 = [0.001333 0.047555  0.012    0.004     0.007111 0.090667  0.088  0.153333  0.127556  0.304444];
worst_timesk40 =[8.89E-4  0.002222  0.003111 0.020889  0.050222 0.326667 0.460445 0.975557 2.714224 5.017338];

avg_timesk100=  [0.005778 0.010667 0.040445 0.180445 0.380889 1.983113 1.771112  3.282225 5.826672  11.055565];
best_timesk100 =[8.89E-4  0.0      4.44E-4  0.040889 0.009333 0.012889  0.023556  0.047556 0.132 0.218667];
worst_timesk100=[8.89E-4  0.001333 0.004889 0.024889 0.053333 0.388001 0.49289  1.057779 3.233781 6.226672];

avg_timesk200 = [0.008    0.016        0.067112  0.427556 0.942224 4.132894 5.371115  4.612004  5.958672 10.988009];
best_timesk200 =[4.45E-4  0.0          4.45E-4  0.080889  0.002222 0.031111 0.068    0.074223  0.232  0.328445];
worst_timesk200=[8.89E-4  8.89E-4      0.003111  0.020889 0.040889 0.285778 0.622667  1.297335 3.699558 6.920895];
%% Drawing the plots to compare average best and worst cases
hold on;
plot(sizes1, avg_timesSel)
plot(sizes1, best_timesSel)
plot(sizes1, worst_timesSel)
plot(sizes, avg_timesk10)
plot(sizes, best_timesk10)
plot(sizes, worst_timesk10)
plot(sizes, avg_timesk15)
plot(sizes, best_timesk15)
plot(sizes, worst_timesk15)
plot(sizes, avg_timesk40)
plot(sizes, best_timesk40)
plot(sizes, worst_timesk40)
plot(sizes, avg_timesk100)
plot(sizes, best_timesk100)
plot(sizes, worst_timesk100)
plot(sizes, avg_timesk200)
plot(sizes, best_timesk200)
plot(sizes, worst_timesk200)
legend('Average Selec. sort', 'Best Sele. Sort', 'Worst Sele. Sort', 'Average k 10','Best k 10','Worst k 10','Average k 15','Best k 15','Worst k 15','Average k 40','Best k 40','Worst k 40','Average k 100','Best k 100','Worst k 100','Average k 200','Best k 200','Worst k 200');
title('Plots for k = {10, 15, 40, 100, 200}');
xlabel('Size');
ylabel('Time (ms)');
hold off;