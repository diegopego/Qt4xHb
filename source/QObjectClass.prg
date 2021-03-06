/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


REQUEST QOBJECT
REQUEST QBYTEARRAY
REQUEST QMETAOBJECT
REQUEST QVARIANT
REQUEST QTHREAD

CLASS QObject

   DATA pointer
   DATA class_id INIT Class_Id_QObject
   DATA class_flags INIT 1
   DATA self_destruction INIT .f.

   METHOD new
   METHOD delete
   METHOD blockSignals
   METHOD children
   METHOD dumpObjectInfo
   METHOD dumpObjectTree
   METHOD dynamicPropertyNames
   METHOD event
   METHOD eventFilter
   METHOD findChild
   METHOD findChildren1
   METHOD findChildren2
   METHOD findChildren
   METHOD inherits
   METHOD installEventFilter
   METHOD isWidgetType
   METHOD killTimer
   METHOD metaObject
   METHOD moveToThread
   METHOD objectName
   METHOD parent
   METHOD property
   METHOD removeEventFilter
   METHOD setObjectName
   METHOD setParent
   METHOD setProperty
   METHOD signalsBlocked
   METHOD startTimer
   METHOD thread
   METHOD deleteLater
   METHOD onCloseEvent
   METHOD onEnterEvent
   METHOD onFocusInEvent
   METHOD onFocusOutEvent
   METHOD onHideEvent
   METHOD onKeyPressEvent
   METHOD onKeyReleaseEvent
   METHOD onLeaveEvent
   METHOD onShowEvent
   METHOD onMouseButtonDblClickEvent
   METHOD onMouseButtonPressEvent
   METHOD onMouseButtonReleaseEvent
   METHOD onMouseMoveEvent
   METHOD onMoveEvent
   METHOD onPaintEvent
   METHOD onResizeEvent
   METHOD onDragEnterEvent
   METHOD onDragLeaveEvent
   METHOD onDragMoveEvent
   METHOD onDropEvent
   METHOD onAccessibilityDescriptionEvent
   METHOD onAccessibilityHelpEvent
   METHOD onAccessibilityPrepareEvent
   METHOD onActionAddedEvent
   METHOD onActionChangedEvent
   METHOD onActionRemovedEvent
   METHOD onActivationChangeEvent
   METHOD onApplicationActivateEvent
   METHOD onApplicationActivatedEvent
   METHOD onApplicationDeactivateEvent
   METHOD onApplicationFontChangeEvent
   METHOD onApplicationLayoutDirectionChangeEvent
   METHOD onApplicationPaletteChangeEvent
   METHOD onApplicationWindowIconChangeEvent
   METHOD onChildAddedEvent
   METHOD onChildInsertedEvent
   METHOD onChildPolishedEvent
   METHOD onChildRemovedEvent
   METHOD onClipboardEvent
   METHOD onCloseSoftwareInputPanelEvent
   METHOD onContentsRectChangeEvent
   METHOD onContextMenuEvent
   METHOD onCursorChangeEvent
   METHOD onDeferredDeleteEvent
   METHOD onEnabledChangeEvent
   METHOD onEnterEditFocusEvent
   METHOD onEnterWhatsThisModeEvent
   METHOD onFileOpenEvent
   METHOD onFontChangeEvent
   METHOD onGrabKeyboardEvent
   METHOD onGrabMouseEvent
   METHOD onGraphicsSceneContextMenuEvent
   METHOD onGraphicsSceneDragEnterEvent
   METHOD onGraphicsSceneDragLeaveEvent
   METHOD onGraphicsSceneDragMoveEvent
   METHOD onGraphicsSceneDropEvent
   METHOD onGraphicsSceneHelpEvent
   METHOD onGraphicsSceneHoverEnterEvent
   METHOD onGraphicsSceneHoverLeaveEvent
   METHOD onGraphicsSceneHoverMoveEvent
   METHOD onGraphicsSceneMouseDoubleClickEvent
   METHOD onGraphicsSceneMouseMoveEvent
   METHOD onGraphicsSceneMousePressEvent
   METHOD onGraphicsSceneMouseReleaseEvent
   METHOD onGraphicsSceneMoveEvent
   METHOD onGraphicsSceneResizeEvent
   METHOD onGraphicsSceneWheelEvent
   METHOD onHideToParentEvent
   METHOD onHoverEnterEvent
   METHOD onHoverLeaveEvent
   METHOD onHoverMoveEvent
   METHOD onIconDragEvent
   METHOD onIconTextChangeEvent
   METHOD onInputMethodEvent
   METHOD onLanguageChangeEvent
   METHOD onLayoutDirectionChangeEvent
   METHOD onLayoutRequestEvent
   METHOD onLeaveEditFocusEvent
   METHOD onLeaveWhatsThisModeEvent
   METHOD onLocaleChangeEvent
   METHOD onNonClientAreaMouseButtonDblClickEvent
   METHOD onNonClientAreaMouseButtonPressEvent
   METHOD onNonClientAreaMouseButtonReleaseEvent
   METHOD onNonClientAreaMouseMoveEvent
   METHOD onMacSizeChangeEvent
   METHOD onMenubarUpdatedEvent
   METHOD onMetaCallEvent
   METHOD onModifiedChangeEvent
   METHOD onMouseTrackingChangeEvent
   METHOD onPaletteChangeEvent
   METHOD onParentAboutToChangeEvent
   METHOD onParentChangeEvent
   METHOD onPolishEvent
   METHOD onPolishRequestEvent
   METHOD onQueryWhatsThisEvent
   METHOD onRequestSoftwareInputPanelEvent
   METHOD onShortcutEvent
   METHOD onShortcutOverrideEvent
   METHOD onShowToParentEvent
   METHOD onSockActEvent
   METHOD onStateMachineSignalEvent
   METHOD onStateMachineWrappedEvent
   METHOD onStatusTipEvent
   METHOD onStyleChangeEvent
   METHOD onTabletMoveEvent
   METHOD onTabletPressEvent
   METHOD onTabletReleaseEvent
   METHOD onOkRequestEvent
   METHOD onTabletEnterProximityEvent
   METHOD onTabletLeaveProximityEvent
   METHOD onTimerEvent
   METHOD onToolBarChangeEvent
   METHOD onToolTipEvent
   METHOD onToolTipChangeEvent
   METHOD onUngrabKeyboardEvent
   METHOD onUngrabMouseEvent
   METHOD onUpdateLaterEvent
   METHOD onUpdateRequestEvent
   METHOD onWhatsThisEvent
   METHOD onWhatsThisClickedEvent
   METHOD onWheelEvent
   METHOD onWinEventActEvent
   METHOD onWindowActivateEvent
   METHOD onWindowBlockedEvent
   METHOD onWindowDeactivateEvent
   METHOD onWindowIconChangeEvent
   METHOD onWindowStateChangeEvent
   METHOD onWindowTitleChangeEvent
   METHOD onWindowUnblockedEvent
   METHOD onZOrderChangeEvent
   METHOD onKeyboardLayoutChangeEvent
   METHOD onDynamicPropertyChangeEvent
   METHOD onTouchBeginEvent
   METHOD onTouchUpdateEvent
   METHOD onTouchEndEvent
   METHOD onWinIdChangeEvent
   METHOD onGestureEvent
   METHOD onGestureOverrideEvent
   METHOD onDestroyed
   METHOD newFrom
   METHOD newFromObject
   METHOD newFromPointer
   METHOD selfDestruction
   METHOD setSelfDestruction
   DESTRUCTOR destroyObject

