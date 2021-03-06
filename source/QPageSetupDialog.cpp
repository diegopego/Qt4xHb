/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QPageSetupDialog>

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
QPageSetupDialog ( QPrinter * printer, QWidget * parent = 0 )
*/
HB_FUNC( QPAGESETUPDIALOG_NEW )
{
  QPageSetupDialog * o = NULL;
  QPrinter * par1 = (QPrinter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QPageSetupDialog ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPageSetupDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}



/*
void open ( QObject * receiver, const char * member )
*/
HB_FUNC( QPAGESETUPDIALOG_OPEN )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
     const char * par2 = ( const char *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->open ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
PageSetupDialogOptions options () const
*/
HB_FUNC( QPAGESETUPDIALOG_OPTIONS )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->options (  );
    hb_retni( i );
  }
}


/*
QPrinter * printer ()
*/
HB_FUNC( QPAGESETUPDIALOG_PRINTER )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPrinter * ptr = obj->printer (  );
    _qt4xhb_createReturnClass ( ptr, "QPRINTER" );  }
}


/*
void setOption ( PageSetupDialogOption option, bool on = true )
*/
HB_FUNC( QPAGESETUPDIALOG_SETOPTION )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setOption (  (QPageSetupDialog::PageSetupDialogOption) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOptions ( PageSetupDialogOptions options )
*/
HB_FUNC( QPAGESETUPDIALOG_SETOPTIONS )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setOptions (  (QPageSetupDialog::PageSetupDialogOptions) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool testOption ( PageSetupDialogOption option ) const
*/
HB_FUNC( QPAGESETUPDIALOG_TESTOPTION )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->testOption (  (QPageSetupDialog::PageSetupDialogOption) par1 );
    hb_retl( b );
  }
}


/*
virtual void setVisible ( bool visible )
*/
HB_FUNC( QPAGESETUPDIALOG_SETVISIBLE )
{
  QPageSetupDialog * obj = (QPageSetupDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



