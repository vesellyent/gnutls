/* File generated by GAA 1.6.6
 */
#define GAA_NO_WIN32
#line 1 "p11tool.gaa"


/* C declarations */

#include <config.h>
#ifdef _WIN32
# include <io.h>
#endif

#include "certtool-common.h"
#include "p11tool.h"
#include <gnutls/pkcs11.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef GAA_NO_WIN32
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(WINDOWS)
#define GAA_WIN32
#endif
#endif

static void* gaa_malloc( size_t size) {
void* ret;
	ret = malloc(size);
	if (ret==NULL) {
		fprintf(stderr, "gaa: could not allocate memory");
		exit(1);
	}
	return ret;
}

static void __gaa_helpsingle(char short_name, char *name, 
	char *arg_desc, char *opt_help)
{
     int col1, col3, col4, tabsize = 3, curr;
     int i;

     col1 = 5; /* Default values */
     col3 = 30;
     col4 = 70;

     curr = 0;
     for(i = 0; i < col1; i++)
        {
        printf(" ");
        curr++;
        }
     if(short_name)
        {
        if(name && *name)
          {
            printf("-%c, ", short_name);
            curr += 4;
          }
        else
          {
            printf("-%c ", short_name);
            curr += 3;
          }
        }
     if(name && *name)
        {
          printf("--%s ", name);
          curr += 3 + strlen(name);
        }
     if(arg_desc && *arg_desc)
        {
          printf("%s ", arg_desc);
          curr += 1 + strlen(arg_desc);
        }
     if(curr >= col3)
        {
          printf("\n");
          curr = 0;
        }
     if(opt_help) /* let's print the option's help body */
        {
        const char *str = opt_help;
        while(*str)
          {
             while(curr < col3)
               {
                 printf(" ");
                 curr++;
               }
             switch(*str)
               {
                 case '\n':
                     printf("\n");
                     curr = 0;
                     break;
                 case '\t':
                     do
                        {
                        printf(" ");
                        curr++;
                        }
                     while((curr - col3) % tabsize != 0 && curr < col4);
                 case ' ':
                     if(*str == ' ')
                        {
                        curr++;
                        printf(" ");
                        }
                     for(i = 1; str[i] && str[i] != ' ' && str[i] != '\n'
                        && str[i] != '\t'; i++);
                     if(curr + i - 1 >= col4)
                        curr = col4;
                     break;
                default:
                     printf("%c", *str);
                     curr++;
               }
             if(curr >= col4)
               {
                 printf("\n");
                 curr = 0;
               }
             str++;
          }
        }
     printf("\n");
}

void gaa_help(void)
{
	printf("p11tool help\nUsage: p11tool [options]\n");
	printf("Usage: p11tool --list-tokens\n");
	printf("Usage: p11tool --list-all\n");
	printf("Usage: p11tool --export 'pkcs11:...'\n\n");
	__gaa_helpsingle(0, "export", "URL ", "Export an object specified by a pkcs11 URL");
	__gaa_helpsingle(0, "list-tokens", "", "List all available tokens");
	__gaa_helpsingle(0, "list-mechanisms", "URL ", "List all available mechanisms in token.");
	__gaa_helpsingle(0, "list-all", "", "List all objects specified by a PKCS#11 URL");
	__gaa_helpsingle(0, "list-all-certs", "", "List all certificates specified by a PKCS#11 URL");
	__gaa_helpsingle(0, "list-certs", "", "List certificates that have a private key specified by a PKCS#11 URL");
	__gaa_helpsingle(0, "list-privkeys", "", "List private keys specified by a PKCS#11 URL");
	__gaa_helpsingle(0, "list-trusted", "", "List certificates marked as trusted, specified by a PKCS#11 URL");
	__gaa_helpsingle(0, "initialize", "URL ", "Initializes a PKCS11 token.");
	__gaa_helpsingle(0, "write", "URL ", "Writes loaded certificates, private or secret keys to a PKCS11 token.");
	__gaa_helpsingle(0, "delete", "URL ", "Deletes objects matching the URL.");
	__gaa_helpsingle(0, "label", "label ", "Sets a label for the write operation.");
	__gaa_helpsingle(0, "trusted", "", "Marks the certificate to be written as trusted.");
	__gaa_helpsingle(0, "private", "", "Marks the object to be written as private (requires PIN).");
	__gaa_helpsingle(0, "no-private", "", "Marks the object to be written as not private.");
	__gaa_helpsingle(0, "login", "", "Force login to token");
	__gaa_helpsingle(0, "detailed-url", "", "Export detailed URLs.");
	__gaa_helpsingle(0, "no-detailed-url", "", "Export less detailed URLs.");
	__gaa_helpsingle(0, "secret-key", "HEX_KEY ", "Provide a hex encoded secret key.");
	__gaa_helpsingle(0, "load-privkey", "FILE ", "Private key file to use.");
	__gaa_helpsingle(0, "load-pubkey", "FILE ", "Private key file to use.");
	__gaa_helpsingle(0, "load-certificate", "FILE ", "Certificate file to use.");
	__gaa_helpsingle('8', "pkcs8", "", "Use PKCS #8 format for private keys.");
	__gaa_helpsingle(0, "inder", "", "Use DER format for input certificates and private keys.");
	__gaa_helpsingle(0, "inraw", "", "Use RAW/DER format for input certificates and private keys.");
	__gaa_helpsingle(0, "provider", "Library ", "Specify the pkcs11 provider library");
	__gaa_helpsingle(0, "outfile", "FILE ", "Output file.");
	__gaa_helpsingle('d', "debug", "LEVEL ", "specify the debug level. Default is 1.");
	__gaa_helpsingle('h', "help", "", "shows this help text");

#line 100 "gaa.skel"
}
/* Copy of C area */

