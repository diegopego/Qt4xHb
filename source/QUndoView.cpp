/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QUndoView>

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
QUndoView ( QWidget * parent = 0 )
*/
HB_FUNC( QUNDOVIEW_NEW1 )
{
  QUndoView * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QUndoView ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QUndoView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QUndoView ( QUndoStack * stack, QWidget * parent = 0 )
*/
HB_FUNC( QUNDOVIEW_NEW2 )
{
  QUndoView * o = NULL;
  QUndoStack * par1 = (QUndoStack *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QUndoView ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QUndoView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QUndoView ( QUndoGroup * group, QWidget * parent = 0 )
*/
HB_FUNC( QUNDOVIEW_NEW3 )
{
  QUndoView * o = NULL;
  QUndoGroup * par1 = (QUndoGroup *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QUndoView ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QUndoView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QUndoView ( QWidget * parent = 0 )
//[2]QUndoView ( QUndoStack * stack, QWidget * parent = 0 )
//[3]QUndoView ( QUndoGroup * group, QWidget * parent = 0 )

HB_FUNC( QUNDOVIEW_NEW )
{
  if( ISBETWEEN(0,1) && (ISQWIDGET(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QUNDOVIEW_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQUNDOSTACK(1) && (ISQWIDGET(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QUNDOVIEW_NEW2 );
  }
  else if( ISBETWEEN(1,2) && ISQUNDOGROUP(1) && (ISQWIDGET(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QUNDOVIEW_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QUNDOVIEW_DELETE )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QIcon cleanIcon () const
*/
HB_FUNC( QUNDOVIEW_CLEANICON )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIcon * ptr = new QIcon( obj->cleanIcon (  ) );
    _qt4xhb_createReturnClass ( ptr, "QICON", true );  }
}


/*
QString emptyLabel () const
*/
HB_FUNC( QUNDOVIEW_EMPTYLABEL )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->emptyLabel (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QUndoGroup * group () const
*/
HB_FUNC( QUNDOVIEW_GROUP )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUndoGroup * ptr = obj->group (  );
    _qt4xhb_createReturnClass ( ptr, "QUNDOGROUP" );  }
}


/*
void setCleanIcon ( const QIcon & icon )
*/
HB_FUNC( QUNDOVIEW_SETCLEANICON )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIcon par1 = ISOBJECT(1)? *(QIcon *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QIcon(hb_parc(1));
    obj->setCleanIcon ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setEmptyLabel ( const QString & label )
*/
HB_FUNC( QUNDOVIEW_SETEMPTYLABEL )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setEmptyLabel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QUndoStack * stack () const
*/
HB_FUNC( QUNDOVIEW_STACK )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUndoStack * ptr = obj->stack (  );
    _qt4xhb_createReturnClass ( ptr, "QUNDOSTACK" );  }
}


/*
void setGroup ( QUndoGroup * group )
*/
HB_FUNC( QUNDOVIEW_SETGROUP )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUndoGroup * par1 = (QUndoGroup *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGroup ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStack ( QUndoStack * stack )
*/
HB_FUNC( QUNDOVIEW_SETSTACK )
{
  QUndoView * obj = (QUndoView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUndoStack * par1 = (QUndoStack *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setStack ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



