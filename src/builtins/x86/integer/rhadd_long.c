/*****************************************************************************/
/* Copyright (C) 2010, 2011 Seoul National University                        */
/* and Samsung Electronics Co., Ltd.                                         */
/*                                                                           */
/* Contributed by Sangmin Seo <sangmin@aces.snu.ac.kr>, Jungwon Kim          */
/* <jungwon@aces.snu.ac.kr>, Jaejin Lee <jlee@cse.snu.ac.kr>, Seungkyun Kim  */
/* <seungkyun@aces.snu.ac.kr>, Jungho Park <jungho@aces.snu.ac.kr>,          */
/* Honggyu Kim <honggyu@aces.snu.ac.kr>, Jeongho Nah                         */
/* <jeongho@aces.snu.ac.kr>, Sung Jong Seo <sj1557.seo@samsung.com>,         */
/* Seung Hak Lee <s.hak.lee@samsung.com>, Seung Mo Cho                       */
/* <seungm.cho@samsung.com>, Hyo Jung Song <hjsong@samsung.com>,             */
/* Sang-Bum Suh <sbuk.suh@samsung.com>, and Jong-Deok Choi                   */
/* <jd11.choi@samsung.com>                                                   */
/*                                                                           */
/* All rights reserved.                                                      */
/*                                                                           */
/* This file is part of the SNU-SAMSUNG OpenCL runtime.                      */
/*                                                                           */
/* The SNU-SAMSUNG OpenCL runtime is free software: you can redistribute it  */
/* and/or modify it under the terms of the GNU Lesser General Public License */
/* as published by the Free Software Foundation, either version 3 of the     */
/* License, or (at your option) any later version.                           */
/*                                                                           */
/* The SNU-SAMSUNG OpenCL runtime is distributed in the hope that it will be */
/* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General  */
/* Public License for more details.                                          */
/*                                                                           */
/* You should have received a copy of the GNU Lesser General Public License  */
/* along with the SNU-SAMSUNG OpenCL runtime. If not, see                    */
/* <http://www.gnu.org/licenses/>.                                           */
/*****************************************************************************/


#include <cl_cpu_ops.h>


// llong
llong rhadd(llong x, llong y){
  llong overflow = (x | y) & 0x1;
	return (x >> 1) + (y >> 1) + overflow;
}
long2 rhadd(long2 x, long2 y){
  llong overflow;
	long2 rst;
  for (int i = 0; i < 2; i++) {
    overflow = (x[i] | y[i]) & 0x1;
    rst[i] = (x[i] >> 1) + (y[i] >> 1) + overflow;
  }
  return rst;
}
long3 rhadd(long3 x, long3 y){
  llong overflow;
	long3 rst;
  for (int i = 0; i < 3; i++) {
    overflow = (x[i] | y[i]) & 0x1;
    rst[i] = (x[i] >> 1) + (y[i] >> 1) + overflow;
  }
  return rst;
}
long4 rhadd(long4 x, long4 y){
  llong overflow;
	long4 rst;
  for (int i = 0; i < 4; i++) {
    overflow = (x[i] | y[i]) & 0x1;
    rst[i] = (x[i] >> 1) + (y[i] >> 1) + overflow;
  }
  return rst;
}
long8 rhadd(long8 x, long8 y){
  llong overflow;
	long8 rst;
  for (int i = 0; i < 8; i++) {
    overflow = (x[i] | y[i]) & 0x1;
    rst[i] = (x[i] >> 1) + (y[i] >> 1) + overflow;
  }
  return rst;
}
long16 rhadd(long16 x, long16 y){
  llong overflow;
	long16 rst;
  for (int i = 0; i < 16; i++) {
    overflow = (x[i] | y[i]) & 0x1;
    rst[i] = (x[i] >> 1) + (y[i] >> 1) + overflow;
  }
  return rst;
}

