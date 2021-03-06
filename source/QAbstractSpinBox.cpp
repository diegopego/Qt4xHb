/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractSpinBox>

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
QAbstractSpinBox ( QWidget * parent = 0 )
*/
HB_FUNC( QABSTRACTSPINBOX_NEW )
{
  QAbstractSpinBox * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QAbstractSpinBox ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QAbstractSpinBox *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QABSTRACTSPINBOX_DELETE )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
Qt::Alignment alignment () const
*/
HB_FUNC( QABSTRACTSPINBOX_ALIGNMENT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->alignment (  );
    hb_retni( i );
  }
}


/*
ButtonSymbols buttonSymbols () const
*/
HB_FUNC( QABSTRACTSPINBOX_BUTTONSYMBOLS )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->buttonSymbols (  );
    hb_retni( i );
  }
}


/*
CorrectionMode correctionMode () const
*/
HB_FUNC( QABSTRACTSPINBOX_CORRECTIONMODE )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->correctionMode (  );
    hb_retni( i );
  }
}


/*
virtual void fixup ( QString & input ) const
*/
HB_FUNC( QABSTRACTSPINBOX_FIXUP )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->fixup ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool hasAcceptableInput () const
*/
HB_FUNC( QABSTRACTSPINBOX_HASACCEPTABLEINPUT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasAcceptableInput (  );
    hb_retl( b );
  }
}


/*
bool hasFrame () const
*/
HB_FUNC( QABSTRACTSPINBOX_HASFRAME )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasFrame (  );
    hb_retl( b );
  }
}


/*
void interpretText ()
*/
HB_FUNC( QABSTRACTSPINBOX_INTERPRETTEXT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->interpretText (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isAccelerated () const
*/
HB_FUNC( QABSTRACTSPINBOX_ISACCELERATED )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isAccelerated (  );
    hb_retl( b );
  }
}


/*
bool isReadOnly () const
*/
HB_FUNC( QABSTRACTSPINBOX_ISREADONLY )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isReadOnly (  );
    hb_retl( b );
  }
}


/*
bool keyboardTracking () const
*/
HB_FUNC( QABSTRACTSPINBOX_KEYBOARDTRACKING )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->keyboardTracking (  );
    hb_retl( b );
  }
}


/*
void setAccelerated ( bool on )
*/
HB_FUNC( QABSTRACTSPINBOX_SETACCELERATED )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAccelerated ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAlignment ( Qt::Alignment flag )
*/
HB_FUNC( QABSTRACTSPINBOX_SETALIGNMENT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setAlignment (  (Qt::Alignment) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setButtonSymbols ( ButtonSymbols bs )
*/
HB_FUNC( QABSTRACTSPINBOX_SETBUTTONSYMBOLS )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setButtonSymbols (  (QAbstractSpinBox::ButtonSymbols) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCorrectionMode ( CorrectionMode cm )
*/
HB_FUNC( QABSTRACTSPINBOX_SETCORRECTIONMODE )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCorrectionMode (  (QAbstractSpinBox::CorrectionMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFrame ( bool )
*/
HB_FUNC( QABSTRACTSPINBOX_SETFRAME )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setFrame ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setKeyboardTracking ( bool kt )
*/
HB_FUNC( QABSTRACTSPINBOX_SETKEYBOARDTRACKING )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setKeyboardTracking ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setReadOnly ( bool r )
*/
HB_FUNC( QABSTRACTSPINBOX_SETREADONLY )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setReadOnly ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSpecialValueText ( const QString & txt )
*/
HB_FUNC( QABSTRACTSPINBOX_SETSPECIALVALUETEXT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setSpecialValueText ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWrapping ( bool w )
*/
HB_FUNC( QABSTRACTSPINBOX_SETWRAPPING )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWrapping ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString specialValueText () const
*/
HB_FUNC( QABSTRACTSPINBOX_SPECIALVALUETEXT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->specialValueText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual void stepBy ( int steps )
*/
HB_FUNC( QABSTRACTSPINBOX_STEPBY )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->stepBy ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString text () const
*/
HB_FUNC( QABSTRACTSPINBOX_TEXT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->text (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QValidator::State validate ( QString & input, int & pos ) const
*/
HB_FUNC( QABSTRACTSPINBOX_VALIDATE )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    int i = obj->validate ( par1, par2 );
    hb_retni( i );
  }
}


/*
bool wrapping () const
*/
HB_FUNC( QABSTRACTSPINBOX_WRAPPING )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->wrapping (  );
    hb_retl( b );
  }
}


/*
virtual bool event ( QEvent * event )
*/
HB_FUNC( QABSTRACTSPINBOX_EVENT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QEvent * par1 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->event ( par1 );
    hb_retl( b );
  }
}


/*
virtual QVariant inputMethodQuery ( Qt::InputMethodQuery query ) const
*/
HB_FUNC( QABSTRACTSPINBOX_INPUTMETHODQUERY )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QVariant * ptr = new QVariant( obj->inputMethodQuery (  (Qt::InputMethodQuery) par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual QSize minimumSizeHint () const
*/
HB_FUNC( QABSTRACTSPINBOX_MINIMUMSIZEHINT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->minimumSizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual QSize sizeHint () const
*/
HB_FUNC( QABSTRACTSPINBOX_SIZEHINT )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual void clear ()
*/
HB_FUNC( QABSTRACTSPINBOX_CLEAR )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void selectAll ()
*/
HB_FUNC( QABSTRACTSPINBOX_SELECTALL )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->selectAll (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void stepDown ()
*/
HB_FUNC( QABSTRACTSPINBOX_STEPDOWN )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->stepDown (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void stepUp ()
*/
HB_FUNC( QABSTRACTSPINBOX_STEPUP )
{
  QAbstractSpinBox * obj = (QAbstractSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->stepUp (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





