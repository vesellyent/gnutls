/* this is not to be included by gnutls_anon.c */
#include <gnutls_auth.h>

#define GNUTLS_ANON_SERVER_CREDENTIALS void*
#define GNUTLS_ANON_CLIENT_CREDENTIALS void*

typedef struct ANON_CLIENT_AUTH_INFO_INT {
	int dh_bits;
} *ANON_CLIENT_AUTH_INFO;

typedef ANON_CLIENT_AUTH_INFO ANON_SERVER_AUTH_INFO;

typedef struct ANON_CLIENT_AUTH_INFO_INT ANON_CLIENT_AUTH_INFO_INT;
typedef ANON_CLIENT_AUTH_INFO_INT ANON_SERVER_AUTH_INFO_INT;
