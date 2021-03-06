/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QState>

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

#include <QVariant>

/*
QState ( QState * parent = 0 )
*/
HB_FUNC( QSTATE_NEW1 )
{
  QState * o = NULL;
  QState * par1 = ISNIL(1)? 0 : (QState *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QState ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QState *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QState ( ChildMode childMode, QState * parent = 0 )
*/
HB_FUNC( QSTATE_NEW2 )
{
  QState * o = NULL;
  int par1 = hb_parni(1);
  QState * par2 = ISNIL(2)? 0 : (QState *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QState (  (QState::ChildMode) par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QState *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QState ( QState * parent = 0 )
//[2]QState ( ChildMode childMode, QState * parent = 0 )

HB_FUNC( QSTATE_NEW )
{
  if( ISBETWEEN(0,1) && (ISQSTATE(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QSTATE_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISQSTATE(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QSTATE_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSTATE_DELETE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addTransition ( QAbstractTransition * transition )
*/
HB_FUNC( QSTATE_ADDTRANSITION1 )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractTransition * par1 = (QAbstractTransition *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addTransition ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QSignalTransition * addTransition ( QObject * sender, const char * signal, QAbstractState * target )
*/
HB_FUNC( QSTATE_ADDTRANSITION2 )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = hb_parc(2);
    QAbstractState * par3 = (QAbstractState *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QSignalTransition * ptr = obj->addTransition ( par1,  (const char *) par2, par3 );
    _qt4xhb_createReturnClass ( ptr, "QSIGNALTRANSITION" );  }
}


/*
QAbstractTransition * addTransition ( QAbstractState * target )
*/
HB_FUNC( QSTATE_ADDTRANSITION3 )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractState * par1 = (QAbstractState *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QAbstractTransition * ptr = obj->addTransition ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTTRANSITION" );  }
}


//[1]void addTransition ( QAbstractTransition * transition )
//[2]QSignalTransition * addTransition ( QObject * sender, const char * signal, QAbstractState * target )
//[3]QAbstractTransition * addTransition ( QAbstractState * target )

HB_FUNC( QSTATE_ADDTRANSITION )
{
  if( ISNUMPAR(1) && ISQABSTRACTTRANSITION(1) )
  {
    HB_FUNC_EXEC( QSTATE_ADDTRANSITION1 );
  }
  else if( ISNUMPAR(3) && ISQOBJECT(1) && ISCHAR(2) && ISQABSTRACTSTATE(3) )
  {
    HB_FUNC_EXEC( QSTATE_ADDTRANSITION2 );
  }
  else if( ISNUMPAR(1) && ISQABSTRACTSTATE(1) )
  {
    HB_FUNC_EXEC( QSTATE_ADDTRANSITION3 );
  }
}

/*
void assignProperty ( QObject * object, const char * name, const QVariant & value )
*/
HB_FUNC( QSTATE_ASSIGNPROPERTY )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = hb_parc(2);
    QVariant * par3 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->assignProperty ( par1,  (const char *) par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
ChildMode childMode () const
*/
HB_FUNC( QSTATE_CHILDMODE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->childMode (  );
    hb_retni( i );
  }
}


/*
QAbstractState * errorState () const
*/
HB_FUNC( QSTATE_ERRORSTATE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractState * ptr = obj->errorState (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTSTATE" );  }
}


/*
QAbstractState * initialState () const
*/
HB_FUNC( QSTATE_INITIALSTATE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractState * ptr = obj->initialState (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTSTATE" );  }
}


/*
void removeTransition ( QAbstractTransition * transition )
*/
HB_FUNC( QSTATE_REMOVETRANSITION )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractTransition * par1 = (QAbstractTransition *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeTransition ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setChildMode ( ChildMode mode )
*/
HB_FUNC( QSTATE_SETCHILDMODE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setChildMode (  (QState::ChildMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setErrorState ( QAbstractState * state )
*/
HB_FUNC( QSTATE_SETERRORSTATE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractState * par1 = (QAbstractState *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setErrorState ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInitialState ( QAbstractState * state )
*/
HB_FUNC( QSTATE_SETINITIALSTATE )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractState * par1 = (QAbstractState *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setInitialState ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QList<QAbstractTransition *> transitions () const
*/
HB_FUNC( QSTATE_TRANSITIONS )
{
  QState * obj = (QState *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QAbstractTransition *> list = obj->transitions (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QABSTRACTTRANSITION" );
    #else
    pDynSym = hb_dynsymFindName( "QABSTRACTTRANSITION" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QAbstractTransition *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}





