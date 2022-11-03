#include "random_vector.h"
#include <string>

// TODO: add any include you might require

double static Rand(double f_min, double f_max)
{
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}

RandomVector::RandomVector(int size, double max_val) { 
    // TODO: Write your code here
    for (int i = 0; i < size; ++i)
    {
        vect.emplace_back(Rand(0, max_val));
    }
}

void RandomVector::print(){
    // TODO: Write your code here
    for (size_t i = 0; i < vect.size(); ++i)
    {
        std::cout << vect[i];
        if (i != vect.size()-1)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << "\n";
        }
    }
}

double RandomVector::mean(){
    // TODO: Write your code here
    if (vect.empty())
    {
      return 0.0;
    }

    double sum = 0.0;
    for(const auto& value : vect)
    {
        sum += value;
    }
    return sum / vect.size();
}

double RandomVector::max(){
  // TODO: Write your code here
    if (vect.empty())
    {
        return -1; 
    }

    double max_v = vect[0];
    for(const auto& value : vect)
    {
        if (value > max_v)
        {
          max_v = value;
        }
    }

    return max_v;
}

double RandomVector::min(){
    //TODO:  Write your code here
    if (vect.empty())
    {
        return -1; 
    }

    double min_v = vect[0];
    for(const auto& value : vect)
    {
        if (value < min_v)
        {
          min_v = value;
        }
    }

    return min_v;
}

void RandomVector::printHistogram(int bins){
    // TODO: Write your code here
    // calc each bin's height
    double max_v = max();
    double min_v = min();
    double bin_width = (max_v - min_v) / bins;
    
    std::vector<int> cnt(vect.size(), 0);

    for (int i = 0 ; i < vect.size(); ++i)
    {
        double val = vect[i];
        for (int j = 0; j < bins; ++j)
        {
          double bin_min = min_v + j*bin_width;
          double bin_max = min_v + (j+1)*bin_width;
          if (val >= bin_min && val < bin_max)
          {
              cnt[j]++;
          }
        }
    }

    // calc eahc bin's string shape
    int max_height = 0;
    for(const auto& c : cnt)
    {
      max_height = c > max_height ? c : max_height;
    }

    std::vector<std::vector<std::string> > hist(bins, std::vector<std::string>(max_height, "   "));
    for (int i = 0; i < bins; ++i)
    {
        int h = cnt[i]; 
        for (int j = 0; j < h; ++j)
        {
            hist[i][j] = "***";
        }
    }

    // print
    for (int h = max_height-1; h >= 0; --h)
    {
      for (int b = 0; b < bins; ++b)
      {
          std::cout << hist[b][h];
          if (b != bins-1)
          {
            std::cout << " ";
          }
          else
          {
            std::cout << "\n";
          }
      }
    }
}
