/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QFontDatabase>

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
QFontDatabase ()
*/
HB_FUNC( QFONTDATABASE_NEW )
{
  QFontDatabase * o = NULL;
  o = new QFontDatabase (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QFontDatabase *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}



/*
bool bold ( const QString & family, const QString & style ) const
*/
HB_FUNC( QFONTDATABASE_BOLD )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    bool b = obj->bold ( par1, par2 );
    hb_retl( b );
  }
}


/*
QStringList families ( WritingSystem writingSystem = Any ) const
*/
HB_FUNC( QFONTDATABASE_FAMILIES )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QFontDatabase::Any : hb_parni(1);
    QStringList strl = obj->families (  (QFontDatabase::WritingSystem) par1 );
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
QFont font ( const QString & family, const QString & style, int pointSize ) const
*/
HB_FUNC( QFONTDATABASE_FONT )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    int par3 = hb_parni(3);
    QFont * ptr = new QFont( obj->font ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QFONT", true );  }
}


/*
bool isBitmapScalable ( const QString & family, const QString & style = QString() ) const
*/
HB_FUNC( QFONTDATABASE_ISBITMAPSCALABLE )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    bool b = obj->isBitmapScalable ( par1, par2 );
    hb_retl( b );
  }
}


/*
bool isFixedPitch ( const QString & family, const QString & style = QString() ) const
*/
HB_FUNC( QFONTDATABASE_ISFIXEDPITCH )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    bool b = obj->isFixedPitch ( par1, par2 );
    hb_retl( b );
  }
}


/*
bool isScalable ( const QString & family, const QString & style = QString() ) const
*/
HB_FUNC( QFONTDATABASE_ISSCALABLE )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    bool b = obj->isScalable ( par1, par2 );
    hb_retl( b );
  }
}


/*
bool isSmoothlyScalable ( const QString & family, const QString & style = QString() ) const
*/
HB_FUNC( QFONTDATABASE_ISSMOOTHLYSCALABLE )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    bool b = obj->isSmoothlyScalable ( par1, par2 );
    hb_retl( b );
  }
}


/*
bool italic ( const QString & family, const QString & style ) const
*/
HB_FUNC( QFONTDATABASE_ITALIC )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    bool b = obj->italic ( par1, par2 );
    hb_retl( b );
  }
}


