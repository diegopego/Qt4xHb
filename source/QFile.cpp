/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFile>

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
QFile ( const QString & name )
*/
HB_FUNC( QFILE_NEW1 )
{
  QFile * o = NULL;
  QString par1 = hb_parc(1);
  o = new QFile ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFile *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QFile ( QObject * parent )
*/
HB_FUNC( QFILE_NEW2 )
{
  QFile * o = NULL;
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFile ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFile *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QFile ( const QString & name, QObject * parent )
*/
HB_FUNC( QFILE_NEW3 )
{
  QFile * o = NULL;
  QString par1 = hb_parc(1);
  QObject * par2 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFile ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFile *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QFile ( const QString & name )
//[2]QFile ( QObject * parent )
//[3]QFile ( const QString & name, QObject * parent )

HB_FUNC( QFILE_NEW )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQOBJECT(1) )
  {
    HB_FUNC_EXEC( QFILE_NEW2 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISQOBJECT(2) )
  {
    HB_FUNC_EXEC( QFILE_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QFILE_DELETE )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool copy ( const QString & newName )
*/
HB_FUNC( QFILE_COPY1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->copy ( par1 );
    hb_retl( b );
  }
}


/*
FileError error () const
*/
HB_FUNC( QFILE_ERROR )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->error (  );
    hb_retni( i );
  }
}


/*
bool exists () const
*/
HB_FUNC( QFILE_EXISTS1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->exists (  );
    hb_retl( b );
  }
}


/*
QString fileName () const
*/
HB_FUNC( QFILE_FILENAME )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->fileName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool flush ()
*/
HB_FUNC( QFILE_FLUSH )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->flush (  );
    hb_retl( b );
  }
}


/*
int handle () const
*/
HB_FUNC( QFILE_HANDLE )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->handle (  );
    hb_retni( i );
  }
}


/*
bool link ( const QString & linkName )
*/
HB_FUNC( QFILE_LINK1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->link ( par1 );
    hb_retl( b );
  }
}



/*
bool open ( FILE * fh, OpenMode mode )
*/
HB_FUNC( QFILE_OPEN1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    FILE * par1 = (FILE *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    bool b = obj->open ( par1,  (QFile::OpenMode) par2 );
    hb_retl( b );
  }
}


/*
bool open ( FILE * fh, OpenMode mode, FileHandleFlags handleFlags )
*/
HB_FUNC( QFILE_OPEN2 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    FILE * par1 = (FILE *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    bool b = obj->open ( par1,  (QFile::OpenMode) par2,  (QFile::FileHandleFlags) par3 );
    hb_retl( b );
  }
}


/*
bool open ( int fd, OpenMode mode )
*/
HB_FUNC( QFILE_OPEN3 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    bool b = obj->open ( par1,  (QFile::OpenMode) par2 );
    hb_retl( b );
  }
}


/*
bool open ( int fd, OpenMode mode, FileHandleFlags handleFlags )
*/
HB_FUNC( QFILE_OPEN4 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    bool b = obj->open ( par1,  (QFile::OpenMode) par2,  (QFile::FileHandleFlags) par3 );
    hb_retl( b );
  }
}



/*
Permissions permissions () const
*/
HB_FUNC( QFILE_PERMISSIONS1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->permissions (  );
    hb_retni( i );
  }
}


/*
bool remove ()
*/
HB_FUNC( QFILE_REMOVE1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->remove (  );
    hb_retl( b );
  }
}


/*
bool rename ( const QString & newName )
*/
HB_FUNC( QFILE_RENAME1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->rename ( par1 );
    hb_retl( b );
  }
}


/*
bool resize ( qint64 sz )
*/
HB_FUNC( QFILE_RESIZE1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 par1 = hb_parni(1);
    bool b = obj->resize ( par1 );
    hb_retl( b );
  }
}


/*
void setFileName ( const QString & name )
*/
HB_FUNC( QFILE_SETFILENAME )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setFileName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool setPermissions ( Permissions permissions )
*/
HB_FUNC( QFILE_SETPERMISSIONS1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->setPermissions (  (QFile::Permissions) par1 );
    hb_retl( b );
  }
}


/*
QString symLinkTarget () const
*/
HB_FUNC( QFILE_SYMLINKTARGET1 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->symLinkTarget (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool unmap ( uchar * address )
*/
HB_FUNC( QFILE_UNMAP )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    uchar * par1 = (uchar *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->unmap ( par1 );
    hb_retl( b );
  }
}


/*
void unsetError ()
*/
HB_FUNC( QFILE_UNSETERROR )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unsetError (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


// Reimplemented Public Functions

/*
virtual bool atEnd () const
*/
HB_FUNC( QFILE_ATEND )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->atEnd (  );
    hb_retl( b );
  }
}


/*
virtual void close ()
*/
HB_FUNC( QFILE_CLOSE )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->close (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool isSequential () const
*/
HB_FUNC( QFILE_ISSEQUENTIAL )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSequential (  );
    hb_retl( b );
  }
}


/*
virtual bool open ( OpenMode mode )
*/
HB_FUNC( QFILE_OPEN6 )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->open (  (QFile::OpenMode) par1 );
    hb_retl( b );
  }
}


//[1]bool open ( FILE * fh, OpenMode mode )
//[2]bool open ( FILE * fh, OpenMode mode, FileHandleFlags handleFlags )
//[3]bool open ( int fd, OpenMode mode )
//[4]bool open ( int fd, OpenMode mode, FileHandleFlags handleFlags )
//[5]bool open ( const RFile & f, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle )
//[6]virtual bool open ( OpenMode mode )

HB_FUNC( QFILE_OPEN )
{
  HB_FUNC_EXEC( QFILE_OPEN6 );
}

