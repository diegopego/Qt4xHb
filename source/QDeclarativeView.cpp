/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDeclarativeView>

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

#include <QDeclarativeError>

/*
QDeclarativeView ( QWidget * parent = 0 )
*/
HB_FUNC( QDECLARATIVEVIEW_NEW1 )
{
  QDeclarativeView * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QDeclarativeView ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDeclarativeView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QDeclarativeView ( const QUrl & source, QWidget * parent = 0 )
*/
HB_FUNC( QDECLARATIVEVIEW_NEW2 )
{
  QDeclarativeView * o = NULL;
  QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QDeclarativeView ( *par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDeclarativeView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QDeclarativeView ( QWidget * parent = 0 )
//[2]QDeclarativeView ( const QUrl & source, QWidget * parent = 0 )

HB_FUNC( QDECLARATIVEVIEW_NEW )
{
  if( ISBETWEEN(0,1) && (ISQWIDGET(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QDECLARATIVEVIEW_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQURL(1) && (ISQWIDGET(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QDECLARATIVEVIEW_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QDECLARATIVEVIEW_DELETE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QDeclarativeEngine * engine () const
*/
HB_FUNC( QDECLARATIVEVIEW_ENGINE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDeclarativeEngine * ptr = obj->engine (  );
    _qt4xhb_createReturnClass ( ptr, "QDECLARATIVEENGINE" );  }
}


/*
QList<QDeclarativeError> errors () const
*/
HB_FUNC( QDECLARATIVEVIEW_ERRORS )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QDeclarativeError> list = obj->errors (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QDECLARATIVEERROR" );
    #else
    pDynSym = hb_dynsymFindName( "QDECLARATIVEERROR" );
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
        hb_itemPutPtr( pItem, (QDeclarativeError *) new QDeclarativeError ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QSize initialSize () const
*/
HB_FUNC( QDECLARATIVEVIEW_INITIALSIZE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->initialSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
ResizeMode resizeMode () const
*/
HB_FUNC( QDECLARATIVEVIEW_RESIZEMODE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->resizeMode (  );
    hb_retni( i );
  }
}


/*
QDeclarativeContext * rootContext () const
*/
HB_FUNC( QDECLARATIVEVIEW_ROOTCONTEXT )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDeclarativeContext * ptr = obj->rootContext (  );
    _qt4xhb_createReturnClass ( ptr, "QDECLARATIVECONTEXT" );  }
}


/*
QGraphicsObject * rootObject () const
*/
HB_FUNC( QDECLARATIVEVIEW_ROOTOBJECT )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsObject * ptr = obj->rootObject (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSOBJECT" );  }
}


/*
void setResizeMode ( ResizeMode )
*/
HB_FUNC( QDECLARATIVEVIEW_SETRESIZEMODE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setResizeMode (  (QDeclarativeView::ResizeMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSource ( const QUrl & url )
*/
HB_FUNC( QDECLARATIVEVIEW_SETSOURCE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSource ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QUrl source () const
*/
HB_FUNC( QDECLARATIVEVIEW_SOURCE )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * ptr = new QUrl( obj->source (  ) );
    _qt4xhb_createReturnClass ( ptr, "QURL", true );  }
}


/*
Status status () const
*/
HB_FUNC( QDECLARATIVEVIEW_STATUS )
{
  QDeclarativeView * obj = (QDeclarativeView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->status (  );
    hb_retni( i );
  }
}




