/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

/*
enum QDecoration::DecorationRegion
*/
#define QDecoration_All                                              0x7fffffff
#define QDecoration_Top                                              0x0000000002
#define QDecoration_Bottom                                           0x0000000040
#define QDecoration_Left                                             0x0000000008
#define QDecoration_Right                                            0x0000000010
#define QDecoration_TopLeft                                          0x0000000001
#define QDecoration_TopRight                                         0x0000000004
#define QDecoration_BottomLeft                                       0x0000000020
#define QDecoration_BottomRight                                      0x0000000080
#define QDecoration_Borders                                          0x00000000ff
#define QDecoration_Title                                            0x0000000200
#define QDecoration_Close                                            0x0000004000
#define QDecoration_Minimize                                         0x0000000800
#define QDecoration_Maximize                                         0x0000001000
#define QDecoration_Normalize                                        0x0000002000
#define QDecoration_Menu                                             0x0000000100
#define QDecoration_Help                                             0x0000000400
#define QDecoration_Resize                                           0x0000010000
#define QDecoration_Move                                             0x0000008000
#define QDecoration_None                                             0x0000000000

/*
enum QDecoration::DecorationState
*/
#define QDecoration_Normal                                           0x04
#define QDecoration_Disabled                                         0x08
#define QDecoration_Hover                                            0x01
#define QDecoration_Pressed                                          0x02
