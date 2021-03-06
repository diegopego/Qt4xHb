/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAxScriptEngine>

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
QAxScriptEngine ( const QString & language, QAxScript * script )
*/
HB_FUNC( QAXSCRIPTENGINE_NEW )
{
  QAxScriptEngine * o = NULL;
  QString par1 = hb_parc(1);
  QAxScript * par2 = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QAxScriptEngine ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QAxScriptEngine *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QAXSCRIPTENGINE_DELETE )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addItem ( const QString & name )
*/
HB_FUNC( QAXSCRIPTENGINE_ADDITEM )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->addItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool hasIntrospection () const
*/
HB_FUNC( QAXSCRIPTENGINE_HASINTROSPECTION )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasIntrospection (  );
    hb_retl( b );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QAXSCRIPTENGINE_ISVALID )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}



/*
QString scriptLanguage () const
*/
HB_FUNC( QAXSCRIPTENGINE_SCRIPTLANGUAGE )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->scriptLanguage (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setState ( State st )
*/
HB_FUNC( QAXSCRIPTENGINE_SETSTATE )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setState (  (QAxScriptEngine::State) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
State state () const
*/
HB_FUNC( QAXSCRIPTENGINE_STATE )
{
  QAxScriptEngine * obj = (QAxScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->state (  );
    hb_retni( i );
  }
}




