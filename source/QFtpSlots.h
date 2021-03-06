/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQFTP_H
#define SLOTSQFTP_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QFtp>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QFtp_release_codeblocks ();
class SlotsQFtp: public QObject
{
  Q_OBJECT
  public:
  SlotsQFtp(QObject *parent = 0);
  ~SlotsQFtp();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void commandFinished ( int id, bool error );
  void commandStarted ( int id );
  void dataTransferProgress ( qint64 done, qint64 total );
  void done ( bool error );
  void listInfo ( const QUrlInfo & i );
  void rawCommandReply ( int replyCode, const QString & detail );
  void readyRead ();
  void stateChanged ( int state );
};
#endif
