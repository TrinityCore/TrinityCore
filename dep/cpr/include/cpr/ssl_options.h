#ifndef CPR_SSLOPTIONS_H
#define CPR_SSLOPTIONS_H

namespace cpr {

class VerifySsl {
  public:
    VerifySsl() {}
    VerifySsl(bool verify);

    operator bool() const;

  private:
    bool verify_ = true;
};

} // namespace cpr

#endif
