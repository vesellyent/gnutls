#!/bin/bash

# Copyright (C) 2016-2017 Red Hat, Inc.
#
# This file is part of GnuTLS.
#
# GnuTLS is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at
# your option) any later version.
#
# GnuTLS is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GnuTLS; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

srcdir="${srcdir:-.}"
SERV="../../../../src/gnutls-serv${EXEEXT}"
CLI="../../../../src/gnutls-cli${EXEEXT}"

OUTFILE=tls-fuzzer.debug.log
TMPFILE=tls-fuzzer.$$.tmp

. "${srcdir}/../scripts/common.sh"

eval "${GETPORT}"

pushd tls-fuzzer

if ! test -d tlsfuzzer;then
	exit 77
fi

rm -f "$OUTFILE"

pushd tlsfuzzer
test -L ecdsa || ln -s ../python-ecdsa/src/ecdsa ecdsa
test -L tlslite || ln -s ../tlslite-ng/tlslite tlslite 2>/dev/null

wait_for_free_port $PORT

retval=0

PRIORITY="NORMAL:-VERS-ALL:+VERS-TLS1.3:+VERS-TLS1.2:+VERS-TLS1.1"

TLS_PY=./tlslite-ng/scripts/tls.py
#TLS_PY=$(which tls.py)

sed -e "s|@SERVER@|$SERV|g" -e "s/@PORT@/$PORT/g" -e "s/@PRIORITY@/$PRIORITY/g" ../gnutls-nocert-tls13.json >${TMPFILE}

PYTHONPATH=. python tests/scripts_retention.py ${TMPFILE} ${SERV}
retval=$?

rm -f ${TMPFILE}

popd
popd

exit $retval