#line 104 "gaa.skel"
/* GAA HEADER */
#ifndef GAA_HEADER_POKY
#define GAA_HEADER_POKY

typedef struct _gaainfo gaainfo;

struct _gaainfo
{
#line 84 "p11tool.gaa"
	int debug;
#line 79 "p11tool.gaa"
	char *outfile;
#line 76 "p11tool.gaa"
	int action;
#line 75 "p11tool.gaa"
	char* pkcs11_provider;
#line 71 "p11tool.gaa"
	int incert_format;
#line 68 "p11tool.gaa"
	int pkcs8;
#line 65 "p11tool.gaa"
	char *cert;
#line 62 "p11tool.gaa"
	char *pubkey;
#line 59 "p11tool.gaa"
	char *privkey;
#line 56 "p11tool.gaa"
	char* secret_key;
#line 52 "p11tool.gaa"
	int pkcs11_detailed_url;
#line 49 "p11tool.gaa"
	int pkcs11_login;
#line 45 "p11tool.gaa"
	int pkcs11_private;
#line 42 "p11tool.gaa"
	int pkcs11_trusted;
#line 35 "p11tool.gaa"
	char* pkcs11_label;
#line 24 "p11tool.gaa"
	int pkcs11_type;
#line 21 "p11tool.gaa"
	char* pkcs11_url;

#line 114 "gaa.skel"
};

#ifdef __cplusplus
extern "C"
{
#endif

    int gaa(int argc, char *argv[], gaainfo *gaaval);

    void gaa_help(void);
    
    int gaa_file(const char *name, gaainfo *gaaval);
    
#ifdef __cplusplus
}
#endif


#endif

#line 135 "gaa.skel"

/* C declarations */

#define GAAERROR(x)    \
{                   \
gaa_error = 1;      \
return x;        \
}

static char *gaa_current_option;
static int gaa_error = 0;

/* Generated by gaa */

#include <string.h>
#include <stdlib.h>


#define GAA_OK                       -1

#define GAA_ERROR_NOMATCH            0
#define GAA_ERROR_NOTENOUGH_ARGS     1
#define GAA_ERROR_INVALID_ARG        2
#define GAA_ERROR_UNKNOWN            3

#define GAA_NOT_AN_OPTION       0
#define GAA_WORD_OPTION         1
#define GAA_LETTER_OPTION       2
#define GAA_MULTIPLE_OPTION     3

#define GAA_REST                0
#define GAA_NB_OPTION           29
#define GAAOPTID_help	1
#define GAAOPTID_debug	2
#define GAAOPTID_outfile	3
#define GAAOPTID_provider	4
#define GAAOPTID_inraw	5
#define GAAOPTID_inder	6
#define GAAOPTID_pkcs8	7
#define GAAOPTID_load_certificate	8
#define GAAOPTID_load_pubkey	9
#define GAAOPTID_load_privkey	10
#define GAAOPTID_secret_key	11
#define GAAOPTID_no_detailed_url	12
#define GAAOPTID_detailed_url	13
#define GAAOPTID_login	14
#define GAAOPTID_no_private	15
#define GAAOPTID_private	16
#define GAAOPTID_trusted	17
#define GAAOPTID_label	18
#define GAAOPTID_delete	19
#define GAAOPTID_write	20
#define GAAOPTID_initialize	21
#define GAAOPTID_list_trusted	22
#define GAAOPTID_list_privkeys	23
#define GAAOPTID_list_certs	24
#define GAAOPTID_list_all_certs	25
#define GAAOPTID_list_all	26
#define GAAOPTID_list_mechanisms	27
#define GAAOPTID_list_tokens	28
#define GAAOPTID_export	29

