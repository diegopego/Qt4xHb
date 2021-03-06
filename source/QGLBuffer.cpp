/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGLBuffer>

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
QGLBuffer ()
*/
HB_FUNC( QGLBUFFER_NEW1 )
{
  QGLBuffer * o = NULL;
  o = new QGLBuffer (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGLBuffer *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QGLBuffer ( QGLBuffer::Type type )
*/
HB_FUNC( QGLBUFFER_NEW2 )
{
  QGLBuffer * o = NULL;
  int par1 = hb_parni(1);
  o = new QGLBuffer (  (QGLBuffer::Type) par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGLBuffer *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QGLBuffer ( const QGLBuffer & other )
*/
HB_FUNC( QGLBUFFER_NEW3 )
{
  QGLBuffer * o = NULL;
  QGLBuffer * par1 = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGLBuffer ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGLBuffer *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QGLBuffer ()
//[2]QGLBuffer ( QGLBuffer::Type type )
//[3]QGLBuffer ( const QGLBuffer & other )

HB_FUNC( QGLBUFFER_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QGLBUFFER_NEW1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QGLBUFFER_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQGLBUFFER(1) )
  {
    HB_FUNC_EXEC( QGLBUFFER_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QGLBUFFER_DELETE )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void allocate ( const void * data, int count )
*/
HB_FUNC( QGLBUFFER_ALLOCATE1 )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const void * par1 = (const void *) hb_parptr(1);
    int par2 = hb_parni(2);
    obj->allocate ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void allocate ( int count )
*/
HB_FUNC( QGLBUFFER_ALLOCATE2 )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->allocate ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void allocate ( const void * data, int count )
//[2]void allocate ( int count )

HB_FUNC( QGLBUFFER_ALLOCATE )
{
  if( ISNUMPAR(2) && ISPOINTER(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGLBUFFER_ALLOCATE1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QGLBUFFER_ALLOCATE2 );
  }
}

/*
bool bind ()
*/
HB_FUNC( QGLBUFFER_BIND )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->bind (  );
    hb_retl( b );
  }
}


/*
GLuint bufferId () const
*/
HB_FUNC( QGLBUFFER_BUFFERID )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    GLuint i = obj->bufferId (  );
    hb_retni( i );
  }
}


/*
bool create ()
*/
HB_FUNC( QGLBUFFER_CREATE )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->create (  );
    hb_retl( b );
  }
}


/*
void destroy ()
*/
HB_FUNC( QGLBUFFER_DESTROY )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->destroy (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isCreated () const
*/
HB_FUNC( QGLBUFFER_ISCREATED )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isCreated (  );
    hb_retl( b );
  }
}


/*
void * map ( QGLBuffer::Access access )
*/
HB_FUNC( QGLBUFFER_MAP )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    void * retptr = obj->map (  (QGLBuffer::Access) par1 );
  hb_retptr( (void *) retptr );
  }
}


/*
bool read ( int offset, void * data, int count )
*/
HB_FUNC( QGLBUFFER_READ )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    void * par2 = (void *) hb_parptr(2);
    int par3 = hb_parni(3);
    bool b = obj->read ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
void release ()
*/
HB_FUNC( QGLBUFFER_RELEASE1 )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->release (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUsagePattern ( QGLBuffer::UsagePattern value )
*/
HB_FUNC( QGLBUFFER_SETUSAGEPATTERN )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setUsagePattern (  (QGLBuffer::UsagePattern) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int size () const
*/
HB_FUNC( QGLBUFFER_SIZE )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->size (  );
    hb_retni( i );
  }
}


/*
QGLBuffer::Type type () const
*/
HB_FUNC( QGLBUFFER_TYPE )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->type (  );
    hb_retni( i );
  }
}


/*
bool unmap ()
*/
HB_FUNC( QGLBUFFER_UNMAP )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->unmap (  );
    hb_retl( b );
  }
}


/*
QGLBuffer::UsagePattern usagePattern () const
*/
HB_FUNC( QGLBUFFER_USAGEPATTERN )
{
  QGLBuffer * obj = (QGLBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->usagePattern (  );
    hb_retni( i );
  }
}




/*
void release ( QGLBuffer::Type type )
*/
HB_FUNC( QGLBUFFER_RELEASE2 )
{
  int par1 = hb_parni(1);
  QGLBuffer::release (  (QGLBuffer::Type) par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void release ()
//[2]void release ( QGLBuffer::Type type )

HB_FUNC( QGLBUFFER_RELEASE )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QGLBUFFER_RELEASE1 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QGLBUFFER_RELEASE2 );
  }
}


