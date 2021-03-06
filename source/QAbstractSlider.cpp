/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractSlider>

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


HB_FUNC( QABSTRACTSLIDER_DELETE )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool hasTracking () const
*/
HB_FUNC( QABSTRACTSLIDER_HASTRACKING )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasTracking (  );
    hb_retl( b );
  }
}


/*
bool invertedAppearance () const
*/
HB_FUNC( QABSTRACTSLIDER_INVERTEDAPPEARANCE )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->invertedAppearance (  );
    hb_retl( b );
  }
}


/*
bool invertedControls () const
*/
HB_FUNC( QABSTRACTSLIDER_INVERTEDCONTROLS )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->invertedControls (  );
    hb_retl( b );
  }
}


/*
bool isSliderDown () const
*/
HB_FUNC( QABSTRACTSLIDER_ISSLIDERDOWN )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSliderDown (  );
    hb_retl( b );
  }
}


/*
int maximum () const
*/
HB_FUNC( QABSTRACTSLIDER_MAXIMUM )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maximum (  );
    hb_retni( i );
  }
}


/*
int minimum () const
*/
HB_FUNC( QABSTRACTSLIDER_MINIMUM )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->minimum (  );
    hb_retni( i );
  }
}


/*
Qt::Orientation orientation () const
*/
HB_FUNC( QABSTRACTSLIDER_ORIENTATION )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->orientation (  );
    hb_retni( i );
  }
}


/*
int pageStep () const
*/
HB_FUNC( QABSTRACTSLIDER_PAGESTEP )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->pageStep (  );
    hb_retni( i );
  }
}


/*
void setInvertedAppearance ( bool )
*/
HB_FUNC( QABSTRACTSLIDER_SETINVERTEDAPPEARANCE )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setInvertedAppearance ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInvertedControls ( bool )
*/
HB_FUNC( QABSTRACTSLIDER_SETINVERTEDCONTROLS )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setInvertedControls ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMaximum ( int )
*/
HB_FUNC( QABSTRACTSLIDER_SETMAXIMUM )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaximum ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimum ( int )
*/
HB_FUNC( QABSTRACTSLIDER_SETMINIMUM )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMinimum ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPageStep ( int )
*/
HB_FUNC( QABSTRACTSLIDER_SETPAGESTEP )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setPageStep ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRange ( int min, int max )
*/
HB_FUNC( QABSTRACTSLIDER_SETRANGE )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setRange ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSingleStep ( int )
*/
HB_FUNC( QABSTRACTSLIDER_SETSINGLESTEP )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSingleStep ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSliderDown ( bool )
*/
HB_FUNC( QABSTRACTSLIDER_SETSLIDERDOWN )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSliderDown ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSliderPosition ( int )
*/
HB_FUNC( QABSTRACTSLIDER_SETSLIDERPOSITION )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSliderPosition ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTracking ( bool enable )
*/
HB_FUNC( QABSTRACTSLIDER_SETTRACKING )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setTracking ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int singleStep () const
*/
HB_FUNC( QABSTRACTSLIDER_SINGLESTEP )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->singleStep (  );
    hb_retni( i );
  }
}


/*
int sliderPosition () const
*/
HB_FUNC( QABSTRACTSLIDER_SLIDERPOSITION )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->sliderPosition (  );
    hb_retni( i );
  }
}


/*
void triggerAction ( SliderAction action )
*/
HB_FUNC( QABSTRACTSLIDER_TRIGGERACTION )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->triggerAction (  (QAbstractSlider::SliderAction) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int value () const
*/
HB_FUNC( QABSTRACTSLIDER_VALUE )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->value (  );
    hb_retni( i );
  }
}


/*
void setOrientation ( Qt::Orientation )
*/
HB_FUNC( QABSTRACTSLIDER_SETORIENTATION )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setOrientation (  (Qt::Orientation) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setValue ( int )
*/
HB_FUNC( QABSTRACTSLIDER_SETVALUE )
{
  QAbstractSlider * obj = (QAbstractSlider *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setValue ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





