# Copyright (c) 2004-2021 Microchip Technology Inc. and its subsidiaries.
# SPDX-License-Identifier: MIT

project(MEPA)

cmake_minimum_required(VERSION 3.5)
include(.cmake/mepa-macros.cmake)

include_directories(common/include)

# Offer an options for CI to get good compliation coverage
option(BUILD_MEPA_ALL "Build all MEPA libraries" OFF)
option(MEPA_OPSYS_VELOCITYSP "Build MEPA with OS abstraction for VELOCITYSP" OFF)

mark_as_advanced(BUILD_MEPA_ALL)
mark_as_advanced(MEPA_OPSYS_VELOCITYSP)

# The various drivers append to this, if user select the corresponding options
set(mepa_drvs)
set(mepa_defs)

# Pull in all drivers (alfabetic sorted)
add_subdirectory(aqr)
add_subdirectory(intel)
add_subdirectory(ksz9031)
add_subdirectory(microchip)
add_subdirectory(vtss)
add_subdirectory(dummy_phy)


###############################################################################
## This is the "default" MEPA packet which can be customized using the menus ##
###############################################################################
MEPA_LIB(LIB_NAME mepa
         DEFS     ${mepa_defs}
         DRVS     ${mepa_drvs})


###############################################################################
## Collection of pre-defined MEPA packets. These packets are used by MEBA    ##
## and other higher layer of applications                                    ##
###############################################################################
MEPA_LIB(LIB_NAME mepa_caracal ADVANCED
         DEFS     -DMEPA_HAS_VTSS
         DRVS     mepa_drv_vtss)

MEPA_LIB(LIB_NAME mepa_jr2 ADVANCED
         DEFS     -DMEPA_HAS_VTSS       -DMEPA_HAS_AQR  -DMEPA_HAS_GPY2211
         DRVS     mepa_drv_vtss_10g_ts  mepa_drv_aqr    mepa_drv_intel)

MEPA_LIB(LIB_NAME mepa_jr2_macsec ADVANCED
         DEFS     -DMEPA_HAS_VTSS       -DMEPA_HAS_AQR  -DMEPA_HAS_GPY2211
         DRVS     mepa_drv_vtss_10g_macsec_ts  mepa_drv_aqr    mepa_drv_intel)

MEPA_LIB(LIB_NAME mepa_jr2_bringup ADVANCED
         DEFS     -DMEPA_HAS_VTSS
         DRVS     mepa_drv_vtss_10g_ts)

MEPA_LIB(LIB_NAME mepa_servalt ADVANCED
         DEFS     -DMEPA_HAS_VTSS
         DRVS     mepa_drv_vtss_10g_ts)

MEPA_LIB(LIB_NAME mepa_ocelot ADVANCED
         DEFS     -DMEPA_HAS_VTSS  -DMEPA_HAS_LAN8814
         DRVS     mepa_drv_vtss_ts mepa_drv_lan8814)

MEPA_LIB(LIB_NAME mepa_ocelot_pcb121 ADVANCED
         DEFS     -DMEPA_HAS_VTSS
         DRVS     mepa_drv_vtss_ts)

MEPA_LIB(LIB_NAME mepa_sparx5 ADVANCED
         DEFS     -DMEPA_HAS_VTSS       -DMEPA_HAS_AQR  -DMEPA_HAS_GPY2211  -DMEPA_HAS_LAN8814 -DMEPA_HAS_LAN884x
         DRVS     mepa_drv_vtss_10g_ts  mepa_drv_aqr    mepa_drv_intel      mepa_drv_lan8814    mepa_drv_lan884x)

MEPA_LIB(LIB_NAME mepa_sparx5_macsec ADVANCED
         DEFS     -DMEPA_HAS_VTSS       -DMEPA_HAS_AQR  -DMEPA_HAS_GPY2211  -DMEPA_HAS_LAN8814
         DRVS     mepa_drv_vtss_10g_macsec_ts  mepa_drv_aqr    mepa_drv_intel      mepa_drv_lan8814)

MEPA_LIB(LIB_NAME mepa_sparx5_bringup ADVANCED
         DEFS     -DMEPA_HAS_VTSS
         DRVS     mepa_drv_vtss_10g_ts)

MEPA_LIB(LIB_NAME mepa_lan966x ADVANCED
         DEFS     -DMEPA_HAS_VTSS  -DMEPA_HAS_KSZ9031  -D MEPA_HAS_LAN8814 -DMEPA_HAS_LAN884x
         DRVS     mepa_drv_vtss    mepa_drv_ksz9031    mepa_drv_lan8814   mepa_drv_lan884x)

MEPA_LIB(LIB_NAME mepa_eds2 ADVANCED
         DEFS     -DMEPA_HAS_VTSS  -DMEPA_HAS_KSZ9031  -D MEPA_HAS_LAN8814 -DMEPA_HAS_LAN884x
         DRVS     mepa_drv_vtss    mepa_drv_ksz9031    mepa_drv_lan8814   mepa_drv_lan884x)

MEPA_LIB(LIB_NAME mepa_velocitysp_lan966x ADVANCED
         DEFS     -DMEPA_HAS_LAN8814
         DRVS     mepa_drv_lan8814)

MEPA_LIB(LIB_NAME mepa_velocitysp_lan969x ADVANCED
         DEFS     -DMEPA_HAS_LAN8814 -DMEPA_HAS_LAN884x
         DRVS     mepa_drv_lan8814_light mepa_drv_lan884x)

MEPA_LIB(LIB_NAME mepa_velocitysp_lan969x_auto ADVANCED
         DEFS     -DMEPA_HAS_LAN887X -DMEPA_HAS_LAN884x
         DRVS     mepa_drv_lan887x mepa_drv_lan884x)
