/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QScriptProgram>

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
QScriptProgram ()
*/
HB_FUNC( QSCRIPTPROGRAM_NEW1 )
{
  QScriptProgram * o = NULL;
  o = new QScriptProgram (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QScriptProgram *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QScriptProgram ( const QString & sourceCode, const QString fileName = QString(), int firstLineNumber = 1 )
*/
HB_FUNC( QSCRIPTPROGRAM_NEW2 )
{
  QScriptProgram * o = NULL;
  QString par1 = hb_parc(1);
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  int par3 = ISNIL(3)? 1 : hb_parni(3);
  o = new QScriptProgram ( par1, par2, par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QScriptProgram *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QScriptProgram ( const QScriptProgram & other )
*/
HB_FUNC( QSCRIPTPROGRAM_NEW3 )
{
  QScriptProgram * o = NULL;
  QScriptProgram * par1 = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QScriptProgram ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QScriptProgram *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QScriptProgram ()
//[2]QScriptProgram ( const QString & sourceCode, const QString fileName = QString(), int firstLineNumber = 1 )
//[3]QScriptProgram ( const QScriptProgram & other )

HB_FUNC( QSCRIPTPROGRAM_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QSCRIPTPROGRAM_NEW1 );
  }
  else if( ISBETWEEN(1,3) && ISCHAR(1) && (ISCHAR(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QSCRIPTPROGRAM_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQSCRIPTPROGRAM(1) )
  {
    HB_FUNC_EXEC( QSCRIPTPROGRAM_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSCRIPTPROGRAM_DELETE )
{
  QScriptProgram * obj = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QString fileName () const
*/
HB_FUNC( QSCRIPTPROGRAM_FILENAME )
{
  QScriptProgram * obj = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->fileName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int firstLineNumber () const
*/
HB_FUNC( QSCRIPTPROGRAM_FIRSTLINENUMBER )
{
  QScriptProgram * obj = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->firstLineNumber (  );
    hb_retni( i );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QSCRIPTPROGRAM_ISNULL )
{
  QScriptProgram * obj = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
QString sourceCode () const
*/
HB_FUNC( QSCRIPTPROGRAM_SOURCECODE )
{
  QScriptProgram * obj = (QScriptProgram *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->sourceCode (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}




