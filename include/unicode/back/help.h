//
// Created by steve on 8/2/15.
//

#ifndef UIMACPP_HELP_H
#define UIMACPP_HELP_H

#include "unicode/rep.h"


/**
 * NUL-terminate a string no matter what its type.
 * Set warning and error codes accordingly.
 */
#define __TERMINATE_STRING(dest, destCapacity, length, pErrorCode)      \
    if(pErrorCode!=NULL && U_SUCCESS(*pErrorCode)) {                    \
        /* not a public function, so no complete argument checking */   \
                                                                        \
        if(length<0) {                                                  \
            /* assume that the caller handles this */                   \
        } else if(length<destCapacity) {                                \
            /* NUL-terminate the string, the NUL fits */                \
            dest[length]=0;                                             \
            /* unset the not-terminated warning but leave all others */ \
            if(*pErrorCode==U_STRING_NOT_TERMINATED_WARNING) {          \
                *pErrorCode=U_ZERO_ERROR;                               \
            }                                                           \
        } else if(length==destCapacity) {                               \
            /* unable to NUL-terminate, but the string itself fit - set a warning code */ \
            *pErrorCode=U_STRING_NOT_TERMINATED_WARNING;                \
        } else /* length>destCapacity */ {                              \
            /* even the string itself did not fit - set an error code */ \
            *pErrorCode=U_BUFFER_OVERFLOW_ERROR;                        \
        }                                                               \
    }


U_CAPI int32_t   U_EXPORT2 inline
u_strncmp(const UChar     *s1,
          const UChar     *s2,
          int32_t     n)
{
    if(n > 0) {
        int32_t rc;
        for(;;) {
            rc = (int32_t)*s1 - (int32_t)*s2;
            if(rc != 0 || *s1 == 0 || --n == 0) {
                return rc;
            }
            ++s1;
            ++s2;
        }
    } else {
        return 0;
    }
}


U_CAPI int32_t U_EXPORT2 inline
u_terminateChars(char *dest, int32_t destCapacity, int32_t length, UErrorCode *pErrorCode) {
    __TERMINATE_STRING(dest, destCapacity, length, pErrorCode);
    return length;
}


static U_INLINE uint8_t *
_appendUTF8(uint8_t *pDest, UChar32 c) {
    /* it is 0<=c<=0x10ffff and not a surrogate if called by a validating function */
    if((c)<=0x7f) {
        *pDest++=(uint8_t)c;
    } else if(c<=0x7ff) {
        *pDest++=(uint8_t)((c>>6)|0xc0);
        *pDest++=(uint8_t)((c&0x3f)|0x80);
    } else if(c<=0xffff) {
        *pDest++=(uint8_t)((c>>12)|0xe0);
        *pDest++=(uint8_t)(((c>>6)&0x3f)|0x80);
        *pDest++=(uint8_t)(((c)&0x3f)|0x80);
    } else /* if((uint32_t)(c)<=0x10ffff) */ {
        *pDest++=(uint8_t)(((c)>>18)|0xf0);
        *pDest++=(uint8_t)((((c)>>12)&0x3f)|0x80);
        *pDest++=(uint8_t)((((c)>>6)&0x3f)|0x80);
        *pDest++=(uint8_t)(((c)&0x3f)|0x80);
    }
    return pDest;
}


