/*****************************************************************************/
/* Path.h                                 Copyright (c) Ladislav Zezula 2019 */
/*---------------------------------------------------------------------------*/
/* Global path merger class                                                  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 24.07.17  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __CASC_PATH_H__
#define __CASC_PATH_H__

//-----------------------------------------------------------------------------
// Structures

template <typename xchar>
struct CASC_PATH
{
    CASC_PATH(int chSeparator = PATH_SEP_CHAR)
    {
        m_szBufferBegin = m_szBufferPtr = m_Buffer;
        m_szBufferEnd = m_szBufferBegin + _countof(m_Buffer);
        m_chSeparator = (xchar)chSeparator;
        m_Buffer[0] = 0;
    }

    ~CASC_PATH()
    {
        if(m_szBufferBegin != m_Buffer)
        {
            CASC_FREE(m_szBufferBegin);
        }
    }

    // LPCTSTR szPath = Path;
    operator const xchar *()
    {
        return m_szBufferBegin;
    }

    // LPTSTR szPath = Path.New();
    xchar * New()
    {
        xchar * szNewStr;

        if((szNewStr = CASC_ALLOC<xchar>(Length() + 1)) != NULL)
        {
            memcpy(szNewStr, m_szBufferBegin, Length() * sizeof(xchar));
            szNewStr[Length()] = 0;
        }

        return szNewStr;
    }

    size_t Save()
    {
        return (m_szBufferPtr - m_szBufferBegin);
    }

    bool Restore(size_t nSavePos)
    {
        if((m_szBufferBegin + nSavePos) < m_szBufferEnd)
        {
            m_szBufferPtr = m_szBufferBegin + nSavePos;
            m_szBufferPtr[0] = 0;
            return true;
        }

        return false;
    }

    // Path.Copy(szBuffer, _countof(szBuffer));
    bool Copy(xchar * szBuffer, size_t cchBuffer)
    {
        if((Length() + 1) > cchBuffer)
            return false;

        memcpy(szBuffer, m_szBufferBegin, Length() * sizeof(xchar));
        szBuffer[Length()] = 0;
        return true;
    }

    size_t Length()
    {
        return m_szBufferPtr - m_szBufferBegin;
    }

    bool SetPathRoot(const xchar * szRoot)
    {
        // Make sure that there is no characters
        m_szBufferPtr = m_szBufferBegin;
        m_szBufferPtr[0] = 0;

        // Append the root path
        return AppendString(szRoot, false);
    }

    bool AppendStringN(const xchar * szString, size_t nMaxchars, bool bWithSeparator)
    {
        const xchar * szStringEnd = szString + nMaxchars;
        xchar chOneChar;

        if(szString && szString[0] && nMaxchars)
        {
            // Append separator, if required and not in begin of the string
            if(m_szBufferPtr > m_szBufferBegin && bWithSeparator)
                AppendChar(m_chSeparator);

            // Append the characters from the string
            while(szString[0] && szString < szStringEnd)
            {
                // Retrieve the single character
                chOneChar = *szString++;

                // Normalize the character
                if(chOneChar == '/' || chOneChar == '\\')
                    chOneChar = m_chSeparator;

                if(!AppendChar(chOneChar))
                    break;
            }
        }

        return true;
    }

    bool AppendString(const xchar * szString, bool bWithSeparator)
    {
        return AppendStringN(szString, (0x10000 / sizeof(xchar)), bWithSeparator);
    }

    bool AppendEKey(LPBYTE pbEKey)
    {
        xchar szEKey[MD5_STRING_SIZE + 1];

        StringFromBinary(pbEKey, MD5_HASH_SIZE, szEKey);
        AppendStringN(szEKey, 2, true);
        AppendStringN(szEKey+2, 2, true);
        return AppendString(szEKey, true);
    }

    bool AppendChar(xchar chOneChar)
    {
        // Buffer our of space?
        if((m_szBufferPtr + 2) >= m_szBufferEnd)
        {
            xchar * szOldBuffer = m_szBufferBegin;
            xchar * szNewBuffer;
            size_t nToAllocate = (m_szBufferEnd - m_szBufferBegin) * 2;
            size_t nLength = (m_szBufferPtr - m_szBufferBegin);

            if((szNewBuffer = CASC_ALLOC<xchar>(nToAllocate)) == NULL)
                return false;

            // Copy the chars
            memcpy(szNewBuffer, m_szBufferBegin, (m_szBufferPtr - m_szBufferBegin) * sizeof(xchar));
            m_szBufferBegin = szNewBuffer;
            m_szBufferPtr = m_szBufferBegin + nLength;
            m_szBufferEnd = m_szBufferBegin + nToAllocate;
            
            // Free the old buffer
            if(szOldBuffer != m_Buffer)
                CASC_FREE(szOldBuffer);
        }

        // Append the character
        *m_szBufferPtr++ = chOneChar;
        m_szBufferPtr[0] = 0;
        return true;
    }

    protected:

    xchar * m_szBufferBegin;
    xchar * m_szBufferPtr;
    xchar * m_szBufferEnd;
    xchar m_Buffer[MAX_PATH];
    xchar m_chSeparator;
};

#endif // __CASC_PATH_H__
