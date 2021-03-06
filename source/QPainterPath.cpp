/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QPainterPath>

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
QPainterPath ()
*/
HB_FUNC( QPAINTERPATH_NEW1 )
{
  QPainterPath * o = NULL;
  o = new QPainterPath (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPainterPath *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QPainterPath ( const QPointF & startPoint )
*/
HB_FUNC( QPAINTERPATH_NEW2 )
{
  QPainterPath * o = NULL;
  QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QPainterPath ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPainterPath *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QPainterPath ( const QPainterPath & path )
*/
HB_FUNC( QPAINTERPATH_NEW3 )
{
  QPainterPath * o = NULL;
  QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QPainterPath ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPainterPath *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QPainterPath ()
//[2]QPainterPath ( const QPointF & startPoint )
//[3]QPainterPath ( const QPainterPath & path )

HB_FUNC( QPAINTERPATH_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QPAINTERPATH_DELETE )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addEllipse ( const QRectF & boundingRectangle )
*/
HB_FUNC( QPAINTERPATH_ADDELLIPSE1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addEllipse ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addEllipse ( qreal x, qreal y, qreal width, qreal height )
*/
HB_FUNC( QPAINTERPATH_ADDELLIPSE2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    obj->addEllipse ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addEllipse ( const QPointF & center, qreal rx, qreal ry )
*/
HB_FUNC( QPAINTERPATH_ADDELLIPSE3 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    obj->addEllipse ( *par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addEllipse ( const QRectF & boundingRectangle )
//[2]void addEllipse ( qreal x, qreal y, qreal width, qreal height )
//[3]void addEllipse ( const QPointF & center, qreal rx, qreal ry )

HB_FUNC( QPAINTERPATH_ADDELLIPSE )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDELLIPSE1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDELLIPSE2 );
  }
  else if( ISNUMPAR(3) && ISQPOINTF(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDELLIPSE3 );
  }
}

/*
void addPath ( const QPainterPath & path )
*/
HB_FUNC( QPAINTERPATH_ADDPATH )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addPath ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addPolygon ( const QPolygonF & polygon )
*/
HB_FUNC( QPAINTERPATH_ADDPOLYGON )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPolygonF * par1 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addPolygon ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addRect ( const QRectF & rectangle )
*/
HB_FUNC( QPAINTERPATH_ADDRECT1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addRect ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addRect ( qreal x, qreal y, qreal width, qreal height )
*/
HB_FUNC( QPAINTERPATH_ADDRECT2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    obj->addRect ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addRect ( const QRectF & rectangle )
//[2]void addRect ( qreal x, qreal y, qreal width, qreal height )

HB_FUNC( QPAINTERPATH_ADDRECT )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDRECT1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDRECT2 );
  }
}

/*
void addRegion ( const QRegion & region )
*/
HB_FUNC( QPAINTERPATH_ADDREGION )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addRegion ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addRoundedRect ( const QRectF & rect, qreal xRadius, qreal yRadius, Qt::SizeMode mode = Qt::AbsoluteSize )
*/
HB_FUNC( QPAINTERPATH_ADDROUNDEDRECT1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    int par4 = ISNIL(4)? (int) Qt::AbsoluteSize : hb_parni(4);
    obj->addRoundedRect ( *par1, par2, par3,  (Qt::SizeMode) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addRoundedRect ( qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, Qt::SizeMode mode = Qt::AbsoluteSize )
*/
HB_FUNC( QPAINTERPATH_ADDROUNDEDRECT2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    qreal par6 = hb_parnd(6);
    int par7 = ISNIL(7)? (int) Qt::AbsoluteSize : hb_parni(7);
    obj->addRoundedRect ( par1, par2, par3, par4, par5, par6,  (Qt::SizeMode) par7 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addRoundedRect ( const QRectF & rect, qreal xRadius, qreal yRadius, Qt::SizeMode mode = Qt::AbsoluteSize )
//[2]void addRoundedRect ( qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, Qt::SizeMode mode = Qt::AbsoluteSize )

HB_FUNC( QPAINTERPATH_ADDROUNDEDRECT )
{
  if( ISBETWEEN(3,4) && ISQRECTF(1) && ISNUM(2) && ISNUM(3) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDROUNDEDRECT1 );
  }
  else if( ISBETWEEN(6,7) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) && ISNUM(6) && (ISNUM(7)||ISNIL(7)) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDROUNDEDRECT2 );
  }
}

/*
void addText ( const QPointF & point, const QFont & font, const QString & text )
*/
HB_FUNC( QPAINTERPATH_ADDTEXT1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QFont * par2 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par3 = hb_parc(3);
    obj->addText ( *par1, *par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addText ( qreal x, qreal y, const QFont & font, const QString & text )
*/
HB_FUNC( QPAINTERPATH_ADDTEXT2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QFont * par3 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par4 = hb_parc(4);
    obj->addText ( par1, par2, *par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addText ( const QPointF & point, const QFont & font, const QString & text )
//[2]void addText ( qreal x, qreal y, const QFont & font, const QString & text )

HB_FUNC( QPAINTERPATH_ADDTEXT )
{
  if( ISNUMPAR(3) && ISQPOINTF(1) && ISQFONT(2) && ISCHAR(3) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDTEXT1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISQFONT(3) && ISCHAR(4) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ADDTEXT2 );
  }
}

/*
qreal angleAtPercent ( qreal t ) const
*/
HB_FUNC( QPAINTERPATH_ANGLEATPERCENT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->angleAtPercent ( par1 );
    hb_retnd( r );
  }
}


/*
void arcMoveTo ( const QRectF & rectangle, qreal angle )
*/
HB_FUNC( QPAINTERPATH_ARCMOVETO1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    obj->arcMoveTo ( *par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void arcMoveTo ( qreal x, qreal y, qreal width, qreal height, qreal angle )
*/
HB_FUNC( QPAINTERPATH_ARCMOVETO2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    obj->arcMoveTo ( par1, par2, par3, par4, par5 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void arcMoveTo ( const QRectF & rectangle, qreal angle )
//[2]void arcMoveTo ( qreal x, qreal y, qreal width, qreal height, qreal angle )

HB_FUNC( QPAINTERPATH_ARCMOVETO )
{
  if( ISNUMPAR(2) && ISQRECTF(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ARCMOVETO1 );
  }
  else if( ISNUMPAR(5) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ARCMOVETO2 );
  }
}

/*
void arcTo ( const QRectF & rectangle, qreal startAngle, qreal sweepLength )
*/
HB_FUNC( QPAINTERPATH_ARCTO1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    obj->arcTo ( *par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void arcTo ( qreal x, qreal y, qreal width, qreal height, qreal startAngle, qreal sweepLength )
*/
HB_FUNC( QPAINTERPATH_ARCTO2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    qreal par6 = hb_parnd(6);
    obj->arcTo ( par1, par2, par3, par4, par5, par6 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void arcTo ( const QRectF & rectangle, qreal startAngle, qreal sweepLength )
//[2]void arcTo ( qreal x, qreal y, qreal width, qreal height, qreal startAngle, qreal sweepLength )

HB_FUNC( QPAINTERPATH_ARCTO )
{
  if( ISNUMPAR(3) && ISQRECTF(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ARCTO1 );
  }
  else if( ISNUMPAR(6) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) && ISNUM(6) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_ARCTO2 );
  }
}

/*
QRectF boundingRect () const
*/
HB_FUNC( QPAINTERPATH_BOUNDINGRECT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->boundingRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
void closeSubpath ()
*/
HB_FUNC( QPAINTERPATH_CLOSESUBPATH )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->closeSubpath (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void connectPath ( const QPainterPath & path )
*/
HB_FUNC( QPAINTERPATH_CONNECTPATH )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->connectPath ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool contains ( const QPointF & point ) const
*/
HB_FUNC( QPAINTERPATH_CONTAINS1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
bool contains ( const QRectF & rectangle ) const
*/
HB_FUNC( QPAINTERPATH_CONTAINS2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
bool contains ( const QPainterPath & p ) const
*/
HB_FUNC( QPAINTERPATH_CONTAINS3 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


//[1]bool contains ( const QPointF & point ) const
//[2]bool contains ( const QRectF & rectangle ) const
//[3]bool contains ( const QPainterPath & p ) const

HB_FUNC( QPAINTERPATH_CONTAINS )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_CONTAINS1 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_CONTAINS2 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_CONTAINS3 );
  }
}

/*
QRectF controlPointRect () const
*/
HB_FUNC( QPAINTERPATH_CONTROLPOINTRECT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->controlPointRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
void cubicTo ( const QPointF & c1, const QPointF & c2, const QPointF & endPoint )
*/
HB_FUNC( QPAINTERPATH_CUBICTO1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * par3 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->cubicTo ( *par1, *par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void cubicTo ( qreal c1X, qreal c1Y, qreal c2X, qreal c2Y, qreal endPointX, qreal endPointY )
*/
HB_FUNC( QPAINTERPATH_CUBICTO2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    qreal par6 = hb_parnd(6);
    obj->cubicTo ( par1, par2, par3, par4, par5, par6 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void cubicTo ( const QPointF & c1, const QPointF & c2, const QPointF & endPoint )
//[2]void cubicTo ( qreal c1X, qreal c1Y, qreal c2X, qreal c2Y, qreal endPointX, qreal endPointY )

HB_FUNC( QPAINTERPATH_CUBICTO )
{
  if( ISNUMPAR(3) && ISQPOINTF(1) && ISQPOINTF(2) && ISQPOINTF(3) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_CUBICTO1 );
  }
  else if( ISNUMPAR(6) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) && ISNUM(6) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_CUBICTO2 );
  }
}

/*
QPointF currentPosition () const
*/
HB_FUNC( QPAINTERPATH_CURRENTPOSITION )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->currentPosition (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}



/*
int elementCount () const
*/
HB_FUNC( QPAINTERPATH_ELEMENTCOUNT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->elementCount (  );
    hb_retni( i );
  }
}


/*
Qt::FillRule fillRule () const
*/
HB_FUNC( QPAINTERPATH_FILLRULE )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->fillRule (  );
    hb_retni( i );
  }
}


/*
QPainterPath intersected ( const QPainterPath & p ) const
*/
HB_FUNC( QPAINTERPATH_INTERSECTED )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->intersected ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
bool intersects ( const QRectF & rectangle ) const
*/
HB_FUNC( QPAINTERPATH_INTERSECTS1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->intersects ( *par1 );
    hb_retl( b );
  }
}


/*
bool intersects ( const QPainterPath & p ) const
*/
HB_FUNC( QPAINTERPATH_INTERSECTS2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->intersects ( *par1 );
    hb_retl( b );
  }
}


//[1]bool intersects ( const QRectF & rectangle ) const
//[2]bool intersects ( const QPainterPath & p ) const

HB_FUNC( QPAINTERPATH_INTERSECTS )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_INTERSECTS1 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_INTERSECTS2 );
  }
}

/*
bool isEmpty () const
*/
HB_FUNC( QPAINTERPATH_ISEMPTY )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEmpty (  );
    hb_retl( b );
  }
}


/*
qreal length () const
*/
HB_FUNC( QPAINTERPATH_LENGTH )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->length (  );
    hb_retnd( r );
  }
}


/*
void lineTo ( const QPointF & endPoint )
*/
HB_FUNC( QPAINTERPATH_LINETO1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->lineTo ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void lineTo ( qreal x, qreal y )
*/
HB_FUNC( QPAINTERPATH_LINETO2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->lineTo ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void lineTo ( const QPointF & endPoint )
//[2]void lineTo ( qreal x, qreal y )

HB_FUNC( QPAINTERPATH_LINETO )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_LINETO1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_LINETO2 );
  }
}

/*
void moveTo ( const QPointF & point )
*/
HB_FUNC( QPAINTERPATH_MOVETO1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->moveTo ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void moveTo ( qreal x, qreal y )
*/
HB_FUNC( QPAINTERPATH_MOVETO2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->moveTo ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void moveTo ( const QPointF & point )
//[2]void moveTo ( qreal x, qreal y )

HB_FUNC( QPAINTERPATH_MOVETO )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_MOVETO1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_MOVETO2 );
  }
}

/*
qreal percentAtLength ( qreal len ) const
*/
HB_FUNC( QPAINTERPATH_PERCENTATLENGTH )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->percentAtLength ( par1 );
    hb_retnd( r );
  }
}


