#include "common_private_pch.h"
#include <cwchar>

//int ustrcmp(wchar_t const*, wchar_t const*)
//unsigned int ustrlen(wchar_t const *)

size_t ustrnlen(wchar_t const* string, size_t count)
{
    assert(string != NULL);

    return wcsnlen(string, count);
}

//wchar_t const * ustrchr(wchar_t const *,wchar_t)
//int ustrcoll(wchar_t const *,wchar_t const *)
//unsigned int ustrcspn(wchar_t const *,wchar_t const *)

wchar_t* ustrnzcat(wchar_t* dest, wchar_t const* src, size_t count)
{
    wcsncat_s(dest, count - 1, src, count);
    return dest;
}

//int ustrncmp(wchar_t const *,wchar_t const *,long)
//wchar_t * ustrncpy(wchar_t *,wchar_t const *,long)

wchar_t* ustrnzcpy(wchar_t* dest, wchar_t const* src, size_t count)
{
    assert(dest != NULL);
    assert(src != NULL);
    assert(count > 0);

    wcsncpy_s(dest, (count - 1) * 2, src, count);
    dest[count - 1] = 0;

    return dest;
}

//wchar_t const * ustrpbrk(wchar_t const *,wchar_t const *)
//wchar_t const * ustrrchr(wchar_t const *,wchar_t)
//unsigned int ustrspn(wchar_t const *,wchar_t const *)
//wchar_t const * ustrstr(wchar_t const *,wchar_t const *)
//wchar_t * ustrtok(wchar_t *,wchar_t const *)
//unsigned int ustrxfrm(wchar_t *,wchar_t const *,long)
//wchar_t * ustrnlwr(wchar_t *,long)
//wchar_t * ustrnupr(wchar_t *,long)

//int ustricmp(wchar_t const* a1, wchar_t const* a2)

extern void wchar_string_to_ascii_string(wchar_t const* source, char* destination, size_t* destination_length)
{
    mbstate_t state;
    wcsrtombs(destination, &source, *destination_length, &state);
}

extern void ascii_string_to_wchar_string(char const* source, wchar_t* destination, size_t* destination_length)
{
    mbstate_t state;
    mbsrtowcs(destination, &source, *destination_length, &state);
}

int usnzprintf(wchar_t* string, size_t size, wchar_t const* format, ...)
{
    va_list list;
    va_start(list, format);

    int result = uvsnzprintf(string, size, format, list);

    va_end(list);
    return result;
}

//int uvfprintf(struct _iobuf *,wchar_t const *,char *)
//int uvprintf(wchar_t const *,char *)

int uvsnzprintf(wchar_t* string, size_t size, wchar_t const* format, va_list list)
{
    assert(string && format);
    assert(size > 0);

    int result = _vsnwprintf_s(string, size, size - 1, format, list);
    string[size - 1] = 0;

    return result;
}

//struct _iobuf * ufdopen(int,wchar_t const *)
//struct _iobuf * ufopen(wchar_t const *,wchar_t const *)
//int ufclose(struct _iobuf *)
//struct _iobuf * ufreopen(wchar_t const *,wchar_t const *,struct _iobuf *)
//void uperror(wchar_t const *)
//int uremove(wchar_t const *)
//wchar_t * utmpnam(wchar_t *)
//long ustrtol(wchar_t const *,wchar_t * *,int)
//unsigned long ustrtoul(wchar_t const *,wchar_t * *,int)
//double ustrtod(wchar_t const *,wchar_t * *)
//wchar_t * ustrftime_tm(wchar_t *,long,wchar_t const *,struct tm const *)
//wchar_t * ustrftime(wchar_t *,long,wchar_t const *,__int64)
//int uatoi(wchar_t const *)

//void wchar_string_to_ascii_string(wchar_t const* source, char* destination, long source_length, long* destination_length)

//struct utf32 ascii_string_to_utf32_characters(char const *,struct s_escape_table const *,char const * *,long *,struct utf32 *,long,long *)
//struct utf32 wchar_string_to_utf32_characters(wchar_t const *,struct s_escape_table const *,wchar_t const * *,long *,struct utf32 *,long,long *)
//void ascii_string_to_utf32_string(char const *,struct s_escape_table const *,struct utf32 *,long,long *)
//void wchar_string_to_utf32_string(wchar_t const *,struct s_escape_table const *,struct utf32 *,long,long *)
//void ascii_string_to_wchar_string(char const *,wchar_t *,long,long *)
//long utf32_character_to_utf16_string(struct utf32,struct utf16 *,long)
//struct utf32 utf16_string_to_utf32_character(struct utf16 const *,struct utf16 const * *)
//bool utf32_in_list(struct utf32,struct s_utf32_range const *,long)
//bool utf32_isspace(struct utf32)
//bool utf32_is_id_start(struct utf32)
//bool utf32_is_id_continue(struct utf32)
//bool utf32_isalpha(struct utf32)
//bool utf32_isprint(struct utf32)
//bool utf32_ismonochrome(struct utf32)
//bool utf32_can_line_break(struct utf32,struct utf32)
//unsigned int utf32_strlen(struct utf32 const *)
//bool is_private_use_character(wchar_t)
//void utf8_string_to_wchar_string(struct utf8 const *,wchar_t *,long,long *)
//void wchar_string_to_utf8_string(wchar_t const *,struct utf8 *,long,long *)
//void string_to_utf32_string<char,8>(char const *,struct s_escape_table const *,struct utf32 *,struct utf32 (*)(char const *,struct s_escape_table const *,char const * *,long *,struct utf32 *,long,long *),long,long *)
//void string_to_utf32_string<wchar_t,8>(wchar_t const *,struct s_escape_table const *,struct utf32 *,struct utf32 (*)(wchar_t const *,struct s_escape_table const *,wchar_t const * *,long *,struct utf32 *,long,long *),long,long *)