END CLASS

METHOD newFrom (p) CLASS QObject
   IF valtype(p) == "O"
      ::pointer := p:pointer
      ::self_destruction := .f.
   ELSEIF valtype(p) == "P"
      ::pointer := p
      ::self_destruction := .f.
   ENDIF
RETURN self

METHOD newFromObject (p) CLASS QObject
   ::pointer := p:pointer
   ::self_destruction := .f.
RETURN self

METHOD newFromPointer (p) CLASS QObject
   ::pointer := p
   ::self_destruction := .f.
RETURN self

METHOD selfDestruction () CLASS QObject
RETURN ::self_destruction

METHOD setSelfDestruction (p) CLASS QObject
   IF valtype(p) == "L"
      ::self_destruction := p
   ENDIF
RETURN self

#include "QEvent.ch"

METHOD onCloseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Close, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Close)
   ENDIF
RETURN r

METHOD onEnterEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Enter, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Enter)
   ENDIF
RETURN r

METHOD onFocusInEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_FocusIn, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_FocusIn)
   ENDIF
RETURN r

METHOD onFocusOutEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_FocusOut, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_FocusOut)
   ENDIF
RETURN r

METHOD onHideEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Hide, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Hide)
   ENDIF
RETURN r

METHOD onKeyPressEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_KeyPress, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_KeyPress)
   ENDIF
