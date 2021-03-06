/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTreeWidget>

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
QTreeWidget ( QWidget * parent = 0 )
*/
HB_FUNC( QTREEWIDGET_NEW )
{
  QTreeWidget * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTreeWidget ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTreeWidget *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTREEWIDGET_DELETE )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addTopLevelItem ( QTreeWidgetItem * item )
*/
HB_FUNC( QTREEWIDGET_ADDTOPLEVELITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addTopLevelItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addTopLevelItems ( const QList<QTreeWidgetItem *> & items )
*/
HB_FUNC( QTREEWIDGET_ADDTOPLEVELITEMS )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QList<QTreeWidgetItem *> par1;
PHB_ITEM aList1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aList1);
for (i1=0;i1<nLen1;i1++)
{
par1 << (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList1, i1+1 ), "POINTER", 0 ) );}
    obj->addTopLevelItems ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void closePersistentEditor ( QTreeWidgetItem * item, int column = 0 )
*/
HB_FUNC( QTREEWIDGET_CLOSEPERSISTENTEDITOR )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    obj->closePersistentEditor ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int columnCount () const
*/
HB_FUNC( QTREEWIDGET_COLUMNCOUNT )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->columnCount (  );
    hb_retni( i );
  }
}


/*
int currentColumn () const
*/
HB_FUNC( QTREEWIDGET_CURRENTCOLUMN )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentColumn (  );
    hb_retni( i );
  }
}


/*
QTreeWidgetItem * currentItem () const
*/
HB_FUNC( QTREEWIDGET_CURRENTITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * ptr = obj->currentItem (  );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
void editItem ( QTreeWidgetItem * item, int column = 0 )
*/
HB_FUNC( QTREEWIDGET_EDITITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    obj->editItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QList<QTreeWidgetItem *> findItems ( const QString & text, Qt::MatchFlags flags, int column = 0 ) const
*/
HB_FUNC( QTREEWIDGET_FINDITEMS )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    int par3 = ISNIL(3)? 0 : hb_parni(3);
    QList<QTreeWidgetItem *> list = obj->findItems ( par1,  (Qt::MatchFlags) par2, par3 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QTREEWIDGETITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QTREEWIDGETITEM" );
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
        hb_itemPutPtr( pItem, (QTreeWidgetItem *) list[i] );
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
QTreeWidgetItem *  headerItem () const
*/
HB_FUNC( QTREEWIDGET_HEADERITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * ptr = obj->headerItem (  );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
int indexOfTopLevelItem ( QTreeWidgetItem * item ) const
*/
HB_FUNC( QTREEWIDGET_INDEXOFTOPLEVELITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->indexOfTopLevelItem ( par1 );
    hb_retni( i );
  }
}


/*
void insertTopLevelItem ( int index, QTreeWidgetItem * item )
*/
HB_FUNC( QTREEWIDGET_INSERTTOPLEVELITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTreeWidgetItem * par2 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->insertTopLevelItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void insertTopLevelItems ( int index, const QList<QTreeWidgetItem *> & items )
*/
HB_FUNC( QTREEWIDGET_INSERTTOPLEVELITEMS )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
QList<QTreeWidgetItem *> par2;
PHB_ITEM aList2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aList2);
for (i2=0;i2<nLen2;i2++)
{
par2 << (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList2, i2+1 ), "POINTER", 0 ) );}
    obj->insertTopLevelItems ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QTreeWidgetItem * invisibleRootItem () const
*/
HB_FUNC( QTREEWIDGET_INVISIBLEROOTITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * ptr = obj->invisibleRootItem (  );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
bool isFirstItemColumnSpanned ( const QTreeWidgetItem * item ) const
*/
HB_FUNC( QTREEWIDGET_ISFIRSTITEMCOLUMNSPANNED )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isFirstItemColumnSpanned ( par1 );
    hb_retl( b );
  }
}


/*
QTreeWidgetItem * itemAbove ( const QTreeWidgetItem * item ) const
*/
HB_FUNC( QTREEWIDGET_ITEMABOVE )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTreeWidgetItem * ptr = obj->itemAbove ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
QTreeWidgetItem * itemAt ( const QPoint & p ) const
*/
HB_FUNC( QTREEWIDGET_ITEMAT1 )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTreeWidgetItem * ptr = obj->itemAt ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
QTreeWidgetItem * itemAt ( int x, int y ) const
*/
HB_FUNC( QTREEWIDGET_ITEMAT2 )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QTreeWidgetItem * ptr = obj->itemAt ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


//[1]QTreeWidgetItem * itemAt ( const QPoint & p ) const
//[2]QTreeWidgetItem * itemAt ( int x, int y ) const

HB_FUNC( QTREEWIDGET_ITEMAT )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QTREEWIDGET_ITEMAT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTREEWIDGET_ITEMAT2 );
  }
}

