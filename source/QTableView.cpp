/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTableView>

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
QTableView ( QWidget * parent = 0 )
*/
HB_FUNC( QTABLEVIEW_NEW )
{
  QTableView * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTableView ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTableView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTABLEVIEW_DELETE )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void clearSpans ()
*/
HB_FUNC( QTABLEVIEW_CLEARSPANS )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearSpans (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int columnAt ( int x ) const
*/
HB_FUNC( QTABLEVIEW_COLUMNAT )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->columnAt ( par1 );
    hb_retni( i );
  }
}


/*
int columnSpan ( int row, int column ) const
*/
HB_FUNC( QTABLEVIEW_COLUMNSPAN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int i = obj->columnSpan ( par1, par2 );
    hb_retni( i );
  }
}


/*
int columnViewportPosition ( int column ) const
*/
HB_FUNC( QTABLEVIEW_COLUMNVIEWPORTPOSITION )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->columnViewportPosition ( par1 );
    hb_retni( i );
  }
}


/*
int columnWidth ( int column ) const
*/
HB_FUNC( QTABLEVIEW_COLUMNWIDTH )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->columnWidth ( par1 );
    hb_retni( i );
  }
}


/*
Qt::PenStyle gridStyle () const
*/
HB_FUNC( QTABLEVIEW_GRIDSTYLE )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->gridStyle (  );
    hb_retni( i );
  }
}


/*
QHeaderView * horizontalHeader () const
*/
HB_FUNC( QTABLEVIEW_HORIZONTALHEADER )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHeaderView * ptr = obj->horizontalHeader (  );
    _qt4xhb_createReturnClass ( ptr, "QHEADERVIEW" );  }
}


/*
bool isColumnHidden ( int column ) const
*/
HB_FUNC( QTABLEVIEW_ISCOLUMNHIDDEN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->isColumnHidden ( par1 );
    hb_retl( b );
  }
}


/*
bool isCornerButtonEnabled () const
*/
HB_FUNC( QTABLEVIEW_ISCORNERBUTTONENABLED )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isCornerButtonEnabled (  );
    hb_retl( b );
  }
}


/*
bool isRowHidden ( int row ) const
*/
HB_FUNC( QTABLEVIEW_ISROWHIDDEN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->isRowHidden ( par1 );
    hb_retl( b );
  }
}


/*
bool isSortingEnabled () const
*/
HB_FUNC( QTABLEVIEW_ISSORTINGENABLED )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSortingEnabled (  );
    hb_retl( b );
  }
}


/*
int rowAt ( int y ) const
*/
HB_FUNC( QTABLEVIEW_ROWAT )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->rowAt ( par1 );
    hb_retni( i );
  }
}


/*
int rowHeight ( int row ) const
*/
HB_FUNC( QTABLEVIEW_ROWHEIGHT )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->rowHeight ( par1 );
    hb_retni( i );
  }
}


/*
int rowSpan ( int row, int column ) const
*/
HB_FUNC( QTABLEVIEW_ROWSPAN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int i = obj->rowSpan ( par1, par2 );
    hb_retni( i );
  }
}


/*
int rowViewportPosition ( int row ) const
*/
HB_FUNC( QTABLEVIEW_ROWVIEWPORTPOSITION )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->rowViewportPosition ( par1 );
    hb_retni( i );
  }
}


