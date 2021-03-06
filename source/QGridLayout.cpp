/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGridLayout>

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
QGridLayout ( QWidget * parent )
*/
HB_FUNC( QGRIDLAYOUT_NEW1 )
{
  QGridLayout * o = NULL;
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGridLayout ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGridLayout *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QGridLayout ()
*/
HB_FUNC( QGRIDLAYOUT_NEW2 )
{
  QGridLayout * o = NULL;
  o = new QGridLayout (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGridLayout *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QGridLayout ( QWidget * parent )
//[2]QGridLayout ()

HB_FUNC( QGRIDLAYOUT_NEW )
{
  if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QGRIDLAYOUT_NEW1 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QGRIDLAYOUT_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QGRIDLAYOUT_DELETE )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addItem ( QLayoutItem * item, int row, int column, int rowSpan = 1, int columnSpan = 1, Qt::Alignment alignment = 0 )
*/
HB_FUNC( QGRIDLAYOUT_ADDITEM )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLayoutItem * par1 = (QLayoutItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = ISNIL(4)? 1 : hb_parni(4);
    int par5 = ISNIL(5)? 1 : hb_parni(5);
    int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
    obj->addItem ( par1, par2, par3, par4, par5,  (Qt::Alignment) par6 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addLayout ( QLayout * layout, int row, int column, Qt::Alignment alignment = 0 )
*/
HB_FUNC( QGRIDLAYOUT_ADDLAYOUT1 )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLayout * par1 = (QLayout *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = ISNIL(4)? (int) 0 : hb_parni(4);
    obj->addLayout ( par1, par2, par3,  (Qt::Alignment) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addLayout ( QLayout * layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment = 0 )
*/
HB_FUNC( QGRIDLAYOUT_ADDLAYOUT2 )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLayout * par1 = (QLayout *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    int par5 = hb_parni(5);
    int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
    obj->addLayout ( par1, par2, par3, par4, par5,  (Qt::Alignment) par6 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addLayout ( QLayout * layout, int row, int column, Qt::Alignment alignment = 0 )
//[2]void addLayout ( QLayout * layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment = 0 )

HB_FUNC( QGRIDLAYOUT_ADDLAYOUT )
{
  if( ISBETWEEN(3,4) && ISQLAYOUT(1) && ISNUM(2) && ISNUM(3) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QGRIDLAYOUT_ADDLAYOUT1 );
  }
  else if( ISBETWEEN(5,6) && ISQLAYOUT(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) && (ISNUM(6)||ISNIL(6)) )
  {
    HB_FUNC_EXEC( QGRIDLAYOUT_ADDLAYOUT2 );
  }
}

/*
void addWidget ( QWidget * widget, int row, int column, Qt::Alignment alignment = 0 )
*/
HB_FUNC( QGRIDLAYOUT_ADDWIDGET1 )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = ISNIL(4)? (int) 0 : hb_parni(4);
    obj->addWidget ( par1, par2, par3,  (Qt::Alignment) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addWidget ( QWidget * widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment alignment = 0 )
*/
HB_FUNC( QGRIDLAYOUT_ADDWIDGET2 )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    int par5 = hb_parni(5);
    int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
    obj->addWidget ( par1, par2, par3, par4, par5,  (Qt::Alignment) par6 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void addWidget ( QWidget * widget, int row, int column, Qt::Alignment alignment = 0 )
//[2]void addWidget ( QWidget * widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment alignment = 0 )

HB_FUNC( QGRIDLAYOUT_ADDWIDGET )
{
  if( ISBETWEEN(3,4) && ISQWIDGET(1) && ISNUM(2) && ISNUM(3) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QGRIDLAYOUT_ADDWIDGET1 );
  }
  else if( ISBETWEEN(5,6) && ISQWIDGET(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) && (ISNUM(6)||ISNIL(6)) )
  {
    HB_FUNC_EXEC( QGRIDLAYOUT_ADDWIDGET2 );
  }
}

/*
QRect cellRect ( int row, int column ) const
*/
HB_FUNC( QGRIDLAYOUT_CELLRECT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QRect * ptr = new QRect( obj->cellRect ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
int columnCount () const
*/
HB_FUNC( QGRIDLAYOUT_COLUMNCOUNT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->columnCount (  );
    hb_retni( i );
  }
}


/*
int columnMinimumWidth ( int column ) const
*/
HB_FUNC( QGRIDLAYOUT_COLUMNMINIMUMWIDTH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->columnMinimumWidth ( par1 );
    hb_retni( i );
  }
}


/*
int columnStretch ( int column ) const
*/
HB_FUNC( QGRIDLAYOUT_COLUMNSTRETCH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->columnStretch ( par1 );
    hb_retni( i );
  }
}


/*
void getItemPosition ( int index, int * row, int * column, int * rowSpan, int * columnSpan )
*/
HB_FUNC( QGRIDLAYOUT_GETITEMPOSITION )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2;
    int par3;
    int par4;
    int par5;
    obj->getItemPosition ( par1, &par2, &par3, &par4, &par5 );
    hb_storni( par2, 2 );
    hb_storni( par3, 3 );
    hb_storni( par4, 4 );
    hb_storni( par5, 5 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int horizontalSpacing () const
*/
HB_FUNC( QGRIDLAYOUT_HORIZONTALSPACING )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->horizontalSpacing (  );
    hb_retni( i );
  }
}


/*
QLayoutItem * itemAtPosition ( int row, int column ) const
*/
HB_FUNC( QGRIDLAYOUT_ITEMATPOSITION )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QLayoutItem * ptr = obj->itemAtPosition ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QLAYOUTITEM" );  }
}


/*
Qt::Corner originCorner () const
*/
HB_FUNC( QGRIDLAYOUT_ORIGINCORNER )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->originCorner (  );
    hb_retni( i );
  }
}


/*
int rowCount () const
*/
HB_FUNC( QGRIDLAYOUT_ROWCOUNT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->rowCount (  );
    hb_retni( i );
  }
}


/*
int rowMinimumHeight ( int row ) const
*/
HB_FUNC( QGRIDLAYOUT_ROWMINIMUMHEIGHT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->rowMinimumHeight ( par1 );
    hb_retni( i );
  }
}


/*
int rowStretch ( int row ) const
*/
HB_FUNC( QGRIDLAYOUT_ROWSTRETCH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->rowStretch ( par1 );
    hb_retni( i );
  }
}


/*
void setColumnMinimumWidth ( int column, int minSize )
*/
HB_FUNC( QGRIDLAYOUT_SETCOLUMNMINIMUMWIDTH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setColumnMinimumWidth ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setColumnStretch ( int column, int stretch )
*/
HB_FUNC( QGRIDLAYOUT_SETCOLUMNSTRETCH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setColumnStretch ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHorizontalSpacing ( int spacing )
*/
HB_FUNC( QGRIDLAYOUT_SETHORIZONTALSPACING )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setHorizontalSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOriginCorner ( Qt::Corner corner )
*/
HB_FUNC( QGRIDLAYOUT_SETORIGINCORNER )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setOriginCorner (  (Qt::Corner) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRowMinimumHeight ( int row, int minSize )
*/
HB_FUNC( QGRIDLAYOUT_SETROWMINIMUMHEIGHT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setRowMinimumHeight ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRowStretch ( int row, int stretch )
*/
HB_FUNC( QGRIDLAYOUT_SETROWSTRETCH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setRowStretch ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSpacing ( int spacing )
*/
HB_FUNC( QGRIDLAYOUT_SETSPACING )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalSpacing ( int spacing )
*/
HB_FUNC( QGRIDLAYOUT_SETVERTICALSPACING )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setVerticalSpacing ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int spacing () const
*/
HB_FUNC( QGRIDLAYOUT_SPACING )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->spacing (  );
    hb_retni( i );
  }
}


/*
int verticalSpacing () const
*/
HB_FUNC( QGRIDLAYOUT_VERTICALSPACING )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->verticalSpacing (  );
    hb_retni( i );
  }
}


/*
virtual int count () const
*/
HB_FUNC( QGRIDLAYOUT_COUNT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
virtual Qt::Orientations expandingDirections () const
*/
HB_FUNC( QGRIDLAYOUT_EXPANDINGDIRECTIONS )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->expandingDirections (  );
    hb_retni( i );
  }
}


/*
virtual bool hasHeightForWidth () const
*/
HB_FUNC( QGRIDLAYOUT_HASHEIGHTFORWIDTH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasHeightForWidth (  );
    hb_retl( b );
  }
}


