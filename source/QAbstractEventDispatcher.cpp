/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractEventDispatcher>

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


HB_FUNC( QABSTRACTEVENTDISPATCHER_DELETE )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool filterEvent ( void * message )
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_FILTEREVENT )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    void * par1 = (void *) hb_parptr(1);
    bool b = obj->filterEvent ( par1 );
    hb_retl( b );
  }
}


/*
virtual void flush () = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_FLUSH )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->flush (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool hasPendingEvents () = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_HASPENDINGEVENTS )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasPendingEvents (  );
    hb_retl( b );
  }
}


/*
virtual void interrupt () = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_INTERRUPT )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->interrupt (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool processEvents ( QEventLoop::ProcessEventsFlags flags ) = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_PROCESSEVENTS )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->processEvents (  (QEventLoop::ProcessEventsFlags) par1 );
    hb_retl( b );
  }
}


/*
virtual void registerSocketNotifier ( QSocketNotifier * notifier ) = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_REGISTERSOCKETNOTIFIER )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSocketNotifier * par1 = (QSocketNotifier *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->registerSocketNotifier ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int registerTimer ( int interval, QObject * object )
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_REGISTERTIMER1 )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QObject * par2 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->registerTimer ( par1, par2 );
    hb_retni( i );
  }
}


/*
virtual void registerTimer ( int timerId, int interval, QObject * object ) = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_REGISTERTIMER2 )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QObject * par3 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->registerTimer ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]int registerTimer ( int interval, QObject * object )
//[2]virtual void registerTimer ( int timerId, int interval, QObject * object ) = 0

HB_FUNC( QABSTRACTEVENTDISPATCHER_REGISTERTIMER )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISQOBJECT(2) )
  {
    HB_FUNC_EXEC( QABSTRACTEVENTDISPATCHER_REGISTERTIMER1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISQOBJECT(3) )
  {
    HB_FUNC_EXEC( QABSTRACTEVENTDISPATCHER_REGISTERTIMER2 );
  }
}



/*
virtual void unregisterSocketNotifier ( QSocketNotifier * notifier ) = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_UNREGISTERSOCKETNOTIFIER )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSocketNotifier * par1 = (QSocketNotifier *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->unregisterSocketNotifier ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool unregisterTimer ( int timerId ) = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_UNREGISTERTIMER )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->unregisterTimer ( par1 );
    hb_retl( b );
  }
}


/*
virtual bool unregisterTimers ( QObject * object ) = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_UNREGISTERTIMERS )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->unregisterTimers ( par1 );
    hb_retl( b );
  }
}


/*
virtual void wakeUp () = 0
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_WAKEUP )
{
  QAbstractEventDispatcher * obj = (QAbstractEventDispatcher *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->wakeUp (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
QAbstractEventDispatcher * instance ( QThread * thread = 0 )
*/
HB_FUNC( QABSTRACTEVENTDISPATCHER_INSTANCE )
{
  QThread * par1 = ISNIL(1)? 0 : (QThread *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QAbstractEventDispatcher * ptr = QAbstractEventDispatcher::instance ( par1 );
  _qt4xhb_createReturnClass ( ptr, "QABSTRACTEVENTDISPATCHER" );}




