/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <assert.h>
#include <set>
#include <list>
#include <sstream>

#ifdef WIN32
#include <direct.h>
#define popen _popen
#define pclose _pclose
#define snprintf _snprintf
#define putenv _putenv
#pragma warning (disable:4996)
#else
#include <unistd.h>
#endif

// max string sizes

#define MAX_REMOTE 256
#define MAX_MSG 16384
#define MAX_PATH 2048
#define MAX_BUF 2048
#define MAX_CMD 2048
#define MAX_HASH 256
#define MAX_DB 256

// config

#define NUM_REMOTES 2
#define NUM_DATABASES 3

char remotes[NUM_REMOTES][MAX_REMOTE] = {
    "git@github.com:gc/TrinityCore.git",
    "git://github.com/gc/TrinityCore.git"        // used for fetch if present
};

char remote_branch[MAX_REMOTE] = "master";
char rev_nr_file[MAX_PATH] = "src/server/shared/revision_gc.h";
char new_index_file[MAX_PATH] = ".git/git_id_index";

bool allow_replace = false;
bool local = false;
bool do_fetch = false;
bool use_new_index = true;
bool generate_makefile = false;                             // not need for cmake build systems
// aux

char origins[NUM_REMOTES][MAX_REMOTE];
int rev;

char head_message[MAX_MSG];
char path_prefix[MAX_PATH] = "";
char base_path[MAX_PATH];
char buffer[MAX_BUF];
char cmd[MAX_CMD];
char origin_hash[MAX_HASH];
char old_index_cmd[MAX_CMD];
char new_index_cmd[MAX_CMD];

FILE *cmd_pipe;

bool find_path()
{
    printf("+ finding path\n");
    char *ptr;
    char cur_path[MAX_PATH];
    getcwd(cur_path, MAX_PATH);
    size_t len = strlen(cur_path);
    strncpy(base_path, cur_path, len+1);

    if(cur_path[len-1] == '/' || cur_path[len-1] == '\\')
    {
        // we're in root, don't bother
        return false;
    }

    // don't count the root
    int count_fwd = 0, count_back = 0;
    for(ptr = cur_path-1; ptr = strchr(ptr+1, '/'); count_fwd++);
    for(ptr = cur_path-1; ptr = strchr(ptr+1, '\\'); count_back++);
    int count = std::max(count_fwd, count_back);

    char path[MAX_PATH];
    for(int i = 0; i < count; i++)
    {
        snprintf(path, MAX_PATH, "%s.git", path_prefix);
        if(0 == chdir(path))
        {
            chdir(cur_path);
            return true;
        }
        strncat(path_prefix, "../", MAX_PATH);

        ptr = strrchr(base_path, '\\');
        if(ptr) *ptr = '\0';
        else
        {
            ptr = strrchr(base_path, '/');
            if(ptr) *ptr = '\0';
        }
    }

    return false;
}

bool find_origin()
{
    printf("+ finding origin\n");
    if( (cmd_pipe = popen( "git remote -v", "r" )) == NULL )
        return false;

    bool ret = false;
    while(fgets(buffer, MAX_BUF, cmd_pipe))
    {
        char name[256], remote[MAX_REMOTE];
        sscanf(buffer, "%s %s", name, remote);
        for(int i = 0; i < NUM_REMOTES; i++)
        {
            if(strcmp(remote, remotes[i]) == 0)
            {
                strncpy(origins[i], name, MAX_REMOTE);
                ret = true;
            }
        }
    }
    pclose(cmd_pipe);
    return ret;
}

bool fetch_origin()
{
    printf("+ fetching origin\n");
    // use the public clone url if present because the private may require a password
    snprintf(cmd, MAX_CMD, "git fetch %s %s", (origins[1][0] ? origins[1] : origins[0]), remote_branch);
    int ret = system(cmd);
    return true;
}

