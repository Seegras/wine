/*
 * Unicode definitions
 *
 * Derived from the mingw header written by Colin Peters.
 * Modified for Wine use by Jon Griffiths and Francois Gouget.
 * This file is in the public domain.
 */
#ifndef __WINE_WCHAR_H
#define __WINE_WCHAR_H

#include <corecrt_wstdio.h>
#include <corecrt_wio.h>
#include <string.h>

#include <pshpack8.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WCHAR_MIN  /* also in stdint.h */
#define WCHAR_MIN 0U
#define WCHAR_MAX 0xffffU
#endif

#ifndef DECLSPEC_ALIGN
# if defined(_MSC_VER) && (_MSC_VER >= 1300) && !defined(MIDL_PASS)
#  define DECLSPEC_ALIGN(x) __declspec(align(x))
# elif defined(__GNUC__)
#  define DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
# else
#  define DECLSPEC_ALIGN(x)
# endif
#endif

typedef int mbstate_t;

#ifndef _DEV_T_DEFINED
typedef unsigned int   _dev_t;
#define _DEV_T_DEFINED
#endif

#ifndef _INO_T_DEFINED
typedef unsigned short _ino_t;
#define _INO_T_DEFINED
#endif

#ifndef _OFF_T_DEFINED
typedef int _off_t;
#define _OFF_T_DEFINED
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};
#endif /* _TM_DEFINED */

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

struct _stat {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct stat {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct _stat32 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  __time32_t st_atime;
  __time32_t st_mtime;
  __time32_t st_ctime;
};

struct _stat32i64 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  _dev_t st_rdev;
  __int64 DECLSPEC_ALIGN(8) st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct _stat64i32 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  __time64_t st_atime;
  __time64_t st_mtime;
  __time64_t st_ctime;
};

struct _stati64 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  __int64 DECLSPEC_ALIGN(8) st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct _stat64 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  __int64 DECLSPEC_ALIGN(8) st_size;
  __time64_t     st_atime;
  __time64_t     st_mtime;
  __time64_t     st_ctime;
};
#endif /* _STAT_DEFINED */

