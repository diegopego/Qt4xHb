/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QReadLocker>

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
QReadLocker ( QReadWriteLock * lock )
*/
HB_FUNC( QREADLOCKER_NEW )
{
  QReadLocker * o = NULL;
  QReadWriteLock * par1 = (QReadWriteLock *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QReadLocker ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QReadLocker *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


HB_FUNC( QREADLOCKER_DELETE )
{
  QReadLocker * obj = (QReadLocker *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QReadWriteLock * readWriteLock () const
*/
HB_FUNC( QREADLOCKER_READWRITELOCK )
{
  QReadLocker * obj = (QReadLocker *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QReadWriteLock * ptr = obj->readWriteLock (  );
    _qt4xhb_createReturnClass ( ptr, "QREADWRITELOCK" );  }
}


/*
void relock ()
*/
HB_FUNC( QREADLOCKER_RELOCK )
{
  QReadLocker * obj = (QReadLocker *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->relock (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void unlock ()
*/
HB_FUNC( QREADLOCKER_UNLOCK )
{
  QReadLocker * obj = (QReadLocker *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unlock (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



