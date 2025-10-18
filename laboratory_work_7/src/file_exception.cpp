#include "file_exception.h"

FileException::FileException()noexcept = default;
FileException::FileException(const std::string& msg) noexcept
{
    this->msg = msg;
}

FileException& FileException::operator=(const FileException& other)noexcept = default;

FileException::~FileException() = default;
const std::string FileException::what()
{
    return this->msg;
}
