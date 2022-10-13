#ifndef KASPERSKIYTEST1_SRC_UTILS_CHRONOUTILS_H_
#define KASPERSKIYTEST1_SRC_UTILS_CHRONOUTILS_H_

class ChronoUtils {
public:
    template <class Rep, std::intmax_t num, std::intmax_t denom>
    static auto chronoBurst(std::chrono::duration<Rep, std::ratio<num, denom>> d)
    {
        const auto hrs = std::chrono::duration_cast<std::chrono::hours>(d);
        const auto mins = std::chrono::duration_cast<std::chrono::minutes>(d - hrs);
        const auto secs = std::chrono::duration_cast<std::chrono::seconds>(d - hrs - mins);
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(d - hrs - mins - secs);

        return std::make_tuple(hrs, mins, secs, ms);
    }
};

#endif //KASPERSKIYTEST1_SRC_UTILS_CHRONOUTILS_H_
