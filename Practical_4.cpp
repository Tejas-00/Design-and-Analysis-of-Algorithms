// Practical 4:
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
double ratio(pair<double, double> item)
{
    return item.first / item.second;
}

double fractional_knapsack(double capacity, vector<double> values, vector<double> weights)
{
    int n = values.size();
    vector<pair<double, double>> items(n);
    for (int i = 0; i < n; ++i)
    {
        items[i] = make_pair(values[i], weights[i]);
    }
    sort(items.begin(), items.end(), [](pair<double, double> a, pair<double, double> b)
         { return ratio(a) > ratio(b); });

    double total_value = 0.0;
    cout << fixed << setprecision(2);
    cout << setw(10) << "Item"
         << setw(10) << "Value"
         << setw(10) << "Weight"
         << setw(10) << "Taken"
         << setw(20) << "Accumulated Value"
         << endl;
    cout << string(60, '-') << endl;
    for (int i = 0; i < n; ++i)
    {
        double value = items[i].first;
        double weight = items[i].second;
        double taken;

        if (weight <= capacity)
        {
            taken = weight;
            capacity -= weight;
            total_value += value;
        }
        else
        {
            taken = capacity;
            total_value += value * (capacity / weight);
            capacity = 0;
        }
        cout << setw(10) << (i + 1)
             << setw(10) << value
             << setw(10) << weight
             << setw(10) << taken
             << setw(20) << total_value
             << endl;
        if (capacity == 0)
        {
            break;
        }
    }

    return total_value;
}
int main()
{
    double capacity = 50;
    vector<double> values = {60, 100, 120};
    vector<double> weights = {10, 20, 30};
    double max_value = fractional_knapsack(capacity, values, weights);
    cout << "\nMaximum value in Knapsack = " << max_value << endl;
    return 0;
}
/* OUTPUT:
      Item     Value    Weight     Taken   Accumulated Value
------------------------------------------------------------
         1     60.00     10.00     10.00               60.00
         2    100.00     20.00     20.00              160.00
         3    120.00     30.00     20.00              240.00

Maximum value in Knapsack = 240.00
*/