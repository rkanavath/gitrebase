#!/bin/sh

CURDIR=$1
VERSION=$3
MANDIR=$CURDIR/debian/manpages
BINDIR=$CURDIR/$2/bin
LIBDIR=$CURDIR/$2/lib

export PATH=$PATH:$BINDIR
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LIBDIR

help2man $BINDIR/otbTestDriver --no-discard-stderr --version-string=$VERSION  -o $MANDIR/otbTestDriver.1 ;
for file in `ls $BINDIR/otbcli* $BINDIR/otb*Launcher*` ; do
     echo "Generating man pages $file"
     help2man `basename $file` --no-discard-stderr --help-option='-help' --version-string=$VERSION -o $MANDIR/`basename $file`.1;
 done

for file in `ls $BINDIR/otbgui*` ; do
    echo "Generating man pages $file"
    help2man `basename $file` --no-discard-stderr --help-option='-help' --version-string=$VERSION -o $MANDIR/`basename $file`.1;
done

for file in `ls $MANDIR/*1 ` ; do
    #echo "Fix man pages $file"
    sed -i 's/.PP.*Inconsistency.detected.by.ld.*_dl_close.*Assertion.*_init_called.*failed//g' $file;
done
