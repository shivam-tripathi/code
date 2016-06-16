/* example.h
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

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <glib.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_OBJECT (example_get_type())

// G_DECLARE_FINAL_TYPE has the arguments as
// name of the structure (Example)
// function prefix (example-)
// namespace (EXAMPLE)
// object name (OBJECT)
// inherits from gobject (GObject)

G_DECLARE_FINAL_TYPE (Example, example, EXAMPLE, OBJECT, GObject)

struct _ExampleClass
{
	GObjectClass parent;
};

Example *example_new (void);

G_END_DECLS

#endif /* EXAMPLE_H */
