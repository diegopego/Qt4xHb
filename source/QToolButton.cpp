/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QToolButton>

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
QToolButton ( QWidget * parent = 0 )
*/
HB_FUNC( QTOOLBUTTON_NEW )
{
  QToolButton * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QToolButton ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QToolButton *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTOOLBUTTON_DELETE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
Qt::ArrowType arrowType () const
*/
HB_FUNC( QTOOLBUTTON_ARROWTYPE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->arrowType (  );
    hb_retni( i );
  }
}


/*
bool autoRaise () const 
*/
HB_FUNC( QTOOLBUTTON_AUTORAISE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoRaise (  );
    hb_retl( b );
  }
}


/*
QAction * defaultAction () const 
*/
HB_FUNC( QTOOLBUTTON_DEFAULTACTION )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * ptr = obj->defaultAction (  );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
QMenu * menu () const
*/
HB_FUNC( QTOOLBUTTON_MENU )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QMenu * ptr = obj->menu (  );
    _qt4xhb_createReturnClass ( ptr, "QMENU" );  }
}


/*
ToolButtonPopupMode popupMode () const
*/
HB_FUNC( QTOOLBUTTON_POPUPMODE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->popupMode (  );
    hb_retni( i );
  }
}


/*
void setArrowType ( Qt::ArrowType type )
*/
HB_FUNC( QTOOLBUTTON_SETARROWTYPE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setArrowType (  (Qt::ArrowType) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAutoRaise ( bool enable )
*/
HB_FUNC( QTOOLBUTTON_SETAUTORAISE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoRaise ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMenu ( QMenu * menu )
*/
HB_FUNC( QTOOLBUTTON_SETMENU )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QMenu * par1 = (QMenu *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMenu ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPopupMode ( ToolButtonPopupMode mode )
*/
HB_FUNC( QTOOLBUTTON_SETPOPUPMODE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setPopupMode (  (QToolButton::ToolButtonPopupMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Qt::ToolButtonStyle toolButtonStyle () const
*/
HB_FUNC( QTOOLBUTTON_TOOLBUTTONSTYLE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->toolButtonStyle (  );
    hb_retni( i );
  }
}


/*
virtual QSize minimumSizeHint () const
*/
HB_FUNC( QTOOLBUTTON_MINIMUMSIZEHINT )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->minimumSizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual QSize sizeHint () const
*/
HB_FUNC( QTOOLBUTTON_SIZEHINT )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
void setDefaultAction ( QAction * action )
*/
HB_FUNC( QTOOLBUTTON_SETDEFAULTACTION )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * par1 = (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDefaultAction ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setToolButtonStyle ( Qt::ToolButtonStyle style )
*/
HB_FUNC( QTOOLBUTTON_SETTOOLBUTTONSTYLE )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setToolButtonStyle (  (Qt::ToolButtonStyle) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showMenu ()
*/
HB_FUNC( QTOOLBUTTON_SHOWMENU )
{
  QToolButton * obj = (QToolButton *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->showMenu (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




