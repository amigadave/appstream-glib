/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2014 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef ASB_CONTEXT_H
#define ASB_CONTEXT_H

#include <glib-object.h>

#include "asb-app.h"
#include "asb-package.h"

#define ASB_TYPE_CONTEXT		(asb_context_get_type())
#define ASB_CONTEXT(obj)		(G_TYPE_CHECK_INSTANCE_CAST((obj), ASB_TYPE_CONTEXT, AsbContext))
#define ASB_CONTEXT_CLASS(cls)		(G_TYPE_CHECK_CLASS_CAST((cls), ASB_TYPE_CONTEXT, AsbContextClass))
#define ASB_IS_CONTEXT(obj)		(G_TYPE_CHECK_INSTANCE_TYPE((obj), ASB_TYPE_CONTEXT))
#define ASB_IS_CONTEXT_CLASS(cls)	(G_TYPE_CHECK_CLASS_TYPE((cls), ASB_TYPE_CONTEXT))
#define ASB_CONTEXT_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS((obj), ASB_TYPE_CONTEXT, AsbContextClass))

G_BEGIN_DECLS

typedef struct _AsbContext		AsbContext;
typedef struct _AsbContextClass	AsbContextClass;

struct _AsbContext
{
	GObject			 parent;
};

struct _AsbContextClass
{
	GObjectClass			parent_class;
	/*< private >*/
	void (*_asb_reserved1)	(void);
	void (*_asb_reserved2)	(void);
	void (*_asb_reserved3)	(void);
	void (*_asb_reserved4)	(void);
	void (*_asb_reserved5)	(void);
	void (*_asb_reserved6)	(void);
	void (*_asb_reserved7)	(void);
	void (*_asb_reserved8)	(void);
};

/**
 * AsbContextProcessFlags:
 * @AS_CONTEXT_PARSE_FLAG_NONE:				No special actions to use
 * @AS_CONTEXT_PARSE_FLAG_IGNORE_MISSING_INFO:		Ignore missing information
 * @AS_CONTEXT_PARSE_FLAG_IGNORE_MISSING_PARENTS:	Ignore missing parents
 *
 * The flags to use when processing the context.
 **/
typedef enum {
	AS_CONTEXT_PARSE_FLAG_NONE,
	AS_CONTEXT_PARSE_FLAG_IGNORE_MISSING_INFO	= 1,	/* Since: 0.3.2 */
	AS_CONTEXT_PARSE_FLAG_IGNORE_MISSING_PARENTS	= 2,	/* Since: 0.3.2 */
	/*< private >*/
	AS_CONTEXT_PARSE_FLAG_LAST,
} AsbContextProcessFlags;

GType		 asb_context_get_type		(void);

AsbContext	*asb_context_new		(void);
AsbPackage	*asb_context_find_by_pkgname	(AsbContext	*ctx,
						 const gchar 	*pkgname);
void		 asb_context_add_app		(AsbContext	*ctx,
						 AsbApp		*app);
void		 asb_context_add_app_ignore	(AsbContext	*ctx,
						 AsbPackage	*pkg);
void		 asb_context_set_no_net		(AsbContext	*ctx,
						 gboolean	 no_net);
void		 asb_context_set_api_version	(AsbContext	*ctx,
						 gdouble	 api_version);
void		 asb_context_set_add_cache_id	(AsbContext	*ctx,
						 gboolean	 add_cache_id);
void		 asb_context_set_hidpi_enabled	(AsbContext	*ctx,
						 gboolean	 hidpi_enabled);
void		 asb_context_set_embedded_icons	(AsbContext	*ctx,
						 gboolean	 embedded_icons);
void		 asb_context_set_max_threads	(AsbContext	*ctx,
						 guint		 max_threads);
void		 asb_context_set_min_icon_size	(AsbContext	*ctx,
						 guint		 min_icon_size);
void		 asb_context_set_old_metadata	(AsbContext	*ctx,
						 const gchar	*old_metadata);
void		 asb_context_set_extra_appstream (AsbContext	*ctx,
						 const gchar	*extra_appstream);
void		 asb_context_set_extra_appdata	(AsbContext	*ctx,
						 const gchar	*extra_appdata);
void		 asb_context_set_extra_screenshots (AsbContext	*ctx,
						 const gchar	*extra_screenshots);
void		 asb_context_set_screenshot_uri	(AsbContext	*ctx,
						 const gchar	*screenshot_uri);
void		 asb_context_set_log_dir	(AsbContext	*ctx,
						 const gchar	*log_dir);
void		 asb_context_set_screenshot_dir	(AsbContext	*ctx,
						 const gchar	*screenshot_dir);
void		 asb_context_set_cache_dir	(AsbContext	*ctx,
						 const gchar	*cache_dir);
void		 asb_context_set_temp_dir	(AsbContext	*ctx,
						 const gchar	*temp_dir);
void		 asb_context_set_output_dir	(AsbContext	*ctx,
						 const gchar	*output_dir);
void		 asb_context_set_basename	(AsbContext	*ctx,
						 const gchar	*basename);
const gchar	*asb_context_get_temp_dir	(AsbContext	*ctx);
gboolean	 asb_context_get_add_cache_id	(AsbContext	*ctx);
gboolean	 asb_context_get_hidpi_enabled	(AsbContext	*ctx);
gboolean	 asb_context_get_embedded_icons	(AsbContext	*ctx);
gboolean	 asb_context_get_no_net		(AsbContext	*ctx);
gdouble		 asb_context_get_api_version	(AsbContext	*ctx);
guint		 asb_context_get_min_icon_size	(AsbContext	*ctx);

gboolean	 asb_context_setup		(AsbContext	*ctx,
						 GError		**error);
gboolean	 asb_context_process		(AsbContext	*ctx,
						 AsbContextProcessFlags flags,
						 GError		**error);
gboolean	 asb_context_add_filename	(AsbContext	*ctx,
						 const gchar	*filename,
						 GError		**error);
gboolean	 asb_context_find_in_cache	(AsbContext	*ctx,
						 const gchar	*filename);

G_END_DECLS

#endif /* ASB_CONTEXT_H */
