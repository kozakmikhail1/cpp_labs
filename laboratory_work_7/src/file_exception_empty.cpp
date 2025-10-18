#include "file_exception_empty.h"

FileExceptionEmpty::~FileExceptionEmpty() = default;

FileExceptionEmpty::FileExceptionEmpty(const std::string& msg) noexcept
{
    this->msg = "File empty\n" + msg;
}

