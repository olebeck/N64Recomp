#pragma once

class source_location {
public:
    constexpr source_location(const char* file = "unknown",
                              const char* function = "unknown",
                              unsigned int line = 0,
                              unsigned int column = 0) noexcept
        : file_name_(file), function_name_(function), line_(line), column_(column) {}

    source_location(const source_location&) = default;
    source_location& operator=(const source_location&) = default;

    constexpr const char* file_name() const noexcept {
        return file_name_;
    }

    constexpr const char* function_name() const noexcept {
        return function_name_;
    }

    constexpr unsigned int line() const noexcept {
        return line_;
    }

    constexpr unsigned int column() const noexcept {
        return column_;
    }

    static source_location current(const char* file = __builtin_FILE(), 
                                   const char* function = __builtin_FUNCTION(), 
                                   unsigned int line = __builtin_LINE(), 
                                   unsigned int column = 0) noexcept {
        return source_location(file, function, line, column);
    }

private:
    const char* file_name_;
    const char* function_name_;
    unsigned int line_;
    unsigned int column_;
};
