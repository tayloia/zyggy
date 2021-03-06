#if defined(ZYGGY_BEGUN)
#error "zyggy-begin.h" included twice without intervening "zyggy-end.h"
#endif
#define ZYGGY_BEGUN

#define ZYGGY_PLATFORM_MSVC 1
#define ZYGGY_PLATFORM_GCC 2

#if defined(_MSC_VER)

// Micrsoft Visual C++
#define ZYGGY_PLATFORM ZYGGY_PLATFORM_MSVC
// Keep windows.h inclusions to a minimum
#define WIN32_LEAN_AND_MEAN
// Disable overexuberant warnings:
// warning C4514: '...': unreferenced function has been removed
// warning C4571: Informational: catch(...) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught
// warning C4710: '...': function not inlined
// warning C4711: function '...' selected for automatic expansion
// warning C4820 : '...' : '...' bytes padding added after data member '...'
// warning C5031: #pragma warning(pop): likely mismatch, popping warning state pushed in different file
// warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
#pragma warning(disable: 4514 4571 4710 4711 4820 5031 5045)
// Prepare to include some system headers with lower warning levels here
#pragma warning(push)
// warning C4365: 'argument': conversion from '...' to '...', signed/unsigned mismatch
// warning C4623: '...': default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
// warning C4625: '...': copy constructor was implicitly defined as deleted
// warning C4626: '...': assignment operator was implicitly defined as deleted
// warning C4774: '...' : format string expected in argument 1 is not a string literal
// warning C5026: '...': move constructor was implicitly defined as deleted
// warning C5027: '...': move assignment operator was implicitly defined as deleted
#pragma warning(disable: 4365 4623 4625 4626 4774 5026 5027)

#elif defined(__GNUC__)

// GNU GCC
#define ZYGGY_PLATFORM ZYGGY_PLATFORM_GCC

// See https://stackoverflow.com/a/16472469
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

#else

// We need to add a new section for this compiler
#error Unknown platform

#endif
