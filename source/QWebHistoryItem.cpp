/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QWebHistoryItem>

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

#include <QVariant>

/*
QWebHistoryItem ( const QWebHistoryItem & other )
*/
HB_FUNC( QWEBHISTORYITEM_NEW )
{
  QWebHistoryItem * o = NULL;
  QWebHistoryItem * par1 = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QWebHistoryItem ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QWebHistoryItem *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


HB_FUNC( QWEBHISTORYITEM_DELETE )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QIcon icon () const
*/
HB_FUNC( QWEBHISTORYITEM_ICON )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIcon * ptr = new QIcon( obj->icon (  ) );
    _qt4xhb_createReturnClass ( ptr, "QICON", true );  }
}


/*
bool isValid () const
*/
HB_FUNC( QWEBHISTORYITEM_ISVALID )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
QDateTime lastVisited () const
*/
HB_FUNC( QWEBHISTORYITEM_LASTVISITED )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDateTime * ptr = new QDateTime( obj->lastVisited (  ) );
    _qt4xhb_createReturnClass ( ptr, "QDATETIME", true );  }
}


/*
QUrl originalUrl () const
*/
HB_FUNC( QWEBHISTORYITEM_ORIGINALURL )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * ptr = new QUrl( obj->originalUrl (  ) );
    _qt4xhb_createReturnClass ( ptr, "QURL", true );  }
}


/*
void setUserData ( const QVariant & userData )
*/
HB_FUNC( QWEBHISTORYITEM_SETUSERDATA )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVariant * par1 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setUserData ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString title () const
*/
HB_FUNC( QWEBHISTORYITEM_TITLE )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->title (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QUrl url () const
*/
HB_FUNC( QWEBHISTORYITEM_URL )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * ptr = new QUrl( obj->url (  ) );
    _qt4xhb_createReturnClass ( ptr, "QURL", true );  }
}


/*
QVariant userData () const
*/
HB_FUNC( QWEBHISTORYITEM_USERDATA )
{
  QWebHistoryItem * obj = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVariant * ptr = new QVariant( obj->userData (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}



