/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFileDialog>

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

#include <QUrl>

/*
QFileDialog ( QWidget * parent, Qt::WindowFlags flags )
*/
HB_FUNC( QFILEDIALOG_NEW1 )
{
  QFileDialog * o = NULL;
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = hb_parni(2);
  o = new QFileDialog ( par1,  (Qt::WindowFlags) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFileDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QFileDialog ( QWidget * parent = 0, const QString & caption = QString(), const QString & directory = QString(), const QString & filter = QString() )
*/
HB_FUNC( QFILEDIALOG_NEW2 )
{
  QFileDialog * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  QString par3 = ISNIL(3)? QString() : hb_parc(3);
  QString par4 = ISNIL(4)? QString() : hb_parc(4);
  o = new QFileDialog ( par1, par2, par3, par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFileDialog *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QFileDialog ( QWidget * parent, Qt::WindowFlags flags )
//[2]QFileDialog ( QWidget * parent = 0, const QString & caption = QString(), const QString & directory = QString(), const QString & filter = QString() )

HB_FUNC( QFILEDIALOG_NEW )
{
  if( ISNUMPAR(2) && ISQWIDGET(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QFILEDIALOG_NEW1 );
  }
  else if( ISBETWEEN(0,4) && (ISQWIDGET(1)||ISNIL(1)) && (ISCHAR(2)||ISNIL(2)) && (ISCHAR(3)||ISNIL(3)) && (ISCHAR(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QFILEDIALOG_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QFILEDIALOG_DELETE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
AcceptMode acceptMode () const
*/
HB_FUNC( QFILEDIALOG_ACCEPTMODE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->acceptMode (  );
    hb_retni( i );
  }
}


/*
bool confirmOverwrite () const
*/
HB_FUNC( QFILEDIALOG_CONFIRMOVERWRITE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->confirmOverwrite (  );
    hb_retl( b );
  }
}


/*
QString defaultSuffix () const
*/
HB_FUNC( QFILEDIALOG_DEFAULTSUFFIX )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->defaultSuffix (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QDir directory () const
*/
HB_FUNC( QFILEDIALOG_DIRECTORY )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDir * ptr = new QDir( obj->directory (  ) );
    _qt4xhb_createReturnClass ( ptr, "QDIR", true );  }
}


/*
FileMode fileMode () const
*/
HB_FUNC( QFILEDIALOG_FILEMODE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->fileMode (  );
    hb_retni( i );
  }
}


/*
QDir::Filters filter () const
*/
HB_FUNC( QFILEDIALOG_FILTER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->filter (  );
    hb_retni( i );
  }
}


/*
QStringList history () const
*/
HB_FUNC( QFILEDIALOG_HISTORY )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->history (  );
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
QFileIconProvider * iconProvider () const
*/
HB_FUNC( QFILEDIALOG_ICONPROVIDER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFileIconProvider * ptr = obj->iconProvider (  );
    _qt4xhb_createReturnClass ( ptr, "QFILEICONPROVIDER" );  }
}


/*
bool isNameFilterDetailsVisible () const
*/
HB_FUNC( QFILEDIALOG_ISNAMEFILTERDETAILSVISIBLE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNameFilterDetailsVisible (  );
    hb_retl( b );
  }
}


/*
bool isReadOnly () const
*/
HB_FUNC( QFILEDIALOG_ISREADONLY )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isReadOnly (  );
    hb_retl( b );
  }
}


