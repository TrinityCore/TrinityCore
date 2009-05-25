/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <fstream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

struct RawData
{
    char hash_str[200];
    char rev_str[200];
    char date_str[200];
    char time_str[200];
};

void extractDataFromSvn(FILE* EntriesFile, bool url, RawData& data)
{
    char buf[200];

    char repo_str[200];
    char num_str[200];

    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile); sscanf(buf,"%s",num_str);
    fgets(buf,200,EntriesFile); sscanf(buf,"%s",repo_str);
    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile);
    fgets(buf,200,EntriesFile); sscanf(buf,"%10sT%8s",data.date_str,data.time_str);

    if(url)
        sprintf(data.rev_str,"%s at %s",num_str,repo_str);
    else
        strcpy(data.rev_str,num_str);
}

void extractDataFromHG(FILE* EntriesFile, std::string path, bool url, RawData& data)
{
    char buf[200];

    char hash_str[200];
    char revision_str[200];

    bool found = false;
    while(fgets(buf,200,EntriesFile))
    {
        if(sscanf(buf,"%s %s",hash_str,revision_str)==2)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        strcpy(data.hash_str,"*");
        strcpy(data.rev_str,"*");
        strcpy(data.date_str,"*");
        strcpy(data.time_str,"*");
        return;
    }

    char thash_str[200];
    for(int i = 11;i >= 0; --i)
    {
        thash_str[i] = hash_str[i];
    }
    thash_str[12] = '\0';

    strcpy(data.hash_str,thash_str);
    strcpy(data.rev_str,revision_str);

    strcpy(data.date_str,"*");
    strcpy(data.time_str,"*");
}

void extractDataFromArchive(FILE* EntriesFile, std::string path, bool url, RawData& data)
{
    char buf[200];

    char hash_str[200];
    char revision_str[200];

    bool found = false;
    while(fgets(buf,200,EntriesFile))
    {
        if(sscanf(buf,"%s %s",revision_str,hash_str)==2)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        strcpy(data.hash_str,"*");
        strcpy(data.rev_str,"*");
        strcpy(data.date_str,"*");
        strcpy(data.time_str,"*");
        return;
    }

    char thash_str[200];
    for(int i = 11;i >= 0; --i)
    {
        thash_str[i] = hash_str[i];
    }
    thash_str[12] = '\0';

    strcpy(data.hash_str,thash_str);
    strcpy(data.rev_str,"Archive");

    strcpy(data.date_str,"*");
    strcpy(data.time_str,"*");
}

void extractDataFromGit(FILE* EntriesFile, std::string path, bool url, RawData& data)
{
    char buf[200];

    char hash_str[200];
    char branch_str[200];
    char url_str[200];

    bool found = false;
    while(fgets(buf,200,EntriesFile))
    {
        if(sscanf(buf,"%s\t\tbranch %s of %s",hash_str,branch_str,url_str)==3)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        strcpy(data.hash_str,"*");
        strcpy(data.rev_str,"*");
        strcpy(data.date_str,"*");
        strcpy(data.time_str,"*");
        return;
    }

    if(url)
    {
        char* host_str = NULL;
        char* acc_str  = NULL;
        char* repo_str = NULL;

        // parse URL like git@github.com:mangos/mangos
        char url_buf[200];
        int res = sscanf(url_str,"git@%s",url_buf);
        if(res)
        {
            host_str = strtok(url_buf,":");
            acc_str  = strtok(NULL,"/");
            repo_str = strtok(NULL," ");
        }
        else
        {
            res = sscanf(url_str,"git://%s",url_buf);
            if(res)
            {
                host_str = strtok(url_buf,"/");
                acc_str  = strtok(NULL,"/");
                repo_str = strtok(NULL,".");
            }
        }

        // can generate nice link
        if(res)
            sprintf(data.rev_str,"http://%s/%s/%s/commit/%s",host_str,acc_str,repo_str,hash_str);
        // unknonw URL format, use as-is
        else
            sprintf(data.rev_str,"%s at %s",hash_str,url_str);
    }
    else
        strcpy(data.rev_str,hash_str);
        strcpy(data.hash_str,"*");

    time_t rev_time = 0;
    // extracting date/time
    FILE* LogFile = fopen((path+".git/logs/HEAD").c_str(), "r");
    if(LogFile)
    {
        while(fgets(buf,200,LogFile))
        {
            char buf2[200];
            char new_hash[200];
            int unix_time = 0;
            int res2 = sscanf(buf,"%s %s %s %s %i",buf2,new_hash,buf2,buf2,&unix_time);
            if(res2!=5)
                continue;

            if(strcmp(hash_str,new_hash))
                continue;

            rev_time = unix_time;
            break;
        }

        fclose(LogFile);

        if(rev_time)
        {
            tm* aTm = localtime(&rev_time);
            //       YYYY   year
            //       MM     month (2 digits 01-12)
            //       DD     day (2 digits 01-31)
            //       HH     hour (2 digits 00-23)
            //       MM     minutes (2 digits 00-59)
            //       SS     seconds (2 digits 00-59)
            sprintf(data.date_str,"%04d-%02d-%02d",aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday);
            sprintf(data.time_str,"%02d:%02d:%02d",aTm->tm_hour,aTm->tm_min,aTm->tm_sec);
        }
        else
        {
            strcpy(data.date_str,"*");
            strcpy(data.time_str,"*");
        }
    }
    else
    {
        strcpy(data.date_str,"*");
        strcpy(data.time_str,"*");
    }
}

