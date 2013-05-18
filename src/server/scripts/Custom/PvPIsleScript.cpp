#include "ScriptPCH.h"
#include "AccountMgr.h"
#include "Group.h"
 
struct PvPIslandInfo
{
    uint8 killCount;
};
 
enum PvPIsland
{
    AREA_PVP_ISLAND             = 297,
    AREA_WILD_SHORE             = 43,
    ZONE_STRANGLETHORN          = 33,
 
    STRING_HAVE_KILLED_OWN_IP   = 3000,
    STRING_BEEN_KILLED_OWN_IP   = 3001,
    STRING_IN_COMBAT            = 3002,
 
    AURA_SHIELD                 = 13874,
    AURA_SICKNESS               = 15007,
 
    SPELL_BERSERK               = 24378,
    SPELL_FOOD                  = 23493,
    SPELL_SPIRITUAL_IMMUNITY    = 36910,
    SPELL_SUMMON_PET            = 883,
    SPELL_ANCIENT               = 56354,
 
    NPC_GRAVEYARD_TELEPORTER    = 731131,
 
    GAMEOBJECT_BERSERKING       = 1649780,
    GAMEOBJECT_FOOD             = 1649781,
    GAMEOBJECT_ANCIENT          = 1649783,
};
 
const int MAX_PLAYER_SPAWN_POINTS = 20;
static const Position playerSpawnPoint[MAX_PLAYER_SPAWN_POINTS] = 
{
    {-14440.370117f, -327.436340f, 4.410726f, 4.033682f}, 
    {-14458.031250f, -400.549774f, 5.651588f, 2.792751f},
    {-14562.885742f, -416.376160f, 4.161105f, 1.775660f},
    {-14642.311523f, -420.966736f, 4.413083f, 1.053092f},
    {-14702.908203f, -367.112091f, 9.321154f, 0.471897f},
    {-14789.429688f, -429.403656f, 2.861711f, 0.373721f},
    {-14813.887695f, -326.723053f, 3.579038f, 1.214097f},
    {-14887.509766f, -294.846863f, 1.064565f, 0.699661f},
    {-14791.174805f, -201.769150f, 3.947325f, 5.922559f},
    {-14698.623047f, -209.096420f, 6.136950f, 1.964154f},
    {-14600.683594f, -237.837906f, 24.878767f, 2.367067f},
    {-14596.894531f, -324.108398f, 7.765882f, 5.457606f},
    {-14469.694336f, -125.378380f, 1.480512f, 3.934720f},
    {-14462.090820f, -236.318695f, 2.598486f, 3.059000f},
    {-14578.166992f, -79.677177f, 1.055793f, 4.633719f},
    {-14616.090820f, -173.828903f, 7.292589f, 4.712251f},
    {-14702.94335f, -133.077103f, 4.793780f, 5.191337f},
    {-14881.835938f, -174.988205f, 1.377991f, 5.265950f},
    {-14499.936523f, -189.258438f, 10.578790f, 2.736194f},
    {-14851.310547f, -400.764923f, 0.554863f, 1.562001f},
};
 
const int MAX_POWERUP_SPAWN_POINTS = 16;
static const Position powerSpawnPoint[MAX_POWERUP_SPAWN_POINTS] = 
{
    {-14593.151367f, -259.881683f, 12.135949f, 5.246307f}, 
    {-14644.541016f, -301.044098f, 28.396610f, 0.714552f},
    {-14605.218750f, -361.029327f, 7.815827f, 5.362543f},
    {-14689.578125f, -376.613190f, 9.250590f, 1.710440f},
    {-14757.111328f, -379.469177f, 7.059680f, 1.180292f},
    {-14804.214844f, -390.037750f, 5.354475f, 4.863809f},
    {-14823.406250f, -294.898651f, 5.558507f, 1.708864f},
    {-14807.781250f, -225.845657f, 4.053310f, 2.282206f},
    {-14740.757813f, -216.970901f, 4.876597f, 5.345258f},
    {-14702.419922f, -133.974731f, 4.761642f, 5.481915f},
    {-14644.129883f, -137.240311f, 5.689415f, 4.612478f},
    {-14592.359375f, -204.442627f, 15.142118f, 0.166331f},
    {-14484.213867f, -186.565048f, 10.063410f, 0.627370f},
    {-14812.387695f, -383.693542f, 5.5103410f, 3.821413f},
    {-14587.189453f, -446.756470f, 3.4505070f, 0.696409f},
    {-14526.170898f, -316.358124f, 7.5021808f, 5.891276f},
 
};
 
 
class pvp_island_resurrect_event : public BasicEvent
{
    public:
        pvp_island_resurrect_event(Player* victim) : _victim(victim) { }
 
        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _victim->ResurrectPlayer(1.0, false);
	     int32 RespawnPos = urand(0, MAX_PLAYER_SPAWN_POINTS - 1);
            _victim->TeleportTo(0, playerSpawnPoint[RespawnPos].GetPositionX(), playerSpawnPoint[RespawnPos].GetPositionY(), playerSpawnPoint[RespawnPos].GetPositionZ(), playerSpawnPoint[RespawnPos].GetOrientation());
            _victim->ResetAllPowers();
	     _victim->RemoveArenaSpellCooldowns();
	     _victim->CastSpell(_victim, SPELL_SPIRITUAL_IMMUNITY, true);
            return true;
        }
 
    private:
        Player* _victim;
};
 
