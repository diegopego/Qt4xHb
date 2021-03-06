/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QBuffer>

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
QBuffer ( QObject * parent = 0 )
*/
HB_FUNC( QBUFFER_NEW1 )
{
  QBuffer * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBuffer ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBuffer *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QBuffer ( QByteArray * byteArray, QObject * parent = 0 )
*/
HB_FUNC( QBUFFER_NEW2 )
{
  QBuffer * o = NULL;
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QBuffer ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QBuffer *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QBuffer ( QObject * parent = 0 )
//[2]QBuffer ( QByteArray * byteArray, QObject * parent = 0 )

HB_FUNC( QBUFFER_NEW )
{
  if( ISBETWEEN(0,1) && (ISQOBJECT(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QBUFFER_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQBYTEARRAY(1) && (ISQOBJECT(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBUFFER_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QBUFFER_DELETE )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QByteArray & buffer ()
*/
HB_FUNC( QBUFFER_BUFFER1 )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = &obj->buffer (  );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
const QByteArray & buffer () const
*/
HB_FUNC( QBUFFER_BUFFER2 )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QByteArray * ptr = &obj->buffer (  );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


//[1]QByteArray & buffer ()
//[2]const QByteArray & buffer () const

HB_FUNC( QBUFFER_BUFFER )
{
  HB_FUNC_EXEC( QBUFFER_BUFFER1 );
}

/*
const QByteArray & data () const
*/
HB_FUNC( QBUFFER_DATA )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QByteArray * ptr = &obj->data (  );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
void setBuffer ( QByteArray * byteArray )
*/
HB_FUNC( QBUFFER_SETBUFFER )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setBuffer ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setData ( const QByteArray & data )
*/
HB_FUNC( QBUFFER_SETDATA1 )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setData ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setData ( const char * data, int size )
*/
HB_FUNC( QBUFFER_SETDATA2 )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int par2 = hb_parni(2);
    obj->setData (  (const char *) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setData ( const QByteArray & data )
//[2]void setData ( const char * data, int size )

HB_FUNC( QBUFFER_SETDATA )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBUFFER_SETDATA1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBUFFER_SETDATA2 );
  }
}

/*
virtual bool atEnd () const
*/
HB_FUNC( QBUFFER_ATEND )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->atEnd (  );
    hb_retl( b );
  }
}


/*
virtual bool canReadLine () const
*/
HB_FUNC( QBUFFER_CANREADLINE )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->canReadLine (  );
    hb_retl( b );
  }
}


/*
virtual void close ()
*/
HB_FUNC( QBUFFER_CLOSE )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->close (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool open ( OpenMode flags )
*/
HB_FUNC( QBUFFER_OPEN )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->open (  (QBuffer::OpenMode) par1 );
    hb_retl( b );
  }
}


/*
virtual qint64 pos () const
*/
HB_FUNC( QBUFFER_POS )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->pos (  );
    hb_retni( i );
  }
}


/*
virtual bool seek ( qint64 pos )
*/
HB_FUNC( QBUFFER_SEEK )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 par1 = hb_parni(1);
    bool b = obj->seek ( par1 );
    hb_retl( b );
  }
}


/*
virtual qint64 size () const
*/
HB_FUNC( QBUFFER_SIZE )
{
  QBuffer * obj = (QBuffer *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->size (  );
    hb_retni( i );
  }
}




