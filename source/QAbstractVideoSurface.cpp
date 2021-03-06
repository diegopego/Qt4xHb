/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractVideoSurface>

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

#include <QVideoSurfaceFormat>


HB_FUNC( QABSTRACTVIDEOSURFACE_DELETE )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
Error error () const
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_ERROR )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->error (  );
    hb_retni( i );
  }
}


/*
bool isActive () const
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_ISACTIVE )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isActive (  );
    hb_retl( b );
  }
}


/*
virtual bool isFormatSupported ( const QVideoSurfaceFormat & format ) const
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_ISFORMATSUPPORTED )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVideoSurfaceFormat * par1 = (QVideoSurfaceFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isFormatSupported ( *par1 );
    hb_retl( b );
  }
}


/*
virtual QVideoSurfaceFormat nearestFormat ( const QVideoSurfaceFormat & format ) const
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_NEARESTFORMAT )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVideoSurfaceFormat * par1 = (QVideoSurfaceFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVideoSurfaceFormat * ptr = new QVideoSurfaceFormat( obj->nearestFormat ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QVIDEOSURFACEFORMAT", true );  }
}


/*
virtual bool present ( const QVideoFrame & frame ) = 0
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_PRESENT )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVideoFrame * par1 = (QVideoFrame *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->present ( *par1 );
    hb_retl( b );
  }
}


/*
virtual bool start ( const QVideoSurfaceFormat & format )
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_START )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVideoSurfaceFormat * par1 = (QVideoSurfaceFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->start ( *par1 );
    hb_retl( b );
  }
}


/*
virtual void stop ()
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_STOP )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->stop (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats ( QAbstractVideoBuffer::HandleType type = QAbstractVideoBuffer::NoHandle ) const = 0
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_SUPPORTEDPIXELFORMATS )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QAbstractVideoBuffer::NoHandle : hb_parni(1);
    QList<QVideoFrame::PixelFormat> list = obj->supportedPixelFormats (  (QAbstractVideoBuffer::HandleType) par1 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutNI( NULL, (int) list[i] );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QVideoSurfaceFormat surfaceFormat () const
*/
HB_FUNC( QABSTRACTVIDEOSURFACE_SURFACEFORMAT )
{
  QAbstractVideoSurface * obj = (QAbstractVideoSurface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVideoSurfaceFormat * ptr = new QVideoSurfaceFormat( obj->surfaceFormat (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVIDEOSURFACEFORMAT", true );  }
}





