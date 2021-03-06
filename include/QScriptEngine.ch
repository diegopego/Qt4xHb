/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

/*
enum QScriptEngine::QObjectWrapOption
flags QScriptEngine::QObjectWrapOptions
*/
#define QScriptEngine_ExcludeChildObjects                            0x0001
#define QScriptEngine_ExcludeSuperClassMethods                       0x0002
#define QScriptEngine_ExcludeSuperClassProperties                    0x0004
#define QScriptEngine_ExcludeSuperClassContents                      0x0006
#define QScriptEngine_ExcludeDeleteLater                             0x0010
#define QScriptEngine_ExcludeSlots                                   0x0020
#define QScriptEngine_AutoCreateDynamicProperties                    0x0100
#define QScriptEngine_PreferExistingWrapperObject                    0x0200
#define QScriptEngine_SkipMethodsInEnumeration                       0x0008

/*
enum QScriptEngine::ValueOwnership
*/
#define QScriptEngine_QtOwnership                                    0
#define QScriptEngine_ScriptOwnership                                1
#define QScriptEngine_AutoOwnership                                  2