#line 168 "gaa.skel"

#define GAA_CHECK1STR(a,b)      \
if(a[0] == str[0])              \
{                               \
    gaa_current_option = a;     \
    return b;                   \
}

#define GAA_CHECKSTR(a,b)                \
if(strcmp(a,str) == 0)                   \
{                                        \
    gaa_current_option = a;              \
    return b;                            \
}

#define GAA_TESTMOREARGS                                                  \
if(!OK)                                                                     \
{                                  \
while((gaa_last_non_option != gaa_index) && (gaa_arg_used[gaa_index] == 1)) \
    gaa_index++;                                                            \
if(gaa_last_non_option == gaa_index)                                        \
    return GAA_ERROR_NOTENOUGH_ARGS; \
}

#define GAA_TESTMOREOPTIONALARGS                                                  \
if(!OK) \
{ \
while((gaa_last_non_option != gaa_index) && (gaa_arg_used[gaa_index] == 1)) \
    gaa_index++;                                                            \
if(gaa_last_non_option == gaa_index)                                        \
    OK = 1; \
}

#define GAA_FILL_2ARGS(target, func)           \
target = func(GAAargv[gaa_index]);       \
gaa_arg_used[gaa_index] = 1;             \
if(gaa_error == 1)                       \
{                                        \
    gaa_error = 0;                       \
    return GAA_ERROR_INVALID_ARG;        \
} 



#define GAA_FILL(target, func, num)           \
if(!OK) \
{ \
target = func(GAAargv[gaa_index]);       \
gaa_arg_used[gaa_index] = 1;             \
if(gaa_error == 1)                       \
{                                        \
    gaa_error = 0;                       \
    return GAA_ERROR_INVALID_ARG;        \
} \
num = 1;  \
} \
else \
{ \
num = 0; \
}

#define GAA_LIST_FILL(target, func, type ,num)                      \
if(!OK) \
{ \
num = 0;                                                            \
target = NULL;                                                      \
if ( gaa_last_non_option - gaa_index > 0)                           \
  target = gaa_malloc((gaa_last_non_option - gaa_index) * sizeof(type));\
for(; gaa_index < gaa_last_non_option; gaa_index++)                 \
{                                                                   \
    if(gaa_arg_used[gaa_index] == 0)                                \
    {                                                               \
        GAA_FILL_2ARGS(target[num], func);                          \
        num++;                                                      \
    }                                                               \
}                                                                   \
if(num == 0)                                                        \
    return GAA_ERROR_NOTENOUGH_ARGS; \
}

#define GAA_OPTIONALLIST_FILL(target, func, type ,num)                      \
if(!OK) \
{ \
num = 0;                                                            \
target = NULL;                                                      \
if ( gaa_last_non_option - gaa_index > 0)                           \
  target = gaa_malloc((gaa_last_non_option - gaa_index) * sizeof(type));\
for(; gaa_index < gaa_last_non_option; gaa_index++)                 \
{                                                                   \
    if(gaa_arg_used[gaa_index] == 0)                                \
    {                                                               \
        GAA_FILL_2ARGS(target[num], func);                                \
        num++;                                                      \
    }                                                               \
} \
}

#define GAA_OBLIGAT(str)                                            \
k = 0;                                                              \
for(i = 0; i < strlen(str); i++)                                    \
{                                                                   \
    j = gaa_get_option_num(str + i, GAA_LETTER_OPTION);           \
    if(j == GAA_ERROR_NOMATCH)                                       \
    {                                                               \
        printf("Error: invalid 'obligat' set\n");                  \
        exit(-1);                                                   \
    }                                                               \
    if(opt_list[j] == 1)                                            \
        k = 1;                                                      \
}                                                                    \
if(k == 0)                                                            \
{                                                                      \
    if(strlen(str) == 1)                                                \
        printf("You must give the -%s option\n", str);                     \
    else                                                                  \
        printf("You must give at least one option of '%s'\n", str);          \
    return 0;         \
}
        
