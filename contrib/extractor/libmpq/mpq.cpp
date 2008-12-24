/*
 *  mpq.c -- functions for developers using libmpq.
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
 *  $Id: mpq.c,v 1.6 2004/02/12 00:49:00 mbroemme Exp $
 */
#define _CRT_SECURE_NO_DEPRECATE

#include <stdlib.h>
#include <sys/stat.h>
//#include <unistd.h>
//#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "mpq.h"
#include "common.h"

/*
 *  This function returns version information.
 *  format: MAJOR.MINOR.PATCH
 */
char *libmpq_version() {
	static char version[10];
	sprintf(version, "%i.%i.%i", LIBMPQ_MAJOR_VERSION, LIBMPQ_MINOR_VERSION, LIBMPQ_PATCH_VERSION);
	return version;
}

/*
 *  This function reads a file and verify if it is a legit MPQ archive
 *  or not. Then it fills the mpq_header structure and reads the hash
 *  table.
 */
int libmpq_archive_open(mpq_archive *mpq_a, unsigned char *mpq_filename) {
	int fd = 0;
	int rb = 0;
	int ncnt = FALSE;
	struct stat fileinfo;

	/* allocate memory */
	mpq_a->mpq_l = (mpq_list *)malloc(sizeof(mpq_list));
	memset(mpq_a->mpq_l, 0, sizeof(mpq_list));
	mpq_a->header = (mpq_header *)malloc(sizeof(mpq_header));
	memset(mpq_a->header, 0, sizeof(mpq_header));

	/* Check if file exists and is readable */
	fd = _open((char *)mpq_filename, MPQ_FILE_OPEN_FLAGS);
	if (fd == LIBMPQ_EFILE) {
		return LIBMPQ_EFILE;
	}

	/* fill the structures with informations */
	strcpy((char *)mpq_a->filename, (char *)mpq_filename);
	libmpq_init_buffer(mpq_a);
	mpq_a->fd               = fd;
	mpq_a->header->id       = 0;
	mpq_a->maxblockindex    = 0;
	mpq_a->mpq_l->mpq_files = NULL;

    mpq_a->mpqpos = 0; //k

	while (!ncnt) {
		mpq_a->header->id = 0;
		#ifdef WIN32
			_lseeki64(mpq_a->fd, mpq_a->mpqpos, SEEK_SET);
		#else
			lseek64(mpq_a->fd, mpq_a->mpqpos, SEEK_SET);
		#endif
		rb = _read(mpq_a->fd, mpq_a->header, sizeof(mpq_header));

		/* if different number of bytes read, break the loop */
		if (rb != sizeof(mpq_header)) {
			return LIBMPQ_EFILE_FORMAT;
		}

		/* special offset for protected MPQs */
		if (mpq_a->header->offset == LIBMPQ_HEADER_W3M) {
			mpq_a->flags |= LIBMPQ_FLAG_PROTECTED;
			mpq_a->header->offset = sizeof(mpq_header);
		}

		/* if valid signature has been found, break the loop */
        if (mpq_a->header->id == LIBMPQ_ID_MPQ) {
            ncnt = true;
        }
        /*if (mpq_a->header->id == LIBMPQ_ID_MPQ &&
		    mpq_a->header->offset == sizeof(mpq_header) &&
		    mpq_a->header->hashtablepos < mpq_a->header->archivesize &&
		    mpq_a->header->blocktablepos < mpq_a->header->archivesize) {
			ncnt = TRUE;
		}*/

		/* move to the next possible offset */
		if (!ncnt) {
			mpq_a->mpqpos += 0x200;
		}
	}

	/* get the right positions of the hash table and the block table. */
	mpq_a->blocksize = (0x200 << mpq_a->header->blocksize);
	fstat(mpq_a->fd, &fileinfo);

	/* Normal MPQs must have position of */
	/*if (mpq_a->header->hashtablepos + mpq_a->mpqpos < fileinfo.st_size &&
	    mpq_a->header->blocktablepos + mpq_a->mpqpos < fileinfo.st_size) {
		mpq_a->header->hashtablepos  += mpq_a->mpqpos;
		mpq_a->header->blocktablepos += mpq_a->mpqpos;
	} else {
		return LIBMPQ_EFILE_FORMAT;
	}*/

	/* Try to read and decrypt the hashtable */
	if (libmpq_read_hashtable(mpq_a) != 0) {
		return LIBMPQ_EHASHTABLE;
	}

	/* Try to read and decrypt the blocktable */
	if (libmpq_read_blocktable(mpq_a) != 0) {
		return LIBMPQ_EBLOCKTABLE;
	}

	return LIBMPQ_TOOLS_SUCCESS;
}

