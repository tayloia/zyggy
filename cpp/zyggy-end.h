#if !defined(ZYGGY_BEGUN)
#error "zyggy-end.h" included without preceding "zyggy-begin.h"
#endif
#undef ZYGGY_BEGUN

#if ZYGGY_PLATFORM == ZYGGY_PLATFORM_MSVC
#pragma warning(pop)
#endif
