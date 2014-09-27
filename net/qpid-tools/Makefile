# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME= qpid-tools
PORTVERSION= 0.30
CATEGORIES= net
MASTER_SITES= ${MASTER_SITE_APACHE}

MAINTAINER= johan@stromnet.se
COMMENT= qpid

LICENSE= APACHE20

USES=python
USE_PYTHON=distutils autoplist

RUN_DEPENDS = ${PYTHON_PKGNAMEPREFIX}qpid>=0.28:${PORTSDIR}/devel/py-qpid
RUN_DEPENDS = ${PYTHON_PKGNAMEPREFIX}qpid-qmf>=0:${PORTSDIR}/devel/py-qpid-qmf

.include <bsd.port.mk>
