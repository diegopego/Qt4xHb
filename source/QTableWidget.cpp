/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTableWidget>

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
QTableWidget ( QWidget * parent = 0 )
*/
HB_FUNC( QTABLEWIDGET_NEW1 )
{
  QTableWidget * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTableWidget ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTableWidget *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QTableWidget ( int rows, int columns, QWidget * parent = 0 )
*/
HB_FUNC( QTABLEWIDGET_NEW2 )
{
  QTableWidget * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QWidget * par3 = ISNIL(3)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTableWidget ( par1, par2, par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTableWidget *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QTableWidget ( QWidget * parent = 0 )
//[2]QTableWidget ( int rows, int columns, QWidget * parent = 0 )

HB_FUNC( QTABLEWIDGET_NEW )
{
  if( ISBETWEEN(0,1) && (ISQWIDGET(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_NEW1 );
  }
  else if( ISBETWEEN(2,3) && ISNUM(1) && ISNUM(2) && (ISQWIDGET(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QTABLEWIDGET_DELETE )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QWidget * cellWidget ( int row, int column ) const
*/
HB_FUNC( QTABLEWIDGET_CELLWIDGET )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QWidget * ptr = obj->cellWidget ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
void closePersistentEditor ( QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_CLOSEPERSISTENTEDITOR )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTableWidgetItem * par1 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->closePersistentEditor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int column ( const QTableWidgetItem * item ) const
*/
HB_FUNC( QTABLEWIDGET_COLUMN )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTableWidgetItem * par1 = (const QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->column ( par1 );
    hb_retni( i );
  }
}


/*
int columnCount () const
*/
HB_FUNC( QTABLEWIDGET_COLUMNCOUNT )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->columnCount (  );
    hb_retni( i );
  }
}


/*
int currentColumn () const
*/
HB_FUNC( QTABLEWIDGET_CURRENTCOLUMN )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentColumn (  );
    hb_retni( i );
  }
}


/*
QTableWidgetItem * currentItem () const
*/
HB_FUNC( QTABLEWIDGET_CURRENTITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTableWidgetItem * ptr = obj->currentItem (  );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
int currentRow () const
*/
HB_FUNC( QTABLEWIDGET_CURRENTROW )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentRow (  );
    hb_retni( i );
  }
}


/*
void editItem ( QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_EDITITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTableWidgetItem * par1 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->editItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QList<QTableWidgetItem *> findItems ( const QString & text, Qt::MatchFlags flags ) const
*/
HB_FUNC( QTABLEWIDGET_FINDITEMS )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QList<QTableWidgetItem *> list = obj->findItems ( par1,  (Qt::MatchFlags) par2 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QTABLEWIDGETITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QTABLEWIDGETITEM" );
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
        hb_itemPutPtr( pItem, (QTableWidgetItem *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QTableWidgetItem * horizontalHeaderItem ( int column ) const
*/
HB_FUNC( QTABLEWIDGET_HORIZONTALHEADERITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTableWidgetItem * ptr = obj->horizontalHeaderItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
QTableWidgetItem * item ( int row, int column ) const
*/
HB_FUNC( QTABLEWIDGET_ITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QTableWidgetItem * ptr = obj->item ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
QTableWidgetItem * itemAt ( const QPoint & point ) const
*/
HB_FUNC( QTABLEWIDGET_ITEMAT1 )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTableWidgetItem * ptr = obj->itemAt ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
QTableWidgetItem * itemAt ( int ax, int ay ) const
*/
HB_FUNC( QTABLEWIDGET_ITEMAT2 )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QTableWidgetItem * ptr = obj->itemAt ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


//[1]QTableWidgetItem * itemAt ( const QPoint & point ) const
//[2]QTableWidgetItem * itemAt ( int ax, int ay ) const

HB_FUNC( QTABLEWIDGET_ITEMAT )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_ITEMAT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_ITEMAT2 );
  }
}


/*
void openPersistentEditor ( QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_OPENPERSISTENTEDITOR )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTableWidgetItem * par1 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->openPersistentEditor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeCellWidget ( int row, int column )
*/
HB_FUNC( QTABLEWIDGET_REMOVECELLWIDGET )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->removeCellWidget ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int row ( const QTableWidgetItem * item ) const
*/
HB_FUNC( QTABLEWIDGET_ROW )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTableWidgetItem * par1 = (const QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->row ( par1 );
    hb_retni( i );
  }
}


/*
int rowCount () const
*/
HB_FUNC( QTABLEWIDGET_ROWCOUNT )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->rowCount (  );
    hb_retni( i );
  }
}


