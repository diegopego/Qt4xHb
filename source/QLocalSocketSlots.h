/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQLOCALSOCKET_H
#define SLOTSQLOCALSOCKET_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QLocalSocket>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QLocalSocket_release_codeblocks ();
class SlotsQLocalSocket: public QObject
{
  Q_OBJECT
  public:
  SlotsQLocalSocket(QObject *parent = 0);
  ~SlotsQLocalSocket();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void connected ();
  void disconnected ();
  void error ( QLocalSocket::LocalSocketError socketError );
  void stateChanged ( QLocalSocket::LocalSocketState socketState );
};
#endif
