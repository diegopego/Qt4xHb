/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QKeyEventTransition>

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
QKeyEventTransition ( QState * sourceState = 0 )
*/
HB_FUNC( QKEYEVENTTRANSITION_NEW1 )
{
  QKeyEventTransition * o = NULL;
  QState * par1 = ISNIL(1)? 0 : (QState *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QKeyEventTransition ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QKeyEventTransition *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QKeyEventTransition ( QObject * object, QEvent::Type type, int key, QState * sourceState = 0 )
*/
HB_FUNC( QKEYEVENTTRANSITION_NEW2 )
{
  QKeyEventTransition * o = NULL;
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  QState * par4 = ISNIL(4)? 0 : (QState *) hb_itemGetPtr( hb_objSendMsg( hb_param(4, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QKeyEventTransition ( par1,  (QEvent::Type) par2, par3, par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QKeyEventTransition *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QKeyEventTransition ( QState * sourceState = 0 )
//[2]QKeyEventTransition ( QObject * object, QEvent::Type type, int key, QState * sourceState = 0 )

HB_FUNC( QKEYEVENTTRANSITION_NEW )
{
  if( ISBETWEEN(0,1) && (ISQSTATE(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QKEYEVENTTRANSITION_NEW1 );
  }
  else if( ISBETWEEN(3,4) && ISQOBJECT(1) && ISNUM(2) && ISNUM(3) && (ISQSTATE(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QKEYEVENTTRANSITION_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QKEYEVENTTRANSITION_DELETE )
{
  QKeyEventTransition * obj = (QKeyEventTransition *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int key () const
*/
HB_FUNC( QKEYEVENTTRANSITION_KEY )
{
  QKeyEventTransition * obj = (QKeyEventTransition *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->key (  );
    hb_retni( i );
  }
}


/*
Qt::KeyboardModifiers modifierMask () const
*/
HB_FUNC( QKEYEVENTTRANSITION_MODIFIERMASK )
{
  QKeyEventTransition * obj = (QKeyEventTransition *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->modifierMask (  );
    hb_retni( i );
  }
}


/*
void setKey ( int key )
*/
HB_FUNC( QKEYEVENTTRANSITION_SETKEY )
{
  QKeyEventTransition * obj = (QKeyEventTransition *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setKey ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setModifierMask ( Qt::KeyboardModifiers modifierMask )
*/
HB_FUNC( QKEYEVENTTRANSITION_SETMODIFIERMASK )
{
  QKeyEventTransition * obj = (QKeyEventTransition *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setModifierMask (  (Qt::KeyboardModifiers) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




