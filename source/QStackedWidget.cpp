/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QStackedWidget>

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
QStackedWidget ( QWidget * parent = 0 )
*/
HB_FUNC( QSTACKEDWIDGET_NEW )
{
  QStackedWidget * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QStackedWidget ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QStackedWidget *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QSTACKEDWIDGET_DELETE )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int addWidget ( QWidget * widget )
*/
HB_FUNC( QSTACKEDWIDGET_ADDWIDGET )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->addWidget ( par1 );
    hb_retni( i );
  }
}


/*
int count () const
*/
HB_FUNC( QSTACKEDWIDGET_COUNT )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
int currentIndex () const
*/
HB_FUNC( QSTACKEDWIDGET_CURRENTINDEX )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentIndex (  );
    hb_retni( i );
  }
}


/*
QWidget * currentWidget () const
*/
HB_FUNC( QSTACKEDWIDGET_CURRENTWIDGET )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->currentWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
int indexOf ( QWidget * widget ) const
*/
HB_FUNC( QSTACKEDWIDGET_INDEXOF )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->indexOf ( par1 );
    hb_retni( i );
  }
}


/*
int insertWidget ( int index, QWidget * widget )
*/
HB_FUNC( QSTACKEDWIDGET_INSERTWIDGET )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->insertWidget ( par1, par2 );
    hb_retni( i );
  }
}


/*
void removeWidget ( QWidget * widget )
*/
HB_FUNC( QSTACKEDWIDGET_REMOVEWIDGET )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWidget * widget ( int index ) const
*/
HB_FUNC( QSTACKEDWIDGET_WIDGET )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * ptr = obj->widget ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
void setCurrentIndex ( int index )
*/
HB_FUNC( QSTACKEDWIDGET_SETCURRENTINDEX )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCurrentIndex ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentWidget ( QWidget * widget )
*/
HB_FUNC( QSTACKEDWIDGET_SETCURRENTWIDGET )
{
  QStackedWidget * obj = (QStackedWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCurrentWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





