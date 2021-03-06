/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFtp>

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
QFtp ( QObject * parent = 0 )
*/
HB_FUNC( QFTP_NEW )
{
  QFtp * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFtp ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFtp *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QFTP_DELETE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
qint64 bytesAvailable () const
*/
HB_FUNC( QFTP_BYTESAVAILABLE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->bytesAvailable (  );
    hb_retni( i );
  }
}


/*
int cd ( const QString & dir )
*/
HB_FUNC( QFTP_CD )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int i = obj->cd ( par1 );
    hb_retni( i );
  }
}


/*
void clearPendingCommands ()
*/
HB_FUNC( QFTP_CLEARPENDINGCOMMANDS )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearPendingCommands (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int close ()
*/
HB_FUNC( QFTP_CLOSE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->close (  );
    hb_retni( i );
  }
}


/*
int connectToHost ( const QString & host, quint16 port = 21 )
*/
HB_FUNC( QFTP_CONNECTTOHOST )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    quint16 par2 = ISNIL(2)? 21 : hb_parni(2);
    int i = obj->connectToHost ( par1, par2 );
    hb_retni( i );
  }
}


/*
Command currentCommand () const
*/
HB_FUNC( QFTP_CURRENTCOMMAND )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentCommand (  );
    hb_retni( i );
  }
}


/*
QIODevice * currentDevice () const
*/
HB_FUNC( QFTP_CURRENTDEVICE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * ptr = obj->currentDevice (  );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
int currentId () const
*/
HB_FUNC( QFTP_CURRENTID )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentId (  );
    hb_retni( i );
  }
}


/*
Error error () const
*/
HB_FUNC( QFTP_ERROR )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->error (  );
    hb_retni( i );
  }
}


/*
QString errorString () const
*/
HB_FUNC( QFTP_ERRORSTRING )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->errorString (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int get ( const QString & file, QIODevice * dev = 0, TransferType type = Binary )
*/
HB_FUNC( QFTP_GET )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QIODevice * par2 = ISNIL(2)? 0 : (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? (int) QFtp::Binary : hb_parni(3);
    int i = obj->get ( par1, par2,  (QFtp::TransferType) par3 );
    hb_retni( i );
  }
}


/*
bool hasPendingCommands () const
*/
HB_FUNC( QFTP_HASPENDINGCOMMANDS )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasPendingCommands (  );
    hb_retl( b );
  }
}


/*
int list ( const QString & dir = QString() )
*/
HB_FUNC( QFTP_LIST )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = ISNIL(1)? QString() : hb_parc(1);
    int i = obj->list ( par1 );
    hb_retni( i );
  }
}


/*
int login ( const QString & user = QString(), const QString & password = QString() )
*/
HB_FUNC( QFTP_LOGIN )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = ISNIL(1)? QString() : hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    int i = obj->login ( par1, par2 );
    hb_retni( i );
  }
}


/*
int mkdir ( const QString & dir )
*/
HB_FUNC( QFTP_MKDIR )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int i = obj->mkdir ( par1 );
    hb_retni( i );
  }
}


/*
int put ( QIODevice * dev, const QString & file, TransferType type = Binary )
*/
HB_FUNC( QFTP_PUT1 )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    int par3 = ISNIL(3)? (int) QFtp::Binary : hb_parni(3);
    int i = obj->put ( par1, par2,  (QFtp::TransferType) par3 );
    hb_retni( i );
  }
}


/*
int put ( const QByteArray & data, const QString & file, TransferType type = Binary )
*/
HB_FUNC( QFTP_PUT2 )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    int par3 = ISNIL(3)? (int) QFtp::Binary : hb_parni(3);
    int i = obj->put ( *par1, par2,  (QFtp::TransferType) par3 );
    hb_retni( i );
  }
}


//[1]int put ( QIODevice * dev, const QString & file, TransferType type = Binary )
//[2]int put ( const QByteArray & data, const QString & file, TransferType type = Binary )

HB_FUNC( QFTP_PUT )
{
  if( ISBETWEEN(2,3) && ISQIODEVICE(1) && ISCHAR(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QFTP_PUT1 );
  }
  else if( ISBETWEEN(2,3) && ISQBYTEARRAY(1) && ISCHAR(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QFTP_PUT2 );
  }
}

/*
int rawCommand ( const QString & command )
*/
HB_FUNC( QFTP_RAWCOMMAND )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int i = obj->rawCommand ( par1 );
    hb_retni( i );
  }
}


/*
qint64 read ( char * data, qint64 maxlen )
*/
HB_FUNC( QFTP_READ )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char * par1 = (char *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qint64 par2 = hb_parni(2);
    qint64 i = obj->read ( par1, par2 );
    hb_retni( i );
  }
}


/*
QByteArray readAll ()
*/
HB_FUNC( QFTP_READALL )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->readAll (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
int remove ( const QString & file )
*/
HB_FUNC( QFTP_REMOVE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int i = obj->remove ( par1 );
    hb_retni( i );
  }
}


/*
int rename ( const QString & oldname, const QString & newname )
*/
HB_FUNC( QFTP_RENAME )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    int i = obj->rename ( par1, par2 );
    hb_retni( i );
  }
}


/*
int rmdir ( const QString & dir )
*/
HB_FUNC( QFTP_RMDIR )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int i = obj->rmdir ( par1 );
    hb_retni( i );
  }
}


/*
int setProxy ( const QString & host, quint16 port )
*/
HB_FUNC( QFTP_SETPROXY )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    quint16 par2 = hb_parni(2);
    int i = obj->setProxy ( par1, par2 );
    hb_retni( i );
  }
}


/*
int setTransferMode ( TransferMode mode )
*/
HB_FUNC( QFTP_SETTRANSFERMODE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->setTransferMode (  (QFtp::TransferMode) par1 );
    hb_retni( i );
  }
}


/*
State state () const
*/
HB_FUNC( QFTP_STATE )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->state (  );
    hb_retni( i );
  }
}


/*
void abort ()
*/
HB_FUNC( QFTP_ABORT )
{
  QFtp * obj = (QFtp *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->abort (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





