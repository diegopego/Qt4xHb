/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFontMetricsF>

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
QFontMetricsF ( const QFont & font )
*/
HB_FUNC( QFONTMETRICSF_NEW1 )
{
  QFontMetricsF * o = NULL;
  QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFontMetricsF ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontMetricsF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QFontMetricsF ( const QFont & font, QPaintDevice * paintdevice )
*/
HB_FUNC( QFONTMETRICSF_NEW2 )
{
  QFontMetricsF * o = NULL;
  QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QPaintDevice * par2 = (QPaintDevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFontMetricsF ( *par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontMetricsF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QFontMetricsF ( const QFontMetrics & fontMetrics )
*/
HB_FUNC( QFONTMETRICSF_NEW3 )
{
  QFontMetricsF * o = NULL;
  QFontMetrics * par1 = (QFontMetrics *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFontMetricsF ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontMetricsF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QFontMetricsF ( const QFontMetricsF & fm )
*/
HB_FUNC( QFONTMETRICSF_NEW4 )
{
  QFontMetricsF * o = NULL;
  QFontMetricsF * par1 = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFontMetricsF ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontMetricsF *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QFontMetricsF ( const QFont & font )
//[2]QFontMetricsF ( const QFont & font, QPaintDevice * paintdevice )
//[3]QFontMetricsF ( const QFontMetrics & fontMetrics )
//[4]QFontMetricsF ( const QFontMetricsF & fm )

HB_FUNC( QFONTMETRICSF_NEW )
{
  if( ISNUMPAR(1) && ISQFONT(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_NEW1 );
  }
  else if( ISNUMPAR(2) && ISQFONT(1) && ISOBJECT(2) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQFONTMETRICS(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQFONTMETRICSF(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QFONTMETRICSF_DELETE )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
HB_FUNC( QFONTMETRICSF_ASCENT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->ascent (  );
    hb_retnd( r );
  }
}


/*
qreal averageCharWidth () const
*/
HB_FUNC( QFONTMETRICSF_AVERAGECHARWIDTH )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->averageCharWidth (  );
    hb_retnd( r );
  }
}


/*
QRectF boundingRect ( const QString & text ) const
*/
HB_FUNC( QFONTMETRICSF_BOUNDINGRECT1 )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QRectF * ptr = new QRectF( obj->boundingRect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF boundingRect ( QChar ch ) const
*/
HB_FUNC( QFONTMETRICSF_BOUNDINGRECT2 )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * par1 = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->boundingRect ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF boundingRect ( const QRectF & rect, int flags, const QString & text, int tabStops = 0, int * tabArray = 0 ) const
*/
HB_FUNC( QFONTMETRICSF_BOUNDINGRECT3 )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    QString par3 = hb_parc(3);
    int par4 = ISNIL(4)? 0 : hb_parni(4);
    int par5;
    QRectF * ptr = new QRectF( obj->boundingRect ( *par1, par2, par3, par4, &par5 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );    hb_storni( par5, 5 );
  }
}


//[1]QRectF boundingRect ( const QString & text ) const
//[2]QRectF boundingRect ( QChar ch ) const
//[3]QRectF boundingRect ( const QRectF & rect, int flags, const QString & text, int tabStops = 0, int * tabArray = 0 ) const

HB_FUNC( QFONTMETRICSF_BOUNDINGRECT )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_BOUNDINGRECT1 );
  }
  else if( ISNUMPAR(1) && ISQCHAR(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_BOUNDINGRECT2 );
  }
  else if( ISBETWEEN(3,5) && ISQRECTF(1) && ISNUM(2) && ISCHAR(3) && (ISNUM(4)||ISNIL(4)) && (ISARRAY(5)||ISNIL(5)) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_BOUNDINGRECT3 );
  }
}

/*
qreal descent () const
*/
HB_FUNC( QFONTMETRICSF_DESCENT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->descent (  );
    hb_retnd( r );
  }
}


/*
QString elidedText ( const QString & text, Qt::TextElideMode mode, qreal width, int flags = 0 ) const
*/
HB_FUNC( QFONTMETRICSF_ELIDEDTEXT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    qreal par3 = hb_parnd(3);
    int par4 = ISNIL(4)? 0 : hb_parni(4);
    QString str1 = obj->elidedText ( par1,  (Qt::TextElideMode) par2, par3, par4 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
qreal height () const
*/
HB_FUNC( QFONTMETRICSF_HEIGHT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->height (  );
    hb_retnd( r );
  }
}


/*
bool inFont ( QChar ch ) const
*/
HB_FUNC( QFONTMETRICSF_INFONT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * par1 = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->inFont ( *par1 );
    hb_retl( b );
  }
}


/*
bool inFontUcs4 ( uint ch ) const
*/
HB_FUNC( QFONTMETRICSF_INFONTUCS4 )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    uint par1 = hb_parni(1);
    bool b = obj->inFontUcs4 ( par1 );
    hb_retl( b );
  }
}


