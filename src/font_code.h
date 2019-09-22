#include <string>

extern const std::string font_code[3143];

template <typename TYPE, std::size_t SIZE>
std::size_t array_length(const TYPE (&)[SIZE])
{   
    return SIZE;
}
