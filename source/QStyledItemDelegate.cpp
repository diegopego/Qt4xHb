/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QStyledItemDelegate>

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
QStyledItemDelegate ( QObject * parent = 0 )
*/
HB_FUNC( QSTYLEDITEMDELEGATE_NEW )
{
  QStyledItemDelegate * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QStyledItemDelegate ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QStyledItemDelegate *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QSTYLEDITEMDELEGATE_DELETE )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QString displayText ( const QVariant & value, const QLocale & locale ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_DISPLAYTEXT )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVariant * par1 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QLocale * par2 = (QLocale *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->displayText ( *par1, *par2 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QItemEditorFactory * itemEditorFactory () const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_ITEMEDITORFACTORY )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemEditorFactory * ptr = obj->itemEditorFactory (  );
    _qt4xhb_createReturnClass ( ptr, "QITEMEDITORFACTORY" );  }
}


/*
void setItemEditorFactory ( QItemEditorFactory * factory )
*/
HB_FUNC( QSTYLEDITEMDELEGATE_SETITEMEDITORFACTORY )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemEditorFactory * par1 = (QItemEditorFactory *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItemEditorFactory ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QWidget * createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_CREATEEDITOR )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QStyleOptionViewItem * par2 = (QStyleOptionViewItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * par3 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * ptr = obj->createEditor ( par1, *par2, *par3 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_PAINT )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QStyleOptionViewItem * par2 = (QStyleOptionViewItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * par3 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->paint ( par1, *par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setEditorData ( QWidget * editor, const QModelIndex & index ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_SETEDITORDATA )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * par2 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setEditorData ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_SETMODELDATA )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QAbstractItemModel * par2 = (QAbstractItemModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * par3 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setModelData ( par1, par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_SIZEHINT )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStyleOptionViewItem * par1 = (QStyleOptionViewItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * par2 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QSize * ptr = new QSize( obj->sizeHint ( *par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual void updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const
*/
HB_FUNC( QSTYLEDITEMDELEGATE_UPDATEEDITORGEOMETRY )
{
  QStyledItemDelegate * obj = (QStyledItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QStyleOptionViewItem * par2 = (QStyleOptionViewItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * par3 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->updateEditorGeometry ( par1, *par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




