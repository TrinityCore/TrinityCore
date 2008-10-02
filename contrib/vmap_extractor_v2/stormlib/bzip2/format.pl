#!/usr/bin/perl -w
use strict;

# get command line values:
if ( $#ARGV !=1 ) {
    die "Usage:  $0 xml_infile xml_outfile\n";
}

my $infile = shift;
# check infile exists
die "Can't find file \"$infile\""
  unless -f $infile;
# check we can read infile
if (! -r $infile) {
    die "Can't read input $infile\n";
}
# check we can open infile
open( INFILE,"<$infile" ) or 
    die "Can't input $infile $!";

#my $outfile = 'fmt-manual.xml';
my $outfile = shift;
#print "Infile: $infile, Outfile: $outfile\n";
# check we can write to outfile
open( OUTFILE,">$outfile" ) or 
    die "Can't output $outfile $! for writing";

my ($prev, $curr, $str);
$prev = ''; $curr = '';
while ( <INFILE> ) {

		print OUTFILE $prev;
    $prev = $curr;
    $curr = $_;
    $str = '';

    if ( $prev =~ /<programlisting>$|<screen>$/ ) {
        chomp $prev;
        $curr = join( '', $prev, "<![CDATA[", $curr );
				$prev = '';
        next;
    }
    elsif ( $curr =~ /<\/programlisting>|<\/screen>/ ) {
        chomp $prev;
        $curr = join( '', $prev, "]]>", $curr );
				$prev = '';
        next;
    }
}
print OUTFILE $curr;
close INFILE;
close OUTFILE;
exit;
