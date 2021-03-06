/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGraphicsAnchorLayout>

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
QGraphicsAnchorLayout ( QGraphicsLayoutItem * parent = 0 )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_NEW )
{
  QGraphicsAnchorLayout * o = NULL;
  QGraphicsLayoutItem * par1 = ISNIL(1)? 0 : (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGraphicsAnchorLayout ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGraphicsAnchorLayout *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QGRAPHICSANCHORLAYOUT_DELETE )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QGraphicsAnchor * addAnchor ( QGraphicsLayoutItem * firstItem, Qt::AnchorPoint firstEdge, QGraphicsLayoutItem * secondItem, Qt::AnchorPoint secondEdge )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_ADDANCHOR )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsLayoutItem * par1 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    QGraphicsLayoutItem * par3 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par4 = hb_parni(4);
    QGraphicsAnchor * ptr = obj->addAnchor ( par1,  (Qt::AnchorPoint) par2, par3,  (Qt::AnchorPoint) par4 );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSANCHOR" );  }
}


/*
void addAnchors ( QGraphicsLayoutItem * firstItem, QGraphicsLayoutItem * secondItem, Qt::Orientations orientations = Qt::Horizontal | Qt::Vertical )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_ADDANCHORS )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsLayoutItem * par1 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QGraphicsLayoutItem * par2 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? (int) Qt::Horizontal | Qt::Vertical : hb_parni(3);
    obj->addAnchors ( par1, par2,  (Qt::Orientations) par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addCornerAnchors ( QGraphicsLayoutItem * firstItem, Qt::Corner firstCorner, QGraphicsLayoutItem * secondItem, Qt::Corner secondCorner )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_ADDCORNERANCHORS )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsLayoutItem * par1 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    QGraphicsLayoutItem * par3 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par4 = hb_parni(4);
    obj->addCornerAnchors ( par1,  (Qt::Corner) par2, par3,  (Qt::Corner) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QGraphicsAnchor * anchor ( QGraphicsLayoutItem * firstItem, Qt::AnchorPoint firstEdge, QGraphicsLayoutItem * secondItem, Qt::AnchorPoint secondEdge )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_ANCHOR )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsLayoutItem * par1 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    QGraphicsLayoutItem * par3 = (QGraphicsLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par4 = hb_parni(4);
    QGraphicsAnchor * ptr = obj->anchor ( par1,  (Qt::AnchorPoint) par2, par3,  (Qt::AnchorPoint) par4 );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSANCHOR" );  }
}


/*
qreal horizontalSpacing () const
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_HORIZONTALSPACING )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->horizontalSpacing (  );
    hb_retnd( r );
  }
}


/*
void setHorizontalSpacing ( qreal spacing )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_SETHORIZONTALSPACING )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setHorizontalSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSpacing ( qreal spacing )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_SETSPACING )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalSpacing ( qreal spacing )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_SETVERTICALSPACING )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setVerticalSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
qreal verticalSpacing () const
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_VERTICALSPACING )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->verticalSpacing (  );
    hb_retnd( r );
  }
}


/*
virtual int count () const
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_COUNT )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
virtual void invalidate ()
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_INVALIDATE )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->invalidate (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QGraphicsLayoutItem * itemAt ( int index ) const
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_ITEMAT )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QGraphicsLayoutItem * ptr = obj->itemAt ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSLAYOUTITEM" );  }
}


/*
virtual void removeAt ( int index )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_REMOVEAT )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->removeAt ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setGeometry ( const QRectF & geom )
*/
HB_FUNC( QGRAPHICSANCHORLAYOUT_SETGEOMETRY )
{
  QGraphicsAnchorLayout * obj = (QGraphicsAnchorLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGeometry ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