RETURN r

METHOD onKeyReleaseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_KeyRelease, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_KeyRelease)
   ENDIF
RETURN r

METHOD onLeaveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Leave, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Leave)
   ENDIF
RETURN r

METHOD onShowEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Show, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Show)
   ENDIF
RETURN r

METHOD onMouseButtonDblClickEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MouseButtonDblClick, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MouseButtonDblClick)
   ENDIF
RETURN r

METHOD onMouseButtonPressEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MouseButtonPress, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MouseButtonPress)
   ENDIF
RETURN r

METHOD onMouseButtonReleaseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MouseButtonRelease, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MouseButtonRelease)
   ENDIF
RETURN r

METHOD onMouseMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MouseMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MouseMove)
   ENDIF
RETURN r

METHOD onMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Move, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Move)
   ENDIF
RETURN r

METHOD onPaintEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Paint, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Paint)
   ENDIF
RETURN r

METHOD onResizeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Resize, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Resize)
   ENDIF
RETURN r

METHOD onDragEnterEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_DragEnter, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_DragEnter)
   ENDIF
RETURN r

METHOD onDragLeaveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_DragLeave, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_DragLeave)
   ENDIF
RETURN r

METHOD onDragMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_DragMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_DragMove)
   ENDIF
RETURN r

METHOD onDropEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Drop, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Drop)
   ENDIF
RETURN r

METHOD onAccessibilityDescriptionEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_AccessibilityDescription, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_AccessibilityDescription)
   ENDIF
RETURN r

METHOD onAccessibilityHelpEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_AccessibilityHelp, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_AccessibilityHelp)
   ENDIF
RETURN r

METHOD onAccessibilityPrepareEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_AccessibilityPrepare, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_AccessibilityPrepare)
   ENDIF
RETURN r

METHOD onActionAddedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ActionAdded, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ActionAdded)
   ENDIF
RETURN r

METHOD onActionChangedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ActionChanged, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ActionChanged)
   ENDIF
RETURN r

METHOD onActionRemovedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ActionRemoved, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ActionRemoved)
   ENDIF
RETURN r

METHOD onActivationChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ActivationChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ActivationChange)
   ENDIF
RETURN r

METHOD onApplicationActivateEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationActivate, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationActivate)
   ENDIF
RETURN r

METHOD onApplicationActivatedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationActivated, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationActivated)
   ENDIF
RETURN r

METHOD onApplicationDeactivateEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationDeactivate, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationDeactivate)
   ENDIF
RETURN r

METHOD onApplicationFontChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationFontChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationFontChange)
   ENDIF
RETURN r

METHOD onApplicationLayoutDirectionChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationLayoutDirectionChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationLayoutDirectionChange)
   ENDIF
RETURN r

METHOD onApplicationPaletteChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationPaletteChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationPaletteChange)
   ENDIF
RETURN r

METHOD onApplicationWindowIconChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ApplicationWindowIconChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ApplicationWindowIconChange)
   ENDIF
RETURN r

METHOD onChildAddedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ChildAdded, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ChildAdded)
   ENDIF