/*
 *  This function closes the file descriptor opened by
 *  mpq_open_archive(); and frees the decryption buffer.
 */
int libmpq_archive_close(mpq_archive *mpq_a) {
	memset(mpq_a->buf, 0, sizeof(mpq_a->buf));

	/* free the allocated memory. */
	free(mpq_a->header);
	free(mpq_a->mpq_l);

	/* Check if file descriptor is valid. */
	if ((_close(mpq_a->fd)) == LIBMPQ_EFILE) {
		return LIBMPQ_EFILE;
	}

	return LIBMPQ_TOOLS_SUCCESS;
}

/*
 * This function returns the value for the given infotype.
 * If an error occurs something < 0 is returned.
 */
int libmpq_archive_info(mpq_archive *mpq_a, unsigned int infotype) {
	unsigned int filecount = 0;
	unsigned int fsize = 0;
	unsigned int csize = 0;
	mpq_block *mpq_b_end = mpq_a->blocktable + mpq_a->header->blocktablesize;
	mpq_block *mpq_b = NULL;

	switch (infotype) {
		case LIBMPQ_MPQ_ARCHIVE_SIZE:
			return mpq_a->header->archivesize;
		case LIBMPQ_MPQ_HASHTABLE_SIZE:
			return mpq_a->header->hashtablesize;
		case LIBMPQ_MPQ_BLOCKTABLE_SIZE:
			return mpq_a->header->blocktablesize;
		case LIBMPQ_MPQ_BLOCKSIZE:
			return mpq_a->blocksize;
		case LIBMPQ_MPQ_NUMFILES:
			for (mpq_b = mpq_a->blocktable; mpq_b < mpq_b_end; mpq_b++) {
				filecount++;
			}
			return filecount;
		case LIBMPQ_MPQ_COMPRESSED_SIZE:
			for (mpq_b = mpq_a->blocktable; mpq_b < mpq_b_end; mpq_b++) {
				csize += mpq_b->csize;
			}
			return csize;
		case LIBMPQ_MPQ_UNCOMPRESSED_SIZE:
			for (mpq_b = mpq_a->blocktable; mpq_b < mpq_b_end; mpq_b++) {
				fsize += mpq_b->fsize;
			}
			return fsize;
		default:
			return LIBMPQ_TOOLS_SUCCESS;
	}
}

/*
 * This function returns some useful file information.
 */
int libmpq_file_info(mpq_archive *mpq_a, unsigned int infotype, const unsigned int number) {
	int blockindex = number; //-1;
	int i = 0;
	mpq_block *mpq_b = NULL;
	mpq_hash *mpq_h = NULL;

	/* check if given number is not out of range */
	if (number < 1 || number > mpq_a->header->blocktablesize) {
		return LIBMPQ_EINV_RANGE;
	}

	/* search for correct hashtable */
	/*for (i = 0; i < mpq_a->header->hashtablesize; i++) {
		if ((number - 1) == (mpq_a->hashtable[i]).blockindex) {
			blockindex = (mpq_a->hashtable[i]).blockindex;
			mpq_h = &(mpq_a->hashtable[i]);
			break;
		}
	}*/

	/* check if file was found */
	/*if (blockindex == -1 || blockindex > mpq_a->header->blocktablesize) {
		return LIBMPQ_EFILE_NOT_FOUND;
	}*/

	/* check if sizes are correct */
	mpq_b = mpq_a->blocktable + blockindex;
	if (mpq_b->filepos > (mpq_a->header->archivesize + mpq_a->mpqpos) || mpq_b->csize > mpq_a->header->archivesize) {
		return LIBMPQ_EFILE_CORRUPT;
	}

	/* check if file exists */
	if ((mpq_b->flags & LIBMPQ_FILE_EXISTS) == 0) {
		return LIBMPQ_EFILE_NOT_FOUND;
	}

	switch (infotype) {
		case LIBMPQ_FILE_COMPRESSED_SIZE:
			return mpq_b->csize;
		case LIBMPQ_FILE_UNCOMPRESSED_SIZE:
			return mpq_b->fsize;
		case LIBMPQ_FILE_COMPRESSION_TYPE:
			if (mpq_b->flags & LIBMPQ_FILE_COMPRESS_PKWARE) {
				return LIBMPQ_FILE_COMPRESS_PKWARE;
			}
			if (mpq_b->flags & LIBMPQ_FILE_COMPRESS_MULTI) {
				return LIBMPQ_FILE_COMPRESS_MULTI;
			}
		default:
			return LIBMPQ_TOOLS_SUCCESS;
	}
}

