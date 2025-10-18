#include "file_exception.h"

FileException::FileException(const std::string& msg) noexcept
{
    this->msg = msg;
}
const std::string FileException::what()
{
    return this->msg;
}

void FileException::set_msg(const std::string& new_msg)
{
    this->msg = new_msg;
}

std::string FileException::get_msg()
{
    return msg;
}
