#!/bin/sh

CURDIR=$1
VERSION=$3
MANDIR=$CURDIR/debian/manpages
BINDIR=$CURDIR/$2/bin
LIBDIR=$CURDIR/$2/lib

export PATH=$PATH:$BINDIR
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LIBDIR

help2man $BINDIR/otbTestDriver --no-discard-stderr --version-string=$VERSION  -o $MANDIR/otbTestDriver.1
for file in `ls $BINDIR/otbcli*` ; do
    echo "Generating man pages $file"
    SCRIPTFILE=`basename $file`
    APPNAME=$(echo $SCRIPTFILE| cut -d'_' -f 2)
    help2man $SCRIPTFILE --no-discard-stderr --help-option='-help' --name="OTB $APPNAME application" --version-string=$VERSION -o $MANDIR/otbcli_$APPNAME.1
done

for file in $BINDIR/otbTestDriver `ls $BINDIR/otb*Launcher*` ; do
    echo "Generating man pages $file"
    SCRIPTFILE=`basename $file`
    help2man $SCRIPTFILE --no-discard-stderr --help-option=' ' --name="OTB $SCRIPTFILE " --version-string=$VERSION -o $MANDIR/$SCRIPTFILE.1
done

for file in `ls $MANDIR/*1 ` ; do
    #echo "Fix man pages $file. This is because of the itk version < 4.7.2"
    sed -i 's/^Inconsistency.detected.by.ld.*_dl_close.*Assertion.*_init_called.*failed.//g' $file;
done

for file in `ls $BINDIR/otbgui*` ; do
#    echo "Generating man pages $file"
    SCRIPTFILE=`basename $file`
    APPNAME=$(echo $SCRIPTFILE| cut -d'_' -f 2)
    echo "Generating man pages $APPNAME"
    cp $MANDIR/otbcli_$APPNAME.1 $MANDIR/otbgui_$APPNAME.1
    sed -i 's/otbcli_/otbgui_/g' $MANDIR/otbgui_$APPNAME.1
    sed -i 's/OTBCLI_/OTBGUI_/g' $MANDIR/otbgui_$APPNAME.1
done
