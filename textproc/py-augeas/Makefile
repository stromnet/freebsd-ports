# $FreeBSD$

PORTNAME=	augeas
PORTVERSION=	0.5.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-augeas-${PORTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	Pure python bindings for Augeas

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaugeas.so:${PORTSDIR}/textproc/augeas

WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	hercules-team
GH_PROJECT=	python-augeas
GH_TAGNAME=	v0.5.0

.include <bsd.port.mk>
