/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QProcess>

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
QProcess ( QObject * parent = 0 )
*/
HB_FUNC( QPROCESS_NEW )
{
  QProcess * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QProcess ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QProcess *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QPROCESS_DELETE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void closeReadChannel ( ProcessChannel channel )
*/
HB_FUNC( QPROCESS_CLOSEREADCHANNEL )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->closeReadChannel (  (QProcess::ProcessChannel) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void closeWriteChannel ()
*/
HB_FUNC( QPROCESS_CLOSEWRITECHANNEL )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->closeWriteChannel (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QStringList environment () const (deprecated)
*/
HB_FUNC( QPROCESS_ENVIRONMENT )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->environment (  );
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
QProcess::ProcessError error () const
*/
HB_FUNC( QPROCESS_ERROR )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->error (  );
    hb_retni( i );
  }
}


/*
int exitCode () const
*/
HB_FUNC( QPROCESS_EXITCODE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->exitCode (  );
    hb_retni( i );
  }
}


/*
QProcess::ExitStatus exitStatus () const
*/
HB_FUNC( QPROCESS_EXITSTATUS )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->exitStatus (  );
    hb_retni( i );
  }
}


/*
QString nativeArguments () const
*/
HB_FUNC( QPROCESS_NATIVEARGUMENTS )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->nativeArguments (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}



/*
ProcessChannelMode processChannelMode () const
*/
HB_FUNC( QPROCESS_PROCESSCHANNELMODE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->processChannelMode (  );
    hb_retni( i );
  }
}


/*
QProcessEnvironment processEnvironment () const
*/
HB_FUNC( QPROCESS_PROCESSENVIRONMENT )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QProcessEnvironment * ptr = new QProcessEnvironment( obj->processEnvironment (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPROCESSENVIRONMENT", true );  }
}


/*
QByteArray readAllStandardError ()
*/
HB_FUNC( QPROCESS_READALLSTANDARDERROR )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->readAllStandardError (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray readAllStandardOutput ()
*/
HB_FUNC( QPROCESS_READALLSTANDARDOUTPUT )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->readAllStandardOutput (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
ProcessChannel readChannel () const
*/
HB_FUNC( QPROCESS_READCHANNEL )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->readChannel (  );
    hb_retni( i );
  }
}


/*
void setEnvironment ( const QStringList & environment ) (deprecated)
*/
HB_FUNC( QPROCESS_SETENVIRONMENT )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QStringList par1;
PHB_ITEM aStrings1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aStrings1);
for (i1=0;i1<nLen1;i1++)
{
QString temp = hb_arrayGetCPtr(aStrings1, i1+1);
par1 << temp;
}
    obj->setEnvironment ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNativeArguments ( const QString & arguments )
