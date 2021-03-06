/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSqlTableModel>

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

#include <QSqlIndex>

/*
QSqlTableModel ( QObject * parent = 0, QSqlDatabase db = QSqlDatabase() )
*/
HB_FUNC( QSQLTABLEMODEL_NEW )
{
  QSqlTableModel * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QSqlDatabase par2 = ISNIL(2)? QSqlDatabase() : *(QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QSqlTableModel ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSqlTableModel *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QSQLTABLEMODEL_DELETE )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QSqlDatabase database () const
*/
HB_FUNC( QSQLTABLEMODEL_DATABASE )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlDatabase * ptr = new QSqlDatabase( obj->database (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLDATABASE" );  }
}


/*
EditStrategy editStrategy () const
*/
HB_FUNC( QSQLTABLEMODEL_EDITSTRATEGY )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->editStrategy (  );
    hb_retni( i );
  }
}


/*
int fieldIndex ( const QString & fieldName ) const
*/
HB_FUNC( QSQLTABLEMODEL_FIELDINDEX )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int i = obj->fieldIndex ( par1 );
    hb_retni( i );
  }
}


/*
QString filter () const
*/
HB_FUNC( QSQLTABLEMODEL_FILTER )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->filter (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool insertRecord ( int row, const QSqlRecord & record )
*/
HB_FUNC( QSQLTABLEMODEL_INSERTRECORD )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QSqlRecord * par2 = (QSqlRecord *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->insertRecord ( par1, *par2 );
    hb_retl( b );
  }
}


/*
bool isDirty ( const QModelIndex & index ) const
*/
HB_FUNC( QSQLTABLEMODEL_ISDIRTY )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isDirty ( *par1 );
    hb_retl( b );
  }
}


/*
QSqlIndex primaryKey () const
*/
HB_FUNC( QSQLTABLEMODEL_PRIMARYKEY )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlIndex * ptr = new QSqlIndex( obj->primaryKey (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLINDEX", true );  }
}


/*
virtual void revertRow ( int row )
*/
HB_FUNC( QSQLTABLEMODEL_REVERTROW )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->revertRow ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool select ()
*/
HB_FUNC( QSQLTABLEMODEL_SELECT )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->select (  );
    hb_retl( b );
  }
}


/*
virtual void setEditStrategy ( EditStrategy strategy )
*/
HB_FUNC( QSQLTABLEMODEL_SETEDITSTRATEGY )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setEditStrategy (  (QSqlTableModel::EditStrategy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setFilter ( const QString & filter )
*/
HB_FUNC( QSQLTABLEMODEL_SETFILTER )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setFilter ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool setRecord ( int row, const QSqlRecord & record )
*/
HB_FUNC( QSQLTABLEMODEL_SETRECORD )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QSqlRecord * par2 = (QSqlRecord *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->setRecord ( par1, *par2 );
    hb_retl( b );
  }
}


/*
virtual void setSort ( int column, Qt::SortOrder order )
*/
HB_FUNC( QSQLTABLEMODEL_SETSORT )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setSort ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setTable ( const QString & tableName )
*/
HB_FUNC( QSQLTABLEMODEL_SETTABLE )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setTable ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString tableName () const
*/
HB_FUNC( QSQLTABLEMODEL_TABLENAME )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->tableName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual void clear ()
*/
HB_FUNC( QSQLTABLEMODEL_CLEAR )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const
*/
HB_FUNC( QSQLTABLEMODEL_DATA )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? Qt::DisplayRole : hb_parni(2);
    QVariant * ptr = new QVariant( obj->data ( *par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual Qt::ItemFlags flags ( const QModelIndex & index ) const
*/
HB_FUNC( QSQLTABLEMODEL_FLAGS )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->flags ( *par1 );
    hb_retni( i );
  }
}


/*
virtual QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const
*/
HB_FUNC( QSQLTABLEMODEL_HEADERDATA )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = ISNIL(3)? Qt::DisplayRole : hb_parni(3);
    QVariant * ptr = new QVariant( obj->headerData ( par1,  (Qt::Orientation) par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual bool insertRows ( int row, int count, const QModelIndex & parent = QModelIndex() )
*/
HB_FUNC( QSQLTABLEMODEL_INSERTROWS )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QModelIndex par3 = ISNIL(3)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->insertRows ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
virtual bool removeColumns ( int column, int count, const QModelIndex & parent = QModelIndex() )
*/
HB_FUNC( QSQLTABLEMODEL_REMOVECOLUMNS )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QModelIndex par3 = ISNIL(3)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->removeColumns ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
virtual bool removeRows ( int row, int count, const QModelIndex & parent = QModelIndex() )
*/
HB_FUNC( QSQLTABLEMODEL_REMOVEROWS )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QModelIndex par3 = ISNIL(3)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->removeRows ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const
*/
HB_FUNC( QSQLTABLEMODEL_ROWCOUNT )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex par1 = ISNIL(1)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->rowCount ( par1 );
    hb_retni( i );
  }
}


/*
virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole )
*/
HB_FUNC( QSQLTABLEMODEL_SETDATA )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual void sort ( int column, Qt::SortOrder order )
*/
HB_FUNC( QSQLTABLEMODEL_SORT )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->sort ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void revert ()
*/
HB_FUNC( QSQLTABLEMODEL_REVERT )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->revert (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void revertAll ()
*/
HB_FUNC( QSQLTABLEMODEL_REVERTALL )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->revertAll (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool submit ()
*/
HB_FUNC( QSQLTABLEMODEL_SUBMIT )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->submit (  );
    hb_retl( b );
  }
}


/*
bool submitAll ()
*/
HB_FUNC( QSQLTABLEMODEL_SUBMITALL )
{
  QSqlTableModel * obj = (QSqlTableModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->submitAll (  );
    hb_retl( b );
  }
}




