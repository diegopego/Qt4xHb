/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTimeLine>

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
QTimeLine ( int duration = 1000, QObject * parent = 0 )
*/
HB_FUNC( QTIMELINE_NEW )
{
  QTimeLine * o = NULL;
  int par1 = ISNIL(1)? 1000 : hb_parni(1);
  QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTimeLine ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTimeLine *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTIMELINE_DELETE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int currentFrame () const
*/
HB_FUNC( QTIMELINE_CURRENTFRAME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentFrame (  );
    hb_retni( i );
  }
}


/*
int currentTime () const
*/
HB_FUNC( QTIMELINE_CURRENTTIME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentTime (  );
    hb_retni( i );
  }
}


/*
qreal currentValue () const
*/
HB_FUNC( QTIMELINE_CURRENTVALUE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->currentValue (  );
    hb_retnd( r );
  }
}


/*
CurveShape curveShape () const
*/
HB_FUNC( QTIMELINE_CURVESHAPE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->curveShape (  );
    hb_retni( i );
  }
}


/*
Direction direction () const
*/
HB_FUNC( QTIMELINE_DIRECTION )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->direction (  );
    hb_retni( i );
  }
}


/*
int duration () const
*/
HB_FUNC( QTIMELINE_DURATION )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->duration (  );
    hb_retni( i );
  }
}



/*
int endFrame () const
*/
HB_FUNC( QTIMELINE_ENDFRAME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->endFrame (  );
    hb_retni( i );
  }
}


/*
int frameForTime ( int msec ) const
*/
HB_FUNC( QTIMELINE_FRAMEFORTIME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->frameForTime ( par1 );
    hb_retni( i );
  }
}


/*
int loopCount () const
*/
HB_FUNC( QTIMELINE_LOOPCOUNT )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->loopCount (  );
    hb_retni( i );
  }
}


/*
void setCurveShape ( CurveShape shape )
*/
HB_FUNC( QTIMELINE_SETCURVESHAPE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCurveShape (  (QTimeLine::CurveShape) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDirection ( Direction direction )
*/
HB_FUNC( QTIMELINE_SETDIRECTION )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setDirection (  (QTimeLine::Direction) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDuration ( int duration )
*/
HB_FUNC( QTIMELINE_SETDURATION )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setDuration ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setEasingCurve ( const QEasingCurve & curve )
*/
HB_FUNC( QTIMELINE_SETEASINGCURVE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QEasingCurve * par1 = (QEasingCurve *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setEasingCurve ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setEndFrame ( int frame )
*/
HB_FUNC( QTIMELINE_SETENDFRAME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setEndFrame ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFrameRange ( int startFrame, int endFrame )
*/
HB_FUNC( QTIMELINE_SETFRAMERANGE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setFrameRange ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLoopCount ( int count )
*/
HB_FUNC( QTIMELINE_SETLOOPCOUNT )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setLoopCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStartFrame ( int frame )
*/
HB_FUNC( QTIMELINE_SETSTARTFRAME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setStartFrame ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUpdateInterval ( int interval )
*/
HB_FUNC( QTIMELINE_SETUPDATEINTERVAL )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setUpdateInterval ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int startFrame () const
*/
HB_FUNC( QTIMELINE_STARTFRAME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->startFrame (  );
    hb_retni( i );
  }
}


/*
State state () const
*/
HB_FUNC( QTIMELINE_STATE )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->state (  );
    hb_retni( i );
  }
}


/*
int updateInterval () const
*/
HB_FUNC( QTIMELINE_UPDATEINTERVAL )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->updateInterval (  );
    hb_retni( i );
  }
}


/*
virtual qreal valueForTime ( int msec ) const
*/
HB_FUNC( QTIMELINE_VALUEFORTIME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    qreal r = obj->valueForTime ( par1 );
    hb_retnd( r );
  }
}


/*
void resume ()
*/
HB_FUNC( QTIMELINE_RESUME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->resume (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCurrentTime ( int msec )
*/
HB_FUNC( QTIMELINE_SETCURRENTTIME )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCurrentTime ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPaused ( bool paused )
*/
HB_FUNC( QTIMELINE_SETPAUSED )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setPaused ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void start ()
*/
HB_FUNC( QTIMELINE_START )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->start (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void stop ()
*/
HB_FUNC( QTIMELINE_STOP )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->stop (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void toggleDirection ()
*/
HB_FUNC( QTIMELINE_TOGGLEDIRECTION )
{
  QTimeLine * obj = (QTimeLine *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->toggleDirection (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




