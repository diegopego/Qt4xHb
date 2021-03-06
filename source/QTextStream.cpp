/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTextStream>

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
QTextStream()
*/
HB_FUNC( QTEXTSTREAM_NEW1 )
{
  QTextStream * o = NULL;
  o = new QTextStream (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextStream *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QTextStream(QIODevice *device)
*/
HB_FUNC( QTEXTSTREAM_NEW2 )
{
  QTextStream * o = NULL;
  QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTextStream ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextStream *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QTextStream(FILE *fileHandle, QIODevice::OpenMode openMode = QIODevice::ReadWrite)
*/
HB_FUNC( QTEXTSTREAM_NEW3 )
{
  QTextStream * o = NULL;
  FILE * par1 = (FILE *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) QIODevice::ReadWrite : hb_parni(2);
  o = new QTextStream ( par1,  (QIODevice::OpenMode) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextStream *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QTextStream(QString *string, QIODevice::OpenMode openMode = QIODevice::ReadWrite)
*/
HB_FUNC( QTEXTSTREAM_NEW4 )
{
  QTextStream * o = NULL;
  QString * par1 = NULL;
  int par2 = ISNIL(2)? (int) QIODevice::ReadWrite : hb_parni(2);
  o = new QTextStream ( par1,  (QIODevice::OpenMode) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextStream *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}



/*
QTextStream(const QByteArray &array, QIODevice::OpenMode openMode = QIODevice::ReadOnly)
*/
HB_FUNC( QTEXTSTREAM_NEW6 )
{
  QTextStream * o = NULL;
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) QIODevice::ReadOnly : hb_parni(2);
  o = new QTextStream ( *par1,  (QIODevice::OpenMode) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextStream *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QTextStream()
//[2]QTextStream(QIODevice *device)
//[3]QTextStream(FILE *fileHandle, QIODevice::OpenMode openMode = QIODevice::ReadWrite)
//[4]QTextStream(QString *string, QIODevice::OpenMode openMode = QIODevice::ReadWrite)
//[5]QTextStream(QByteArray *array, QIODevice::OpenMode openMode = QIODevice::ReadWrite)
//[6]QTextStream(const QByteArray &array, QIODevice::OpenMode openMode = QIODevice::ReadOnly)

HB_FUNC( QTEXTSTREAM_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQIODEVICE(1) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_NEW2 );
  }
  else if( ISBETWEEN(1,2) && ISPOINTER(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_NEW3 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_NEW4 );
  }
  else if( ISBETWEEN(1,2) && ISQBYTEARRAY(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_NEW6 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QTEXTSTREAM_DELETE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void setCodec(QTextCodec *codec)
*/
HB_FUNC( QTEXTSTREAM_SETCODEC1 )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCodec * par1 = (QTextCodec *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCodec ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCodec(const char *codecName)
*/
HB_FUNC( QTEXTSTREAM_SETCODEC2 )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    obj->setCodec (  (const char *) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCodec(QTextCodec *codec)
//[2]void setCodec(const char *codecName)

HB_FUNC( QTEXTSTREAM_SETCODEC )
{
  if( ISNUMPAR(1) && ISQTEXTCODEC(1) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_SETCODEC1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QTEXTSTREAM_SETCODEC2 );
  }
}

/*
QTextCodec *codec() const
*/
HB_FUNC( QTEXTSTREAM_CODEC )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCodec * ptr = obj->codec (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCODEC" );  }
}


/*
void setAutoDetectUnicode(bool enabled)
*/
HB_FUNC( QTEXTSTREAM_SETAUTODETECTUNICODE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoDetectUnicode ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool autoDetectUnicode() const
*/
HB_FUNC( QTEXTSTREAM_AUTODETECTUNICODE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoDetectUnicode (  );
    hb_retl( b );
  }
}


/*
void setGenerateByteOrderMark(bool generate)
*/
HB_FUNC( QTEXTSTREAM_SETGENERATEBYTEORDERMARK )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setGenerateByteOrderMark ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool generateByteOrderMark() const
*/
HB_FUNC( QTEXTSTREAM_GENERATEBYTEORDERMARK )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->generateByteOrderMark (  );
    hb_retl( b );
  }
}


/*
void setLocale(const QLocale &locale)
*/
HB_FUNC( QTEXTSTREAM_SETLOCALE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLocale * par1 = (QLocale *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setLocale ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QLocale locale() const
*/
HB_FUNC( QTEXTSTREAM_LOCALE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLocale * ptr = new QLocale( obj->locale (  ) );
    _qt4xhb_createReturnClass ( ptr, "QLOCALE" );  }
}


/*
void setDevice(QIODevice *device)
*/
HB_FUNC( QTEXTSTREAM_SETDEVICE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDevice ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QIODevice *device() const
*/
HB_FUNC( QTEXTSTREAM_DEVICE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * ptr = obj->device (  );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
void setString(QString *string, QIODevice::OpenMode openMode = QIODevice::ReadWrite)
*/
HB_FUNC( QTEXTSTREAM_SETSTRING )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString * par1 = NULL;
    int par2 = ISNIL(2)? (int) QIODevice::ReadWrite : hb_parni(2);
    obj->setString ( par1,  (QIODevice::OpenMode) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString *string() const
*/
HB_FUNC( QTEXTSTREAM_STRING )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString * ptr = obj->string (  );
    _qt4xhb_createReturnClass ( ptr, "QSTRING" );  }
}


/*
Status status() const
*/
HB_FUNC( QTEXTSTREAM_STATUS )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->status (  );
    hb_retni( i );
  }
}


/*
void setStatus(Status status)
*/
HB_FUNC( QTEXTSTREAM_SETSTATUS )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setStatus (  (QTextStream::Status) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resetStatus()
*/
HB_FUNC( QTEXTSTREAM_RESETSTATUS )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->resetStatus (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool atEnd() const
*/
HB_FUNC( QTEXTSTREAM_ATEND )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->atEnd (  );
    hb_retl( b );
  }
}


/*
void reset()
*/
HB_FUNC( QTEXTSTREAM_RESET )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->reset (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void flush()
*/
HB_FUNC( QTEXTSTREAM_FLUSH )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->flush (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool seek(qint64 pos)
*/
HB_FUNC( QTEXTSTREAM_SEEK )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 par1 = hb_parni(1);
    bool b = obj->seek ( par1 );
    hb_retl( b );
  }
}


/*
qint64 pos() const
*/
HB_FUNC( QTEXTSTREAM_POS )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->pos (  );
    hb_retni( i );
  }
}


/*
void skipWhiteSpace()
*/
HB_FUNC( QTEXTSTREAM_SKIPWHITESPACE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->skipWhiteSpace (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString readLine(qint64 maxlen = 0)
*/
HB_FUNC( QTEXTSTREAM_READLINE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 par1 = ISNIL(1)? 0 : hb_parni(1);
    QString str1 = obj->readLine ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString readAll()
*/
HB_FUNC( QTEXTSTREAM_READALL )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->readAll (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString read(qint64 maxlen)
*/
HB_FUNC( QTEXTSTREAM_READ )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 par1 = hb_parni(1);
    QString str1 = obj->read ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setFieldAlignment(FieldAlignment alignment)
*/
HB_FUNC( QTEXTSTREAM_SETFIELDALIGNMENT )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFieldAlignment (  (QTextStream::FieldAlignment) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
FieldAlignment fieldAlignment() const
*/
HB_FUNC( QTEXTSTREAM_FIELDALIGNMENT )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->fieldAlignment (  );
    hb_retni( i );
  }
}


/*
void setPadChar(QChar ch)
*/
HB_FUNC( QTEXTSTREAM_SETPADCHAR )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * par1 = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPadChar ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QChar padChar() const
*/
HB_FUNC( QTEXTSTREAM_PADCHAR )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * ptr = new QChar( obj->padChar (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}


/*
void setFieldWidth(int width)
*/
HB_FUNC( QTEXTSTREAM_SETFIELDWIDTH )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFieldWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int fieldWidth() const
*/
HB_FUNC( QTEXTSTREAM_FIELDWIDTH )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->fieldWidth (  );
    hb_retni( i );
  }
}


/*
void setNumberFlags(NumberFlags flags)
*/
HB_FUNC( QTEXTSTREAM_SETNUMBERFLAGS )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setNumberFlags (  (QTextStream::NumberFlags) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
NumberFlags numberFlags() const
*/
HB_FUNC( QTEXTSTREAM_NUMBERFLAGS )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->numberFlags (  );
    hb_retni( i );
  }
}


/*
void setIntegerBase(int base)
*/
HB_FUNC( QTEXTSTREAM_SETINTEGERBASE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setIntegerBase ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int integerBase() const
*/
HB_FUNC( QTEXTSTREAM_INTEGERBASE )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->integerBase (  );
    hb_retni( i );
  }
}


/*
void setRealNumberNotation(RealNumberNotation notation)
*/
HB_FUNC( QTEXTSTREAM_SETREALNUMBERNOTATION )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setRealNumberNotation (  (QTextStream::RealNumberNotation) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
RealNumberNotation realNumberNotation() const
*/
HB_FUNC( QTEXTSTREAM_REALNUMBERNOTATION )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->realNumberNotation (  );
    hb_retni( i );
  }
}


/*
void setRealNumberPrecision(int precision)
*/
HB_FUNC( QTEXTSTREAM_SETREALNUMBERPRECISION )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setRealNumberPrecision ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int realNumberPrecision() const
*/
HB_FUNC( QTEXTSTREAM_REALNUMBERPRECISION )
{
  QTextStream * obj = (QTextStream *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->realNumberPrecision (  );
    hb_retni( i );
  }
}




