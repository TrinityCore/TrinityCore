


#ifndef DOTCONFPP_H
#define DOTCONFPP_H

#include <list>

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "mempool.h"

class DOTCONFDocument;

class DOTCONFDocumentNode
{
friend class DOTCONFDocument;
private:
    DOTCONFDocumentNode * previousNode;
    DOTCONFDocumentNode * nextNode;
    DOTCONFDocumentNode * parentNode;
    DOTCONFDocumentNode * childNode;
    char ** values;
    int valuesCount;
    char * name;
    const DOTCONFDocument * document;
    int lineNum;
    char * fileName;
    bool closed;

    void pushValue(char * _value);

public:
    DOTCONFDocumentNode();
    ~DOTCONFDocumentNode();

    const char * getConfigurationFileName()const { return fileName; }
    int getConfigurationLineNumber() const { return lineNum; }

    const DOTCONFDocumentNode * getNextNode() const { return nextNode; }
    const DOTCONFDocumentNode * getPreviuosNode() const { return previousNode; }
    const DOTCONFDocumentNode * getParentNode() const { return parentNode; }
    const DOTCONFDocumentNode * getChildNode() const { return childNode; }
    const char* getValue(int index = 0) const;
    const char * getName() const { return name; }
    const DOTCONFDocument * getDocument() const { return document; }
};

class DOTCONFDocument
{
public:
    enum CaseSensitive { CASESENSETIVE, CASEINSENSETIVE };
protected:
    AsyncDNSMemPool * mempool;
private:
    DOTCONFDocumentNode * curParent;
    DOTCONFDocumentNode * curPrev;
    int curLine;
    bool quoted;
    std::list<DOTCONFDocumentNode*> nodeTree;
    std::list<char*> requiredOptions;
    std::list<char*> processedFiles;
    FILE * file;
    char * fileName;
    std::list<char*> words;
    int (*cmp_func)(const char *, const char *);

    int checkRequiredOptions();
    int parseLine();
    int parseFile(DOTCONFDocumentNode * _parent = NULL);
    int checkConfig(const std::list<DOTCONFDocumentNode*>::iterator & from);
    int cleanupLine(char * line);
    char * getSubstitution(char * macro, int lineNum);
    int macroSubstitute(DOTCONFDocumentNode * tagNode, int valueIndex);

protected:
    virtual void error(int lineNum, const char * fileName, const char * fmt, ...) ATTR_PRINTF(4,5);

public:
    DOTCONFDocument(CaseSensitive caseSensitivity = CASESENSETIVE);
    virtual ~DOTCONFDocument();

    int setContent(const char * _fileName);

    void setRequiredOptionNames(const char ** requiredOptionNames);
    const DOTCONFDocumentNode * getFirstNode() const;
    const DOTCONFDocumentNode * findNode(const char * nodeName, const DOTCONFDocumentNode * parentNode = NULL, const DOTCONFDocumentNode * startNode = NULL) const;
};

#endif

