/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QVector2D>

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

#include <QVector3D>
#include <QVector4D>

/*
QVector2D ()
*/
HB_FUNC( QVECTOR2D_NEW1 )
{
  QVector2D * o = NULL;
  o = new QVector2D (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector2D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector2D ( qreal xpos, qreal ypos )
*/
HB_FUNC( QVECTOR2D_NEW2 )
{
  QVector2D * o = NULL;
  qreal par1 = hb_parnd(1);
  qreal par2 = hb_parnd(2);
  o = new QVector2D ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector2D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector2D ( const QPoint & point )
*/
HB_FUNC( QVECTOR2D_NEW3 )
{
  QVector2D * o = NULL;
  QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector2D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector2D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector2D ( const QPointF & point )
*/
HB_FUNC( QVECTOR2D_NEW4 )
{
  QVector2D * o = NULL;
  QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector2D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector2D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector2D ( const QVector3D & vector )
*/
HB_FUNC( QVECTOR2D_NEW5 )
{
  QVector2D * o = NULL;
  QVector3D * par1 = (QVector3D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector2D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector2D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector2D ( const QVector4D & vector )
*/
HB_FUNC( QVECTOR2D_NEW6 )
{
  QVector2D * o = NULL;
  QVector4D * par1 = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector2D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector2D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QVector2D ()
//[2]QVector2D ( qreal xpos, qreal ypos )
//[3]QVector2D ( const QPoint & point )
//[4]QVector2D ( const QPointF & point )
//[5]QVector2D ( const QVector3D & vector )
//[6]QVector2D ( const QVector4D & vector )

HB_FUNC( QVECTOR2D_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QVECTOR2D_NEW1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QVECTOR2D_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QVECTOR2D_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QVECTOR2D_NEW4 );
  }
  else if( ISNUMPAR(1) && ISQVECTOR3D(1) )
  {
    HB_FUNC_EXEC( QVECTOR2D_NEW5 );
  }
  else if( ISNUMPAR(1) && ISQVECTOR4D(1) )
  {
    HB_FUNC_EXEC( QVECTOR2D_NEW6 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QVECTOR2D_DELETE )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool isNull () const
*/
HB_FUNC( QVECTOR2D_ISNULL )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
qreal length () const
*/
HB_FUNC( QVECTOR2D_LENGTH )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->length (  );
    hb_retnd( r );
  }
}


/*
qreal lengthSquared () const
*/
HB_FUNC( QVECTOR2D_LENGTHSQUARED )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->lengthSquared (  );
    hb_retnd( r );
  }
}


/*
void normalize ()
*/
HB_FUNC( QVECTOR2D_NORMALIZE )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->normalize (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QVector2D normalized () const
*/
HB_FUNC( QVECTOR2D_NORMALIZED )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector2D * ptr = new QVector2D( obj->normalized (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR2D" );  }
}


/*
void setX ( qreal x )
*/
HB_FUNC( QVECTOR2D_SETX )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setX ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setY ( qreal y )
*/
HB_FUNC( QVECTOR2D_SETY )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setY ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QPoint toPoint () const
*/
HB_FUNC( QVECTOR2D_TOPOINT )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * ptr = new QPoint( obj->toPoint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPointF toPointF () const
*/
HB_FUNC( QVECTOR2D_TOPOINTF )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->toPointF (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QVector3D toVector3D () const
*/
HB_FUNC( QVECTOR2D_TOVECTOR3D )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector3D * ptr = new QVector3D( obj->toVector3D (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR3D" );  }
}


/*
QVector4D toVector4D () const
*/
HB_FUNC( QVECTOR2D_TOVECTOR4D )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector4D * ptr = new QVector4D( obj->toVector4D (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR4D" );  }
}


/*
qreal x () const
*/
HB_FUNC( QVECTOR2D_X )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->x (  );
    hb_retnd( r );
  }
}


/*
qreal y () const
*/
HB_FUNC( QVECTOR2D_Y )
{
  QVector2D * obj = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->y (  );
    hb_retnd( r );
  }
}



/*
qreal dotProduct ( const QVector2D & v1, const QVector2D & v2 )
*/
HB_FUNC( QVECTOR2D_DOTPRODUCT )
{
  QVector2D * par1 = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QVector2D * par2 = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  qreal r = QVector2D::dotProduct ( *par1, *par2 );
  hb_retnd( r );
}




// TODO: implementar fun��o
// bool qFuzzyCompare ( const QVector2D & v1, const QVector2D & v2 )
