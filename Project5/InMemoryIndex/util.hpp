#ifndef __UTIL_HPP_
#define __UTIL_HPP_

#include <vector>
#include <string>
#include <string.h>
#include <assert.h>

using namespace std;

vector<string> tokenize(const string& line, const char* delim)
{
	vector<string> tokens;
	char *dup = strdup(line.c_str());
	char *tok = strtok(dup, delim);
	while(tok != NULL)
	{
		tokens.push_back(string(tok));
		tok = strtok(NULL, delim);
	}
	free(dup);

	return tokens;
}

inline uint64_t last_bit_set (uint64_t x) {
  assert (x > 0);
  return (sizeof (uint64_t) * 8 - __builtin_clzll (x));
}

inline uint64_t floor_lg (uint64_t x) {
  return (last_bit_set (x) - 1);
}

inline uint64_t ceil_lg (uint64_t x) {
  return (last_bit_set (x - 1));
}

/* Returns the largest power of 2 not greater than x
 * (i.e., $2^{\lfloor \lg x \rfloor}$).
 */
inline uint64_t hyperfloor (uint64_t x) {
  return (1 << floor_lg (x));
}

/* Returns the smallest power of 2 not less than x
 * (i.e., $2^{\lceil \lg x \rceil}$).
 */
inline uint64_t hyperceil (uint64_t x) {
  return (1 << ceil_lg (x));
}

inline uint64_t ceil_div (uint64_t x, uint64_t y) {
  assert (x > 0);
  return (1 + ((x - 1) / y));
}

#endif  /* __UTIL_H_ */
