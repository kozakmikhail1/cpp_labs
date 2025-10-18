#include "file_exception.h"
#include <iostream>

class FileExceptionEmpty : public FileException
{
  public:
    explicit FileExceptionEmpty(const std::string& msg) noexcept;
    ~FileExceptionEmpty() final = default;
};