noinst_PROGRAMS= \
	add_dir \
	add_from_buffer \
	add_from_file \
	add_from_filep \
	encrypt \
	fread \
	get_comment \
	open \
	name_locate \
	set_comment_all \
	set_comment_localonly \
	set_comment_removeglobal \
	set_comment_revert

EXTRA_PROGRAMS=deltest ziptest

EXTRA_DIST= \
	CMakeLists.txt \
	runtest \
	${TESTS} \
	broken.zip \
	encrypt.zip \
	test.zip \
	testbuffer.zip \
	testdir.zip \
	testchanged.zip \
	testchangedlocal.zip \
	testcomment.zip \
	testcommentremoved.zip \
	testfile.txt \
	testfile.zip \
	testnottorrent.zip \
	testtorrent.tzip

TESTS_ENVIRONMENT=	ZIPCMP=${top_builddir}/src/zipcmp ${srcdir}/runtest

TESTS= \
	add_dir.test \
	add_from_buffer.test \
	add_from_file.test \
	add_from_filep.test \
	encrypt.test \
	fread.test \
	get_comment.test \
	name_locate.test \
	open.test \
	set_comment_all.test \
	set_comment_localonly.test \
	set_comment_removeglobal.test \
	set_comment_revert.test \
	torrent-already.test \
	torrent-new.test

AM_CPPFLAGS=-I${top_srcdir}/lib
LDADD=${top_builddir}/lib/libzip.la