/*
QTreeWidgetItem *  itemBelow ( const QTreeWidgetItem * item ) const
*/
HB_FUNC( QTREEWIDGET_ITEMBELOW )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTreeWidgetItem * ptr = obj->itemBelow ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
QWidget * itemWidget ( QTreeWidgetItem * item, int column ) const
*/
HB_FUNC( QTREEWIDGET_ITEMWIDGET )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    QWidget * ptr = obj->itemWidget ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
void openPersistentEditor ( QTreeWidgetItem * item, int column = 0 )
*/
HB_FUNC( QTREEWIDGET_OPENPERSISTENTEDITOR )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    obj->openPersistentEditor ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeItemWidget ( QTreeWidgetItem * item, int column )
*/
HB_FUNC( QTREEWIDGET_REMOVEITEMWIDGET )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    obj->removeItemWidget ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QList<QTreeWidgetItem *> selectedItems () const
*/
HB_FUNC( QTREEWIDGET_SELECTEDITEMS )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QTreeWidgetItem *> list = obj->selectedItems (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QTREEWIDGETITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QTREEWIDGETITEM" );
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
        hb_itemPutPtr( pItem, (QTreeWidgetItem *) list[i] );
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
void setColumnCount ( int columns )
*/
HB_FUNC( QTREEWIDGET_SETCOLUMNCOUNT )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setColumnCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentItem ( QTreeWidgetItem * item )
*/
HB_FUNC( QTREEWIDGET_SETCURRENTITEM1 )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCurrentItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentItem ( QTreeWidgetItem * item, int column )
*/
HB_FUNC( QTREEWIDGET_SETCURRENTITEM2 )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    obj->setCurrentItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentItem ( QTreeWidgetItem * item, int column, QItemSelectionModel::SelectionFlags command )
*/
HB_FUNC( QTREEWIDGET_SETCURRENTITEM3 )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    obj->setCurrentItem ( par1, par2,  (QItemSelectionModel::SelectionFlags) par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCurrentItem ( QTreeWidgetItem * item )
//[2]void setCurrentItem ( QTreeWidgetItem * item, int column )
//[3]void setCurrentItem ( QTreeWidgetItem * item, int column, QItemSelectionModel::SelectionFlags command )

HB_FUNC( QTREEWIDGET_SETCURRENTITEM )
{
  if( ISNUMPAR(1) && ISQTREEWIDGETITEM(1) )
  {
    HB_FUNC_EXEC( QTREEWIDGET_SETCURRENTITEM1 );
  }
  else if( ISNUMPAR(2) && ISQTREEWIDGETITEM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTREEWIDGET_SETCURRENTITEM2 );
  }
  else if( ISNUMPAR(3) && ISQTREEWIDGETITEM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QTREEWIDGET_SETCURRENTITEM3 );
  }
}

/*
void setFirstItemColumnSpanned ( const QTreeWidgetItem * item, bool span )
*/
HB_FUNC( QTREEWIDGET_SETFIRSTITEMCOLUMNSPANNED )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2 = hb_parl(2);
    obj->setFirstItemColumnSpanned ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHeaderItem ( QTreeWidgetItem * item )
*/
HB_FUNC( QTREEWIDGET_SETHEADERITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setHeaderItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHeaderLabel ( const QString & label )
*/
HB_FUNC( QTREEWIDGET_SETHEADERLABEL )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setHeaderLabel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHeaderLabels ( const QStringList & labels )
*/
HB_FUNC( QTREEWIDGET_SETHEADERLABELS )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
    obj->setHeaderLabels ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemWidget ( QTreeWidgetItem * item, int column, QWidget * widget )
*/
HB_FUNC( QTREEWIDGET_SETITEMWIDGET )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTreeWidgetItem * par1 = (QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    QWidget * par3 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItemWidget ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int sortColumn () const
*/
HB_FUNC( QTREEWIDGET_SORTCOLUMN )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->sortColumn (  );
    hb_retni( i );
  }
}


/*
void sortItems ( int column, Qt::SortOrder order )
*/
HB_FUNC( QTREEWIDGET_SORTITEMS )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->sortItems ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QTreeWidgetItem *  takeTopLevelItem ( int index )
*/
HB_FUNC( QTREEWIDGET_TAKETOPLEVELITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTreeWidgetItem * ptr = obj->takeTopLevelItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
QTreeWidgetItem *  topLevelItem ( int index ) const
*/
HB_FUNC( QTREEWIDGET_TOPLEVELITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTreeWidgetItem * ptr = obj->topLevelItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTREEWIDGETITEM" );  }
}


/*
int topLevelItemCount () const
*/
HB_FUNC( QTREEWIDGET_TOPLEVELITEMCOUNT )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->topLevelItemCount (  );
    hb_retni( i );
  }
}


/*
QRect visualItemRect ( const QTreeWidgetItem * item ) const
*/
HB_FUNC( QTREEWIDGET_VISUALITEMRECT )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->visualItemRect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}



/*
virtual void setSelectionModel ( QItemSelectionModel * selectionModel )
*/
HB_FUNC( QTREEWIDGET_SETSELECTIONMODEL )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemSelectionModel * par1 = (QItemSelectionModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSelectionModel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clear ()
*/
HB_FUNC( QTREEWIDGET_CLEAR )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void collapseItem ( const QTreeWidgetItem * item )
*/
HB_FUNC( QTREEWIDGET_COLLAPSEITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->collapseItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void expandItem ( const QTreeWidgetItem * item )
*/
HB_FUNC( QTREEWIDGET_EXPANDITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->expandItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void scrollToItem ( const QTreeWidgetItem * item, QAbstractItemView::ScrollHint hint = EnsureVisible )
*/
HB_FUNC( QTREEWIDGET_SCROLLTOITEM )
{
  QTreeWidget * obj = (QTreeWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTreeWidgetItem * par1 = (const QTreeWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) QAbstractItemView::EnsureVisible : hb_parni(2);
    obj->scrollToItem ( par1,  (QAbstractItemView::ScrollHint) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}





