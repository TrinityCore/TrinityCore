/*
	httppost.c

	gSOAP HTTP POST plugin for non-SOAP payloads.

	See instructions below.

	Revisions:
	register multiple POST content handlers, each for a content type

	Note: multipart/related and multipart/form-data are already handled in gSOAP.

gSOAP XML Web services tools
Copyright (C) 2004-2005, Robert van Engelen, Genivia, Inc. All Rights Reserved.

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
Copyright (C) 2000-2004 Robert A. van Engelen, Genivia inc. All Rights Reserved.
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

	Compile & link with stand-alone gSOAP server.

	Usage (server side):

	Define a NULL-terminated array of type-handler pairs, each with a media
	type and a the handler function:

	struct http_post_handlers my_handlers[] =
		{ { "image/jpg",  jpeg_handler },
		  { "image/ *",   image_handler },
		  { "text/html",  html_handler },
		  { "text/ *",    text_handler },
		  { "text/ *;*",  text_handler },
		  { "POST",       generic_POST_handler },
		  { "PUT",        generic_PUT_handler },
		  { "DELETE",     generic_DELETE_handler },
		  { NULL }
		};
	Note that '*' can be used as a wildcard and some media types may have
	optional parameters (after ';').

	Register the plugin and the handlers:

	struct soap soap;
	soap_init(&soap);
	soap_register_plugin_arg(&soap, http_post, my_handlers);
	...
	... = soap_copy(&soap); // copies plugin too but not its data: plugin data is shared since fcopy is not set
	...
	soap_done(&soap); // detach plugin (calls plugin->fdelete)

	A POST handler function is triggered by the media type in the
	http_post_handlers table. Use http_copy_body() as below to retrieve
	HTTP POST body data:

	int image_handler(struct soap *soap)
	{ const char *buf;
	  size_t len;
	  // if necessary, check type in soap->http_content
	  if (soap->http_content && !soap_tag_cmp(soap->http_content, "image/gif")
	    return 404;
	  if (!(buf = soap_get_http_body(soap, &len))
	    return soap->error;
	  soap_end_recv(soap);
	  // ... process image in buf[0..len-1]
	  // reply with empty HTTP OK response:
	  return soap_send_empty_response(soap, SOAP_OK);
	}

	This function should also produce a valid HTTP response, for example:

	if (we want to return HTML)
	  soap_response(soap, SOAP_HTML); // use this to return HTML...
	else
	{ soap->http_content = "image/jpeg"; // a jpeg image
	  soap_response(soap, SOAP_FILE); // SOAP_FILE sets custom http content
	}
	...
	soap_send(soap, "<HTML>...</HTML>"); // example HTML
	...
	soap_end_send(soap);
	soap_closesock(soap);	// close, but keep open only with HTTP keep-alive

	The soap_send(soap, char*) and soap_send_raw(soap, char*, size_t) can
	be used to return content from server.

	Usage (client side):

	char *buf;	// to hold the HTTP response body data
	size_t len;
	...
	if (soap_post_connect(soap, "URL", "SOAP action or NULL", "media type")
	 || soap_send(soap, ...)
	 || soap_end_send(soap))
	  ... error ...
	if (soap_begin_recv(&soap)
	 || soap_http_body(&soap, &buf, &len)
	 || soap_end_recv(&soap))
	  ... error ...
	// ... use buf[0..len-1]
	soap_closesock(soap);	// close, but keep open only with HTTP keep-alive
	soap_end(soap);		// also deletes buf content

	The soap_send(soap, char*) and soap_send_raw(soap, char*, size_t) can
	be used to send content to the server as shown above.

*/

#include "httppost.h"

