/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QListWidget>

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
QListWidget ( QWidget * parent = 0 )
*/
HB_FUNC( QLISTWIDGET_NEW )
{
  QListWidget * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QListWidget ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QListWidget *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QLISTWIDGET_DELETE )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addItem ( const QString & label )
*/
HB_FUNC( QLISTWIDGET_ADDITEM1 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->addItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addItem ( QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_ADDITEM2 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addItem ( const QString & label )
//[2]void addItem ( QListWidgetItem * item )

HB_FUNC( QLISTWIDGET_ADDITEM )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_ADDITEM1 );
  }
  else if( ISNUMPAR(1) && ISQLISTWIDGETITEM(1) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_ADDITEM2 );
  }
}

/*
void addItems ( const QStringList & labels )
*/
HB_FUNC( QLISTWIDGET_ADDITEMS )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
    obj->addItems ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void closePersistentEditor ( QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_CLOSEPERSISTENTEDITOR )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->closePersistentEditor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int count () const
*/
HB_FUNC( QLISTWIDGET_COUNT )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
QListWidgetItem * currentItem () const
*/
HB_FUNC( QLISTWIDGET_CURRENTITEM )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * ptr = obj->currentItem (  );
    _qt4xhb_createReturnClass ( ptr, "QLISTWIDGETITEM" );  }
}


/*
int currentRow () const
*/
HB_FUNC( QLISTWIDGET_CURRENTROW )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentRow (  );
    hb_retni( i );
  }
}


/*
void editItem ( QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_EDITITEM )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->editItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QList<QListWidgetItem *> findItems ( const QString & text, Qt::MatchFlags flags ) const
*/
HB_FUNC( QLISTWIDGET_FINDITEMS )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QList<QListWidgetItem *> list = obj->findItems ( par1,  (Qt::MatchFlags) par2 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QLISTWIDGETITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QLISTWIDGETITEM" );
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
        hb_itemPutPtr( pItem, (QListWidgetItem *) list[i] );
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
void insertItem ( int row, QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_INSERTITEM1 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QListWidgetItem * par2 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->insertItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void insertItem ( int row, const QString & label )
*/
HB_FUNC( QLISTWIDGET_INSERTITEM2 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    obj->insertItem ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void insertItem ( int row, QListWidgetItem * item )
//[2]void insertItem ( int row, const QString & label )

HB_FUNC( QLISTWIDGET_INSERTITEM )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISQLISTWIDGETITEM(2) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_INSERTITEM1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_INSERTITEM2 );
  }
}

/*
void insertItems ( int row, const QStringList & labels )
*/
HB_FUNC( QLISTWIDGET_INSERTITEMS )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
QStringList par2;
PHB_ITEM aStrings2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aStrings2);
for (i2=0;i2<nLen2;i2++)
{
QString temp = hb_arrayGetCPtr(aStrings2, i2+1);
par2 << temp;
}
    obj->insertItems ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isSortingEnabled () const
*/
HB_FUNC( QLISTWIDGET_ISSORTINGENABLED )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSortingEnabled (  );
    hb_retl( b );
  }
}


/*
QListWidgetItem * item ( int row ) const
*/
HB_FUNC( QLISTWIDGET_ITEM )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QListWidgetItem * ptr = obj->item ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QLISTWIDGETITEM" );  }
}


/*
QListWidgetItem * itemAt ( const QPoint & p ) const
*/
HB_FUNC( QLISTWIDGET_ITEMAT1 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QListWidgetItem * ptr = obj->itemAt ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QLISTWIDGETITEM" );  }
}


/*
QListWidgetItem * itemAt ( int x, int y ) const
*/
HB_FUNC( QLISTWIDGET_ITEMAT2 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QListWidgetItem * ptr = obj->itemAt ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QLISTWIDGETITEM" );  }
}


//[1]QListWidgetItem * itemAt ( const QPoint & p ) const
//[2]QListWidgetItem * itemAt ( int x, int y ) const

HB_FUNC( QLISTWIDGET_ITEMAT )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_ITEMAT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_ITEMAT2 );
  }
}

