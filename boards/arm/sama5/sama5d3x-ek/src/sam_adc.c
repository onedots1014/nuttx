/****************************************************************************
 * boards/arm/sama5/sama5d3x-ek/src/sam_adc.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <errno.h>
#include <debug.h>

#include <nuttx/board.h>
#include <nuttx/analog/adc.h>

#include "sam_adc.h"
#include "sama5d3x-ek.h"

#ifdef CONFIG_ADC

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: sam_adc_setup
 *
 * Description:
 *   Initialize ADC and register the ADC driver.
 *
 ****************************************************************************/

int sam_adc_setup(void)
{
#ifdef CONFIG_SAMA5_ADC
  static bool initialized = false;
  struct adc_dev_s *adc;
  int ret;

  /* Check if we have already initialized */

  if (!initialized)
    {
      /* Call stm32_adcinitialize() to get an instance of the ADC interface */

      adc = sam_adc_initialize();
      if (adc == NULL)
        {
          aerr("ERROR: Failed to get ADC interface\n");
          return -ENODEV;
        }

      /* Register the ADC driver at "/dev/adc0" */

      ret = adc_register("/dev/adc0", adc);
      if (ret < 0)
        {
          aerr("ERROR: adc_register failed: %d\n", ret);
          return ret;
        }

      /* Now we are initialized */

      initialized = true;
    }

  return OK;
#else
  return -ENOSYS;
#endif
}

#endif /* CONFIG_ADC */
