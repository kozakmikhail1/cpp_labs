#include <iostream>

class FileException : public std::exception
{
  private:
    std::string msg;

  public:
    FileException() noexcept = default;
    explicit FileException(const std::string &msg) noexcept;

    FileException &operator=(const FileException &other) noexcept = default;
    virtual ~FileException() = default;

    void set_msg(const std::string& new_msg);
    std::string get_msg();
    const std::string what();
};