#include "file_exception_empty.h"

FileExceptionEmpty::~FileExceptionEmpty() = default;

FileExceptionEmpty::FileExceptionEmpty(const std::string& msg) noexcept
{
    set_msg("File empty.\n" + msg);
}

