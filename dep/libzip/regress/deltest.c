#include "zip.h"
#include "error.h"

char *prg;
#define BUFSIZE 65536

int
main(int argc, char *argv[])
{
    struct zip *za;

    if (argc != 2) {
	fprintf(stderr, "%s: call with one option: zip-file. First file"
		" in zip-file will be deleted\n", argv[0]);
	return 1;
    }

    if ((za=zip_open(argv[1], ZIP_CHECKCONS))==NULL) {
	fprintf(stderr, "%s: can't open '%s': %s\n", argv[0], argv[1],
		zip_err_str[zip_err]);
	return 1;
    }

    if (zip_delete(za, 0)< 0) {
	fprintf(stderr, "%s: can't delete first file in '%s': %s", 
		argv[0], argv[1], zip_err_str[zip_err]);
	return 1;
    }

    if (zip_close(za)!=0) {
	fprintf(stderr, "%s: can't close file '%s': %s", argv[0], argv[1],
		zip_err_str[zip_err]);
	return 1;
    }
    
    return 0;
}