*/
HB_FUNC( QPROCESS_SETNATIVEARGUMENTS )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setNativeArguments ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setProcessChannelMode ( ProcessChannelMode mode )
*/
HB_FUNC( QPROCESS_SETPROCESSCHANNELMODE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setProcessChannelMode (  (QProcess::ProcessChannelMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setProcessEnvironment ( const QProcessEnvironment & environment )
*/
HB_FUNC( QPROCESS_SETPROCESSENVIRONMENT )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QProcessEnvironment * par1 = (QProcessEnvironment *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setProcessEnvironment ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setReadChannel ( ProcessChannel channel )
*/
HB_FUNC( QPROCESS_SETREADCHANNEL )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setReadChannel (  (QProcess::ProcessChannel) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStandardErrorFile ( const QString & fileName, OpenMode mode = Truncate )
*/
HB_FUNC( QPROCESS_SETSTANDARDERRORFILE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? (int) QIODevice::Truncate : hb_parni(2);
    obj->setStandardErrorFile ( par1,  (QIODevice::OpenMode) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStandardInputFile ( const QString & fileName )
*/
HB_FUNC( QPROCESS_SETSTANDARDINPUTFILE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setStandardInputFile ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStandardOutputFile ( const QString & fileName, OpenMode mode = Truncate )
*/
HB_FUNC( QPROCESS_SETSTANDARDOUTPUTFILE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? (int) QIODevice::Truncate : hb_parni(2);
    obj->setStandardOutputFile ( par1,  (QIODevice::OpenMode) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStandardOutputProcess ( QProcess * destination )
*/
HB_FUNC( QPROCESS_SETSTANDARDOUTPUTPROCESS )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QProcess * par1 = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setStandardOutputProcess ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWorkingDirectory ( const QString & dir )
*/
HB_FUNC( QPROCESS_SETWORKINGDIRECTORY )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setWorkingDirectory ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void start ( const QString & program, const QStringList & arguments, OpenMode mode = ReadWrite )
*/
HB_FUNC( QPROCESS_START1 )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
QStringList par2;
PHB_ITEM aStrings2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aStrings2);
for (i2=0;i2<nLen2;i2++)
{
QString temp = hb_arrayGetCPtr(aStrings2, i2+1);
par2 << temp;
}
    int par3 = ISNIL(3)? (int) QIODevice::ReadWrite : hb_parni(3);
    obj->start ( par1, par2,  (QIODevice::OpenMode) par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void start ( const QString & program, OpenMode mode = ReadWrite )
*/
HB_FUNC( QPROCESS_START2 )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? (int) QIODevice::ReadWrite : hb_parni(2);
    obj->start ( par1,  (QIODevice::OpenMode) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void start ( const QString & program, const QStringList & arguments, OpenMode mode = ReadWrite )
//[2]void start ( const QString & program, OpenMode mode = ReadWrite )

HB_FUNC( QPROCESS_START )
{
  if( ISBETWEEN(2,3) && ISCHAR(1) && ISARRAY(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QPROCESS_START1 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QPROCESS_START2 );
  }
}


/*
QProcess::ProcessState state () const
*/
HB_FUNC( QPROCESS_STATE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->state (  );
    hb_retni( i );
  }
}


/*
bool waitForFinished ( int msecs = 30000 )
*/
HB_FUNC( QPROCESS_WAITFORFINISHED )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? 30000 : hb_parni(1);
    bool b = obj->waitForFinished ( par1 );
    hb_retl( b );
  }
}


/*
bool waitForStarted ( int msecs = 30000 )
*/
HB_FUNC( QPROCESS_WAITFORSTARTED )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? 30000 : hb_parni(1);
    bool b = obj->waitForStarted ( par1 );
    hb_retl( b );
  }
}


/*
QString workingDirectory () const
*/
HB_FUNC( QPROCESS_WORKINGDIRECTORY )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->workingDirectory (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual bool atEnd () const
*/
HB_FUNC( QPROCESS_ATEND )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->atEnd (  );
    hb_retl( b );
  }
}


/*
virtual qint64 bytesAvailable () const
*/
HB_FUNC( QPROCESS_BYTESAVAILABLE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->bytesAvailable (  );
    hb_retni( i );
  }
}


/*
virtual qint64 bytesToWrite () const
*/
HB_FUNC( QPROCESS_BYTESTOWRITE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->bytesToWrite (  );
    hb_retni( i );
  }
}


/*
virtual bool canReadLine () const
*/
HB_FUNC( QPROCESS_CANREADLINE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->canReadLine (  );
    hb_retl( b );
  }
}


/*
virtual void close ()
*/
HB_FUNC( QPROCESS_CLOSE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->close (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool isSequential () const
*/
HB_FUNC( QPROCESS_ISSEQUENTIAL )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSequential (  );
    hb_retl( b );
  }
}


/*
virtual bool waitForBytesWritten ( int msecs = 30000 )
*/
HB_FUNC( QPROCESS_WAITFORBYTESWRITTEN )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? 30000 : hb_parni(1);
    bool b = obj->waitForBytesWritten ( par1 );
    hb_retl( b );
  }
}


