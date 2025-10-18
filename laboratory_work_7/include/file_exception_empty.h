#include "file_exception.h"
#include <iostream>

class FileExceptionEmpty : public FileException
{
  public:
    FileExceptionEmpty(const std::string& msg) noexcept;
    ~FileExceptionEmpty() override;
};