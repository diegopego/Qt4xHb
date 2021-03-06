/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QLineF>

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
QLineF()
*/
HB_FUNC( QLINEF_NEW1 )
{
  QLineF * o = NULL;
  o = new QLineF (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QLineF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QLineF(const QPointF & p1, const QPointF & p2)
*/
HB_FUNC( QLINEF_NEW2 )
{
  QLineF * o = NULL;
  QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QLineF ( *par1, *par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QLineF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QLineF(qreal x1, qreal y1, qreal x2, qreal y2)
*/
HB_FUNC( QLINEF_NEW3 )
{
  QLineF * o = NULL;
  qreal par1 = hb_parnd(1);
  qreal par2 = hb_parnd(2);
  qreal par3 = hb_parnd(3);
  qreal par4 = hb_parnd(4);
  o = new QLineF ( par1, par2, par3, par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QLineF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QLineF(const QLine & line)
*/
HB_FUNC( QLINEF_NEW4 )
{
  QLineF * o = NULL;
  QLine * par1 = (QLine *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QLineF ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QLineF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QLineF()
//[2]QLineF(const QPointF & p1, const QPointF & p2)
//[3]QLineF(qreal x1, qreal y1, qreal x2, qreal y2)
//[4]QLineF(const QLine & line)

HB_FUNC( QLINEF_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QLINEF_NEW1 );
  }
  else if( ISNUMPAR(2) && ISQPOINTF(1) && ISQPOINTF(2) )
  {
    HB_FUNC_EXEC( QLINEF_NEW2 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QLINEF_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQLINE(1) )
  {
    HB_FUNC_EXEC( QLINEF_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QLINEF_DELETE )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QPointF p1() const
*/
HB_FUNC( QLINEF_P1 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->p1 (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPointF p2() const
*/
HB_FUNC( QLINEF_P2 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->p2 (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
qreal x1() const
*/
HB_FUNC( QLINEF_X1 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->x1 (  );
    hb_retnd( r );
  }
}


/*
qreal x2() const
*/
HB_FUNC( QLINEF_X2 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->x2 (  );
    hb_retnd( r );
  }
}


/*
qreal y1() const
*/
HB_FUNC( QLINEF_Y1 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->y1 (  );
    hb_retnd( r );
  }
}


/*
qreal y2() const
*/
HB_FUNC( QLINEF_Y2 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->y2 (  );
    hb_retnd( r );
  }
}


/*
qreal angle() const
*/
HB_FUNC( QLINEF_ANGLE )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->angle (  );
    hb_retnd( r );
  }
}


/*
qreal angleTo(const QLineF & line) const
*/
HB_FUNC( QLINEF_ANGLETO )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLineF * par1 = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal r = obj->angleTo ( *par1 );
    hb_retnd( r );
  }
}


/*
qreal dx() const
*/
HB_FUNC( QLINEF_DX )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->dx (  );
    hb_retnd( r );
  }
}


/*
qreal dy() const
*/
HB_FUNC( QLINEF_DY )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->dy (  );
    hb_retnd( r );
  }
}



/*
bool isNull() const
*/
HB_FUNC( QLINEF_ISNULL )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
qreal length() const
*/
HB_FUNC( QLINEF_LENGTH )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->length (  );
    hb_retnd( r );
  }
}


/*
QLineF normalVector() const
*/
HB_FUNC( QLINEF_NORMALVECTOR )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLineF * ptr = new QLineF( obj->normalVector (  ) );
    _qt4xhb_createReturnClass ( ptr, "QLINEF", true );  }
}


/*
QPointF pointAt(qreal t) const
*/
HB_FUNC( QLINEF_POINTAT )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    QPointF * ptr = new QPointF( obj->pointAt ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
void setP1(const QPointF & p1)
*/
HB_FUNC( QLINEF_SETP1 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setP1 ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setP2(const QPointF & p2)
*/
HB_FUNC( QLINEF_SETP2 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setP2 ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAngle(qreal angle)
*/
HB_FUNC( QLINEF_SETANGLE )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setAngle ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLength(qreal length)
*/
HB_FUNC( QLINEF_SETLENGTH )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setLength ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLine(qreal x1, qreal y1, qreal x2, qreal y2)
*/
HB_FUNC( QLINEF_SETLINE )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    obj->setLine ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPoints(const QPointF & p1, const QPointF & p2)
*/
HB_FUNC( QLINEF_SETPOINTS )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPoints ( *par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QLine toLine() const
*/
HB_FUNC( QLINEF_TOLINE )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLine * ptr = new QLine( obj->toLine (  ) );
    _qt4xhb_createReturnClass ( ptr, "QLINE", true );  }
}


/*
void translate(const QPointF & offset)
*/
HB_FUNC( QLINEF_TRANSLATE1 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->translate ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void translate(qreal dx, qreal dy)
*/
HB_FUNC( QLINEF_TRANSLATE2 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->translate ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void translate(const QPointF & offset)
//[2]void translate(qreal dx, qreal dy)

HB_FUNC( QLINEF_TRANSLATE )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QLINEF_TRANSLATE1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QLINEF_TRANSLATE2 );
  }
}

/*
QLineF translated(const QPointF & offset) const
*/
HB_FUNC( QLINEF_TRANSLATED1 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QLineF * ptr = new QLineF( obj->translated ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QLINEF", true );  }
}


/*
QLineF translated(qreal dx, qreal dy) const
*/
HB_FUNC( QLINEF_TRANSLATED2 )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QLineF * ptr = new QLineF( obj->translated ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QLINEF", true );  }
}


//[1]QLineF translated(const QPointF & offset) const
//[2]QLineF translated(qreal dx, qreal dy) const

HB_FUNC( QLINEF_TRANSLATED )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QLINEF_TRANSLATED1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QLINEF_TRANSLATED2 );
  }
}

/*
QLineF unitVector() const
*/
HB_FUNC( QLINEF_UNITVECTOR )
{
  QLineF * obj = (QLineF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLineF * ptr = new QLineF( obj->unitVector (  ) );
    _qt4xhb_createReturnClass ( ptr, "QLINEF", true );  }
}



/*
QLineF fromPolar(qreal length, qreal angle)
*/
HB_FUNC( QLINEF_FROMPOLAR )
{
  qreal par1 = hb_parnd(1);
  qreal par2 = hb_parnd(2);
  QLineF * ptr = new QLineF( QLineF::fromPolar ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QLINEF", true );}



