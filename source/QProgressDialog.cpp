/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QProgressDialog>

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
QProgressDialog ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
*/
HB_FUNC( QPROGRESSDIALOG_NEW1 )
{
  QProgressDialog * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) 0 : hb_parni(2);
  o = new QProgressDialog ( par1,  (Qt::WindowFlags) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QProgressDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QProgressDialog ( const QString & labelText, const QString & cancelButtonText, int minimum, int maximum, QWidget * parent = 0, Qt::WindowFlags f = 0 )
*/
HB_FUNC( QPROGRESSDIALOG_NEW2 )
{
  QProgressDialog * o = NULL;
  QString par1 = hb_parc(1);
  QString par2 = hb_parc(2);
  int par3 = hb_parni(3);
  int par4 = hb_parni(4);
  QWidget * par5 = ISNIL(5)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(5, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
  o = new QProgressDialog ( par1, par2, par3, par4, par5,  (Qt::WindowFlags) par6 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QProgressDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QProgressDialog ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
//[2]QProgressDialog ( const QString & labelText, const QString & cancelButtonText, int minimum, int maximum, QWidget * parent = 0, Qt::WindowFlags f = 0 )

HB_FUNC( QPROGRESSDIALOG_NEW )
{
  if( ISBETWEEN(0,2) && (ISQWIDGET(1)||ISNIL(1)) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QPROGRESSDIALOG_NEW1 );
  }
  else if( ISBETWEEN(4,6) && ISCHAR(1) && ISCHAR(2) && ISNUM(3) && ISNUM(4) && (ISQWIDGET(5)||ISNIL(5)) && (ISNUM(6)||ISNIL(6)) )
  {
    HB_FUNC_EXEC( QPROGRESSDIALOG_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QPROGRESSDIALOG_DELETE )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool autoClose () const
*/
HB_FUNC( QPROGRESSDIALOG_AUTOCLOSE )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoClose (  );
    hb_retl( b );
  }
}


/*
bool autoReset () const
*/
HB_FUNC( QPROGRESSDIALOG_AUTORESET )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoReset (  );
    hb_retl( b );
  }
}


/*
QString labelText () const
*/
HB_FUNC( QPROGRESSDIALOG_LABELTEXT )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->labelText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int maximum () const
*/
HB_FUNC( QPROGRESSDIALOG_MAXIMUM )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maximum (  );
    hb_retni( i );
  }
}


/*
int minimum () const
*/
HB_FUNC( QPROGRESSDIALOG_MINIMUM )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->minimum (  );
    hb_retni( i );
  }
}


/*
int minimumDuration () const
*/
HB_FUNC( QPROGRESSDIALOG_MINIMUMDURATION )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->minimumDuration (  );
    hb_retni( i );
  }
}


/*
void open ( QObject * receiver, const char * member )
*/
HB_FUNC( QPROGRESSDIALOG_OPEN )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = hb_parc(2);
    obj->open ( par1,  (const char *) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAutoClose ( bool close )
*/
HB_FUNC( QPROGRESSDIALOG_SETAUTOCLOSE )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoClose ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAutoReset ( bool reset )
*/
HB_FUNC( QPROGRESSDIALOG_SETAUTORESET )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoReset ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBar ( QProgressBar * bar )
*/
HB_FUNC( QPROGRESSDIALOG_SETBAR )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QProgressBar * par1 = (QProgressBar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setBar ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCancelButton ( QPushButton * cancelButton )
*/
HB_FUNC( QPROGRESSDIALOG_SETCANCELBUTTON )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPushButton * par1 = (QPushButton *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCancelButton ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLabel ( QLabel * label )
*/
HB_FUNC( QPROGRESSDIALOG_SETLABEL )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLabel * par1 = (QLabel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setLabel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int value () const
*/
HB_FUNC( QPROGRESSDIALOG_VALUE )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->value (  );
    hb_retni( i );
  }
}


/*
bool wasCanceled () const
*/
HB_FUNC( QPROGRESSDIALOG_WASCANCELED )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->wasCanceled (  );
    hb_retl( b );
  }
}


/*
virtual QSize sizeHint () const
*/
HB_FUNC( QPROGRESSDIALOG_SIZEHINT )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
void cancel ()
*/
HB_FUNC( QPROGRESSDIALOG_CANCEL )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->cancel (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void reset ()
*/
HB_FUNC( QPROGRESSDIALOG_RESET )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->reset (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCancelButtonText ( const QString & cancelButtonText )
*/
HB_FUNC( QPROGRESSDIALOG_SETCANCELBUTTONTEXT )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setCancelButtonText ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLabelText ( const QString & text )
*/
HB_FUNC( QPROGRESSDIALOG_SETLABELTEXT )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setLabelText ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMaximum ( int maximum )
*/
HB_FUNC( QPROGRESSDIALOG_SETMAXIMUM )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaximum ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimum ( int minimum )
*/
HB_FUNC( QPROGRESSDIALOG_SETMINIMUM )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMinimum ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimumDuration ( int ms )
*/
HB_FUNC( QPROGRESSDIALOG_SETMINIMUMDURATION )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMinimumDuration ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRange ( int minimum, int maximum )
*/
HB_FUNC( QPROGRESSDIALOG_SETRANGE )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setRange ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setValue ( int progress )
*/
HB_FUNC( QPROGRESSDIALOG_SETVALUE )
{
  QProgressDialog * obj = (QProgressDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setValue ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




