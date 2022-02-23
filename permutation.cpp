#include <iostream>
#include <list>

template<class T>
std::list<std::list<T>> permutation(std::list<T> L) {
  if (L.size() == 0)
    return std::list<std::list<T>> {{}};
  if (L.size() == 1)
    return std::list<std::list<T>> { L };
  else {
    auto elem = *L.begin();
    L.erase(L.begin());
    auto prev = permutation(L);   // 规模小了一次
    
    std::list<std::list<T>> result;
    
    for (auto sublist : prev) {
      for (int pos = 0; pos <= sublist.size(); pos++) {
	auto work = sublist;    // 需要定义一个变量work
	work.insert(std::next(work.begin(), pos), elem);
	result.insert(result.end(), work);
      }
    }
    return result;
  }
}

template<class T>
std::ostream& operator<< (std::ostream& os, std::list<T>& list) {
  os << "{ ";
  for (auto& x : list)
    os << x << ' ';
  os << " }\n";
  return os;
}

template<class T>
std::ostream& operator<< (std::ostream& os, std::list<std::list<T>>& list) {
  for (auto& sublist : list) {
    os << "\n{ ";
    for (auto& ele : sublist) {
      os << ele << ' ';
    }
    os << " }\n";
  }
  return os;
}

int main() {
  std::list<int> money = { 1, 2, 3, 4 };
  auto result = permutation(money);
  std::cout << result << std::endl;
  return 0;
}
