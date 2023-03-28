#include <iostream>
#include <vector>

using std::vector;

void sort_items(vector<int>& weights, vector<int>& values){
  for(int j=0; j<weights.size()-1; j++){
    for(int i=j+1; i<weights.size(); i++){
      if((double)values[i]/(double)weights[i] > (double)values[j]/(double)weights[j]){
        int temp = values[j];
        values[j] = values[i];
        values[i] = temp;

        temp = weights[j];
        weights[j] = weights[i];
        weights[i] = temp;
      }
    }
  }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  // for(int i=0; i<weights.size(); i++){
  //   std::cout << values[i] << " : " << weights[i] << " : " << values[i]/weights[i] << "\n";
  // }
  
  sort_items(weights, values);

  // std::cout << "\n\n\n";
  
  // for(int i=0; i<weights.size(); i++){
  //   std::cout << values[i] << " : " << weights[i] << " : " << values[i]/weights[i] << "\n";
  // }

  for(int i=0; i<weights.size(); i++){
    int unit = weights[i] < capacity ? weights[i] : capacity;
    value += unit * (double)values[i]/(double)weights[i];
    capacity -= unit;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;

  vector<int> values(n);
  vector<int> weights(n);

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
