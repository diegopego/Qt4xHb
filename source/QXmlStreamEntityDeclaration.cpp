/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QXmlStreamEntityDeclaration>

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
QXmlStreamEntityDeclaration()
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_NEW1 )
{
  QXmlStreamEntityDeclaration * o = NULL;
  o = new QXmlStreamEntityDeclaration (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlStreamEntityDeclaration *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlStreamEntityDeclaration(const QXmlStreamEntityDeclaration & other)
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_NEW2 )
{
  QXmlStreamEntityDeclaration * o = NULL;
  QXmlStreamEntityDeclaration * par1 = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlStreamEntityDeclaration ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlStreamEntityDeclaration *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QXmlStreamEntityDeclaration()
//[2]QXmlStreamEntityDeclaration(const QXmlStreamEntityDeclaration & other)

HB_FUNC( QXMLSTREAMENTITYDECLARATION_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QXMLSTREAMENTITYDECLARATION_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQXMLSTREAMENTITYDECLARATION(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMENTITYDECLARATION_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QXMLSTREAMENTITYDECLARATION_DELETE )
{
  QXmlStreamEntityDeclaration * obj = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QStringRef name() const
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_NAME )
{
  QXmlStreamEntityDeclaration * obj = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringRef * ptr = new QStringRef( obj->name (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSTRINGREF" );  }
}


/*
QStringRef notationName() const
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_NOTATIONNAME )
{
  QXmlStreamEntityDeclaration * obj = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringRef * ptr = new QStringRef( obj->notationName (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSTRINGREF" );  }
}


/*
QStringRef publicId() const
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_PUBLICID )
{
  QXmlStreamEntityDeclaration * obj = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringRef * ptr = new QStringRef( obj->publicId (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSTRINGREF" );  }
}


/*
QStringRef systemId() const
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_SYSTEMID )
{
  QXmlStreamEntityDeclaration * obj = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringRef * ptr = new QStringRef( obj->systemId (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSTRINGREF" );  }
}


/*
QStringRef value() const
*/
HB_FUNC( QXMLSTREAMENTITYDECLARATION_VALUE )
{
  QXmlStreamEntityDeclaration * obj = (QXmlStreamEntityDeclaration *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringRef * ptr = new QStringRef( obj->value (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSTRINGREF" );  }
}



