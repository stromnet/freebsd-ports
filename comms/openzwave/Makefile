# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$
# Set as build var, used during build process

PORTNAME=openzwave
PORTVERSION=1.4.0
CATEGORIES=	comms

MAINTAINER=johan@stromnet.se
COMMENT=Open-zwave - An open-source interface to Z-Wave networks

LICENSE=LGPL20

USE_LDCONFIG=yes
USE_GITHUB=yes
GH_ACCOUNT=OpenZWave
GH_PROJECT=open-zwave
GH_TAGNAME=v1.4

USES=gmake tar:bz2 iconv pkgconfig

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=
OPTIONS_SUB=yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

DOXYGEN_DESCR=	Build docs (requires doxygen + graphviz)
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen dot:${PORTSDIR}/graphics/graphviz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=api/* default.htm general/* images+css/*
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libopenzwave.so.1.4
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/MinOZW
.if ! ${PORT_OPTIONS:MDOXYGEN}
# If doxygen was installed in env, it was built anyway..
# Or even if it isnt, some files are copied here.
	${RM} -rf ${STAGEDIR}${DOCSDIR}
.else
	${RM} ${STAGEDIR}${DOCSDIR}/Doxyfile.in
.endif
	# File in wrong dir, master fix 27bfef31
	${MV} ${STAGEDIR}/${LOCALBASE}/etc/openzwave/POP009303.xml ${STAGEDIR}/${LOCALBASE}/etc/openzwave/popp/POP009303.xml

# Extract patch version
VERSION_REV!=${ECHO} ${PORTVERSION} | ${CUT} -f3 -d'.'

MAKE_ARGS=VERSION_REV=${VERSION_REV} LIBDIR=${WRKSRC} docdir=${DOCSDIR}

.include <bsd.port.mk>