/* ASCII char classification table - binary compatible */
#define _UPPER        0x0001  /* C1_UPPER */
#define _LOWER        0x0002  /* C1_LOWER */
#define _DIGIT        0x0004  /* C1_DIGIT */
#define _SPACE        0x0008  /* C1_SPACE */
#define _PUNCT        0x0010  /* C1_PUNCT */
#define _CONTROL      0x0020  /* C1_CNTRL */
#define _BLANK        0x0040  /* C1_BLANK */
#define _HEX          0x0080  /* C1_XDIGIT */
#define _LEADBYTE     0x8000
#define _ALPHA       (0x0100|_UPPER|_LOWER)  /* (C1_ALPHA|_UPPER|_LOWER) */

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED
int     __cdecl is_wctype(wint_t,wctype_t);
int     __cdecl isleadbyte(int);
int     __cdecl iswalnum(wint_t);
int     __cdecl iswalpha(wint_t);
int     __cdecl iswascii(wint_t);
int     __cdecl iswcntrl(wint_t);
int     __cdecl iswctype(wint_t,wctype_t);
int     __cdecl iswdigit(wint_t);
int     __cdecl iswgraph(wint_t);
int     __cdecl iswlower(wint_t);
int     __cdecl iswprint(wint_t);
int     __cdecl iswpunct(wint_t);
int     __cdecl iswspace(wint_t);
int     __cdecl iswupper(wint_t);
int     __cdecl iswxdigit(wint_t);
wchar_t __cdecl towlower(wchar_t);
wchar_t __cdecl towupper(wchar_t);
#endif /* _WCTYPE_DEFINED */

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
int      __cdecl _wchdir(const wchar_t*);
wchar_t* __cdecl _wgetcwd(wchar_t*,int);
wchar_t* __cdecl _wgetdcwd(int,wchar_t*,int);
int      __cdecl _wmkdir(const wchar_t*);
int      __cdecl _wrmdir(const wchar_t*);
#endif /* _WDIRECT_DEFINED */

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
wchar_t* __cdecl _wsetlocale(int,const wchar_t*);
#endif /* _WLOCALE_DEFINED */

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
int      WINAPIV _wexecl(const wchar_t*,const wchar_t*,...);
int      WINAPIV _wexecle(const wchar_t*,const wchar_t*,...);
int      WINAPIV _wexeclp(const wchar_t*,const wchar_t*,...);
int      WINAPIV _wexeclpe(const wchar_t*,const wchar_t*,...);
int      __cdecl _wexecv(const wchar_t*,const wchar_t* const *);
int      __cdecl _wexecve(const wchar_t*,const wchar_t* const *,const wchar_t* const *);
int      __cdecl _wexecvp(const wchar_t*,const wchar_t* const *);
int      __cdecl _wexecvpe(const wchar_t*,const wchar_t* const *,const wchar_t* const *);
int      WINAPIV _wspawnl(int,const wchar_t*,const wchar_t*,...);
int      WINAPIV _wspawnle(int,const wchar_t*,const wchar_t*,...);
int      WINAPIV _wspawnlp(int,const wchar_t*,const wchar_t*,...);
int      WINAPIV _wspawnlpe(int,const wchar_t*,const wchar_t*,...);
int      __cdecl _wspawnv(int,const wchar_t*,const wchar_t* const *);
int      __cdecl _wspawnve(int,const wchar_t*,const wchar_t* const *,const wchar_t* const *);
int      __cdecl _wspawnvp(int,const wchar_t*,const wchar_t* const *);
int      __cdecl _wspawnvpe(int,const wchar_t*,const wchar_t* const *,const wchar_t* const *);
int      __cdecl _wsystem(const wchar_t*);
#endif /* _WPROCESS_DEFINED */

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED
int __cdecl _wstat(const wchar_t*,struct _stat*);
int __cdecl _wstat32(const wchar_t*, struct _stat32*);
int __cdecl _wstati64(const wchar_t*,struct _stati64*);
int __cdecl _wstat64(const wchar_t*,struct _stat64*);
#endif /* _WSTAT_DEFINED */

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED
wchar_t* __cdecl _itow(int,wchar_t*,int);
errno_t  __cdecl _itow_s(int,wchar_t*,int, int);
wchar_t* __cdecl _i64tow(__int64,wchar_t*,int);
errno_t  __cdecl _i64tow_s(__int64, wchar_t*, size_t, int);
wchar_t* __cdecl _ltow(__msvcrt_long,wchar_t*,int);
errno_t  __cdecl _ltow_s(__msvcrt_long,wchar_t*,int,int);
wchar_t* __cdecl _ui64tow(unsigned __int64,wchar_t*,int);
errno_t  __cdecl _ui64tow_s(unsigned __int64, wchar_t*, size_t, int);
wchar_t* __cdecl _ultow(__msvcrt_ulong,wchar_t*,int);
errno_t  __cdecl _ultow_s(__msvcrt_ulong, wchar_t*, size_t, int);
wchar_t* __cdecl _wfullpath(wchar_t*,const wchar_t*,size_t);
wchar_t* __cdecl _wgetenv(const wchar_t*);
void     __cdecl _wmakepath(wchar_t*,const wchar_t*,const wchar_t*,const wchar_t*,const wchar_t*);
int      __cdecl _wmakepath_s(wchar_t*,size_t,const wchar_t*,const wchar_t*,const wchar_t*,const wchar_t*);
void     __cdecl _wperror(const wchar_t*);
int      __cdecl _wputenv(const wchar_t*);
void     __cdecl _wsearchenv(const wchar_t*,const wchar_t*,wchar_t*);
void     __cdecl _wsplitpath(const wchar_t*,wchar_t*,wchar_t*,wchar_t*,wchar_t*);
errno_t  __cdecl _wsplitpath_s(const wchar_t*,wchar_t*,size_t,wchar_t*,size_t,
                                   wchar_t*,size_t,wchar_t*,size_t);
int      __cdecl _wsystem(const wchar_t*);
double   __cdecl _wtof(const wchar_t*);
int      __cdecl _wtoi(const wchar_t*);
__int64  __cdecl _wtoi64(const wchar_t*);
__msvcrt_long __cdecl _wtol(const wchar_t*);

size_t        __cdecl mbstowcs(wchar_t*,const char*,size_t);
errno_t       __cdecl mbstowcs_s(size_t*,wchar_t*,size_t,const char*,size_t);
int           __cdecl mbtowc(wchar_t*,const char*,size_t);
float         __cdecl wcstof(const wchar_t*,wchar_t**);
double        __cdecl wcstod(const wchar_t*,wchar_t**);
__msvcrt_long __cdecl wcstol(const wchar_t*,wchar_t**,int);
size_t        __cdecl wcstombs(char*,const wchar_t*,size_t);
errno_t       __cdecl wcstombs_s(size_t*,char*,size_t,const wchar_t*,size_t);
__msvcrt_ulong __cdecl wcstoul(const wchar_t*,wchar_t**,int);
int           __cdecl wctomb(char*,wchar_t);
#endif /* _WSTDLIB_DEFINED */

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
int      __cdecl _wcscoll_l(const wchar_t*,const wchar_t*,_locale_t);
wchar_t* __cdecl _wcsdup(const wchar_t*);
int      __cdecl _wcsicmp(const wchar_t*,const wchar_t*);
int      __cdecl _wcsicoll(const wchar_t*,const wchar_t*);
int      __cdecl _wcsicoll_l(const wchar_t*,const wchar_t*,_locale_t);
wchar_t* __cdecl _wcslwr(wchar_t*);
errno_t  __cdecl _wcslwr_s(wchar_t*, size_t);
int      __cdecl _wcsncoll(const wchar_t*,const wchar_t*,size_t);
int      __cdecl _wcsncoll_l(const wchar_t*,const wchar_t*,size_t,_locale_t);
int      __cdecl _wcsnicmp(const wchar_t*,const wchar_t*,size_t);
int      __cdecl _wcsnicoll(const wchar_t*,const wchar_t*,size_t);
int      __cdecl _wcsnicoll_l(const wchar_t*,const wchar_t*,size_t,_locale_t);
wchar_t* __cdecl _wcsnset(wchar_t*,wchar_t,size_t);
wchar_t* __cdecl _wcsrev(wchar_t*);
wchar_t* __cdecl _wcsset(wchar_t*,wchar_t);
wchar_t* __cdecl _wcsupr(wchar_t*);
errno_t  __cdecl _wcsupr_s(wchar_t*, size_t);

