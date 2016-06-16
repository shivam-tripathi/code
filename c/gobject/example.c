/* example.c
 *
 * Copyright (C) 2016 shivam <shivam.flash@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "example.h"

struct _Example{
  GObject parent_instance;
};

G_DEFINE_TYPE(Example, example, G_TYPE_OBJECT)

static void
example_class_init(ExampleClass *klass)
{

}

static void
example_init(Example *self)
{

}


