/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QXmlItem>

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

#include <QVariant>

/*
QXmlItem ()
*/
HB_FUNC( QXMLITEM_NEW1 )
{
  QXmlItem * o = NULL;
  o = new QXmlItem (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlItem ( const QXmlItem & other )
*/
HB_FUNC( QXMLITEM_NEW2 )
{
  QXmlItem * o = NULL;
  QXmlItem * par1 = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlItem ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlItem ( const QXmlNodeModelIndex & node )
*/
HB_FUNC( QXMLITEM_NEW3 )
{
  QXmlItem * o = NULL;
  QXmlNodeModelIndex * par1 = (QXmlNodeModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlItem ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlItem ( const QVariant & atomicValue )
*/
HB_FUNC( QXMLITEM_NEW4 )
{
  QXmlItem * o = NULL;
  QVariant * par1 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlItem ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QXmlItem ()
//[2]QXmlItem ( const QXmlItem & other )
//[3]QXmlItem ( const QXmlNodeModelIndex & node )
//[4]QXmlItem ( const QVariant & atomicValue )

HB_FUNC( QXMLITEM_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QXMLITEM_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQXMLITEM(1) )
  {
    HB_FUNC_EXEC( QXMLITEM_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQXMLNODEMODELINDEX(1) )
  {
    HB_FUNC_EXEC( QXMLITEM_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQVARIANT(1) )
  {
    HB_FUNC_EXEC( QXMLITEM_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QXMLITEM_DELETE )
{
  QXmlItem * obj = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool isAtomicValue () const
*/
HB_FUNC( QXMLITEM_ISATOMICVALUE )
{
  QXmlItem * obj = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isAtomicValue (  );
    hb_retl( b );
  }
}


/*
bool isNode () const
*/
HB_FUNC( QXMLITEM_ISNODE )
{
  QXmlItem * obj = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNode (  );
    hb_retl( b );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QXMLITEM_ISNULL )
{
  QXmlItem * obj = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
QVariant toAtomicValue () const
*/
HB_FUNC( QXMLITEM_TOATOMICVALUE )
{
  QXmlItem * obj = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVariant * ptr = new QVariant( obj->toAtomicValue (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
QXmlNodeModelIndex toNodeModelIndex () const
*/
HB_FUNC( QXMLITEM_TONODEMODELINDEX )
{
  QXmlItem * obj = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlNodeModelIndex * ptr = new QXmlNodeModelIndex( obj->toNodeModelIndex (  ) );
    _qt4xhb_createReturnClass ( ptr, "QXMLNODEMODELINDEX", true );  }
}




