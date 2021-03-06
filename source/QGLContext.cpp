/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGLContext>

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
QGLContext ( const QGLFormat & format )
*/
HB_FUNC( QGLCONTEXT_NEW )
{
  QGLContext * o = NULL;
  QGLFormat * par1 = (QGLFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGLContext ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGLContext *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QGLCONTEXT_DELETE )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
GLuint bindTexture ( const QImage & image, GLenum target, GLint format, BindOptions options )
*/
HB_FUNC( QGLCONTEXT_BINDTEXTURE1 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    GLenum par2 = hb_parni(2);
    int par4 = hb_parni(4);
    GLuint i = obj->bindTexture ( *par1, par2,  (QGLContext::BindOptions) par4 );
    hb_retni( i );
  }
}


/*
GLuint bindTexture ( const QString & fileName )
*/
HB_FUNC( QGLCONTEXT_BINDTEXTURE2 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    GLuint i = obj->bindTexture ( par1 );
    hb_retni( i );
  }
}


/*
GLuint bindTexture ( const QImage & image, GLenum target = GL_TEXTURE_2D, GLint format = GL_RGBA )
*/
HB_FUNC( QGLCONTEXT_BINDTEXTURE3 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QImage * par1 = (QImage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    GLenum par2 = ISNIL(2)? GL_TEXTURE_2D : hb_parni(2);
    GLint par3 = ISNIL(3)? GL_RGBA : hb_parni(3);
    GLuint i = obj->bindTexture ( *par1, par2, par3 );
    hb_retni( i );
  }
}


/*
GLuint bindTexture ( const QPixmap & pixmap, GLenum target = GL_TEXTURE_2D, GLint format = GL_RGBA )
*/
HB_FUNC( QGLCONTEXT_BINDTEXTURE4 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    GLenum par2 = ISNIL(2)? GL_TEXTURE_2D : hb_parni(2);
    GLint par3 = ISNIL(3)? GL_RGBA : hb_parni(3);
    GLuint i = obj->bindTexture ( *par1, par2, par3 );
    hb_retni( i );
  }
}


/*
GLuint bindTexture ( const QPixmap & pixmap, GLenum target, GLint format, BindOptions options )
*/
HB_FUNC( QGLCONTEXT_BINDTEXTURE5 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPixmap * par1 = (QPixmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    GLenum par2 = hb_parni(2);
    GLint par3 = hb_parni(3);
    int par4 = hb_parni(4);
    GLuint i = obj->bindTexture ( *par1, par2, par3,  (QGLContext::BindOptions) par4 );
    hb_retni( i );
  }
}


//[1]GLuint bindTexture ( const QImage & image, GLenum target, GLint format, BindOptions options )
//[2]GLuint bindTexture ( const QString & fileName )
//[3]GLuint bindTexture ( const QImage & image, GLenum target = GL_TEXTURE_2D, GLint format = GL_RGBA )
//[4]GLuint bindTexture ( const QPixmap & pixmap, GLenum target = GL_TEXTURE_2D, GLint format = GL_RGBA )
//[5]GLuint bindTexture ( const QPixmap & pixmap, GLenum target, GLint format, BindOptions options )

HB_FUNC( QGLCONTEXT_BINDTEXTURE )
{
  if( ISNUMPAR(4) && ISQIMAGE(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_BINDTEXTURE1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_BINDTEXTURE2 );
  }
  else if( ISBETWEEN(1,3) && ISQIMAGE(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_BINDTEXTURE3 );
  }
  else if( ISBETWEEN(1,3) && ISQPIXMAP(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_BINDTEXTURE4 );
  }
  else if( ISNUMPAR(4) && ISQPIXMAP(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_BINDTEXTURE5 );
  }
}

/*
virtual bool create ( const QGLContext * shareContext = 0 )
*/
HB_FUNC( QGLCONTEXT_CREATE )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGLContext * par1 = ISNIL(1)? 0 : (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->create ( par1 );
    hb_retl( b );
  }
}


/*
void deleteTexture ( GLuint id )
*/
HB_FUNC( QGLCONTEXT_DELETETEXTURE )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    GLuint par1 = hb_parni(1);
    obj->deleteTexture ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QPaintDevice * device () const
*/
HB_FUNC( QGLCONTEXT_DEVICE )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPaintDevice * ptr = obj->device (  );
    _qt4xhb_createReturnClass ( ptr, "QPAINTDEVICE" );  }
}


