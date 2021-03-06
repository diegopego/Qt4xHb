/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractTextDocumentLayout>

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
QString anchorAt ( const QPointF & position ) const
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_ANCHORAT )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->anchorAt ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QRectF blockBoundingRect ( const QTextBlock & block ) const = 0
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_BLOCKBOUNDINGRECT )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * par1 = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->blockBoundingRect ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QTextDocument * document () const
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_DOCUMENT )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextDocument * ptr = obj->document (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTDOCUMENT" );  }
}


/*
virtual QSizeF documentSize () const = 0
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_DOCUMENTSIZE )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSizeF * ptr = new QSizeF( obj->documentSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZEF", true );  }
}



/*
virtual QRectF frameBoundingRect ( QTextFrame * frame ) const = 0
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_FRAMEBOUNDINGRECT )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextFrame * par1 = (QTextFrame *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->frameBoundingRect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QTextObjectInterface * handlerForObject ( int objectType ) const
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_HANDLERFOROBJECT )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTextObjectInterface * ptr = obj->handlerForObject ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTEXTOBJECTINTERFACE" );  }
}


/*
virtual int hitTest ( const QPointF & point, Qt::HitTestAccuracy accuracy ) const = 0
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_HITTEST )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int i = obj->hitTest ( *par1,  (Qt::HitTestAccuracy) par2 );
    hb_retni( i );
  }
}


/*
virtual int pageCount () const = 0
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_PAGECOUNT )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->pageCount (  );
    hb_retni( i );
  }
}


/*
QPaintDevice * paintDevice () const
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_PAINTDEVICE )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPaintDevice * ptr = obj->paintDevice (  );
    _qt4xhb_createReturnClass ( ptr, "QPAINTDEVICE" );  }
}


/*
void registerHandler ( int objectType, QObject * component )
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_REGISTERHANDLER )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QObject * par2 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->registerHandler ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPaintDevice ( QPaintDevice * device )
*/
HB_FUNC( QABSTRACTTEXTDOCUMENTLAYOUT_SETPAINTDEVICE )
{
  QAbstractTextDocumentLayout * obj = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPaintDevice * par1 = (QPaintDevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPaintDevice ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




