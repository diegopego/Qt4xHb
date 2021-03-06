/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDirIterator>

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
QDirIterator ( const QDir & dir, IteratorFlags flags = NoIteratorFlags )
*/
HB_FUNC( QDIRITERATOR_NEW1 )
{
  QDirIterator * o = NULL;
  QDir * par1 = (QDir *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) QDirIterator::NoIteratorFlags : hb_parni(2);
  o = new QDirIterator ( *par1,  (QDirIterator::IteratorFlags) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDirIterator *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QDirIterator ( const QString & path, IteratorFlags flags = NoIteratorFlags )
*/
HB_FUNC( QDIRITERATOR_NEW2 )
{
  QDirIterator * o = NULL;
  QString par1 = hb_parc(1);
  int par2 = ISNIL(2)? (int) QDirIterator::NoIteratorFlags : hb_parni(2);
  o = new QDirIterator ( par1,  (QDirIterator::IteratorFlags) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDirIterator *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QDirIterator ( const QString & path, QDir::Filters filters, IteratorFlags flags = NoIteratorFlags )
*/
HB_FUNC( QDIRITERATOR_NEW3 )
{
  QDirIterator * o = NULL;
  QString par1 = hb_parc(1);
  int par2 = hb_parni(2);
  int par3 = ISNIL(3)? (int) QDirIterator::NoIteratorFlags : hb_parni(3);
  o = new QDirIterator ( par1,  (QDir::Filters) par2,  (QDirIterator::IteratorFlags) par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDirIterator *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QDirIterator ( const QString & path, const QStringList & nameFilters, QDir::Filters filters = QDir::NoFilter, IteratorFlags flags = NoIteratorFlags )
*/
HB_FUNC( QDIRITERATOR_NEW4 )
{
  QDirIterator * o = NULL;
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
  int par3 = ISNIL(3)? (int) QDir::NoFilter : hb_parni(3);
  int par4 = ISNIL(4)? (int) QDirIterator::NoIteratorFlags : hb_parni(4);
  o = new QDirIterator ( par1, par2,  (QDir::Filters) par3,  (QDirIterator::IteratorFlags) par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDirIterator *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QDirIterator ( const QDir & dir, IteratorFlags flags = NoIteratorFlags )
//[2]QDirIterator ( const QString & path, IteratorFlags flags = NoIteratorFlags )
//[3]QDirIterator ( const QString & path, QDir::Filters filters, IteratorFlags flags = NoIteratorFlags )
//[4]QDirIterator ( const QString & path, const QStringList & nameFilters, QDir::Filters filters = QDir::NoFilter, IteratorFlags flags = NoIteratorFlags )

// TODO: resolver conflito entre casos 2 e 3

HB_FUNC( QDIRITERATOR_NEW )
{
  if( ISBETWEEN(1,2) && ISQDIR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QDIRITERATOR_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QDIRITERATOR_NEW2 );
  }
  else if( ISBETWEEN(2,3) && ISCHAR(1) && ISNUM(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QDIRITERATOR_NEW3 );
  }
  else if( ISBETWEEN(2,4) && ISCHAR(1) && ISARRAY(2) && (ISNUM(3)||ISNIL(3)) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QDIRITERATOR_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QDIRITERATOR_DELETE )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QFileInfo fileInfo () const
*/
HB_FUNC( QDIRITERATOR_FILEINFO )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFileInfo * ptr = new QFileInfo( obj->fileInfo (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFILEINFO", true );  }
}


/*
QString fileName () const
*/
HB_FUNC( QDIRITERATOR_FILENAME )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->fileName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString filePath () const
*/
HB_FUNC( QDIRITERATOR_FILEPATH )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->filePath (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool hasNext () const
*/
HB_FUNC( QDIRITERATOR_HASNEXT )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasNext (  );
    hb_retl( b );
  }
}


/*
QString next ()
*/
HB_FUNC( QDIRITERATOR_NEXT )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->next (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString path () const
*/
HB_FUNC( QDIRITERATOR_PATH )
{
  QDirIterator * obj = (QDirIterator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->path (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}