/*
virtual int heightForWidth ( int w ) const
*/
HB_FUNC( QGRIDLAYOUT_HEIGHTFORWIDTH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->heightForWidth ( par1 );
    hb_retni( i );
  }
}


/*
virtual void invalidate ()
*/
HB_FUNC( QGRIDLAYOUT_INVALIDATE )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->invalidate (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QLayoutItem * itemAt ( int index ) const
*/
HB_FUNC( QGRIDLAYOUT_ITEMAT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QLayoutItem * ptr = obj->itemAt ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QLAYOUTITEM" );  }
}


/*
virtual QSize maximumSize () const
*/
HB_FUNC( QGRIDLAYOUT_MAXIMUMSIZE )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->maximumSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual int minimumHeightForWidth ( int w ) const
*/
HB_FUNC( QGRIDLAYOUT_MINIMUMHEIGHTFORWIDTH )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->minimumHeightForWidth ( par1 );
    hb_retni( i );
  }
}


/*
virtual QSize minimumSize () const
*/
HB_FUNC( QGRIDLAYOUT_MINIMUMSIZE )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->minimumSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual void setGeometry ( const QRect & rect )
*/
HB_FUNC( QGRIDLAYOUT_SETGEOMETRY )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGeometry ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QSize sizeHint () const
*/
HB_FUNC( QGRIDLAYOUT_SIZEHINT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual QLayoutItem * takeAt ( int index )
*/
HB_FUNC( QGRIDLAYOUT_TAKEAT )
{
  QGridLayout * obj = (QGridLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QLayoutItem * ptr = obj->takeAt ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QLAYOUTITEM" );  }
}




