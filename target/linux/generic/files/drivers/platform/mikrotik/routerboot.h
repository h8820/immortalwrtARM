// SPDX-License-Identifier: GPL-2.0
/*
 * Common definitions for MikroTik RouterBoot data.
 *
 * Copyright (C) 2020 Thibaut VARÈNE <hacks+kernel@slashdirt.org>
 */


#ifndef _ROUTERBOOT_H_
#define _ROUTERBOOT_H_

#include <linux/types.h>

// these magic values are stored in cpu-endianness on flash
#define RB_MAGIC_HARD	(('H') | ('a' << 8) | ('r' << 16) | ('d' << 24))
#define RB_MAGIC_SOFT	(('S') | ('o' << 8) | ('f' << 16) | ('t' << 24))
#define RB_MAGIC_LZOR	(('L') | ('Z' << 8) | ('O' << 16) | ('R' << 24))
#define RB_MAGIC_ERD	(('E' << 16) | ('R' << 8) | ('D'))

#define RB_ART_SIZE	0x10000

#define RB_MTD_HARD_CONFIG	"hard_config"
#define RB_MTD_SOFT_CONFIG	"soft_config"

int routerboot_tag_find(const u8 *bufhead, const size_t buflen, const u16 tag_id, u16 *pld_ofs, u16 *pld_len);
int routerboot_rle_decode(const u8 *in, size_t inlen, u8 *out, size_t *outlen);

int __init rb_hardconfig_init(struct kobject *rb_kobj);
void __exit rb_hardconfig_exit(void);

ssize_t routerboot_tag_show_string(const u8 *pld, u16 pld_len, char *buf);

#endif /* _ROUTERBOOT_H_ */
