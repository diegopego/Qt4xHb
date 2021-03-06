/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QHelpSearchQuery>

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
QHelpSearchQuery ()
*/
HB_FUNC( QHELPSEARCHQUERY_NEW1 )
{
  QHelpSearchQuery * o = NULL;
  o = new QHelpSearchQuery (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QHelpSearchQuery *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QHelpSearchQuery ( FieldName field, const QStringList & wordList )
*/
HB_FUNC( QHELPSEARCHQUERY_NEW2 )
{
  QHelpSearchQuery * o = NULL;
  int par1 = hb_parni(1);
QStringList par2;
PHB_ITEM aStrings2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aStrings2);
for (i2=0;i2<nLen2;i2++)
{
QString temp = hb_arrayGetCPtr(aStrings2, i2+1);
par2 << temp;
}
  o = new QHelpSearchQuery (  (QHelpSearchQuery::FieldName) par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QHelpSearchQuery *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QHelpSearchQuery ()
//[2]QHelpSearchQuery ( FieldName field, const QStringList & wordList )

HB_FUNC( QHELPSEARCHQUERY_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QHELPSEARCHQUERY_NEW1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISARRAY(2) )
  {
    HB_FUNC_EXEC( QHELPSEARCHQUERY_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}