U_CAPI inline char* U_EXPORT2
u_strToUTF8WithSub(char *dest,
            int32_t destCapacity,
            int32_t *pDestLength,
            const UChar *pSrc,
            int32_t srcLength,
            UChar32 subchar, int32_t *pNumSubstitutions,
            UErrorCode *pErrorCode){

    int32_t reqLength=0;
    uint32_t ch=0,ch2=0;
    uint8_t *pDest = (uint8_t *)dest;
    uint8_t *pDestLimit = pDest + destCapacity;
    int32_t numSubstitutions;

    /* args check */
    if(pErrorCode==NULL || U_FAILURE(*pErrorCode)){
        return NULL;
    }

    if( (pSrc==NULL) || (srcLength < -1) || (destCapacity<0) || (!dest && destCapacity > 0) ||
        subchar > 0x10ffff || U_IS_SURROGATE(subchar)
    ) {
        *pErrorCode = U_ILLEGAL_ARGUMENT_ERROR;
        return NULL;
    }

    numSubstitutions=0;

    if(srcLength==-1) {
        while((ch=*pSrc)!=0) {
            ++pSrc;
            if(ch <= 0x7f) {
                if(pDest<pDestLimit) {
                    *pDest++ = (char)ch;
                } else {
                    reqLength = 1;
                    break;
                }
            } else if(ch <= 0x7ff) {
                if((pDestLimit - pDest) >= 2) {
                    *pDest++=(uint8_t)((ch>>6)|0xc0);
                    *pDest++=(uint8_t)((ch&0x3f)|0x80);
                } else {
                    reqLength = 2;
                    break;
                }
            } else if(ch <= 0xd7ff || ch >= 0xe000) {
                if((pDestLimit - pDest) >= 3) {
                    *pDest++=(uint8_t)((ch>>12)|0xe0);
                    *pDest++=(uint8_t)(((ch>>6)&0x3f)|0x80);
                    *pDest++=(uint8_t)((ch&0x3f)|0x80);
                } else {
                    reqLength = 3;
                    break;
                }
            } else /* ch is a surrogate */ {
                int32_t length;

                /*need not check for NUL because NUL fails UTF_IS_TRAIL() anyway*/
                if(UTF_IS_SURROGATE_FIRST(ch) && UTF_IS_TRAIL(ch2=*pSrc)) {
                    ++pSrc;
                    ch=UTF16_GET_PAIR_VALUE(ch, ch2);
                } else if(subchar>=0) {
                    ch=subchar;
                    ++numSubstitutions;
                } else {
                    /* Unicode 3.2 forbids surrogate code points in UTF-8 */
                    *pErrorCode = U_INVALID_CHAR_FOUND;
                    return NULL;
                }

                length = U8_LENGTH(ch);
                if((pDestLimit - pDest) >= length) {
                    /* convert and append*/
                    pDest=_appendUTF8(pDest, ch);
                } else {
                    reqLength = length;
                    break;
                }
            }
        }
        while((ch=*pSrc++)!=0) {
            if(ch<=0x7f) {
                ++reqLength;
            } else if(ch<=0x7ff) {
                reqLength+=2;
            } else if(!UTF_IS_SURROGATE(ch)) {
                reqLength+=3;
            } else if(UTF_IS_SURROGATE_FIRST(ch) && UTF_IS_TRAIL(ch2=*pSrc)) {
                ++pSrc;
                reqLength+=4;
            } else if(subchar>=0) {
                reqLength+=U8_LENGTH(subchar);
                ++numSubstitutions;
            } else {
                /* Unicode 3.2 forbids surrogate code points in UTF-8 */
                *pErrorCode = U_INVALID_CHAR_FOUND;
                return NULL;
            }
        }
    } else {
        const UChar *pSrcLimit = pSrc+srcLength;
        int32_t count;

        /* Faster loop without ongoing checking for pSrcLimit and pDestLimit. */
        for(;;) {
            /*
             * Each iteration of the inner loop progresses by at most 3 UTF-8
             * bytes and one UChar, for most characters.
             * For supplementary code points (4 & 2), which are rare,
             * there is an additional adjustment.
             */
            count = (int32_t)((pDestLimit - pDest) / 3);
            srcLength = (int32_t)(pSrcLimit - pSrc);
            if(count > srcLength) {
                count = srcLength; /* min(remaining dest/3, remaining src) */
            }
            if(count < 3) {
                /*
                 * Too much overhead if we get near the end of the string,
                 * continue with the next loop.
                 */
                break;
            }
            do {
                ch=*pSrc++;
                if(ch <= 0x7f) {
                    *pDest++ = (char)ch;
                } else if(ch <= 0x7ff) {
                    *pDest++=(uint8_t)((ch>>6)|0xc0);
                    *pDest++=(uint8_t)((ch&0x3f)|0x80);
                } else if(ch <= 0xd7ff || ch >= 0xe000) {
                    *pDest++=(uint8_t)((ch>>12)|0xe0);
                    *pDest++=(uint8_t)(((ch>>6)&0x3f)|0x80);
                    *pDest++=(uint8_t)((ch&0x3f)|0x80);
                } else /* ch is a surrogate */ {
                    /*
                     * We will read two UChars and probably output four bytes,
                     * which we didn't account for with computing count,
                     * so we adjust it here.
                     */
                    if(--count == 0) {
                        --pSrc; /* undo ch=*pSrc++ for the lead surrogate */
                        break;  /* recompute count */
                    }

                    if(UTF_IS_SURROGATE_FIRST(ch) && UTF_IS_TRAIL(ch2=*pSrc)) {
                        ++pSrc;
                        ch=UTF16_GET_PAIR_VALUE(ch, ch2);

                        /* writing 4 bytes per 2 UChars is ok */
                        *pDest++=(uint8_t)((ch>>18)|0xf0);
                        *pDest++=(uint8_t)(((ch>>12)&0x3f)|0x80);
                        *pDest++=(uint8_t)(((ch>>6)&0x3f)|0x80);
                        *pDest++=(uint8_t)((ch&0x3f)|0x80);
                    } else  {
                        /* Unicode 3.2 forbids surrogate code points in UTF-8 */
                        if(subchar>=0) {
                            ch=subchar;
                            ++numSubstitutions;
                        } else {
                            *pErrorCode = U_INVALID_CHAR_FOUND;
                            return NULL;
                        }

                        /* convert and append*/
                        pDest=_appendUTF8(pDest, ch);
                    }
                }
            } while(--count > 0);
        }

        while(pSrc<pSrcLimit) {
            ch=*pSrc++;
            if(ch <= 0x7f) {
                if(pDest<pDestLimit) {
                    *pDest++ = (char)ch;
                } else {
                    reqLength = 1;
                    break;
                }
            } else if(ch <= 0x7ff) {
                if((pDestLimit - pDest) >= 2) {
                    *pDest++=(uint8_t)((ch>>6)|0xc0);
                    *pDest++=(uint8_t)((ch&0x3f)|0x80);
                } else {
                    reqLength = 2;
                    break;
                }
            } else if(ch <= 0xd7ff || ch >= 0xe000) {
                if((pDestLimit - pDest) >= 3) {
                    *pDest++=(uint8_t)((ch>>12)|0xe0);
                    *pDest++=(uint8_t)(((ch>>6)&0x3f)|0x80);
                    *pDest++=(uint8_t)((ch&0x3f)|0x80);
                } else {
                    reqLength = 3;
                    break;
                }
            } else /* ch is a surrogate */ {
                int32_t length;

                if(UTF_IS_SURROGATE_FIRST(ch) && pSrc<pSrcLimit && UTF_IS_TRAIL(ch2=*pSrc)) {
                    ++pSrc;
                    ch=UTF16_GET_PAIR_VALUE(ch, ch2);
                } else if(subchar>=0) {
                    ch=subchar;
                    ++numSubstitutions;
                } else {
                    /* Unicode 3.2 forbids surrogate code points in UTF-8 */
                    *pErrorCode = U_INVALID_CHAR_FOUND;
                    return NULL;
                }

                length = U8_LENGTH(ch);
                if((pDestLimit - pDest) >= length) {
                    /* convert and append*/
                    pDest=_appendUTF8(pDest, ch);
                } else {
                    reqLength = length;
                    break;
                }
            }
        }
        while(pSrc<pSrcLimit) {
            ch=*pSrc++;
            if(ch<=0x7f) {
                ++reqLength;
            } else if(ch<=0x7ff) {
                reqLength+=2;
            } else if(!UTF_IS_SURROGATE(ch)) {
                reqLength+=3;
            } else if(UTF_IS_SURROGATE_FIRST(ch) && pSrc<pSrcLimit && UTF_IS_TRAIL(ch2=*pSrc)) {
                ++pSrc;
                reqLength+=4;
            } else if(subchar>=0) {
                reqLength+=U8_LENGTH(subchar);
                ++numSubstitutions;
            } else {
                /* Unicode 3.2 forbids surrogate code points in UTF-8 */
                *pErrorCode = U_INVALID_CHAR_FOUND;
                return NULL;
            }
        }
    }

    reqLength+=(int32_t)(pDest - (uint8_t *)dest);

    if(pNumSubstitutions!=NULL) {
        *pNumSubstitutions=numSubstitutions;
    }

    if(pDestLength){
        *pDestLength = reqLength;
    }

    /* Terminate the buffer */
    u_terminateChars((char*)dest,destCapacity,reqLength,pErrorCode);

    return (char*)dest;
}

