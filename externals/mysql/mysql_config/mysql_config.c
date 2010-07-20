/* Copyright (C) 2009 Sun Microsystems, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#include <my_global.h>
#include <my_sys.h>
#include <my_getopt.h>
#include <stdio.h>

#define INCLUDE "-IC:/Program Files/libmysql/include"
#define LIBS    "-LC:/Program Files/libmysql/lib -lmysql" \
                ""
#define CFLAGS  INCLUDE
#define VERSION "6.0.2"

enum options_client
{
  OPT_CFLAGS= 256,
  OPT_INCLUDE,
  OPT_LIBS,
  OPT_LIBS_R,
  OPT_VERSION,
};

static struct my_option my_long_options[]=
{
  {"cflags", OPT_CFLAGS, "[" CFLAGS "]",
   0, 0, 0, GET_NO_ARG, NO_ARG, 0, 0, 0, 0, 0, 0},
  {"help", '?', "Display this help and exit.", 0, 0, 0, GET_NO_ARG,
   NO_ARG, 0, 0, 0, 0, 0, 0},
  {"include", OPT_INCLUDE, "[" INCLUDE "]",
   0, 0, 0, GET_NO_ARG, NO_ARG, 0, 0, 0, 0, 0, 0},
  {"libs", OPT_LIBS, "[" LIBS "]",
   0, 0, 0, GET_NO_ARG, NO_ARG, 0, 0, 0, 0, 0, 0},
  {"libs_r", OPT_LIBS_R, "[" LIBS "]",
   0, 0, 0, GET_NO_ARG, NO_ARG, 0, 0, 0, 0, 0, 0},
  {"version", OPT_VERSION, "[" VERSION "]",
   0, 0, 0, GET_NO_ARG, NO_ARG, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, GET_NO_ARG, NO_ARG, 0, 0, 0, 0, 0, 0}
};


void usage(void)
{
  puts("Copyright 2009 Sun Microsystems, Inc.");
  puts("This software comes with ABSOLUTELY NO WARRANTY. This is free software,\nand you are welcome to modify and redistribute it under the GPL license\n");
  puts("Get compiler flags for using the MySQL client library.");
  printf("Usage: %s [OPTIONS]\n", my_progname);
  my_print_help(my_long_options);
}


my_bool
get_one_option(int optid, const struct my_option *opt __attribute__((unused)),
                              char *argument)
{
  switch (optid) {
  case OPT_CFLAGS:
    puts(CFLAGS);
    break;
  case OPT_INCLUDE:
    puts(INCLUDE);
    break;
  case OPT_LIBS:
  case OPT_LIBS_R:
    puts(LIBS);
    break;
  case OPT_VERSION:
    puts(VERSION);
    break;
  }

  return 0;
}


int main(int ac, char **av)
{
  int error;
  my_progname= av[0];

  if (ac <= 1)
  {
    usage();
    exit(1);
  }

  if ((error= handle_options(&ac, &av, my_long_options, get_one_option)))
    exit(error);

  exit(0);
}
