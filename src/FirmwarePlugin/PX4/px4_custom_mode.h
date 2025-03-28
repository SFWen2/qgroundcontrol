/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

/****************************************************************************
 *
 * Copyright (c) 2013-2020 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file px4_custom_mode.h
 * PX4 custom flight modes
 *
 */

#ifndef PX4_CUSTOM_MODE_H_
#define PX4_CUSTOM_MODE_H_

#include <stdint.h>

enum PX4_CUSTOM_MAIN_MODE {
	PX4_CUSTOM_MAIN_MODE_MANUAL = 1,
	PX4_CUSTOM_MAIN_MODE_ALTCTL,
	PX4_CUSTOM_MAIN_MODE_POSCTL,
	PX4_CUSTOM_MAIN_MODE_AUTO,
	PX4_CUSTOM_MAIN_MODE_ACRO,
	PX4_CUSTOM_MAIN_MODE_OFFBOARD,
	PX4_CUSTOM_MAIN_MODE_STABILIZED,
	PX4_CUSTOM_MAIN_MODE_RATTITUDE,
	PX4_CUSTOM_MAIN_MODE_SIMPLE /* unused, but reserved for future use */
};

enum PX4_CUSTOM_SUB_MODE_AUTO {
	PX4_CUSTOM_SUB_MODE_AUTO_READY = 1,
	PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF,
	PX4_CUSTOM_SUB_MODE_AUTO_LOITER,
	PX4_CUSTOM_SUB_MODE_AUTO_MISSION,
	PX4_CUSTOM_SUB_MODE_AUTO_RTL,
	PX4_CUSTOM_SUB_MODE_AUTO_LAND,
	PX4_CUSTOM_SUB_MODE_AUTO_RTGS,
	PX4_CUSTOM_SUB_MODE_AUTO_FOLLOW_TARGET,
	PX4_CUSTOM_SUB_MODE_AUTO_PRECLAND
};

enum PX4_CUSTOM_SUB_MODE_POSCTL {
    PX4_CUSTOM_SUB_MODE_POSCTL_POSCTL = 0,
    PX4_CUSTOM_SUB_MODE_POSCTL_ORBIT
};

union px4_custom_mode {
    struct {
        uint16_t reserved;
        uint8_t main_mode;
        uint8_t sub_mode;
    };
    uint32_t data;
    float data_float;
    struct {
        uint16_t reserved_hl;
        uint16_t custom_mode_hl;
    };
};

struct PX4CustomMode{
    enum Mode : uint32_t{
        MANUAL              = PX4_CUSTOM_MAIN_MODE_MANUAL       <<16,
        STABILIZED          = PX4_CUSTOM_MAIN_MODE_STABILIZED   <<16,
        ACRO                = PX4_CUSTOM_MAIN_MODE_ACRO         <<16,
        RATTITUDE           = PX4_CUSTOM_MAIN_MODE_RATTITUDE    <<16,
        ALTCTL              = PX4_CUSTOM_MAIN_MODE_ALTCTL       <<16,
        OFFBOARD            = PX4_CUSTOM_MAIN_MODE_OFFBOARD     <<16,
        SIMPLE              = PX4_CUSTOM_MAIN_MODE_SIMPLE       <<16,
        POSCTL_POSCTL       = PX4_CUSTOM_MAIN_MODE_POSCTL       <<16 | (PX4_CUSTOM_SUB_MODE_POSCTL_POSCTL      << 24 ),
        POSCTL_ORBIT        = PX4_CUSTOM_MAIN_MODE_POSCTL       <<16 | (PX4_CUSTOM_SUB_MODE_POSCTL_ORBIT       << 24 ),
        AUTO_LOITER         = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_LOITER        << 24 ),
        AUTO_MISSION        = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_MISSION       << 24 ),
        AUTO_RTL            = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_RTL           << 24 ),
        AUTO_FOLLOW_TARGET  = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_FOLLOW_TARGET << 24 ),
        AUTO_LAND           = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_LAND          << 24 ),
        AUTO_PRECLAND       = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_PRECLAND      << 24 ),
        AUTO_READY          = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_READY         << 24 ),
        AUTO_RTGS           = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_RTGS          << 24 ),
        AUTO_TAKEOFF        = PX4_CUSTOM_MAIN_MODE_AUTO         <<16 | (PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF       << 24 ),
    };
};

#endif /* PX4_CUSTOM_MODE_H_ */