RETURN r

METHOD onChildInsertedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ChildInserted, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ChildInserted)
   ENDIF
RETURN r

METHOD onChildPolishedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ChildPolished, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ChildPolished)
   ENDIF
RETURN r

METHOD onChildRemovedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ChildRemoved, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ChildRemoved)
   ENDIF
RETURN r

METHOD onClipboardEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Clipboard, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Clipboard)
   ENDIF
RETURN r

METHOD onCloseSoftwareInputPanelEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_CloseSoftwareInputPanel, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_CloseSoftwareInputPanel)
   ENDIF
RETURN r

METHOD onContentsRectChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ContentsRectChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ContentsRectChange)
   ENDIF
RETURN r

METHOD onContextMenuEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ContextMenu, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ContextMenu)
   ENDIF
RETURN r

METHOD onCursorChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_CursorChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_CursorChange)
   ENDIF
RETURN r

METHOD onDeferredDeleteEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_DeferredDelete, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_DeferredDelete)
   ENDIF
RETURN r

METHOD onEnabledChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_EnabledChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_EnabledChange)
   ENDIF
RETURN r

METHOD onEnterEditFocusEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_EnterEditFocus, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_EnterEditFocus)
   ENDIF
RETURN r

METHOD onEnterWhatsThisModeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_EnterWhatsThisMode, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_EnterWhatsThisMode)
   ENDIF
RETURN r

METHOD onFileOpenEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_FileOpen, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_FileOpen)
   ENDIF
RETURN r

METHOD onFontChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_FontChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_FontChange)
   ENDIF
RETURN r

METHOD onGrabKeyboardEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GrabKeyboard, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GrabKeyboard)
   ENDIF
RETURN r

METHOD onGrabMouseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GrabMouse, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GrabMouse)
   ENDIF
RETURN r

METHOD onGraphicsSceneContextMenuEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneContextMenu, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneContextMenu)
   ENDIF
RETURN r

METHOD onGraphicsSceneDragEnterEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneDragEnter, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneDragEnter)
   ENDIF
RETURN r

METHOD onGraphicsSceneDragLeaveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneDragLeave, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneDragLeave)
   ENDIF
RETURN r

METHOD onGraphicsSceneDragMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneDragMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneDragMove)
   ENDIF
RETURN r

METHOD onGraphicsSceneDropEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneDrop, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneDrop)
   ENDIF
RETURN r

METHOD onGraphicsSceneHelpEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneHelp, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneHelp)
   ENDIF
RETURN r

METHOD onGraphicsSceneHoverEnterEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneHoverEnter, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneHoverEnter)
   ENDIF
RETURN r

METHOD onGraphicsSceneHoverLeaveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneHoverLeave, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneHoverLeave)
   ENDIF
RETURN r

METHOD onGraphicsSceneHoverMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneHoverMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneHoverMove)
   ENDIF
RETURN r

METHOD onGraphicsSceneMouseDoubleClickEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneMouseDoubleClick, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneMouseDoubleClick)
   ENDIF
RETURN r

METHOD onGraphicsSceneMouseMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneMouseMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneMouseMove)
   ENDIF
RETURN r

METHOD onGraphicsSceneMousePressEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneMousePress, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneMousePress)
   ENDIF
RETURN r

METHOD onGraphicsSceneMouseReleaseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneMouseRelease, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneMouseRelease)
   ENDIF
RETURN r

METHOD onGraphicsSceneMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneMove)
   ENDIF
RETURN r

METHOD onGraphicsSceneResizeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneResize, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneResize)
   ENDIF
RETURN r

METHOD onGraphicsSceneWheelEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GraphicsSceneWheel, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GraphicsSceneWheel)
   ENDIF
RETURN r

METHOD onHideToParentEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_HideToParent, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_HideToParent)
   ENDIF
RETURN r

METHOD onHoverEnterEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_HoverEnter, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_HoverEnter)
   ENDIF
RETURN r

METHOD onHoverLeaveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_HoverLeave, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_HoverLeave)
   ENDIF
