#include <iostream>

class FileException : public std::exception
{
  protected:
    std::string msg;

  public:
    FileException() noexcept;
    explicit FileException(const std::string &msg) noexcept;

    FileException &operator=(const FileException &other) noexcept;
    virtual ~FileException();
    const std::string what();
};