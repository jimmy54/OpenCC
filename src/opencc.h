/*
* Open Chinese Convert
*
* Copyright 2010 BYVoid <byvoid1@gmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __OPENCC_H_
#define __OPENCC_H_

#include "opencc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Headers from C standard library
 */
#include <wchar.h>

/* Macros */
#define OPENCC_CONVERT_ERROR ((size_t) -1)
#define OPENCC_DICHEADER "OPENCCDATRIE"

/**
 * opencc_open:
 * @convert_direction: Direction of convert.
 * @returns: A description pointer of the newly allocated instance of opencc.
 *
 * Make an instance of opencc.
 *
 */
opencc_t opencc_open(const char * config_file);

/**
 * opencc_close:
 * @od: The description pointer.
 * @returns: 0 on success or non-zero number on failure.
 *
 * Destroy an instance of opencc.
 *
 */
int opencc_close(opencc_t od);

/**
 * opencc_convert:
 * @od: The description pointer.
 * @inbuf: The pointer to the wide character string of the input buffer.
 * @inbufleft: The maximum number of characters in *inbuf to convert.
 * @outbuf: The pointer to the wide character string of the output buffer.
 * @outbufleft: The size of output buffer.
 *
 * @returns: The number of characters of the input buffer that converted.
 *
 * Convert string from *inbuf to *outbuf.
 *
 * (Note: Don't forget to assign **outbuf to L'\0' after this method called.)
 *
 */
size_t opencc_convert(opencc_t od, wchar_t ** inbuf, size_t * inbufleft,
		wchar_t ** outbuf, size_t * outbufleft);

char * opencc_convert_utf8(opencc_t odt, const char * inbuf, size_t length);

int opencc_dict_load(opencc_t odt, const char * dict_filename,
		opencc_dictionary_type dict_type);

/**
 * opencc_errno:
 * @od: The description pointer.
 *
 * @returns: The error number.
 *
 * Return an opencc_convert_errno_t which describes the last error that occured or
 * OPENCC_CONVERT_ERROR_VOID
 *
 */
opencc_convert_errno_t opencc_errno(opencc_t od);

/**
 * opencc_perror:
 * @od: The description pointer.
 *
 * Print the error message to stderr when errno is set.
 *
 */
void opencc_perror(opencc_t od);

#ifdef __cplusplus
};
#endif

/**
 * c++ wrapper for opencc
 */

#ifdef __cplusplus
#include "openccxx.h"
#endif

#endif /* __OPENCC_H_ */
