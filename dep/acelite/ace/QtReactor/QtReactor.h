// -*- C++ -*-

//=============================================================================
/**
 *  @file    QtReactor.h
 *
 *  $Id: QtReactor.h 94053 2011-05-11 13:44:41Z mhengstmengel $
 *
 *  @author Hamish Friedlander <ullexco@wave.co.nz>
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_QTREACTOR_H
#define ACE_QTREACTOR_H

#include /**/ "ace/pre.h"

#include "ace/QtReactor/ACE_QtReactor_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Select_Reactor.h"
#include "ace/Map_Manager.h"

#if defined (ACE_HAS_QT4)
# include "QtCore/qglobal.h"
#endif

// QT toolkit specific includes.
#include /**/ <QtGui/QApplication>
#include /**/ <QtCore/QObject>
#include /**/ <QtCore/QSocketNotifier>
#include /**/ <QtCore/QTimer>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_QtReactor
 *
 * @brief An object-oriented event demultiplexor and event handler
 * dispatcher that uses the Qt Library. This class declaration
 * also uses the extension facilities  provided by the Qt. So,
 * readers  of the class declaration should not be upset with
 * the appearence of the Keywords like Q_OBJECT, private slots
 * etc. They are specific to Qt which uses these as a call back
 * methods implementation mechanism.
 *
 * \note Marek Brudka <mbrudka@elka.pw.edu.pl>: ACE_QtReactor was
 * quickly bugfixed to meet ACE 5.4.2 (6.0.0?) deadline.
 * While it passes QtReactor_Test now, there is a great
 * room for improvements as the implementation is rather inefficient
 * and obfuscated
 * To be more specific:
 * - reset_timeout always creates and removes qtimer after each
 * timeout event! Obviously, for fast triggering timers this may
 * lead to excessive memory management.
 * - create/destroy_notifiers_for_handle may also be reworked to
 * establish more clean relations between handles and QSocketNotifiers.
 * - read/write_exception_event disable now SocketNotifier for a while
 * to clear pending events. The cost of this operation is high: two hash
 * acces in ACE and at least two next ones in Qt. This makes QtReator slow,
 * but how clear pending events another way ?
 * - there is qapplication() mutator, which sets new qapplication for
 * QtReactor. This mutator violates implicit assumption about the
 * relations between QTimer and QSocketNotifiers and QApplication for
 * this reactor, namely one may expect that after qapplication(), none
 * of QtReactor artifacts is bound to old qapplication. That's not true
 * now, as QTimer and QSocketNotifiers are not reparent to new
 * QApplication. As a result, the sequence:
 * QApplication *old_qapp = new QApplication(..);
 * QtReactor qreactor( old_qapp);
 * // .. register handlers, schedule_timers etc
 * QApplication *new_qapp = new QApplication(..);
 * qreactor.qpplication( new_qapp );
 * delete old_qapp;
 * almost always leads to problems and memory violation, because
 * QSocketNotifiers are released by old_qapp. Therefore QtReactor
 * should not be reparent now by setting new qapplication.
 * - the lifecycle of Qt objects in ACE contects is rather mysterious
 * and should be made more explicit.
 * - valgrind reports a small memory leak in QtReactor_Test, though as for now
 * it is not clear if the leak is introduced by  QtReactor, or rather incorrect
 * memory management in QtReactor_Test.
 */