bool check_fwd()
{
    printf("+ checking fast forward\n");
    snprintf(cmd, MAX_CMD, "git log -n 1 --pretty=\"format:%%H\" %s/%s", (origins[1][0] ? origins[1] : origins[0]), remote_branch);
    if( (cmd_pipe = popen( cmd, "r" )) == NULL )
        return false;

    if(!fgets(buffer, MAX_BUF, cmd_pipe)) return false;
    strncpy(origin_hash, buffer, MAX_HASH);
    pclose(cmd_pipe);

    if( (cmd_pipe = popen( "git log --pretty=\"format:%H\"", "r" )) == NULL )
        return false;

    bool found = false;
    while(fgets(buffer, MAX_BUF, cmd_pipe))
    {
        buffer[strlen(buffer) - 1] = '\0';
        if(strncmp(origin_hash, buffer, MAX_BUF) == 0)
        {
            found = true;
            break;
        }
    }
    pclose(cmd_pipe);

    if(!found)
    {
        // with fetch you still get the latest rev, you just rebase afterwards and push
        // without it you may not get the right rev
        if(do_fetch) printf("WARNING: non-fastforward, use rebase!\n");
        else { printf("ERROR: non-fastforward, use rebase!\n"); return false; }
    }
    return true;
}

int get_rev(char *from_msg)
{
    // accept only the rev number format, not the sql update format
    char * pch;
    pch = strstr(from_msg,"[gc");
    if (!pch) return 0;
    strncpy (pch,"[00",3);
    char nr_str[256];
    if(sscanf(from_msg, "[%[0123456789]]",nr_str) != 1) return 0;
//    if(from_msg[strlen(nr_str)+1] != ']') return 0;
    return atoi(nr_str);
}

bool find_rev()
{
    printf("+ finding next revision number\n");
    // find the highest rev number on either of the remotes
    for(int i = 0; i < NUM_REMOTES; i++)
    {
        if(!local && !origins[i][0]) continue;

        if(local) snprintf(cmd, MAX_CMD, "git log HEAD --pretty=\"format:%%s\"");
        else sprintf(cmd, "git log %s/%s --pretty=\"format:%%s\"", origins[i], remote_branch);
        if( (cmd_pipe = popen( cmd, "r" )) == NULL )
            continue;

        int nr;
        while(fgets(buffer, MAX_BUF, cmd_pipe))
        {
            nr = get_rev(buffer);
            if(nr >= rev)
                rev = nr+1;
        }
        pclose(cmd_pipe);
    }

    if(rev > 0) printf("Found [%d].\n", rev);

    return rev > 0;
}

std::string generateNrHeader(char const* rev_str)
{
    std::ostringstream newData;
    newData << "#ifndef __REVISION_gc_H__" << std::endl;
    newData << "#define __REVISION_gc_H__"  << std::endl;
    newData << " #define REVISION_gc \"" << rev_str << "\"" << std::endl;
    newData << "#endif // __REVISION_gc_H__" << std::endl;
    return newData.str();
}

void system_switch_index(const char *cmd)
{
    // do the command for the original index and then for the new index
    // both need to be updated with the changes before commit
    // but the new index will contains only the desired changes
    // while the old may contain others
    system(cmd);
    if(!use_new_index) return;
    if(putenv(new_index_cmd) != 0) return;
    system(cmd);
    if(putenv(old_index_cmd) != 0) return;
}

bool write_rev_nr()
{
    printf("+ writing revision_gc.h\n");
    char rev_str[256];
    sprintf(rev_str, "%d", rev);
    std::string header = generateNrHeader(rev_str);

    char prefixed_file[MAX_PATH];
    snprintf(prefixed_file, MAX_PATH, "%s%s", path_prefix, rev_nr_file);

    if(FILE* OutputFile = fopen(prefixed_file, "wb"))
    {
        fprintf(OutputFile,"%s", header.c_str());
        fclose(OutputFile);

        // add the file to both indices, to be committed later
        snprintf(cmd, MAX_CMD, "git add %s", prefixed_file);
        system_switch_index(cmd);

        return true;
    }

    return false;
}

bool find_head_msg()
{
    printf("+ finding last message on HEAD\n");
    if( (cmd_pipe = popen( "git log -n 1 --pretty=\"format:%s%n%n%b\"", "r" )) == NULL )
        return false;

    int poz = 0;
    while(poz < 16384-1 && EOF != (head_message[poz++] = fgetc(cmd_pipe)));
    head_message[poz-1] = '\0';

    pclose(cmd_pipe);

    if(int head_rev = get_rev(head_message))
    {
        if(!allow_replace)
        {
            printf("Last commit on HEAD is [%d]. Use -r to replace it with [%d].\n", head_rev, rev);
            return false;
        }

        // skip the rev number in the commit
        char *p = strchr(head_message, ']'), *q = head_message;
        assert(p && *(p+1));
        p+=2;
        while(*p) *q = *p, p++, q++;
        *q = 0;
        return true;
    }

    return true;
}

