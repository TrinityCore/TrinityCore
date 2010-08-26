MANFMT=@MANFMT@
man1_MANS=${MAN1:.mdoc=.${MANFMT}}
man3_MANS=${MAN3:.mdoc=.${MANFMT}}

DISTCLEANFILES=${HTML}
EXTRA_DIST=${MANDOC} ${MAN} CMakeLists.txt

MAN1=	zipcmp.mdoc zipmerge.mdoc ziptorrent.mdoc
MAN3=	libzip.mdoc \
	zip_add.mdoc \
	zip_add_dir.mdoc \
	zip_close.mdoc \
	zip_delete.mdoc \
	zip_error_clear.mdoc \
	zip_error_get.mdoc \
	zip_error_get_sys_type.mdoc \
	zip_error_to_str.mdoc \
	zip_errors.mdoc \
	zip_fclose.mdoc \
	zip_file_strerror.mdoc \
	zip_fopen.mdoc \
	zip_fread.mdoc \
	zip_get_archive_comment.mdoc \
	zip_get_archive_flag.mdoc \
	zip_get_file_comment.mdoc \
	zip_get_name.mdoc \
	zip_get_num_files.mdoc \
	zip_name_locate.mdoc \
	zip_open.mdoc \
	zip_rename.mdoc \
	zip_set_archive_comment.mdoc \
	zip_set_archive_flag.mdoc \
	zip_set_file_comment.mdoc \
	zip_source_buffer.mdoc \
	zip_source_file.mdoc \
	zip_source_filep.mdoc \
	zip_source_free.mdoc \
	zip_source_function.mdoc \
	zip_source_zip.mdoc \
	zip_stat.mdoc \
	zip_stat_init.mdoc \
	zip_unchange.mdoc \
	zip_unchange_all.mdoc \
	zip_unchange_archive.mdoc

install-data-hook: link-man3

LN=ln

link-man3: install-man3 uninstall-hook
	${LN} ${DESTDIR}${man3dir}/zip_error_clear.3 \
		${DESTDIR}${man3dir}/zip_file_error_clear.3
	${LN} ${DESTDIR}${man3dir}/zip_error_get.3 \
		${DESTDIR}${man3dir}/zip_file_error_get.3
	${LN} ${DESTDIR}${man3dir}/zip_fopen.3 \
		${DESTDIR}${man3dir}/zip_fopen_index.3
	${LN} ${DESTDIR}${man3dir}/zip_add.3 \
		${DESTDIR}${man3dir}/zip_replace.3
	${LN} ${DESTDIR}${man3dir}/zip_stat.3 \
		${DESTDIR}${man3dir}/zip_stat_index.3
	${LN} ${DESTDIR}${man3dir}/zip_file_strerror.3 \
		${DESTDIR}${man3dir}/zip_strerror.3

uninstall-hook:
	-rm -f ${DESTDIR}${man3dir}/zip_file_error_clear.3
	-rm -f ${DESTDIR}${man3dir}/zip_file_error_get.3
	-rm -f ${DESTDIR}${man3dir}/zip_fopen_index.3
	-rm -f ${DESTDIR}${man3dir}/zip_replace.3
	-rm -f ${DESTDIR}${man3dir}/zip_stat_index.3
	-rm -f ${DESTDIR}${man3dir}/zip_strerror.3

link-html: ${HTML}
	-rm -f zip_file_error_get.html zip_fopen_index.html \
		zip_replace.html zip_stat_index.html \
		zip_strerror.html
	${LN} zip_error_get.html zip_file_error_get.html
	${LN} zip_fopen.html zip_fopen_index.html
	${LN} zip_add.html zip_replace.html
	${LN} zip_stat.html zip_stat_index.html
	${LN} zip_file_strerror.html zip_strerror.html

MANDOC=${MAN1} ${MAN3}
HTML=${MANDOC:.mdoc=.html}
MAN=${MANDOC:.mdoc=.man}

MDOC2MAN=mdoc2man
SUFFIXES=.man .mdoc .html

.PHONY: mkman update-errors

mkman: ${MAN}
mkhtml: ${HTML} link-html

update-errors:
	sh $(srcdir)/make_zip_errors.sh $(srcdir)/../lib/zip.h zip_errors.mdoc

.mdoc.man:
	${MDOC2MAN} $< > $@.$$$$ && mv $@.$$$$ $@

.mdoc.html:
	nroff -mdoc2html $< | sed -e "s,../html[0-9]/,," > $@.$$$$ && mv $@.$$$$ $@
