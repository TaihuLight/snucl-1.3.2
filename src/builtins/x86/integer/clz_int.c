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




int clzf(int y){
  int rst=0;
  llong x=y;

  if (x == 0x0)
  {
    rst = 32;
  }
  else
  {
    if (x < 0)
    {
      x = x&0xFFFFFFFF;
    }
    for (rst = 0; x < 0x80000000; rst++)
    {
      x <<= 1;
    }
  }

  return rst;
}

int clz(int x)
{

	return clzf(x);

}

int2 clz(int2 x){
	int2 rst;
	rst[0]        = clzf(x[0]);
	rst[1]        = clzf(x[1]);
	return rst;
}
int3 clz(int3 x){
  int3 rst;
  rst[0]        = clzf(x[0]);
  rst[1]        = clzf(x[1]);
  rst[2]        = clzf(x[2]);
  return rst;
}
int4 clz(int4 x){
  int4 rst;
  rst[0]        = clzf(x[0]);
  rst[1]        = clzf(x[1]);
  rst[2]        = clzf(x[2]);
  rst[3]        = clzf(x[3]);
  return rst;
}
int8 clz(int8 x){

  int8 rst;
  rst[0]        = clzf(x[0]);
  rst[1]        = clzf(x[1]);
  rst[2]        = clzf(x[2]);
  rst[3]        = clzf(x[3]);
  rst[4]        = clzf(x[4]);
  rst[5]        = clzf(x[5]);
  rst[6]        = clzf(x[6]);
  rst[7]        = clzf(x[7]);

  return rst;
}
int16 clz(int16 x){
  int16 rst;
  rst[0]        = clzf(x[0]);
  rst[1]        = clzf(x[1]);
  rst[2]        = clzf(x[2]);
  rst[3]        = clzf(x[3]);
  rst[4]        = clzf(x[4]);
  rst[5]        = clzf(x[5]);
  rst[6]        = clzf(x[6]);
  rst[7]        = clzf(x[7]);
  rst[8]        = clzf(x[8]);
  rst[9]        = clzf(x[9]);
  rst[10]        = clzf(x[10]);
  rst[11]        = clzf(x[11]);
  rst[12]        = clzf(x[12]);
  rst[13]        = clzf(x[13]);
  rst[14]        = clzf(x[14]);
  rst[15]        = clzf(x[15]);
  return rst;
}
