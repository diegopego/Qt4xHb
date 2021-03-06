/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QListView>

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
QListView ( QWidget * parent = 0 )
*/
HB_FUNC( QLISTVIEW_NEW )
{
  QListView * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QListView ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QListView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QLISTVIEW_DELETE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int batchSize () const
*/
HB_FUNC( QLISTVIEW_BATCHSIZE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->batchSize (  );
    hb_retni( i );
  }
}


/*
void clearPropertyFlags ()
*/
HB_FUNC( QLISTVIEW_CLEARPROPERTYFLAGS )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearPropertyFlags (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Flow flow () const
*/
HB_FUNC( QLISTVIEW_FLOW )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->flow (  );
    hb_retni( i );
  }
}


/*
QSize gridSize () const
*/
HB_FUNC( QLISTVIEW_GRIDSIZE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->gridSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
bool isRowHidden ( int row ) const
*/
HB_FUNC( QLISTVIEW_ISROWHIDDEN )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->isRowHidden ( par1 );
    hb_retl( b );
  }
}


/*
bool isSelectionRectVisible () const
*/
HB_FUNC( QLISTVIEW_ISSELECTIONRECTVISIBLE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSelectionRectVisible (  );
    hb_retl( b );
  }
}


/*
bool isWrapping () const
*/
HB_FUNC( QLISTVIEW_ISWRAPPING )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isWrapping (  );
    hb_retl( b );
  }
}


/*
LayoutMode layoutMode () const
*/
HB_FUNC( QLISTVIEW_LAYOUTMODE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->layoutMode (  );
    hb_retni( i );
  }
}


/*
int modelColumn () const
*/
HB_FUNC( QLISTVIEW_MODELCOLUMN )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->modelColumn (  );
    hb_retni( i );
  }
}


/*
Movement movement () const
*/
HB_FUNC( QLISTVIEW_MOVEMENT )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->movement (  );
    hb_retni( i );
  }
}


/*
ResizeMode resizeMode () const
*/
HB_FUNC( QLISTVIEW_RESIZEMODE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->resizeMode (  );
    hb_retni( i );
  }
}


/*
void setBatchSize ( int batchSize )
*/
HB_FUNC( QLISTVIEW_SETBATCHSIZE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setBatchSize ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFlow ( Flow flow )
*/
HB_FUNC( QLISTVIEW_SETFLOW )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFlow (  (QListView::Flow) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGridSize ( const QSize & size )
*/
HB_FUNC( QLISTVIEW_SETGRIDSIZE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGridSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLayoutMode ( LayoutMode mode )
*/
HB_FUNC( QLISTVIEW_SETLAYOUTMODE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setLayoutMode (  (QListView::LayoutMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setModelColumn ( int column )
*/
HB_FUNC( QLISTVIEW_SETMODELCOLUMN )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setModelColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMovement ( Movement movement )
*/
HB_FUNC( QLISTVIEW_SETMOVEMENT )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMovement (  (QListView::Movement) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setResizeMode ( ResizeMode mode )
*/
HB_FUNC( QLISTVIEW_SETRESIZEMODE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setResizeMode (  (QListView::ResizeMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRowHidden ( int row, bool hide )
*/
HB_FUNC( QLISTVIEW_SETROWHIDDEN )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = hb_parl(2);
    obj->setRowHidden ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSelectionRectVisible ( bool show )
*/
HB_FUNC( QLISTVIEW_SETSELECTIONRECTVISIBLE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSelectionRectVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSpacing ( int space )
*/
HB_FUNC( QLISTVIEW_SETSPACING )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUniformItemSizes ( bool enable )
*/
HB_FUNC( QLISTVIEW_SETUNIFORMITEMSIZES )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setUniformItemSizes ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setViewMode ( ViewMode mode )
*/
HB_FUNC( QLISTVIEW_SETVIEWMODE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setViewMode (  (QListView::ViewMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWordWrap ( bool on )
*/
HB_FUNC( QLISTVIEW_SETWORDWRAP )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWordWrap ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWrapping ( bool enable )
*/
HB_FUNC( QLISTVIEW_SETWRAPPING )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWrapping ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int spacing () const
*/
HB_FUNC( QLISTVIEW_SPACING )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->spacing (  );
    hb_retni( i );
  }
}


/*
bool uniformItemSizes () const
*/
HB_FUNC( QLISTVIEW_UNIFORMITEMSIZES )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->uniformItemSizes (  );
    hb_retl( b );
  }
}


/*
ViewMode viewMode () const
*/
HB_FUNC( QLISTVIEW_VIEWMODE )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->viewMode (  );
    hb_retni( i );
  }
}


/*
bool wordWrap () const
*/
HB_FUNC( QLISTVIEW_WORDWRAP )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->wordWrap (  );
    hb_retl( b );
  }
}


/*
virtual QModelIndex indexAt ( const QPoint & p ) const
*/
HB_FUNC( QLISTVIEW_INDEXAT )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->indexAt ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
virtual void scrollTo ( const QModelIndex & index, ScrollHint hint = EnsureVisible )
*/
HB_FUNC( QLISTVIEW_SCROLLTO )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) QListView::EnsureVisible : hb_parni(2);
    obj->scrollTo ( *par1,  (QListView::ScrollHint) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QRect visualRect ( const QModelIndex & index ) const
*/
HB_FUNC( QLISTVIEW_VISUALRECT )
{
  QListView * obj = (QListView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->visualRect ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}




