/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QImageReader>

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

#include <QColor>

/*
QImageReader ()
*/
HB_FUNC( QIMAGEREADER_NEW1 )
{
  QImageReader * o = NULL;
  o = new QImageReader (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QImageReader *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QImageReader ( QIODevice * device, const QByteArray & format = QByteArray() )
*/
HB_FUNC( QIMAGEREADER_NEW2 )
{
  QImageReader * o = NULL;
  QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QByteArray par2 = ISNIL(2)? QByteArray() : *(QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QImageReader ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QImageReader *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QImageReader ( const QString & fileName, const QByteArray & format = QByteArray() )
*/
HB_FUNC( QIMAGEREADER_NEW3 )
{
  QImageReader * o = NULL;
  QString par1 = hb_parc(1);
  QByteArray par2 = ISNIL(2)? QByteArray() : *(QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QImageReader ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QImageReader *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QImageReader ()
//[2]QImageReader ( QIODevice * device, const QByteArray & format = QByteArray() )
//[3]QImageReader ( const QString & fileName, const QByteArray & format = QByteArray() )

HB_FUNC( QIMAGEREADER_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQIODEVICE(1) && (ISQBYTEARRAY(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_NEW2 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISQBYTEARRAY(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QIMAGEREADER_DELETE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool autoDetectImageFormat () const
*/
HB_FUNC( QIMAGEREADER_AUTODETECTIMAGEFORMAT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoDetectImageFormat (  );
    hb_retl( b );
  }
}


/*
QColor backgroundColor () const
*/
HB_FUNC( QIMAGEREADER_BACKGROUNDCOLOR )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor * ptr = new QColor( obj->backgroundColor (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCOLOR", true );  }
}


/*
bool canRead () const
*/
HB_FUNC( QIMAGEREADER_CANREAD )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->canRead (  );
    hb_retl( b );
  }
}


/*
QRect clipRect () const
*/
HB_FUNC( QIMAGEREADER_CLIPRECT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->clipRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
int currentImageNumber () const
*/
HB_FUNC( QIMAGEREADER_CURRENTIMAGENUMBER )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentImageNumber (  );
    hb_retni( i );
  }
}


/*
QRect currentImageRect () const
*/
HB_FUNC( QIMAGEREADER_CURRENTIMAGERECT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->currentImageRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
bool decideFormatFromContent () const
*/
HB_FUNC( QIMAGEREADER_DECIDEFORMATFROMCONTENT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->decideFormatFromContent (  );
    hb_retl( b );
  }
}


/*
QIODevice * device () const
*/
HB_FUNC( QIMAGEREADER_DEVICE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * ptr = obj->device (  );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
ImageReaderError error () const
*/
HB_FUNC( QIMAGEREADER_ERROR )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->error (  );
    hb_retni( i );
  }
}


/*
QString errorString () const
*/
HB_FUNC( QIMAGEREADER_ERRORSTRING )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->errorString (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString fileName () const
*/
HB_FUNC( QIMAGEREADER_FILENAME )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->fileName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QByteArray format () const
*/
HB_FUNC( QIMAGEREADER_FORMAT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->format (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
int imageCount () const
*/
HB_FUNC( QIMAGEREADER_IMAGECOUNT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->imageCount (  );
    hb_retni( i );
  }
}


/*
QImage::Format imageFormat () const
*/
HB_FUNC( QIMAGEREADER_IMAGEFORMAT1 )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->imageFormat (  );
    hb_retni( i );
  }
}


/*
bool jumpToImage ( int imageNumber )
*/
HB_FUNC( QIMAGEREADER_JUMPTOIMAGE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->jumpToImage ( par1 );
    hb_retl( b );
  }
}


/*
bool jumpToNextImage ()
*/
HB_FUNC( QIMAGEREADER_JUMPTONEXTIMAGE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->jumpToNextImage (  );
    hb_retl( b );
  }
}


/*
int loopCount () const
*/
HB_FUNC( QIMAGEREADER_LOOPCOUNT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->loopCount (  );
    hb_retni( i );
  }
}


/*
int nextImageDelay () const
*/
HB_FUNC( QIMAGEREADER_NEXTIMAGEDELAY )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->nextImageDelay (  );
    hb_retni( i );
  }
}


/*
int quality () const
*/
HB_FUNC( QIMAGEREADER_QUALITY )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->quality (  );
    hb_retni( i );
  }
}


/*
QImage read ()
*/
HB_FUNC( QIMAGEREADER_READ1 )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * ptr = new QImage( obj->read (  ) );
    _qt4xhb_createReturnClass ( ptr, "QIMAGE", true );  }
}


/*
bool read ( QImage * image )
*/
HB_FUNC( QIMAGEREADER_READ2 )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->read ( par1 );
    hb_retl( b );
  }
}


//[1]QImage read ()
//[2]bool read ( QImage * image )

HB_FUNC( QIMAGEREADER_READ )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_READ1 );
  }
  else if( ISNUMPAR(1) && ISQIMAGE(1) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_READ2 );
  }
}