/*
QAbstractItemDelegate * itemDelegate () const
*/
HB_FUNC( QFILEDIALOG_ITEMDELEGATE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemDelegate * ptr = obj->itemDelegate (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTITEMDELEGATE" );  }
}


/*
QString labelText ( DialogLabel label ) const
*/
HB_FUNC( QFILEDIALOG_LABELTEXT )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString str1 = obj->labelText (  (QFileDialog::DialogLabel) par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QStringList nameFilters () const
*/
HB_FUNC( QFILEDIALOG_NAMEFILTERS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->nameFilters (  );
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
void open ( QObject * receiver, const char * member )
*/
HB_FUNC( QFILEDIALOG_OPEN )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = hb_parc(2);
    obj->open ( par1,  (const char *) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Options options () const
*/
HB_FUNC( QFILEDIALOG_OPTIONS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->options (  );
    hb_retni( i );
  }
}


/*
QAbstractProxyModel * proxyModel () const
*/
HB_FUNC( QFILEDIALOG_PROXYMODEL )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractProxyModel * ptr = obj->proxyModel (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTPROXYMODEL" );  }
}


/*
bool resolveSymlinks () const
*/
HB_FUNC( QFILEDIALOG_RESOLVESYMLINKS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->resolveSymlinks (  );
    hb_retl( b );
  }
}


/*
bool restoreState ( const QByteArray & state )
*/
HB_FUNC( QFILEDIALOG_RESTORESTATE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->restoreState ( *par1 );
    hb_retl( b );
  }
}


/*
QByteArray saveState () const
*/
HB_FUNC( QFILEDIALOG_SAVESTATE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->saveState (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
void selectFile ( const QString & filename )
*/
HB_FUNC( QFILEDIALOG_SELECTFILE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->selectFile ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void selectNameFilter ( const QString & filter )
*/
HB_FUNC( QFILEDIALOG_SELECTNAMEFILTER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->selectNameFilter ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QStringList selectedFiles () const
*/
HB_FUNC( QFILEDIALOG_SELECTEDFILES )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->selectedFiles (  );
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
QString selectedNameFilter () const
*/
HB_FUNC( QFILEDIALOG_SELECTEDNAMEFILTER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->selectedNameFilter (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setAcceptMode ( AcceptMode mode )
*/
HB_FUNC( QFILEDIALOG_SETACCEPTMODE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setAcceptMode (  (QFileDialog::AcceptMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setConfirmOverwrite ( bool enabled )
*/
HB_FUNC( QFILEDIALOG_SETCONFIRMOVERWRITE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setConfirmOverwrite ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDefaultSuffix ( const QString & suffix )
*/
HB_FUNC( QFILEDIALOG_SETDEFAULTSUFFIX )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setDefaultSuffix ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDirectory ( const QString & directory )
*/
HB_FUNC( QFILEDIALOG_SETDIRECTORY1 )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setDirectory ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDirectory ( const QDir & directory )
*/
HB_FUNC( QFILEDIALOG_SETDIRECTORY2 )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDir * par1 = (QDir *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDirectory ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setDirectory ( const QString & directory )
//[2]void setDirectory ( const QDir & directory )

HB_FUNC( QFILEDIALOG_SETDIRECTORY )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFILEDIALOG_SETDIRECTORY1 );
  }
  else if( ISNUMPAR(1) && ISQDIR(1) )
  {
    HB_FUNC_EXEC( QFILEDIALOG_SETDIRECTORY2 );
  }
}

/*
void setFileMode ( FileMode mode )
*/
HB_FUNC( QFILEDIALOG_SETFILEMODE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFileMode (  (QFileDialog::FileMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFilter ( QDir::Filters filters )
*/
HB_FUNC( QFILEDIALOG_SETFILTER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFilter (  (QDir::Filters) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHistory ( const QStringList & paths )
*/
HB_FUNC( QFILEDIALOG_SETHISTORY )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
    obj->setHistory ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setIconProvider ( QFileIconProvider * provider )
*/
HB_FUNC( QFILEDIALOG_SETICONPROVIDER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFileIconProvider * par1 = (QFileIconProvider *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setIconProvider ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setItemDelegate ( QAbstractItemDelegate * delegate )
*/
HB_FUNC( QFILEDIALOG_SETITEMDELEGATE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemDelegate * par1 = (QAbstractItemDelegate *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setItemDelegate ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLabelText ( DialogLabel label, const QString & text )
*/
HB_FUNC( QFILEDIALOG_SETLABELTEXT )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    obj->setLabelText (  (QFileDialog::DialogLabel) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNameFilter ( const QString & filter )
*/
HB_FUNC( QFILEDIALOG_SETNAMEFILTER )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setNameFilter ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNameFilterDetailsVisible ( bool enabled )
*/
HB_FUNC( QFILEDIALOG_SETNAMEFILTERDETAILSVISIBLE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setNameFilterDetailsVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNameFilters ( const QStringList & filters )
*/
HB_FUNC( QFILEDIALOG_SETNAMEFILTERS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
    obj->setNameFilters ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOption ( Option option, bool on = true )
*/
HB_FUNC( QFILEDIALOG_SETOPTION )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setOption (  (QFileDialog::Option) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOptions ( Options options )
*/
HB_FUNC( QFILEDIALOG_SETOPTIONS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setOptions (  (QFileDialog::Options) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setProxyModel ( QAbstractProxyModel * proxyModel )
*/
HB_FUNC( QFILEDIALOG_SETPROXYMODEL )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractProxyModel * par1 = (QAbstractProxyModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setProxyModel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setReadOnly ( bool enabled )
*/
HB_FUNC( QFILEDIALOG_SETREADONLY )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setReadOnly ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setResolveSymlinks ( bool enabled )
*/
HB_FUNC( QFILEDIALOG_SETRESOLVESYMLINKS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setResolveSymlinks ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSidebarUrls ( const QList<QUrl> & urls )
*/
HB_FUNC( QFILEDIALOG_SETSIDEBARURLS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QList<QUrl> par1;
PHB_ITEM aList1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aList1);
for (i1=0;i1<nLen1;i1++)
{
par1 << *(QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList1, i1+1 ), "POINTER", 0 ) );
}
    obj->setSidebarUrls ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setViewMode ( ViewMode mode )
*/
HB_FUNC( QFILEDIALOG_SETVIEWMODE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setViewMode (  (QFileDialog::ViewMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QList<QUrl> sidebarUrls () const
*/
HB_FUNC( QFILEDIALOG_SIDEBARURLS )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QUrl> list = obj->sidebarUrls (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QURL" );
    #else
    pDynSym = hb_dynsymFindName( "QURL" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QUrl *) new QUrl ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        PHB_ITEM pDestroy = hb_itemNew( NULL );
        hb_itemPutL( pDestroy, true );
        hb_objSendMsg( pObject, "_SELF_DESTRUCTION", 1, pDestroy );
        hb_itemRelease( pDestroy );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
bool testOption ( Option option ) const
*/
HB_FUNC( QFILEDIALOG_TESTOPTION )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->testOption (  (QFileDialog::Option) par1 );
    hb_retl( b );
  }
}


/*
ViewMode viewMode () const
*/
HB_FUNC( QFILEDIALOG_VIEWMODE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->viewMode (  );
    hb_retni( i );
  }
}


/*
virtual void setVisible ( bool visible )
*/
HB_FUNC( QFILEDIALOG_SETVISIBLE )
{
  QFileDialog * obj = (QFileDialog *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
QString getExistingDirectory ( QWidget * parent = 0, const QString & caption = QString(), const QString & dir = QString(), Options options = ShowDirsOnly )
*/
HB_FUNC( QFILEDIALOG_GETEXISTINGDIRECTORY )
{
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  QString par3 = ISNIL(3)? QString() : hb_parc(3);
  int par4 = ISNIL(4)? (int) QFileDialog::ShowDirsOnly : hb_parni(4);
  QString str1 = QFileDialog::getExistingDirectory ( par1, par2, par3,  (QFileDialog::Options) par4 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString getOpenFileName ( QWidget * parent = 0, const QString & caption = QString(), const QString & dir = QString(), const QString & filter = QString(), QString * selectedFilter = 0, Options options = 0 )
*/
HB_FUNC( QFILEDIALOG_GETOPENFILENAME )
{
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  QString par3 = ISNIL(3)? QString() : hb_parc(3);
  QString par4 = ISNIL(4)? QString() : hb_parc(4);
  QString * par5 = NULL;
  int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
  QString str1 = QFileDialog::getOpenFileName ( par1, par2, par3, par4, par5,  (QFileDialog::Options) par6 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QStringList getOpenFileNames ( QWidget * parent = 0, const QString & caption = QString(), const QString & dir = QString(), const QString & filter = QString(), QString * selectedFilter = 0, Options options = 0 )
*/
HB_FUNC( QFILEDIALOG_GETOPENFILENAMES )
{
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  QString par3 = ISNIL(3)? QString() : hb_parc(3);
  QString par4 = ISNIL(4)? QString() : hb_parc(4);
  QString * par5 = NULL;
  int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
  QStringList strl = QFileDialog::getOpenFileNames ( par1, par2, par3, par4, par5,  (QFileDialog::Options) par6 );
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
QString getSaveFileName ( QWidget * parent = 0, const QString & caption = QString(), const QString & dir = QString(), const QString & filter = QString(), QString * selectedFilter = 0, Options options = 0 )
*/
HB_FUNC( QFILEDIALOG_GETSAVEFILENAME )
{
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  QString par3 = ISNIL(3)? QString() : hb_parc(3);
  QString par4 = ISNIL(4)? QString() : hb_parc(4);
  QString * par5 = NULL;
  int par6 = ISNIL(6)? (int) 0 : hb_parni(6);
  QString str1 = QFileDialog::getSaveFileName ( par1, par2, par3, par4, par5,  (QFileDialog::Options) par6 );
  hb_retc( (const char *) str1.toLatin1().data() );
}




