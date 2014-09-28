# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	qpid-tools
PORTVERSION=	0.30
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_APACHE}

MAINTAINER=	johan@stromnet.se
COMMENT=	Management tools for net/qpidd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# No actual dep on net/qpidd; this can be used remotely
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qpid>=0.28:${PORTSDIR}/devel/py-qpid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qpid-qmf>=0:${PORTSDIR}/devel/py-qpid-qmf

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
