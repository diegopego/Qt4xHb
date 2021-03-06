/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QToolBox>

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
QToolBox ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
*/
HB_FUNC( QTOOLBOX_NEW )
{
  QToolBox * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) 0 : hb_parni(2);
  o = new QToolBox ( par1,  (Qt::WindowFlags) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QToolBox *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTOOLBOX_DELETE )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int addItem ( QWidget * widget, const QIcon & iconSet, const QString & text )
*/
HB_FUNC( QTOOLBOX_ADDITEM1 )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QIcon par2 = ISOBJECT(2)? *(QIcon *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) ) : QIcon(hb_parc(2));
    QString par3 = hb_parc(3);
    int i = obj->addItem ( par1, par2, par3 );
    hb_retni( i );
  }
}


/*
int addItem ( QWidget * w, const QString & text )
*/
HB_FUNC( QTOOLBOX_ADDITEM2 )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    int i = obj->addItem ( par1, par2 );
    hb_retni( i );
  }
}


//[1]int addItem ( QWidget * widget, const QIcon & iconSet, const QString & text )
//[2]int addItem ( QWidget * w, const QString & text )

HB_FUNC( QTOOLBOX_ADDITEM )
{
  if( ISNUMPAR(3) && ISQWIDGET(1) && (ISQICON(2)||ISCHAR(2)) && ISCHAR(3) )
  {
    HB_FUNC_EXEC( QTOOLBOX_ADDITEM1 );
  }
  else if( ISNUMPAR(2) && ISQWIDGET(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QTOOLBOX_ADDITEM2 );
  }
}

/*
int count () const
*/
HB_FUNC( QTOOLBOX_COUNT )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
int currentIndex () const
*/
HB_FUNC( QTOOLBOX_CURRENTINDEX )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentIndex (  );
    hb_retni( i );
  }
}


/*
QWidget * currentWidget () const
*/
HB_FUNC( QTOOLBOX_CURRENTWIDGET )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->currentWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
int indexOf ( QWidget * widget ) const
*/
HB_FUNC( QTOOLBOX_INDEXOF )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->indexOf ( par1 );
    hb_retni( i );
  }
}


/*
int insertItem ( int index, QWidget * widget, const QIcon & icon, const QString & text )
*/
HB_FUNC( QTOOLBOX_INSERTITEM1 )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QIcon par3 = ISOBJECT(3)? *(QIcon *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) ) : QIcon(hb_parc(3));
    QString par4 = hb_parc(4);
    int i = obj->insertItem ( par1, par2, par3, par4 );
    hb_retni( i );
  }
}


/*
int insertItem ( int index, QWidget * widget, const QString & text )
*/
HB_FUNC( QTOOLBOX_INSERTITEM2 )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par3 = hb_parc(3);
    int i = obj->insertItem ( par1, par2, par3 );
    hb_retni( i );
  }
}


//[1]int insertItem ( int index, QWidget * widget, const QIcon & icon, const QString & text )
//[2]int insertItem ( int index, QWidget * widget, const QString & text )

HB_FUNC( QTOOLBOX_INSERTITEM )
{
  if( ISNUMPAR(4) && ISNUM(1) && ISQWIDGET(2) && (ISQICON(3)||ISCHAR(3)) && ISCHAR(4) )
  {
    HB_FUNC_EXEC( QTOOLBOX_INSERTITEM1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISQWIDGET(2) && ISCHAR(3) )
  {
    HB_FUNC_EXEC( QTOOLBOX_INSERTITEM2 );
  }
}

/*
bool isItemEnabled ( int index ) const
*/
HB_FUNC( QTOOLBOX_ISITEMENABLED )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->isItemEnabled ( par1 );
    hb_retl( b );
  }
}


/*
QIcon itemIcon ( int index ) const
*/
HB_FUNC( QTOOLBOX_ITEMICON )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QIcon * ptr = new QIcon( obj->itemIcon ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QICON", true );  }
}


/*
QString itemText ( int index ) const
*/
HB_FUNC( QTOOLBOX_ITEMTEXT )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString str1 = obj->itemText ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString itemToolTip ( int index ) const
*/
HB_FUNC( QTOOLBOX_ITEMTOOLTIP )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString str1 = obj->itemToolTip ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void removeItem ( int index )
*/
HB_FUNC( QTOOLBOX_REMOVEITEM )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->removeItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemEnabled ( int index, bool enabled )
*/
HB_FUNC( QTOOLBOX_SETITEMENABLED )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = hb_parl(2);
    obj->setItemEnabled ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemIcon ( int index, const QIcon & icon )
*/
HB_FUNC( QTOOLBOX_SETITEMICON )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QIcon par2 = ISOBJECT(2)? *(QIcon *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) ) : QIcon(hb_parc(2));
    obj->setItemIcon ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemText ( int index, const QString & text )
*/
HB_FUNC( QTOOLBOX_SETITEMTEXT )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    obj->setItemText ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemToolTip ( int index, const QString & toolTip )
*/
HB_FUNC( QTOOLBOX_SETITEMTOOLTIP )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    obj->setItemToolTip ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWidget * widget ( int index ) const
*/
HB_FUNC( QTOOLBOX_WIDGET )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QWidget * ptr = obj->widget ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
void setCurrentIndex ( int index )
*/
HB_FUNC( QTOOLBOX_SETCURRENTINDEX )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCurrentIndex ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentWidget ( QWidget * widget )
*/
HB_FUNC( QTOOLBOX_SETCURRENTWIDGET )
{
  QToolBox * obj = (QToolBox *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCurrentWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




