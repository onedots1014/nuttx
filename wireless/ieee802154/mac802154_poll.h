/****************************************************************************
 * wireless/ieee802154/mac802154_poll.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __WIRELESS_IEEE802154__MAC802154_POLL_H
#define __WIRELESS_IEEE802154__MAC802154_POLL_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include <nuttx/wireless/ieee802154/ieee802154_mac.h>
#include <nuttx/wireless/ieee802154/ieee802154_radio.h>

/****************************************************************************
 * Function Prototypes
 ****************************************************************************/

struct ieee802154_privmac_s; /* Forward Reference */

void mac802154_txdone_datareq_poll(FAR struct ieee802154_privmac_s *priv,
                                   FAR struct ieee802154_txdesc_s *txdesc);

#endif /* __WIRELESS_IEEE802154__MAC802154_POLL_H */
