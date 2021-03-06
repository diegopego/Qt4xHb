/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSvgGenerator>

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
QSvgGenerator ()
*/
HB_FUNC( QSVGGENERATOR_NEW )
{
  QSvgGenerator * o = NULL;
  o = new QSvgGenerator (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSvgGenerator *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QSVGGENERATOR_DELETE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QString description () const
*/
HB_FUNC( QSVGGENERATOR_DESCRIPTION )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->description (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString fileName () const
*/
HB_FUNC( QSVGGENERATOR_FILENAME )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->fileName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QIODevice * outputDevice () const
*/
HB_FUNC( QSVGGENERATOR_OUTPUTDEVICE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * ptr = obj->outputDevice (  );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
int resolution () const
*/
HB_FUNC( QSVGGENERATOR_RESOLUTION )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->resolution (  );
    hb_retni( i );
  }
}


/*
void setDescription ( const QString & description )
*/
HB_FUNC( QSVGGENERATOR_SETDESCRIPTION )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setDescription ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFileName ( const QString & fileName )
*/
HB_FUNC( QSVGGENERATOR_SETFILENAME )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setFileName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOutputDevice ( QIODevice * outputDevice )
*/
HB_FUNC( QSVGGENERATOR_SETOUTPUTDEVICE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setOutputDevice ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setResolution ( int dpi )
*/
HB_FUNC( QSVGGENERATOR_SETRESOLUTION )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setResolution ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSize ( const QSize & size )
*/
HB_FUNC( QSVGGENERATOR_SETSIZE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTitle ( const QString & title )
*/
HB_FUNC( QSVGGENERATOR_SETTITLE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setTitle ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setViewBox ( const QRect & viewBox )
*/
HB_FUNC( QSVGGENERATOR_SETVIEWBOX1 )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setViewBox ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setViewBox ( const QRectF & viewBox )
*/
HB_FUNC( QSVGGENERATOR_SETVIEWBOX2 )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setViewBox ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setViewBox ( const QRect & viewBox )
//[2]void setViewBox ( const QRectF & viewBox )

HB_FUNC( QSVGGENERATOR_SETVIEWBOX )
{
  if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QSVGGENERATOR_SETVIEWBOX1 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QSVGGENERATOR_SETVIEWBOX2 );
  }
}

/*
QSize size () const
*/
HB_FUNC( QSVGGENERATOR_SIZE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->size (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
QString title () const
*/
HB_FUNC( QSVGGENERATOR_TITLE )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->title (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QRect viewBox () const
*/
HB_FUNC( QSVGGENERATOR_VIEWBOX )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->viewBox (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
QRectF viewBoxF () const
*/
HB_FUNC( QSVGGENERATOR_VIEWBOXF )
{
  QSvgGenerator * obj = (QSvgGenerator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->viewBoxF (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}



