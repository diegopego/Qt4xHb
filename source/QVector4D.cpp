/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QVector4D>

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

#include <QVector2D>
#include <QVector3D>

/*
QVector4D ()
*/
HB_FUNC( QVECTOR4D_NEW1 )
{
  QVector4D * o = NULL;
  o = new QVector4D (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( qreal xpos, qreal ypos, qreal zpos, qreal wpos )
*/
HB_FUNC( QVECTOR4D_NEW2 )
{
  QVector4D * o = NULL;
  qreal par1 = hb_parnd(1);
  qreal par2 = hb_parnd(2);
  qreal par3 = hb_parnd(3);
  qreal par4 = hb_parnd(4);
  o = new QVector4D ( par1, par2, par3, par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( const QPoint & point )
*/
HB_FUNC( QVECTOR4D_NEW3 )
{
  QVector4D * o = NULL;
  QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector4D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( const QPointF & point )
*/
HB_FUNC( QVECTOR4D_NEW4 )
{
  QVector4D * o = NULL;
  QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector4D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( const QVector2D & vector )
*/
HB_FUNC( QVECTOR4D_NEW5 )
{
  QVector4D * o = NULL;
  QVector2D * par1 = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector4D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( const QVector2D & vector, qreal zpos, qreal wpos )
*/
HB_FUNC( QVECTOR4D_NEW6 )
{
  QVector4D * o = NULL;
  QVector2D * par1 = (QVector2D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  qreal par2 = hb_parnd(2);
  qreal par3 = hb_parnd(3);
  o = new QVector4D ( *par1, par2, par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( const QVector3D & vector )
*/
HB_FUNC( QVECTOR4D_NEW7 )
{
  QVector4D * o = NULL;
  QVector3D * par1 = (QVector3D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QVector4D ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QVector4D ( const QVector3D & vector, qreal wpos )
*/
HB_FUNC( QVECTOR4D_NEW8 )
{
  QVector4D * o = NULL;
  QVector3D * par1 = (QVector3D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  qreal par2 = hb_parnd(2);
  o = new QVector4D ( *par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QVector4D *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QVector4D ()
//[2]QVector4D ( qreal xpos, qreal ypos, qreal zpos, qreal wpos )
//[3]QVector4D ( const QPoint & point )
//[4]QVector4D ( const QPointF & point )
//[5]QVector4D ( const QVector2D & vector )
//[6]QVector4D ( const QVector2D & vector, qreal zpos, qreal wpos )
//[7]QVector4D ( const QVector3D & vector )
//[8]QVector4D ( const QVector3D & vector, qreal wpos )

HB_FUNC( QVECTOR4D_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW4 );
  }
  else if( ISNUMPAR(1) && ISQVECTOR2D(1) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW5 );
  }
  else if( ISNUMPAR(3) && ISQVECTOR2D(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW6 );
  }
  else if( ISNUMPAR(1) && ISQVECTOR3D(1) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW7 );
  }
  else if( ISNUMPAR(2) && ISQVECTOR3D(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QVECTOR4D_NEW8 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QVECTOR4D_DELETE )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
HB_FUNC( QVECTOR4D_ISNULL )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
qreal length () const
*/
HB_FUNC( QVECTOR4D_LENGTH )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->length (  );
    hb_retnd( r );
  }
}


/*
qreal lengthSquared () const
*/
HB_FUNC( QVECTOR4D_LENGTHSQUARED )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->lengthSquared (  );
    hb_retnd( r );
  }
}


/*
void normalize ()
*/
HB_FUNC( QVECTOR4D_NORMALIZE )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->normalize (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QVector4D normalized () const
*/
HB_FUNC( QVECTOR4D_NORMALIZED )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector4D * ptr = new QVector4D( obj->normalized (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR4D" );  }
}


/*
void setW ( qreal w )
*/
HB_FUNC( QVECTOR4D_SETW )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setW ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setX ( qreal x )
*/
HB_FUNC( QVECTOR4D_SETX )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
HB_FUNC( QVECTOR4D_SETY )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setY ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setZ ( qreal z )
*/
HB_FUNC( QVECTOR4D_SETZ )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setZ ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QPoint toPoint () const
*/
HB_FUNC( QVECTOR4D_TOPOINT )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * ptr = new QPoint( obj->toPoint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPointF toPointF () const
*/
HB_FUNC( QVECTOR4D_TOPOINTF )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->toPointF (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QVector2D toVector2D () const
*/
HB_FUNC( QVECTOR4D_TOVECTOR2D )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector2D * ptr = new QVector2D( obj->toVector2D (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR2D" );  }
}


/*
QVector2D toVector2DAffine () const
*/
HB_FUNC( QVECTOR4D_TOVECTOR2DAFFINE )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector2D * ptr = new QVector2D( obj->toVector2DAffine (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR2D" );  }
}


/*
QVector3D toVector3D () const
*/
HB_FUNC( QVECTOR4D_TOVECTOR3D )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector3D * ptr = new QVector3D( obj->toVector3D (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR3D" );  }
}


/*
QVector3D toVector3DAffine () const
*/
HB_FUNC( QVECTOR4D_TOVECTOR3DAFFINE )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector3D * ptr = new QVector3D( obj->toVector3DAffine (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVECTOR3D" );  }
}


/*
qreal w () const
*/
HB_FUNC( QVECTOR4D_W )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->w (  );
    hb_retnd( r );
  }
}


/*
qreal x () const
*/
HB_FUNC( QVECTOR4D_X )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->x (  );
    hb_retnd( r );
  }
}


/*
qreal y () const
*/
HB_FUNC( QVECTOR4D_Y )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->y (  );
    hb_retnd( r );
  }
}


/*
qreal z () const
*/
HB_FUNC( QVECTOR4D_Z )
{
  QVector4D * obj = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->z (  );
    hb_retnd( r );
  }
}



/*
qreal dotProduct ( const QVector4D & v1, const QVector4D & v2 )
*/
HB_FUNC( QVECTOR4D_DOTPRODUCT )
{
  QVector4D * par1 = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QVector4D * par2 = (QVector4D *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  qreal r = QVector4D::dotProduct ( *par1, *par2 );
  hb_retnd( r );
}




// TODO: implementar fun��o
// bool qFuzzyCompare ( const QVector4D & v1, const QVector4D & v2 )
