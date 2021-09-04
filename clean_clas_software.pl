#!/usr/bin/perl

my $topdir   = "";
my $osname   = "";

if($#ARGV != 3) {
  print "Missing arguments $#ARGV\n";
  print_help();
}

process_args();

if(!(-d $topdir)) {
  print "directory $topdir does not exists\n";
  exit(0);
}

$claspack = "$topdir/packages/";
$incdir   = "$claspack/inc_derived/";
$bnkdir   = "$claspack/bankdefs/";

@rmv_olb = ("$topdir/bin","$topdir/lib","$topdir/slib","$topdir/obj","$claspack/ClasTool/bin","$claspack/ClasTool/slib","$claspack/ClasTool/include");
@rmv_inc = ("$incdir/clasbanks.h","$incdir/clas_index.inc","$incdir/clas_offsets.inc");
@rmv_bnk = ("$bnkdir/clasbanks.ddl","$bnkdir/clasbanks.cc");
@rmv_os  = `find $claspack -name $osname`;
@rmv_dep = `find $claspack -name depends`;
@rmv_obj = `find $claspack -name obj`;
@rmv_dic = `find $claspack -name dicts`;
@rmv_a   = `find $claspack -name "*.a"`;
@rmv_o   = `find $claspack -name "*.o"`;
@rmv_oo  = `find $claspack -name "*.oo"`;
@rmv_so  = `find $claspack -name "*.so"`;
@rmv_d   = `find $claspack -name "*.d"`;
@rmv_dd  = `find $claspack -name "*.dd"`;
@rmv_md  = `find $claspack -name "Makefile_depends"`;

$cmd0 = "rm -f $topdir/make.log";
system ($cmd0);

$cmd1 = "rm -rf $claspack/ClasTool/html/{*.html,*.ps,*.pdf,*.h,*.root,*.css,*.js,*.png,*.gif}";
system ($cmd1);

$cmd2 = "rm -rf $claspack/ClasTool/html/{src,incl,inh,inhmem,lib}";
system ($cmd2);

print "Removing rmv_olb $#rmv_olb\n";
rmvfunc(0,@rmv_olb);

print "Removing rmv_inc $#rmv_inc\n";
rmvfunc(0,@rmv_inc);

print "Removing rmv_bnk $#rmv_bnk\n";
rmvfunc(0,@rmv_bnk);

print "Removing rmv_os $#rmv_os\n";
if($#rmv_os >= 0) {rmvfunc(1,@rmv_os);}

print "Removing rmv_dep $#rmv_dep\n";
if($#rmv_dep >= 0) {rmvfunc(1,@rmv_dep);}

print "Removing rmv_obj $#rmv_obj\n";
if($#rmv_obj >= 0) {rmvfunc(1,@rmv_obj);}

print "Removing rmv_dic $#rmv_dic\n";
if($#rmv_dic >= 0) {rmvfunc(1,@rmv_dic);}

print "Removing rmv_a $#rmv_a\n";
if($#rmv_a >= 0) {rmvfunc(1,@rmv_a);}

print "Removing rmv_o $#rmv_o\n";
if($#rmv_o >= 0) {rmvfunc(1,@rmv_o);}

print "Removing rmv_oo $#rmv_oo\n";
if($#rmv_oo >= 0) {rmvfunc(1,@rmv_oo);}

print "Removing rmv_so $#rmv_so\n";
if($#rmv_so >= 0) {rmvfunc(1,@rmv_so);}

print "Removing rmv_d $#rmv_d\n";
if($#rmv_d >= 0) {rmvfunc(1,@rmv_d);}

print "Removing rmv_dd $#rmv_dd\n";
if($#rmv_dd >= 0) {rmvfunc(1,@rmv_dd);}

print "Removing rmv_md $#rmv_md\n";
if($#rmv_md >= 0) {rmvfunc(1,@rmv_md);}

=pod
=cut

########################################################

sub rmvfunc
{
  local($a,@list) = ($_[0],@_);
  if($#list == 0) {exit(0);}
  #print "size $#list\n";
  for($ic = 1; $ic <= $#list; $ic++) {
    $t = $list[$ic];
    #print "$a, $t\n";

    if( $a == 1 ) {chop($t);}
    if(-f $t) {
      print "remove $t \n";
      system (" rm -rf $t");
    }
    elsif(-d $t) {
      print "remove $t \n";
      system (" rm -rf $t");
    }
    else {
      print "$t does not exist \n"; #exit(0);
    }
  }
}

########################################################

sub print_help()
{
  print "Usage: \n";
  print "<script_name> --osname <osname> --topdir <topdir>";
  print "\n";
  print "Where:\n";
  print "  <osname>  = Env. Variable OS Name\n";
  print "  <topdir>  = package dir to be cleaned\n";
  exit(0);
}

#########################################################

sub process_args()
{
  $iv = 0;
  while($iv < $#ARGV) {
    if   ($ARGV[$iv] eq '--osname')  {$osname = $ARGV[++$iv];}
    elsif($ARGV[$iv] eq '--topdir')  {$topdir = $ARGV[++$iv];}
    else {
      print "bad arguments: $ARGV[$iv]\n";
      print_help(); 
    }
    $iv++;
  }
}
