#include "zyggy-begin.h"
#include "gtest.h"
#include "zyggy-end.h"

// Reduce the warning level in MSVC
#if ZYGGY_PLATFORM == ZYGGY_PLATFORM_MSVC
#pragma warning(push, 3)
// BEWARE: This source must be compiled with an additional include path of $(GoogleTest) and not /Za
// HOWEVER: We cannot enforce that (or even detect it) so we just get cryptic compile-time errors if we forget
#endif

// Include the consolidated GoogleTest source code
#include "src/gtest-all.cc"

// Restore the warning level in MSVC
#if ZYGGY_PLATFORM == ZYGGY_PLATFORM_MSVC
#pragma warning(pop)
// GoogleTest for MSVC uses old POSIX names
// See https://docs.microsoft.com/en-gb/cpp/c-runtime-library/backward-compatibility
#pragma comment(lib, "oldnames.lib")
#endif

int main(int argc, char *argv[]) try {
  // The main entry point for GoogleTest harnesses
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
} catch (const std::runtime_error& exception) {
  std::cerr << "Exception caught: " << exception.what() << std::endl;
  return 1;
}
