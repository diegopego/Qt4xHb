/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDesignerFormWindowManagerInterface>

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


HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_DELETE )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QAction * actionAdjustSize () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONADJUSTSIZE )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionAdjustSize (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionBreakLayout () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONBREAKLAYOUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionBreakLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionCopy () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONCOPY )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionCopy (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionCut () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONCUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionCut (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionDelete () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONDELETE )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionDelete (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
QAction * actionFormLayout () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONFORMLAYOUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionFormLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionGridLayout () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONGRIDLAYOUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionGridLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionHorizontalLayout () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONHORIZONTALLAYOUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionHorizontalLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionLower () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONLOWER )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionLower (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionPaste () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONPASTE )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionPaste (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionRaise () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONRAISE )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionRaise (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionRedo () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONREDO )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionRedo (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionSelectAll () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONSELECTALL )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionSelectAll (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
QAction * actionSimplifyLayout () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONSIMPLIFYLAYOUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionSimplifyLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionSplitHorizontal () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONSPLITHORIZONTAL )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionSplitHorizontal (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionSplitVertical () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONSPLITVERTICAL )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionSplitVertical (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionUndo () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONUNDO )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionUndo (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QAction * actionVerticalLayout () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIONVERTICALLAYOUT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->actionVerticalLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QDesignerFormWindowInterface * activeFormWindow () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ACTIVEFORMWINDOW )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormWindowInterface * ptr = obj->activeFormWindow (  );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWINTERFACE" );  }
}


/*
virtual QDesignerFormEditorInterface * core () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_CORE )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormEditorInterface * ptr = obj->core (  );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMEDITORINTERFACE" );  }
}


/*
virtual QDesignerFormWindowInterface * createFormWindow ( QWidget * parent = 0, Qt::WindowFlags flags = 0 )
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_CREATEFORMWINDOW )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) 0 : hb_parni(2);
    QDesignerFormWindowInterface * ptr = obj->createFormWindow ( par1,  (Qt::WindowFlags) par2 );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWINTERFACE" );  }
}


/*
virtual QDesignerFormWindowInterface * formWindow ( int index ) const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_FORMWINDOW )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QDesignerFormWindowInterface * ptr = obj->formWindow ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWINTERFACE" );  }
}


/*
virtual int formWindowCount () const
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_FORMWINDOWCOUNT )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->formWindowCount (  );
    hb_retni( i );
  }
}


/*
virtual void addFormWindow ( QDesignerFormWindowInterface * formWindow )
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_ADDFORMWINDOW )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormWindowInterface * par1 = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addFormWindow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void removeFormWindow ( QDesignerFormWindowInterface * formWindow )
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_REMOVEFORMWINDOW )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormWindowInterface * par1 = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeFormWindow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setActiveFormWindow ( QDesignerFormWindowInterface * formWindow )
*/
HB_FUNC( QDESIGNERFORMWINDOWMANAGERINTERFACE_SETACTIVEFORMWINDOW )
{
  QDesignerFormWindowManagerInterface * obj = (QDesignerFormWindowManagerInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormWindowInterface * par1 = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setActiveFormWindow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





