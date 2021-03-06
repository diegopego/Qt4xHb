/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QCoreApplication>

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

#include <QStringList>


/*
QCoreApplication ( int & argc, char ** argv )
*/
HB_FUNC( QCOREAPPLICATION_NEW )
{
  int argc;
  char ** argv;
  argc = hb_cmdargARGC();
  argv = hb_cmdargARGV();
  QCoreApplication * o = NULL;
  o = new QCoreApplication( argc, argv );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,   (QCoreApplication *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}

HB_FUNC( QCOREAPPLICATION_DELETE )
{
  QCoreApplication * obj = (QCoreApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool filterEvent ( void * message, long * result )
*/
HB_FUNC( QCOREAPPLICATION_FILTEREVENT )
{
  QCoreApplication * obj = (QCoreApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    void * par1 = (void *) hb_parptr(1);
    long par2;
    bool b = obj->filterEvent ( par1, &par2 );
    hb_retl( b );
    hb_stornl( par2, 2 );
  }
}


/*
virtual bool notify ( QObject * receiver, QEvent * event )
*/
HB_FUNC( QCOREAPPLICATION_NOTIFY )
{
  QCoreApplication * obj = (QCoreApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QEvent * par2 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->notify ( par1, par2 );
    hb_retl( b );
  }
}




/*
void quit ()
*/
HB_FUNC( QCOREAPPLICATION_QUIT )
{
  QCoreApplication * obj = (QCoreApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->quit (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
void addLibraryPath ( const QString & path )
*/
HB_FUNC( QCOREAPPLICATION_ADDLIBRARYPATH )
{
  QString par1 = hb_parc(1);
  QCoreApplication::addLibraryPath ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString applicationDirPath ()
*/
HB_FUNC( QCOREAPPLICATION_APPLICATIONDIRPATH )
{
  QString str1 = QCoreApplication::applicationDirPath (  );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString applicationFilePath ()
*/
HB_FUNC( QCOREAPPLICATION_APPLICATIONFILEPATH )
{
  QString str1 = QCoreApplication::applicationFilePath (  );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString applicationName ()
*/
HB_FUNC( QCOREAPPLICATION_APPLICATIONNAME )
{
  QString str1 = QCoreApplication::applicationName (  );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
qint64 applicationPid ()
*/
HB_FUNC( QCOREAPPLICATION_APPLICATIONPID )
{
  qint64 i = QCoreApplication::applicationPid (  );
  hb_retni( i );
}


/*
QString applicationVersion ()
*/
HB_FUNC( QCOREAPPLICATION_APPLICATIONVERSION )
{
  QString str1 = QCoreApplication::applicationVersion (  );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QStringList arguments ()
*/
HB_FUNC( QCOREAPPLICATION_ARGUMENTS )
{
  QStringList strl = QCoreApplication::arguments (  );
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


/*
bool closingDown ()
*/
HB_FUNC( QCOREAPPLICATION_CLOSINGDOWN )
{
  bool b = QCoreApplication::closingDown (  );
  hb_retl( b );
}


/*
int exec ()
*/
HB_FUNC( QCOREAPPLICATION_EXEC )
{
  int i = QCoreApplication::exec (  );
  hb_retni( i );
}


/*
void exit ( int returnCode = 0 )
*/
HB_FUNC( QCOREAPPLICATION_EXIT )
{
  int par1 = ISNIL(1)? 0 : hb_parni(1);
  QCoreApplication::exit ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void flush ()
*/
HB_FUNC( QCOREAPPLICATION_FLUSH )
{
  QCoreApplication::flush (  );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool hasPendingEvents ()
*/
HB_FUNC( QCOREAPPLICATION_HASPENDINGEVENTS )
{
  bool b = QCoreApplication::hasPendingEvents (  );
  hb_retl( b );
}


/*
void installTranslator ( QTranslator * translationFile )
*/
HB_FUNC( QCOREAPPLICATION_INSTALLTRANSLATOR )
{
  QTranslator * par1 = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QCoreApplication::installTranslator ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QCoreApplication * instance ()
*/
HB_FUNC( QCOREAPPLICATION_INSTANCE )
{
  QCoreApplication * ptr = QCoreApplication::instance (  );
  _qt4xhb_createReturnClass ( ptr, "QCOREAPPLICATION" );}


/*
QStringList libraryPaths ()
*/
HB_FUNC( QCOREAPPLICATION_LIBRARYPATHS )
{
  QStringList strl = QCoreApplication::libraryPaths (  );
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


/*
QString organizationDomain ()
*/
HB_FUNC( QCOREAPPLICATION_ORGANIZATIONDOMAIN )
{
  QString str1 = QCoreApplication::organizationDomain (  );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString organizationName ()
*/
HB_FUNC( QCOREAPPLICATION_ORGANIZATIONNAME )
{
  QString str1 = QCoreApplication::organizationName (  );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
void postEvent ( QObject * receiver, QEvent * event )
*/
HB_FUNC( QCOREAPPLICATION_POSTEVENT1 )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QEvent * par2 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QCoreApplication::postEvent ( par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void postEvent ( QObject * receiver, QEvent * event, int priority )
*/
HB_FUNC( QCOREAPPLICATION_POSTEVENT2 )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QEvent * par2 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par3 = hb_parni(3);
  QCoreApplication::postEvent ( par1, par2, par3 );
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void postEvent ( QObject * receiver, QEvent * event )
//[2]void postEvent ( QObject * receiver, QEvent * event, int priority )

HB_FUNC( QCOREAPPLICATION_POSTEVENT )
{
  if( ISNUMPAR(2) && ISQOBJECT(1) && ISOBJECT(2) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_POSTEVENT1 );
  }
  else if( ISNUMPAR(3) && ISQOBJECT(1) && ISOBJECT(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_POSTEVENT2 );
  }
}

/*
void processEvents ( QEventLoop::ProcessEventsFlags flags = QEventLoop::AllEvents )
*/
HB_FUNC( QCOREAPPLICATION_PROCESSEVENTS1 )
{
  int par1 = ISNIL(1)? (int) QEventLoop::AllEvents : hb_parni(1);
  QCoreApplication::processEvents (  (QEventLoop::ProcessEventsFlags) par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void processEvents ( QEventLoop::ProcessEventsFlags flags, int maxtime )
*/
HB_FUNC( QCOREAPPLICATION_PROCESSEVENTS2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QCoreApplication::processEvents (  (QEventLoop::ProcessEventsFlags) par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void processEvents ( QEventLoop::ProcessEventsFlags flags = QEventLoop::AllEvents )
//[2]void processEvents ( QEventLoop::ProcessEventsFlags flags, int maxtime )

HB_FUNC( QCOREAPPLICATION_PROCESSEVENTS )
{
  if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_PROCESSEVENTS1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_PROCESSEVENTS2 );
  }
}

/*
void removeLibraryPath ( const QString & path )
*/
HB_FUNC( QCOREAPPLICATION_REMOVELIBRARYPATH )
{
  QString par1 = hb_parc(1);
  QCoreApplication::removeLibraryPath ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removePostedEvents ( QObject * receiver )
*/
HB_FUNC( QCOREAPPLICATION_REMOVEPOSTEDEVENTS1 )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QCoreApplication::removePostedEvents ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removePostedEvents ( QObject * receiver, int eventType )
*/
HB_FUNC( QCOREAPPLICATION_REMOVEPOSTEDEVENTS2 )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = hb_parni(2);
  QCoreApplication::removePostedEvents ( par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void removePostedEvents ( QObject * receiver )
//[2]void removePostedEvents ( QObject * receiver, int eventType )

HB_FUNC( QCOREAPPLICATION_REMOVEPOSTEDEVENTS )
{
  if( ISNUMPAR(1) && ISQOBJECT(1) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_REMOVEPOSTEDEVENTS1 );
  }
  else if( ISNUMPAR(2) && ISQOBJECT(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_REMOVEPOSTEDEVENTS2 );
  }
}

/*
void removeTranslator ( QTranslator * translationFile )
*/
HB_FUNC( QCOREAPPLICATION_REMOVETRANSLATOR )
{
  QTranslator * par1 = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QCoreApplication::removeTranslator ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool sendEvent ( QObject * receiver, QEvent * event )
*/
HB_FUNC( QCOREAPPLICATION_SENDEVENT )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QEvent * par2 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  bool b = QCoreApplication::sendEvent ( par1, par2 );
  hb_retl( b );
}


/*
void sendPostedEvents ( QObject * receiver, int event_type )
*/
HB_FUNC( QCOREAPPLICATION_SENDPOSTEDEVENTS1 )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = hb_parni(2);
  QCoreApplication::sendPostedEvents ( par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void sendPostedEvents ()
*/
HB_FUNC( QCOREAPPLICATION_SENDPOSTEDEVENTS2 )
{
  QCoreApplication::sendPostedEvents (  );
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void sendPostedEvents ( QObject * receiver, int event_type )
//[2]void sendPostedEvents ()

HB_FUNC( QCOREAPPLICATION_SENDPOSTEDEVENTS )
{
  if( ISNUMPAR(2) && ISQOBJECT(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_SENDPOSTEDEVENTS1 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_SENDPOSTEDEVENTS2 );
  }
}

/*
void setApplicationName ( const QString & application )
*/
HB_FUNC( QCOREAPPLICATION_SETAPPLICATIONNAME )
{
  QString par1 = hb_parc(1);
  QCoreApplication::setApplicationName ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setApplicationVersion ( const QString & version )
*/
HB_FUNC( QCOREAPPLICATION_SETAPPLICATIONVERSION )
{
  QString par1 = hb_parc(1);
  QCoreApplication::setApplicationVersion ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAttribute ( Qt::ApplicationAttribute attribute, bool on = true )
*/
HB_FUNC( QCOREAPPLICATION_SETATTRIBUTE )
{
  int par1 = hb_parni(1);
  bool par2 = ISNIL(2)? true : hb_parl(2);
  QCoreApplication::setAttribute (  (Qt::ApplicationAttribute) par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLibraryPaths ( const QStringList & paths )
*/
HB_FUNC( QCOREAPPLICATION_SETLIBRARYPATHS )
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
  QCoreApplication::setLibraryPaths ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOrganizationDomain ( const QString & orgDomain )
*/
HB_FUNC( QCOREAPPLICATION_SETORGANIZATIONDOMAIN )
{
  QString par1 = hb_parc(1);
  QCoreApplication::setOrganizationDomain ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOrganizationName ( const QString & orgName )
*/
HB_FUNC( QCOREAPPLICATION_SETORGANIZATIONNAME )
{
  QString par1 = hb_parc(1);
  QCoreApplication::setOrganizationName ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool startingUp ()
*/
HB_FUNC( QCOREAPPLICATION_STARTINGUP )
{
  bool b = QCoreApplication::startingUp (  );
  hb_retl( b );
}


/*
bool testAttribute ( Qt::ApplicationAttribute attribute )
*/
HB_FUNC( QCOREAPPLICATION_TESTATTRIBUTE )
{
  int par1 = hb_parni(1);
  bool b = QCoreApplication::testAttribute (  (Qt::ApplicationAttribute) par1 );
  hb_retl( b );
}


/*
QString translate ( const char * context, const char * sourceText, const char * disambiguation, Encoding encoding, int n )
*/
HB_FUNC( QCOREAPPLICATION_TRANSLATE1 )
{
  const char * par1 = hb_parc(1);
  const char * par2 = hb_parc(2);
  const char * par3 = hb_parc(3);
  int par4 = hb_parni(4);
  int par5 = hb_parni(5);
  QString str1 = QCoreApplication::translate (  (const char *) par1,  (const char *) par2,  (const char *) par3,  (QCoreApplication::Encoding) par4, par5 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString translate ( const char * context, const char * sourceText, const char * disambiguation = 0, Encoding encoding = CodecForTr )
*/
HB_FUNC( QCOREAPPLICATION_TRANSLATE2 )
{
  const char * par1 = hb_parc(1);
  const char * par2 = hb_parc(2);
  const char * par3 = hb_parc(3);
  int par4 = ISNIL(4)? (int) QCoreApplication::CodecForTr : hb_parni(4);
  QString str1 = QCoreApplication::translate (  (const char *) par1,  (const char *) par2,  (const char *) par3,  (QCoreApplication::Encoding) par4 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString translate ( const char * context, const char * sourceText, const char * disambiguation, Encoding encoding, int n )
//[2]QString translate ( const char * context, const char * sourceText, const char * disambiguation = 0, Encoding encoding = CodecForTr )

HB_FUNC( QCOREAPPLICATION_TRANSLATE )
{
  if( ISNUMPAR(5) && ISCHAR(1) && ISCHAR(2) && ISCHAR(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_TRANSLATE1 );
  }
  else if( ISNUMPAR(4) && ISCHAR(1) && ISCHAR(2) && ISCHAR(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QCOREAPPLICATION_TRANSLATE2 );
  }
}



