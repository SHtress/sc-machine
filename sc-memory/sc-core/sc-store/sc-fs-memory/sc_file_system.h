/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#ifndef _sc_file_system_h_
#define _sc_file_system_h_

#include "../sc_types.h"

sc_bool sc_fs_create_file(sc_char const * path);

sc_bool sc_fs_remove_file(sc_char const * path);

sc_bool sc_fs_is_file(sc_char const * path);

sc_bool sc_fs_is_binary_file(sc_char const * file_path);

void sc_fs_get_file_content(sc_char const * file_path, sc_char ** content, sc_uint64 * content_size);

sc_bool sc_fs_create_if_is_not_file(sc_char const * path);

sc_bool sc_fs_create_directory(const sc_char * path);

sc_bool sc_fs_remove_directory(const sc_char * path);

sc_bool sc_fs_is_directory(const sc_char * path);

void * sc_fs_new_tmp_write_channel(const sc_char * path, sc_char ** tmp_file_name, sc_char * prefix);

void sc_fs_concat_path(sc_char const * path, sc_char const * postfix, sc_char ** out_path);

sc_char * sc_fs_execute(sc_char const * command);

#endif
