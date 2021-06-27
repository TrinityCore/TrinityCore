/*****************************************************************************/
/* Csv.cpp                                Copyright (c) Ladislav Zezula 2019 */
/*---------------------------------------------------------------------------*/
/* Implementation for the CSV handler class                                  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 24.05.19  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local variables

static const CASC_CSV_LINE NullLine;
#define NullColumn NullLine.Columns[0];

//-----------------------------------------------------------------------------
// Local functions

static char * NextLine_Default(void * /* pvUserData */, char * szLine)
{
    // Find the end of the line
    while(szLine[0] != 0 && szLine[0] != 0x0A && szLine[0] != 0x0D)
        szLine++;

    // Terminate the line
    while(szLine[0] == 0x0A || szLine[0] == 0x0D)
        *szLine++ = 0;

    // If there's an end-of-string, it's over
    return (szLine[0] != 0) ? szLine : NULL;
}

static char * NextColumn_Default(void * /* pvUserData */, char * szColumn)
{
    // Find the end of the column
    while(szColumn[0] != 0 && szColumn[0] != '|')
        szColumn++;

    // Terminate the column
    if (szColumn[0] == '|')
    {
        *szColumn++ = 0;
        return szColumn;
    }

    // If there's an end-of-string, it's over
    return NULL;
}

static size_t CalcHashValue(const char * szString)
{
    size_t dwHash = 0x7EEE7EEE;

    // Hash the string itself
    while(szString[0] != 0)
    {
        dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ szString[0];
        szString++;
    }

    // Return the hash limited by the table size
    return dwHash;
}

static BYTE HashToIndex(size_t dwHashValue)
{
    return (BYTE)(dwHashValue & (CSV_HASH_TABLE_SIZE - 1));
}

//-----------------------------------------------------------------------------
// Class for CSV line

CASC_CSV_LINE::CASC_CSV_LINE()
{
    m_pParent = NULL;
    m_nColumns = 0;
}

CASC_CSV_LINE::~CASC_CSV_LINE()
{}

bool CASC_CSV_LINE::SetLine(CASC_CSV * pParent, char * szCsvLine)
{
    CASC_CSV_NEXTPROC PfnNextColumn = pParent->GetNextColumnProc();
    char * szCsvColumn;
    size_t nHdrColumns = 0;
    size_t nColumns = 0;

    // Reset the number of column to zero
    m_pParent = pParent;
    m_nColumns = 0;

    // Parse each column
    while(szCsvLine != NULL && nColumns < CSV_MAX_COLUMNS)
    {
        // Get current line and the next one
        szCsvColumn = szCsvLine;
        szCsvLine = PfnNextColumn(pParent->GetUserData(), szCsvLine);

        // Save the current line
        Columns[nColumns].szValue = szCsvColumn;
        Columns[nColumns].nLength = strlen(szCsvColumn);
        nColumns++;
    }

    // Columns overflow
    if(nColumns >= CSV_MAX_COLUMNS)
    {
        assert(false);
        return false;
    }

    // If the parent has header lines, then the number of columns must match
    // In the case of mismatched column count, ignore the line
    nHdrColumns = pParent->GetHeaderColumns();
    if(nHdrColumns != 0 && nColumns != nHdrColumns)
        return false;

    // All OK
    m_nColumns = nColumns;
    return true;
}

const CASC_CSV_COLUMN & CASC_CSV_LINE::operator[](const char * szColumnName) const
{
    size_t nIndex;

    // The column must have a hash table
    if(m_pParent != NULL)
    {
        nIndex = m_pParent->GetColumnIndex(szColumnName);
        if(nIndex != CSV_INVALID_INDEX && nIndex < m_nColumns)
        {
            return Columns[nIndex];
        }
    }

    return NullColumn;
}

const CASC_CSV_COLUMN & CASC_CSV_LINE::operator[](size_t nIndex) const
{
    return (nIndex < m_nColumns) ? Columns[nIndex] : NullColumn;
}

//-----------------------------------------------------------------------------
// Class for CSV object

CASC_CSV::CASC_CSV(size_t nLinesMax, bool bHasHeader)
{
    // Initialize the class variables
    memset(HashTable, 0xFF, sizeof(HashTable));
    m_pvUserData = NULL;
    m_szCsvFile = NULL;
    m_szCsvPtr = NULL;
    m_nCsvFile = 0;
    m_nLines = 0;
    m_bHasHeader = bHasHeader;

    // Initialize the "NextLine" function that will serve for finding next line in the text
    PfnNextLine = NextLine_Default;
    PfnNextColumn = NextColumn_Default;

    // Nonzero number of lines means a finite CSV handler. The CSV will be loaded at once.
    // Zero means that the user needs to call LoadNextLine() and then the line data
    if(nLinesMax != 0)
    {
        m_pLines = new CASC_CSV_LINE[nLinesMax];
        m_nLinesMax = nLinesMax;
        m_bHasAllLines = true;
    }
    else
    {
        m_pLines = new CASC_CSV_LINE[1];
        m_nLinesMax = 1;
        m_bHasAllLines = false;
    }
}

CASC_CSV::~CASC_CSV()
{
    if(m_pLines != NULL)
        delete[] m_pLines;
    if(m_szCsvFile != NULL)
        delete [] m_szCsvFile;
    m_szCsvFile = NULL;
}

