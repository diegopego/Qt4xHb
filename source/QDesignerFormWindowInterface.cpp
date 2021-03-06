/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDesignerFormWindowInterface>

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

#include <QDir>


HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_DELETE )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QDir absoluteDir () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_ABSOLUTEDIR )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDir * ptr = new QDir( obj->absoluteDir (  ) );
    _qt4xhb_createReturnClass ( ptr, "QDIR", true );  }
}


/*
virtual void addResourceFile ( const QString & path ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_ADDRESOURCEFILE )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->addResourceFile ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QString author () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_AUTHOR )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->author (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QString comment () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_COMMENT )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->comment (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QString contents () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_CONTENTS )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->contents (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QDesignerFormEditorInterface * core () const
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_CORE )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormEditorInterface * ptr = obj->core (  );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMEDITORINTERFACE" );  }
}


/*
virtual QDesignerFormWindowCursorInterface * cursor () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_CURSOR )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDesignerFormWindowCursorInterface * ptr = obj->cursor (  );
    _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWCURSORINTERFACE" );  }
}


/*
virtual void emitSelectionChanged () = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_EMITSELECTIONCHANGED )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->emitSelectionChanged (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QString exportMacro () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_EXPORTMACRO )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->exportMacro (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual Feature features () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_FEATURES )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->features (  );
    hb_retni( i );
  }
}


/*
virtual QString fileName () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_FILENAME )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->fileName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QPoint grid () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_GRID )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * ptr = new QPoint( obj->grid (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
virtual bool hasFeature ( Feature feature ) const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_HASFEATURE )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->hasFeature (  (QDesignerFormWindowInterface::Feature) par1 );
    hb_retl( b );
  }
}


/*
virtual QStringList includeHints () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_INCLUDEHINTS )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->includeHints (  );
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
virtual bool isDirty () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_ISDIRTY )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isDirty (  );
    hb_retl( b );
  }
}


/*
virtual bool isManaged ( QWidget * widget ) const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_ISMANAGED )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isManaged ( par1 );
    hb_retl( b );
  }
}


/*
virtual void layoutDefault ( int * margin, int * spacing ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_LAYOUTDEFAULT )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1;
    int par2;
    obj->layoutDefault ( &par1, &par2 );
    hb_storni( par1, 1 );
    hb_storni( par2, 2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
virtual QWidget * mainContainer () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_MAINCONTAINER )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->mainContainer (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual QString pixmapFunction () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_PIXMAPFUNCTION )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->pixmapFunction (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual void removeResourceFile ( const QString & path ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_REMOVERESOURCEFILE )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->removeResourceFile ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QStringList resourceFiles () const = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_RESOURCEFILES )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->resourceFiles (  );
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
virtual void setAuthor ( const QString & author ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETAUTHOR )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setAuthor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setComment ( const QString & comment ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETCOMMENT )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setComment ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setContents ( QIODevice * device ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETCONTENTS1 )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setContents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setExportMacro ( const QString & exportMacro ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETEXPORTMACRO )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setExportMacro ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setIncludeHints ( const QStringList & includeHints ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETINCLUDEHINTS )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
    obj->setIncludeHints ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setLayoutDefault ( int margin, int spacing ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETLAYOUTDEFAULT )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setLayoutDefault ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setLayoutFunction ( const QString & margin, const QString & spacing ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETLAYOUTFUNCTION )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->setLayoutFunction ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setMainContainer ( QWidget * mainContainer ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETMAINCONTAINER )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMainContainer ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setPixmapFunction ( const QString & pixmapFunction ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETPIXMAPFUNCTION )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setPixmapFunction ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void clearSelection ( bool update = true ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_CLEARSELECTION )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = ISNIL(1)? true : hb_parl(1);
    obj->clearSelection ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void manageWidget ( QWidget * widget ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_MANAGEWIDGET )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->manageWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void selectWidget ( QWidget * widget, bool select = true ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SELECTWIDGET )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->selectWidget ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setContents ( const QString & contents ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETCONTENTS2 )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setContents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]virtual void setContents ( QIODevice * device ) = 0
//[2]virtual void setContents ( const QString & contents ) = 0

HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETCONTENTS )
{
  if( ISNUMPAR(1) && ISQIODEVICE(1) )
  {
    HB_FUNC_EXEC( QDESIGNERFORMWINDOWINTERFACE_SETCONTENTS1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QDESIGNERFORMWINDOWINTERFACE_SETCONTENTS2 );
  }
}

/*
virtual void setDirty ( bool dirty ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETDIRTY )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setDirty ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setFeatures ( Feature features ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETFEATURES )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFeatures (  (QDesignerFormWindowInterface::Feature) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setFileName ( const QString & fileName ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETFILENAME )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setFileName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setGrid ( const QPoint & grid ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_SETGRID )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGrid ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void unmanageWidget ( QWidget * widget ) = 0
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_UNMANAGEWIDGET )
{
  QDesignerFormWindowInterface * obj = (QDesignerFormWindowInterface *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->unmanageWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
QDesignerFormWindowInterface * findFormWindow ( QWidget * widget )
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_FINDFORMWINDOW1 )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QDesignerFormWindowInterface * ptr = QDesignerFormWindowInterface::findFormWindow ( par1 );
  _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWINTERFACE" );}


/*
QDesignerFormWindowInterface * findFormWindow ( QObject * object )
*/
HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_FINDFORMWINDOW2 )
{
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QDesignerFormWindowInterface * ptr = QDesignerFormWindowInterface::findFormWindow ( par1 );
  _qt4xhb_createReturnClass ( ptr, "QDESIGNERFORMWINDOWINTERFACE" );}


//[1]QDesignerFormWindowInterface * findFormWindow ( QWidget * widget )
//[2]QDesignerFormWindowInterface * findFormWindow ( QObject * object )

HB_FUNC( QDESIGNERFORMWINDOWINTERFACE_FINDFORMWINDOW )
{
  if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QDESIGNERFORMWINDOWINTERFACE_FINDFORMWINDOW1 );
  }
  else if( ISNUMPAR(1) && ISQOBJECT(1) )
  {
    HB_FUNC_EXEC( QDESIGNERFORMWINDOWINTERFACE_FINDFORMWINDOW2 );
  }
}



