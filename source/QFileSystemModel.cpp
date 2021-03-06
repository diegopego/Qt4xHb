/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFileSystemModel>

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

#include <QDateTime>

/*
QFileSystemModel(QObject * parent = 0)
*/
HB_FUNC( QFILESYSTEMMODEL_NEW )
{
  QFileSystemModel * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QFileSystemModel ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFileSystemModel *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QFILESYSTEMMODEL_DELETE )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QIcon fileIcon ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_FILEICON )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QIcon * ptr = new QIcon( obj->fileIcon ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QICON", true );  }
}


/*
QFileInfo fileInfo ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_FILEINFO )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QFileInfo * ptr = new QFileInfo( obj->fileInfo ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QFILEINFO", true );  }
}


/*
QString fileName ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_FILENAME )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->fileName ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString filePath ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_FILEPATH )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->filePath ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QDir::Filters filter () const
*/
HB_FUNC( QFILESYSTEMMODEL_FILTER )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->filter (  );
    hb_retni( i );
  }
}


/*
QFileIconProvider * iconProvider () const
*/
HB_FUNC( QFILESYSTEMMODEL_ICONPROVIDER )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFileIconProvider * ptr = obj->iconProvider (  );
    _qt4xhb_createReturnClass ( ptr, "QFILEICONPROVIDER" );  }
}


/*
QModelIndex index ( const QString & path, int column = 0 ) const
*/
HB_FUNC( QFILESYSTEMMODEL_INDEX1 )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    QModelIndex * ptr = new QModelIndex( obj->index ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
bool isDir ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_ISDIR )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isDir ( *par1 );
    hb_retl( b );
  }
}


/*
bool isReadOnly () const
*/
HB_FUNC( QFILESYSTEMMODEL_ISREADONLY )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isReadOnly (  );
    hb_retl( b );
  }
}


/*
QDateTime lastModified ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_LASTMODIFIED )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QDateTime * ptr = new QDateTime( obj->lastModified ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QDATETIME", true );  }
}


/*
QModelIndex mkdir ( const QModelIndex & parent, const QString & name )
*/
HB_FUNC( QFILESYSTEMMODEL_MKDIR )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    QModelIndex * ptr = new QModelIndex( obj->mkdir ( *par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
QVariant myComputer ( int role = Qt::DisplayRole ) const
*/
HB_FUNC( QFILESYSTEMMODEL_MYCOMPUTER )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? Qt::DisplayRole : hb_parni(1);
    QVariant * ptr = new QVariant( obj->myComputer ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
bool nameFilterDisables () const
*/
HB_FUNC( QFILESYSTEMMODEL_NAMEFILTERDISABLES )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->nameFilterDisables (  );
    hb_retl( b );
  }
}


/*
QStringList nameFilters () const
*/
HB_FUNC( QFILESYSTEMMODEL_NAMEFILTERS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QFile::Permissions permissions ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_PERMISSIONS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->permissions ( *par1 );
    hb_retni( i );
  }
}


/*
bool remove ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_REMOVE )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->remove ( *par1 );
    hb_retl( b );
  }
}


/*
bool resolveSymlinks () const
*/
HB_FUNC( QFILESYSTEMMODEL_RESOLVESYMLINKS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->resolveSymlinks (  );
    hb_retl( b );
  }
}


/*
bool rmdir ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_RMDIR )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->rmdir ( *par1 );
    hb_retl( b );
  }
}


/*
QDir rootDirectory () const
*/
HB_FUNC( QFILESYSTEMMODEL_ROOTDIRECTORY )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDir * ptr = new QDir( obj->rootDirectory (  ) );
    _qt4xhb_createReturnClass ( ptr, "QDIR", true );  }
}


/*
QString rootPath () const
*/
HB_FUNC( QFILESYSTEMMODEL_ROOTPATH )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->rootPath (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setFilter ( QDir::Filters filters )
*/
HB_FUNC( QFILESYSTEMMODEL_SETFILTER )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFilter (  (QDir::Filters) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setIconProvider ( QFileIconProvider * provider )
*/
HB_FUNC( QFILESYSTEMMODEL_SETICONPROVIDER )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFileIconProvider * par1 = (QFileIconProvider *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setIconProvider ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNameFilterDisables ( bool enable )
*/
HB_FUNC( QFILESYSTEMMODEL_SETNAMEFILTERDISABLES )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setNameFilterDisables ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNameFilters ( const QStringList & filters )
*/
HB_FUNC( QFILESYSTEMMODEL_SETNAMEFILTERS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void setReadOnly ( bool enable )
*/
HB_FUNC( QFILESYSTEMMODEL_SETREADONLY )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setReadOnly ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setResolveSymlinks ( bool enable )
*/
HB_FUNC( QFILESYSTEMMODEL_SETRESOLVESYMLINKS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setResolveSymlinks ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QModelIndex setRootPath ( const QString & newPath )
*/
HB_FUNC( QFILESYSTEMMODEL_SETROOTPATH )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QModelIndex * ptr = new QModelIndex( obj->setRootPath ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
qint64 size ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_SIZE )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qint64 i = obj->size ( *par1 );
    hb_retni( i );
  }
}


/*
QString type ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_TYPE )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->type ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual bool canFetchMore ( const QModelIndex & parent ) const
*/
HB_FUNC( QFILESYSTEMMODEL_CANFETCHMORE )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->canFetchMore ( *par1 );
    hb_retl( b );
  }
}


/*
virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const
*/
HB_FUNC( QFILESYSTEMMODEL_COLUMNCOUNT )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex par1 = ISNIL(1)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->columnCount ( par1 );
    hb_retni( i );
  }
}