#ifdef __cplusplus
extern "C" {
#endif

const char http_post_id[14] = HTTP_POST_ID;

static int http_post_init(struct soap *soap, struct http_post_data *data, struct http_post_handlers *handlers);
static void http_post_delete(struct soap *soap, struct soap_plugin *p);
static int http_post_parse_header(struct soap *soap, const char*, const char*);
static http_handler_t http_lookup_handler(struct soap *soap, const char *type, struct http_post_data *data);

static int http_fput(struct soap *soap);
static int http_fdel(struct soap *soap);

int http_post(struct soap *soap, struct soap_plugin *p, void *arg)
{ p->id = http_post_id;
  p->data = (void*)malloc(sizeof(struct http_post_data));
  p->fdelete = http_post_delete;
  if (p->data)
    if (http_post_init(soap, (struct http_post_data*)p->data, (struct http_post_handlers *)arg))
    { free(p->data); /* error: could not init */
      return SOAP_EOM; /* return error */
    }
  return SOAP_OK;
}

static int http_post_init(struct soap *soap, struct http_post_data *data, struct http_post_handlers *handlers)
{ data->fparsehdr = soap->fparsehdr; /* save old HTTP header parser callback */
  soap->fparsehdr = http_post_parse_header; /* replace HTTP header parser callback with ours */
  data->fput = soap->fput;
  soap->fput = http_fput;
  data->fdel = soap->fdel;
  soap->fdel = http_fdel;
  data->handlers = handlers;
  return SOAP_OK;
}

static void http_post_delete(struct soap *soap, struct soap_plugin *p)
{ soap->fparsehdr = ((struct http_post_data*)p->data)->fparsehdr;
  soap->fput = ((struct http_post_data*)p->data)->fput;
  soap->fdel = ((struct http_post_data*)p->data)->fdel;
  free(p->data); /* free allocated plugin data (this function is not called for shared plugin data, but only when the final soap_done() is invoked on the original soap struct) */
}

static int http_post_parse_header(struct soap *soap, const char *key, const char *val)
{ struct http_post_data *data = (struct http_post_data*)soap_lookup_plugin(soap, http_post_id);
  if (!data)
    return SOAP_PLUGIN_ERROR;
  soap->error = data->fparsehdr(soap, key, val); /* parse HTTP header */
  if (soap->error == SOAP_OK)
  { if (!soap_tag_cmp(key, "Content-Type"))
    { /* check content type */
      soap->fform = http_lookup_handler(soap, val, data);
      if (!soap->fform)
        soap->fform = http_lookup_handler(soap, "POST", data);
      if (soap->fform)
        return SOAP_FORM; /* calls soap->fform after processing the HTTP header */
    }
  }
  return soap->error;
}

static http_handler_t http_lookup_handler(struct soap *soap, const char *type, struct http_post_data *data)
{ struct http_post_handlers *p;
  for (p = data->handlers; p && p->type; p++)
  { if (!soap_tag_cmp(type, p->type))
    { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Found HTTP POST plugin handler for '%s'\n", type));
      return p->handler;
    }
  }
  return NULL;
}

static int http_fput(struct soap *soap)
{ struct http_post_data *data = (struct http_post_data*)soap_lookup_plugin(soap, http_post_id);
  if (!data)
    return SOAP_PLUGIN_ERROR;
  soap->fform = http_lookup_handler(soap, "PUT", data);
  if (soap->fform)
    return SOAP_FORM;
  return 405;
}

static int http_fdel(struct soap *soap)
{ struct http_post_data *data = (struct http_post_data*)soap_lookup_plugin(soap, http_post_id);
  if (!data)
    return SOAP_PLUGIN_ERROR;
  soap->fform = http_lookup_handler(soap, "DELETE", data);
  if (soap->fform)
    return SOAP_STOP;
  return 405;
}

/******************************************************************************/

int soap_post_connect(struct soap *soap, const char *endpoint, const char *action, const char *type)
{ if ((soap->omode & SOAP_IO) != SOAP_IO_CHUNK) /* not chunking: store in buf */
    soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_STORE;
  soap->http_content = type;
  return soap_connect_command(soap, SOAP_POST_FILE, endpoint, action);
}

int soap_put_connect(struct soap *soap, const char *endpoint, const char *action, const char *type)
{ if ((soap->omode & SOAP_IO) != SOAP_IO_CHUNK) /* not chunking: store in buf */
    soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_STORE;
  soap->http_content = type;
  return soap_connect_command(soap, SOAP_PUT, endpoint, action);
}

int soap_delete_connect(struct soap *soap, const char *endpoint, const char *action, const char *type)
{ if (soap_connect_command(soap, SOAP_DEL, endpoint, action)
   || soap_end_send(soap))
    return soap_closesock(soap);
  return soap_closesock(soap);
}

int soap_http_body(struct soap *soap, char **buf, size_t *len)
{ char *s = *buf = NULL;
  *len = 0;
  /* It is unlikely chunked and/or compressed POST messages are sent by browsers, but we need to handle them */
  if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK
#ifdef WITH_ZLIB
   || soap->zlib_in != SOAP_ZLIB_NONE
#endif
   )
  { register size_t k;
    soap_wchar c = EOF;
    soap->labidx = 0;
    do
    { if (soap_append_lab(soap, NULL, 0))
        return soap->error;
      s = soap->labbuf + soap->labidx;
      k = soap->lablen - soap->labidx;
      soap->labidx = soap->lablen;
      while (k--)
      { if ((c = soap_getchar(soap)) == (int)EOF)
	  break;
        *s++ = c;
      }
    } while (c != (int)EOF);
    *len = soap->lablen - k - 1;
    *buf = (char*)soap_malloc(soap, *len + 1);
    memcpy(*buf, soap->labbuf, *len + 1);
  }
  else
  { if (soap->length)
    { s = (char*)soap_malloc(soap, soap->length + 1);
      if (s)
      { char *t = s;
        size_t i;
        for (i = soap->length; i; i--)
        { soap_wchar c;
	  if ((c = soap_getchar(soap)) == (int)EOF)
	    return soap->error = SOAP_EOF;
	  *t++ = c;
	}
        *t = '\0';
      }
    }
    *buf = s;
    *len = soap->length;
  }
  return soap_end_recv(soap);
}

/******************************************************************************/

#ifdef __cplusplus
}
#endif

