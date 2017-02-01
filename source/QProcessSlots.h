/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQPROCESS_H
#define SLOTSQPROCESS_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QProcess>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QProcess_release_codeblocks ();
class SlotsQProcess: public QObject
{
  Q_OBJECT
  public:
  SlotsQProcess(QObject *parent = 0);
  ~SlotsQProcess();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void error ( QProcess::ProcessError error );
  void finished ( int exitCode, QProcess::ExitStatus exitStatus );
  void readyReadStandardError ();
  void readyReadStandardOutput ();
  void started ();
  void stateChanged ( QProcess::ProcessState newState );
};
#endif
