/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSyntaxHighlighter>

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




//[1]QSyntaxHighlighter ( QObject * parent )
//[2]QSyntaxHighlighter ( QTextDocument * parent )
//[3]QSyntaxHighlighter ( QTextEdit * parent )

//HB_FUNC( QSYNTAXHIGHLIGHTER_NEW )
//{
//  if( ISNUMPAR(1) && ISQOBJECT(1) )
//  {
//    HB_FUNC_EXEC(QSYNTAXHIGHLIGHTER_NEW1 );
//    //HB_FUNC_EXEC(QSYNTAXHIGHLIGHTER_NEW2 ); // TODO: implementar
//    //HB_FUNC_EXEC(QSYNTAXHIGHLIGHTER_NEW3 ); // TODO: implementar
//  }
//}

HB_FUNC( QSYNTAXHIGHLIGHTER_DELETE )
{
  QSyntaxHighlighter * obj = (QSyntaxHighlighter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QTextDocument * document () const
*/
HB_FUNC( QSYNTAXHIGHLIGHTER_DOCUMENT )
{
  QSyntaxHighlighter * obj = (QSyntaxHighlighter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextDocument * ptr = obj->document (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTDOCUMENT" );  }
}


/*
void setDocument ( QTextDocument * doc )
*/
HB_FUNC( QSYNTAXHIGHLIGHTER_SETDOCUMENT )
{
  QSyntaxHighlighter * obj = (QSyntaxHighlighter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextDocument * par1 = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDocument ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void rehighlight ()
*/
HB_FUNC( QSYNTAXHIGHLIGHTER_REHIGHLIGHT )
{
  QSyntaxHighlighter * obj = (QSyntaxHighlighter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->rehighlight (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void rehighlightBlock ( const QTextBlock & block )
*/
HB_FUNC( QSYNTAXHIGHLIGHTER_REHIGHLIGHTBLOCK )
{
  QSyntaxHighlighter * obj = (QSyntaxHighlighter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * par1 = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->rehighlightBlock ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