bool amend_commit()
{
    printf("+ amending last commit\n");

    // commit the contents of the (new) index
    if(use_new_index && putenv(new_index_cmd) != 0) return false;
    snprintf(cmd, MAX_CMD, "git commit --amend -F-");
    if( (cmd_pipe = popen( cmd, "w" )) == NULL )
        return false;

    fprintf(cmd_pipe, "[gc%d] %s", rev, head_message);
    pclose(cmd_pipe);
    if(use_new_index && putenv(old_index_cmd) != 0) return false;

    return true;
}

bool copy_file(const char *src_file, const char *dst_file)
{
    FILE * fin = fopen( src_file, "rb" );
    if(!fin) return false;
    FILE * fout = fopen( dst_file, "wb" );
    if(!fout) { fclose(fin); return false; }

    for(char c = getc(fin); !feof(fin); putc(c, fout), c = getc(fin));

    fclose(fin);
    fclose(fout);
    return true;
}

bool prepare_new_index()
{
    if(!use_new_index) return true;

    // only use a new index if there are staged changes that should be preserved
    if( (cmd_pipe = popen( "git diff --cached", "r" )) == NULL ) {
        use_new_index = false;
        return false;
    }

    if(!fgets(buffer, MAX_BUF, cmd_pipe))
    {
        use_new_index = false;
        pclose(cmd_pipe);
        return true;
    }

    pclose(cmd_pipe);

    printf("+ preparing new index\n");

    // copy the existing index file to a new one
    char src_file[MAX_PATH], dst_file[MAX_PATH];

    char *old_index = getenv("GIT_INDEX_FILE");
    if(old_index) strncpy(src_file, old_index, MAX_PATH);
    else snprintf(src_file, MAX_PATH, "%s.git/index", path_prefix);
    snprintf(dst_file, MAX_PATH, "%s%s", path_prefix, new_index_file);

    if(!copy_file(src_file, dst_file)) return false;

    // doesn't seem to work with path_prefix
    snprintf(new_index_cmd, MAX_CMD, "GIT_INDEX_FILE=%s/%s", base_path, new_index_file);
    if(putenv(new_index_cmd) != 0) return false;

    // clear the new index
    system("git reset -q --mixed HEAD");

    // revert to old index
    snprintf(old_index_cmd, MAX_CMD, "GIT_INDEX_FILE=");
    if(putenv(old_index_cmd) != 0) return false;
    return true;
}

bool cleanup_new_index()
{
    if(!use_new_index) return true;
    printf("+ cleaning up the new index\n");
    char idx_file[MAX_PATH];
    snprintf(idx_file, MAX_PATH, "%s%s", path_prefix, new_index_file);
    remove(idx_file);
    return true;
}

#define DO(cmd) if(!cmd) { printf("FAILED\n"); return 1; }

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if(argv[i] == NULL) continue;
        if(strncmp(argv[i], "-r", 2) == 0 || strncmp(argv[i], "--replace", 9) == 0)
            allow_replace = true;
        else if(strncmp(argv[i], "-l", 2) == 0 || strncmp(argv[i], "--local", 7) == 0)
            local = true;
        else if(strncmp(argv[i], "-f", 2) == 0 || strncmp(argv[i], "--fetch", 7) == 0)
            do_fetch = true;
        else if(strncmp(argv[i], "--branch=", 9) == 0)
            snprintf(remote_branch, MAX_REMOTE, "%s", argv[i] + 9);
        else if(strncmp(argv[i], "-h", 2) == 0 || strncmp(argv[i], "--help", 6) == 0)
        {
            printf("Usage: git_id [OPTION]\n");
            printf("Generates a new rev number and updates revision_nr.h and the commit message.\n");
            printf("Should be used just before push.\n");
            printf("   -h, --help            show the usage\n");
            printf("   -r, --replace         replace the rev number if it was already applied\n");
            printf("                         to the last commit\n");
            printf("   -l, --local           search for the highest rev number on HEAD\n");
            printf("   -f, --fetch           fetch from origin before searching for the new rev\n");
            printf("       --branch=BRANCH   specify which remote branch to use\n");
            return 0;
        }
    }

    DO( find_path()                     );
    if(!local)
    {
        DO( find_origin()               );
        if(do_fetch)
            DO( fetch_origin()          );
        DO( check_fwd()                 );
    }
    DO( find_rev()                      );
    DO( find_head_msg()                 );
    DO( prepare_new_index()             );
    DO( write_rev_nr()                  );
    DO( amend_commit()                  );
    DO( cleanup_new_index()             );
    return 0;
}
