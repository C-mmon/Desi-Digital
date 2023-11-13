constexpr static std::array<uint8_t, 256> isForbiddenArray =[]()
{
      std::array<uint8_t, 256> result{};
  for (uint8_t c : {'\0', '\x09', '\x0a','\x0d', ' ', '#', '/', ':',
    '<', '>', '?', '@', '[', '\\', ']', '^', '|'}) {
   result[c] = true;
  }
  return result;
}();

bool is_forbidden_host_code_point_array(char c) {
  return is_forbidden_array[uint8_t(c)];
}