/*
QWidget * itemWidget ( QListWidgetItem * item ) const
*/
HB_FUNC( QLISTWIDGET_ITEMWIDGET )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * ptr = obj->itemWidget ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
void openPersistentEditor ( QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_OPENPERSISTENTEDITOR )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->openPersistentEditor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeItemWidget ( QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_REMOVEITEMWIDGET )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeItemWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int row ( const QListWidgetItem * item ) const
*/
HB_FUNC( QLISTWIDGET_ROW )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QListWidgetItem * par1 = (const QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->row ( par1 );
    hb_retni( i );
  }
}


/*
QList<QListWidgetItem *> selectedItems () const
*/
HB_FUNC( QLISTWIDGET_SELECTEDITEMS )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QListWidgetItem *> list = obj->selectedItems (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QLISTWIDGETITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QLISTWIDGETITEM" );
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
        hb_itemPutPtr( pItem, (QListWidgetItem *) list[i] );
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
void setCurrentItem ( QListWidgetItem * item )
*/
HB_FUNC( QLISTWIDGET_SETCURRENTITEM1 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCurrentItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentItem ( QListWidgetItem * item, QItemSelectionModel::SelectionFlags command )
*/
HB_FUNC( QLISTWIDGET_SETCURRENTITEM2 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    obj->setCurrentItem ( par1,  (QItemSelectionModel::SelectionFlags) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCurrentItem ( QListWidgetItem * item )
//[2]void setCurrentItem ( QListWidgetItem * item, QItemSelectionModel::SelectionFlags command )

HB_FUNC( QLISTWIDGET_SETCURRENTITEM )
{
  if( ISNUMPAR(1) && ISQLISTWIDGETITEM(1) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_SETCURRENTITEM1 );
  }
  else if( ISNUMPAR(2) && ISQLISTWIDGETITEM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_SETCURRENTITEM2 );
  }
}

/*
void setCurrentRow ( int row )
*/
HB_FUNC( QLISTWIDGET_SETCURRENTROW1 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCurrentRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentRow ( int row, QItemSelectionModel::SelectionFlags command )
*/
HB_FUNC( QLISTWIDGET_SETCURRENTROW2 )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setCurrentRow ( par1,  (QItemSelectionModel::SelectionFlags) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCurrentRow ( int row )
//[2]void setCurrentRow ( int row, QItemSelectionModel::SelectionFlags command )

HB_FUNC( QLISTWIDGET_SETCURRENTROW )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_SETCURRENTROW1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QLISTWIDGET_SETCURRENTROW2 );
  }
}

/*
void setItemWidget ( QListWidgetItem * item, QWidget * widget )
*/
HB_FUNC( QLISTWIDGET_SETITEMWIDGET )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QListWidgetItem * par1 = (QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItemWidget ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSortingEnabled ( bool enable )
*/
HB_FUNC( QLISTWIDGET_SETSORTINGENABLED )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSortingEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void sortItems ( Qt::SortOrder order = Qt::AscendingOrder )
*/
HB_FUNC( QLISTWIDGET_SORTITEMS )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) Qt::AscendingOrder : hb_parni(1);
    obj->sortItems (  (Qt::SortOrder) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QListWidgetItem * takeItem ( int row )
*/
HB_FUNC( QLISTWIDGET_TAKEITEM )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QListWidgetItem * ptr = obj->takeItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QLISTWIDGETITEM" );  }
}


/*
QRect visualItemRect ( const QListWidgetItem * item ) const
*/
HB_FUNC( QLISTWIDGET_VISUALITEMRECT )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QListWidgetItem * par1 = (const QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * ptr = new QRect( obj->visualItemRect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
virtual void dropEvent ( QDropEvent * event )
*/
HB_FUNC( QLISTWIDGET_DROPEVENT )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDropEvent * par1 = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->dropEvent ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clear ()
*/
HB_FUNC( QLISTWIDGET_CLEAR )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void scrollToItem ( const QListWidgetItem * item, QAbstractItemView::ScrollHint hint = EnsureVisible )
*/
HB_FUNC( QLISTWIDGET_SCROLLTOITEM )
{
  QListWidget * obj = (QListWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QListWidgetItem * par1 = (const QListWidgetItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) QAbstractItemView::EnsureVisible : hb_parni(2);
    obj->scrollToItem ( par1,  (QAbstractItemView::ScrollHint) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




