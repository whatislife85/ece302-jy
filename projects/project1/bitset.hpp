#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

  //constructs valid bitset of size 8 with all bits set to 0
  Bitset();

  //constructs valid bitset of size 'size' with all bits set to 0
  Bitset(intmax_t size);

  //constructs valid bitset from string array of 1's and 0's
  Bitset(const std::string & value);

  //deconstructs Bitset object and deallocates memory
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  //returns size of bitset
  intmax_t size() const;

  //returns true if bitset is valid, false otherwise
  bool good() const;

  //sets 'index' bit value to 1
  void set(intmax_t index);

  //resets 'index' bit value to 0
  void reset(intmax_t index);

  //toggles 'index' bit value
  void toggle(intmax_t index);

  //checks if 'index' bit is set, returns true if yes and false if not
  bool test(intmax_t index);

  //returns bitset as a string of digits from left-to-right
  std::string asString() const;

private:
  bool valid; //true if bitset is valid, false otherwise
  intmax_t bsize; //size of bitset
  u_int8_t *myBitset; //bitset
};

#endif
