/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQFUTUREWATCHERBASE_H
#define SLOTSQFUTUREWATCHERBASE_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QFutureWatcherBase>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QFutureWatcherBase_release_codeblocks ();
class SlotsQFutureWatcherBase: public QObject
{
  Q_OBJECT
  public:
  SlotsQFutureWatcherBase(QObject *parent = 0);
  ~SlotsQFutureWatcherBase();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void started();
  void finished();
  void canceled();
  void paused();
  void resumed();
  void resultReadyAt(int resultIndex);
  void resultsReadyAt(int beginIndex, int endIndex);
  void progressRangeChanged(int minimum, int maximum);
  void progressValueChanged(int progressValue);
  void progressTextChanged(const QString &progressText);
};
#endif
