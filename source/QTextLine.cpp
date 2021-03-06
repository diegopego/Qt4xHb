/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTextLine>

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
QTextLine ()
*/
HB_FUNC( QTEXTLINE_NEW )
{
  QTextLine * o = NULL;
  o = new QTextLine (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextLine *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTEXTLINE_DELETE )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
qreal ascent () const
*/
HB_FUNC( QTEXTLINE_ASCENT )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->ascent (  );
    hb_retnd( r );
  }
}


/*
qreal cursorToX ( int * cursorPos, Edge edge = Leading ) const
*/
HB_FUNC( QTEXTLINE_CURSORTOX1 )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1;
    int par2 = ISNIL(2)? (int) QTextLine::Leading : hb_parni(2);
    qreal r = obj->cursorToX ( &par1,  (QTextLine::Edge) par2 );
    hb_retnd( r );
    hb_storni( par1, 1 );
  }
}


/*
qreal cursorToX ( int cursorPos, Edge edge = Leading ) const
*/
HB_FUNC( QTEXTLINE_CURSORTOX2 )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) QTextLine::Leading : hb_parni(2);
    qreal r = obj->cursorToX ( par1,  (QTextLine::Edge) par2 );
    hb_retnd( r );
  }
}


//[1]qreal cursorToX ( int * cursorPos, Edge edge = Leading ) const
//[2]qreal cursorToX ( int cursorPos, Edge edge = Leading ) const

// TODO: resolver conflito

HB_FUNC( QTEXTLINE_CURSORTOX )
{
  if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTEXTLINE_CURSORTOX1 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTEXTLINE_CURSORTOX2 );
  }
}

/*
qreal descent () const
*/
HB_FUNC( QTEXTLINE_DESCENT )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->descent (  );
    hb_retnd( r );
  }
}



/*
qreal height () const
*/
HB_FUNC( QTEXTLINE_HEIGHT )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->height (  );
    hb_retnd( r );
  }
}


/*
qreal horizontalAdvance () const
*/
HB_FUNC( QTEXTLINE_HORIZONTALADVANCE )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->horizontalAdvance (  );
    hb_retnd( r );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QTEXTLINE_ISVALID )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
qreal leading () const
*/
HB_FUNC( QTEXTLINE_LEADING )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->leading (  );
    hb_retnd( r );
  }
}


/*
bool leadingIncluded () const
*/
HB_FUNC( QTEXTLINE_LEADINGINCLUDED )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->leadingIncluded (  );
    hb_retl( b );
  }
}


/*
int lineNumber () const
*/
HB_FUNC( QTEXTLINE_LINENUMBER )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->lineNumber (  );
    hb_retni( i );
  }
}


/*
QRectF naturalTextRect () const
*/
HB_FUNC( QTEXTLINE_NATURALTEXTRECT )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->naturalTextRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
qreal naturalTextWidth () const
*/
HB_FUNC( QTEXTLINE_NATURALTEXTWIDTH )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->naturalTextWidth (  );
    hb_retnd( r );
  }
}


/*
QPointF position () const
*/
HB_FUNC( QTEXTLINE_POSITION )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->position (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QRectF rect () const
*/
HB_FUNC( QTEXTLINE_RECT )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->rect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
void setLeadingIncluded ( bool included )
*/
HB_FUNC( QTEXTLINE_SETLEADINGINCLUDED )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setLeadingIncluded ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLineWidth ( qreal width )
*/
HB_FUNC( QTEXTLINE_SETLINEWIDTH )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setLineWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNumColumns ( int numColumns )
*/
HB_FUNC( QTEXTLINE_SETNUMCOLUMNS1 )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setNumColumns ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNumColumns ( int numColumns, qreal alignmentWidth )
*/
HB_FUNC( QTEXTLINE_SETNUMCOLUMNS2 )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    qreal par2 = hb_parnd(2);
    obj->setNumColumns ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setNumColumns ( int numColumns )
//[2]void setNumColumns ( int numColumns, qreal alignmentWidth )

HB_FUNC( QTEXTLINE_SETNUMCOLUMNS )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QTEXTLINE_SETNUMCOLUMNS1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTEXTLINE_SETNUMCOLUMNS2 );
  }
}

/*
void setPosition ( const QPointF & pos )
*/
HB_FUNC( QTEXTLINE_SETPOSITION )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPosition ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int textLength () const
*/
HB_FUNC( QTEXTLINE_TEXTLENGTH )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->textLength (  );
    hb_retni( i );
  }
}


/*
int textStart () const
*/
HB_FUNC( QTEXTLINE_TEXTSTART )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->textStart (  );
    hb_retni( i );
  }
}


/*
qreal width () const
*/
HB_FUNC( QTEXTLINE_WIDTH )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->width (  );
    hb_retnd( r );
  }
}


/*
qreal x () const
*/
HB_FUNC( QTEXTLINE_X )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->x (  );
    hb_retnd( r );
  }
}


/*
int xToCursor ( qreal x, CursorPosition cpos = CursorBetweenCharacters ) const
*/
HB_FUNC( QTEXTLINE_XTOCURSOR )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    int par2 = ISNIL(2)? (int) QTextLine::CursorBetweenCharacters : hb_parni(2);
    int i = obj->xToCursor ( par1,  (QTextLine::CursorPosition) par2 );
    hb_retni( i );
  }
}


/*
qreal y () const
*/
HB_FUNC( QTEXTLINE_Y )
{
  QTextLine * obj = (QTextLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->y (  );
    hb_retnd( r );
  }
}



