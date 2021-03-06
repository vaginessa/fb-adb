/*
 *  Copyright (c) 2014, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in
 *  the LICENSE file in the root directory of this source tree. An
 *  additional grant of patent rights can be found in the PATENTS file
 *  in the same directory.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "util.h"
#include "autocmd.h"
#include "fs.h"

FORWARD(readlink);

#if !FBADB_MAIN
int
readlink_main(const struct cmd_readlink_info* info)
{
    char* linkname = xreadlink(info->link);
    size_t len = strlen(linkname);
    write_all(STDOUT_FILENO, linkname, len);
    return 0;
}
#endif
