FAQ - Frequently Asked Questions
================================

Q: What is libmpq?
A: libmpq is a library for manipulating MoPaQ mpq archives mostly used
   used by Blizzard in their games.

Q: What can i do with libmpq?
A: With libmpq you can write applications which can extract, create
   and manipulate mpq archives.

Q: Is it legal?
A: Yes, i think so. I have no idea why it should not, all informations
   about the fileformat are available.

Q: Is there a description of the functions?
A: Since version 0.4.0 libmpq comes with a API documentation for
   developers. The documentation is written as manual pages.

Q: Can i help?
A: Yes, help is needed, not only with developing, also with testing.
   A good point to start is using a recent SVN version of libmpq and
   trying to use it with every mpq archive you could get :)

Q: Can you give a small example to demonstrate the usage?
A: Of course :) The example below takes first parameter as mpq archive
   and extracts the first file to a buffer.

   /*
    *  Compile with:
    *
    *  x86_32:
    *
    *  gcc \
    *    -D_FILE_OFFSET_BITS=64 \
    *    -D_LARGE_FILES=1 \
    *    -D_LARGEFILE_SOURCE=1 \
    *    mpq-example.c -o mpq-example -lmpq -lz -lbz2 -I/usr/local/include/libmpq
    *
    *  x86_64:
    *
    *  gcc \
    *    -D_LARGE_FILES=1 \
    *    mpq-example.c -o mpq-example -lmpq -lz -lbz2 -I/usr/local/include/libmpq
    */

   #include <mpq.h>
   #include <stdlib.h>
   #include <limits.h>

   int main(int argc, char **argv) {
           mpq_archive_s *mpq_archive;
           off_t out_size;
           char *out_buf;

           /* open the mpq archive given as first parameter. */
           libmpq__archive_open(&mpq_archive, argv[1], -1);

           /* get size of first file (0) and malloc output buffer. */
           libmpq__file_size_unpacked(mpq_archive, 0, &out_size);
           out_buf = malloc(out_size);

           /* read, decrypt and unpack file to output buffer. */
           libmpq__file_read(mpq_archive, 0, out_buf, out_size, NULL);

           /* close the mpq archive. */
           libmpq__archive_close(mpq_archive);
   }
