/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQNETWORKREPLY_H
#define SLOTSQNETWORKREPLY_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QNetworkReply>
#include <QSslError>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QNetworkReply_release_codeblocks ();
class SlotsQNetworkReply: public QObject
{
  Q_OBJECT
  public:
  SlotsQNetworkReply(QObject *parent = 0);
  ~SlotsQNetworkReply();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void downloadProgress ( qint64 bytesReceived, qint64 bytesTotal );
  void error ( QNetworkReply::NetworkError code );
  void finished ();
  void metaDataChanged ();
  void sslErrors ( const QList<QSslError> & errors );
  void uploadProgress ( qint64 bytesSent, qint64 bytesTotal );
};
#endif