RETURN r

METHOD onHoverMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_HoverMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_HoverMove)
   ENDIF
RETURN r

METHOD onIconDragEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_IconDrag, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_IconDrag)
   ENDIF
RETURN r

METHOD onIconTextChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_IconTextChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_IconTextChange)
   ENDIF
RETURN r

METHOD onInputMethodEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_InputMethod, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_InputMethod)
   ENDIF
RETURN r

METHOD onLanguageChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_LanguageChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_LanguageChange)
   ENDIF
RETURN r

METHOD onLayoutDirectionChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_LayoutDirectionChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_LayoutDirectionChange)
   ENDIF
RETURN r

METHOD onLayoutRequestEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_LayoutRequest, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_LayoutRequest)
   ENDIF
RETURN r

METHOD onLeaveEditFocusEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_LeaveEditFocus, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_LeaveEditFocus)
   ENDIF
RETURN r

METHOD onLeaveWhatsThisModeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_LeaveWhatsThisMode, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_LeaveWhatsThisMode)
   ENDIF
RETURN r

METHOD onLocaleChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_LocaleChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_LocaleChange)
   ENDIF
RETURN r

METHOD onNonClientAreaMouseButtonDblClickEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseButtonDblClick, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseButtonDblClick)
   ENDIF
RETURN r

METHOD onNonClientAreaMouseButtonPressEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseButtonPress, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseButtonPress)
   ENDIF
RETURN r

METHOD onNonClientAreaMouseButtonReleaseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseButtonRelease, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseButtonRelease)
   ENDIF
RETURN r

METHOD onNonClientAreaMouseMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_NonClientAreaMouseMove)
   ENDIF
RETURN r

METHOD onMacSizeChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MacSizeChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MacSizeChange)
   ENDIF
RETURN r

METHOD onMenubarUpdatedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MenubarUpdated, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MenubarUpdated)
   ENDIF
RETURN r

METHOD onMetaCallEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MetaCall, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MetaCall)
   ENDIF
RETURN r

METHOD onModifiedChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ModifiedChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ModifiedChange)
   ENDIF
RETURN r

METHOD onMouseTrackingChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_MouseTrackingChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_MouseTrackingChange)
   ENDIF
RETURN r

METHOD onPaletteChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_PaletteChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_PaletteChange)
   ENDIF
RETURN r

METHOD onParentAboutToChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ParentAboutToChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ParentAboutToChange)
   ENDIF
RETURN r

METHOD onParentChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ParentChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ParentChange)
   ENDIF
RETURN r

METHOD onPolishEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Polish, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Polish)
   ENDIF
RETURN r

METHOD onPolishRequestEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_PolishRequest, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_PolishRequest)
   ENDIF
RETURN r

METHOD onQueryWhatsThisEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_QueryWhatsThis, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_QueryWhatsThis)
   ENDIF
RETURN r

METHOD onRequestSoftwareInputPanelEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_RequestSoftwareInputPanel, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_RequestSoftwareInputPanel)
   ENDIF
RETURN r

METHOD onShortcutEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Shortcut, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Shortcut)
   ENDIF
RETURN r

METHOD onShortcutOverrideEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ShortcutOverride, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ShortcutOverride)
   ENDIF
RETURN r

METHOD onShowToParentEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ShowToParent, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ShowToParent)
   ENDIF
RETURN r

METHOD onSockActEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_SockAct, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_SockAct)
   ENDIF
RETURN r

METHOD onStateMachineSignalEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_StateMachineSignal, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_StateMachineSignal)
   ENDIF
RETURN r

METHOD onStateMachineWrappedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_StateMachineWrapped, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_StateMachineWrapped)
   ENDIF
RETURN r

METHOD onStatusTipEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_StatusTip, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_StatusTip)
   ENDIF
RETURN r

METHOD onStyleChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_StyleChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_StyleChange)
   ENDIF
RETURN r

METHOD onTabletMoveEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TabletMove, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TabletMove)
   ENDIF
RETURN r

