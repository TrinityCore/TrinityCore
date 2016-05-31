/*
	httpget.c

	gSOAP HTTP GET plugin.

	See instructions below.

gSOAP XML Web services tools
Copyright (C) 2000-2008, Robert van Engelen, Genivia Inc., All Rights Reserved.
This part of the software is released under ONE of the following licenses:
GPL, the gSOAP public license, OR Genivia's license for commercial use.
--------------------------------------------------------------------------------
gSOAP public license.

The contents of this file are subject to the gSOAP Public License Version 1.3
(the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at
http://www.cs.fsu.edu/~engelen/soaplicense.html
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the License.

The Initial Developer of the Original Code is Robert A. van Engelen.
Copyright (C) 2000-2008 Robert A. van Engelen, Genivia inc. All Rights Reserved.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------

	Compile & link with stand-alone gSOAP server for HTTP GET support.
	Compile & link with gSOAP clients for client-side HTTP GET requests.

	Usage (server side):

	struct soap soap;
	soap_init(&soap);
	soap_register_plugin_arg(&soap, http_get, http_get_handler);
	...
	... = soap_copy(&soap); // copies plugin too but not its data: plugin data is shared since fcopy is not set
	...
	soap_done(&soap); // detach plugin (calls plugin->fdelete)

	You need to define a HTTP GET handling function at the server-side:

	int http_get_handler(struct soap*)

	which will be called from the plugin upon an HTTP GET request.
	The function should return an error code or SOAP_OK;
	This function should produce a valid HTTP response, for example:

	soap_response(soap, SOAP_HTML); // use this to return HTML ...
	soap_response(soap, SOAP_OK); // ... or use this to return a SOAP message
	...
	soap_send(soap, "<HTML>...</HTML>"); // example HTML
	...
	soap_end_send(soap);

	To get query string key-value pairs within a service routine, use:

	char *s;
	s = query(soap);
	while (s)
	{ char *key = query(soap, &s);
	  char *val = query(soap, &s);
	  ...
	}

	This will garble soap->path, which contains the HTTP path of the form:
	/path?query
	where path and/or ?query may be absent. The path info is obtained from
	the HTTP request URL: http://domain/path?query
	The URL should not exceed the length of SOAP_TAGLEN. Adjust SOAP_TAGLEN
	in stdsoap2.h if necessary.

	Usage (client side):

	For SOAP calls, declare a one-way response message in the header file,
	for example:
	int ns__methodResponse(... params ..., void);
	The params will hold the return values returned by the server's SOAP
	response message.

	Client code:

	struct soap soap;
	soap_init(&soap);
	soap_register_plugin(&soap, http_get); // register plugin
	...
	if (soap_get_connect(&soap, endpoint, action))
	  ... connect error ...
        else if (soap_recv_ns__methodResponse(&soap, ... params ...))
	  ... error ...
        else
	  ... ok ...
        soap_destroy(&soap);
        soap_end(&soap);
	soap_done(&soap);

	Note that the endpoint URL may contain a query string with key-value
	pairs to pass to the server, e.g.: http://domain/path?key=val&key=val

	To use general HTTP GET, for example to retrieve an HTML document, use:

	struct soap soap;
        char *buf = NULL;
	size_t len;
	soap_init(&soap);
	soap_register_plugin(&soap, http_get); // register plugin
	if (soap_get_connect(&soap, endpoint, action)
	 || soap_begin_recv(&soap))
	  ... connect/recv error ...
	else
          buf = soap_get_http_body(&soap, &len);
        soap_end_recv(&soap);
	... process data in buf[0..len-1]
        soap_destroy(&soap);
        soap_end(&soap);
	soap_done(&soap);

        The soap_get_http_body() function above moves HTTP body content into a
        buffer.
*/

#include "httpget.h"

