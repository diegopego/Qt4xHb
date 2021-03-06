/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTextFrameFormat>

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
QTextFrameFormat ()
*/
HB_FUNC( QTEXTFRAMEFORMAT_NEW )
{
  QTextFrameFormat * o = NULL;
  o = new QTextFrameFormat (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextFrameFormat *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTEXTFRAMEFORMAT_DELETE )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
qreal border () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_BORDER )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->border (  );
    hb_retnd( r );
  }
}


/*
QBrush borderBrush () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_BORDERBRUSH )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBrush * ptr = new QBrush( obj->borderBrush (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBRUSH", true );  }
}


/*
BorderStyle borderStyle () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_BORDERSTYLE )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->borderStyle (  );
    hb_retni( i );
  }
}


/*
qreal bottomMargin () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_BOTTOMMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->bottomMargin (  );
    hb_retnd( r );
  }
}


/*
QTextLength height () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_HEIGHT )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextLength * ptr = new QTextLength( obj->height (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTLENGTH" );  }
}


/*
bool isValid () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_ISVALID )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
qreal leftMargin () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_LEFTMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->leftMargin (  );
    hb_retnd( r );
  }
}


/*
qreal margin () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_MARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->margin (  );
    hb_retnd( r );
  }
}


/*
qreal padding () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_PADDING )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->padding (  );
    hb_retnd( r );
  }
}


/*
PageBreakFlags pageBreakPolicy () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_PAGEBREAKPOLICY )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->pageBreakPolicy (  );
    hb_retni( i );
  }
}


/*
Position position () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_POSITION )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->position (  );
    hb_retni( i );
  }
}


/*
qreal rightMargin () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_RIGHTMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->rightMargin (  );
    hb_retnd( r );
  }
}


/*
void setBorder ( qreal width )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETBORDER )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setBorder ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBorderBrush ( const QBrush & brush )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETBORDERBRUSH )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBrush * par1 = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setBorderBrush ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBorderStyle ( BorderStyle style )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETBORDERSTYLE )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setBorderStyle (  (QTextFrameFormat::BorderStyle) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBottomMargin ( qreal margin )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETBOTTOMMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setBottomMargin ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHeight ( const QTextLength & height )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETHEIGHT1 )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextLength * par1 = (QTextLength *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setHeight ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHeight ( qreal height )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETHEIGHT2 )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setHeight ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setHeight ( const QTextLength & height )
//[2]void setHeight ( qreal height )

HB_FUNC( QTEXTFRAMEFORMAT_SETHEIGHT )
{
  if( ISNUMPAR(1) && ISQTEXTLENGTH(1) )
  {
    HB_FUNC_EXEC( QTEXTFRAMEFORMAT_SETHEIGHT1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QTEXTFRAMEFORMAT_SETHEIGHT2 );
  }
}

/*
void setLeftMargin ( qreal margin )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETLEFTMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setLeftMargin ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMargin ( qreal margin )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setMargin ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPadding ( qreal width )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETPADDING )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setPadding ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPageBreakPolicy ( PageBreakFlags policy )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETPAGEBREAKPOLICY )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setPageBreakPolicy (  (QTextFormat::PageBreakFlags) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPosition ( Position policy )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETPOSITION )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setPosition (  (QTextFrameFormat::Position) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRightMargin ( qreal margin )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETRIGHTMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setRightMargin ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTopMargin ( qreal margin )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETTOPMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setTopMargin ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWidth ( const QTextLength & width )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETWIDTH1 )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextLength * par1 = (QTextLength *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setWidth ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWidth ( qreal width )
*/
HB_FUNC( QTEXTFRAMEFORMAT_SETWIDTH2 )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setWidth ( const QTextLength & width )
//[2]void setWidth ( qreal width )

HB_FUNC( QTEXTFRAMEFORMAT_SETWIDTH )
{
  if( ISNUMPAR(1) && ISQTEXTLENGTH(1) )
  {
    HB_FUNC_EXEC( QTEXTFRAMEFORMAT_SETWIDTH1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QTEXTFRAMEFORMAT_SETWIDTH2 );
  }
}

/*
qreal topMargin () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_TOPMARGIN )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->topMargin (  );
    hb_retnd( r );
  }
}


/*
QTextLength width () const
*/
HB_FUNC( QTEXTFRAMEFORMAT_WIDTH )
{
  QTextFrameFormat * obj = (QTextFrameFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextLength * ptr = new QTextLength( obj->width (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTLENGTH" );  }
}



