/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQGRAPHICSEFFECT_H
#define SLOTSQGRAPHICSEFFECT_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QGraphicsEffect>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QGraphicsEffect_release_codeblocks ();
class SlotsQGraphicsEffect: public QObject
{
  Q_OBJECT
  public:
  SlotsQGraphicsEffect(QObject *parent = 0);
  ~SlotsQGraphicsEffect();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void enabledChanged ( bool enabled );
};
#endif
