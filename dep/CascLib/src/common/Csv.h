/*****************************************************************************/
/* Csv.h                                  Copyright (c) Ladislav Zezula 2019 */
/*---------------------------------------------------------------------------*/
/* Interface for the CSV handler class                                       */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 24.05.19  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __CSV_H__
#define __CSV_H__

//-----------------------------------------------------------------------------
// Defines

#define CSV_INVALID_INDEX       ((size_t)(-1))
#define CSV_ZERO                ((size_t)(0))       // Use Csv[0][CSV_ZERO] instead of ambiguous Csv[0][0]
#define CSV_MAX_COLUMNS         0x20
#define CSV_HASH_TABLE_SIZE     0x80

//-----------------------------------------------------------------------------
// Class for CSV line

class CASC_CSV;

struct CASC_CSV_COLUMN
{
    CASC_CSV_COLUMN()
    {
        szValue = NULL;
        nLength = 0;
    }

    const char * szValue;
    size_t nLength;
};

class CASC_CSV_LINE
{
    public:

    CASC_CSV_LINE();
    ~CASC_CSV_LINE();

    bool SetLine(CASC_CSV * pParent, char * szLine);

    const CASC_CSV_COLUMN & operator[](const char * szColumnName) const;
    const CASC_CSV_COLUMN & operator[](size_t nIndex) const;

    size_t GetColumnCount() const
    {
        return m_nColumns;
    }

    protected:

    friend class CASC_CSV;

    CASC_CSV * m_pParent;
    CASC_CSV_COLUMN Columns[CSV_MAX_COLUMNS];
    size_t m_nColumns;
};

class CASC_CSV
{
    public:

    CASC_CSV(size_t nLinesMax, bool bHasHeader);
    ~CASC_CSV();

    DWORD Load(LPBYTE pbData, size_t cbData);
    DWORD Load(const TCHAR * szFileName);
    bool LoadNextLine();

    const CASC_CSV_COLUMN & operator[](const char * szColumnName) const;
    const CASC_CSV_LINE & operator[](size_t nIndex) const;

    size_t GetHeaderColumns() const;
    size_t GetColumnIndex(const char * szColumnName) const;

    size_t GetLineCount() const
    {
        return m_nLines;
    }

    protected:

    bool InitializeHashTable();
    bool LoadNextLine(CASC_CSV_LINE & Line);
    bool ParseCsvData();

    CASC_CSV_LINE * m_pLines;
    CASC_CSV_LINE Header;
    BYTE HashTable[CSV_HASH_TABLE_SIZE];
    char * m_szCsvFile;
    char * m_szCsvPtr;
    size_t m_nCsvFile;
    size_t m_nLinesMax;
    size_t m_nLines;
    bool m_bHasHeader;
    bool m_bHasAllLines;
};

#endif  // __CSV_H__
