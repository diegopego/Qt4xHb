/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGraphicsItemAnimation>

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

#include <QMatrix>
#include <QPointF>

/*
QGraphicsItemAnimation ( QObject * parent = 0 )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_NEW )
{
  QGraphicsItemAnimation * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGraphicsItemAnimation ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGraphicsItemAnimation *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QGRAPHICSITEMANIMATION_DELETE )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void clear ()
*/
HB_FUNC( QGRAPHICSITEMANIMATION_CLEAR )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
qreal horizontalScaleAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_HORIZONTALSCALEAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->horizontalScaleAt ( par1 );
    hb_retnd( r );
  }
}


/*
qreal horizontalShearAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_HORIZONTALSHEARAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->horizontalShearAt ( par1 );
    hb_retnd( r );
  }
}


/*
QGraphicsItem * item () const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_ITEM )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * ptr = obj->item (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
QMatrix matrixAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_MATRIXAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    QMatrix * ptr = new QMatrix( obj->matrixAt ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMATRIX" );  }
}


/*
QPointF posAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_POSAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    QPointF * ptr = new QPointF( obj->posAt ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}



/*
qreal rotationAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_ROTATIONAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->rotationAt ( par1 );
    hb_retnd( r );
  }
}




/*
void setItem ( QGraphicsItem * item )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETITEM )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * par1 = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPosAt ( qreal step, const QPointF & point )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETPOSAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPosAt ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRotationAt ( qreal step, qreal angle )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETROTATIONAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->setRotationAt ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setScaleAt ( qreal step, qreal sx, qreal sy )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETSCALEAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    obj->setScaleAt ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setShearAt ( qreal step, qreal sh, qreal sv )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETSHEARAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    obj->setShearAt ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTimeLine ( QTimeLine * timeLine )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETTIMELINE )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTimeLine * par1 = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setTimeLine ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTranslationAt ( qreal step, qreal dx, qreal dy )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETTRANSLATIONAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    obj->setTranslationAt ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
QTimeLine * timeLine () const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_TIMELINE )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTimeLine * ptr = obj->timeLine (  );
    _qt4xhb_createReturnClass ( ptr, "QTIMELINE" );  }
}



/*
qreal verticalScaleAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_VERTICALSCALEAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->verticalScaleAt ( par1 );
    hb_retnd( r );
  }
}


/*
qreal verticalShearAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_VERTICALSHEARAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->verticalShearAt ( par1 );
    hb_retnd( r );
  }
}


/*
qreal xTranslationAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_XTRANSLATIONAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->xTranslationAt ( par1 );
    hb_retnd( r );
  }
}


/*
qreal yTranslationAt ( qreal step ) const
*/
HB_FUNC( QGRAPHICSITEMANIMATION_YTRANSLATIONAT )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal r = obj->yTranslationAt ( par1 );
    hb_retnd( r );
  }
}


/*
void setStep ( qreal step )
*/
HB_FUNC( QGRAPHICSITEMANIMATION_SETSTEP )
{
  QGraphicsItemAnimation * obj = (QGraphicsItemAnimation *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setStep ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




