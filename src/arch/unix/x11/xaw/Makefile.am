SUBDIRS = widgets

INCLUDES = \
	@ARCH_INCLUDES@ \
	-I$(top_builddir)/src \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/drive \
	-I$(top_srcdir)/src/vdrive \
	-I$(top_srcdir)/src/c64 \
	-I$(top_srcdir)/src/c64dtv \
	-I$(top_srcdir)/src/c128 \
	-I$(top_srcdir)/src/vic20 \
	-I$(top_srcdir)/src/pet \
	-I$(top_srcdir)/src/cbm2 \
	-I$(top_srcdir)/src/lib/p64 \
	-I$(top_srcdir)/src/platform \
	-I$(top_srcdir)/src/arch/unix/gui \
	-I$(top_srcdir)/src/arch/unix/x11

noinst_LIBRARIES = libxawui.a

libxawui_a_SOURCES = \
	about.c \
	checkmark.xbm \
	console.c \
	lightpendrv.c \
	lightpendrv.h \
	right_arrow.xbm \
	uiarch.h \
	uicartridge.c \
	uicolor.c \
	uiedisk.c \
	uiedit.c \
	uimenu.c \
	uimenu.h \
	uipalcontrol.c \
	uipalcontrol.h \
	uiscreenshot.c \
	uisnapshot.c \
	uivsidcontrol.c \
	videoarch.h \
	x11video.c \
	x11kbd.c \
	x11ui.c
