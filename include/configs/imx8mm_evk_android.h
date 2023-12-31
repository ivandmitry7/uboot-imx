/*
 * Copyright 2020 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef IMX8MM_EVK_ANDROID_H
#define IMX8MM_EVK_ANDROID_H

#define FSL_FASTBOOT_FB_DEV "mmc"

#undef CFG_EXTRA_ENV_SETTINGS
#undef CONFIG_BOOTCOMMAND

#define CFG_EXTRA_ENV_SETTINGS		\
	"splashpos=m,m\0"			\
	"splashimage=0x50000000\0"		\
	"fdt_high=0xffffffffffffffff\0"		\
	"initrd_high=0xffffffffffffffff\0"	\
	"emmc_dev=2\0"\
	"sd_dev=1\0" \

/* Enable mcu firmware flash */
#ifdef CONFIG_FLASH_MCUFIRMWARE_SUPPORT
#define ANDROID_MCU_FRIMWARE_DEV_TYPE DEV_MMC
#define ANDROID_MCU_FIRMWARE_START 0x500000
#define ANDROID_MCU_OS_PARTITION_SIZE 0x40000
#define ANDROID_MCU_FIRMWARE_SIZE  0x20000
#define ANDROID_MCU_FIRMWARE_HEADER_STACK 0x20020000
#endif

#define CFG_SYS_SPL_PTE_RAM_BASE    0x41580000

#ifdef CONFIG_IMX_TRUSTY_OS
#define BOOTLOADER_RBIDX_OFFSET  0x3FE000
#define BOOTLOADER_RBIDX_START   0x3FF000
#define BOOTLOADER_RBIDX_LEN     0x08
#define BOOTLOADER_RBIDX_INITVAL 0
#endif

#ifdef CONFIG_IMX_TRUSTY_OS
#define AVB_RPMB
#define KEYSLOT_HWPARTITION_ID 2
#define KEYSLOT_BLKS             0x1FFF
#define NS_ARCH_ARM64 1

#endif

/* Enable CONFIG_IMX8M_1G_MEMORY  to config 1GB ddr */
#ifdef CONFIG_IMX8M_1G_MEMORY
#undef  PHYS_SDRAM_SIZE
#define PHYS_SDRAM_SIZE 0x40000000 /* 1GB DDR */
#endif

#ifdef CONFIG_IMX8M_4G_LPDDR4
#undef PHYS_SDRAM_SIZE
#define PHYS_SDRAM_SIZE          0xC0000000 /* 3GB */
#define PHYS_SDRAM_2             0x100000000
#define PHYS_SDRAM_2_SIZE        0x40000000 /* 1GB */
#endif

#endif /* IMX8MM_EVK_ANDROID_H */