bool extractDataFromSvn(std::string filename, bool url, RawData& data)
{
    FILE* EntriesFile = fopen(filename.c_str(), "r");
    if(!EntriesFile)
        return false;

    extractDataFromSvn(EntriesFile,url,data);
    fclose(EntriesFile);
    return true;
}

bool extractDataFromGit(std::string filename, std::string path, bool url, RawData& data)
{
    FILE* EntriesFile = fopen(filename.c_str(), "r");
    if(!EntriesFile)
        return false;

    extractDataFromGit(EntriesFile,path,url,data);
    fclose(EntriesFile);
    return true;
}

bool extractDataFromHG(std::string filename, std::string path, bool url, RawData& data)
{
    FILE* EntriesFile = fopen(filename.c_str(), "r");
    if(!EntriesFile)
        return false;

    extractDataFromHG(EntriesFile,path,url,data);
    fclose(EntriesFile);
    return true;
}

bool extractDataFromArchive(std::string filename, std::string path, bool url, RawData& data)
{
    FILE* EntriesFile = fopen(filename.c_str(), "r");
    if(!EntriesFile)
        return false;

    extractDataFromArchive(EntriesFile,path,url,data);
    fclose(EntriesFile);
    return true;
}

std::string generateHeader(char const* rev_str, char const* date_str, char const* time_str, char const* hash_str)
{
    std::ostringstream newData;
    newData << "#ifndef __REVISION_H__" << std::endl;
    newData << "#define __REVISION_H__"  << std::endl;
    newData << " #define _REVISION \"" << rev_str << "\"" << std::endl;
    newData << " #define _HASH \"" << hash_str << "\"" << std::endl;
    newData << " #define _REVISION_DATE \"" << date_str << "\"" << std::endl;
    newData << " #define _REVISION_TIME \"" << time_str << "\""<< std::endl;
    newData << "#endif // __REVISION_H__" << std::endl;
    return newData.str();
}