/*
qreal leading () const
*/
HB_FUNC( QFONTMETRICSF_LEADING )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->leading (  );
    hb_retnd( r );
  }
}


/*
qreal leftBearing ( QChar ch ) const
*/
HB_FUNC( QFONTMETRICSF_LEFTBEARING )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * par1 = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal r = obj->leftBearing ( *par1 );
    hb_retnd( r );
  }
}


/*
qreal lineSpacing () const
*/
HB_FUNC( QFONTMETRICSF_LINESPACING )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->lineSpacing (  );
    hb_retnd( r );
  }
}


/*
qreal lineWidth () const
*/
HB_FUNC( QFONTMETRICSF_LINEWIDTH )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->lineWidth (  );
    hb_retnd( r );
  }
}


/*
qreal maxWidth () const
*/
HB_FUNC( QFONTMETRICSF_MAXWIDTH )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->maxWidth (  );
    hb_retnd( r );
  }
}


/*
qreal minLeftBearing () const
*/
HB_FUNC( QFONTMETRICSF_MINLEFTBEARING )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->minLeftBearing (  );
    hb_retnd( r );
  }
}


/*
qreal minRightBearing () const
*/
HB_FUNC( QFONTMETRICSF_MINRIGHTBEARING )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->minRightBearing (  );
    hb_retnd( r );
  }
}


/*
qreal overlinePos () const
*/
HB_FUNC( QFONTMETRICSF_OVERLINEPOS )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->overlinePos (  );
    hb_retnd( r );
  }
}


/*
qreal rightBearing ( QChar ch ) const
*/
HB_FUNC( QFONTMETRICSF_RIGHTBEARING )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * par1 = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal r = obj->rightBearing ( *par1 );
    hb_retnd( r );
  }
}


/*
QSizeF size ( int flags, const QString & text, int tabStops = 0, int * tabArray = 0 ) const
*/
HB_FUNC( QFONTMETRICSF_SIZE )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    int par3 = ISNIL(3)? 0 : hb_parni(3);
    int par4;
    QSizeF * ptr = new QSizeF( obj->size ( par1, par2, par3, &par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZEF", true );    hb_storni( par4, 4 );
  }
}


/*
qreal strikeOutPos () const
*/
HB_FUNC( QFONTMETRICSF_STRIKEOUTPOS )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->strikeOutPos (  );
    hb_retnd( r );
  }
}


/*
QRectF tightBoundingRect ( const QString & text ) const
*/
HB_FUNC( QFONTMETRICSF_TIGHTBOUNDINGRECT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QRectF * ptr = new QRectF( obj->tightBoundingRect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
qreal underlinePos () const
*/
HB_FUNC( QFONTMETRICSF_UNDERLINEPOS )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->underlinePos (  );
    hb_retnd( r );
  }
}


/*
qreal width ( const QString & text ) const
*/
HB_FUNC( QFONTMETRICSF_WIDTH1 )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    qreal r = obj->width ( par1 );
    hb_retnd( r );
  }
}


/*
qreal width ( QChar ch ) const
*/
HB_FUNC( QFONTMETRICSF_WIDTH2 )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * par1 = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal r = obj->width ( *par1 );
    hb_retnd( r );
  }
}


//[1]qreal width ( const QString & text ) const
//[2]qreal width ( QChar ch ) const

HB_FUNC( QFONTMETRICSF_WIDTH )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_WIDTH1 );
  }
  else if( ISNUMPAR(1) && ISQCHAR(1) )
  {
    HB_FUNC_EXEC( QFONTMETRICSF_WIDTH2 );
  }
}

/*
qreal xHeight () const
*/
HB_FUNC( QFONTMETRICSF_XHEIGHT )
{
  QFontMetricsF * obj = (QFontMetricsF *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->xHeight (  );
    hb_retnd( r );
  }
}




