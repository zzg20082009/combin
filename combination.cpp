#include <list>
#include <set>
#include <iostream>
#include <string>

template<class T>
std::ostream& operator<<(std::ostream& os, std::set<T>& set) {
  os << "{ ";
  for (auto&& s : set)
    os << s << " ";
  os << "}\n";
  return os;
}

template<class T>
std::list<std::set<T>> combination(std::set<T> C, int R) {
  if (C.size() < R) {
    return std::list<std::set<T>> {};
  } else if (C.size() == R)
    return std::list<std::set<T>> {C};
  else {
    T tmp = *C.begin();
    C.erase(C.begin());
    std::list<std::set<T>> Result1 = combination(C, R);
    std::list<std::set<T>> Result2 = combination(C, R-1);
    for (auto& s : Result2)
      s.insert(tmp);
    Result1.splice(Result1.end(), Result2);
    return Result1;
  }
}

int main() {
  std::set<int> c { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::list<std::set<int>> result = combination(c, 4);

  for (std::set<int> r : result) {
    std::cout << r;
  }
}
