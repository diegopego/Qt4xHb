/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QHttpMultiPart>

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
QHttpMultiPart ( QObject * parent = 0 )
*/
HB_FUNC( QHTTPMULTIPART_NEW1 )
{
  QHttpMultiPart * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QHttpMultiPart ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QHttpMultiPart *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QHttpMultiPart ( ContentType contentType, QObject * parent = 0 )
*/
HB_FUNC( QHTTPMULTIPART_NEW2 )
{
  QHttpMultiPart * o = NULL;
  int par1 = hb_parni(1);
  QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QHttpMultiPart (  (QHttpMultiPart::ContentType) par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QHttpMultiPart *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QHttpMultiPart ( QObject * parent = 0 )
//[2]QHttpMultiPart ( ContentType contentType, QObject * parent = 0 )

HB_FUNC( QHTTPMULTIPART_NEW )
{
  if( ISBETWEEN(0,1) && (ISQOBJECT(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QHTTPMULTIPART_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISQOBJECT(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QHTTPMULTIPART_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QHTTPMULTIPART_DELETE )
{
  QHttpMultiPart * obj = (QHttpMultiPart *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void append ( const QHttpPart & httpPart )
*/
HB_FUNC( QHTTPMULTIPART_APPEND )
{
  QHttpMultiPart * obj = (QHttpMultiPart *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHttpPart * par1 = (QHttpPart *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->append ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QByteArray boundary () const
*/
HB_FUNC( QHTTPMULTIPART_BOUNDARY )
{
  QHttpMultiPart * obj = (QHttpMultiPart *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->boundary (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
void setBoundary ( const QByteArray & boundary )
*/
HB_FUNC( QHTTPMULTIPART_SETBOUNDARY )
{
  QHttpMultiPart * obj = (QHttpMultiPart *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setBoundary ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setContentType ( ContentType contentType )
*/
HB_FUNC( QHTTPMULTIPART_SETCONTENTTYPE )
{
  QHttpMultiPart * obj = (QHttpMultiPart *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setContentType (  (QHttpMultiPart::ContentType) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




