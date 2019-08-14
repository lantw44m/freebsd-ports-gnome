# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	1.16.0
CATEGORIES=	multimedia
MASTER_SITES=	GNOME \
		http://gstreamer.freedesktop.org/src/gstreamer/
PKGNAMESUFFIX=	1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Media applications framework

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gettext gmake gnome libtool pathfix perl5 pkgconfig python tar:xz
USE_PERL5=	build
USE_GNOME=	glib20 introspection:build

GNU_CONFIGURE=	yes
# CFLAGS+=	-Wno-format
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-failing-tests \
		--disable-fatal-warnings \
		--disable-gtk-doc
CONFIGURE_ENV=	ac_cv_func_register_printf_function="no"
INSTALL_TARGET=	install-strip
PLIST_SUB=	VERSION=${GST10_VERSION} \
		SOVERSION=0.1600.0

USE_LDCONFIG=	yes
GST10_VERSION=	1.0

PORTSCOUT=	limitw:1,even

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS

OPTIONS_DEFINE_aarch64=		LIBUNWIND
OPTIONS_DEFFAULT_aarch64=	LIBUNWIND
OPTIONS_DEFINE_amd64=		LIBUNWIND
OPTIONS_DEFAULT_amd64=		LIBUNWIND
OPTIONS_DEFINE_i386=		LIBUNWIND
OPTIONS_DEFFAULT_i386=		LIBUNWIND

NLS_USES=	gettext
NLS_MESON_ON=	-Dnls=enabled
NLS_MESON_OFF=	-Dnls=disabled

LIBUNWIND_DESC=	...
LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_MESON_ON=	-Dlibunwind=enabled
LIBUNWIND_MESON_OFF=	-Dlibunwind=disabled

.include <bsd.port.mk>
