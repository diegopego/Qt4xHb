/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QStatusBar>

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
QStatusBar ( QWidget * parent = 0 )
*/
HB_FUNC( QSTATUSBAR_NEW )
{
  QStatusBar * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QStatusBar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QStatusBar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QSTATUSBAR_DELETE )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addPermanentWidget ( QWidget * widget, int stretch = 0 )
*/
HB_FUNC( QSTATUSBAR_ADDPERMANENTWIDGET )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    obj->addPermanentWidget ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addWidget ( QWidget * widget, int stretch = 0 )
*/
HB_FUNC( QSTATUSBAR_ADDWIDGET )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    obj->addWidget ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString currentMessage () const
*/
HB_FUNC( QSTATUSBAR_CURRENTMESSAGE )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->currentMessage (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int insertPermanentWidget ( int index, QWidget * widget, int stretch = 0 )
*/
HB_FUNC( QSTATUSBAR_INSERTPERMANENTWIDGET )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? 0 : hb_parni(3);
    int i = obj->insertPermanentWidget ( par1, par2, par3 );
    hb_retni( i );
  }
}


/*
int insertWidget ( int index, QWidget * widget, int stretch = 0 )
*/
HB_FUNC( QSTATUSBAR_INSERTWIDGET )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? 0 : hb_parni(3);
    int i = obj->insertWidget ( par1, par2, par3 );
    hb_retni( i );
  }
}


/*
bool isSizeGripEnabled () const
*/
HB_FUNC( QSTATUSBAR_ISSIZEGRIPENABLED )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSizeGripEnabled (  );
    hb_retl( b );
  }
}


/*
void removeWidget ( QWidget * widget )
*/
HB_FUNC( QSTATUSBAR_REMOVEWIDGET )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSizeGripEnabled ( bool )
*/
HB_FUNC( QSTATUSBAR_SETSIZEGRIPENABLED )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSizeGripEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clearMessage ()
*/
HB_FUNC( QSTATUSBAR_CLEARMESSAGE )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearMessage (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showMessage ( const QString & message, int timeout = 0 )
*/
HB_FUNC( QSTATUSBAR_SHOWMESSAGE )
{
  QStatusBar * obj = (QStatusBar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    obj->showMessage ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




