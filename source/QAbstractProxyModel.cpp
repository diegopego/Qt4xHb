/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractProxyModel>

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

#include <QItemSelection>
#include <QStringList>
#include <QSize>


HB_FUNC( QABSTRACTPROXYMODEL_DELETE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QModelIndex mapFromSource ( const QModelIndex & sourceIndex ) const = 0
*/
HB_FUNC( QABSTRACTPROXYMODEL_MAPFROMSOURCE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->mapFromSource ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
virtual QItemSelection mapSelectionFromSource ( const QItemSelection & sourceSelection ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_MAPSELECTIONFROMSOURCE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemSelection * par1 = (QItemSelection *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QItemSelection * ptr = new QItemSelection( obj->mapSelectionFromSource ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QITEMSELECTION" );  }
}


/*
virtual QItemSelection mapSelectionToSource ( const QItemSelection & proxySelection ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_MAPSELECTIONTOSOURCE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemSelection * par1 = (QItemSelection *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QItemSelection * ptr = new QItemSelection( obj->mapSelectionToSource ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QITEMSELECTION" );  }
}


/*
virtual QModelIndex mapToSource ( const QModelIndex & proxyIndex ) const = 0
*/
HB_FUNC( QABSTRACTPROXYMODEL_MAPTOSOURCE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->mapToSource ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
virtual void setSourceModel ( QAbstractItemModel * sourceModel )
*/
HB_FUNC( QABSTRACTPROXYMODEL_SETSOURCEMODEL )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemModel * par1 = (QAbstractItemModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSourceModel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QAbstractItemModel * sourceModel () const
*/
HB_FUNC( QABSTRACTPROXYMODEL_SOURCEMODEL )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemModel * ptr = obj->sourceModel (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTITEMMODEL" );  }
}


/*
virtual QModelIndex buddy ( const QModelIndex & index ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_BUDDY )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->buddy ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
virtual bool canFetchMore ( const QModelIndex & parent ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_CANFETCHMORE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->canFetchMore ( *par1 );
    hb_retl( b );
  }
}


/*
virtual QVariant data ( const QModelIndex & proxyIndex, int role = Qt::DisplayRole ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_DATA )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? Qt::DisplayRole : hb_parni(2);
    QVariant * ptr = new QVariant( obj->data ( *par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual void fetchMore ( const QModelIndex & parent )
*/
HB_FUNC( QABSTRACTPROXYMODEL_FETCHMORE )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->fetchMore ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual Qt::ItemFlags flags ( const QModelIndex & index ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_FLAGS )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->flags ( *par1 );
    hb_retni( i );
  }
}


/*
virtual bool hasChildren ( const QModelIndex & parent = QModelIndex() ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_HASCHILDREN )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex par1 = ISNIL(1)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->hasChildren ( par1 );
    hb_retl( b );
  }
}


/*
virtual QVariant headerData ( int section, Qt::Orientation orientation, int role ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_HEADERDATA )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    QVariant * ptr = new QVariant( obj->headerData ( par1,  (Qt::Orientation) par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}



/*
virtual QMimeData * mimeData ( const QModelIndexList & indexes ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_MIMEDATA )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndexList * par1 = (QModelIndexList *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QMimeData * ptr = obj->mimeData ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QMIMEDATA" );  }
}


/*
virtual QStringList mimeTypes () const
*/
HB_FUNC( QABSTRACTPROXYMODEL_MIMETYPES )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->mimeTypes (  );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<strl.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
virtual void revert ()
*/
HB_FUNC( QABSTRACTPROXYMODEL_REVERT )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->revert (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole )
*/
HB_FUNC( QABSTRACTPROXYMODEL_SETDATA )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * par2 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? Qt::EditRole : hb_parni(3);
    bool b = obj->setData ( *par1, *par2, par3 );
    hb_retl( b );
  }
}


/*
virtual bool setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole )
*/
HB_FUNC( QABSTRACTPROXYMODEL_SETHEADERDATA )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QVariant * par3 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par4 = ISNIL(4)? Qt::EditRole : hb_parni(4);
    bool b = obj->setHeaderData ( par1,  (Qt::Orientation) par2, *par3, par4 );
    hb_retl( b );
  }
}



/*
virtual void sort ( int column, Qt::SortOrder order = Qt::AscendingOrder )
*/
HB_FUNC( QABSTRACTPROXYMODEL_SORT )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) Qt::AscendingOrder : hb_parni(2);
    obj->sort ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QSize span ( const QModelIndex & index ) const
*/
HB_FUNC( QABSTRACTPROXYMODEL_SPAN )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QSize * ptr = new QSize( obj->span ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual bool submit ()
*/
HB_FUNC( QABSTRACTPROXYMODEL_SUBMIT )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->submit (  );
    hb_retl( b );
  }
}


/*
virtual Qt::DropActions supportedDropActions () const
*/
HB_FUNC( QABSTRACTPROXYMODEL_SUPPORTEDDROPACTIONS )
{
  QAbstractProxyModel * obj = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->supportedDropActions (  );
    hb_retni( i );
  }
}



