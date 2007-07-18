/*
    crypto.c -- Cryptographic miscellaneous functions and initialisation
    Copyright (C) 2007 Guus Sliepen <guus@tinc-vpn.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    $Id$
*/

#include "system.h"

#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/engine.h>

#include "crypto.h"

void crypto_init() {
        RAND_load_file("/dev/urandom", 1024);

        ENGINE_load_builtin_engines();
        ENGINE_register_all_complete();

        OpenSSL_add_all_algorithms();
}

void crypto_exit() {
	EVP_cleanup();
}

void randomize(void *out, size_t outlen) {
	RAND_pseudo_bytes(out, outlen);
}