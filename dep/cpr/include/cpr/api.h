#ifndef CPR_API_H
#define CPR_API_H

#include <functional>
#include <future>
#include <string>

#include "cpr/auth.h"
#include "cpr/cprtypes.h"
#include "cpr/defines.h"
#include "cpr/digest.h"
#include "cpr/multipart.h"
#include "cpr/payload.h"
#include "cpr/response.h"
#include "cpr/session.h"

namespace cpr {

using AsyncResponse = std::future<Response>;

namespace priv {

template <typename T>
void set_option(Session& session, T&& t) {
    session.SetOption(CPR_FWD(t));
}

template <typename T, typename... Ts>
void set_option(Session& session, T&& t, Ts&&... ts) {
    set_option(session, CPR_FWD(t));
    set_option(session, CPR_FWD(ts)...);
}

} // namespace priv

// Get methods
template <typename... Ts>
Response Get(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Get();
}

// Get async methods
template <typename... Ts>
AsyncResponse GetAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Get(std::move(ts)...); },
                      std::move(ts)...);
}

// Get callback methods
template <typename Then, typename... Ts>
auto GetCallback(Then then, Ts... ts) -> std::future<decltype(then(Get(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Get(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

// Post methods
template <typename... Ts>
Response Post(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Post();
}

// Post async methods
template <typename... Ts>
AsyncResponse PostAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Post(std::move(ts)...); },
                      std::move(ts)...);
}

// Post callback methods
template <typename Then, typename... Ts>
auto PostCallback(Then then, Ts... ts) -> std::future<decltype(then(Post(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Post(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

// Put methods
template <typename... Ts>
Response Put(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Put();
}

// Put async methods
template <typename... Ts>
AsyncResponse PutAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Put(std::move(ts)...); },
                      std::move(ts)...);
}

// Put callback methods
template <typename Then, typename... Ts>
auto PutCallback(Then then, Ts... ts) -> std::future<decltype(then(Put(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Put(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

// Head methods
template <typename... Ts>
Response Head(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Head();
}

// Head async methods
template <typename... Ts>
AsyncResponse HeadAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Head(std::move(ts)...); },
                      std::move(ts)...);
}

// Head callback methods
template <typename Then, typename... Ts>
auto HeadCallback(Then then, Ts... ts) -> std::future<decltype(then(Head(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Head(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

// Delete methods
template <typename... Ts>
Response Delete(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Delete();
}

// Delete async methods
template <typename... Ts>
AsyncResponse DeleteAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Delete(std::move(ts)...); },
                      std::move(ts)...);
}

// Delete callback methods
template <typename Then, typename... Ts>
auto DeleteCallback(Then then, Ts... ts) -> std::future<decltype(then(Delete(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Delete(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

// Options methods
template <typename... Ts>
Response Options(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Options();
}

// Options async methods
template <typename... Ts>
AsyncResponse OptionsAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Options(std::move(ts)...); },
                      std::move(ts)...);
}

// Options callback methods
template <typename Then, typename... Ts>
auto OptionsCallback(Then then, Ts... ts)
        -> std::future<decltype(then(Options(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Options(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

// Patch methods
template <typename... Ts>
Response Patch(Ts&&... ts) {
    Session session;
    priv::set_option(session, CPR_FWD(ts)...);
    return session.Patch();
}

// Patch async methods
template <typename... Ts>
AsyncResponse PatchAsync(Ts... ts) {
    return std::async(std::launch::async, [](Ts... ts) { return Patch(std::move(ts)...); },
                      std::move(ts)...);
}

// Patch callback methods
template <typename Then, typename... Ts>
auto PatchCallback(Then then, Ts... ts) -> std::future<decltype(then(Patch(std::move(ts)...)))> {
    return std::async(std::launch::async, [](Then then, Ts... ts) {
        return then(Patch(std::move(ts)...));
    }, std::move(then), std::move(ts)...);
}

} // namespace cpr

#endif