U_CAPI inline char* U_EXPORT2
u_strToUTF8(char *dest,
            int32_t destCapacity,
            int32_t *pDestLength,
            const UChar *pSrc,
            int32_t srcLength,
            UErrorCode *pErrorCode){
    return u_strToUTF8WithSub(
            dest, destCapacity, pDestLength,
            pSrc, srcLength,
            U_SENTINEL, NULL,
            pErrorCode);
}


U_CAPI int32_t   U_EXPORT2 inline
u_strlen(const UChar *s)
{
#if U_SIZEOF_WCHAR_T == U_SIZEOF_UCHAR
    return (int32_t)uprv_wcslen(s);
#else
    const UChar *t = s;
    while(*t != 0) {
      ++t;
    }
    return t - s;
#endif
}

U_CAPI int32_t U_EXPORT2 inline
uprv_strCompare(const UChar *s1, int32_t length1,
                const UChar *s2, int32_t length2,
                UBool strncmpStyle, UBool codePointOrder) {
    const UChar *start1, *start2, *limit1, *limit2;
    UChar c1, c2;

    /* setup for fix-up */
    start1=s1;
    start2=s2;

    /* compare identical prefixes - they do not need to be fixed up */
    if(length1<0 && length2<0) {
        /* strcmp style, both NUL-terminated */
        if(s1==s2) {
            return 0;
        }

        for(;;) {
            c1=*s1;
            c2=*s2;
            if(c1!=c2) {
                break;
            }
            if(c1==0) {
                return 0;
            }
            ++s1;
            ++s2;
        }

        /* setup for fix-up */
        limit1=limit2=NULL;
    } else if(strncmpStyle) {
        /* special handling for strncmp, assume length1==length2>=0 but also check for NUL */
        if(s1==s2) {
            return 0;
        }

        limit1=start1+length1;

        for(;;) {
            /* both lengths are same, check only one limit */
            if(s1==limit1) {
                return 0;
            }

            c1=*s1;
            c2=*s2;
            if(c1!=c2) {
                break;
            }
            if(c1==0) {
                return 0;
            }
            ++s1;
            ++s2;
        }

        /* setup for fix-up */
        limit2=start2+length1; /* use length1 here, too, to enforce assumption */
    } else {
        /* memcmp/UnicodeString style, both length-specified */
        int32_t lengthResult;

        if(length1<0) {
            length1=u_strlen(s1);
        }
        if(length2<0) {
            length2=u_strlen(s2);
        }

        /* limit1=start1+min(lenght1, length2) */
        if(length1<length2) {
            lengthResult=-1;
            limit1=start1+length1;
        } else if(length1==length2) {
            lengthResult=0;
            limit1=start1+length1;
        } else /* length1>length2 */ {
            lengthResult=1;
            limit1=start1+length2;
        }

        if(s1==s2) {
            return lengthResult;
        }

        for(;;) {
            /* check pseudo-limit */
            if(s1==limit1) {
                return lengthResult;
            }

            c1=*s1;
            c2=*s2;
            if(c1!=c2) {
                break;
            }
            ++s1;
            ++s2;
        }

        /* setup for fix-up */
        limit1=start1+length1;
        limit2=start2+length2;
    }

    /* if both values are in or above the surrogate range, fix them up */
    if(c1>=0xd800 && c2>=0xd800 && codePointOrder) {
        /* subtract 0x2800 from BMP code points to make them smaller than supplementary ones */
        if(
            (c1<=0xdbff && (s1+1)!=limit1 && UTF_IS_TRAIL(*(s1+1))) ||
            (UTF_IS_TRAIL(c1) && start1!=s1 && UTF_IS_LEAD(*(s1-1)))
        ) {
            /* part of a surrogate pair, leave >=d800 */
        } else {
            /* BMP code point - may be surrogate code point - make <d800 */
            c1-=0x2800;
        }

        if(
            (c2<=0xdbff && (s2+1)!=limit2 && UTF_IS_TRAIL(*(s2+1))) ||
            (UTF_IS_TRAIL(c2) && start2!=s2 && UTF_IS_LEAD(*(s2-1)))
        ) {
            /* part of a surrogate pair, leave >=d800 */
        } else {
            /* BMP code point - may be surrogate code point - make <d800 */
            c2-=0x2800;
        }
    }

    /* now c1 and c2 are in the requested (code unit or code point) order */
    return (int32_t)c1-(int32_t)c2;
}


U_CAPI int32_t U_EXPORT2 inline
u_strncmpCodePointOrder(const UChar *s1, const UChar *s2, int32_t n) {
    return uprv_strCompare(s1, n, s2, n, TRUE, TRUE);
}



#endif //UIMACPP_HELP_H