/*
 * This function searches the listfile for the filename.
 * On success it returns the filename, otherwiese a name
 * like file000001.xxx and if number is out of range it
 * returns NULL.
 */
char *libmpq_file_name(mpq_archive *mpq_a, const int number) {
	static char tempfile[PATH_MAX];

	/* check if we are in the range of available files. */
	if (number > libmpq_archive_info(mpq_a, LIBMPQ_MPQ_NUMFILES) || number < 1) {
		return NULL;
	}

	/* this is safe because we built a fallback filelist, if something was wrong. */
	sprintf(tempfile, (char *)mpq_a->mpq_l->mpq_files[number - 1], number);

	return tempfile;
}

/*
 *  This function returns the number to the given
 *  filename.
 */
int libmpq_file_number(mpq_archive *mpq_a, const char *name) {
	int i;
	char tempfile[PATH_MAX];

	for (i = 0; mpq_a->mpq_l->mpq_files[i]; i++) {
		sprintf(tempfile, (char *)mpq_a->mpq_l->mpq_files[i], i + 1);
		if (strncmp(tempfile, name, strlen(name)) == 0) {

			/* if file found return the number */
			return i + 1;
		}
	}

	/* if no matching entry found return LIBMPQ_EFILE_NOT_FOUND */
	return LIBMPQ_EFILE_NOT_FOUND;
}

/*
 *  This function verifies if a given file (by number
 *  or name) is in the opened mpq archive. On success
 *  it returns 0, otherwise LIBMPQ_EFILE_NOT_FOUND.
 */
int libmpq_file_check(mpq_archive *mpq_a, void *file, int type) {
	int found = 0;
	int i;
	char tempfile[PATH_MAX];

	switch (type) {
		case LIBMPQ_FILE_TYPE_INT:

			/* check if we are in the range of available files. */
			if (*(int *)file > libmpq_archive_info(mpq_a, LIBMPQ_MPQ_NUMFILES) || *(int *)file < 1) {
				return LIBMPQ_EFILE_NOT_FOUND;
			} else {
				return LIBMPQ_TOOLS_SUCCESS;
			}
		case LIBMPQ_FILE_TYPE_CHAR:
			for (i = 0; mpq_a->mpq_l->mpq_files[i]; i++) {
				sprintf(tempfile, (char *)mpq_a->mpq_l->mpq_files[i], i);
				if (strncmp(tempfile, (char *)file, strlen((char *)file)) == 0) {

					/* if file found break */
					found = 1;
					break;
				}
			}

			/* if a file was found return 0 */
			if (found == 1) {
				return LIBMPQ_TOOLS_SUCCESS;
			} else {
				return LIBMPQ_EFILE_NOT_FOUND;
			}
		default:
			return LIBMPQ_TOOLS_SUCCESS;
	}
}

/*
 *  This function extracts a file from a MPQ archive
 *  by the given number.
 */
