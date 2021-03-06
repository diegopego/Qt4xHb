/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAudioFormat>

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
QAudioFormat ()
*/
HB_FUNC( QAUDIOFORMAT_NEW1 )
{
  QAudioFormat * o = NULL;
  o = new QAudioFormat (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QAudioFormat *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QAudioFormat ( const QAudioFormat & other )
*/
HB_FUNC( QAUDIOFORMAT_NEW2 )
{
  QAudioFormat * o = NULL;
  QAudioFormat * par1 = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QAudioFormat ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QAudioFormat *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QAudioFormat ()
//[2]QAudioFormat ( const QAudioFormat & other )

HB_FUNC( QAUDIOFORMAT_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QAUDIOFORMAT_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQAUDIOFORMAT(1) )
  {
    HB_FUNC_EXEC( QAUDIOFORMAT_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QAUDIOFORMAT_DELETE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool isValid () const
*/
HB_FUNC( QAUDIOFORMAT_ISVALID )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
void setFrequency(int frequency)
*/
HB_FUNC( QAUDIOFORMAT_SETFREQUENCY )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFrequency ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int frequency() const
*/
HB_FUNC( QAUDIOFORMAT_FREQUENCY )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->frequency (  );
    hb_retni( i );
  }
}


/*
void setSampleRate ( int samplerate )
*/
HB_FUNC( QAUDIOFORMAT_SETSAMPLERATE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSampleRate ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int sampleRate () const
*/
HB_FUNC( QAUDIOFORMAT_SAMPLERATE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->sampleRate (  );
    hb_retni( i );
  }
}


/*
void setChannels(int channels)
*/
HB_FUNC( QAUDIOFORMAT_SETCHANNELS )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setChannels ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int channels() const
*/
HB_FUNC( QAUDIOFORMAT_CHANNELS )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->channels (  );
    hb_retni( i );
  }
}


/*
void setChannelCount(int channelCount)
*/
HB_FUNC( QAUDIOFORMAT_SETCHANNELCOUNT )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setChannelCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int channelCount() const
*/
HB_FUNC( QAUDIOFORMAT_CHANNELCOUNT )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->channelCount (  );
    hb_retni( i );
  }
}


/*
void setSampleSize ( int sampleSize )
*/
HB_FUNC( QAUDIOFORMAT_SETSAMPLESIZE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSampleSize ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int sampleSize () const
*/
HB_FUNC( QAUDIOFORMAT_SAMPLESIZE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->sampleSize (  );
    hb_retni( i );
  }
}


/*
void setCodec ( const QString & codec )
*/
HB_FUNC( QAUDIOFORMAT_SETCODEC )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setCodec ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString codec () const
*/
HB_FUNC( QAUDIOFORMAT_CODEC )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->codec (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setByteOrder ( QAudioFormat::Endian byteOrder )
*/
HB_FUNC( QAUDIOFORMAT_SETBYTEORDER )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setByteOrder (  (QAudioFormat::Endian) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QAudioFormat::Endian byteOrder () const
*/
HB_FUNC( QAUDIOFORMAT_BYTEORDER )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->byteOrder (  );
    hb_retni( i );
  }
}


/*
QAudioFormat::SampleType sampleType () const
*/
HB_FUNC( QAUDIOFORMAT_SAMPLETYPE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->sampleType (  );
    hb_retni( i );
  }
}


/*
void setSampleType ( QAudioFormat::SampleType sampleType )
*/
HB_FUNC( QAUDIOFORMAT_SETSAMPLETYPE )
{
  QAudioFormat * obj = (QAudioFormat *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setSampleType (  (QAudioFormat::SampleType) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




