/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGraphicsSceneHoverEvent>

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

HB_FUNC( QGRAPHICSSCENEHOVEREVENT_DELETE )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QPointF lastPos () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_LASTPOS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->lastPos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPointF lastScenePos () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_LASTSCENEPOS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->lastScenePos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPoint lastScreenPos () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_LASTSCREENPOS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * ptr = new QPoint( obj->lastScreenPos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
Qt::KeyboardModifiers modifiers () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_MODIFIERS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->modifiers (  );
    hb_retni( i );
  }
}


/*
QPointF pos () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_POS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->pos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPointF scenePos () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_SCENEPOS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->scenePos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPoint screenPos () const
*/
HB_FUNC( QGRAPHICSSCENEHOVEREVENT_SCREENPOS )
{
  QGraphicsSceneHoverEvent * obj = (QGraphicsSceneHoverEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * ptr = new QPoint( obj->screenPos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}



