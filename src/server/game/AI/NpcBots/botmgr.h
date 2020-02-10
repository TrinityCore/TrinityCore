#ifndef _BOTMGR_H
#define _BOTMGR_H

class Creature;
class Map;
class Player;
class DPSTracker;

struct Position;

enum BotAddResult
{
    BOT_ADD_DISABLED                    = 0x001,
    BOT_ADD_ALREADY_HAVE                = 0x002,
    BOT_ADD_MAX_EXCEED                  = 0x004,
    BOT_ADD_MAX_CLASS_EXCEED            = 0x008,
    BOT_ADD_CANT_AFFORD                 = 0x010,
    BOT_ADD_INSTANCE_LIMIT              = 0x020,
    BOT_ADD_BUSY                        = 0x040,
    BOT_ADD_NOT_AVAILABLE               = 0x080,

    BOT_ADD_SUCCESS                     = 0x100,

    BOT_ADD_FATAL                       = (BOT_ADD_DISABLED | BOT_ADD_CANT_AFFORD | BOT_ADD_MAX_EXCEED | BOT_ADD_MAX_CLASS_EXCEED)
};

enum BotRemoveType
{
    BOT_REMOVE_LOGOUT                   = 0,
    BOT_REMOVE_DISMISS                  = 1,
    BOT_REMOVE_HIDE                     = 2, //NYI
    BOT_REMOVE_UNSUMMON                 = 3,
    BOT_REMOVE_BY_DEFAULT               = BOT_REMOVE_LOGOUT
};

enum BotAttackRange
{
    BOT_ATTACK_RANGE_SHORT              = 1,
    BOT_ATTACK_RANGE_LONG               = 2,
    BOT_ATTACK_RANGE_EXACT              = 3
};

typedef std::unordered_map<ObjectGuid /*guid*/, Creature* /*bot*/> BotMap;

class BotMgr
{
    public:
        BotMgr(Player* const master);
        ~BotMgr();

        Player* GetOwner() const { return _owner; }

        BotMap const* GetBotMap() const { return &_bots; }
        BotMap* GetBotMap() { return &_bots; }

        static bool IsNpcBotModEnabled();
        static bool IsNpcBotDungeonFinderEnabled();
        static bool ShowEquippedCloak();
        static bool ShowEquippedHelm();
        static bool IsClassEnabled(uint8 m_class);
        static bool IsBotStatsLimitsEnabled();
        static float GetBotStatLimitDodge();
        static float GetBotStatLimitParry();
        static float GetBotStatLimitBlock();
        static float GetBotStatLimitCrit();

        static void Initialize();
        static void ReloadConfig();
        static void LoadConfig(bool reload = false);

        //onEvent hooks
        static void OnBotDamageDealt(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellInfo const* spellInfo);
        static void OnBotDispelDealt(Unit* dispeller, Unit* dispelled, uint8 num);
        //mod hooks
        static void ApplyBotEffectMods(Unit const* caster, Unit const* target, SpellInfo const* spellInfo, uint8 effIndex, float& value);
        static float GetBotDamageTakenMod(Creature const* bot, bool magic);
        static float GetBotDamageModPhysical();
        static float GetBotDamageModSpell();

        void Update(uint32 diff);

        Creature* GetBot(ObjectGuid guid) const;
        bool HaveBot() const { return !_bots.empty(); }
        uint8 GetNpcBotsCount() const;
        uint8 GetNpcBotsCountByRole(uint16 roles) const;
        uint8 GetNpcBotSlotByRole(uint16 roles, Creature const* bot) const;
        static uint8 GetMaxNpcBots();
        static uint8 GetNpcBotXpReduction();
        static bool LimitBots(Map const* map);
        bool RestrictBots(Creature const* bot, bool add) const;
        bool IsPartyInCombat() const;
        bool HasBotClass(uint8 botclass) const;
        bool HasBotPetType(uint32 petType) const;

        static uint32 GetNpcBotCost(uint8 level, Creature const* creature);
        static std::string GetNpcBotCostStr(uint8 level, Creature const* creature);

        void OnTeleportFar(uint32 mapId, float x, float y, float z, float ori = 0.f);
        void OnOwnerSetGameMaster(bool on);
        void ReviveAllBots();
        void SendBotCommandState(CommandStates state);
        void RecallAllBots();
        void RecallBot(Creature* bot);
        void KillAllBots();
        void KillBot(Creature* bot);

        void CleanupsBeforeBotDelete(ObjectGuid guid, uint8 removetype = BOT_REMOVE_LOGOUT);
        void RemoveAllBots(uint8 removetype = BOT_REMOVE_LOGOUT);
        void RemoveBot(ObjectGuid guid, uint8 removetype = BOT_REMOVE_LOGOUT);
        BotAddResult AddBot(Creature* bot, bool takeMoney);
        bool AddBotToGroup(Creature* bot);
        bool RemoveBotFromGroup(Creature* bot, uint8 removetype = BOT_REMOVE_LOGOUT);
        bool RemoveAllBotsFromGroup();

        static uint8 GetBotFollowDistDefault() { return 100; }
        uint8 GetBotFollowDist() const { return _followdist; }
        void SetBotFollowDist(uint8 dist) { _followdist = dist; }

        uint8 GetBotExactAttackRange() const { return _exactAttackRange; }
        uint8 GetBotAttackRangeMode() const { return _attackRangeMode; }
        void SetBotAttackRangeMode(uint8 mode, uint8 exactRange = 0) { _attackRangeMode = mode; _setBotExactAttackRange(exactRange); }

        void SetBotsHidden(bool hidden) { _botsHidden = hidden; }

        void SetBotsShouldUpdateStats();
        void UpdatePhaseForBots();
        void UpdatePvPForBots();

        void TrackDamage(Unit const* u, uint32 damage);
        uint32 GetDPSTaken(Unit const* u) const;
        int32 GetHPSTaken(Unit const* unit) const;

        static void ReviveBot(Creature* bot) { _reviveBot(bot); }

        //TELEPORT BETWEEN MAPS
        //CONFIRMEND UNSAFE (charmer,owner)
        static void TeleportBot(Creature* bot, Map* newMap, Position* pos);

    private:
        static void _teleportBot(Creature* bot, Map* newMap, float x, float y, float z, float ori = 0.f);
        static void _reviveBot(Creature* bot);
        void _addBotToRemoveList(ObjectGuid guid);
        void _setBotExactAttackRange(uint8 exactRange) { _exactAttackRange = exactRange; }

        Player* const _owner;
        BotMap _bots;
        std::list<ObjectGuid> _removeList;
        DPSTracker* const _dpstracker;

        uint8 _followdist;
        uint8 _exactAttackRange;
        uint8 _attackRangeMode;

        bool _botsHidden;
};

void AddNpcBotScripts();

#endif