#ifdef __cplusplus
extern "C" {
#endif

const char http_get_id[13] = HTTP_GET_ID;

static int http_get_init(struct soap *soap, struct http_get_data *data, int (*handler)(struct soap*));
static void http_get_delete(struct soap *soap, struct soap_plugin *p);
static int http_get_parse(struct soap *soap);

int http_get(struct soap *soap, struct soap_plugin *p, void *arg)
{ p->id = http_get_id;
  p->data = (void*)malloc(sizeof(struct http_get_data));
  /* p->fcopy = http_get_copy; obsolete, see note with http_get_copy() */
  p->fdelete = http_get_delete;
  if (p->data)
    if (http_get_init(soap, (struct http_get_data*)p->data, (int (*)(struct soap*))arg))
    { free(p->data); /* error: could not init */
      return SOAP_EOM; /* return error */
    }
  return SOAP_OK;
}

static int http_get_init(struct soap *soap, struct http_get_data *data, int (*handler)(struct soap*))
{ data->fparse = soap->fparse; /* save old HTTP header parser callback */
  data->fget = handler;
  data->stat_get = 0;
  data->stat_post = 0;
  data->stat_fail = 0;
  memset(data->min, 0, sizeof(data->min));
  memset(data->hour, 0, sizeof(data->hour));
  memset(data->day, 0, sizeof(data->day));
  soap->fparse = http_get_parse; /* replace HTTP header parser callback with ours */
  return SOAP_OK;
}

/* We will share the plugin data among all soap copies created with soap_copy(), so we don't have to define this
static int http_get_copy(struct soap *soap, struct soap_plugin *dst, struct soap_plugin *src)
{ *dst = *src;
  return SOAP_OK;
}
*/

static void http_get_delete(struct soap *soap, struct soap_plugin *p)
{ free(p->data); /* free allocated plugin data (this function is not called for shared plugin data, but only when the final soap_done() is invoked on the original soap struct) */
}

static int http_get_parse(struct soap *soap)
{
#ifndef WITH_LEAN
  time_t t;
  struct tm T, *pT;
#endif
  struct http_get_data *data = (struct http_get_data*)soap_lookup_plugin(soap, http_get_id);
  if (!data)
    return SOAP_PLUGIN_ERROR;
#ifndef WITH_LEAN
  time(&t);
#ifdef HAVE_LOCALTIME_R
  pT = localtime_r(&t, &T);
#else
  pT = localtime(&t);
#endif
  /* updates should be in mutex, but we don't mind some inaccuracy in the count to preserve performance */
  data->day[pT->tm_yday]++;
  data->day[(pT->tm_yday + 1) % 365] = 0;
  data->hour[pT->tm_hour]++;
  data->hour[(pT->tm_hour + 1) % 24] = 0;
  data->min[pT->tm_min]++;
  data->min[(pT->tm_min + 1) % 60] = 0;
#endif
  soap->error = data->fparse(soap); /* parse HTTP header */
  if (soap->error == SOAP_OK)
  { /* update should be in mutex, but we don't mind some inaccuracy in the count */
    data->stat_post++;
  }
  else if (soap->error == SOAP_GET_METHOD && data->fget)
  { soap->error = SOAP_OK;
    if ((soap->error = data->fget(soap))) /* call user-defined HTTP GET handler */
    { /* update should be in mutex, but we don't mind some inaccuracy in the count */
      data->stat_fail++;
      return soap->error;
    }
    /* update should be in mutex, but we don't mind some inaccuracy in the count */
    data->stat_get++;
    return SOAP_STOP; /* stop processing the request and do not return SOAP Fault */
  }
  else
  { /* update should be in mutex, but we don't mind some inaccuracy in the count */
    data->stat_fail++;
  }
  return soap->error;
}

/******************************************************************************/

int soap_get_connect(struct soap *soap, const char *endpoint, const char *action)
{ return soap_connect_command(soap, SOAP_GET, endpoint, action);
}

char *query(struct soap *soap)
{ return strchr(soap->path, '?');
}

char *query_key(struct soap *soap, char **s)
{ char *t = *s;
  if (t && *t)
  { *s = (char*)soap_decode_string(t, strlen(t), t + 1);
    return t;
  }
  return *s = NULL;
}

char *query_val(struct soap *soap, char **s)
{ char *t = *s;
  if (t && *t == '=')
  { *s = (char*)soap_decode_string(t, strlen(t), t + 1);
    return t;
  }
  return NULL;
}

int soap_encode_string(const char *s, char *t, size_t len)
{ register int c;
  register size_t n = len;
  while ((c = *s++) && n-- > 1)
  { if (c == ' ') 
      *t++ = '+';
    else if (c == '!'
          || c == '$'
          || (c >= '(' && c <= '.')
          || (c >= '0' && c <= '9')
          || (c >= 'A' && c <= 'Z')
          || c == '_'
          || (c >= 'a' && c <= 'z'))
      *t++ = (char)c;
    else if (n > 2)
    { *t++ = '%';
      *t++ = (char)((c >> 4) + (c > 159 ? '7' : '0'));
      c &= 0xF;
      *t++ = (char)(c + (c > 9 ? '7' : '0'));
      n -= 2;
    }
    else
      break;
  }
  *t = '\0';
  return len - n;
}

const char* soap_decode_string(char *buf, size_t len, const char *val)
{ const char *s;
  char *t;
  for (s = val; *s; s++)
    if (*s != ' ' && *s != '=')
      break;
  if (*s == '"')
  { t = buf;
    s++;
    while (*s && *s != '"' && --len)
      *t++ = *s++;
    *t = '\0';
    do s++;
    while (*s && *s != '&' && *s != '=');
  }
  else
  { t = buf;
    while (*s && *s != '&' && *s != '=' && --len)
    { switch (*s)
      { case '+':
          *t++ = ' ';
        case ' ':
          s++;
          break;
        case '%':
          *t++ = ((s[1] >= 'A' ? (s[1]&0x7) + 9 : s[1] - '0') << 4) + (s[2] >= 'A' ? (s[2]&0x7) + 9 : s[2] - '0');
          s += 3;
          break;
        default:
          *t++ = *s++;
      }
    }
    *t = '\0';
  }
  return s;
}

/******************************************************************************/

#ifdef __cplusplus
}
#endif

