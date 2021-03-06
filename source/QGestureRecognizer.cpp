/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGestureRecognizer>

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


HB_FUNC( QGESTURERECOGNIZER_DELETE )
{
  QGestureRecognizer * obj = (QGestureRecognizer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QGesture * create ( QObject * target )
*/
HB_FUNC( QGESTURERECOGNIZER_CREATE )
{
  QGestureRecognizer * obj = (QGestureRecognizer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QGesture * ptr = obj->create ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QGESTURE" );  }
}


/*
virtual Result recognize ( QGesture * gesture, QObject * watched, QEvent * event ) = 0
*/
HB_FUNC( QGESTURERECOGNIZER_RECOGNIZE )
{
  QGestureRecognizer * obj = (QGestureRecognizer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGesture * par1 = (QGesture *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QObject * par2 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QEvent * par3 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->recognize ( par1, par2, par3 );
    hb_retni( i );
  }
}


/*
virtual void reset ( QGesture * gesture )
*/
HB_FUNC( QGESTURERECOGNIZER_RESET )
{
  QGestureRecognizer * obj = (QGestureRecognizer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGesture * par1 = (QGesture *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->reset ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
Qt::GestureType registerRecognizer ( QGestureRecognizer * recognizer )
*/
HB_FUNC( QGESTURERECOGNIZER_REGISTERRECOGNIZER )
{
  QGestureRecognizer * par1 = (QGestureRecognizer *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int i = QGestureRecognizer::registerRecognizer ( par1 );
  hb_retni( i );
}


/*
void unregisterRecognizer ( Qt::GestureType type )
*/
HB_FUNC( QGESTURERECOGNIZER_UNREGISTERRECOGNIZER )
{
  int par1 = hb_parni(1);
  QGestureRecognizer::unregisterRecognizer (  (Qt::GestureType) par1 );
  hb_itemReturn( hb_stackSelfItem() );
}



