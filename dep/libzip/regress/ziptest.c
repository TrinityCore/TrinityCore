#include "zip.h"
#include "error.h"


int
main(int argc, char *argv[])
{
#if 0
    int i;
#endif
    struct zip *za, *destza;
#if 0
#define BUFSIZE 65536
    struct zip_file *zf1, *zf2;
    char buf1[BUFSIZE], buf2[BUFSIZE];
#endif
    
#if 0
    if (argc != 2) {
	fprintf(stderr, "%s: call with one option: the zip-file to destroy"
		"^H^H^H^H^H^H^Htest\n", argv[0]);
	return 1;
    }
#endif
    if (argc != 3) {
	fprintf(stderr, "%s: call with two options: src dest\n", argv[0]);
	return 1;
    }

    if ((za=zip_open(argv[1], ZIP_CHECKCONS))==NULL) {
	fprintf(stderr, "%s: %s: can't open file: %s\n", argv[0], argv[1],
		zip_err_str[zip_err]);
	return 1;
    }

    if ((destza=zip_open(argv[2], ZIP_CREATE))==NULL) {
	fprintf(stderr, "%s: %s: can't open file: %s\n", argv[0], argv[2],
		zip_err_str[zip_err]);
	return 1;
    }

#if 0
    for (i=0; i<za->nentry; i++) {
	printf("%8d %s\n", za->entry[i].uncomp_size, za->entry[i].fn);
	zip_add_zip(destza, za->entry[i].fn, za, i, 0, 0);
    }
#endif

    if (zip_add_zip(destza, NULL, NULL, za, 0, 0, 0) == -1)
	fprintf(stderr, "%s: %s: can't add file to zip '%s': %s\n", argv[0],
		za->entry[0].fn, argv[1], zip_err_str[zip_err]);

#if 0
    zf1= zf_open_index(za, 1);
    if (!zf1) {
	fprintf(stderr, "boese, boese\n");
	exit(100);
    }
    
    i = zf_read(zf1, buf1, 100);
    if (i < 0)
	fprintf(stderr, "read error: %s\n", zip_err_str[zf1->flags]);
    else {
	buf1[i] = 0;
	printf("read %d bytes: '%s'\n", i, buf1);
    }
    zf2 = zf_open_index(za, 1);
    i = zf_read(zf2, buf2, 200);
    if (i < 0)
	fprintf(stderr, "read error: %s\n", zip_err_str[zf2->flags]);
    else {
	buf2[i] = 0;
	printf("read %d bytes: '%s'\n", i, buf2);
    }
    i = zf_read(zf1, buf1, 100);
    if (i < 0)
	fprintf(stderr, "read error: %s\n", zip_err_str[zf1->flags]);
    else {
	buf1[i] = 0;
	printf("read %d bytes: '%s'\n", i, buf1);
    }
    zf_close(zf1);
    zf_close(zf2);
#endif
    
    if (zip_close(destza)!=0) {
	fprintf(stderr, "%s: %s: can't close file: %s\n", argv[0], argv[2],
		zip_err_str[zip_err]);
	return 1;
    }

    if (zip_close(za)!=0) {
	fprintf(stderr, "%s: %s: can't close file: %s\n", argv[0], argv[1],
		zip_err_str[zip_err]);
	return 1;
    }
    
    return 0;
}
