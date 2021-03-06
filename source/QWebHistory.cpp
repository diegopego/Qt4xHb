/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QWebHistory>

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
void back ()
*/
HB_FUNC( QWEBHISTORY_BACK )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->back (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWebHistoryItem backItem () const
*/
HB_FUNC( QWEBHISTORY_BACKITEM )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebHistoryItem * ptr = new QWebHistoryItem( obj->backItem (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBHISTORYITEM", true );  }
}


/*
QList<QWebHistoryItem> backItems ( int maxItems ) const
*/
HB_FUNC( QWEBHISTORY_BACKITEMS )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QList<QWebHistoryItem> list = obj->backItems ( par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QWEBHISTORYITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QWEBHISTORYITEM" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QWebHistoryItem *) new QWebHistoryItem ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        PHB_ITEM pDestroy = hb_itemNew( NULL );
        hb_itemPutL( pDestroy, true );
        hb_objSendMsg( pObject, "_SELF_DESTRUCTION", 1, pDestroy );
        hb_itemRelease( pDestroy );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
bool canGoBack () const
*/
HB_FUNC( QWEBHISTORY_CANGOBACK )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->canGoBack (  );
    hb_retl( b );
  }
}


/*
bool canGoForward () const
*/
HB_FUNC( QWEBHISTORY_CANGOFORWARD )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->canGoForward (  );
    hb_retl( b );
  }
}


/*
void clear ()
*/
HB_FUNC( QWEBHISTORY_CLEAR )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int count () const
*/
HB_FUNC( QWEBHISTORY_COUNT )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
QWebHistoryItem currentItem () const
*/
HB_FUNC( QWEBHISTORY_CURRENTITEM )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebHistoryItem * ptr = new QWebHistoryItem( obj->currentItem (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBHISTORYITEM", true );  }
}


/*
int currentItemIndex () const
*/
HB_FUNC( QWEBHISTORY_CURRENTITEMINDEX )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentItemIndex (  );
    hb_retni( i );
  }
}


/*
void forward ()
*/
HB_FUNC( QWEBHISTORY_FORWARD )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->forward (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWebHistoryItem forwardItem () const
*/
HB_FUNC( QWEBHISTORY_FORWARDITEM )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebHistoryItem * ptr = new QWebHistoryItem( obj->forwardItem (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBHISTORYITEM", true );  }
}


/*
QList<QWebHistoryItem> forwardItems ( int maxItems ) const
*/
HB_FUNC( QWEBHISTORY_FORWARDITEMS )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QList<QWebHistoryItem> list = obj->forwardItems ( par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QWEBHISTORYITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QWEBHISTORYITEM" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QWebHistoryItem *) new QWebHistoryItem ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        PHB_ITEM pDestroy = hb_itemNew( NULL );
        hb_itemPutL( pDestroy, true );
        hb_objSendMsg( pObject, "_SELF_DESTRUCTION", 1, pDestroy );
        hb_itemRelease( pDestroy );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
void goToItem ( const QWebHistoryItem & item )
*/
HB_FUNC( QWEBHISTORY_GOTOITEM )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebHistoryItem * par1 = (QWebHistoryItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->goToItem ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWebHistoryItem itemAt ( int i ) const
*/
HB_FUNC( QWEBHISTORY_ITEMAT )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWebHistoryItem * ptr = new QWebHistoryItem( obj->itemAt ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBHISTORYITEM", true );  }
}


/*
QList<QWebHistoryItem> items () const
*/
HB_FUNC( QWEBHISTORY_ITEMS )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QWebHistoryItem> list = obj->items (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QWEBHISTORYITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QWEBHISTORYITEM" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QWebHistoryItem *) new QWebHistoryItem ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        PHB_ITEM pDestroy = hb_itemNew( NULL );
        hb_itemPutL( pDestroy, true );
        hb_objSendMsg( pObject, "_SELF_DESTRUCTION", 1, pDestroy );
        hb_itemRelease( pDestroy );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
int maximumItemCount () const
*/
HB_FUNC( QWEBHISTORY_MAXIMUMITEMCOUNT )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maximumItemCount (  );
    hb_retni( i );
  }
}


/*
void setMaximumItemCount ( int count )
*/
HB_FUNC( QWEBHISTORY_SETMAXIMUMITEMCOUNT )
{
  QWebHistory * obj = (QWebHistory *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaximumItemCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