/*
virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const
*/
HB_FUNC( QFILESYSTEMMODEL_DATA )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? Qt::DisplayRole : hb_parni(2);
    QVariant * ptr = new QVariant( obj->data ( *par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual bool dropMimeData ( const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent )
*/
HB_FUNC( QFILESYSTEMMODEL_DROPMIMEDATA )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QMimeData * par1 = (const QMimeData *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    QModelIndex * par5 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(5, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->dropMimeData ( par1,  (Qt::DropAction) par2, par3, par4, *par5 );
    hb_retl( b );
  }
}


/*
virtual void fetchMore ( const QModelIndex & parent )
*/
HB_FUNC( QFILESYSTEMMODEL_FETCHMORE )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->fetchMore ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual Qt::ItemFlags flags ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_FLAGS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->flags ( *par1 );
    hb_retni( i );
  }
}


/*
virtual bool hasChildren ( const QModelIndex & parent = QModelIndex() ) const
*/
HB_FUNC( QFILESYSTEMMODEL_HASCHILDREN )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex par1 = ISNIL(1)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->hasChildren ( par1 );
    hb_retl( b );
  }
}


/*
virtual QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const
*/
HB_FUNC( QFILESYSTEMMODEL_HEADERDATA )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = ISNIL(3)? Qt::DisplayRole : hb_parni(3);
    QVariant * ptr = new QVariant( obj->headerData ( par1,  (Qt::Orientation) par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const
*/
HB_FUNC( QFILESYSTEMMODEL_INDEX2 )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QModelIndex par3 = ISNIL(3)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->index ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


//[1]QModelIndex index ( const QString & path, int column = 0 ) const
//[2]virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const

HB_FUNC( QFILESYSTEMMODEL_INDEX )
{
  if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QFILESYSTEMMODEL_INDEX1 );
  }
  else if( ISBETWEEN(2,3) && ISNUM(1) && ISNUM(2) && (ISQMODELINDEX(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QFILESYSTEMMODEL_INDEX2 );
  }
}

/*
virtual QMimeData * mimeData ( const QModelIndexList & indexes ) const
*/
HB_FUNC( QFILESYSTEMMODEL_MIMEDATA )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndexList * par1 = (QModelIndexList *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QMimeData * ptr = obj->mimeData ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QMIMEDATA" );  }
}


/*
virtual QStringList mimeTypes () const
*/
HB_FUNC( QFILESYSTEMMODEL_MIMETYPES )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->mimeTypes (  );
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
virtual QModelIndex parent ( const QModelIndex & index ) const
*/
HB_FUNC( QFILESYSTEMMODEL_PARENT )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QModelIndex * ptr = new QModelIndex( obj->parent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const
*/
HB_FUNC( QFILESYSTEMMODEL_ROWCOUNT )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex par1 = ISNIL(1)? QModelIndex() : *(QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->rowCount ( par1 );
    hb_retni( i );
  }
}


/*
virtual bool setData ( const QModelIndex & idx, const QVariant & value, int role = Qt::EditRole )
*/
HB_FUNC( QFILESYSTEMMODEL_SETDATA )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * par2 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? Qt::EditRole : hb_parni(3);
    bool b = obj->setData ( *par1, *par2, par3 );
    hb_retl( b );
  }
}


/*
virtual void sort ( int column, Qt::SortOrder order = Qt::AscendingOrder )
*/
HB_FUNC( QFILESYSTEMMODEL_SORT )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) Qt::AscendingOrder : hb_parni(2);
    obj->sort ( par1,  (Qt::SortOrder) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual Qt::DropActions supportedDropActions () const
*/
HB_FUNC( QFILESYSTEMMODEL_SUPPORTEDDROPACTIONS )
{
  QFileSystemModel * obj = (QFileSystemModel *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->supportedDropActions (  );
    hb_retni( i );
  }
}





