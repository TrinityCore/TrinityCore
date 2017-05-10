/* Copyright (C) 2009 Sun Microsystems, Inc

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; version 2 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */

/* Check stack direction (0-down, 1-up) */
int f(int *a)
{
  int b;
  return(&b > a)?1:0;
}
/*
 Prevent compiler optimizations by calling function
 through pointer.
*/
volatile int (*ptr_f)(int *) = f;
int main()
{
  int a;
  return ptr_f(&a);
}