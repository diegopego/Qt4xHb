/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QEventLoop>

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
QEventLoop ( QObject * parent = 0 )
*/
HB_FUNC( QEVENTLOOP_NEW )
{
  QEventLoop * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QEventLoop ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QEventLoop *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QEVENTLOOP_DELETE )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int exec ( ProcessEventsFlags flags = AllEvents )
*/
HB_FUNC( QEVENTLOOP_EXEC )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QEventLoop::AllEvents : hb_parni(1);
    int i = obj->exec (  (QEventLoop::ProcessEventsFlags) par1 );
    hb_retni( i );
  }
}


/*
void exit ( int returnCode = 0 )
*/
HB_FUNC( QEVENTLOOP_EXIT )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? 0 : hb_parni(1);
    obj->exit ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isRunning () const
*/
HB_FUNC( QEVENTLOOP_ISRUNNING )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isRunning (  );
    hb_retl( b );
  }
}


/*
bool processEvents ( ProcessEventsFlags flags = AllEvents )
*/
HB_FUNC( QEVENTLOOP_PROCESSEVENTS1 )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QEventLoop::AllEvents : hb_parni(1);
    bool b = obj->processEvents (  (QEventLoop::ProcessEventsFlags) par1 );
    hb_retl( b );
  }
}


/*
void processEvents ( ProcessEventsFlags flags, int maxTime )
*/
HB_FUNC( QEVENTLOOP_PROCESSEVENTS2 )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->processEvents (  (QEventLoop::ProcessEventsFlags) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]bool processEvents ( ProcessEventsFlags flags = AllEvents )
//[2]void processEvents ( ProcessEventsFlags flags, int maxTime )

HB_FUNC( QEVENTLOOP_PROCESSEVENTS )
{
  if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QEVENTLOOP_PROCESSEVENTS1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QEVENTLOOP_PROCESSEVENTS2 );
  }
}

/*
void wakeUp ()
*/
HB_FUNC( QEVENTLOOP_WAKEUP )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->wakeUp (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void quit ()
*/
HB_FUNC( QEVENTLOOP_QUIT )
{
  QEventLoop * obj = (QEventLoop *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->quit (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



