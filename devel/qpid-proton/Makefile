# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	qpid-proton
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=qpid/proton/${PORTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	Qpid Proton is a high-performance, lightweight messaging library

LICENSE=	APACHE20

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CMAKE_ARGS=	-DBUILD_WITH_CXX=on -DLIB_SUFFIX=

OPTIONS_DEFINE=	PYTHON PERL RUBY PHP DOXYGEN JAVA
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

PYTHON_DESC=		Python bindings
PYTHON_CMAKE_ON=	-DBUILD_PYTHON=on
PYTHON_CMAKE_OFF =	-DBUILD_PYTHON=off
PYTHON_RUN_DEPENDS =	python:${PORTSDIR}/lang/python
PYTHON_USES=		python

PERL_DESC=	Perl Bindings
PERL_CMAKE_ON =	-DBUILD_PERL=on
PERL_CMAKE_OFF=	-DBUILD_PERL=off
PERL_USES=	perl5

JAVA_DESC=	Java Bindings
JAVA_CMAKE_ON=	-DBUILD_JAVA=on
JAVA_CMAKE_OFF=	-DBUILD_JAVA=off
JAVA_USE=	java=yes

# Broken: libuuid problems
RUBY_DESC=	Ruby bindings (BROKEN)
RUBY_CMAKE_ON=	-DBUILD_RUBY=on
RUBY_CMAKE_OFF=	-DBUILD_RUBY=off
RUBY_USE=	ruby=yes
RUBY_BUILD_DEPENDS=rubygem-simplecov>0:${PORTSDIR}/devel/rubygem-simplecov rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec

# Broken: fails to find zend.h.
PHP_DESC=	PHP bindings (BROKEN)
PHP_CMAKE_ON=	-DBUILD_PHP=on
PHP_CMAKE_OFF=	-DBUILD_PHP=off
PHP_USE=	php=yes

DOXYGEN_BUILD_DEPENDS=doxygen:${PORTSDIR}/devel/doxygen

USES=		cmake
USE_LDCONFIG=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MPYTHON}
PLIST_SUB+=	BINDINGS=""
.else
PLIST_SUB+=	BINDINGS="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MPERL}
BUILD_DEPENDS+=	${LOCALBASE}/bin/swig2.0:${PORTSDIR}/devel/swig20
.endif

.if ! ${PORT_OPTIONS:MPYTHON}
USES+=		python:build
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
MAKE_ARGS=	all docs
PORTDOCS=	api-c/*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MAN_INSTALL_DIR share/man|MAN_INSTALL_DIR man|' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|DESTINATION $${LIB_INSTALL_DIR}/pkgconfig|DESTINATION libdata/pkgconfig|' ${WRKSRC}/proton-c/CMakeLists.txt
	${REINPLACE_CMD} -e 's|DESTINATION $${LIB_INSTALL_DIR}/cmake/Proton|DESTINATION share/cmake/Modules|' ${WRKSRC}/proton-c/CMakeLists.txt

.include <bsd.port.mk>
