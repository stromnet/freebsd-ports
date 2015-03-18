# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

# echo $(git describe --long --tags --dirty 2>/dev/null | sed s/^v//) | awk '{split($$0,a,"-"); print a[2]}'
VERSION_REV=102

PORTNAME=openzwave
PORTVERSION=1.3.${VERSION_REV}
CATEGORIES=	comms
PKGNAMESUFFIX=	-devel

MAINTAINER=johan@stromnet.se
COMMENT=Open-zwave - An open-source interface to Z-Wave networks

LICENSE=LGPL20

USE_GITHUB=yes
GH_ACCOUNT=OpenZWave
GH_COMMIT=b57775f
GH_TAGNAME=	${GH_COMMIT}
GH_PROJECT=open-zwave

USES=gmake tar:bz2 iconv

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
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libopenzwave.so.1.3
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/MinOZW
.if ! ${PORT_OPTIONS:MDOXYGEN}
# If doxygen was installed in env, it was built anyway..
# Or even if it isnt, some files are copied here.
	${RM} -rf ${STAGEDIR}${DOCSDIR}
.else
	${RM} ${STAGEDIR}${DOCSDIR}/Doxyfile.in
.endif

MAKE_ARGS=VERSION_REV=${VERSION_REV} LIBDIR=${WRKSRC} docdir=$(DOCSDIR)

.include <bsd.port.mk>
