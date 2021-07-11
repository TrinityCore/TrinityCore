#include "AbstractPlayer.h"
#include "Player.h"
#include "MasterPlayer.h"

template<typename T>
PlayerWrapper<T>::PlayerWrapper(T &pl) : player(pl) {}

template<typename T>
PlayerWrapper<T>::PlayerWrapper(T *pl) : player(*pl) {}

template<typename T>
PlayerWrapper<T>::PlayerWrapper() : player(*((T*)nullptr)) {}

template<typename T>
PlayerWrapper<T>::PlayerWrapper(const PlayerWrapper<T> &other) : player(other.player) {}

template <typename T>
ObjectGuid PlayerWrapper<T>::GetObjectGuid() const { return player.GetObjectGuid(); }
template <typename T>
Team PlayerWrapper<T>::GetTeam() const { return player.GetTeam(); }
template <typename T>
char const* PlayerWrapper<T>::GetName() const { return player.GetName(); }
template <typename T>
uint32 PlayerWrapper<T>::GetZoneId() const { return player.GetZoneId(); }
template <typename T>
uint32 PlayerWrapper<T>::GetAreaId() const { return player.GetAreaId(); }
template <typename T>
uint8 PlayerWrapper<T>::GetClass() const { return player.GetClass(); }
template <typename T>
uint8 PlayerWrapper<T>::GetRace() const { return player.GetRace(); }
template <typename T>
uint32 PlayerWrapper<T>::GetLevel() const { return player.GetLevel(); }
template <typename T>
bool PlayerWrapper<T>::IsAFK() const { return player.IsAFK(); }
template <typename T>
bool PlayerWrapper<T>::IsDND() const { return player.IsDND(); }
template <typename T>
bool PlayerWrapper<T>::IsGameMaster() const { return player.IsGameMaster(); }
template <typename T>
uint8 PlayerWrapper<T>::GetChatTag() const { return player.GetChatTag(); }
template <typename T>
uint32 PlayerWrapper<T>::GetGuildId() const { return player.GetGuildId(); }
template <typename T>
WorldSession* PlayerWrapper<T>::GetSession() const { return player.GetSession(); }
template <typename T>
PlayerSocial* PlayerWrapper<T>::GetSocial() const { return player.GetSocial(); }
template <typename T>
void PlayerWrapper<T>::JoinedChannel(Channel* c) { player.JoinedChannel(c); }
template <typename T>
void PlayerWrapper<T>::LeftChannel(Channel* c) { player.LeftChannel(c); }

template <typename T>
bool PlayerWrapper<T>::ok() const { return (&player) != nullptr; }

// Specializations
template <>
Player* PlayerWrapper<Player>::ToPlayer() const { return &player; }
template <>
MasterPlayer* PlayerWrapper<Player>::ToMasterPlayer() const { return nullptr; }

template <>
Player* PlayerWrapper<MasterPlayer>::ToPlayer() const { return nullptr; }
template <>
MasterPlayer* PlayerWrapper<MasterPlayer>::ToMasterPlayer() const { return &player; }

// Instanciate classes
template class PlayerWrapper<Player>;
template class PlayerWrapper<MasterPlayer>;
