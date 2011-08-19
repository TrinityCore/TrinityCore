#ifndef SQL_COMMON_INCLUDED
#define SQL_COMMON_INCLUDED

/* Copyright (C) 2003-2004, 2006 MySQL AB
   
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

#define SQL_COMMON_INCLUDED

#ifdef	__cplusplus
extern "C" {
#endif

#include <mysql.h>

extern const char	*unknown_sqlstate;
extern const char	*cant_connect_sqlstate;
extern const char	*not_error_sqlstate;

struct st_mysql_options_extention {
  char *plugin_dir;
  char *default_auth;
};

typedef struct st_mysql_methods
{
  my_bool (*read_query_result)(MYSQL *mysql);
  my_bool (*advanced_command)(MYSQL *mysql,
			      enum enum_server_command command,
			      const unsigned char *header,
			      unsigned long header_length,
			      const unsigned char *arg,
			      unsigned long arg_length,
			      my_bool skip_check,
                              MYSQL_STMT *stmt);
  MYSQL_DATA *(*read_rows)(MYSQL *mysql,MYSQL_FIELD *mysql_fields,
			   unsigned int fields);
  MYSQL_RES * (*use_result)(MYSQL *mysql);
  void (*fetch_lengths)(unsigned long *to, 
			MYSQL_ROW column, unsigned int field_count);
  void (*flush_use_result)(MYSQL *mysql, my_bool flush_all_results);
  int (*read_change_user_result)(MYSQL *mysql);
#if !defined(MYSQL_SERVER) || defined(EMBEDDED_LIBRARY)
  MYSQL_FIELD * (*list_fields)(MYSQL *mysql);
  my_bool (*read_prepare_result)(MYSQL *mysql, MYSQL_STMT *stmt);
  int (*stmt_execute)(MYSQL_STMT *stmt);
  int (*read_binary_rows)(MYSQL_STMT *stmt);
  int (*unbuffered_fetch)(MYSQL *mysql, char **row);
  void (*free_embedded_thd)(MYSQL *mysql);
  const char *(*read_statistics)(MYSQL *mysql);
  my_bool (*next_result)(MYSQL *mysql);
  int (*read_rows_from_cursor)(MYSQL_STMT *stmt);
#endif
} MYSQL_METHODS;

#define simple_command(mysql, command, arg, length, skip_check) \
  (*(mysql)->methods->advanced_command)(mysql, command, 0,  \
                                        0, arg, length, skip_check, NULL)
#define stmt_command(mysql, command, arg, length, stmt) \
  (*(mysql)->methods->advanced_command)(mysql, command, 0,  \
                                        0, arg, length, 1, stmt)

extern CHARSET_INFO *default_client_charset_info;
MYSQL_FIELD *unpack_fields(MYSQL_DATA *data,MEM_ROOT *alloc,uint fields,
			   my_bool default_value, uint server_capabilities);
void free_rows(MYSQL_DATA *cur);
void free_old_query(MYSQL *mysql);
void end_server(MYSQL *mysql);
my_bool mysql_reconnect(MYSQL *mysql);
void mysql_read_default_options(struct st_mysql_options *options,
				const char *filename,const char *group);
my_bool
cli_advanced_command(MYSQL *mysql, enum enum_server_command command,
		     const unsigned char *header, ulong header_length,
		     const unsigned char *arg, ulong arg_length,
                     my_bool skip_check, MYSQL_STMT *stmt);
unsigned long cli_safe_read(MYSQL *mysql);
void net_clear_error(NET *net);
void set_stmt_errmsg(MYSQL_STMT *stmt, NET *net);
void set_stmt_error(MYSQL_STMT *stmt, int errcode, const char *sqlstate,
                    const char *err);
void set_mysql_error(MYSQL *mysql, int errcode, const char *sqlstate);
void set_mysql_extended_error(MYSQL *mysql, int errcode, const char *sqlstate,
                              const char *format, ...);

/* client side of the pluggable authentication */
struct st_plugin_vio_info;
void mpvio_info(Vio *vio, struct st_plugin_vio_info *info);
int run_plugin_auth(MYSQL *mysql, char *data, uint data_len,
                    const char *data_plugin, const char *db);
int mysql_client_plugin_init();
void mysql_client_plugin_deinit();
struct st_mysql_client_plugin;
extern struct st_mysql_client_plugin *mysql_client_builtins[];

#ifdef	__cplusplus
}
#endif

#define protocol_41(A) ((A)->server_capabilities & CLIENT_PROTOCOL_41)

#endif /* SQL_COMMON_INCLUDED */