class ACE_QtReactor_Export ACE_QtReactor
  : public QObject,
    public ACE_Select_Reactor
{

    Q_OBJECT

public:
    /** \brief Constructor follows  @ACE_Select_Reactor
        \param QApplication *qapp, qapplication which runs events loop
    */
    ACE_QtReactor (QApplication *qapp = 0,
        ACE_Sig_Handler * = 0,
        ACE_Timer_Queue * = 0,
        int disable_notify_pipe = 0,
        ACE_Reactor_Notify *notify = 0,
        bool mask_signals = true,
        int s_queue = ACE_SELECT_TOKEN::FIFO);

    /** \brief Constructor follows @ACE_Select_Reactor
        \param QApplication *qapp, qapplication which runs events loop
    */
    ACE_QtReactor (size_t size,
        QApplication *qapp = 0,
        bool restart = false,
        ACE_Sig_Handler * = 0,
        ACE_Timer_Queue * = 0,
        int disable_notify_pipe = 0,
        ACE_Reactor_Notify *notify = 0,
        bool mask_signals = true,
        int s_queue = ACE_SELECT_TOKEN::FIFO);

    virtual ~ACE_QtReactor (void);

    void qapplication (QApplication *qapp);

    // = Timer operations.
    virtual long schedule_timer (ACE_Event_Handler *handler,
        const void *arg,
        const ACE_Time_Value &delay_time,
        const ACE_Time_Value &interval);

    virtual int  cancel_timer (ACE_Event_Handler *handler,
        int dont_call_handle_close = 1);

    virtual int  cancel_timer (long timer_id,
        const void **arg = 0,
        int dont_call_handle_close = 1);

protected:

    // = Register timers/handles with Qt

    /// Register a single @a handler.
    virtual int register_handler_i (ACE_HANDLE handle,
        ACE_Event_Handler *handler,
        ACE_Reactor_Mask mask);

    /// Register a set of <handlers> with Qt.
    virtual int register_handler_i (const ACE_Handle_Set &handles,
        ACE_Event_Handler *handler,
        ACE_Reactor_Mask mask);


    /// Remove the <handler> associated with this @a handle.
    virtual int remove_handler_i (ACE_HANDLE handle,
        ACE_Reactor_Mask mask);

    /// Remove a set of <handles>.
    virtual int remove_handler_i (const ACE_Handle_Set &handles,
        ACE_Reactor_Mask mask);

    /// Wait for events to occur.
    virtual int wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &handle_set,
        ACE_Time_Value *max_wait_time);

    virtual int QtWaitForMultipleEvents (int width,
        ACE_Select_Reactor_Handle_Set &wait_set,
        ACE_Time_Value *max_wait_time);

    virtual int bit_ops (ACE_HANDLE handle,
        ACE_Reactor_Mask mask,
        ACE_Select_Reactor_Handle_Set &handle_set,
        int ops);

    int set_enable_flag_by_mask (int flag_value, ACE_HANDLE handle, ACE_Reactor_Mask mask);
    void create_notifiers_for_handle (ACE_HANDLE handle);
    void destroy_notifiers_for_handle (ACE_HANDLE handle);

    // Wait for Qt events to occur

    /// Some Qt stuff that we need to have
    QApplication *qapp_ ;

    /// Typedef of a map.
    typedef ACE_Map_Manager<ACE_HANDLE, QSocketNotifier *, ACE_Null_Mutex> MAP;

    /// A notifier for a read
    MAP read_notifier_;

    /// A write notifier
    MAP write_notifier_;

    /// An exception notifier
    MAP exception_notifier_;

    /// The timer class that would provide timer-sgnals & single-shot timers
    QTimer *qtime_ ;

private:
    /// This method ensures there's an Qt timeout for the first timeout
    /// in the Reactor's Timer_Queue.
    void reset_timeout (void);
    /// reopens notification pipe to create SocketNotifier for it
    void reopen_notification_pipe(void);
    /// Deny access since member-wise won't work...
    ACE_QtReactor (const ACE_QtReactor &);
    ACE_QtReactor &operator= (const ACE_QtReactor &);

private slots:

    // These are all part of the communication mechanism adopted in Qt.
    /// Dispatch a Read Event
    void read_event (int FD);

    /// Dispatch a Write Event
    void write_event (int FD);

    /// Dispatch an exception event
    void exception_event (int FD);

    /// Dispatch a timeout event
    void timeout_event (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_QTREACTOR_H */
