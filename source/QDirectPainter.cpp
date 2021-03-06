/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDirectPainter>

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
QDirectPainter ( QObject * parent = 0, SurfaceFlag flag = NonReserved )
*/
HB_FUNC( QDIRECTPAINTER_NEW )
{
  QDirectPainter * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) QDirectPainter::NonReserved : hb_parni(2);
  o = new QDirectPainter ( par1,  (QDirectPainter::SurfaceFlag) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDirectPainter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QDIRECTPAINTER_DELETE )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QRegion allocatedRegion () const
*/
HB_FUNC( QDIRECTPAINTER_ALLOCATEDREGION )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * ptr = new QRegion( obj->allocatedRegion (  ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
void endPainting ()
*/
HB_FUNC( QDIRECTPAINTER_ENDPAINTING1 )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->endPainting (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void endPainting ( const QRegion & region )
*/
HB_FUNC( QDIRECTPAINTER_ENDPAINTING2 )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->endPainting ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void endPainting ()
//[2]void endPainting ( const QRegion & region )

HB_FUNC( QDIRECTPAINTER_ENDPAINTING )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QDIRECTPAINTER_ENDPAINTING1 );
  }
  else if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QDIRECTPAINTER_ENDPAINTING2 );
  }
}

/*
void flush ( const QRegion & region )
*/
HB_FUNC( QDIRECTPAINTER_FLUSH )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->flush ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QRect geometry () const
*/
HB_FUNC( QDIRECTPAINTER_GEOMETRY )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->geometry (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
void lower ()
*/
HB_FUNC( QDIRECTPAINTER_LOWER )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->lower (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void raise ()
*/
HB_FUNC( QDIRECTPAINTER_RAISE )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->raise (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void regionChanged ( const QRegion & newRegion )
*/
HB_FUNC( QDIRECTPAINTER_REGIONCHANGED )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->regionChanged ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QRegion requestedRegion () const
*/
HB_FUNC( QDIRECTPAINTER_REQUESTEDREGION )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * ptr = new QRegion( obj->requestedRegion (  ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
void setGeometry ( const QRect & rectangle )
*/
HB_FUNC( QDIRECTPAINTER_SETGEOMETRY )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGeometry ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRegion ( const QRegion & region )
*/
HB_FUNC( QDIRECTPAINTER_SETREGION )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setRegion ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void startPainting ( bool lockDisplay = true )
*/
HB_FUNC( QDIRECTPAINTER_STARTPAINTING )
{
  QDirectPainter * obj = (QDirectPainter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = ISNIL(1)? true : hb_parl(1);
    obj->startPainting ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




/*
uchar * frameBuffer ()
*/
HB_FUNC( QDIRECTPAINTER_FRAMEBUFFER )
{
  uchar * ptr = QDirectPainter::frameBuffer (  );
  _qt4xhb_createReturnClass ( ptr, "UCHAR" );}


/*
int linestep ()
*/
HB_FUNC( QDIRECTPAINTER_LINESTEP )
{
  int i = QDirectPainter::linestep (  );
  hb_retni( i );
}


/*
void lock ()
*/
HB_FUNC( QDIRECTPAINTER_LOCK )
{
  QDirectPainter::lock (  );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int screenDepth ()
*/
HB_FUNC( QDIRECTPAINTER_SCREENDEPTH )
{
  int i = QDirectPainter::screenDepth (  );
  hb_retni( i );
}


/*
int screenHeight ()
*/
HB_FUNC( QDIRECTPAINTER_SCREENHEIGHT )
{
  int i = QDirectPainter::screenHeight (  );
  hb_retni( i );
}


/*
int screenWidth ()
*/
HB_FUNC( QDIRECTPAINTER_SCREENWIDTH )
{
  int i = QDirectPainter::screenWidth (  );
  hb_retni( i );
}


/*
void unlock ()
*/
HB_FUNC( QDIRECTPAINTER_UNLOCK )
{
  QDirectPainter::unlock (  );
  hb_itemReturn( hb_stackSelfItem() );
}



