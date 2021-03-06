/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQAUDIOOUTPUT_H
#define SLOTSQAUDIOOUTPUT_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QAudioOutput>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QAudioOutput_release_codeblocks ();
class SlotsQAudioOutput: public QObject
{
  Q_OBJECT
  public:
  SlotsQAudioOutput(QObject *parent = 0);
  ~SlotsQAudioOutput();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void notify ();
  void stateChanged ( QAudio::State state );
};
#endif
