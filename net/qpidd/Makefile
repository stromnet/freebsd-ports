# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	qpidd
PORTVERSION=	0.30
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_APACHE}
DISTNAME=	qpid-cpp-${PORTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	Apache Qpid C++ libraries and C++ broker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs

USE_LDCONFIG=	yes
USES=		cmake
CXXFLAGS+=	-std=c++11
CMAKE_ARGS=	-DLIB_SUFFIX=

RUN_USER=	qpidd
RUN_GROUP=	qpidd
USE_RC_SUBR=	qpidd
USERS=		${RUN_USER}
GROUPS=		${RUN_GROUP}

RUN_DIR=	/var/lib/qpidd
PID_DIR=	/var/run/qpidd
PLIST_SUB=	RUN_DIR=${RUN_DIR} PID_DIR=${PID_DIR}

# Ruby is required for building
# So is Python, but that comes later (after we know if we want it for just build)
USE_RUBY=	yes

OPTIONS_DEFINE=	PYTHON PERL RUBY QMFGEN DOXYGEN SASL SSL XML ACL HA AMQP TESTING
OPTIONS_DEFAULT=SSL SASL ACL
OPTIONS_SUB=	yes

PYTHON_DESC=		Native python bindings
PYTHON_CMAKE_ON=	-DBUILD_BINDING_PYTHON=on
PYTHON_CMAKE_OFF=	-DBUILD_BINDING_PYTHON=off
PYTHON_USES=		python
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qpid>=0.28:${PORTSDIR}/devel/py-qpid

QMFGEN_DESC=		Python QMF interface generator
QMFGEN_CMAKE_ON=	-DINSTALL_QMFGEN=on
QMFGEN_CMAKE_OFF=	-DINSTALL_QMFGEN=off
QMFGEN_USES=		python

PERL_DESC=		Perl Bindings (BROKEN!)
PERL_CMAKE_ON=		-DBUILD_BINDING_PERL=on
PERL_CMAKE_OFF=		-DBUILD_BINDING_PERL=off

RUBY_DESC=		Ruby bindings
RUBY_CMAKE_ON=		-DBUILD_BINDING_RUBY=on
RUBY_CMAKE_OFF=		-DBUILD_BINDING_RUBY=off

DOXYGEN_CMAKE_ON=	-DBUILD_DOCS=on
DOXYGEN_CMAKE_OFF=	-DBUILD_DOCS=off
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

SASL_DESC=		Cyrus SASL authentication support
SASL_CMAKE_ON=		-DBUILD_SASL=on -DCMAKE_REQUIRED_FLAGS=-L${LOCALBASE}/lib -DCMAKE_REQUIRED_INCLUDES=${LOCALBASE}/include
SASL_CMAKE_OFF=		-DBUILD_SASL=off
SASL_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

SSL_DESC=		Support for SSL
SSL_CMAKE_ON=		-DBUILD_SSL=on
SSL_CMAKE_OFF=		-DBUILD_SSL=off
SSL_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss
SSL_BUILD_DEPENDS=	pkgconf:${PORTSDIR}/devel/pkgconf

AMQP_DESC=		Build with support for AMQP 1.0
AMQP_CMAKE_ON=		-DBUILD_AMQP=on
AMQP_CMAKE_OFF=		-DBUILD_AMQP=off
AMQP_LIB_DEPENDS=	libqpid-proton.so:${PORTSDIR}/devel/qpid-proton

XML_DESC=		XML Exchange
XML_CMAKE_ON=		-DBUILD_XML=on
XML_CMAKE_OFF=		-DBUILD_XML=off
XML_LIB_DEPENDS=	libxqilla.so:${PORTSDIR}/textproc/xqilla

ACL_DESC=		ACL enforcement broker plugin
ACL_CMAKE_ON=		-DBUILD_ACL=on
ACL_CMAKE_OFF=		-DBUILD_ACL=off

HA_DESC=		Active-Passive HA plugin
HA_CMAKE_ON=		-DBUILD_HA=on
HA_CMAKE_OFF=		-DBUILD_HA=off

TESTING_DESC=		Enable testing
TESTING_CMAKE_ON=	-DBUILD_TESTING=on
TESTING_CMAKE_OFF=	-DBUILD_TESTING=off
TESTING_BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

# LINEARSTORAGE not supported, requires linux libaio
CMAKE_ARGS+=	-DBUILD_LINEARSTORE=off
# LEGACYSTORE  not supported, requires linux libaio
CMAKE_ARGS+=	-DBUILD_LEGACYSTORE=off

.include <bsd.port.options.mk>
.if ! ${PORT_OPTIONS:MRUBY}
RUBY_NO_RUN_DEPENDS=yes
.endif

.if ! ${PORT_OPTIONS:MACL}
# Does not build without ACL
CMAKE_ARGS+=	-DBUILD_TESTING=off
.endif

.if ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MPERL}
BUILD_DEPENDS+=	${LOCALBASE}/bin/swig2.0:${PORTSDIR}/devel/swig20
.endif

.if ! ${PORT_OPTIONS:MQMFGEN} && ! ${PORT_OPTIONS:MPYTHON}
USES+=		python:build
.endif

PORTDOCS=	LICENSE NOTICE
CMAKE_ARGS+=	-DDOC_INSTALL_DIR=${LOCALBASE}/share/doc/${PORTNAME}

.if ${PORT_OPTIONS:MDOXYGEN}
MAKE_ARGS=	all docs
PORTDOCS+=	api/*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|QPID_INSTALL_MANDIR share/man|QPID_INSTALL_MANDIR man|' ${WRKSRC}/BuildInstallSettings.cmake
	@${REINPLACE_CMD} -e 's|DESTINATION $${QPID_INSTALL_LIBDIR}/pkgconfig|DESTINATION libdata/pkgconfig|' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|DESTINATION $${QPID_INSTALL_LIBDIR}/cmake/Qpid|DESTINATION share/cmake/Modules|' ${WRKSRC}/src/CMakeLists.txt

post-install:
	cd ${STAGEDIR}${PREFIX}/etc/qpid && \
		${MV} qpidd.conf qpidd.conf.sample && \
		${MV} qpidc.conf qpidc.conf.sample

.if ${PORT_OPTIONS:MSASL}
	cd ${STAGEDIR}${PREFIX}/etc/sasl2 && \
		${MV} qpidd.conf qpidd.conf.sample
.endif

	cd ${STAGEDIR}${PREFIX}/etc/rc.d && \
		${RM} -rf init.d
	${MKDIR} ${STAGEDIR}${RUN_DIR}
	${MKDIR} ${STAGEDIR}${PID_DIR}

.include <bsd.port.mk>
