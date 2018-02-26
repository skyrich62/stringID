#include <iostream>
#include <vector>
#include <map>

class stringID
{
public:
  stringID() = delete;
  
  static stringID from_string(const std::string &name)
  {
    auto &map = get_map();
    auto found = map.equal_range(name);
    if (found.first == found.second)  {
      auto &vec = get_vec();
      auto idx = vec.size();
      map.insert(found.first, {name, idx});
      vec.push_back(name);
      return stringID{idx};
    }
    return stringID{found.first->second};
  }

  const std::string& name() const
  {
    return get_vec()[_idx];
  }

private:
  
  using Map = std::map<std::string, size_t>;
  using Vec = std::vector<std::string>;

  static Map& get_map()
  {
    static Map _map;
    return _map;
  }

  static Vec& get_vec()
  {
    static Vec _vec;
    return _vec;
  }

  explicit stringID(size_t idx) : _idx(idx) { }
  size_t _idx;
};

