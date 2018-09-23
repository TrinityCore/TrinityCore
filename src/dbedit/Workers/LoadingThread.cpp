#include "LoadingThread.h"
#include "advstd.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DatabaseLoader.h"
#include "DBCLoadList.h"
#include "Duration.h"
#include "Globals.h"
#include "LoadingBar.h"
#include "LoadingWindow.h"
#include "Log.h"
#include "MainWindow.h"
#include "MySQLThreading.h"
#include "SpellAccessor.h"
#include "StringFormat.h"
#include "QtHelpers.h"
#include <boost/filesystem/operations.hpp>
#include <string>
#include <thread>

struct LoadingStep
{
    using LoadingFunc = bool(LoadingThread&, std::string&);

    constexpr LoadingStep(char const* label, LoadingFunc* func) : _label(label), _func(func) {}
    constexpr operator char const*() const { return _label; }

    char const* const  _label;
    LoadingFunc* const _func;
};

//// CONFIG LOADING
#ifndef _TRINITY_CORE_CONFIG
    #define _TRINITY_CORE_CONFIG  "worldserver.conf"
#endif

static bool loadConfig(LoadingThread&, std::string& error)
{
    auto configPath = boost::filesystem::absolute(_TRINITY_CORE_CONFIG).generic_string();
    std::string configError;
    if (!sConfigMgr->LoadInitial(configPath, {}, configError))
    {
        error = Trinity::StringFormat("%s:\n%s", configPath, configError);
        return false;
    }
    sLog->Initialize(sConfigMgr->GetBoolDefault("Log.Async.Enable", false) ? sGlobals.IoCtx.get() : nullptr);
    return true;
}

//// DBC LOADING
static bool loadDBC(LoadingThread& loading, std::string& error)
{
    constexpr size_t n = advstd::size(DBCLoads::List);
    for (size_t i = 0; i < n; ++i)
    {
        Q_EMIT loading.SetStepProgress(0, n);
        if (!DBCLoads::List[i].Load())
        {
            error = Trinity::StringFormat("Failed to load data from '%s'.", DBCLoads::List[i].Name());
            return false;
        }
    }
    Q_EMIT loading.SetStepProgress(n, n);
    return true;
}

//// SQL INIT
static bool connectSQL(std::string& error)
{
    MySQL::Library_Init();

    DatabaseLoader loader("server.worldserver", DatabaseLoader::DATABASE_NONE);
    loader.AddDatabase(WorldDatabase, "World");
    if (!loader.Load())
    {
        error = "Database connection failed. See previous console output for details.";
        return false;
    }
    return true;
}

static bool loadDBCFromSQL(std::string& error)
{
    for (auto const& loadEntry : DBCLoads::List)
    {
        if (!loadEntry.HasDB())
            continue;
        if (!loadEntry.LoadDB())
        {
            error = Trinity::StringFormat("Failed to load '%s' data from database.", error);
            return false;
        }
    }
    return true;
}

static constexpr bool (*sqlSteps[])(std::string&) = {
    &connectSQL,
    &loadDBCFromSQL
};

static bool setupSQL(LoadingThread& thread, std::string& error)
{
    size_t constexpr n = advstd::size(sqlSteps);
    Q_EMIT thread.SetStepProgress(0, n);
    for (size_t i = 0; i < n; ++i)
    {
        if (!sqlSteps[i](error))
            return false;
        Q_EMIT thread.SetStepProgress(i, n);
    }
    return true;
}

static bool buildIndex(LoadingThread& thread, std::string& error)
{
    SpellAccessor::BuildIndices();
    return true;
}

static constexpr LoadingStep steps[] = {
    { "CONF", &loadConfig },
    { "DBC", &loadDBC },
    { "MYSQL", &setupSQL },
    { "INDEX", &buildIndex }
};

template <size_t I, typename T, size_t N>
static constexpr T const& arrayget(const T(&array)[N]) { static_assert(I < N, "Invalid index"); return array[I]; }
template <size_t N, size_t... Is>
static constexpr std::array<char const*, N> makelabels(const LoadingStep(&array)[N], std::index_sequence<Is...>)
{
    return { {static_cast<char const*>(arrayget<Is>(array))...} };
}
static constexpr auto stepLabels = makelabels(steps, std::make_index_sequence<advstd::size(steps)>());

void LoadingThread::Load(LoadingWindow& loading)
{
    for (uint16 i = 0; i < advstd::size(steps); ++i)
    {
        LoadingStep const& step = steps[i];
        LoadingBar* bar = loading[i];
        auto c1 = CONNECT(this, StepComplete, bar, Complete);
        auto c2 = CONNECT(this, SetStepProgress, bar, SetProgress);
        Q_EMIT SetStepProgress(0, 0);

        std::string error;
        if (!step._func(*this, error))
        {
            printf("Loading %s failed:\n%s\n", step._label, error.c_str());
            Q_EMIT StepComplete(false);
            Q_EMIT LoadAborted(i);
            return;
        }
        Q_EMIT StepComplete(true);
        DISCONNECT(c1);
        DISCONNECT(c2);
    }
    Q_EMIT LoadComplete();
}

/*static*/ void LoadingThread::BeginLoading(LoadingWindow& loading)
{
    loading.Init(advstd::size(steps), stepLabels.data());
    std::thread([&loading]() {
        LoadingThread loader;
        CONNECT_SAME(&loader, &loading, LoadAborted);
        CONNECT(&loader, LoadComplete, &loading, hide);
        CONNECT(&loader, LoadComplete, sGlobals.MainWindow, Setup);
        loader.Load(loading);
    }).detach();
}