class pvp_island_resurrect_event_pet : public BasicEvent
{
    public:
        pvp_island_resurrect_event_pet(Player* victim) : _victim(victim) { }
 
        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _victim->CastSpell(_victim, SPELL_SUMMON_PET, false); // Summons last used pet
            return true;
        }
 
    private:
        Player* _victim;
};
 
class pvp_island : public PlayerScript
{
    public:
        pvp_island() : PlayerScript("pvp_island") { }
 
        uint64 killerGUID;
        uint64 victimGUID;
        char msg[500];
 
        void OnLogout(Player* player)
        {
            if (player->GetGUID() == killerGUID)
                return;
        }
 
        // When player leaves PvP Island and his GUID was stored as the GUID of a killer, the group will be reset
        void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
        {
            // Prevent Group
            if (Group* group = player->GetGroup())
	         if (newArea != AREA_PVP_ISLAND)
		      group->Disband(true);

            if (newArea != AREA_PVP_ISLAND || newArea != AREA_WILD_SHORE)
                if (player->GetGUID() == killerGUID)
		      return;
        }
 
        void OnPVPKill(Player* killer, Player* victim)
        {
            if (killer->GetAreaId() == AREA_PVP_ISLAND)
            {
                if (victim->GetAreaId() == AREA_PVP_ISLAND)
                {
                    killerGUID = killer->GetGUID();
                    victimGUID = victim->GetGUID();
 
                    // If player killed himself, do not execute any code (think of when a warlock uses Hellfire, when player falls to dead, etc.)
                    if (killerGUID == victimGUID)
                    {
                        victim->m_Events.AddEvent(new pvp_island_resurrect_event(victim), victim->m_Events.CalculateTime(1000));
 
                        if (victim->getClass() == CLASS_HUNTER || victim->getClass() == CLASS_WARLOCK)
                            victim->m_Events.AddEvent(new pvp_island_resurrect_event_pet(victim), victim->m_Events.CalculateTime(2000));
 
                        return;
                    }

                    // This will cause the victim to be resurrected, teleported and health set to 100% after 1 second of dieing
                    victim->m_Events.AddEvent(new pvp_island_resurrect_event(victim), victim->m_Events.CalculateTime(1000));
 
                    // This will cause warlocks and hunters to have their last-used pet to be re-summoned when arriving on the island
                    if (victim->getClass() == CLASS_HUNTER || victim->getClass() == CLASS_WARLOCK)
                        victim->m_Events.AddEvent(new pvp_island_resurrect_event_pet(victim), victim->m_Events.CalculateTime(2000));

                }
            }
        }
};
 
class npc_summon_powerups : public CreatureScript
{
    public:
        npc_summon_powerups() : CreatureScript("npc_summon_powerups") { }
 
        struct npc_summon_powerupsAI : public ScriptedAI
        {
            npc_summon_powerupsAI(Creature* creature) : ScriptedAI(creature) { }
 
            uint32 summonTimer;
 
            void Reset()
            {
                summonTimer = urand(30000, 60000);
            }
 
