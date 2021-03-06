/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQACTIONGROUP_H
#define SLOTSQACTIONGROUP_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QActionGroup>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QActionGroup_release_codeblocks ();
class SlotsQActionGroup: public QObject
{
  Q_OBJECT
  public:
  SlotsQActionGroup(QObject *parent = 0);
  ~SlotsQActionGroup();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void hovered ( QAction * action );
  void triggered ( QAction * action );
};
#endif