/*
QList<int> pointSizes ( const QString & family, const QString & style = QString() )
*/
HB_FUNC( QFONTDATABASE_POINTSIZES )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QList<int> list = obj->pointSizes ( par1, par2 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutNI( NULL, list[i] );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QList<int> smoothSizes ( const QString & family, const QString & style )
*/
HB_FUNC( QFONTDATABASE_SMOOTHSIZES )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QList<int> list = obj->smoothSizes ( par1, par2 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutNI( NULL, list[i] );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QString styleString ( const QFont & font )
*/
HB_FUNC( QFONTDATABASE_STYLESTRING1 )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->styleString ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString styleString ( const QFontInfo & fontInfo )
*/
HB_FUNC( QFONTDATABASE_STYLESTRING2 )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFontInfo * par1 = (QFontInfo *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->styleString ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


//[1]QString styleString ( const QFont & font )
//[2]QString styleString ( const QFontInfo & fontInfo )

HB_FUNC( QFONTDATABASE_STYLESTRING )
{
  if( ISNUMPAR(1) && ISQFONT(1) )
  {
    HB_FUNC_EXEC( QFONTDATABASE_STYLESTRING1 );
  }
  else if( ISNUMPAR(1) && ISQFONTINFO(1) )
  {
    HB_FUNC_EXEC( QFONTDATABASE_STYLESTRING2 );
  }
}

/*
QStringList styles ( const QString & family ) const
*/
HB_FUNC( QFONTDATABASE_STYLES )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QStringList strl = obj->styles ( par1 );
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
int weight ( const QString & family, const QString & style ) const
*/
HB_FUNC( QFONTDATABASE_WEIGHT )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    int i = obj->weight ( par1, par2 );
    hb_retni( i );
  }
}


/*
QList<WritingSystem> writingSystems () const
*/
HB_FUNC( QFONTDATABASE_WRITINGSYSTEMS1 )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QFontDatabase::WritingSystem> list = obj->writingSystems (  );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutNI( NULL, (int) list[i] );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QList<WritingSystem> writingSystems ( const QString & family ) const
*/
HB_FUNC( QFONTDATABASE_WRITINGSYSTEMS2 )
{
  QFontDatabase * obj = (QFontDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QList<QFontDatabase::WritingSystem> list = obj->writingSystems ( par1 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutNI( NULL, (int) list[i] );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


//[1]QList<WritingSystem> writingSystems () const
//[2]QList<WritingSystem> writingSystems ( const QString & family ) const

HB_FUNC( QFONTDATABASE_WRITINGSYSTEMS )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QFONTDATABASE_WRITINGSYSTEMS1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QFONTDATABASE_WRITINGSYSTEMS2 );
  }
}


/*
int addApplicationFont ( const QString & fileName )
*/
HB_FUNC( QFONTDATABASE_ADDAPPLICATIONFONT )
{
  QString par1 = hb_parc(1);
  int i = QFontDatabase::addApplicationFont ( par1 );
  hb_retni( i );
}


/*
int addApplicationFontFromData ( const QByteArray & fontData )
*/
HB_FUNC( QFONTDATABASE_ADDAPPLICATIONFONTFROMDATA )
{
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int i = QFontDatabase::addApplicationFontFromData ( *par1 );
  hb_retni( i );
}


/*
QStringList applicationFontFamilies ( int id )
*/
HB_FUNC( QFONTDATABASE_APPLICATIONFONTFAMILIES )
{
  int par1 = hb_parni(1);
  QStringList strl = QFontDatabase::applicationFontFamilies ( par1 );
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
bool removeAllApplicationFonts ()
*/
HB_FUNC( QFONTDATABASE_REMOVEALLAPPLICATIONFONTS )
{
  bool b = QFontDatabase::removeAllApplicationFonts (  );
  hb_retl( b );
}


/*
bool removeApplicationFont ( int id )
*/
HB_FUNC( QFONTDATABASE_REMOVEAPPLICATIONFONT )
{
  int par1 = hb_parni(1);
  bool b = QFontDatabase::removeApplicationFont ( par1 );
  hb_retl( b );
}


/*
QList<int> standardSizes ()
*/
HB_FUNC( QFONTDATABASE_STANDARDSIZES )
{
  QList<int> list = QFontDatabase::standardSizes (  );
  PHB_ITEM pArray;
  pArray = hb_itemArrayNew(0);
  int i;
  for(i=0;i<list.count();i++)
  {
    PHB_ITEM pItem = hb_itemPutNI( NULL, list[i] );
    hb_arrayAddForward( pArray, pItem );
    hb_itemRelease(pItem);
  }
  hb_itemReturnRelease(pArray);
}


/*
bool supportsThreadedFontRendering ()
*/
HB_FUNC( QFONTDATABASE_SUPPORTSTHREADEDFONTRENDERING )
{
  bool b = QFontDatabase::supportsThreadedFontRendering (  );
  hb_retl( b );
}


/*
QString writingSystemName ( WritingSystem writingSystem )
*/
HB_FUNC( QFONTDATABASE_WRITINGSYSTEMNAME )
{
  int par1 = hb_parni(1);
  QString str1 = QFontDatabase::writingSystemName (  (QFontDatabase::WritingSystem) par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString writingSystemSample ( WritingSystem writingSystem )
*/
HB_FUNC( QFONTDATABASE_WRITINGSYSTEMSAMPLE )
{
  int par1 = hb_parni(1);
  QString str1 = QFontDatabase::writingSystemSample (  (QFontDatabase::WritingSystem) par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}