int libmpq_file_extract(mpq_archive *mpq_a, const int number, const char *filename) {
	int blockindex = number; //-1;
	int fd = 0;
	int i = 0;
	char buffer[0x1000];
	//char tempfile[PATH_MAX];
	unsigned int transferred = 1;
	mpq_file *mpq_f = NULL;
	mpq_block *mpq_b = NULL;
	mpq_hash *mpq_h = NULL;

/*	if (number < 1 || number > mpq_a->header->blocktablesize) {
		return LIBMPQ_EINV_RANGE;
	}*/
/*
	sprintf(tempfile, libmpq_file_name(mpq_a, number));
*/
	/* check if mpq_f->filename could be written here. */
	fd = _open(filename, O_RDWR|O_CREAT|O_TRUNC, 0644);
	if (fd == LIBMPQ_EFILE) {
		return LIBMPQ_EFILE;
	}

	/* search for correct hashtable */
	/*for (i = 0; i < mpq_a->header->hashtablesize; i++) {
		if ((number - 1) == (mpq_a->hashtable[i]).blockindex) {
			blockindex = (mpq_a->hashtable[i]).blockindex;
			mpq_h = &(mpq_a->hashtable[i]);
			break;
		}
	}*/

	/* check if file was found */
	if (blockindex == -1 || blockindex > mpq_a->header->blocktablesize) {
		return LIBMPQ_EFILE_NOT_FOUND;
	}

	/* check if sizes are correct */
	mpq_b = mpq_a->blocktable + blockindex;
	if (mpq_b->filepos > (mpq_a->header->archivesize + mpq_a->mpqpos) || mpq_b->csize > mpq_a->header->archivesize) {
		return LIBMPQ_EFILE_CORRUPT;
	}

	/* check if file exists */
	if ((mpq_b->flags & LIBMPQ_FILE_EXISTS) == 0) {
		return LIBMPQ_EFILE_NOT_FOUND;
	}

	/* allocate memory for file structure */
	mpq_f = (mpq_file *)malloc(sizeof(mpq_file));
	if (!mpq_f) {
		return LIBMPQ_EALLOCMEM;
	}

	/* initialize file structure */
	memset(mpq_f, 0, sizeof(mpq_file));
	mpq_f->fd             = fd;
	mpq_f->mpq_b          = mpq_b;
	mpq_f->nblocks        = (mpq_f->mpq_b->fsize + mpq_a->blocksize - 1) / mpq_a->blocksize;
	mpq_f->mpq_h          = mpq_h;
	mpq_f->accessed       = FALSE;
	mpq_f->blockposloaded = FALSE;
	sprintf((char *)mpq_f->filename, filename);

	/* allocate buffers for decompression. */
	if (mpq_f->mpq_b->flags & LIBMPQ_FILE_COMPRESSED) {

		/*
		 *  Allocate buffer for block positions. At the begin of file are stored
		 *  unsigned ints holding positions of each block relative from begin of
		 *  file in the archive.
		 */
		if ((mpq_f->blockpos = (unsigned int *)malloc(sizeof(int) * mpq_f->nblocks + 1)) == NULL) {
			return LIBMPQ_EALLOCMEM;
		}
	}

	while (transferred > 0) {
		transferred = libmpq_file_read_file(mpq_a, mpq_f, mpq_f->filepos, buffer, sizeof(buffer));
		if (transferred == 0) {
			break;
		} else {
			mpq_f->accessed  = TRUE;
			mpq_f->filepos  += transferred;
		}

		transferred = _write(mpq_f->fd, buffer, transferred);
		if (transferred == 0) {
			break;
		}
	}

	_close(fd);

	/* freeing the file structure */
	free(mpq_f);
	return LIBMPQ_TOOLS_SUCCESS;
}

/*
 *  This function tries to get the filenames for the hashes. It uses
 *  an internal listfile database and gets the correct listfile from
 *  some specific archive informations.
 */

int libmpq_listfile_open(mpq_archive *mpq_a, char file[PATH_MAX]) {
	FILE *fp;
	//char **filelist;
	int i = 0;
	//int fl_count;
	//int fl_size;
	int fl_count_fb;
	int fl_size_fb;
	int result = LIBMPQ_TOOLS_SUCCESS;
	struct stat statbuf;

	/* get file status */
	if (stat(file, &statbuf) < 0) {
		result = LIBMPQ_CONF_EFILE_NOT_FOUND;
	}

	/* check if file is a filename or directory */
	/*if (S_ISDIR(statbuf.st_mode)) {

		// allocate memory for the file list
		filelist = (char **)malloc(LIBMPQ_CONF_FL_INCREMENT * sizeof(char *));
		fl_count = 0;
		fl_size = LIBMPQ_CONF_FL_INCREMENT;

		// check if it is a valid listfile
		if (libmpq_detect_listfile_rec(file, &filelist, &fl_count, &fl_size)) {
			filelist == NULL;
		}

		filelist[fl_count] = NULL;

		// return if no listfile was found
		if (filelist == NULL) {
			result = LIBMPQ_CONF_EFILE_NOT_FOUND;
		}

		for (i = 0; filelist[i]; i++) {
			if ((fp = fopen(filelist[i], "r")) != NULL ) {
				result = libmpq_read_listfile(mpq_a, fp);
				fclose(fp);
			}
		}

		// freeing the listfile struct
		libmpq_free_listfile(filelist);
	}*/

	/* if file is a regular file use it */
	//if (S_ISREG(statbuf.st_mode)) {

		/* if specific listfile was forced. */
		if ((fp = fopen(file, "r")) != NULL ) {
			result = libmpq_read_listfile(mpq_a, fp);
			fclose(fp);
		} else {
			result = LIBMPQ_CONF_EFILE_OPEN;
		}
	//}

	/* if error occured we need to create a fallback filelist. */
	if (mpq_a->mpq_l->mpq_files == NULL) {

		/* allocate memory for the file list */
		mpq_a->mpq_l->mpq_files = (unsigned char **)malloc(LIBMPQ_CONF_FL_INCREMENT * sizeof(char *));
		fl_count_fb = 0;
		fl_size_fb = LIBMPQ_CONF_FL_INCREMENT;

		for (i = 0; i < libmpq_archive_info(mpq_a, LIBMPQ_MPQ_NUMFILES); i++) {

			/* set the next filelist entry to a copy of the file */
			mpq_a->mpq_l->mpq_files[fl_count_fb++] = (unsigned char *)_strdup("file%06lu.xxx");

			/* increase the array size */
			if (fl_count_fb == fl_size_fb) {
				mpq_a->mpq_l->mpq_files = (unsigned char **)realloc(mpq_a->mpq_l->mpq_files, (fl_size_fb + LIBMPQ_CONF_FL_INCREMENT) * sizeof(char *));
				fl_size_fb += LIBMPQ_CONF_FL_INCREMENT;
			}
		}
		mpq_a->mpq_l->mpq_files[fl_count_fb] = NULL;

		/* if no error occurs and no listfile was assigned, we think there was no matching listfile. */
		if (result == 0) {
			result = LIBMPQ_CONF_EFILE_NOT_FOUND;
		}
	}

	return result;
}