METHOD onTabletPressEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TabletPress, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TabletPress)
   ENDIF
RETURN r

METHOD onTabletReleaseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TabletRelease, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TabletRelease)
   ENDIF
RETURN r

METHOD onOkRequestEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_OkRequest, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_OkRequest)
   ENDIF
RETURN r

METHOD onTabletEnterProximityEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TabletEnterProximity, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TabletEnterProximity)
   ENDIF
RETURN r

METHOD onTabletLeaveProximityEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TabletLeaveProximity, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TabletLeaveProximity)
   ENDIF
RETURN r

METHOD onTimerEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Timer, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Timer)
   ENDIF
RETURN r

METHOD onToolBarChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ToolBarChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ToolBarChange)
   ENDIF
RETURN r

METHOD onToolTipEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ToolTip, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ToolTip)
   ENDIF
RETURN r

METHOD onToolTipChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ToolTipChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ToolTipChange)
   ENDIF
RETURN r

METHOD onUngrabKeyboardEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_UngrabKeyboard, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_UngrabKeyboard)
   ENDIF
RETURN r

METHOD onUngrabMouseEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_UngrabMouse, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_UngrabMouse)
   ENDIF
RETURN r

METHOD onUpdateLaterEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_UpdateLater, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_UpdateLater)
   ENDIF
RETURN r

METHOD onUpdateRequestEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_UpdateRequest, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_UpdateRequest)
   ENDIF
RETURN r

METHOD onWhatsThisEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WhatsThis, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WhatsThis)
   ENDIF
RETURN r

METHOD onWhatsThisClickedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WhatsThisClicked, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WhatsThisClicked)
   ENDIF
RETURN r

METHOD onWheelEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Wheel, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Wheel)
   ENDIF
RETURN r

METHOD onWinEventActEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WinEventAct, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WinEventAct)
   ENDIF
RETURN r

METHOD onWindowActivateEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowActivate, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowActivate)
   ENDIF
RETURN r

METHOD onWindowBlockedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowBlocked, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowBlocked)
   ENDIF
RETURN r

METHOD onWindowDeactivateEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowDeactivate, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowDeactivate)
   ENDIF
RETURN r

METHOD onWindowIconChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowIconChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowIconChange)
   ENDIF
RETURN r

METHOD onWindowStateChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowStateChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowStateChange)
   ENDIF
RETURN r

METHOD onWindowTitleChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowTitleChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowTitleChange)
   ENDIF
RETURN r

METHOD onWindowUnblockedEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WindowUnblocked, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WindowUnblocked)
   ENDIF
RETURN r

METHOD onZOrderChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_ZOrderChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_ZOrderChange)
   ENDIF
RETURN r

METHOD onKeyboardLayoutChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_KeyboardLayoutChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_KeyboardLayoutChange)
   ENDIF
RETURN r

METHOD onDynamicPropertyChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_DynamicPropertyChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_DynamicPropertyChange)
   ENDIF
RETURN r

METHOD onTouchBeginEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TouchBegin, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TouchBegin)
   ENDIF
RETURN r

METHOD onTouchUpdateEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TouchUpdate, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TouchUpdate)
   ENDIF
RETURN r

METHOD onTouchEndEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_TouchEnd, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_TouchEnd)
   ENDIF
RETURN r

METHOD onWinIdChangeEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_WinIdChange, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_WinIdChange)
   ENDIF
RETURN r

METHOD onGestureEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_Gesture, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_Gesture)
   ENDIF
RETURN r

METHOD onGestureOverrideEvent (cb) CLASS QObject
   LOCAL r := .F.
   IF valtype(cb) == "B" .OR. valtype(cb) == "S"
      r := QT_CONNECT_EVENT(::pointer, QEvent_GestureOverride, cb)
   ELSEIF valtype(cb) == "U"
      r := QT_DISCONNECT_EVENT(::pointer, QEvent_GestureOverride)
   ENDIF
RETURN r


PROCEDURE destroyObject () CLASS QObject
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