/*
virtual void doneCurrent ()
*/
HB_FUNC( QGLCONTEXT_DONECURRENT )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->doneCurrent (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void drawTexture ( const QRectF & target, GLuint textureId, GLenum textureTarget = GL_TEXTURE_2D )
*/
HB_FUNC( QGLCONTEXT_DRAWTEXTURE1 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    GLuint par2 = hb_parni(2);
    GLenum par3 = ISNIL(3)? GL_TEXTURE_2D : hb_parni(3);
    obj->drawTexture ( *par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void drawTexture ( const QPointF & point, GLuint textureId, GLenum textureTarget = GL_TEXTURE_2D )
*/
HB_FUNC( QGLCONTEXT_DRAWTEXTURE2 )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    GLuint par2 = hb_parni(2);
    GLenum par3 = ISNIL(3)? GL_TEXTURE_2D : hb_parni(3);
    obj->drawTexture ( *par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void drawTexture ( const QRectF & target, GLuint textureId, GLenum textureTarget = GL_TEXTURE_2D )
//[2]void drawTexture ( const QPointF & point, GLuint textureId, GLenum textureTarget = GL_TEXTURE_2D )

HB_FUNC( QGLCONTEXT_DRAWTEXTURE )
{
  if( ISBETWEEN(2,3) && ISQRECTF(1) && ISNUM(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_DRAWTEXTURE1 );
  }
  else if( ISBETWEEN(2,3) && ISQPOINTF(1) && ISNUM(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QGLCONTEXT_DRAWTEXTURE2 );
  }
}

/*
QGLFormat format () const
*/
HB_FUNC( QGLCONTEXT_FORMAT )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGLFormat * ptr = new QGLFormat( obj->format (  ) );
    _qt4xhb_createReturnClass ( ptr, "QGLFORMAT" );  }
}


/*
void * getProcAddress ( const QString & proc ) const
*/
HB_FUNC( QGLCONTEXT_GETPROCADDRESS )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    void * retptr = obj->getProcAddress ( par1 );
  hb_retptr( (void *) retptr );
  }
}


/*
bool isSharing () const
*/
HB_FUNC( QGLCONTEXT_ISSHARING )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSharing (  );
    hb_retl( b );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QGLCONTEXT_ISVALID )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
virtual void makeCurrent ()
*/
HB_FUNC( QGLCONTEXT_MAKECURRENT )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->makeCurrent (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QColor overlayTransparentColor () const
*/
HB_FUNC( QGLCONTEXT_OVERLAYTRANSPARENTCOLOR )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QColor * ptr = new QColor( obj->overlayTransparentColor (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCOLOR", true );  }
}


/*
QGLFormat requestedFormat () const
*/
HB_FUNC( QGLCONTEXT_REQUESTEDFORMAT )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGLFormat * ptr = new QGLFormat( obj->requestedFormat (  ) );
    _qt4xhb_createReturnClass ( ptr, "QGLFORMAT" );  }
}


/*
void reset ()
*/
HB_FUNC( QGLCONTEXT_RESET )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->reset (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFormat ( const QGLFormat & format )
*/
HB_FUNC( QGLCONTEXT_SETFORMAT )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGLFormat * par1 = (QGLFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFormat ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void swapBuffers () const
*/
HB_FUNC( QGLCONTEXT_SWAPBUFFERS )
{
  QGLContext * obj = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->swapBuffers (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
bool areSharing ( const QGLContext * context1, const QGLContext * context2 )
*/
HB_FUNC( QGLCONTEXT_ARESHARING )
{
  QGLContext * par1 = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QGLContext * par2 = (QGLContext *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  bool b = QGLContext::areSharing ( par1, par2 );
  hb_retl( b );
}


/*
const QGLContext * currentContext ()
*/
HB_FUNC( QGLCONTEXT_CURRENTCONTEXT )
{
  const QGLContext * ptr = QGLContext::currentContext (  );
  _qt4xhb_createReturnClass ( ptr, "QGLCONTEXT" );}


/*
void setTextureCacheLimit ( int size )
*/
HB_FUNC( QGLCONTEXT_SETTEXTURECACHELIMIT )
{
  int par1 = hb_parni(1);
  QGLContext::setTextureCacheLimit ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int textureCacheLimit ()
*/
HB_FUNC( QGLCONTEXT_TEXTURECACHELIMIT )
{
  int i = QGLContext::textureCacheLimit (  );
  hb_retni( i );
}



