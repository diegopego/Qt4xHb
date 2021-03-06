/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTranslator>

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

#include <QLocale>

/*
QTranslator(QObject * parent = 0)
*/
HB_FUNC( QTRANSLATOR_NEW )
{
  QTranslator * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTranslator ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTranslator *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTRANSLATOR_DELETE )
{
  QTranslator * obj = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual bool isEmpty() const
*/
HB_FUNC( QTRANSLATOR_ISEMPTY )
{
  QTranslator * obj = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEmpty (  );
    hb_retl( b );
  }
}


/*
bool load(const QString & filename, const QString & directory = QString(), const QString & search_delimiters = QString(), const QString & suffix = QString())
*/
HB_FUNC( QTRANSLATOR_LOAD1 )
{
  QTranslator * obj = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QString par3 = ISNIL(3)? QString() : hb_parc(3);
    QString par4 = ISNIL(4)? QString() : hb_parc(4);
    bool b = obj->load ( par1, par2, par3, par4 );
    hb_retl( b );
  }
}


/*
bool load(const QLocale & locale, const QString & filename, const QString & prefix = QString(), const QString & directory = QString(), const QString & suffix = QString())
*/
HB_FUNC( QTRANSLATOR_LOAD2 )
{
  QTranslator * obj = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLocale * par1 = (QLocale *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    QString par3 = ISNIL(3)? QString() : hb_parc(3);
    QString par4 = ISNIL(4)? QString() : hb_parc(4);
    QString par5 = ISNIL(5)? QString() : hb_parc(5);
    bool b = obj->load ( *par1, par2, par3, par4, par5 );
    hb_retl( b );
  }
}



//[1]bool load(const QString & filename, const QString & directory = QString(), const QString & search_delimiters = QString(), const QString & suffix = QString())
//[2]bool load(const QLocale & locale, const QString & filename, const QString & prefix = QString(), const QString & directory = QString(), const QString & suffix = QString())
//[3]bool load(const uchar * data, int len, const QString & directory = QString())

HB_FUNC( QTRANSLATOR_LOAD )
{
  if( ISBETWEEN(1,4) && ISCHAR(1) && (ISCHAR(2)||ISNIL(2)) && (ISCHAR(3)||ISNIL(3)) && (ISCHAR(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QTRANSLATOR_LOAD1 );
  }
  else if( ISBETWEEN(2,5) && ISQLOCALE(1) && ISCHAR(2) && (ISCHAR(3)||ISNIL(3)) && (ISCHAR(4)||ISNIL(4)) && (ISCHAR(5)||ISNIL(5)) )
  {
    HB_FUNC_EXEC( QTRANSLATOR_LOAD2 );
  }
  //else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  //{
  //  HB_FUNC_EXEC( QTRANSLATOR_LOAD3 );
  //}
  //else if( ISNUMPAR(3) && ISCHAR(1) && ISNUM(2) && (ISCHAR(3)||ISNIL(3)) )
  //{
  //  HB_FUNC_EXEC( QTRANSLATOR_LOAD3 );
  //}
}

/*
virtual QString translate(const char * context, const char * sourceText, const char * disambiguation = 0, int n = -1) const
*/
HB_FUNC( QTRANSLATOR_TRANSLATE )
{
  QTranslator * obj = (QTranslator *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    const char * par2 = hb_parc(2);
    const char * par3 = hb_parc(3);
    int par4 = ISNIL(4)? -1 : hb_parni(4);
    QString str1 = obj->translate (  (const char *) par1,  (const char *) par2,  (const char *) par3, par4 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}