/*
 *  This function frees the allocated memory for the listfile.
 */
int libmpq_listfile_close(mpq_archive *mpq_a) {
	int i = 0;

	/* safety check if we really have a filelist. */
	if (mpq_a->mpq_l->mpq_files != NULL) {
		/* freeing the filelist */
		while (mpq_a->mpq_l->mpq_files[i]) {
			free(mpq_a->mpq_l->mpq_files[i++]);
		}
		free(mpq_a->mpq_l->mpq_files);
	}
    return 0;
}

int libmpq_file_getdata(mpq_archive *mpq_a, mpq_hash mpq_h, const int number, unsigned char *dest) {
	int blockindex = number; //-1;
	int i = 0;
	mpq_file *mpq_f = NULL;
	mpq_block *mpq_b = NULL;
	int success = 0;

	/*if (number < 1 || number > mpq_a->header->blocktablesize) {
		return LIBMPQ_EINV_RANGE;
	}*/

	/* search for correct hashtable */
	/*for (i = 0; i < mpq_a->header->hashtablesize; i++) {
		if ((number - 1) == (mpq_a->hashtable[i]).blockindex) {
			blockindex = (mpq_a->hashtable[i]).blockindex;
			mpq_h = &(mpq_a->hashtable[i]);
			break;
		}
	}*/

	/* check if file was found */
	if (blockindex == -1 || blockindex > mpq_a->header->blocktablesize) {
		return LIBMPQ_EFILE_NOT_FOUND;
	}

	/* check if sizes are correct */
	mpq_b = mpq_a->blocktable + blockindex;
	if (mpq_b->filepos > (mpq_a->header->archivesize + mpq_a->mpqpos) || mpq_b->csize > mpq_a->header->archivesize) {
		return LIBMPQ_EFILE_CORRUPT;
	}

	/* check if file exists */
	if ((mpq_b->flags & LIBMPQ_FILE_EXISTS) == 0) {
		return LIBMPQ_EFILE_NOT_FOUND;
	}

	/* allocate memory for file structure */
	mpq_f = (mpq_file*)malloc(sizeof(mpq_file));
	if (!mpq_f) {
		return LIBMPQ_EALLOCMEM;
	}

	/* initialize file structure */
	memset(mpq_f, 0, sizeof(mpq_file));
	mpq_f->mpq_b          = mpq_b;
	mpq_f->nblocks        = (mpq_f->mpq_b->fsize + mpq_a->blocksize - 1) / mpq_a->blocksize;
	mpq_f->mpq_h          = &mpq_h;
	mpq_f->accessed       = FALSE;
	mpq_f->blockposloaded = FALSE;

	/* allocate buffers for decompression. */
	if (mpq_f->mpq_b->flags & LIBMPQ_FILE_COMPRESSED) {

		/*
		 *  Allocate buffer for block positions. At the begin of file are stored
		 *  unsigned ints holding positions of each block relative from begin of
		 *  file in the archive.
		 */
		if ((mpq_f->blockpos = (unsigned int*)malloc(sizeof(int) * (mpq_f->nblocks + 1))) == NULL) {
			return LIBMPQ_EALLOCMEM;
		}
	}

    if(libmpq_file_read_file(mpq_a, mpq_f, 0, (char*)dest, mpq_b->fsize) == mpq_b->fsize)
        success = 1;

    if (mpq_f->mpq_b->flags & LIBMPQ_FILE_COMPRESSED) {
        // Free buffer for block positions
		
	       free(mpq_f->blockpos);
	}
	/* freeing the file structure */
	free(mpq_f);
	return success?LIBMPQ_TOOLS_SUCCESS:LIBMPQ_EFILE_CORRUPT;
}
