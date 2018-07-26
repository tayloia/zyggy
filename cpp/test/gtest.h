#if ZYGGY_PLATFORM == ZYGGY_PLATFORM_MSVC

// GoogleTest needs a much lower warning level under MSVC
#pragma warning(push, 3)
#include "gtest/gtest.h"
#pragma warning(pop)

#else

#include "gtest/gtest.h"

#endif
