/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGraphicsEllipseItem>

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
QGraphicsEllipseItem ( QGraphicsItem * parent = 0 )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_NEW1 )
{
  QGraphicsEllipseItem * o = NULL;
  QGraphicsItem * par1 = ISNIL(1)? 0 : (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGraphicsEllipseItem ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGraphicsEllipseItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QGraphicsEllipseItem ( const QRectF & rect, QGraphicsItem * parent = 0 )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_NEW2 )
{
  QGraphicsEllipseItem * o = NULL;
  QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QGraphicsItem * par2 = ISNIL(2)? 0 : (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGraphicsEllipseItem ( *par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGraphicsEllipseItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QGraphicsEllipseItem ( qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0 )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_NEW3 )
{
  QGraphicsEllipseItem * o = NULL;
  qreal par1 = hb_parnd(1);
  qreal par2 = hb_parnd(2);
  qreal par3 = hb_parnd(3);
  qreal par4 = hb_parnd(4);
  QGraphicsItem * par5 = ISNIL(5)? 0 : (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(5, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGraphicsEllipseItem ( par1, par2, par3, par4, par5 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGraphicsEllipseItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QGraphicsEllipseItem ( QGraphicsItem * parent = 0 )
//[2]QGraphicsEllipseItem ( const QRectF & rect, QGraphicsItem * parent = 0 )
//[3]QGraphicsEllipseItem ( qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0 )

HB_FUNC( QGRAPHICSELLIPSEITEM_NEW )
{
  if( ISBETWEEN(0,1) && (ISQGRAPHICSITEM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QGRAPHICSELLIPSEITEM_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQRECTF(1) && (ISQGRAPHICSITEM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QGRAPHICSELLIPSEITEM_NEW2 );
  }
  else if( ISBETWEEN(4,5) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && (ISQGRAPHICSITEM(5)||ISNIL(5)) )
  {
    HB_FUNC_EXEC( QGRAPHICSELLIPSEITEM_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QGRAPHICSELLIPSEITEM_DELETE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QRectF rect () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_RECT )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->rect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
void setRect ( const QRectF & rect )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_SETRECT1 )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setRect ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRect ( qreal x, qreal y, qreal width, qreal height )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_SETRECT2 )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    obj->setRect ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setRect ( const QRectF & rect )
//[2]void setRect ( qreal x, qreal y, qreal width, qreal height )

HB_FUNC( QGRAPHICSELLIPSEITEM_SETRECT )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSELLIPSEITEM_SETRECT1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSELLIPSEITEM_SETRECT2 );
  }
}

/*
void setSpanAngle ( int angle )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_SETSPANANGLE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSpanAngle ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStartAngle ( int angle )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_SETSTARTANGLE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setStartAngle ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int spanAngle () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_SPANANGLE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->spanAngle (  );
    hb_retni( i );
  }
}


/*
int startAngle () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_STARTANGLE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->startAngle (  );
    hb_retni( i );
  }
}


/*
virtual QRectF boundingRect () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_BOUNDINGRECT )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->boundingRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
virtual bool contains ( const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_CONTAINS )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
virtual bool isObscuredBy ( const QGraphicsItem * item ) const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_ISOBSCUREDBY )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isObscuredBy ( par1 );
    hb_retl( b );
  }
}


/*
virtual QPainterPath opaqueArea () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_OPAQUEAREA )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->opaqueArea (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
virtual void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 )
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_PAINT )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const QStyleOptionGraphicsItem * par2 = (const QStyleOptionGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * par3 = ISNIL(3)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->paint ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QPainterPath shape () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_SHAPE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->shape (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
virtual int type () const
*/
HB_FUNC( QGRAPHICSELLIPSEITEM_TYPE )
{
  QGraphicsEllipseItem * obj = (QGraphicsEllipseItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->type (  );
    hb_retni( i );
  }
}



