/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2023 Variscite Ltd.
 */

int var_get_som_rev(struct var_eeprom *ep);

enum {
    SOM_REV_10,
    SOM_REV_11,
    SOM_REV_12,
    SOM_REV_13,
    UNKNOWN_REV
};