int main(int argc, char **argv)
{
    bool use_url = false;
    bool hg_prefered = true;
    bool git_prefered = false;
    bool svn_prefered = false;
    std::string path;

    // Call: tool {options} [path]
    //    -h use hg prefered (default)
    //    -g use git prefered
    //    -s use svn prefered
    //    -r use only revision (without repo URL) (default)
    //    -u include repositire URL as commit URL or "rev at URL"
    for(int k = 1; k <= argc; ++k)
    {
        if(!argv[k] || !*argv[k])
            break;

        if(argv[k][0]!='-')
        {
            path = argv[k];
            if(path.size() > 0 && (path[path.size()-1]!='/' || path[path.size()-1]!='\\'))
                path += '/';
            break;
        }

        switch(argv[k][1])
        {
            case 'h':
                hg_prefered = true;
                git_prefered = false;
                svn_prefered = false;
                continue;
            case 'g':
                hg_prefered = false;
                git_prefered = true;
                svn_prefered = false;
                continue;
            case 'r':
                use_url = false;
                continue;
            case 's':
                hg_prefered = false;
                git_prefered = false;
                svn_prefered = true;
                continue;
            case 'u':
                use_url = true;
                continue;
            default:
                printf("Unknown option %s",argv[k]);
                return 1;
        }
    }


    /// new data extraction
    std::string newData;

    {
        RawData data;

        bool res = false;

        if(svn_prefered)
        {
            /// SVN data
            res = extractDataFromSvn(path+".svn/entries",use_url,data);
            if (!res)
                res = extractDataFromSvn(path+"_svn/entries",use_url,data);
            // HG data
            if (!res)
                res = extractDataFromHG(path+".hg/branchheads.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+"_hg/branchheads.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+".hg/branch.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+"_hg/branch.cache",path,use_url,data);
            // GIT data
            if (!res)
                res = extractDataFromGit(path+".git/FETCH_HEAD",path,use_url,data);
            if (!res)
                res = extractDataFromGit(path+"_git/FETCH_HEAD",path,use_url,data);
            // Archive data
            if (!res)
                res = extractDataFromArchive(path+".hg_archival.txt",path,use_url,data);
            if (!res)
                res = extractDataFromArchive(path+"_hg_archival.txt",path,use_url,data);
        }
        else if(git_prefered)
        {
            // GIT data
            res = extractDataFromGit(path+".git/FETCH_HEAD",path,use_url,data);
            if (!res)
                res = extractDataFromGit(path+"_git/FETCH_HEAD",path,use_url,data);
            // HG data
            if (!res)
                res = extractDataFromHG(path+".hg/branchheads.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+"_hg/branchheads.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+".hg/branch.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+"_hg/branch.cache",path,use_url,data);
           /// SVN data
            if (!res)
                res = extractDataFromSvn(path+".svn/entries",use_url,data);
            if (!res)
                res = extractDataFromSvn(path+"_svn/entries",use_url,data);
            // Archive data
            if (!res)
                res = extractDataFromArchive(path+".hg_archival.txt",path,use_url,data);
            if (!res)
                res = extractDataFromArchive(path+"_hg_archival.txt",path,use_url,data);
        }

        else if(hg_prefered)
        {
            // HG data
            res = extractDataFromHG(path+".hg/branchheads.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+"_hg/branchheads.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+".hg/branch.cache",path,use_url,data);
            if (!res)
                res = extractDataFromHG(path+"_hg/branch.cache",path,use_url,data);
            /// SVN data
            if (!res)
                res = extractDataFromSvn(path+".svn/entries",use_url,data);
            if (!res)
                res = extractDataFromSvn(path+"_svn/entries",use_url,data);
            // GIT data
            if (!res)
                res = extractDataFromGit(path+".git/FETCH_HEAD",path,use_url,data);
            if (!res)
                res = extractDataFromGit(path+"_git/FETCH_HEAD",path,use_url,data);
            // Archive data
            if (!res)
                res = extractDataFromArchive(path+".hg_archival.txt",path,use_url,data);
            if (!res)
                res = extractDataFromArchive(path+"_hg_archival.txt",path,use_url,data);
        }

        if(res)
            newData = generateHeader(data.rev_str,data.date_str,data.time_str,data.hash_str);
        else
            newData = generateHeader("*", "*", "*", "*");
    }

    /// get existed header data for compare
    std::string oldData;

    if(FILE* HeaderFile = fopen("revision.h","rb"))
    {
        while(!feof(HeaderFile))
        {
            int c = fgetc(HeaderFile);
            if(c < 0)
                break;
            oldData += (char)c;
        }

        fclose(HeaderFile);
    }

    /// update header only if different data
    if(newData != oldData)
    {
        if(FILE* OutputFile = fopen("revision.h","wb"))
        {
            fprintf(OutputFile,"%s",newData.c_str());
            fclose(OutputFile);
        }
    }

    return 0;
}

