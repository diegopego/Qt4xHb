/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSslCipher>

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
QSslCipher ()
*/
HB_FUNC( QSSLCIPHER_NEW1 )
{
  QSslCipher * o = NULL;
  o = new QSslCipher (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSslCipher *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QSslCipher ( const QString & name, QSsl::SslProtocol protocol )
*/
HB_FUNC( QSSLCIPHER_NEW2 )
{
  QSslCipher * o = NULL;
  QString par1 = hb_parc(1);
  int par2 = hb_parni(2);
  o = new QSslCipher ( par1,  (QSsl::SslProtocol) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSslCipher *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QSslCipher ( const QSslCipher & other )
*/
HB_FUNC( QSSLCIPHER_NEW3 )
{
  QSslCipher * o = NULL;
  QSslCipher * par1 = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QSslCipher ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSslCipher *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QSslCipher ()
//[2]QSslCipher ( const QString & name, QSsl::SslProtocol protocol )
//[3]QSslCipher ( const QSslCipher & other )

HB_FUNC( QSSLCIPHER_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QSSLCIPHER_NEW1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QSSLCIPHER_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQSSLCIPHER(1) )
  {
    HB_FUNC_EXEC( QSSLCIPHER_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSSLCIPHER_DELETE )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QString authenticationMethod () const
*/
HB_FUNC( QSSLCIPHER_AUTHENTICATIONMETHOD )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->authenticationMethod (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString encryptionMethod () const
*/
HB_FUNC( QSSLCIPHER_ENCRYPTIONMETHOD )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->encryptionMethod (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QSSLCIPHER_ISNULL )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
QString keyExchangeMethod () const
*/
HB_FUNC( QSSLCIPHER_KEYEXCHANGEMETHOD )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->keyExchangeMethod (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString name () const
*/
HB_FUNC( QSSLCIPHER_NAME )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->name (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QSsl::SslProtocol protocol () const
*/
HB_FUNC( QSSLCIPHER_PROTOCOL )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->protocol (  );
    hb_retni( i );
  }
}


/*
QString protocolString () const
*/
HB_FUNC( QSSLCIPHER_PROTOCOLSTRING )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->protocolString (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int supportedBits () const
*/
HB_FUNC( QSSLCIPHER_SUPPORTEDBITS )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->supportedBits (  );
    hb_retni( i );
  }
}


/*
int usedBits () const
*/
HB_FUNC( QSSLCIPHER_USEDBITS )
{
  QSslCipher * obj = (QSslCipher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->usedBits (  );
    hb_retni( i );
  }
}