DWORD CASC_CSV::SetNextLineProc(CASC_CSV_NEXTPROC PfnNextLineProc, CASC_CSV_NEXTPROC PfnNextColProc, void * pvUserData)
{
    // Set the procedure for next line parsing
    if(PfnNextLineProc != NULL)
        PfnNextLine = PfnNextLineProc;

    // Set procedure for next columne parsing
    if(PfnNextColProc != NULL)
        PfnNextColumn = PfnNextColProc;

    // Save the user data
    m_pvUserData = pvUserData;
    return ERROR_SUCCESS;
}

DWORD CASC_CSV::Load(LPCTSTR szFileName)
{
    DWORD cbFileData = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    m_szCsvFile = (char *)LoadFileToMemory(szFileName, &cbFileData);
    if (m_szCsvFile != NULL)
    {
        // Assign the data to the CSV object
        m_szCsvPtr = m_szCsvFile;
        m_nCsvFile = cbFileData;

        // Parse the data
        dwErrCode = ParseCsvData() ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
    }
    else
    {
        dwErrCode = GetCascError();
    }

    return dwErrCode;
}

DWORD CASC_CSV::Load(LPBYTE pbData, size_t cbData)
{
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    m_szCsvFile = new char[cbData + 1];
    if (m_szCsvFile != NULL)
    {
        // Copy the entire data and terminate them with zero
        memcpy(m_szCsvFile, pbData, cbData);
        m_szCsvFile[cbData] = 0;
        m_szCsvPtr = m_szCsvFile;
        m_nCsvFile = cbData;

        // Parse the data
        dwErrCode = ParseCsvData() ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
    }

    return dwErrCode;
}

bool CASC_CSV::LoadNextLine()
{
    bool bResult = false;

    // Only endless CSV handler can do this
    if(m_bHasAllLines == false)
    {
        // A few checks
        assert(m_pLines != NULL);
        assert(m_nLinesMax == 1);

        // Reset the current line and load it
        bResult = LoadNextLine(m_pLines[0]);
        m_nLines = (bResult) ? 1 : 0;
    }

    return bResult;
}

bool CASC_CSV::InitializeHashTable()
{
    // Create the hash table of HeaderText -> ColumnIndex
    for(size_t i = 0; i < Header.GetColumnCount(); i++)
    {
        // Calculate the start slot and the current slot
        size_t nStartIndex = HashToIndex(CalcHashValue(Header[i].szValue));
        size_t nHashIndex = nStartIndex;

        // Go as long as there is not a free space
        while(HashTable[nHashIndex] != 0xFF)
        {
            nHashIndex = HashToIndex(nHashIndex + 1);
        }

        // Set the slot
        HashTable[nHashIndex] = (BYTE)i;
    }

    return true;
}

bool CASC_CSV::LoadNextLine(CASC_CSV_LINE & Line)
{
    // Overwatch ROOT's header begins with "#"
    if(m_szCsvPtr == m_szCsvFile && m_szCsvPtr[0] == '#')
        m_szCsvPtr++;

    // Parse the entire line
    while(m_szCsvPtr != NULL && m_szCsvPtr[0] != 0)
    {
        char * szCsvLine = m_szCsvPtr;

        // Get the next line
        m_szCsvPtr = PfnNextLine(m_pvUserData, m_szCsvPtr);

        // Initialize the line
        if (Line.SetLine(this, szCsvLine))
            return true;
    }

    // End-of-file found
    return false;
}

bool CASC_CSV::ParseCsvData()
{
    // Sanity checks
    assert(m_nLines == 0);

    // If we have header, then parse it and set the pointer to the next line
    if(m_bHasHeader)
    {
        // Load the current line to the header
        if (!LoadNextLine(Header))
            return false;

        // Initialize the hash table
        if(!InitializeHashTable())
            return false;
    }

    // Are we supposed to load all lines?
    if(m_bHasAllLines)
    {
        // Parse each line
        for(size_t i = 0; i < m_nLinesMax; i++)
        {
            if(!LoadNextLine(m_pLines[i]))
                break;
            m_nLines++;
        }
    }

    return true;
}

const CASC_CSV_COLUMN & CASC_CSV::operator[](const char * szColumnName) const
{
    if (m_pLines == NULL || m_nLines == 0)
        return NullColumn;
    return m_pLines[0][GetColumnIndex(szColumnName)];
}

const CASC_CSV_LINE & CASC_CSV::operator[](size_t nIndex) const
{
    if (m_pLines == NULL || nIndex >= m_nLines)
        return NullLine;
    return m_pLines[nIndex];
}

size_t CASC_CSV::GetHeaderColumns() const
{
    return (m_bHasHeader) ? Header.GetColumnCount() : 0;
}

size_t CASC_CSV::GetColumnIndex(const char * szColumnName) const
{
    if(m_bHasHeader)
    {
        // Calculate the start slot and the current slot
        size_t nStartIndex = HashToIndex(CalcHashValue(szColumnName));
        size_t nHashIndex = nStartIndex;
        size_t nIndex;

        // Go as long as there is not a free space
        while((nIndex = HashTable[nHashIndex]) != 0xFF)
        {
            // Compare the string
            if(!strcmp(Header[nIndex].szValue, szColumnName))
                return nIndex;

            // Move to the next column
            nHashIndex = HashToIndex(nHashIndex + 1);
        }
    }

    return CSV_INVALID_INDEX;
}

