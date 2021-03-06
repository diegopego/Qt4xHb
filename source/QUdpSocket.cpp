/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QUdpSocket>

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbapierr.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#define ISNIL HB_ISNIL
#define ISLOG HB_ISLOG
#define ISNUM HB_ISNUM
#define ISCHAR HB_ISCHAR
#define ISPOINTER HB_ISPOINTER
#define ISOBJECT HB_ISOBJECT
#define ISARRAY HB_ISARRAY
#endif
#include "qt4xhb_clsid.h"
#include "qt4xhb_utils.h"

/*
QUdpSocket ( QObject * parent = 0 )
*/
HB_FUNC( QUDPSOCKET_NEW )
{
  QUdpSocket * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QUdpSocket ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QUdpSocket *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QUDPSOCKET_DELETE )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    delete obj;
    obj = NULL;
    PHB_ITEM self = hb_stackSelfItem();
    PHB_ITEM ptr = hb_itemPutPtr( NULL, NULL );
    hb_objSendMsg( self, "_pointer", 1, ptr );
    hb_itemRelease( ptr );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool bind ( const QHostAddress & address, quint16 port )
*/
HB_FUNC( QUDPSOCKET_BIND1 )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHostAddress * par1 = (QHostAddress *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    quint16 par2 = hb_parni(2);
    bool b = obj->bind ( *par1, par2 );
    hb_retl( b );
  }
}


/*
bool bind ( const QHostAddress & address, quint16 port, BindMode mode )
*/
HB_FUNC( QUDPSOCKET_BIND2 )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHostAddress * par1 = (QHostAddress *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    quint16 par2 = hb_parni(2);
    int par3 = hb_parni(3);
    bool b = obj->bind ( *par1, par2,  (QUdpSocket::BindMode) par3 );
    hb_retl( b );
  }
}


/*
bool bind ( quint16 port = 0 )
*/
HB_FUNC( QUDPSOCKET_BIND3 )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    quint16 par1 = ISNIL(1)? 0 : hb_parni(1);
    bool b = obj->bind ( par1 );
    hb_retl( b );
  }
}


/*
bool bind ( quint16 port, BindMode mode )
*/
HB_FUNC( QUDPSOCKET_BIND4 )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    quint16 par1 = hb_parni(1);
    int par2 = hb_parni(2);
    bool b = obj->bind ( par1,  (QUdpSocket::BindMode) par2 );
    hb_retl( b );
  }
}


//[1]bool bind ( const QHostAddress & address, quint16 port )
//[2]bool bind ( const QHostAddress & address, quint16 port, BindMode mode )
//[3]bool bind ( quint16 port = 0 )
//[4]bool bind ( quint16 port, BindMode mode )

HB_FUNC( QUDPSOCKET_BIND )
{
  if( ISNUMPAR(2) && ISQHOSTADDRESS(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QUDPSOCKET_BIND1 );
  }
  else if( ISNUMPAR(3) && ISQHOSTADDRESS(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QUDPSOCKET_BIND2 );
  }
  else if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QUDPSOCKET_BIND3 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QUDPSOCKET_BIND4 );
  }
}

/*
bool hasPendingDatagrams () const
*/
HB_FUNC( QUDPSOCKET_HASPENDINGDATAGRAMS )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasPendingDatagrams (  );
    hb_retl( b );
  }
}


/*
qint64 pendingDatagramSize () const
*/
HB_FUNC( QUDPSOCKET_PENDINGDATAGRAMSIZE )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->pendingDatagramSize (  );
    hb_retni( i );
  }
}


/*
qint64 readDatagram ( char * data, qint64 maxSize, QHostAddress * address = 0, quint16 * port = 0 )
*/
HB_FUNC( QUDPSOCKET_READDATAGRAM )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char * par1 = (char *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qint64 par2 = hb_parni(2);
    QHostAddress * par3 = ISNIL(3)? 0 : (QHostAddress *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    quint16 * par4 = ISNIL(4)? 0 : (quint16 *) hb_itemGetPtr( hb_objSendMsg( hb_param(4, HB_IT_OBJECT ), "POINTER", 0 ) );
    qint64 i = obj->readDatagram ( par1, par2, par3, par4 );
    hb_retni( i );
  }
}


/*
qint64 writeDatagram ( const char * data, qint64 size, const QHostAddress & address, quint16 port )
*/
HB_FUNC( QUDPSOCKET_WRITEDATAGRAM1 )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    qint64 par2 = hb_parni(2);
    QHostAddress * par3 = (QHostAddress *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    quint16 par4 = hb_parni(4);
    qint64 i = obj->writeDatagram (  (const char *) par1, par2, *par3, par4 );
    hb_retni( i );
  }
}


/*
qint64 writeDatagram ( const QByteArray & datagram, const QHostAddress & host, quint16 port )
*/
HB_FUNC( QUDPSOCKET_WRITEDATAGRAM2 )
{
  QUdpSocket * obj = (QUdpSocket *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QHostAddress * par2 = (QHostAddress *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    quint16 par3 = hb_parni(3);
    qint64 i = obj->writeDatagram ( *par1, *par2, par3 );
    hb_retni( i );
  }
}


//[1]qint64 writeDatagram ( const char * data, qint64 size, const QHostAddress & address, quint16 port )
//[2]qint64 writeDatagram ( const QByteArray & datagram, const QHostAddress & host, quint16 port )

HB_FUNC( QUDPSOCKET_WRITEDATAGRAM )
{
  if( ISNUMPAR(4) && ISCHAR(1) && ISNUM(2) && ISQHOSTADDRESS(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QUDPSOCKET_WRITEDATAGRAM1 );
  }
  else if( ISNUMPAR(3) && ISQBYTEARRAY(1) && ISQHOSTADDRESS(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QUDPSOCKET_WRITEDATAGRAM2 );
  }
}