/*
virtual qint64 pos () const
*/
HB_FUNC( QFILE_POS )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->pos (  );
    hb_retni( i );
  }
}


/*
virtual bool seek ( qint64 pos )
*/
HB_FUNC( QFILE_SEEK )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
HB_FUNC( QFILE_SIZE )
{
  QFile * obj = (QFile *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qint64 i = obj->size (  );
    hb_retni( i );
  }
}



// Static Public Members

/*
bool copy ( const QString & fileName, const QString & newName )
*/
HB_FUNC( QFILE_COPY2 )
{
  QString par1 = hb_parc(1);
  QString par2 = hb_parc(2);
  bool b = QFile::copy ( par1, par2 );
  hb_retl( b );
}


//[1]bool copy ( const QString & newName )
//[2]bool copy ( const QString & fileName, const QString & newName )

HB_FUNC( QFILE_COPY )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_COPY1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QFILE_COPY2 );
  }
}

/*
QString decodeName ( const QByteArray & localFileName )
*/
HB_FUNC( QFILE_DECODENAME1 )
{
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString str1 = QFile::decodeName ( *par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString decodeName ( const char * localFileName )
*/
HB_FUNC( QFILE_DECODENAME2 )
{
  const char * par1 = hb_parc(1);
  QString str1 = QFile::decodeName (  (const char *) par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString decodeName ( const QByteArray & localFileName )
//[2]QString decodeName ( const char * localFileName )

HB_FUNC( QFILE_DECODENAME )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QFILE_DECODENAME1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_DECODENAME2 );
  }
}

/*
QByteArray encodeName ( const QString & fileName )
*/
HB_FUNC( QFILE_ENCODENAME )
{
  QString par1 = hb_parc(1);
  QByteArray * ptr = new QByteArray( QFile::encodeName ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
bool exists ( const QString & fileName )
*/
HB_FUNC( QFILE_EXISTS2 )
{
  QString par1 = hb_parc(1);
  bool b = QFile::exists ( par1 );
  hb_retl( b );
}


//[1]bool exists () const
//[2]bool exists ( const QString & fileName )

HB_FUNC( QFILE_EXISTS )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QFILE_EXISTS1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_EXISTS2 );
  }
}

/*
bool link ( const QString & fileName, const QString & linkName )
*/
HB_FUNC( QFILE_LINK2 )
{
  QString par1 = hb_parc(1);
  QString par2 = hb_parc(2);
  bool b = QFile::link ( par1, par2 );
  hb_retl( b );
}


//[1]bool link ( const QString & linkName )
//[2]bool link ( const QString & fileName, const QString & linkName )

HB_FUNC( QFILE_LINK )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_LINK1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QFILE_LINK2 );
  }
}

/*
Permissions permissions ( const QString & fileName )
*/
HB_FUNC( QFILE_PERMISSIONS2 )
{
  QString par1 = hb_parc(1);
  int i = QFile::permissions ( par1 );
  hb_retni( i );
}


//[1]Permissions permissions () const
//[2]Permissions permissions ( const QString & fileName )

HB_FUNC( QFILE_PERMISSIONS )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QFILE_PERMISSIONS1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QFILE_PERMISSIONS2 );
  }
}

/*
bool remove ( const QString & fileName )
*/
HB_FUNC( QFILE_REMOVE2 )
{
  QString par1 = hb_parc(1);
  bool b = QFile::remove ( par1 );
  hb_retl( b );
}


//[1]bool remove ()
//[2]bool remove ( const QString & fileName )

HB_FUNC( QFILE_REMOVE )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QFILE_REMOVE1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_REMOVE2 );
  }
}

/*
bool rename ( const QString & oldName, const QString & newName )
*/
HB_FUNC( QFILE_RENAME2 )
{
  QString par1 = hb_parc(1);
  QString par2 = hb_parc(2);
  bool b = QFile::rename ( par1, par2 );
  hb_retl( b );
}


//[1]bool rename ( const QString & newName )
//[2]bool rename ( const QString & oldName, const QString & newName )

HB_FUNC( QFILE_RENAME )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_RENAME1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QFILE_RENAME2 );
  }
}

/*
bool resize ( const QString & fileName, qint64 sz )
*/
HB_FUNC( QFILE_RESIZE2 )
{
  QString par1 = hb_parc(1);
  qint64 par2 = hb_parni(2);
  bool b = QFile::resize ( par1, par2 );
  hb_retl( b );
}


//[1]bool resize ( qint64 sz )
//[2]bool resize ( const QString & fileName, qint64 sz )

HB_FUNC( QFILE_RESIZE )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QFILE_RESIZE1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QFILE_RESIZE2 );
  }
}



/*
bool setPermissions ( const QString & fileName, Permissions permissions )
*/
HB_FUNC( QFILE_SETPERMISSIONS2 )
{
  QString par1 = hb_parc(1);
  int par2 = hb_parni(2);
  bool b = QFile::setPermissions ( par1,  (QFile::Permissions) par2 );
  hb_retl( b );
}


//[1]bool setPermissions ( Permissions permissions )
//[2]bool setPermissions ( const QString & fileName, Permissions permissions )

HB_FUNC( QFILE_SETPERMISSIONS )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QFILE_SETPERMISSIONS1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QFILE_SETPERMISSIONS2 );
  }
}

/*
QString symLinkTarget ( const QString & fileName )
*/
HB_FUNC( QFILE_SYMLINKTARGET2 )
{
  QString par1 = hb_parc(1);
  QString str1 = QFile::symLinkTarget ( par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString symLinkTarget () const
//[2]QString symLinkTarget ( const QString & fileName )

HB_FUNC( QFILE_SYMLINKTARGET )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QFILE_SYMLINKTARGET1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILE_SYMLINKTARGET2 );
  }
}

//Signals


