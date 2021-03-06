/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDeclarativeItem>

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
QDeclarativeItem ( QDeclarativeItem * parent = 0 )
*/
HB_FUNC( QDECLARATIVEITEM_NEW )
{
  QDeclarativeItem * o = NULL;
  QDeclarativeItem * par1 = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QDeclarativeItem ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDeclarativeItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QDECLARATIVEITEM_DELETE )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
qreal baselineOffset () const
*/
HB_FUNC( QDECLARATIVEITEM_BASELINEOFFSET )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->baselineOffset (  );
    hb_retnd( r );
  }
}


/*
QDeclarativeItem * childAt ( qreal x, qreal y ) const
*/
HB_FUNC( QDECLARATIVEITEM_CHILDAT )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QDeclarativeItem * ptr = obj->childAt ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QDECLARATIVEITEM" );  }
}


/*
QRectF childrenRect ()
*/
HB_FUNC( QDECLARATIVEITEM_CHILDRENRECT )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->childrenRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
bool clip () const
*/
HB_FUNC( QDECLARATIVEITEM_CLIP )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->clip (  );
    hb_retl( b );
  }
}


/*
void forceActiveFocus ()
*/
HB_FUNC( QDECLARATIVEITEM_FORCEACTIVEFOCUS )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->forceActiveFocus (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
qreal implicitHeight () const
*/
HB_FUNC( QDECLARATIVEITEM_IMPLICITHEIGHT )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->implicitHeight (  );
    hb_retnd( r );
  }
}


/*
qreal implicitWidth () const
*/
HB_FUNC( QDECLARATIVEITEM_IMPLICITWIDTH )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->implicitWidth (  );
    hb_retnd( r );
  }
}


/*
bool keepMouseGrab () const
*/
HB_FUNC( QDECLARATIVEITEM_KEEPMOUSEGRAB )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->keepMouseGrab (  );
    hb_retl( b );
  }
}


/*
QScriptValue mapFromItem ( const QScriptValue & item, qreal x, qreal y ) const
*/
HB_FUNC( QDECLARATIVEITEM_MAPFROMITEM )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * par1 = (QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    QScriptValue * ptr = new QScriptValue( obj->mapFromItem ( *par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QScriptValue mapToItem ( const QScriptValue & item, qreal x, qreal y ) const
*/
HB_FUNC( QDECLARATIVEITEM_MAPTOITEM )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * par1 = (QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    QScriptValue * ptr = new QScriptValue( obj->mapToItem ( *par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QDeclarativeItem * parentItem () const
*/
HB_FUNC( QDECLARATIVEITEM_PARENTITEM )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDeclarativeItem * ptr = obj->parentItem (  );
    _qt4xhb_createReturnClass ( ptr, "QDECLARATIVEITEM" );  }
}


/*
void setBaselineOffset ( qreal )
*/
HB_FUNC( QDECLARATIVEITEM_SETBASELINEOFFSET )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setBaselineOffset ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setClip ( bool )
*/
HB_FUNC( QDECLARATIVEITEM_SETCLIP )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setClip ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setKeepMouseGrab ( bool keep )
*/
HB_FUNC( QDECLARATIVEITEM_SETKEEPMOUSEGRAB )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setKeepMouseGrab ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setParentItem ( QDeclarativeItem * parent )
*/
HB_FUNC( QDECLARATIVEITEM_SETPARENTITEM )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDeclarativeItem * par1 = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setParentItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSmooth ( bool smooth )
*/
HB_FUNC( QDECLARATIVEITEM_SETSMOOTH )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSmooth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTransformOrigin ( TransformOrigin origin )
*/
HB_FUNC( QDECLARATIVEITEM_SETTRANSFORMORIGIN )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setTransformOrigin (  (QDeclarativeItem::TransformOrigin) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool smooth () const
*/
HB_FUNC( QDECLARATIVEITEM_SMOOTH )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->smooth (  );
    hb_retl( b );
  }
}


/*
TransformOrigin transformOrigin () const
*/
HB_FUNC( QDECLARATIVEITEM_TRANSFORMORIGIN )
{
  QDeclarativeItem * obj = (QDeclarativeItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->transformOrigin (  );
    hb_retni( i );
  }
}




