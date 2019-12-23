/* ----------------------------------------------------------------------
 * Project:      PULP DSP Library
 * Title:        plp_rfft_f32.c
 * Description:  Floating-point FFT on real input data
 *
 * $Date:        16. December 2019
 * $Revision:    V0
 *
 * Target Processor: PULP cores with "F" support (wolfe, vega)
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2019 ETH Zurich and University of Bologna. All rights reserved.
 *
 * Author: Giuseppe Tagliavini, University of Bologna
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "plp_math.h"

/**
  @ingroup groupTransforms
 */


 /**
   @defgroup fft  FFT transforms
   This module contains the code to perform FFT transforms.


  */

 /**
    @addtogroup fft
    @{
 */

 /**
    @brief Floating-point FFT on real input data.
    @param[in]   S       points to an instance of the floating-point FFT structure
    @param[in]   pSrcA   points to the input buffer (real data)
    @param[out]  pDst    points to the output buffer (complex data)
    @return      none
 */
 void plp_rfft_f32(
         const plp_rfft_instance_f32 *S,
 		     const float32_t * __restrict__ pSrc,
 	 	     float32_t * __restrict__ pDst){

   if (rt_cluster_id() == ARCHI_FC_CID){
     printf("F extension is supported only for cluster side\n");
     return;
   }
   
   plp_rfft_f32_xpulpv2(S, pSrc, pDst);


 }

 /**
    @} end of FFT group
 */