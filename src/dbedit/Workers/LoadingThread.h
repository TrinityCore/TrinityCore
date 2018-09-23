#ifndef TRINITY_LOADINGTHREAD_H
#define TRINITY_LOADINGTHREAD_H

#include "Define.h"
#include <memory>
#include <QObject>

class LoadingWindow;

class LoadingThread : public QObject
{
    Q_OBJECT

    public:
        static void BeginLoading(LoadingWindow& loading);
        void Load(LoadingWindow& loading);

    Q_SIGNALS:
        void StepComplete(bool success);
        void SetStepProgress(unsigned short cur, unsigned short max);
        void LoadAborted(unsigned short at);
        void LoadComplete();
};

#endif