#define GAA_INCOMP(str)                                                \
k = 0;                                                              \
for(i = 0; i < strlen(str); i++)                                    \
{                                                                   \
    j = gaa_get_option_num(str + i, GAA_LETTER_OPTION);           \
    if(j == GAA_ERROR_NOMATCH)                                      \
    {                                                               \
        printf("Error: invalid 'obligat' set\n");                  \
        exit(-1);                                                   \
    }                                                               \
    if(opt_list[j] == 1)                                            \
        k++;                                                      \
}                   \
if(k > 1)                                                            \
{                                                                      \
    printf("The options '%s' are incompatible\n", str);              \
    return 0;                                                          \
}
        

static char **GAAargv;
static int GAAargc;
static char *gaa_arg_used;
static int gaa_processing_file = 0;
static int inited = 0;

static int gaa_getint(char *arg)
{
    int tmp;
    char a;
    if(sscanf(arg, "%d%c", &tmp, &a) < 1)
    {
        printf("Option %s: '%s' isn't an integer\n", gaa_current_option, arg);
        GAAERROR(-1);
    }
    return tmp;
}

static char gaa_getchar(char *arg)
{
    if(strlen(arg) != 1)
    {
        printf("Option %s: '%s' isn't an character\n", gaa_current_option, arg);
        GAAERROR(-1);
    }
    return arg[0];
}

static char* gaa_getstr(char *arg)
{
    return arg;
}
static float gaa_getfloat(char *arg)
{
    float tmp;
    char a;
    if(sscanf(arg, "%f%c", &tmp, &a) < 1)
    {
        printf("Option %s: '%s' isn't a float number\n", gaa_current_option, arg);
        GAAERROR(-1);
    }
    return tmp;
}
/* option structures */

struct GAAOPTION_debug 
{
	int arg1;
	int size1;
};

struct GAAOPTION_outfile 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_provider 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_load_certificate 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_load_pubkey 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_load_privkey 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_secret_key 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_label 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_delete 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_write 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_initialize 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_list_mechanisms 
{
	char* arg1;
	int size1;
};

struct GAAOPTION_export 
{
	char* arg1;
	int size1;
};
         
#line 349 "gaa.skel"
static int gaa_is_an_argument(char *str)
{
#ifdef GAA_WIN32
    if(str[0] == '/' && str[1] != 0)
	return GAA_MULTIPLE_OPTION;
#endif
    if(str[0] != '-')
        return GAA_NOT_AN_OPTION;
    if(str[1] == 0)
        return GAA_NOT_AN_OPTION;
    if(str[1] == '-')
    {
        if(str[2] != 0)
            return GAA_WORD_OPTION;
        else
            return GAA_NOT_AN_OPTION;
    }
    if(str[2] == 0)
        return GAA_LETTER_OPTION;
    else
        return GAA_MULTIPLE_OPTION;
}