/*
QRect scaledClipRect () const
*/
HB_FUNC( QIMAGEREADER_SCALEDCLIPRECT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->scaledClipRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
QSize scaledSize () const
*/
HB_FUNC( QIMAGEREADER_SCALEDSIZE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->scaledSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
void setAutoDetectImageFormat ( bool enabled )
*/
HB_FUNC( QIMAGEREADER_SETAUTODETECTIMAGEFORMAT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoDetectImageFormat ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBackgroundColor ( const QColor & color )
*/
HB_FUNC( QIMAGEREADER_SETBACKGROUNDCOLOR )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor par1 = ISOBJECT(1)? *(QColor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QColor(hb_parc(1));
    obj->setBackgroundColor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setClipRect ( const QRect & rect )
*/
HB_FUNC( QIMAGEREADER_SETCLIPRECT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setClipRect ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDecideFormatFromContent ( bool ignored )
*/
HB_FUNC( QIMAGEREADER_SETDECIDEFORMATFROMCONTENT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setDecideFormatFromContent ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDevice ( QIODevice * device )
*/
HB_FUNC( QIMAGEREADER_SETDEVICE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDevice ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFileName ( const QString & fileName )
*/
HB_FUNC( QIMAGEREADER_SETFILENAME )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setFileName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFormat ( const QByteArray & format )
*/
HB_FUNC( QIMAGEREADER_SETFORMAT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFormat ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setQuality ( int quality )
*/
HB_FUNC( QIMAGEREADER_SETQUALITY )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setQuality ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setScaledClipRect ( const QRect & rect )
*/
HB_FUNC( QIMAGEREADER_SETSCALEDCLIPRECT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setScaledClipRect ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setScaledSize ( const QSize & size )
*/
HB_FUNC( QIMAGEREADER_SETSCALEDSIZE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setScaledSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QSize size () const
*/
HB_FUNC( QIMAGEREADER_SIZE )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->size (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
bool supportsAnimation () const
*/
HB_FUNC( QIMAGEREADER_SUPPORTSANIMATION )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->supportsAnimation (  );
    hb_retl( b );
  }
}


/*
bool supportsOption ( QImageIOHandler::ImageOption option ) const
*/
HB_FUNC( QIMAGEREADER_SUPPORTSOPTION )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->supportsOption (  (QImageIOHandler::ImageOption) par1 );
    hb_retl( b );
  }
}


/*
QString text ( const QString & key ) const
*/
HB_FUNC( QIMAGEREADER_TEXT )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString str1 = obj->text ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QStringList textKeys () const
*/
HB_FUNC( QIMAGEREADER_TEXTKEYS )
{
  QImageReader * obj = (QImageReader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->textKeys (  );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<strl.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}



/*
QByteArray imageFormat ( const QString & fileName )
*/
HB_FUNC( QIMAGEREADER_IMAGEFORMAT2 )
{
  QString par1 = hb_parc(1);
  QByteArray * ptr = new QByteArray( QImageReader::imageFormat ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray imageFormat ( QIODevice * device )
*/
HB_FUNC( QIMAGEREADER_IMAGEFORMAT3 )
{
  QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QByteArray * ptr = new QByteArray( QImageReader::imageFormat ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


//[1]QImage::Format imageFormat () const
//[2]QByteArray imageFormat ( const QString & fileName )
//[3]QByteArray imageFormat ( QIODevice * device )

HB_FUNC( QIMAGEREADER_IMAGEFORMAT )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_IMAGEFORMAT1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_IMAGEFORMAT2 );
  }
  else if( ISNUMPAR(1) && ISQIODEVICE(1) )
  {
    HB_FUNC_EXEC( QIMAGEREADER_IMAGEFORMAT3 );
  }
}

/*
QList<QByteArray> supportedImageFormats ()
*/
HB_FUNC( QIMAGEREADER_SUPPORTEDIMAGEFORMATS )
{
  QList<QByteArray> list = QImageReader::supportedImageFormats (  );
  PHB_DYNS pDynSym;
  #ifdef __XHARBOUR__
  pDynSym = hb_dynsymFind( "QBYTEARRAY" );
  #else
  pDynSym = hb_dynsymFindName( "QBYTEARRAY" );
  #endif
  PHB_ITEM pArray;
  pArray = hb_itemArrayNew(0);
  int i;
  for(i=0;i<list.count();i++)
  {
    if( pDynSym )
    {
      #ifdef __XHARBOUR__
      hb_vmPushSymbol( pDynSym->pSymbol );
      #else
      hb_vmPushDynSym( pDynSym );
      #endif
      hb_vmPushNil();
      hb_vmDo( 0 );
      PHB_ITEM pObject = hb_itemNew( NULL );
      hb_itemCopy( pObject, hb_stackReturnItem() );
      PHB_ITEM pItem = hb_itemNew( NULL );
      hb_itemPutPtr( pItem, (QByteArray *) new QByteArray ( list[i] ) );
      hb_objSendMsg( pObject, "_POINTER", 1, pItem );
      hb_itemRelease( pItem );
      hb_arrayAddForward( pArray, pObject );
      hb_itemRelease( pObject );
    }
  }
  hb_itemReturnRelease(pArray);
}



