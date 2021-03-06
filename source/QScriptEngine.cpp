/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QScriptEngine>

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
QScriptEngine ()
*/
HB_FUNC( QSCRIPTENGINE_NEW1 )
{
  QScriptEngine * o = NULL;
  o = new QScriptEngine (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QScriptEngine *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QScriptEngine ( QObject * parent )
*/
HB_FUNC( QSCRIPTENGINE_NEW2 )
{
  QScriptEngine * o = NULL;
  QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QScriptEngine ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QScriptEngine *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QScriptEngine ()
//[2]QScriptEngine ( QObject * parent )

HB_FUNC( QSCRIPTENGINE_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQOBJECT(1) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSCRIPTENGINE_DELETE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void abortEvaluation ( const QScriptValue & result = QScriptValue() )
*/
HB_FUNC( QSCRIPTENGINE_ABORTEVALUATION )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue par1 = ISNIL(1)? QScriptValue() : *(QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->abortEvaluation ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QScriptEngineAgent * agent () const
*/
HB_FUNC( QSCRIPTENGINE_AGENT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptEngineAgent * ptr = obj->agent (  );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTENGINEAGENT" );  }
}


/*
QStringList availableExtensions () const
*/
HB_FUNC( QSCRIPTENGINE_AVAILABLEEXTENSIONS )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->availableExtensions (  );
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
void clearExceptions ()
*/
HB_FUNC( QSCRIPTENGINE_CLEAREXCEPTIONS )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearExceptions (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void collectGarbage ()
*/
HB_FUNC( QSCRIPTENGINE_COLLECTGARBAGE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->collectGarbage (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QScriptContext * currentContext () const
*/
HB_FUNC( QSCRIPTENGINE_CURRENTCONTEXT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptContext * ptr = obj->currentContext (  );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTCONTEXT" );  }
}


/*
QScriptValue defaultPrototype ( int metaTypeId ) const
*/
HB_FUNC( QSCRIPTENGINE_DEFAULTPROTOTYPE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QScriptValue * ptr = new QScriptValue( obj->defaultPrototype ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QScriptValue evaluate ( const QString & program, const QString & fileName = QString(), int lineNumber = 1 )
*/
HB_FUNC( QSCRIPTENGINE_EVALUATE1 )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    int par3 = ISNIL(3)? 1 : hb_parni(3);
    QScriptValue * ptr = new QScriptValue( obj->evaluate ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QScriptValue evaluate ( const QScriptProgram & program )
*/
HB_FUNC( QSCRIPTENGINE_EVALUATE2 )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptProgram * par1 = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QScriptValue * ptr = new QScriptValue( obj->evaluate ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


//[1]QScriptValue evaluate ( const QString & program, const QString & fileName = QString(), int lineNumber = 1 )
//[2]QScriptValue evaluate ( const QScriptProgram & program )

HB_FUNC( QSCRIPTENGINE_EVALUATE )
{
  if( ISBETWEEN(1,3) && ISCHAR(1) && (ISCHAR(2)||ISNIL(2)) && (ISNUM(3)||ISNUM(3)) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_EVALUATE1 );
  }
  else if( ISNUMPAR(1) && ISQSCRIPTPROGRAM(1) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_EVALUATE2 );
  }
}


/*
QScriptValue globalObject () const
*/
HB_FUNC( QSCRIPTENGINE_GLOBALOBJECT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * ptr = new QScriptValue( obj->globalObject (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
bool hasUncaughtException () const
*/
HB_FUNC( QSCRIPTENGINE_HASUNCAUGHTEXCEPTION )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasUncaughtException (  );
    hb_retl( b );
  }
}


/*
QScriptValue importExtension ( const QString & extension )
*/
HB_FUNC( QSCRIPTENGINE_IMPORTEXTENSION )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QScriptValue * ptr = new QScriptValue( obj->importExtension ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QStringList importedExtensions () const
*/
HB_FUNC( QSCRIPTENGINE_IMPORTEDEXTENSIONS )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->importedExtensions (  );
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
void installTranslatorFunctions ( const QScriptValue & object = QScriptValue() )
*/
HB_FUNC( QSCRIPTENGINE_INSTALLTRANSLATORFUNCTIONS )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue par1 = ISNIL(1)? QScriptValue() : *(QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->installTranslatorFunctions ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isEvaluating () const
*/
HB_FUNC( QSCRIPTENGINE_ISEVALUATING )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEvaluating (  );
    hb_retl( b );
  }
}


/*
QScriptValue newArray ( uint length = 0 )
*/
HB_FUNC( QSCRIPTENGINE_NEWARRAY )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    uint par1 = ISNIL(1)? 0 : hb_parni(1);
    QScriptValue * ptr = new QScriptValue( obj->newArray ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}











/*
QScriptValue newRegExp ( const QRegExp & regexp )
*/
HB_FUNC( QSCRIPTENGINE_NEWREGEXP1 )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegExp * par1 = (QRegExp *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QScriptValue * ptr = new QScriptValue( obj->newRegExp ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QScriptValue newRegExp ( const QString & pattern, const QString & flags )
*/
HB_FUNC( QSCRIPTENGINE_NEWREGEXP2 )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QScriptValue * ptr = new QScriptValue( obj->newRegExp ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


//[1]QScriptValue newRegExp ( const QRegExp & regexp )
//[2]QScriptValue newRegExp ( const QString & pattern, const QString & flags )

HB_FUNC( QSCRIPTENGINE_NEWREGEXP )
{
  if( ISNUMPAR(1) && ISQREGEXP(1) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_NEWREGEXP1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_NEWREGEXP2 );
  }
}

/*
QScriptValue newVariant ( const QVariant & value )
*/
HB_FUNC( QSCRIPTENGINE_NEWVARIANT1 )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVariant * par1 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QScriptValue * ptr = new QScriptValue( obj->newVariant ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QScriptValue newVariant ( const QScriptValue & object, const QVariant & value )
*/
HB_FUNC( QSCRIPTENGINE_NEWVARIANT2 )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * par1 = (QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * par2 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QScriptValue * ptr = new QScriptValue( obj->newVariant ( *par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


//[1]QScriptValue newVariant ( const QVariant & value )
//[2]QScriptValue newVariant ( const QScriptValue & object, const QVariant & value )

HB_FUNC( QSCRIPTENGINE_NEWVARIANT )
{
  if( ISNUMPAR(1) && ISQVARIANT(1) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_NEWVARIANT1 );
  }
  else if( ISNUMPAR(2) && ISQSCRIPTVALUE(1) && ISQVARIANT(2) )
  {
    HB_FUNC_EXEC( QSCRIPTENGINE_NEWVARIANT2 );
  }
}

/*
QScriptValue nullValue ()
*/
HB_FUNC( QSCRIPTENGINE_NULLVALUE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * ptr = new QScriptValue( obj->nullValue (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
void popContext ()
*/
HB_FUNC( QSCRIPTENGINE_POPCONTEXT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->popContext (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int processEventsInterval () const
*/
HB_FUNC( QSCRIPTENGINE_PROCESSEVENTSINTERVAL )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->processEventsInterval (  );
    hb_retni( i );
  }
}


/*
QScriptContext * pushContext ()
*/
HB_FUNC( QSCRIPTENGINE_PUSHCONTEXT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptContext * ptr = obj->pushContext (  );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTCONTEXT" );  }
}


/*
void reportAdditionalMemoryCost ( int size )
*/
HB_FUNC( QSCRIPTENGINE_REPORTADDITIONALMEMORYCOST )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->reportAdditionalMemoryCost ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
void setAgent ( QScriptEngineAgent * agent )
*/
HB_FUNC( QSCRIPTENGINE_SETAGENT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptEngineAgent * par1 = (QScriptEngineAgent *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setAgent ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDefaultPrototype ( int metaTypeId, const QScriptValue & prototype )
*/
HB_FUNC( QSCRIPTENGINE_SETDEFAULTPROTOTYPE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QScriptValue * par2 = (QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDefaultPrototype ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGlobalObject ( const QScriptValue & object )
*/
HB_FUNC( QSCRIPTENGINE_SETGLOBALOBJECT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * par1 = (QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGlobalObject ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setProcessEventsInterval ( int interval )
*/
HB_FUNC( QSCRIPTENGINE_SETPROCESSEVENTSINTERVAL )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setProcessEventsInterval ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QScriptValue toObject ( const QScriptValue & value )
*/
HB_FUNC( QSCRIPTENGINE_TOOBJECT )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * par1 = (QScriptValue *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QScriptValue * ptr = new QScriptValue( obj->toObject ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}



/*
QScriptString toStringHandle ( const QString & str )
*/
HB_FUNC( QSCRIPTENGINE_TOSTRINGHANDLE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QScriptString * ptr = new QScriptString( obj->toStringHandle ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTSTRING" );  }
}


/*
QScriptValue uncaughtException () const
*/
HB_FUNC( QSCRIPTENGINE_UNCAUGHTEXCEPTION )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * ptr = new QScriptValue( obj->uncaughtException (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}


/*
QStringList uncaughtExceptionBacktrace () const
*/
HB_FUNC( QSCRIPTENGINE_UNCAUGHTEXCEPTIONBACKTRACE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->uncaughtExceptionBacktrace (  );
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
int uncaughtExceptionLineNumber () const
*/
HB_FUNC( QSCRIPTENGINE_UNCAUGHTEXCEPTIONLINENUMBER )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->uncaughtExceptionLineNumber (  );
    hb_retni( i );
  }
}


/*
QScriptValue undefinedValue ()
*/
HB_FUNC( QSCRIPTENGINE_UNDEFINEDVALUE )
{
  QScriptEngine * obj = (QScriptEngine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QScriptValue * ptr = new QScriptValue( obj->undefinedValue (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSCRIPTVALUE" );  }
}



/*
QScriptSyntaxCheckResult checkSyntax ( const QString & program )
*/
HB_FUNC( QSCRIPTENGINE_CHECKSYNTAX )
{
  QString par1 = hb_parc(1);
  QScriptSyntaxCheckResult * ptr = new QScriptSyntaxCheckResult( QScriptEngine::checkSyntax ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QSCRIPTSYNTAXCHECKRESULT" );}




