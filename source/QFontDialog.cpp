/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFontDialog>

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
QFontDialog(QWidget *parent = 0)
*/
HB_FUNC( QFONTDIALOG_NEW1 )
{
  QFontDialog * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFontDialog ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QFontDialog(const QFont &initial, QWidget *parent = 0)
*/
HB_FUNC( QFONTDIALOG_NEW2 )
{
  QFontDialog * o = NULL;
  QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFontDialog ( *par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QFontDialog(QWidget *parent = 0)
//[2]QFontDialog(const QFont &initial, QWidget *parent = 0)

HB_FUNC( QFONTDIALOG_NEW )
{
  if( ISBETWEEN(0,1) && (ISQWIDGET(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QFONTDIALOG_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQFONT(1) && (ISQWIDGET(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QFONTDIALOG_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}


/*
QFont currentFont () const
*/
HB_FUNC( QFONTDIALOG_CURRENTFONT )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * ptr = new QFont( obj->currentFont (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFONT", true );  }
}


/*
void open ( QObject * receiver, const char * member )
*/
HB_FUNC( QFONTDIALOG_OPEN )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = hb_parc(2);
    obj->open ( par1,  (const char *) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
FontDialogOptions options () const
*/
HB_FUNC( QFONTDIALOG_OPTIONS )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->options (  );
    hb_retni( i );
  }
}


/*
QFont selectedFont () const
*/
HB_FUNC( QFONTDIALOG_SELECTEDFONT )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * ptr = new QFont( obj->selectedFont (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFONT", true );  }
}


/*
void setCurrentFont ( const QFont & font )
*/
HB_FUNC( QFONTDIALOG_SETCURRENTFONT )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCurrentFont ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOption ( FontDialogOption option, bool on = true )
*/
HB_FUNC( QFONTDIALOG_SETOPTION )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setOption (  (QFontDialog::FontDialogOption) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOptions ( FontDialogOptions options )
*/
HB_FUNC( QFONTDIALOG_SETOPTIONS )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setOptions (  (QFontDialog::FontDialogOptions) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool testOption ( FontDialogOption option ) const
*/
HB_FUNC( QFONTDIALOG_TESTOPTION )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->testOption (  (QFontDialog::FontDialogOption) par1 );
    hb_retl( b );
  }
}


/*
virtual void setVisible ( bool visible )
*/
HB_FUNC( QFONTDIALOG_SETVISIBLE )
{
  QFontDialog * obj = (QFontDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
static QFont getFont(bool *ok, const QFont &initial, QWidget *parent, const QString &title,FontDialogOptions options)
*/
HB_FUNC( QFONTDIALOG_GETFONT1 )
{
  bool par1;
  QFont * par2 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par3 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par4 = hb_parc(4);
  int par5 = hb_parni(5);
  QFont * ptr = new QFont( QFontDialog::getFont ( &par1, *par2, par3, par4,  (QFontDialog::FontDialogOptions) par5 ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );  hb_storl( par1, 1 );
}


/*
static QFont getFont(bool *ok, const QFont &initial, QWidget *parent, const QString &title)
*/
HB_FUNC( QFONTDIALOG_GETFONT2 )
{
  bool par1;
  QFont * par2 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par3 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par4 = hb_parc(4);
  QFont * ptr = new QFont( QFontDialog::getFont ( &par1, *par2, par3, par4 ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );  hb_storl( par1, 1 );
}


/*
static QFont getFont(bool *ok, const QFont &initial, QWidget *parent = 0)
*/
HB_FUNC( QFONTDIALOG_GETFONT3 )
{
  bool par1;
  QFont * par2 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par3 = ISNIL(3)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  QFont * ptr = new QFont( QFontDialog::getFont ( &par1, *par2, par3 ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );  hb_storl( par1, 1 );
}


/*
static QFont getFont(bool *ok, QWidget *parent = 0)
*/
HB_FUNC( QFONTDIALOG_GETFONT4 )
{
  bool par1;
  QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QFont * ptr = new QFont( QFontDialog::getFont ( &par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );  hb_storl( par1, 1 );
}


//[1]static QFont getFont(bool *ok, const QFont &initial, QWidget *parent, const QString &title,FontDialogOptions options)
//[2]static QFont getFont(bool *ok, const QFont &initial, QWidget *parent, const QString &title)
//[3]static QFont getFont(bool *ok, const QFont &initial, QWidget *parent = 0)
//[4]static QFont getFont(bool *ok, QWidget *parent = 0)

HB_FUNC( QFONTDIALOG_GETFONT )
{
  if( ISNUMPAR(5) && ISLOG(1) && ISQFONT(2) && ISQWIDGET(3) && ISCHAR(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QFONTDIALOG_GETFONT1 );
  }
  else if( ISNUMPAR(4) && ISLOG(1) && ISQFONT(2) && ISQWIDGET(3) && ISCHAR(4) )
  {
    HB_FUNC_EXEC( QFONTDIALOG_GETFONT2 );
  }
  else if( ISBETWEEN(2,3) && ISLOG(1) && ISQFONT(2) && (ISQWIDGET(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QFONTDIALOG_GETFONT3 );
  }
  else if( ISBETWEEN(1,2) && ISLOG(1) && (ISQWIDGET(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QFONTDIALOG_GETFONT4 );
  }
}