/*
virtual bool waitForReadyRead ( int msecs = 30000 )
*/
HB_FUNC( QPROCESS_WAITFORREADYREAD )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? 30000 : hb_parni(1);
    bool b = obj->waitForReadyRead ( par1 );
    hb_retl( b );
  }
}


/*
void kill ()
*/
HB_FUNC( QPROCESS_KILL )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->kill (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void terminate ()
*/
HB_FUNC( QPROCESS_TERMINATE )
{
  QProcess * obj = (QProcess *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->terminate (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
int execute ( const QString & program, const QStringList & arguments )
*/
HB_FUNC( QPROCESS_EXECUTE1 )
{
  QString par1 = hb_parc(1);
QStringList par2;
PHB_ITEM aStrings2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aStrings2);
for (i2=0;i2<nLen2;i2++)
{
QString temp = hb_arrayGetCPtr(aStrings2, i2+1);
par2 << temp;
}
  int i = QProcess::execute ( par1, par2 );
  hb_retni( i );
}


/*
int execute ( const QString & program )
*/
HB_FUNC( QPROCESS_EXECUTE2 )
{
  QString par1 = hb_parc(1);
  int i = QProcess::execute ( par1 );
  hb_retni( i );
}


//[1]int execute ( const QString & program, const QStringList & arguments )
//[2]int execute ( const QString & program )

HB_FUNC( QPROCESS_EXECUTE )
{
  if( ISNUMPAR(2) && ISCHAR(1) && ISARRAY(2) )
  {
    HB_FUNC_EXEC( QPROCESS_EXECUTE1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QPROCESS_EXECUTE2 );
  }
}

/*
bool startDetached ( const QString & program, const QStringList & arguments, const QString & workingDirectory, qint64 * pid = 0 )
*/
HB_FUNC( QPROCESS_STARTDETACHED1 )
{
  QString par1 = hb_parc(1);
QStringList par2;
PHB_ITEM aStrings2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aStrings2);
for (i2=0;i2<nLen2;i2++)
{
QString temp = hb_arrayGetCPtr(aStrings2, i2+1);
par2 << temp;
}
  QString par3 = hb_parc(3);
  qint64 * par4 = (qint64 *) hb_itemGetPtr( hb_objSendMsg( hb_param(4, HB_IT_OBJECT ), "POINTER", 0 ) );
  bool b = QProcess::startDetached ( par1, par2, par3, par4 );
  hb_retl( b );
}


/*
bool startDetached ( const QString & program, const QStringList & arguments )
*/
HB_FUNC( QPROCESS_STARTDETACHED2 )
{
  QString par1 = hb_parc(1);
QStringList par2;
PHB_ITEM aStrings2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aStrings2);
for (i2=0;i2<nLen2;i2++)
{
QString temp = hb_arrayGetCPtr(aStrings2, i2+1);
par2 << temp;
}
  bool b = QProcess::startDetached ( par1, par2 );
  hb_retl( b );
}


/*
bool startDetached ( const QString & program )
*/
HB_FUNC( QPROCESS_STARTDETACHED3 )
{
  QString par1 = hb_parc(1);
  bool b = QProcess::startDetached ( par1 );
  hb_retl( b );
}


//[1]bool startDetached ( const QString & program, const QStringList & arguments, const QString & workingDirectory, qint64 * pid = 0 )
//[2]bool startDetached ( const QString & program, const QStringList & arguments )
//[3]bool startDetached ( const QString & program )

HB_FUNC( QPROCESS_STARTDETACHED )
{
  if( ISNUMPAR(4) && ISCHAR(1) && ISARRAY(2) && ISCHAR(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QPROCESS_STARTDETACHED1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISARRAY(2) )
  {
    HB_FUNC_EXEC( QPROCESS_STARTDETACHED2 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QPROCESS_STARTDETACHED3 );
  }
}

/*
QStringList systemEnvironment ()
*/
HB_FUNC( QPROCESS_SYSTEMENVIRONMENT )
{
  QStringList strl = QProcess::systemEnvironment (  );
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




