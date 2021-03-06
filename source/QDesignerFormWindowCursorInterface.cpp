/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDesignerFormWindowCursorInterface>

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

HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_DELETE )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QWidget * current () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_CURRENT )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->current (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual QDesignerFormWindowInterface * formWindow () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_FORMWINDOW )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormWindowInterface * ptr = obj->formWindow (  );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWINTERFACE" );  }
}


/*
virtual bool hasSelection () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_HASSELECTION )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasSelection (  );
    hb_retl( b );
  }
}


/*
bool isWidgetSelected ( QWidget * widget ) const
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_ISWIDGETSELECTED )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isWidgetSelected ( par1 );
    hb_retl( b );
  }
}


/*
virtual bool movePosition ( MoveOperation operation, MoveMode mode = MoveAnchor ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_MOVEPOSITION )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) QDesignerFormWindowCursorInterface::MoveAnchor : hb_parni(2);
    bool b = obj->movePosition (  (QDesignerFormWindowCursorInterface::MoveOperation) par1,  (QDesignerFormWindowCursorInterface::MoveMode) par2 );
    hb_retl( b );
  }
}


/*
virtual int position () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_POSITION )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->position (  );
    hb_retni( i );
  }
}



/*
virtual QWidget * selectedWidget ( int index ) const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_SELECTEDWIDGET )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * ptr = obj->selectedWidget ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual int selectedWidgetCount () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_SELECTEDWIDGETCOUNT )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->selectedWidgetCount (  );
    hb_retni( i );
  }
}


/*
virtual void setPosition ( int position, MoveMode mode = MoveAnchor ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_SETPOSITION )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) QDesignerFormWindowCursorInterface::MoveAnchor : hb_parni(2);
    obj->setPosition ( par1,  (QDesignerFormWindowCursorInterface::MoveMode) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




/*
virtual QWidget * widget ( int index ) const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_WIDGET )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * ptr = obj->widget ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual int widgetCount () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWCURSORINTERFACE_WIDGETCOUNT )
{
  QDesignerFormWindowCursorInterface * obj = (QDesignerFormWindowCursorInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->widgetCount (  );
    hb_retni( i );
  }
}