wchar_t* __cdecl wcscat(wchar_t*,const wchar_t*);
errno_t  __cdecl wcscat_s(wchar_t*,size_t,const wchar_t*);
wchar_t* __cdecl wcschr(const wchar_t*,wchar_t);
int      __cdecl wcscmp(const wchar_t*,const wchar_t*);
int      __cdecl wcscoll(const wchar_t*,const wchar_t*);
wchar_t* __cdecl wcscpy(wchar_t*,const wchar_t*);
errno_t  __cdecl wcscpy_s(wchar_t*,size_t,const wchar_t*);
size_t   __cdecl wcscspn(const wchar_t*,const wchar_t*);
size_t   __cdecl wcslen(const wchar_t*);
wchar_t* __cdecl wcsncat(wchar_t*,const wchar_t*,size_t);
errno_t  __cdecl wcsncat_s(wchar_t *, size_t, const wchar_t *, size_t);
int      __cdecl wcsncmp(const wchar_t*,const wchar_t*,size_t);
wchar_t* __cdecl wcsncpy(wchar_t*,const wchar_t*,size_t);
errno_t  __cdecl wcsncpy_s(wchar_t*,size_t,const wchar_t*,size_t);
size_t   __cdecl wcsnlen(const size_t*,size_t);
wchar_t* __cdecl wcspbrk(const wchar_t*,const wchar_t*);
wchar_t* __cdecl wcsrchr(const wchar_t*,wchar_t wcFor);
size_t   __cdecl wcsspn(const wchar_t*,const wchar_t*);
wchar_t* __cdecl wcsstr(const wchar_t*,const wchar_t*);
wchar_t* __cdecl wcstok(wchar_t*,const wchar_t*);
size_t   __cdecl wcsxfrm(wchar_t*,const wchar_t*,size_t);
#endif /* _WSTRING_DEFINED */

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

#ifdef _USE_32BIT_TIME_T
#define _wctime32 _wctime
#endif

wchar_t* __cdecl _wasctime(const struct tm*);
size_t   __cdecl wcsftime(wchar_t*,size_t,const wchar_t*,const struct tm*);
wchar_t* __cdecl _wctime32(const __time32_t*);
wchar_t* __cdecl _wctime64(const __time64_t*);
wchar_t* __cdecl _wstrdate(wchar_t*);
errno_t  __cdecl _wstrdate_s(wchar_t*,size_t);
wchar_t* __cdecl _wstrtime(wchar_t*);
errno_t  __cdecl _wstrtime_s(wchar_t*,size_t);

#ifndef _USE_32BIT_TIME_T
static inline wchar_t* _wctime(const time_t *t) { return _wctime64(t); }
#endif

#endif /* _WTIME_DEFINED */

wchar_t __cdecl btowc(int);
size_t  __cdecl mbrlen(const char *,size_t,mbstate_t*);
size_t  __cdecl mbrtowc(wchar_t*,const char*,size_t,mbstate_t*);
size_t  __cdecl mbsrtowcs(wchar_t*,const char**,size_t,mbstate_t*);
size_t  __cdecl wcrtomb(char*,wchar_t,mbstate_t*);
size_t  __cdecl wcsrtombs(char*,const wchar_t**,size_t,mbstate_t*);
int     __cdecl wctob(wint_t);
errno_t __cdecl wmemcpy_s(wchar_t *, size_t, const wchar_t *, size_t);

static inline wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n)
{
    const wchar_t *end;
    for (end = s + n; s < end; s++)
        if (*s == c) return (wchar_t*)s;
    return NULL;
}

static inline int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
    {
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return -1;
    }
    return 0;
}

static inline wchar_t* __cdecl wmemcpy(wchar_t *dst, const wchar_t *src, size_t n)
{
    return (wchar_t*)memcpy(dst, src, n * sizeof(wchar_t));
}

static inline wchar_t* __cdecl wmemmove(wchar_t *dst, const wchar_t *src, size_t n)
{
    return (wchar_t*)memmove(dst, src, n * sizeof(wchar_t));
}

static inline wchar_t* __cdecl wmemset(wchar_t *s, wchar_t c, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
        s[i] = c;
    return s;
}

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif /* __WINE_WCHAR_H */
