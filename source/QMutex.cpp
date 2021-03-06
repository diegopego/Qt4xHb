/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QMutex>

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
QMutex ( RecursionMode mode = NonRecursive )
*/
HB_FUNC( QMUTEX_NEW )
{
  QMutex * o = NULL;
  int par1 = ISNIL(1)? (int) QMutex::NonRecursive : hb_parni(1);
  o = new QMutex (  (QMutex::RecursionMode) par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QMutex *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


HB_FUNC( QMUTEX_DELETE )
{
  QMutex * obj = (QMutex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void lock ()
*/
HB_FUNC( QMUTEX_LOCK )
{
  QMutex * obj = (QMutex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->lock (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool tryLock ()
*/
HB_FUNC( QMUTEX_TRYLOCK1 )
{
  QMutex * obj = (QMutex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->tryLock (  );
    hb_retl( b );
  }
}


/*
bool tryLock ( int timeout )
*/
HB_FUNC( QMUTEX_TRYLOCK2 )
{
  QMutex * obj = (QMutex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->tryLock ( par1 );
    hb_retl( b );
  }
}


//[1]bool tryLock ()
//[2]bool tryLock ( int timeout )

HB_FUNC( QMUTEX_TRYLOCK )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QMUTEX_TRYLOCK1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QMUTEX_TRYLOCK2 );
  }
}

/*
void unlock ()
*/
HB_FUNC( QMUTEX_UNLOCK )
{
  QMutex * obj = (QMutex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unlock (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



