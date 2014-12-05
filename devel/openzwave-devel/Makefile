# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

SVN_REV=939
PORTNAME=openzwave
PORTVERSION=1.1.${SVN_REV}
CATEGORIES= comms
MASTER_SITES= ${MASTER_SITE_LOCAL}
PKGNAMESUFFIX=  -devel

MAINTAINER=johan@stromnet.se
COMMENT=Open-zwave - An open-source interface to Z-Wave networks

LICENSE=LGPL20

USES=gmake tar:bz2 iconv

OPTIONS_DEFINE= DOXYGEN
OPTIONS_DEFAULT=
OPTIONS_SUB=yes

PLIST_SUB= PORTVERSION=${PORTVERSION}

DOXYGEN_DESCR= Build docs (requires doxygen + graphviz)
DOXYGEN_BUILD_DEPENDS= doxygen:${PORTSDIR}/devel/doxygen dot:${PORTSDIR}/graphics/graphviz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=api/* default.htm general/* images+css/*
.endif

# Updating to new rev:
# make do-fetch BOOTSTRAP=YES
# make makesum
.if defined(BOOTSTRAP)
FETCH_DEPENDS = svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		http://open-zwave.googlecode.com/svn/trunk/ ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
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

MAKE_ARGS=VERSION_REV=${SVN_REV} LIBDIR=${WRKSRC} docdir=$(DOCSDIR)

.include <bsd.port.mk>