/*
void setColumnHidden ( int column, bool hide )
*/
HB_FUNC( QTABLEVIEW_SETCOLUMNHIDDEN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = hb_parl(2);
    obj->setColumnHidden ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setColumnWidth ( int column, int width )
*/
HB_FUNC( QTABLEVIEW_SETCOLUMNWIDTH )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setColumnWidth ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCornerButtonEnabled ( bool enable )
*/
HB_FUNC( QTABLEVIEW_SETCORNERBUTTONENABLED )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setCornerButtonEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGridStyle ( Qt::PenStyle style )
*/
HB_FUNC( QTABLEVIEW_SETGRIDSTYLE )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setGridStyle (  (Qt::PenStyle) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHorizontalHeader ( QHeaderView * header )
*/
HB_FUNC( QTABLEVIEW_SETHORIZONTALHEADER )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHeaderView * par1 = (QHeaderView *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setHorizontalHeader ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRowHeight ( int row, int height )
*/
HB_FUNC( QTABLEVIEW_SETROWHEIGHT )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setRowHeight ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRowHidden ( int row, bool hide )
*/
HB_FUNC( QTABLEVIEW_SETROWHIDDEN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = hb_parl(2);
    obj->setRowHidden ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSortingEnabled ( bool enable )
*/
HB_FUNC( QTABLEVIEW_SETSORTINGENABLED )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSortingEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSpan ( int row, int column, int rowSpanCount, int columnSpanCount )
*/
HB_FUNC( QTABLEVIEW_SETSPAN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->setSpan ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalHeader ( QHeaderView * header )
*/
HB_FUNC( QTABLEVIEW_SETVERTICALHEADER )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHeaderView * par1 = (QHeaderView *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setVerticalHeader ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWordWrap ( bool on )
*/
HB_FUNC( QTABLEVIEW_SETWORDWRAP )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWordWrap ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool showGrid () const
*/
HB_FUNC( QTABLEVIEW_SHOWGRID )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->showGrid (  );
    hb_retl( b );
  }
}


/*
void sortByColumn ( int column, Qt::SortOrder order )
*/
HB_FUNC( QTABLEVIEW_SORTBYCOLUMN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->sortByColumn ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QHeaderView * verticalHeader () const
*/
HB_FUNC( QTABLEVIEW_VERTICALHEADER )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QHeaderView * ptr = obj->verticalHeader (  );
    _qt4xhb_createReturnClass ( ptr, "QHEADERVIEW" );  }
}


/*
bool wordWrap () const
*/
HB_FUNC( QTABLEVIEW_WORDWRAP )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->wordWrap (  );
    hb_retl( b );
  }
}


/*
virtual QModelIndex indexAt ( const QPoint & pos ) const
*/
HB_FUNC( QTABLEVIEW_INDEXAT )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->indexAt ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
virtual void setModel ( QAbstractItemModel * model )
*/
HB_FUNC( QTABLEVIEW_SETMODEL )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemModel * par1 = (QAbstractItemModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setModel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setRootIndex ( const QModelIndex & index )
*/
HB_FUNC( QTABLEVIEW_SETROOTINDEX )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setRootIndex ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setSelectionModel ( QItemSelectionModel * selectionModel )
*/
HB_FUNC( QTABLEVIEW_SETSELECTIONMODEL )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemSelectionModel * par1 = (QItemSelectionModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSelectionModel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void hideColumn ( int column )
*/
HB_FUNC( QTABLEVIEW_HIDECOLUMN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->hideColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void hideRow ( int row )
*/
HB_FUNC( QTABLEVIEW_HIDEROW )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->hideRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resizeColumnToContents ( int column )
*/
HB_FUNC( QTABLEVIEW_RESIZECOLUMNTOCONTENTS )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->resizeColumnToContents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resizeColumnsToContents ()
*/
HB_FUNC( QTABLEVIEW_RESIZECOLUMNSTOCONTENTS )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->resizeColumnsToContents (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resizeRowToContents ( int row )
*/
HB_FUNC( QTABLEVIEW_RESIZEROWTOCONTENTS )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->resizeRowToContents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resizeRowsToContents ()
*/
HB_FUNC( QTABLEVIEW_RESIZEROWSTOCONTENTS )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->resizeRowsToContents (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void selectColumn ( int column )
*/
HB_FUNC( QTABLEVIEW_SELECTCOLUMN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->selectColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void selectRow ( int row )
*/
HB_FUNC( QTABLEVIEW_SELECTROW )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->selectRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setShowGrid ( bool show )
*/
HB_FUNC( QTABLEVIEW_SETSHOWGRID )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setShowGrid ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showColumn ( int column )
*/
HB_FUNC( QTABLEVIEW_SHOWCOLUMN )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->showColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showRow ( int row )
*/
HB_FUNC( QTABLEVIEW_SHOWROW )
{
  QTableView * obj = (QTableView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->showRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



