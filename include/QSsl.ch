/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

/*
enum QSsl::AlternateNameEntryType
*/
#define QSsl_EmailEntry                                              0
#define QSsl_DnsEntry                                                1

/*
enum QSsl::EncodingFormat
*/
#define QSsl_Pem                                                     0
#define QSsl_Der                                                     1

/*
enum QSsl::KeyAlgorithm
*/
#define QSsl_Rsa                                                     0
#define QSsl_Dsa                                                     1

/*
enum QSsl::KeyType
*/
#define QSsl_PrivateKey                                              0
#define QSsl_PublicKey                                               1

/*
enum QSsl::SslOption
flags QSsl::SslOptions
*/
#define QSsl_SslOptionDisableEmptyFragments                          0x01
#define QSsl_SslOptionDisableSessionTickets                          0x02
#define QSsl_SslOptionDisableCompression                             0x04
#define QSsl_SslOptionDisableServerNameIndication                    0x08
#define QSsl_SslOptionDisableLegacyRenegotiation                     0x10

/*
enum QSsl::SslProtocol
*/
#define QSsl_SslV3                                                   0
#define QSsl_SslV2                                                   1
#define QSsl_TlsV1                                                   2
#define QSsl_UnknownProtocol                                         -1
#define QSsl_AnyProtocol                                             3
#define QSsl_TlsV1SslV3                                              4
#define QSsl_SecureProtocols                                         5