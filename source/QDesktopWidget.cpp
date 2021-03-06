/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDesktopWidget>

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
const QRect availableGeometry ( int screen = -1 ) const
*/
HB_FUNC( QDESKTOPWIDGET_AVAILABLEGEOMETRY1 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? -1 : hb_parni(1);
    QRect * ptr = new QRect( obj->availableGeometry ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
const QRect availableGeometry ( const QWidget * widget ) const
*/
HB_FUNC( QDESKTOPWIDGET_AVAILABLEGEOMETRY2 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QWidget * par1 = (const QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->availableGeometry ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
const QRect availableGeometry ( const QPoint & p ) const
*/
HB_FUNC( QDESKTOPWIDGET_AVAILABLEGEOMETRY3 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->availableGeometry ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


//[1]const QRect availableGeometry ( int screen = -1 ) const
//[2]const QRect availableGeometry ( const QWidget * widget ) const
//[3]const QRect availableGeometry ( const QPoint & p ) const

HB_FUNC( QDESKTOPWIDGET_AVAILABLEGEOMETRY )
{
  if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_AVAILABLEGEOMETRY1 );
  }
  else if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_AVAILABLEGEOMETRY2 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_AVAILABLEGEOMETRY3 );
  }
}

/*
bool isVirtualDesktop () const
*/
HB_FUNC( QDESKTOPWIDGET_ISVIRTUALDESKTOP )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isVirtualDesktop (  );
    hb_retl( b );
  }
}


/*
int primaryScreen () const
*/
HB_FUNC( QDESKTOPWIDGET_PRIMARYSCREEN )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->primaryScreen (  );
    hb_retni( i );
  }
}


/*
QWidget * screen ( int screen = -1 )
*/
HB_FUNC( QDESKTOPWIDGET_SCREEN )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? -1 : hb_parni(1);
    QWidget * ptr = obj->screen ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
int screenCount () const
*/
HB_FUNC( QDESKTOPWIDGET_SCREENCOUNT )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->screenCount (  );
    hb_retni( i );
  }
}


/*
const QRect screenGeometry ( int screen = -1 ) const
*/
HB_FUNC( QDESKTOPWIDGET_SCREENGEOMETRY1 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? -1 : hb_parni(1);
    QRect * ptr = new QRect( obj->screenGeometry ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
const QRect screenGeometry ( const QWidget * widget ) const
*/
HB_FUNC( QDESKTOPWIDGET_SCREENGEOMETRY2 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QWidget * par1 = (const QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->screenGeometry ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
const QRect screenGeometry ( const QPoint & p ) const
*/
HB_FUNC( QDESKTOPWIDGET_SCREENGEOMETRY3 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->screenGeometry ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


//[1]const QRect screenGeometry ( int screen = -1 ) const
//[2]const QRect screenGeometry ( const QWidget * widget ) const
//[3]const QRect screenGeometry ( const QPoint & p ) const

HB_FUNC( QDESKTOPWIDGET_SCREENGEOMETRY )
{
  if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_SCREENGEOMETRY1 );
  }
  else if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_SCREENGEOMETRY2 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_SCREENGEOMETRY3 );
  }
}

/*
int screenNumber ( const QWidget * widget = 0 ) const
*/
HB_FUNC( QDESKTOPWIDGET_SCREENNUMBER1 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QWidget * par1 = ISNIL(1)? 0 : (const QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->screenNumber ( par1 );
    hb_retni( i );
  }
}


/*
int screenNumber ( const QPoint & point ) const
*/
HB_FUNC( QDESKTOPWIDGET_SCREENNUMBER2 )
{
  QDesktopWidget * obj = (QDesktopWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->screenNumber ( *par1 );
    hb_retni( i );
  }
}


//[1]int screenNumber ( const QWidget * widget = 0 ) const
//[2]int screenNumber ( const QPoint & point ) const

HB_FUNC( QDESKTOPWIDGET_SCREENNUMBER )
{
  if( ISBETWEEN(0,1) && (ISQWIDGET(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_SCREENNUMBER1 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QDESKTOPWIDGET_SCREENNUMBER2 );
  }
}



