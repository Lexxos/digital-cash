// Public Resource ℗ 2021 Satoshi Nakamoto
// Public Resource ℗ 2021 𝖡𝗂𝗍𝖼𝗈𝗂𝗇 𝖣𝖾𝗏𝖾𝗅𝗈𝗉𝖾𝗋𝗌
// Public Resource ℗ 2020 𝖠𝗆𝖾𝗋𝗈 𝖣𝖾𝗏𝖾𝗅𝗈𝗉𝖾𝗋𝗌
// THIS REPOSITORY IS LICENSED UNDER THE AMERO PUBLIC RESOURCE LICENSE.

#include <support/cleanse.h>

#include <cstring>

#if defined(_MSC_VER)
#include <Windows.h> // For SecureZeroMemory.
#endif

/* Compilers have a bad habit of removing "superfluous" memset calls that
 * are trying to zero memory. For example, when memset()ing a buffer and
 * then free()ing it, the compiler might decide that the memset is
 * unobservable and thus can be removed.
 *
 * Previously we used OpenSSL which tried to stop this by a) implementing
 * memset in assembly on x86 and b) putting the function in its own file
 * for other platforms.
 *
 * This change removes those tricks in favour of using asm directives to
 * scare the compiler away. As best as our compiler folks can tell, this is
 * sufficient and will continue to be so.
 *
 * Adam Langley <agl@google.com>
 * Commit: ad1907fe73334d6c696c8539646c21b11178f20f
 * BoringSSL (LICENSE: ISC)
 */
void memory_cleanse(void *ptr, size_t len)
{
    std::memset(ptr, 0, len);

    /* As best as we can tell, this is sufficient to break any optimisations that
       might try to eliminate "superfluous" memsets. If there's an easy way to
       detect memset_s, it would be better to use that. */
#if defined(_MSC_VER)
    SecureZeroMemory(ptr, len);
#else
    __asm__ __volatile__("" : : "r"(ptr) : "memory");
#endif
}
