/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QIconEngine>

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

HB_FUNC( QICONENGINE_DELETE )
{
  QIconEngine * obj = (QIconEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QSize actualSize ( const QSize & size, QIcon::Mode mode, QIcon::State state )
*/
HB_FUNC( QICONENGINE_ACTUALSIZE )
{
  QIconEngine * obj = (QIconEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    QSize * ptr = new QSize( obj->actualSize ( *par1,  (QIcon::Mode) par2,  (QIcon::State) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual void addFile ( const QString & fileName, const QSize & size, QIcon::Mode mode, QIcon::State state )
*/
HB_FUNC( QICONENGINE_ADDFILE )
{
  QIconEngine * obj = (QIconEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QSize * par2 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->addFile ( par1, *par2,  (QIcon::Mode) par3,  (QIcon::State) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void addPixmap ( const QPixmap & pixmap, QIcon::Mode mode, QIcon::State state )
*/
HB_FUNC( QICONENGINE_ADDPIXMAP )
{
  QIconEngine * obj = (QIconEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    obj->addPixmap ( *par1,  (QIcon::Mode) par2,  (QIcon::State) par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void paint ( QPainter * painter, const QRect & rect, QIcon::Mode mode, QIcon::State state ) = 0
*/
HB_FUNC( QICONENGINE_PAINT )
{
  QIconEngine * obj = (QIconEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * par2 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->paint ( par1, *par2,  (QIcon::Mode) par3,  (QIcon::State) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QPixmap pixmap ( const QSize & size, QIcon::Mode mode, QIcon::State state )
*/
HB_FUNC( QICONENGINE_PIXMAP )
{
  QIconEngine * obj = (QIconEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    QPixmap * ptr = new QPixmap( obj->pixmap ( *par1,  (QIcon::Mode) par2,  (QIcon::State) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}



