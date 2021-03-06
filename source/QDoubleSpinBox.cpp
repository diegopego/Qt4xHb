/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDoubleSpinBox>

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
QDoubleSpinBox ( QWidget * parent = 0 )
*/
HB_FUNC( QDOUBLESPINBOX_NEW )
{
  QDoubleSpinBox * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QDoubleSpinBox ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDoubleSpinBox *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}



/*
QString cleanText () const
*/
HB_FUNC( QDOUBLESPINBOX_CLEANTEXT )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->cleanText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int decimals () const
*/
HB_FUNC( QDOUBLESPINBOX_DECIMALS )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->decimals (  );
    hb_retni( i );
  }
}


/*
double maximum () const
*/
HB_FUNC( QDOUBLESPINBOX_MAXIMUM )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double r = obj->maximum (  );
    hb_retnd( r );
  }
}


/*
double minimum () const
*/
HB_FUNC( QDOUBLESPINBOX_MINIMUM )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double r = obj->minimum (  );
    hb_retnd( r );
  }
}


/*
QString prefix () const
*/
HB_FUNC( QDOUBLESPINBOX_PREFIX )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->prefix (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setDecimals ( int prec )
*/
HB_FUNC( QDOUBLESPINBOX_SETDECIMALS )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setDecimals ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMaximum ( double max )
*/
HB_FUNC( QDOUBLESPINBOX_SETMAXIMUM )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    obj->setMaximum ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimum ( double min )
*/
HB_FUNC( QDOUBLESPINBOX_SETMINIMUM )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    obj->setMinimum ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPrefix ( const QString & prefix )
*/
HB_FUNC( QDOUBLESPINBOX_SETPREFIX )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setPrefix ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRange ( double minimum, double maximum )
*/
HB_FUNC( QDOUBLESPINBOX_SETRANGE )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    double par2 = hb_parnd(2);
    obj->setRange ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSingleStep ( double val )
*/
HB_FUNC( QDOUBLESPINBOX_SETSINGLESTEP )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    obj->setSingleStep ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSuffix ( const QString & suffix )
*/
HB_FUNC( QDOUBLESPINBOX_SETSUFFIX )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setSuffix ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
double singleStep () const
*/
HB_FUNC( QDOUBLESPINBOX_SINGLESTEP )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double r = obj->singleStep (  );
    hb_retnd( r );
  }
}


/*
QString suffix () const
*/
HB_FUNC( QDOUBLESPINBOX_SUFFIX )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->suffix (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QString textFromValue ( double value ) const
*/
HB_FUNC( QDOUBLESPINBOX_TEXTFROMVALUE )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    QString str1 = obj->textFromValue ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
double value () const
*/
HB_FUNC( QDOUBLESPINBOX_VALUE )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double r = obj->value (  );
    hb_retnd( r );
  }
}


/*
virtual double valueFromText ( const QString & text ) const
*/
HB_FUNC( QDOUBLESPINBOX_VALUEFROMTEXT )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    double r = obj->valueFromText ( par1 );
    hb_retnd( r );
  }
}


/*
virtual void fixup ( QString & input ) const
*/
HB_FUNC( QDOUBLESPINBOX_FIXUP )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->fixup ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QValidator::State validate ( QString & text, int & pos ) const
*/
HB_FUNC( QDOUBLESPINBOX_VALIDATE )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    int i = obj->validate ( par1, par2 );
    hb_retni( i );
  }
}


/*
void setValue ( double val )
*/
HB_FUNC( QDOUBLESPINBOX_SETVALUE )
{
  QDoubleSpinBox * obj = (QDoubleSpinBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    obj->setValue ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