static int gaa_get_option_num(char *str, int status)
{
    switch(status)
        {
        case GAA_LETTER_OPTION:
			GAA_CHECK1STR("d", GAAOPTID_debug);
			GAA_CHECK1STR("", GAAOPTID_outfile);
			GAA_CHECK1STR("", GAAOPTID_provider);
			GAA_CHECK1STR("", GAAOPTID_load_certificate);
			GAA_CHECK1STR("", GAAOPTID_load_pubkey);
			GAA_CHECK1STR("", GAAOPTID_load_privkey);
			GAA_CHECK1STR("", GAAOPTID_secret_key);
			GAA_CHECK1STR("", GAAOPTID_label);
			GAA_CHECK1STR("", GAAOPTID_delete);
			GAA_CHECK1STR("", GAAOPTID_write);
			GAA_CHECK1STR("", GAAOPTID_initialize);
			GAA_CHECK1STR("", GAAOPTID_list_mechanisms);
			GAA_CHECK1STR("", GAAOPTID_export);
        case GAA_MULTIPLE_OPTION:
#line 375 "gaa.skel"
			GAA_CHECK1STR("h", GAAOPTID_help);
			GAA_CHECK1STR("", GAAOPTID_inraw);
			GAA_CHECK1STR("", GAAOPTID_inder);
			GAA_CHECK1STR("8", GAAOPTID_pkcs8);
			GAA_CHECK1STR("", GAAOPTID_no_detailed_url);
			GAA_CHECK1STR("", GAAOPTID_detailed_url);
			GAA_CHECK1STR("", GAAOPTID_login);
			GAA_CHECK1STR("", GAAOPTID_no_private);
			GAA_CHECK1STR("", GAAOPTID_private);
			GAA_CHECK1STR("", GAAOPTID_trusted);
			GAA_CHECK1STR("", GAAOPTID_list_trusted);
			GAA_CHECK1STR("", GAAOPTID_list_privkeys);
			GAA_CHECK1STR("", GAAOPTID_list_certs);
			GAA_CHECK1STR("", GAAOPTID_list_all_certs);
			GAA_CHECK1STR("", GAAOPTID_list_all);
			GAA_CHECK1STR("", GAAOPTID_list_tokens);

#line 277 "gaa.skel"
        break;
        case GAA_WORD_OPTION:
			GAA_CHECKSTR("help", GAAOPTID_help);
			GAA_CHECKSTR("debug", GAAOPTID_debug);
			GAA_CHECKSTR("outfile", GAAOPTID_outfile);
			GAA_CHECKSTR("provider", GAAOPTID_provider);
			GAA_CHECKSTR("inraw", GAAOPTID_inraw);
			GAA_CHECKSTR("inder", GAAOPTID_inder);
			GAA_CHECKSTR("pkcs8", GAAOPTID_pkcs8);
			GAA_CHECKSTR("load-certificate", GAAOPTID_load_certificate);
			GAA_CHECKSTR("load-pubkey", GAAOPTID_load_pubkey);
			GAA_CHECKSTR("load-privkey", GAAOPTID_load_privkey);
			GAA_CHECKSTR("secret-key", GAAOPTID_secret_key);
			GAA_CHECKSTR("no-detailed-url", GAAOPTID_no_detailed_url);
			GAA_CHECKSTR("detailed-url", GAAOPTID_detailed_url);
			GAA_CHECKSTR("login", GAAOPTID_login);
			GAA_CHECKSTR("no-private", GAAOPTID_no_private);
			GAA_CHECKSTR("private", GAAOPTID_private);
			GAA_CHECKSTR("trusted", GAAOPTID_trusted);
			GAA_CHECKSTR("label", GAAOPTID_label);
			GAA_CHECKSTR("delete", GAAOPTID_delete);
			GAA_CHECKSTR("write", GAAOPTID_write);
			GAA_CHECKSTR("initialize", GAAOPTID_initialize);
			GAA_CHECKSTR("list-trusted", GAAOPTID_list_trusted);
			GAA_CHECKSTR("list-privkeys", GAAOPTID_list_privkeys);
			GAA_CHECKSTR("list-certs", GAAOPTID_list_certs);
			GAA_CHECKSTR("list-all-certs", GAAOPTID_list_all_certs);
			GAA_CHECKSTR("list-all", GAAOPTID_list_all);
			GAA_CHECKSTR("list-mechanisms", GAAOPTID_list_mechanisms);
			GAA_CHECKSTR("list-tokens", GAAOPTID_list_tokens);
			GAA_CHECKSTR("export", GAAOPTID_export);

#line 281 "gaa.skel"
	break;
        default: break;
        }
    return GAA_ERROR_NOMATCH;
}

