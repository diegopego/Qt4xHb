/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QBrush>

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
QBrush ()
*/
HB_FUNC( QBRUSH_NEW1 )
{
  QBrush * o = NULL;
  o = new QBrush (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( Qt::BrushStyle style )
*/
HB_FUNC( QBRUSH_NEW2 )
{
  QBrush * o = NULL;
  int par1 = hb_parni(1);
  o = new QBrush (  (Qt::BrushStyle) par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( const QColor & color, Qt::BrushStyle style = Qt::SolidPattern )
*/
HB_FUNC( QBRUSH_NEW3 )
{
  QBrush * o = NULL;
  QColor par1 = ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
  int par2 = ISNIL(2)? (int) Qt::SolidPattern : hb_parni(2);
  o = new QBrush ( par1,  (Qt::BrushStyle) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( Qt::GlobalColor color, Qt::BrushStyle style = Qt::SolidPattern )
*/
HB_FUNC( QBRUSH_NEW4 )
{
  QBrush * o = NULL;
  int par1 = hb_parni(1);
  int par2 = ISNIL(2)? (int) Qt::SolidPattern : hb_parni(2);
  o = new QBrush (  (Qt::GlobalColor) par1,  (Qt::BrushStyle) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( const QColor & color, const QPixmap & pixmap )
*/
HB_FUNC( QBRUSH_NEW5 )
{
  QBrush * o = NULL;
  QColor par1 = ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
  QPixmap * par2 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBrush ( par1, *par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( Qt::GlobalColor color, const QPixmap & pixmap )
*/
HB_FUNC( QBRUSH_NEW6 )
{
  QBrush * o = NULL;
  int par1 = hb_parni(1);
  QPixmap * par2 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBrush (  (Qt::GlobalColor) par1, *par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( const QPixmap & pixmap )
*/
HB_FUNC( QBRUSH_NEW7 )
{
  QBrush * o = NULL;
  QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBrush ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( const QImage & image )
*/
HB_FUNC( QBRUSH_NEW8 )
{
  QBrush * o = NULL;
  QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBrush ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( const QBrush & other )
*/
HB_FUNC( QBRUSH_NEW9 )
{
  QBrush * o = NULL;
  QBrush * par1 = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBrush ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QBrush ( const QGradient & gradient )
*/
HB_FUNC( QBRUSH_NEW10 )
{
  QBrush * o = NULL;
  QGradient * par1 = (QGradient *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBrush ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBrush *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[01]QBrush ()
//[02]QBrush ( Qt::BrushStyle style )
//[03]QBrush ( const QColor & color, Qt::BrushStyle style = Qt::SolidPattern )
//[04]QBrush ( Qt::GlobalColor color, Qt::BrushStyle style = Qt::SolidPattern )
//[05]QBrush ( const QColor & color, const QPixmap & pixmap )
//[06]QBrush ( Qt::GlobalColor color, const QPixmap & pixmap )
//[07]QBrush ( const QPixmap & pixmap )
//[08]QBrush ( const QImage & image )
//[09]QBrush ( const QBrush & other )
//[10]QBrush ( const QGradient & gradient )

// TODO: resolver conflito entre [2] e [4] quando for 1 par�metro

HB_FUNC( QBRUSH_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW2 );
  }
  else if( ISBETWEEN(1,2) && (ISQCOLOR(1)||ISCHAR(1)) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW3 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW4 );
  }
  else if( ISNUMPAR(2) && (ISQCOLOR(1)||ISCHAR(1)) && ISQPIXMAP(2) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW5 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISQPIXMAP(2) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW6 );
  }
  else if( ISNUMPAR(1) && ISQPIXMAP(1) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW7 );
  }
  else if( ISNUMPAR(1) && ISQIMAGE(1) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW8 );
  }
  else if( ISNUMPAR(1) && ISQBRUSH(1) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW9 );
  }
  else if( ISNUMPAR(1) && ISQGRADIENT(1) )
  {
    HB_FUNC_EXEC( QBRUSH_NEW10 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QBRUSH_DELETE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
const QColor & color () const
*/
HB_FUNC( QBRUSH_COLOR )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QColor * ptr = &obj->color (  );
    _qt4xhb_createReturnClass ( ptr, "QCOLOR" );  }
}


/*
const QGradient * gradient () const
*/
HB_FUNC( QBRUSH_GRADIENT )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGradient * ptr = obj->gradient (  );
    _qt4xhb_createReturnClass ( ptr, "QGRADIENT" );  }
}


/*
bool isOpaque () const
*/
HB_FUNC( QBRUSH_ISOPAQUE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isOpaque (  );
    hb_retl( b );
  }
}


/*
const QMatrix & matrix () const
*/
HB_FUNC( QBRUSH_MATRIX )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QMatrix * ptr = &obj->matrix (  );
    _qt4xhb_createReturnClass ( ptr, "QMATRIX" );  }
}


/*
void setColor ( const QColor & color )
*/
HB_FUNC( QBRUSH_SETCOLOR1 )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor par1 = ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
    obj->setColor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setColor ( Qt::GlobalColor color )
*/
HB_FUNC( QBRUSH_SETCOLOR2 )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setColor (  (Qt::GlobalColor) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setColor ( const QColor & color )
//[2]void setColor ( Qt::GlobalColor color )

HB_FUNC( QBRUSH_SETCOLOR )
{
  if( ISNUMPAR(1) && (ISQCOLOR(1)||ISCHAR(1)) )
  {
    HB_FUNC_EXEC( QBRUSH_SETCOLOR1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBRUSH_SETCOLOR2 );
  }
}

/*
void setMatrix ( const QMatrix & matrix )
*/
HB_FUNC( QBRUSH_SETMATRIX )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QMatrix * par1 = (QMatrix *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMatrix ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStyle ( Qt::BrushStyle style )
*/
HB_FUNC( QBRUSH_SETSTYLE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setStyle (  (Qt::BrushStyle) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTexture ( const QPixmap & pixmap )
*/
HB_FUNC( QBRUSH_SETTEXTURE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setTexture ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTextureImage ( const QImage & image )
*/
HB_FUNC( QBRUSH_SETTEXTUREIMAGE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setTextureImage ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTransform ( const QTransform & matrix )
*/
HB_FUNC( QBRUSH_SETTRANSFORM )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setTransform ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Qt::BrushStyle style () const
*/
HB_FUNC( QBRUSH_STYLE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->style (  );
    hb_retni( i );
  }
}


/*
QPixmap texture () const
*/
HB_FUNC( QBRUSH_TEXTURE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPixmap * ptr = new QPixmap( obj->texture (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


/*
QImage textureImage () const
*/
HB_FUNC( QBRUSH_TEXTUREIMAGE )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * ptr = new QImage( obj->textureImage (  ) );
    _qt4xhb_createReturnClass ( ptr, "QIMAGE", true );  }
}


/*
QTransform transform () const
*/
HB_FUNC( QBRUSH_TRANSFORM )
{
  QBrush * obj = (QBrush *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * ptr = new QTransform( obj->transform (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTRANSFORM", true );  }
}