/*
QList<QTableWidgetItem *> selectedItems ()
*/
HB_FUNC( QTABLEWIDGET_SELECTEDITEMS )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QTableWidgetItem *> list = obj->selectedItems (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QTABLEWIDGETITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QTABLEWIDGETITEM" );
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
        hb_itemPutPtr( pItem, (QTableWidgetItem *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QList<QTableWidgetSelectionRange> selectedRanges () const
*/
HB_FUNC( QTABLEWIDGET_SELECTEDRANGES )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QTableWidgetSelectionRange> list = obj->selectedRanges (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QTABLEWIDGETSELECTIONRANGE" );
    #else
    pDynSym = hb_dynsymFindName( "QTABLEWIDGETSELECTIONRANGE" );
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
        hb_itemPutPtr( pItem, (QTableWidgetSelectionRange *) new QTableWidgetSelectionRange ( list[i] ) );
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
void setCellWidget ( int row, int column, QWidget * widget )
*/
HB_FUNC( QTABLEWIDGET_SETCELLWIDGET )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QWidget * par3 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCellWidget ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setColumnCount ( int columns )
*/
HB_FUNC( QTABLEWIDGET_SETCOLUMNCOUNT )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setColumnCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentCell ( int row, int column )
*/
HB_FUNC( QTABLEWIDGET_SETCURRENTCELL1 )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setCurrentCell ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentCell ( int row, int column, QItemSelectionModel::SelectionFlags command )
*/
HB_FUNC( QTABLEWIDGET_SETCURRENTCELL2 )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    obj->setCurrentCell ( par1, par2,  (QItemSelectionModel::SelectionFlags) par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCurrentCell ( int row, int column )
//[2]void setCurrentCell ( int row, int column, QItemSelectionModel::SelectionFlags command )

HB_FUNC( QTABLEWIDGET_SETCURRENTCELL )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_SETCURRENTCELL1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_SETCURRENTCELL2 );
  }
}

/*
void setCurrentItem ( QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_SETCURRENTITEM1 )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTableWidgetItem * par1 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCurrentItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentItem ( QTableWidgetItem * item, QItemSelectionModel::SelectionFlags command )
*/
HB_FUNC( QTABLEWIDGET_SETCURRENTITEM2 )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTableWidgetItem * par1 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    obj->setCurrentItem ( par1,  (QItemSelectionModel::SelectionFlags) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCurrentItem ( QTableWidgetItem * item )
//[2]void setCurrentItem ( QTableWidgetItem * item, QItemSelectionModel::SelectionFlags command )

HB_FUNC( QTABLEWIDGET_SETCURRENTITEM )
{
  if( ISNUMPAR(1) && ISQTABLEWIDGETITEM(1) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_SETCURRENTITEM1 );
  }
  else if( ISNUMPAR(2) && ISQTABLEWIDGETITEM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTABLEWIDGET_SETCURRENTITEM2 );
  }
}

/*
void setHorizontalHeaderItem ( int column, QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_SETHORIZONTALHEADERITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTableWidgetItem * par2 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setHorizontalHeaderItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHorizontalHeaderLabels ( const QStringList & labels )
*/
HB_FUNC( QTABLEWIDGET_SETHORIZONTALHEADERLABELS )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QStringList par1;
PHB_ITEM aStrings1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aStrings1);
for (i1=0;i1<nLen1;i1++)
{
QString temp = hb_arrayGetCPtr(aStrings1, i1+1);
par1 << temp;
}
    obj->setHorizontalHeaderLabels ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItem ( int row, int column, QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_SETITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QTableWidgetItem * par3 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItem ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemPrototype ( const QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_SETITEMPROTOTYPE )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTableWidgetItem * par1 = (const QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItemPrototype ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRangeSelected ( const QTableWidgetSelectionRange & range, bool select )
*/
HB_FUNC( QTABLEWIDGET_SETRANGESELECTED )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTableWidgetSelectionRange  * par1 = (const QTableWidgetSelectionRange  *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2 = hb_parl(2);
    obj->setRangeSelected ( *par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRowCount ( int rows )
*/
HB_FUNC( QTABLEWIDGET_SETROWCOUNT )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setRowCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalHeaderItem ( int row, QTableWidgetItem * item )
*/
HB_FUNC( QTABLEWIDGET_SETVERTICALHEADERITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTableWidgetItem * par2 = (QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setVerticalHeaderItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalHeaderLabels ( const QStringList & labels )
*/
HB_FUNC( QTABLEWIDGET_SETVERTICALHEADERLABELS )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QStringList par1;
PHB_ITEM aStrings1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aStrings1);
for (i1=0;i1<nLen1;i1++)
{
QString temp = hb_arrayGetCPtr(aStrings1, i1+1);
par1 << temp;
}
    obj->setVerticalHeaderLabels ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void sortItems ( int column, Qt::SortOrder order = Qt::AscendingOrder )
*/
HB_FUNC( QTABLEWIDGET_SORTITEMS )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) Qt::AscendingOrder : hb_parni(2);
    obj->sortItems ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QTableWidgetItem * takeHorizontalHeaderItem ( int column )
*/
HB_FUNC( QTABLEWIDGET_TAKEHORIZONTALHEADERITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTableWidgetItem * ptr = obj->takeHorizontalHeaderItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
QTableWidgetItem * takeItem ( int row, int column )
*/
HB_FUNC( QTABLEWIDGET_TAKEITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QTableWidgetItem * ptr = obj->takeItem ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
QTableWidgetItem * takeVerticalHeaderItem ( int row )
*/
HB_FUNC( QTABLEWIDGET_TAKEVERTICALHEADERITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTableWidgetItem * ptr = obj->takeVerticalHeaderItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
QTableWidgetItem * verticalHeaderItem ( int row ) const
*/
HB_FUNC( QTABLEWIDGET_VERTICALHEADERITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTableWidgetItem * ptr = obj->verticalHeaderItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTABLEWIDGETITEM" );  }
}


/*
int visualColumn ( int logicalColumn ) const
*/
HB_FUNC( QTABLEWIDGET_VISUALCOLUMN )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->visualColumn ( par1 );
    hb_retni( i );
  }
}


/*
QRect visualItemRect ( const QTableWidgetItem * item ) const
*/
HB_FUNC( QTABLEWIDGET_VISUALITEMRECT )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTableWidgetItem * par1 = (const QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->visualItemRect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
int visualRow ( int logicalRow ) const
*/
HB_FUNC( QTABLEWIDGET_VISUALROW )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->visualRow ( par1 );
    hb_retni( i );
  }
}


/*
void clear ()
*/
HB_FUNC( QTABLEWIDGET_CLEAR )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clearContents ()
*/
HB_FUNC( QTABLEWIDGET_CLEARCONTENTS )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearContents (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void insertColumn ( int column )
*/
HB_FUNC( QTABLEWIDGET_INSERTCOLUMN )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->insertColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void insertRow ( int row )
*/
HB_FUNC( QTABLEWIDGET_INSERTROW )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->insertRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeColumn ( int column )
*/
HB_FUNC( QTABLEWIDGET_REMOVECOLUMN )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->removeColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeRow ( int row )
*/
HB_FUNC( QTABLEWIDGET_REMOVEROW )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->removeRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void scrollToItem ( const QTableWidgetItem * item, QAbstractItemView::ScrollHint hint = EnsureVisible )
*/
HB_FUNC( QTABLEWIDGET_SCROLLTOITEM )
{
  QTableWidget * obj = (QTableWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTableWidgetItem * par1 = (const QTableWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) QAbstractItemView::EnsureVisible : hb_parni(2);
    obj->scrollToItem ( par1,  (QAbstractItemView::ScrollHint) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




