
/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QWorkspace>

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
QWorkspace ( QWidget * parent = 0 )
*/
HB_FUNC( QWORKSPACE_NEW )
{
  QWorkspace * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QWorkspace ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QWorkspace *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QWORKSPACE_DELETE )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QWidget * activeWindow () const
*/
HB_FUNC( QWORKSPACE_ACTIVEWINDOW )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->activeWindow (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QWidget * addWindow ( QWidget * w, Qt::WindowFlags flags = 0 )
*/
HB_FUNC( QWORKSPACE_ADDWINDOW )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) 0 : hb_parni(2);
    QWidget * ptr = obj->addWindow ( par1,  (Qt::WindowFlags) par2 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QBrush background () const
*/
HB_FUNC( QWORKSPACE_BACKGROUND )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBrush * ptr = new QBrush( obj->background (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBRUSH", true );  }
}


/*
bool scrollBarsEnabled () const
*/
HB_FUNC( QWORKSPACE_SCROLLBARSENABLED )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->scrollBarsEnabled (  );
    hb_retl( b );
  }
}


/*
void setBackground ( const QBrush & background )
*/
HB_FUNC( QWORKSPACE_SETBACKGROUND )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBrush * par1 = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setBackground ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setScrollBarsEnabled ( bool enable )
*/
HB_FUNC( QWORKSPACE_SETSCROLLBARSENABLED )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setScrollBarsEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWidgetList windowList ( WindowOrder order = CreationOrder ) const
*/
HB_FUNC( QWORKSPACE_WINDOWLIST )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QWorkspace::CreationOrder : hb_parni(1);
    QWidgetList list = obj->windowList (  (QWorkspace::WindowOrder) par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QWIDGET" );
    #else
    pDynSym = hb_dynsymFindName( "QWIDGET" );
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
        hb_itemPutPtr( pItem, (QWidget *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


// Reimplemented Public Functions

/*
virtual QSize sizeHint () const
*/
HB_FUNC( QWORKSPACE_SIZEHINT )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


// Public Slots

/*
void activateNextWindow ()
*/
HB_FUNC( QWORKSPACE_ACTIVATENEXTWINDOW )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->activateNextWindow (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void activatePreviousWindow ()
*/
HB_FUNC( QWORKSPACE_ACTIVATEPREVIOUSWINDOW )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->activatePreviousWindow (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void arrangeIcons ()
*/
HB_FUNC( QWORKSPACE_ARRANGEICONS )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->arrangeIcons (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void cascade ()
*/
HB_FUNC( QWORKSPACE_CASCADE )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->cascade (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void closeActiveWindow ()
*/
HB_FUNC( QWORKSPACE_CLOSEACTIVEWINDOW )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->closeActiveWindow (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void closeAllWindows ()
*/
HB_FUNC( QWORKSPACE_CLOSEALLWINDOWS )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->closeAllWindows (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setActiveWindow ( QWidget * w )
*/
HB_FUNC( QWORKSPACE_SETACTIVEWINDOW )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setActiveWindow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void tile ()
*/
HB_FUNC( QWORKSPACE_TILE )
{
  QWorkspace * obj = (QWorkspace *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->tile (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





