// Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
// SPDX-License-Identifier: MIT

/*
 * This file is autogenerated by cml-utils 2021-04-13 14:16:28 +0000.
 * Commit ID: 377a55eebafe278cd5b557227fe13f6167fe1821
 */

#ifndef _VTSS_LAN966X_VCAP_AG_API_H_
#define _VTSS_LAN966X_VCAP_AG_API_H_

#include "vtss_lan966x_vcap_ag_layout.h"

/*******************************************************************************
 * VCAP ES0
 ******************************************************************************/
int vtss_lan966x_vcap_es0_key_pack(const struct vtss_lan966x_vcap_es0_key_fields *fields,
                                   struct vtss_lan966x_vcap_data                 *data);

int vtss_lan966x_vcap_es0_action_pack(const struct vtss_lan966x_vcap_es0_action_fields *fields,
                                      struct vtss_lan966x_vcap_data                    *data);

/*******************************************************************************
 * VCAP IS1
 ******************************************************************************/
int vtss_lan966x_vcap_is1_key_pack(const struct vtss_lan966x_vcap_is1_key_fields *fields,
                                   struct vtss_lan966x_vcap_data                 *data);

int vtss_lan966x_vcap_is1_action_pack(const struct vtss_lan966x_vcap_is1_action_fields *fields,
                                      struct vtss_lan966x_vcap_data                    *data);

/*******************************************************************************
 * VCAP IS2
 ******************************************************************************/
int vtss_lan966x_vcap_is2_key_pack(const struct vtss_lan966x_vcap_is2_key_fields *fields,
                                   struct vtss_lan966x_vcap_data                 *data);

int vtss_lan966x_vcap_is2_action_pack(const struct vtss_lan966x_vcap_is2_action_fields *fields,
                                      struct vtss_lan966x_vcap_data                    *data);

/*******************************************************************************
 * VCAP Common
 ******************************************************************************/
#define VTSS_LAN966X_VCAP_MAX_SW_WIDTH     96
#define VTSS_LAN966X_VCAP_MAX_STICKY_WIDTH 32
#define VTSS_LAN966X_VCAP_MAX_ACT_WIDTH    123

#define VTSS_LAN966X_VCAP_MAX_NUM_KEYS    13
#define VTSS_LAN966X_VCAP_MAX_NUM_ACTIONS 2

enum vtss_lan966x_vcap {
    VTSS_LAN966X_VCAP_ES0,
    VTSS_LAN966X_VCAP_IS1,
    VTSS_LAN966X_VCAP_IS2,
    VTSS_LAN966X_VCAP_LAST
};

struct vtss_lan966x_vcap_attrs {
    char *name;
    u32   instance;
    u32   rows;
    u32   sw_count;
    u32   sw_width;
    u32   sticky_width;
    u32   act_width;
    u32   default_cnt;
    u32   require_cnt_dis;
    u32   version;
};

const struct vtss_lan966x_vcap_attrs *vtss_lan966x_vcap_attrs_get(enum vtss_lan966x_vcap vcap);

struct vtss_lan966x_vcap_tg_bit {
    u32 width;
    u32 val;
};

struct vtss_lan966x_vcap_tgs_attrs {
    char                           *name;
    u32                             tg_width;
    u32                             tg_val;
    u32                             type_width;
    u32                             max_width;
    struct vtss_lan966x_vcap_tg_bit tg_bits[4];
};

const struct vtss_lan966x_vcap_tgs_attrs *vtss_lan966x_vcap_key_tgs_attrs_get(enum vtss_lan966x_vcap
                                                                                  vcap,
                                                                              u32 sw_per_entry);

const struct vtss_lan966x_vcap_tgs_attrs *vtss_lan966x_vcap_action_tgs_attrs_get(enum vtss_lan966x_vcap
                                                                                     vcap,
                                                                                 u32 sw_per_entry);

struct vtss_lan966x_vcap_key_attrs {
    char *name;
    u32   type_id;
    u32   type_width;
    u32   width;
    u32   sw_per_entry;
    u32   sw_cnt;
};

const struct vtss_lan966x_vcap_key_attrs *vtss_lan966x_vcap_key_attrs_get(enum vtss_lan966x_vcap
                                                                              vcap,
                                                                          int key);

struct vtss_lan966x_vcap_action_attrs {
    char *name;
    u32   type_id;
    u32   type_width;
    u32   width;
    u32   sw_per_action;
    u32   sw_cnt;
};

const struct vtss_lan966x_vcap_action_attrs *vtss_lan966x_vcap_action_attrs_get(enum vtss_lan966x_vcap
                                                                                    vcap,
                                                                                int action);

#ifdef VTSS_LAN966X_VCAP_INCLUDE_FIELD_ATTRS

struct vtss_lan966x_vcap_field_attrs {
    char *name;
    u32   offset;
    u32   length;
};

const struct vtss_lan966x_vcap_field_attrs *vtss_lan966x_vcap_key_field_attrs_get(
    enum vtss_lan966x_vcap vcap,
    int                    key,
    u32                    index);

const struct vtss_lan966x_vcap_field_attrs *vtss_lan966x_vcap_action_field_attrs_get(
    enum vtss_lan966x_vcap vcap,
    int                    action,
    u32                    index);

#endif /* VTSS_LAN966X_VCAP_INCLUDE_FIELD_ATTRS */

#endif /* _VTSS_LAN966X_VCAP_AG_API_H_ */