/*
QPointF pointAtPercent ( qreal t ) const
*/
HB_FUNC( QPAINTERPATH_POINTATPERCENT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    QPointF * ptr = new QPointF( obj->pointAtPercent ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
void quadTo ( const QPointF & c, const QPointF & endPoint )
*/
HB_FUNC( QPAINTERPATH_QUADTO1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->quadTo ( *par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void quadTo ( qreal cx, qreal cy, qreal endPointX, qreal endPointY )
*/
HB_FUNC( QPAINTERPATH_QUADTO2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    obj->quadTo ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void quadTo ( const QPointF & c, const QPointF & endPoint )
//[2]void quadTo ( qreal cx, qreal cy, qreal endPointX, qreal endPointY )

HB_FUNC( QPAINTERPATH_QUADTO )
{
  if( ISNUMPAR(2) && ISQPOINTF(1) && ISQPOINTF(2) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_QUADTO1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_QUADTO2 );
  }
}

/*
void setElementPositionAt ( int index, qreal x, qreal y )
*/
HB_FUNC( QPAINTERPATH_SETELEMENTPOSITIONAT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    obj->setElementPositionAt ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFillRule ( Qt::FillRule fillRule )
*/
HB_FUNC( QPAINTERPATH_SETFILLRULE )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFillRule (  (Qt::FillRule) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QPainterPath simplified () const
*/
HB_FUNC( QPAINTERPATH_SIMPLIFIED )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->simplified (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
qreal slopeAtPercent ( qreal t ) const
*/
HB_FUNC( QPAINTERPATH_SLOPEATPERCENT )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->slopeAtPercent ( par1 );
    hb_retnd( r );
  }
}


/*
QPainterPath subtracted ( const QPainterPath & p ) const
*/
HB_FUNC( QPAINTERPATH_SUBTRACTED )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->subtracted ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
void swap ( QPainterPath & other )
*/
HB_FUNC( QPAINTERPATH_SWAP )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->swap ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QPolygonF toFillPolygon ( const QTransform & matrix ) const
*/
HB_FUNC( QPAINTERPATH_TOFILLPOLYGON1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->toFillPolygon ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}



//[1]QPolygonF toFillPolygon ( const QTransform & matrix ) const
//[2]QPolygonF toFillPolygon ( const QMatrix & matrix = QMatrix() ) const

HB_FUNC( QPAINTERPATH_TOFILLPOLYGON )
{
  if( ISNUMPAR(1) && ISQTRANSFORM(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TOFILLPOLYGON1 );
  }
}

/*
QList<QPolygonF> toFillPolygons ( const QTransform & matrix ) const
*/
HB_FUNC( QPAINTERPATH_TOFILLPOLYGONS1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QList<QPolygonF> list = obj->toFillPolygons ( *par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QPOLYGONF" );
    #else
    pDynSym = hb_dynsymFindName( "QPOLYGONF" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QPolygonF *) new QPolygonF ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        PHB_ITEM pDestroy = hb_itemNew( NULL );
        hb_itemPutL( pDestroy, true );
        hb_objSendMsg( pObject, "_SELF_DESTRUCTION", 1, pDestroy );
        hb_itemRelease( pDestroy );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}



//[1]QList<QPolygonF> toFillPolygons ( const QTransform & matrix ) const
//[2]QList<QPolygonF> toFillPolygons ( const QMatrix & matrix = QMatrix() ) const

HB_FUNC( QPAINTERPATH_TOFILLPOLYGONS )
{
  if( ISNUMPAR(1) && ISQTRANSFORM(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TOFILLPOLYGONS1 );
  }
}

/*
QPainterPath toReversed () const
*/
HB_FUNC( QPAINTERPATH_TOREVERSED )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->toReversed (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QList<QPolygonF> toSubpathPolygons ( const QTransform & matrix ) const
*/
HB_FUNC( QPAINTERPATH_TOSUBPATHPOLYGONS1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QList<QPolygonF> list = obj->toSubpathPolygons ( *par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QPOLYGONF" );
    #else
    pDynSym = hb_dynsymFindName( "QPOLYGONF" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QPolygonF *) new QPolygonF ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        PHB_ITEM pDestroy = hb_itemNew( NULL );
        hb_itemPutL( pDestroy, true );
        hb_objSendMsg( pObject, "_SELF_DESTRUCTION", 1, pDestroy );
        hb_itemRelease( pDestroy );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}



//[1]QList<QPolygonF> toSubpathPolygons ( const QTransform & matrix ) const
//[2]QList<QPolygonF> toSubpathPolygons ( const QMatrix & matrix = QMatrix() ) const

HB_FUNC( QPAINTERPATH_TOSUBPATHPOLYGONS )
{
  if( ISNUMPAR(1) && ISQTRANSFORM(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TOSUBPATHPOLYGONS1 );
  }
}

/*
void translate ( qreal dx, qreal dy )
*/
HB_FUNC( QPAINTERPATH_TRANSLATE1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->translate ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void translate ( const QPointF & offset )
*/
HB_FUNC( QPAINTERPATH_TRANSLATE2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->translate ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void translate ( qreal dx, qreal dy )
//[2]void translate ( const QPointF & offset )

HB_FUNC( QPAINTERPATH_TRANSLATE )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TRANSLATE1 );
  }
  else if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TRANSLATE2 );
  }
}

/*
QPainterPath translated ( qreal dx, qreal dy ) const
*/
HB_FUNC( QPAINTERPATH_TRANSLATED1 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QPainterPath * ptr = new QPainterPath( obj->translated ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPainterPath translated ( const QPointF & offset ) const
*/
HB_FUNC( QPAINTERPATH_TRANSLATED2 )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->translated ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


//[1]QPainterPath translated ( qreal dx, qreal dy ) const
//[2]QPainterPath translated ( const QPointF & offset ) const

HB_FUNC( QPAINTERPATH_TRANSLATED )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TRANSLATED1 );
  }
  else if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QPAINTERPATH_TRANSLATED2 );
  }
}

/*
QPainterPath united ( const QPainterPath & p ) const
*/
HB_FUNC( QPAINTERPATH_UNITED )
{
  QPainterPath * obj = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->united ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}



