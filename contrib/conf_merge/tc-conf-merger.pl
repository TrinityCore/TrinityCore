#!/usr/bin/perl -w

# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
# Author: leak
# Date: 2010-12-06
# Note: Based on conf file format of rev 10507

use strict;

if (@ARGV != 3)
{
    print("Usage:\ntc-conf-merger.pl <path to new .conf.dist> <path to old .conf> <path to output .conf>\n");
    exit(1);
}

if (! -e $ARGV[0])
{
    print("No file found at: ".$ARGV[0]);
    exit(1);
}
elsif (! -e $ARGV[1])
{
    print("No file found at: ".$ARGV[1]);
    exit(1);
}

open CONFDIST, "<", $ARGV[0] or die "Error: Could not open ".$ARGV[0]."\n";
my $confdist = join "", <CONFDIST>;
close CONFDIST;

open CONFOLD, "<", $ARGV[1] or die "Error: Could not open ".$ARGV[1]."\n";
my $confold = join "", <CONFOLD>;
close CONFOLD;

while ($confold =~ m/^(?!#)(.*?)\s+?=\s+?(.*?)$/mg) {
    my $key = $1, my $value = $2;
        $confdist =~ s/^(\Q$key\E)(\s+?=\s+?)(.*)/$1$2$value/mg;
}

open OUTPUT, ">", $ARGV[2] or die "Error: Could not open ".$ARGV[2]."\n";
binmode(OUTPUT);
print OUTPUT $confdist;
close OUTPUT;
