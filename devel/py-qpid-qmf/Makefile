# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	qpid-qmf
PORTVERSION=	0.30
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_APACHE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johan@stromnet.se
COMMENT=	Qpid Management Framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qpid>=0.28:${PORTSDIR}/devel/py-qpid

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
