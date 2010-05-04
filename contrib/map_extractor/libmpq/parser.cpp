/*
 *  parser.c -- functions used to parse list or config file.
 *
 *  Copyright (C) 2003 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  $Id: parser.c,v 1.5 2004/02/12 00:47:53 mbroemme Exp $
 */
#define _CRT_SECURE_NO_DEPRECATE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mpq.h"
#include "common.h"
#include <ctype.h>

/*
 *  This function deletes the specified characters, but leaves
 *  escape sequences unaffected. This means that " would be
 *  deleted but \" would not.
 */
char *libmpq_conf_delete_char(char *buf, char *chars) {
    static char *temp;
    char ch;

    temp = buf;

    /* strip out special chars like " */
    while (temp = strpbrk(temp, chars)) {
        ch = temp[0];
        memmove(&temp[0], &temp[1], strlen(temp));
        if (ch == '\\') {
            temp++;
        }
    }

    return buf;
}

/*
 *  This function parses a line for the value to the given option. It
 *  return 1 on success and the byte array or 0 and null.
 */
int libmpq_conf_parse_line(char *line, char *search_value, char *return_value, int size) {
    int level = 0;
    int found = 0;
    int i = 0;
    int pos = 0;

    /* search value */
    while (*(++line)) {

        /* check for spaces */
        if (!isspace(*line) && level == 1) {

            /* we found our value so break */
            found = 1;
            break;
        }

        /* check for '=' so the value follows as next parameter */
        if (*line == '=' && level == 0) {
            level = 1;
        }
    }

    /* now search for comment in this line */
    for (i = 0; i < int(strlen(line)); i++) {
        if (line[i] == '#') {
            pos = i - 1;
            break;
        }
    }

    /* now set end of byte array behind value, but only if comment was found */
    if (pos != 0) {
        for (i = pos; i >= 0; i--) {
            if (line[i] != ' ' && line[i] != '\t') {
                line[i + 1] = '\0';
                break;
            }
        }
    }

    /* now check if line has trailing spaces */
    for (i = strlen(line); i >= 0; i--) {
        if (line[i] != ' ' && line[i] != '\t') {
            line[i + 1] = '\0';
            break;
        }
    }

    /* now check if value is quoted with "" and if there is a char behind. */
    for (i = strlen(line); i >= 0; i--) {
        if (line[i] == '"') {
            line[i + 1] = '\0';
            break;
        }
    }

    /* return the values */
    strncpy(return_value, line, size);
    return found;
}

/*
 *  This function returns the value for a given option in the
 *  listdb or config file. On success it returns 1, otherwise 0.
 */
int libmpq_conf_get_value(FILE *fp, char *search_value, void *return_value, int type, int size) {
    char buf[LIBMPQ_CONF_BUFSIZE];
    int found = 0;
    int result = LIBMPQ_TOOLS_SUCCESS;

    while (fgets(buf, LIBMPQ_CONF_BUFSIZE, fp) != NULL) {
        char *line;

        buf[strlen(buf) - 1] = '\0';

        /* skip whitespace */
        for (line = buf; isspace(*line); line++) {
            continue;
        }

        /* skip empty line */
        if (line[0] == '\0') {
            continue;
        }

        /* skip comments */
        if (line[0] == '#') {
            continue;
        }

        /* process the line */
        //if (!strncasecmp(line, search_value, strlen(search_value))) {
        if (!strcmp(line, search_value)) {
            found = libmpq_conf_parse_line(line, search_value, line, LIBMPQ_CONF_BUFSIZE);
            if (found == 1) {
                libmpq_conf_delete_char(line, "\"\\");

                switch (type) {
                    case LIBMPQ_CONF_TYPE_INT:

                        /* if it is no valid number it is safe to return 0 */
                        *(int *)return_value = atoi(line);
                        break;
                    default:
                        strncpy((char *)return_value, line, size);
                        break;
                }

                /* value found, so rewind stream */
                break;
            }
        }
    }

    /* if value was not found */
    if (found == 0) {
        switch (type) {
            case LIBMPQ_CONF_TYPE_INT:
                *(int *)return_value = 0;
                result = LIBMPQ_CONF_EVALUE_NOT_FOUND;
                break;
            default:
                strncpy((char *)return_value, "", size);
                result = LIBMPQ_CONF_EVALUE_NOT_FOUND;
                break;
        }
    }
    fseek(fp, 0L, SEEK_SET);

    return result;
}

/*
 *  This function returns a pointer to a byte array, with all values
 *  found in the config file. As second value it returns th number of
 *  entries in the byte array. On success it returns 1, otherwise 0.
 */
int libmpq_conf_get_array(FILE *fp, char *search_value, char ***filelist, int *entries) {
    char buf[LIBMPQ_CONF_BUFSIZE];
    char temp[LIBMPQ_CONF_BUFSIZE];
    int level = 0;
    int array_start = 0;
    int array_end = 0;
    int fl_count;
    int fl_size;
    int found = 0;
    int i = 0;

    *entries = 0;

    /* allocate memory for the file list */
    (*filelist) = (char **)malloc(LIBMPQ_CONF_FL_INCREMENT * sizeof(char *));
    fl_count = 0;
    fl_size = LIBMPQ_CONF_FL_INCREMENT;

    while (fgets(buf, LIBMPQ_CONF_BUFSIZE, fp) != NULL) {
        char *line;

        buf[strlen(buf) - 1] = '\0';

        /* skip whitespace */
        for (line = buf; isspace(*line); line++) {
            continue;
        }

        /* skip empty line */
        if (line[0] == '\0') {
            continue;
        }

        /* skip comments */
        if (line[0] == '#') {
            continue;
        }

        /* check for array end ) */
        if (*line == ')') {
            array_end = 1;
            break;
        }

        /* process entries between () */
        if (array_start == 1 && array_end == 0) {

            /* add dummy option to use with libmpq_conf_parse_line() */
            strncpy(temp, "MPQ_BUFFER = ", LIBMPQ_CONF_BUFSIZE);
            strncat(temp, line, LIBMPQ_CONF_BUFSIZE);
            found = libmpq_conf_parse_line(temp, "MPQ_BUFFER", temp, LIBMPQ_CONF_BUFSIZE);

            if (found == 1) {
                libmpq_conf_delete_char(temp, "\"\\");

                /* set the next filelist entry to a copy of the file */
                (*filelist)[fl_count++] = _strdup(temp);

                /* increase the array size */
                if (fl_count == fl_size) {
                    (*filelist) = (char **)realloc((*filelist), (fl_size + LIBMPQ_CONF_FL_INCREMENT) * sizeof(char *));
                    fl_size += LIBMPQ_CONF_FL_INCREMENT;
                }

                /* increase number of entries */
                (*entries)++;
            }
        }

        /* process the line and search array start */
        //if (!strncasecmp(line, search_value, strlen(search_value))) {
        if (!strcmp(line, search_value)) {

            /* search value */
            while (*(++line)) {

                /* check for array start ( */
                if (*line == '(' && level == 1) {

                    /* we found our value so break */
                    array_start = 1;
                    break;
                }

                /* check for '=' so the value follows as next parameter */
                if (*line == '=' && level == 0) {
                    level = 1;
                }
            }
        }
    }

    /* we got all files, so rewind stream */
    fseek(fp, 0L, SEEK_SET);

    (*filelist)[fl_count] = NULL;

    return found;
}

