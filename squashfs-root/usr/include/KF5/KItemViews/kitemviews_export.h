
#ifndef KITEMVIEWS_EXPORT_H
#define KITEMVIEWS_EXPORT_H

#ifdef KITEMVIEWS_STATIC_DEFINE
#  define KITEMVIEWS_EXPORT
#  define KITEMVIEWS_NO_EXPORT
#else
#  ifndef KITEMVIEWS_EXPORT
#    ifdef KF5ItemViews_EXPORTS
        /* We are building this library */
#      define KITEMVIEWS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define KITEMVIEWS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef KITEMVIEWS_NO_EXPORT
#    define KITEMVIEWS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef KITEMVIEWS_DECL_DEPRECATED
#  define KITEMVIEWS_DECL_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef KITEMVIEWS_DECL_DEPRECATED_EXPORT
#  define KITEMVIEWS_DECL_DEPRECATED_EXPORT KITEMVIEWS_EXPORT KITEMVIEWS_DECL_DEPRECATED
#endif

#ifndef KITEMVIEWS_DECL_DEPRECATED_NO_EXPORT
#  define KITEMVIEWS_DECL_DEPRECATED_NO_EXPORT KITEMVIEWS_NO_EXPORT KITEMVIEWS_DECL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef KITEMVIEWS_NO_DEPRECATED
#    define KITEMVIEWS_NO_DEPRECATED
#  endif
#endif

#define KITEMVIEWS_DECL_DEPRECATED_TEXT(text) __attribute__ ((__deprecated__(text)))

#define ECM_GENERATEEXPORTHEADER_VERSION_VALUE(major, minor, patch) ((major<<16)|(minor<<8)|(patch))

/* Take any defaults from group settings */
#if !defined(KITEMVIEWS_NO_DEPRECATED) && !defined(KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT)
#  ifdef KF_NO_DEPRECATED
#    define KITEMVIEWS_NO_DEPRECATED
#  elif defined(KF_DISABLE_DEPRECATED_BEFORE_AND_AT)
#    define KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT KF_DISABLE_DEPRECATED_BEFORE_AND_AT
#  endif
#endif
#if !defined(KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT) && defined(KF_DISABLE_DEPRECATED_BEFORE_AND_AT)
#  define KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT KF_DISABLE_DEPRECATED_BEFORE_AND_AT
#endif

#if !defined(KITEMVIEWS_NO_DEPRECATED_WARNINGS) && !defined(KITEMVIEWS_DEPRECATED_WARNINGS_SINCE)
#  ifdef KF_NO_DEPRECATED_WARNINGS
#    define KITEMVIEWS_NO_DEPRECATED_WARNINGS
#  elif defined(KF_DEPRECATED_WARNINGS_SINCE)
#    define KITEMVIEWS_DEPRECATED_WARNINGS_SINCE KF_DEPRECATED_WARNINGS_SINCE
#  endif
#endif
#if !defined(KITEMVIEWS_DEPRECATED_WARNINGS_SINCE) && defined(KF_DEPRECATED_WARNINGS_SINCE)
#  define KITEMVIEWS_DEPRECATED_WARNINGS_SINCE KF_DEPRECATED_WARNINGS_SINCE
#endif

#if defined(KITEMVIEWS_NO_DEPRECATED)
#  undef KITEMVIEWS_DEPRECATED
#  define KITEMVIEWS_DEPRECATED_EXPORT KITEMVIEWS_EXPORT
#  define KITEMVIEWS_DEPRECATED_NO_EXPORT KITEMVIEWS_NO_EXPORT
#elif defined(KITEMVIEWS_NO_DEPRECATED_WARNINGS)
#  define KITEMVIEWS_DEPRECATED
#  define KITEMVIEWS_DEPRECATED_EXPORT KITEMVIEWS_EXPORT
#  define KITEMVIEWS_DEPRECATED_NO_EXPORT KITEMVIEWS_NO_EXPORT
#else
#  define KITEMVIEWS_DEPRECATED KITEMVIEWS_DECL_DEPRECATED
#  define KITEMVIEWS_DEPRECATED_EXPORT KITEMVIEWS_DECL_DEPRECATED_EXPORT
#  define KITEMVIEWS_DEPRECATED_NO_EXPORT KITEMVIEWS_DECL_DEPRECATED_NO_EXPORT
#endif

/* No deprecated API had been removed from build */
#define KITEMVIEWS_EXCLUDE_DEPRECATED_BEFORE_AND_AT 0

#define KITEMVIEWS_BUILD_DEPRECATED_SINCE(major, minor) 1

#ifdef KITEMVIEWS_NO_DEPRECATED
#  define KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT 344064
#endif
#ifdef KITEMVIEWS_NO_DEPRECATED_WARNINGS
#  define KITEMVIEWS_DEPRECATED_WARNINGS_SINCE 0
#endif

#ifndef KITEMVIEWS_DEPRECATED_WARNINGS_SINCE
#  ifdef KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT
#    define KITEMVIEWS_DEPRECATED_WARNINGS_SINCE KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT
#  else
#    define KITEMVIEWS_DEPRECATED_WARNINGS_SINCE 344064
#  endif
#endif

#ifndef KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT
#  define KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT 0
#endif

#ifdef KITEMVIEWS_DEPRECATED
#  define KITEMVIEWS_ENABLE_DEPRECATED_SINCE(major, minor) (ECM_GENERATEEXPORTHEADER_VERSION_VALUE(major, minor, 0) > KITEMVIEWS_DISABLE_DEPRECATED_BEFORE_AND_AT)
#else
#  define KITEMVIEWS_ENABLE_DEPRECATED_SINCE(major, minor) 0
#endif

#if KITEMVIEWS_DEPRECATED_WARNINGS_SINCE >= 262656
#  define KITEMVIEWS_DEPRECATED_VERSION_4_2(text) KITEMVIEWS_DECL_DEPRECATED_TEXT(text)
#else
#  define KITEMVIEWS_DEPRECATED_VERSION_4_2(text)
#endif

#if KITEMVIEWS_DEPRECATED_WARNINGS_SINCE >= 263168
#  define KITEMVIEWS_DEPRECATED_VERSION_4_4(text) KITEMVIEWS_DECL_DEPRECATED_TEXT(text)
#else
#  define KITEMVIEWS_DEPRECATED_VERSION_4_4(text)
#endif

#if KITEMVIEWS_DEPRECATED_WARNINGS_SINCE >= 327680
#  define KITEMVIEWS_DEPRECATED_VERSION_5_0(text) KITEMVIEWS_DECL_DEPRECATED_TEXT(text)
#else
#  define KITEMVIEWS_DEPRECATED_VERSION_5_0(text)
#endif

#if KITEMVIEWS_DEPRECATED_WARNINGS_SINCE >= 340480
#  define KITEMVIEWS_DEPRECATED_VERSION_5_50(text) KITEMVIEWS_DECL_DEPRECATED_TEXT(text)
#else
#  define KITEMVIEWS_DEPRECATED_VERSION_5_50(text)
#endif
#define KITEMVIEWS_DEPRECATED_VERSION_4(minor, text)      KITEMVIEWS_DEPRECATED_VERSION_4_##minor(text)
#define KITEMVIEWS_DEPRECATED_VERSION_5(minor, text)      KITEMVIEWS_DEPRECATED_VERSION_5_##minor(text)
#define KITEMVIEWS_DEPRECATED_VERSION(major, minor, text) KITEMVIEWS_DEPRECATED_VERSION_##major(minor, "Since "#major"."#minor". " text)

#endif
