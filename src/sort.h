/**
 * Copyright (C) 2009-2014 by Gerardo Orellana <goaccess@prosoftcorp.com>
 * GoAccess - An Ncurses apache weblog analyzer & interactive viewer
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * A copy of the GNU General Public License is attached to this
 * source distribution for its full text.
 *
 * Visit http://goaccess.prosoftcorp.com for new releases.
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "commons.h"
#include "parser.h"

#define SORT_MAX_OPTS   11

/* See GEnum for mapping */
#define SORT_FIELD_LEN  12 + 1  /* longest metric name */
#define SORT_MODULE_LEN 15 + 1  /* longest module name */
#define SORT_ORDER_LEN   4 + 1

/* Enumerated sorting metrics */
typedef enum GSortField_
{
  SORT_BY_HITS,
  SORT_BY_VISITORS,
  SORT_BY_DATA,
  SORT_BY_BW,
  SORT_BY_AVGTS,
  SORT_BY_CUMTS,
  SORT_BY_MAXTS,
  SORT_BY_PROT,
  SORT_BY_MTHD,
  SORT_BY_STATUS_HITS,
} GSortField;

/* Enumerated sorting order */
typedef enum GSortOrder_
{
  SORT_ASC,
  SORT_DESC
} GSortOrder;

/* Sorting of each panel, metric and order */
typedef struct GSort_
{
  GModule module;
  GSortField field;
  GSortOrder sort;
} GSort;

extern GSort module_sort[TOTAL_MODULES];
extern const int sort_choices[][SORT_MAX_OPTS];;

GRawData *sort_raw_data (GRawData * raw_data, int ht_size);
int can_sort_module (GModule module, int field);
int get_sort_field_enum (const char *str);
int get_sort_order_enum (const char *str);
void parse_initial_sort (void);
void set_initial_sort (const char *smod, const char *sfield, const char *ssort);
void sort_holder_items (GHolderItem * items, int size, GSort sort);

#endif
