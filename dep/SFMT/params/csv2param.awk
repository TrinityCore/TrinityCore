#!/usr/bin/awk -f
#
#
#
#
#
BEGIN {
    if (length(ARGV) <= 2) {
	usage();
	exit;
    } else {
	FS=",";
	line = ARGV[1] + 1;
	delete ARGV[1];
    }
}

NR == line { print_variable();}

function usage() {
    printf("usage:\n");
    printf("csv2param.awk line-no csv-filename\n");
}

function print_variable() {
  #printf("#ifndef SFMT_PARAMS%s_H\n", $1);
  #printf("#define SFMT_PARAMS%s_H\n\n", $1);
  printf("#define POS1\t%s\n", $3);
  printf("#define SL1\t%s\n", $4);
  printf("#define SL2\t%s\n", $5);
  printf("#define SR1\t%s\n", $6);
  printf("#define SR2\t%s\n", $7);
  printf("#define MSK1\t0x%sU\n", $8);
  printf("#define MSK2\t0x%sU\n", $9);
  printf("#define MSK3\t0x%sU\n", $10);
  printf("#define MSK4\t0x%sU\n", $11);
  printf("#define PARITY1\t0x%sU\n", $12);
  printf("#define PARITY2\t0x%sU\n", $13);
  printf("#define PARITY3\t0x%sU\n", $14);
  printf("#define PARITY4\t0x%sU\n", $15);

  printf("\n\n/* PARAMETERS FOR ALTIVEC */\n")
  printf("#if defined(__APPLE__)\t/* For OSX */\n")
  printf("    #define ALTI_SL1\t(vector unsigned int)(SL1, SL1, SL1, SL1)\n")
  printf("    #define ALTI_SR1\t(vector unsigned int)(SR1, SR1, SR1, SR1)\n")
  printf("    #define ALTI_MSK\t")
  printf("(vector unsigned int)(MSK1, MSK2, MSK3, MSK4)\n")
  printf("    #define ALTI_MSK64 \\\n")
  printf("\t(vector unsigned int)(MSK2, MSK1, MSK4, MSK3)\n")

  cnt = 16;
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SL2_PERM \\\n\t(vector unsigned char)(%s)\n", s);
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SL2_PERM64 \\\n\t(vector unsigned char)(%s)\n", s);
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SR2_PERM \\\n\t(vector unsigned char)(%s)\n", s);
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SR2_PERM64 \\\n\t(vector unsigned char)(%s)\n", s);
  printf("#else\t/* For OTHER OSs(Linux?) */\n")
  printf("    #define ALTI_SL1\t{SL1, SL1, SL1, SL1}\n")
  printf("    #define ALTI_SR1\t{SR1, SR1, SR1, SR1}\n")
  printf("    #define ALTI_MSK\t{MSK1, MSK2, MSK3, MSK4}\n")
  printf("    #define ALTI_MSK64\t{MSK2, MSK1, MSK4, MSK3}\n")
  cnt = 16;
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SL2_PERM\t{%s}\n", s);
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SL2_PERM64\t{%s}\n", s);
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SR2_PERM\t{%s}\n", s);
  s = $(cnt++);
  for (i = 1; i < 16; i++) {
      s = s "," $(cnt++);
  }
  printf("    #define ALTI_SR2_PERM64\t{%s}\n", s);
  printf("#endif\t/* For OSX */\n")
  printf("#define IDSTR\t\"SFMT-%s:%s-%s-%s-%s-%s:%s-%s-%s-%s\"\n",
         $1, $3, $4, $5, $6, $7, $8, $9, $10, $11);
  #printf("\n#endif /* SFMT_PARAMS%s_H */\n", $1);
}
