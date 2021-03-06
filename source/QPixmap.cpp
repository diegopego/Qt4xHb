/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QPixmap>

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

#include <QBitmap>

/*
QPixmap ()
*/
HB_FUNC( QPIXMAP_NEW1 )
{
  QPixmap * o = NULL;
  o = new QPixmap (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPixmap *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QPixmap ( int width, int height )
*/
HB_FUNC( QPIXMAP_NEW2 )
{
  QPixmap * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  o = new QPixmap ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPixmap *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QPixmap ( const QString & fileName, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_NEW3 )
{
  QPixmap * o = NULL;
  QString par1 = hb_parc(1);
  const char * par2 = ISNIL(2)? 0 : hb_parc(2);
  int par3 = ISNIL(3)? (int) Qt::AutoColor : hb_parni(3);
  o = new QPixmap ( par1,  (const char *) par2,  (Qt::ImageConversionFlags) par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPixmap *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}



/*
QPixmap ( const QPixmap & pixmap )
*/
HB_FUNC( QPIXMAP_NEW5 )
{
  QPixmap * o = NULL;
  QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QPixmap ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPixmap *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QPixmap ( const QSize & size )
*/
HB_FUNC( QPIXMAP_NEW6 )
{
  QPixmap * o = NULL;
  QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QPixmap ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QPixmap *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QPixmap ()
//[2]QPixmap ( int width, int height )
//[3]QPixmap ( const QString & fileName, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )
//[4]QPixmap ( const char * const[] xpm )
//[5]QPixmap ( const QPixmap & pixmap )
//[6]QPixmap ( const QSize & size )

HB_FUNC( QPIXMAP_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QPIXMAP_NEW1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPIXMAP_NEW2 );
  }
  else if( ISBETWEEN(1,3) && ISCHAR(1) && (ISCHAR(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QPIXMAP_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQPIXMAP(1) )
  {
    HB_FUNC_EXEC( QPIXMAP_NEW5 );
  }
  else if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QPIXMAP_NEW6 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QPIXMAP_DELETE )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
qint64 cacheKey () const
*/
HB_FUNC( QPIXMAP_CACHEKEY )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->cacheKey (  );
    hb_retni( i );
  }
}


/*
bool convertFromImage ( const QImage & image, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_CONVERTFROMIMAGE )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) Qt::AutoColor : hb_parni(2);
    bool b = obj->convertFromImage ( *par1,  (Qt::ImageConversionFlags) par2 );
    hb_retl( b );
  }
}


/*
QPixmap copy ( const QRect & rectangle = QRect() ) const
*/
HB_FUNC( QPIXMAP_COPY1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect par1 = ISNIL(1)? QRect() : *(QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPixmap * ptr = new QPixmap( obj->copy ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


/*
QPixmap copy ( int x, int y, int width, int height ) const
*/
HB_FUNC( QPIXMAP_COPY2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    QPixmap * ptr = new QPixmap( obj->copy ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


//[1]QPixmap copy ( const QRect & rectangle = QRect() ) const
//[2]QPixmap copy ( int x, int y, int width, int height ) const

HB_FUNC( QPIXMAP_COPY )
{
  if( ISBETWEEN(0,1) && (ISQRECT(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QPIXMAP_COPY1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QPIXMAP_COPY2 );
  }
}

/*
QBitmap createHeuristicMask ( bool clipTight = true ) const
*/
HB_FUNC( QPIXMAP_CREATEHEURISTICMASK )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = ISNIL(1)? true : hb_parl(1);
    QBitmap * ptr = new QBitmap( obj->createHeuristicMask ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBITMAP", true );  }
}


/*
QBitmap createMaskFromColor ( const QColor & maskColor, Qt::MaskMode mode ) const
*/
HB_FUNC( QPIXMAP_CREATEMASKFROMCOLOR1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor par1 = ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
    int par2 = hb_parni(2);
    QBitmap * ptr = new QBitmap( obj->createMaskFromColor ( par1,  (Qt::MaskMode) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBITMAP", true );  }
}


/*
QBitmap createMaskFromColor ( const QColor & maskColor ) const
*/
HB_FUNC( QPIXMAP_CREATEMASKFROMCOLOR2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor par1 = ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
    QBitmap * ptr = new QBitmap( obj->createMaskFromColor ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBITMAP", true );  }
}


//[1]QBitmap createMaskFromColor ( const QColor & maskColor, Qt::MaskMode mode ) const
//[2]QBitmap createMaskFromColor ( const QColor & maskColor ) const

HB_FUNC( QPIXMAP_CREATEMASKFROMCOLOR )
{
  if( ISNUMPAR(2) && (ISQCOLOR(1)||ISCHAR(1)) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QPIXMAP_CREATEMASKFROMCOLOR1 );
  }
  else if( ISNUMPAR(1) && (ISQCOLOR(1)||ISCHAR(1)) )
  {
    HB_FUNC_EXEC( QPIXMAP_CREATEMASKFROMCOLOR2 );
  }
}

/*
int depth () const
*/
HB_FUNC( QPIXMAP_DEPTH )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->depth (  );
    hb_retni( i );
  }
}


/*
void detach ()
*/
HB_FUNC( QPIXMAP_DETACH )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->detach (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void fill ( const QColor & color = Qt::white )
*/
HB_FUNC( QPIXMAP_FILL1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor par1 = ISNIL(1)? Qt::white : ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
    obj->fill ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void fill ( const QWidget * widget, const QPoint & offset )
*/
HB_FUNC( QPIXMAP_FILL2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QWidget * par1 = (const QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * par2 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->fill ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void fill ( const QWidget * widget, int x, int y )
*/
HB_FUNC( QPIXMAP_FILL3 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QWidget * par1 = (const QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    obj->fill ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void fill ( const QColor & color = Qt::white )
//[2]void fill ( const QWidget * widget, const QPoint & offset )
//[3]void fill ( const QWidget * widget, int x, int y )

HB_FUNC( QPIXMAP_FILL )
{
  if( ISBETWEEN(0,1) && (ISQCOLOR(1)||ISCHAR(1)||ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QPIXMAP_FILL1 );
  }
  else if( ISNUMPAR(2) && ISQWIDGET(1) && ISQPOINT(2) )
  {
    HB_FUNC_EXEC( QPIXMAP_FILL2 );
  }
  else if( ISNUMPAR(3) && ISQWIDGET(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QPIXMAP_FILL3 );
  }
}


/*
bool hasAlpha () const
*/
HB_FUNC( QPIXMAP_HASALPHA )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasAlpha (  );
    hb_retl( b );
  }
}


/*
bool hasAlphaChannel () const
*/
HB_FUNC( QPIXMAP_HASALPHACHANNEL )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasAlphaChannel (  );
    hb_retl( b );
  }
}


/*
int height () const
*/
HB_FUNC( QPIXMAP_HEIGHT )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->height (  );
    hb_retni( i );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QPIXMAP_ISNULL )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
bool isQBitmap () const
*/
HB_FUNC( QPIXMAP_ISQBITMAP )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isQBitmap (  );
    hb_retl( b );
  }
}


/*
bool load ( const QString & fileName, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_LOAD )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    const char * par2 = ISNIL(2)? 0 : hb_parc(2);
    int par3 = ISNIL(3)? (int) Qt::AutoColor : hb_parni(3);
    bool b = obj->load ( par1,  (const char *) par2,  (Qt::ImageConversionFlags) par3 );
    hb_retl( b );
  }
}


/*
bool loadFromData ( const uchar * data, uint len, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_LOADFROMDATA1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const uchar * par1 = (const uchar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    uint par2 = hb_parni(2);
    const char * par3 = ISNIL(3)? 0 : hb_parc(3);
    int par4 = ISNIL(4)? (int) Qt::AutoColor : hb_parni(4);
    bool b = obj->loadFromData ( par1, par2,  (const char *) par3,  (Qt::ImageConversionFlags) par4 );
    hb_retl( b );
  }
}


/*
bool loadFromData ( const QByteArray & data, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_LOADFROMDATA2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = ISNIL(2)? 0 : hb_parc(2);
    int par3 = ISNIL(3)? (int) Qt::AutoColor : hb_parni(3);
    bool b = obj->loadFromData ( *par1,  (const char *) par2,  (Qt::ImageConversionFlags) par3 );
    hb_retl( b );
  }
}


//[1]bool loadFromData ( const uchar * data, uint len, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )
//[2]bool loadFromData ( const QByteArray & data, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )

HB_FUNC( QPIXMAP_LOADFROMDATA )
{
  if( ISBETWEEN(2,4) && ISCHAR(1) && ISNUM(2) && (ISCHAR(3)||ISNIL(3)) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QPIXMAP_LOADFROMDATA1 );
  }
  else if( ISBETWEEN(1,3) && ISQBYTEARRAY(1) && (ISCHAR(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QPIXMAP_LOADFROMDATA2 );
  }
}

/*
QBitmap mask () const
*/
HB_FUNC( QPIXMAP_MASK )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBitmap * ptr = new QBitmap( obj->mask (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBITMAP", true );  }
}


/*
QRect rect () const
*/
HB_FUNC( QPIXMAP_RECT )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->rect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
bool save ( const QString & fileName, const char * format = 0, int quality = -1 ) const
*/
HB_FUNC( QPIXMAP_SAVE1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    const char * par2 = ISNIL(2)? 0 : hb_parc(2);
    int par3 = ISNIL(3)? -1 : hb_parni(3);
    bool b = obj->save ( par1,  (const char *) par2, par3 );
    hb_retl( b );
  }
}


/*
bool save ( QIODevice * device, const char * format = 0, int quality = -1 ) const
*/
HB_FUNC( QPIXMAP_SAVE2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = ISNIL(2)? 0 : hb_parc(2);
    int par3 = ISNIL(3)? -1 : hb_parni(3);
    bool b = obj->save ( par1,  (const char *) par2, par3 );
    hb_retl( b );
  }
}


//[1]bool save ( const QString & fileName, const char * format = 0, int quality = -1 ) const
//[2]bool save ( QIODevice * device, const char * format = 0, int quality = -1 ) const

HB_FUNC( QPIXMAP_SAVE )
{
  if( ISBETWEEN(1,3) && ISCHAR(1) && (ISCHAR(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QPIXMAP_SAVE1 );
  }
  else if( ISBETWEEN(1,3) && ISQIODEVICE(1) && (ISCHAR(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QPIXMAP_SAVE2 );
  }
}

/*
QPixmap scaled ( const QSize & size, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation ) const
*/
HB_FUNC( QPIXMAP_SCALED1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) Qt::IgnoreAspectRatio : hb_parni(2);
    int par3 = ISNIL(3)? (int) Qt::FastTransformation : hb_parni(3);
    QPixmap * ptr = new QPixmap( obj->scaled ( *par1,  (Qt::AspectRatioMode) par2,  (Qt::TransformationMode) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


/*
QPixmap scaled ( int width, int height, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation ) const
*/
HB_FUNC( QPIXMAP_SCALED2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = ISNIL(3)? (int) Qt::IgnoreAspectRatio : hb_parni(3);
    int par4 = ISNIL(4)? (int) Qt::FastTransformation : hb_parni(4);
    QPixmap * ptr = new QPixmap( obj->scaled ( par1, par2,  (Qt::AspectRatioMode) par3,  (Qt::TransformationMode) par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


//[1]QPixmap scaled ( const QSize & size, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation ) const
//[2]QPixmap scaled ( int width, int height, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation ) const

HB_FUNC( QPIXMAP_SCALED )
{
  if( ISBETWEEN(1,3) && ISQSIZE(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QPIXMAP_SCALED1 );
  }
  else if( ISBETWEEN(2,4) && ISNUM(1) && ISNUM(2) && (ISNUM(3)||ISNIL(3)) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QPIXMAP_SCALED2 );
  }
}

/*
QPixmap scaledToHeight ( int height, Qt::TransformationMode mode = Qt::FastTransformation ) const
*/
HB_FUNC( QPIXMAP_SCALEDTOHEIGHT )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) Qt::FastTransformation : hb_parni(2);
    QPixmap * ptr = new QPixmap( obj->scaledToHeight ( par1,  (Qt::TransformationMode) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


/*
QPixmap scaledToWidth ( int width, Qt::TransformationMode mode = Qt::FastTransformation ) const
*/
HB_FUNC( QPIXMAP_SCALEDTOWIDTH )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) Qt::FastTransformation : hb_parni(2);
    QPixmap * ptr = new QPixmap( obj->scaledToWidth ( par1,  (Qt::TransformationMode) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}


/*
void scroll ( int dx, int dy, int x, int y, int width, int height, QRegion * exposed = 0 )
*/
HB_FUNC( QPIXMAP_SCROLL1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    int par5 = hb_parni(5);
    int par6 = hb_parni(6);
    QRegion * par7 = ISNIL(7)? 0 : (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(7, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->scroll ( par1, par2, par3, par4, par5, par6, par7 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void scroll ( int dx, int dy, const QRect & rect, QRegion * exposed = 0 )
*/
HB_FUNC( QPIXMAP_SCROLL2 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QRect * par3 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * par4 = ISNIL(4)? 0 : (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(4, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->scroll ( par1, par2, *par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void scroll ( int dx, int dy, int x, int y, int width, int height, QRegion * exposed = 0 )
//[2]void scroll ( int dx, int dy, const QRect & rect, QRegion * exposed = 0 )

HB_FUNC( QPIXMAP_SCROLL )
{
  if( ISBETWEEN(6,7) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) && ISNUM(6) && (ISQREGION(7)||ISNIL(7)) )
  {
    HB_FUNC_EXEC( QPIXMAP_SCROLL1 );
  }
  else if( ISBETWEEN(3,4) && ISNUM(1) && ISNUM(2) && ISQRECT(3) && (ISQREGION(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QPIXMAP_SCROLL2 );
  }
}

/*
void setMask ( const QBitmap & mask )
*/
HB_FUNC( QPIXMAP_SETMASK )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBitmap * par1 = (QBitmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMask ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QSize size () const
*/
HB_FUNC( QPIXMAP_SIZE )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->size (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
void swap ( QPixmap & other )
*/
HB_FUNC( QPIXMAP_SWAP )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->swap ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QImage toImage () const
*/
HB_FUNC( QPIXMAP_TOIMAGE )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * ptr = new QImage( obj->toImage (  ) );
    _qt4xhb_createReturnClass ( ptr, "QIMAGE", true );  }
}







/*
QPixmap transformed ( const QTransform & transform, Qt::TransformationMode mode = Qt::FastTransformation ) const
*/
HB_FUNC( QPIXMAP_TRANSFORMED1 )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) Qt::FastTransformation : hb_parni(2);
    QPixmap * ptr = new QPixmap( obj->transformed ( *par1,  (Qt::TransformationMode) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );  }
}



//[1]QPixmap transformed ( const QTransform & transform, Qt::TransformationMode mode = Qt::FastTransformation ) const
//[2]QPixmap transformed ( const QMatrix & matrix, Qt::TransformationMode mode = Qt::FastTransformation ) const

HB_FUNC( QPIXMAP_TRANSFORMED )
{
  if( ISBETWEEN(1,2) && ISQTRANSFORM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QPIXMAP_TRANSFORMED1 );
  }
  //else if( ISBETWEEN(1,2) && ISQMATRIX(1) && (ISNUM(2)||ISNIL(2)) )
  //{
  //  HB_FUNC_EXEC( QPIXMAP_TRANSFORMED2 );
  //}
}

/*
int width () const
*/
HB_FUNC( QPIXMAP_WIDTH )
{
  QPixmap * obj = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->width (  );
    hb_retni( i );
  }
}




//operator QVariant () const
//bool operator! () const
//QPixmap & operator= ( const QPixmap & pixmap )


//Static Public Members

/*
int defaultDepth ()
*/
HB_FUNC( QPIXMAP_DEFAULTDEPTH )
{
  int i = QPixmap::defaultDepth (  );
  hb_retni( i );
}


/*
QPixmap fromImage ( const QImage & image, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_FROMIMAGE )
{
  QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) Qt::AutoColor : hb_parni(2);
  QPixmap * ptr = new QPixmap( QPixmap::fromImage ( *par1,  (Qt::ImageConversionFlags) par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );}


/*
QPixmap fromImageReader ( QImageReader * imageReader, Qt::ImageConversionFlags flags = Qt::AutoColor )
*/
HB_FUNC( QPIXMAP_FROMIMAGEREADER )
{
  QImageReader * par1 = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) Qt::AutoColor : hb_parni(2);
  QPixmap * ptr = new QPixmap( QPixmap::fromImageReader ( par1,  (Qt::ImageConversionFlags) par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );}








/*
QPixmap grabWidget ( QWidget * widget, const QRect & rectangle )
*/
HB_FUNC( QPIXMAP_GRABWIDGET1 )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QRect * par2 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QPixmap * ptr = new QPixmap( QPixmap::grabWidget ( par1, *par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );}


/*
QPixmap grabWidget ( QWidget * widget, int x = 0, int y = 0, int width = -1, int height = -1 )
*/
HB_FUNC( QPIXMAP_GRABWIDGET2 )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? 0 : hb_parni(2);
  int par3 = ISNIL(3)? 0 : hb_parni(3);
  int par4 = ISNIL(4)? -1 : hb_parni(4);
  int par5 = ISNIL(5)? -1 : hb_parni(5);
  QPixmap * ptr = new QPixmap( QPixmap::grabWidget ( par1, par2, par3, par4, par5 ) );
  _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );}


//[1]QPixmap grabWidget ( QWidget * widget, const QRect & rectangle )
//[2]QPixmap grabWidget ( QWidget * widget, int x = 0, int y = 0, int width = -1, int height = -1 )

HB_FUNC( QPIXMAP_GRABWIDGET )
{
  if( ISNUMPAR(2) && ISQWIDGET(1) && ISQRECT(2) )
  {
    HB_FUNC_EXEC( QPIXMAP_GRABWIDGET1 );
  }
  else if( ISBETWEEN(1,5) && ISQWIDGET(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) && (ISNUM(4)||ISNIL(4)) && (ISNUM(5)||ISNIL(5)) )
  {
    HB_FUNC_EXEC( QPIXMAP_GRABWIDGET2 );
  }
}

/*
QPixmap grabWindow ( WId window, int x = 0, int y = 0, int width = -1, int height = -1 )
*/
HB_FUNC( QPIXMAP_GRABWINDOW )
{
  WId par1 = (WId) hb_parptr(1);
  int par2 = ISNIL(2)? 0 : hb_parni(2);
  int par3 = ISNIL(3)? 0 : hb_parni(3);
  int par4 = ISNIL(4)? -1 : hb_parni(4);
  int par5 = ISNIL(5)? -1 : hb_parni(5);
  QPixmap * ptr = new QPixmap( QPixmap::grabWindow ( par1, par2, par3, par4, par5 ) );
  _qt4xhb_createReturnClass ( ptr, "QPIXMAP", true );}


/*
QTransform trueMatrix ( const QTransform & matrix, int width, int height )
*/
HB_FUNC( QPIXMAP_TRUEMATRIX1 )
{
  QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  QTransform * ptr = new QTransform( QPixmap::trueMatrix ( *par1, par2, par3 ) );
  _qt4xhb_createReturnClass ( ptr, "QTRANSFORM", true );}



//[1]QTransform trueMatrix ( const QTransform & matrix, int width, int height )
//[2]QMatrix trueMatrix ( const QMatrix & m, int w, int h )

HB_FUNC( QPIXMAP_TRUEMATRIX )
{
  if( ISNUMPAR(3) && ISQTRANSFORM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QPIXMAP_TRUEMATRIX1 );
  }
  //else if( ISNUMPAR(3) && ISQMATRIX(1) && ISNUM(2) && ISNUM(3) )
  //{
  //  HB_FUNC_EXEC( QPIXMAP_TRUEMATRIX2 );
  //}
}