static int gaa_try(int gaa_num, int gaa_index, gaainfo *gaaval, char *opt_list)
{
    int OK = 0;
    int gaa_last_non_option;
	struct GAAOPTION_debug GAATMP_debug;
	struct GAAOPTION_outfile GAATMP_outfile;
	struct GAAOPTION_provider GAATMP_provider;
	struct GAAOPTION_load_certificate GAATMP_load_certificate;
	struct GAAOPTION_load_pubkey GAATMP_load_pubkey;
	struct GAAOPTION_load_privkey GAATMP_load_privkey;
	struct GAAOPTION_secret_key GAATMP_secret_key;
	struct GAAOPTION_label GAATMP_label;
	struct GAAOPTION_delete GAATMP_delete;
	struct GAAOPTION_write GAATMP_write;
	struct GAAOPTION_initialize GAATMP_initialize;
	struct GAAOPTION_list_mechanisms GAATMP_list_mechanisms;
	struct GAAOPTION_export GAATMP_export;

#line 393 "gaa.skel"
#ifdef GAA_REST_EXISTS
    struct GAAREST GAAREST_tmp;
#endif

    opt_list[gaa_num] = 1;
    
    for(gaa_last_non_option = gaa_index;
        (gaa_last_non_option != GAAargc) && (gaa_is_an_argument(GAAargv[gaa_last_non_option]) == GAA_NOT_AN_OPTION);
        gaa_last_non_option++);

    if(gaa_num == GAA_REST)
    {
        gaa_index = 1;
        gaa_last_non_option = GAAargc;
    }
    
    switch(gaa_num)
    {
	case GAAOPTID_help:
	OK = 0;
#line 87 "p11tool.gaa"
{ gaa_help(); exit(0); ;};

		return GAA_OK;
		break;
	case GAAOPTID_debug:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_debug.arg1, gaa_getint, GAATMP_debug.size1);
		gaa_index++;
#line 85 "p11tool.gaa"
{ gaaval->debug = GAATMP_debug.arg1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_outfile:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_outfile.arg1, gaa_getstr, GAATMP_outfile.size1);
		gaa_index++;
#line 80 "p11tool.gaa"
{ gaaval->outfile = GAATMP_outfile.arg1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_provider:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_provider.arg1, gaa_getstr, GAATMP_provider.size1);
		gaa_index++;
#line 77 "p11tool.gaa"
{ gaaval->pkcs11_provider = GAATMP_provider.arg1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_inraw:
	OK = 0;
#line 73 "p11tool.gaa"
{ gaaval->incert_format=GNUTLS_X509_FMT_DER ;};

		return GAA_OK;
		break;
	case GAAOPTID_inder:
	OK = 0;
#line 72 "p11tool.gaa"
{ gaaval->incert_format=GNUTLS_X509_FMT_DER ;};

		return GAA_OK;
		break;
	case GAAOPTID_pkcs8:
	OK = 0;
#line 69 "p11tool.gaa"
{ gaaval->pkcs8=1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_load_certificate:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_load_certificate.arg1, gaa_getstr, GAATMP_load_certificate.size1);
		gaa_index++;
#line 66 "p11tool.gaa"
{ gaaval->cert = GAATMP_load_certificate.arg1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_load_pubkey:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_load_pubkey.arg1, gaa_getstr, GAATMP_load_pubkey.size1);
		gaa_index++;
#line 63 "p11tool.gaa"
{ gaaval->pubkey = GAATMP_load_pubkey.arg1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_load_privkey:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_load_privkey.arg1, gaa_getstr, GAATMP_load_privkey.size1);
		gaa_index++;
#line 60 "p11tool.gaa"
{ gaaval->privkey = GAATMP_load_privkey.arg1 ;};

		return GAA_OK;
		break;
	case GAAOPTID_secret_key:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_secret_key.arg1, gaa_getstr, GAATMP_secret_key.size1);
		gaa_index++;
#line 57 "p11tool.gaa"
{ gaaval->secret_key = GAATMP_secret_key.arg1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_no_detailed_url:
	OK = 0;
#line 54 "p11tool.gaa"
{ gaaval->pkcs11_detailed_url = 0; ;};

		return GAA_OK;
		break;
	case GAAOPTID_detailed_url:
	OK = 0;
#line 53 "p11tool.gaa"
{ gaaval->pkcs11_detailed_url = GNUTLS_PKCS11_URL_LIB; ;};

		return GAA_OK;
		break;
	case GAAOPTID_login:
	OK = 0;
#line 50 "p11tool.gaa"
{ gaaval->pkcs11_login = 1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_no_private:
	OK = 0;
#line 47 "p11tool.gaa"
{ gaaval->pkcs11_private = 0; ;};

		return GAA_OK;
		break;
	case GAAOPTID_private:
	OK = 0;
#line 46 "p11tool.gaa"
{ gaaval->pkcs11_private = 1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_trusted:
	OK = 0;
#line 43 "p11tool.gaa"
{ gaaval->pkcs11_trusted = 1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_label:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_label.arg1, gaa_getstr, GAATMP_label.size1);
		gaa_index++;
#line 41 "p11tool.gaa"
{ gaaval->pkcs11_label = GAATMP_label.arg1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_delete:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_delete.arg1, gaa_getstr, GAATMP_delete.size1);
		gaa_index++;
#line 38 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_DELETE_URL; gaaval->pkcs11_url = GAATMP_delete.arg1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_write:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_write.arg1, gaa_getstr, GAATMP_write.size1);
		gaa_index++;
#line 37 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_WRITE_URL; gaaval->pkcs11_url = GAATMP_write.arg1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_initialize:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_initialize.arg1, gaa_getstr, GAATMP_initialize.size1);
		gaa_index++;
#line 36 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_TOKEN_INIT; gaaval->pkcs11_url = GAATMP_initialize.arg1; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_trusted:
	OK = 0;
#line 33 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_LIST; gaaval->pkcs11_type=PKCS11_TYPE_TRUSTED; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_privkeys:
	OK = 0;
#line 32 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_LIST; gaaval->pkcs11_type=PKCS11_TYPE_PRIVKEY; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_certs:
	OK = 0;
#line 31 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_LIST; gaaval->pkcs11_type=PKCS11_TYPE_PK; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_all_certs:
	OK = 0;
#line 30 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_LIST; gaaval->pkcs11_type=PKCS11_TYPE_CRT_ALL; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_all:
	OK = 0;
#line 29 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_LIST; gaaval->pkcs11_type=PKCS11_TYPE_ALL; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_mechanisms:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_list_mechanisms.arg1, gaa_getstr, GAATMP_list_mechanisms.size1);
		gaa_index++;
#line 27 "p11tool.gaa"
{ gaaval->pkcs11_url = GAATMP_list_mechanisms.arg1; gaaval->action = ACTION_PKCS11_MECHANISMS; ;};

		return GAA_OK;
		break;
	case GAAOPTID_list_tokens:
	OK = 0;
#line 25 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_TOKENS; ;};

		return GAA_OK;
		break;
	case GAAOPTID_export:
	OK = 0;
		GAA_TESTMOREARGS;
		GAA_FILL(GAATMP_export.arg1, gaa_getstr, GAATMP_export.size1);
		gaa_index++;
#line 22 "p11tool.gaa"
{ gaaval->action = ACTION_PKCS11_EXPORT_URL; gaaval->pkcs11_url = GAATMP_export.arg1; ;};

		return GAA_OK;
		break;

#line 413 "gaa.skel"
    default: break;
    }
    return GAA_ERROR_UNKNOWN;
}

int gaa(int argc, char **argv, gaainfo *gaaval)
{
    int tmp1, tmp2;
    int i, j;
    char *opt_list;

    GAAargv = argv;
    GAAargc = argc;

    opt_list = (char*) gaa_malloc(GAA_NB_OPTION + 1);

    for(i = 0; i < GAA_NB_OPTION + 1; i++)
        opt_list[i] = 0;
    /* initialization */
    if(inited == 0)
    {

#line 89 "p11tool.gaa"
{
	gaaval->action = -1; gaaval->pkcs11_provider= NULL; gaaval->outfile = NULL; gaaval->pubkey = NULL; gaaval->privkey = NULL;
	gaaval->pkcs11_url = NULL; gaaval->pkcs11_type = PKCS11_TYPE_PK; gaaval->pubkey=NULL; gaaval->pkcs11_label = NULL; 
	gaaval->pkcs11_trusted=0; gaaval->pkcs11_login = 0; gaaval->pkcs11_detailed_url = GNUTLS_PKCS11_URL_LIB; 
	gaaval->secret_key = NULL; gaaval->cert = NULL; gaaval->incert_format = GNUTLS_X509_FMT_PEM; gaaval->pkcs11_private = -1; ;};

    }
    inited = 1;
#line 438 "gaa.skel"
    gaa_arg_used = NULL;

    if (argc > 0) {
      gaa_arg_used = gaa_malloc(argc * sizeof(char));
    }

    for(i = 1; i < argc; i++)
        gaa_arg_used[i] = 0;
    for(i = 1; i < argc; i++)
    {
        if(gaa_arg_used[i] == 0)
        {
            j = 0;
            tmp1 = gaa_is_an_argument(GAAargv[i]);
            switch(tmp1)
            {
            case GAA_WORD_OPTION:
                j++;
            case GAA_LETTER_OPTION:
                j++;
                tmp2 = gaa_get_option_num(argv[i]+j, tmp1);
                if(tmp2 == GAA_ERROR_NOMATCH)
                {
                    printf("Invalid option '%s'\n", argv[i]+j);
                    return 0;
                }
                switch(gaa_try(tmp2, i+1, gaaval, opt_list))
                {
                case GAA_ERROR_NOTENOUGH_ARGS:
                    printf("'%s': not enough arguments\n",gaa_current_option);
                    return 0;
                case GAA_ERROR_INVALID_ARG:
                    printf("Invalid arguments\n");
                    return 0;
                case GAA_OK:
                    break;
                default:
                    printf("Unknown error\n");
                }
                gaa_arg_used[i] = 1;
                break;
            case GAA_MULTIPLE_OPTION:
                for(j = 1; j < strlen(argv[i]); j++)
                {
                    tmp2 = gaa_get_option_num(argv[i]+j, tmp1);
                    if(tmp2 == GAA_ERROR_NOMATCH)
                    {
                        printf("Invalid option '%c'\n", *(argv[i]+j));
                        return 0;
                    }
                    switch(gaa_try(tmp2, i+1, gaaval, opt_list))
                    {
                    case GAA_ERROR_NOTENOUGH_ARGS:
                        printf("'%s': not enough arguments\n",gaa_current_option);
                        return 0;
                    case GAA_ERROR_INVALID_ARG:
                        printf("Invalid arguments\n");
                        return 0;
                    case GAA_OK:
                        break;
                    default:
                        printf("Unknown error\n");
                    }
                }
                gaa_arg_used[i] = 1;
                break;
            default: break;
            }
        }
    }
if(gaa_processing_file == 0)
{

#line 507 "gaa.skel"
#ifdef GAA_REST_EXISTS
    switch(gaa_try(GAA_REST, 1, gaaval, opt_list))
    {
    case GAA_ERROR_NOTENOUGH_ARGS:
        printf("Rest: not enough arguments\n");
        return 0;
    case GAA_ERROR_INVALID_ARG:
        printf("Invalid arguments\n");
        return 0;
    case GAA_OK:
        break;
    default:
        printf("Unknown error\n");
    }
#endif
}
    for(i = 1; i < argc; i++)
    {
        if(gaa_arg_used[i] == 0)
        {
            printf("Too many arguments\n");
            return 0;
        }
    }
    free(gaa_arg_used);
    free(opt_list);
    return -1;
}

struct gaastrnode
{
    char *str;
    struct gaastrnode *next;
};

typedef struct gaastrnode gaa_str_node;

static int gaa_internal_get_next_str(FILE *file, gaa_str_node *tmp_str, int argc)
{
    int pos_ini;
    int a;
    int i = 0, len = 0, newline = 0;

    if(argc == 1) {
        newline = 1;
        len = 2;
    }
    
    a = fgetc( file);
    if (a == EOF) return 0;

    while(a == ' ' || a == 9 || a == '\n')
    {
        if(a == '\n')
        {
            newline=1;
            len = 2;
        }
        a = fgetc( file);
        if (a == EOF) return 0;
    }

    pos_ini = ftell(file) - 1;

    while(a != ' ' && a != 9 && a != '\n')
    {

        len++;
        a = fgetc( file);
        if(a==EOF) return 0; //a = ' ';
    }

    len += 1;
    tmp_str->str = gaa_malloc((len) * sizeof(char));

    if(newline == 1)
    {
        tmp_str->str[0] = '-';
        tmp_str->str[1] = '-';
        i = 2;
    }
    else
    {
        i = 0;
    }

    fseek(file,pos_ini, SEEK_SET);
    do
    {
        a = fgetc( file);

        if (a == EOF) {
            i+=2;
            break;
        }
        tmp_str->str[i] = a;
        i++;
    }
    while(a != ' ' && a != 9 && a != '\n' && i < len);

    tmp_str->str[i - 1] = 0;

    fseek(file,- 1, SEEK_CUR);
/*    printf("%d\n", ftell(file)); */
    
    return -1;
}

int gaa_file(const char *name, gaainfo *gaaval)
{
    gaa_str_node *first_str, **tmp_str, *tmp_str2;
    int rval, i;
    char **argv;
    int argc = 0;
    FILE *file;

    gaa_processing_file = 1;
    
    if((file = fopen(name, "r")) == NULL)
    {
        printf("Couldn't open '%s' configuration file for reading\n", name);
        return 1;
    }
    
    tmp_str = &first_str;
    do
    {
        argc++;
        *tmp_str = gaa_malloc(sizeof(gaa_str_node));

        (*tmp_str)->str = NULL;
        (*tmp_str)->next = NULL;

        rval = gaa_internal_get_next_str(file, *tmp_str, argc);
        tmp_str = &((*tmp_str)->next);
    }
    while(rval == -1);
    
    if(rval == 1)
        return 0;
    
    argv = gaa_malloc((1 + argc) * sizeof(char*));

    tmp_str2 = first_str;
    argv[0] = "cfg";
    for(i = 1; i < argc; i++)
    {
        argv[i] = tmp_str2->str;
        tmp_str2 = tmp_str2->next;
    }

    rval = gaa(argc, argv, gaaval);
    gaa_processing_file = 0;
    return rval;
}
