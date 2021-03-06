/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QElapsedTimer>

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
QElapsedTimer()
*/
HB_FUNC( QELAPSEDTIMER_NEW )
{
  QElapsedTimer * o = NULL;
  o = new QElapsedTimer (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QElapsedTimer *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


HB_FUNC( QELAPSEDTIMER_DELETE )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
qint64 elapsed() const
*/
HB_FUNC( QELAPSEDTIMER_ELAPSED )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->elapsed (  );
    hb_retni( i );
  }
}


/*
bool hasExpired(qint64 timeout) const
*/
HB_FUNC( QELAPSEDTIMER_HASEXPIRED )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 par1 = hb_parni(1);
    bool b = obj->hasExpired ( par1 );
    hb_retl( b );
  }
}


/*
void invalidate()
*/
HB_FUNC( QELAPSEDTIMER_INVALIDATE )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->invalidate (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isValid() const
*/
HB_FUNC( QELAPSEDTIMER_ISVALID )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
qint64 msecsSinceReference() const
*/
HB_FUNC( QELAPSEDTIMER_MSECSSINCEREFERENCE )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->msecsSinceReference (  );
    hb_retni( i );
  }
}


/*
qint64 msecsTo(const QElapsedTimer & other) const
*/
HB_FUNC( QELAPSEDTIMER_MSECSTO )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QElapsedTimer * par1 = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qint64 i = obj->msecsTo ( *par1 );
    hb_retni( i );
  }
}


/*
qint64 nsecsElapsed() const
*/
HB_FUNC( QELAPSEDTIMER_NSECSELAPSED )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->nsecsElapsed (  );
    hb_retni( i );
  }
}


/*
qint64 restart()
*/
HB_FUNC( QELAPSEDTIMER_RESTART )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->restart (  );
    hb_retni( i );
  }
}


/*
qint64 secsTo(const QElapsedTimer & other) const
*/
HB_FUNC( QELAPSEDTIMER_SECSTO )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QElapsedTimer * par1 = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qint64 i = obj->secsTo ( *par1 );
    hb_retni( i );
  }
}


/*
void start()
*/
HB_FUNC( QELAPSEDTIMER_START )
{
  QElapsedTimer * obj = (QElapsedTimer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->start (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
ClockType clockType()
*/
HB_FUNC( QELAPSEDTIMER_CLOCKTYPE )
{
  int i = QElapsedTimer::clockType (  );
  hb_retni( i );
}


/*
bool isMonotonic()
*/
HB_FUNC( QELAPSEDTIMER_ISMONOTONIC )
{
  bool b = QElapsedTimer::isMonotonic (  );
  hb_retl( b );
}



