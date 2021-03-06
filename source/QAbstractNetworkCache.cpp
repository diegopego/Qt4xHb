/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractNetworkCache>

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

HB_FUNC( QABSTRACTNETWORKCACHE_DELETE )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual qint64 cacheSize () const = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_CACHESIZE )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->cacheSize (  );
    hb_retni( i );
  }
}


/*
virtual QIODevice * data ( const QUrl & url ) = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_DATA )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QIODevice * ptr = obj->data ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
virtual void insert ( QIODevice * device ) = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_INSERT )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->insert ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QNetworkCacheMetaData metaData ( const QUrl & url ) = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_METADATA )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QNetworkCacheMetaData * ptr = new QNetworkCacheMetaData( obj->metaData ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QNETWORKCACHEMETADATA", true );  }
}


/*
virtual QIODevice * prepare ( const QNetworkCacheMetaData & metaData ) = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_PREPARE )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QNetworkCacheMetaData * par1 = (QNetworkCacheMetaData *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QIODevice * ptr = obj->prepare ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
virtual bool remove ( const QUrl & url ) = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_REMOVE )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->remove ( *par1 );
    hb_retl( b );
  }
}


/*
virtual void updateMetaData ( const QNetworkCacheMetaData & metaData ) = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_UPDATEMETADATA )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QNetworkCacheMetaData * par1 = (QNetworkCacheMetaData *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->updateMetaData ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void clear () = 0
*/
HB_FUNC( QABSTRACTNETWORKCACHE_CLEAR )
{
  QAbstractNetworkCache * obj = (QAbstractNetworkCache *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