            void UpdateAI(const uint32 diff)
            {
                if (summonTimer <= diff)
                {
		      int i;
			
                    i = urand(0, MAX_POWERUP_SPAWN_POINTS - 1);
                    me->SummonGameObject(GAMEOBJECT_BERSERKING, powerSpawnPoint[i].GetPositionX(), powerSpawnPoint[i].GetPositionY(), powerSpawnPoint[i].GetPositionZ(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), 90000);
                    i = urand(0, MAX_POWERUP_SPAWN_POINTS - 1);
                    me->SummonGameObject(GAMEOBJECT_FOOD, powerSpawnPoint[i].GetPositionX(), powerSpawnPoint[i].GetPositionY(), powerSpawnPoint[i].GetPositionZ(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), 90000);
                    i = urand(0, MAX_POWERUP_SPAWN_POINTS - 1);
                    me->SummonGameObject(GAMEOBJECT_ANCIENT, powerSpawnPoint[i].GetPositionX(), powerSpawnPoint[i].GetPositionY(), powerSpawnPoint[i].GetPositionZ(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), powerSpawnPoint[i].GetOrientation(), 90000);
                    summonTimer = urand(45000, 60000);
                }
                else
                    summonTimer -= diff;
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_summon_powerupsAI(creature);
        }
};
 
class go_powerup_berserking : public GameObjectScript
{
    public:
        go_powerup_berserking() : GameObjectScript("go_powerup_berserking") { }
 
        bool OnGossipHello(Player* player, GameObject* go)
        {
            player->CastSpell(player, SPELL_BERSERK, false);
            go->RemoveFromWorld();
            return false;
        }
};
 
class go_powerup_food : public GameObjectScript
{
    public:
        go_powerup_food() : GameObjectScript("go_powerup_food") { }
 
        bool OnGossipHello(Player* player, GameObject* go)
        {
            player->CastSpell(player, SPELL_FOOD, false);
            go->RemoveFromWorld();
            return false;
        }
};

class go_powerup_ancient : public GameObjectScript
{
    public:
        go_powerup_ancient() : GameObjectScript("go_powerup_ancient") { }
 
        bool OnGossipHello(Player* player, GameObject* go)
        {
            player->CastSpell(player, SPELL_ANCIENT, false);
	     player->RemoveArenaSpellCooldowns();
            go->RemoveFromWorld();
            return false;
        }
};
 
class npc_teleport_pvp_island : public CreatureScript
{
    public:
        npc_teleport_pvp_island() : CreatureScript("npc_teleport_pvp_island") { }
 
        struct npc_teleport_pvp_islandAI : public ScriptedAI
        {
            npc_teleport_pvp_islandAI(Creature* creature) : ScriptedAI(creature) { }
 
            void UpdateAI(const uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(0.7f))
                {
                    if (!player || player->IsBeingTeleported() || !player->isAlive() || player->isInCombat())
                        return;

		      // Prevent Group
                    if (Group* group = player->GetGroup())
		      {
		          if (group->GetMembersCount() > 3) 
			       group->Disband(true);
			   
                        if (group->isRaidGroup())
                            group->Disband(true);
		      }

	              player->CastSpell(player, SPELL_SPIRITUAL_IMMUNITY, true);
 
                    int i = urand(0, MAX_PLAYER_SPAWN_POINTS - 1);
                    player->TeleportTo(0, playerSpawnPoint[i].GetPositionX(), playerSpawnPoint[i].GetPositionY(), playerSpawnPoint[i].GetPositionZ(), playerSpawnPoint[i].GetOrientation());
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleport_pvp_islandAI(creature);
        }
};
 
/*class spell_spiritual_immunity : public SpellScriptLoader
{
    public:
        spell_spiritual_immunity() : SpellScriptLoader("spell_spiritual_immunity") { }
 
        class spell_spiritual_immunity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spiritual_immunity_AuraScript);
 
            // cheap hax to make it have update calls
            void CalcPeriodic(AuraEffect const* /*effect*//*, bool& isPeriodic, int32& amplitude)
            {
                isPeriodic = true;
                amplitude = 1 * IN_MILLISECONDS;
            }
 
            void OnPeriodicTick(AuraEffect const* /*effect*//*)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;
 
                if (GetTarget()->GetAreaId() != AREA_WILD_SHORE)
                    GetTarget()->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
            }
 
            void Register()
            {
                DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_spiritual_immunity_AuraScript::CalcPeriodic, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spiritual_immunity_AuraScript::OnPeriodicTick, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY);
            }
        };
 
        AuraScript* GetAuraScript() const
        {
            return new spell_spiritual_immunity_AuraScript();
        }
};*/
 
void AddSC_vitality_pvp_island()
{
    new pvp_island();
    new npc_summon_powerups();
    new go_powerup_berserking();
    new go_powerup_food();
    new go_powerup_ancient();
    new npc_teleport_pvp_island();
    //new spell_spiritual_immunity();
}