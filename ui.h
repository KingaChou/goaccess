/**
 * Copyright (C) 2010 by Gerardo Orellana <goaccess@prosoftcorp.com>
 * GoAccess - An ncurses apache weblog analyzer & interactive viewer
 * @version 0.1
 * Last Modified: Wednesday, July 07, 2010
 * Path:  /ui.h
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * GoAccess is released under the GNU/GPL License.
 * Copy of the GNU General Public License is attached to this source 
 * distribution for its full text.
 *
 * Visit http://goaccess.prosoftcorp.com for new releases.
 */

#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

WINDOW *create_win(WINDOW *main_win);

void close_win(WINDOW *w);

void generate_time(void);

void drawHeader(WINDOW *win, char* header, int x, int y, int w, int color);

void update_header(WINDOW *header_win, int current);

void display_general(WINDOW *header_win, struct logger *logger, char *ifile);

void create_graphs(WINDOW *main_win, struct stu_alloc_all **sorted_alloc_all,
				   struct logger *logger, int i, int module, int max);

int get_max_value(struct stu_alloc_all **sorted_alloc_all, struct logger *logger, int module);

void display_content(WINDOW *main_win, struct stu_alloc_all **sorted_alloc_all, 
					 struct logger *logger);

void do_scrolling(WINDOW *main_win, struct stu_alloc_all **sorted_alloc_all, 
				  struct logger *logger, struct scrolling *scrolling, int cmd);

void load_help_popup(WINDOW *help_win);

void load_reverse_dns_popup(WINDOW *ip_detail_win, char *addr);

void load_popup(WINDOW *my_menu_win,  struct stu_alloc_holder **sorted_alloc_holder, 
				struct logger *logger);

#endif