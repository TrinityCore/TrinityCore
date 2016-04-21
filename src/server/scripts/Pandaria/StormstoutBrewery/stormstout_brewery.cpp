#include "stormstout_brewery.h"
#include "MoveSpline.h"

/********************************************************/
/********************* OOK OOK **************************/
/********************************************************/

/** Dialogue :
 *  Auntie : Oh hello Zan, it is good of you...
 *  Chen : I am not Zan - I am Chen
 *  Auntie : Oh Zan, you remind
 *  Chen : Tell me what has happened here
 *  Auntie : it is certainly a nice day outside
 *  Chen : Where are the others Stormstout
 *  Auntie : Have you seen the size of
 *  Chen : Auntie Stormstout... why is the brewery abandonned ?
 *  Auntie : Abandonned ? Oh heavens
 *  Chen : I see and where is uncle gao ?
 *  Auntie : I have some cookies for you
 *  Chen : There is no time for cookies
 *  Chen : Wait these are...
 */

#define DIALOGUE_STOP_TIMER 0xFFFFFF

class npc_chen_stormstout : public CreatureScript
{
public :
    npc_chen_stormstout() : CreatureScript("npc_chen_stormstout")
    {

    }

    class npc_chen_stormstoutAI : public ScriptedAI
    {
    public :
        npc_chen_stormstoutAI(Creature* creature) : ScriptedAI(creature)
        {
            m_uiTalkId = 0 ;
            m_bCanTalk = true ;
        }

        void DoAction(int32 action)
        {
            if(action == 1 && m_bCanTalk)
            {
                m_bCanTalk = false ;
                m_uiTalkTimer = 8000 ; // Before SAY_1 : 2 s wait + 6 sec Auntie
                if(Creature* auntie = me->FindNearestCreature(59822, 40.0f, true))
                    auntie->AI()->DoAction(1);
            }
        }

        void UpdateAI(uint32 diff)
        {
            // Return since the dialogue is ended
            if(m_uiTalkTimer == DIALOGUE_STOP_TIMER)
                return ;

            if(m_uiTalkTimer <= diff)
            {
                Talk(m_uiTalkId);
                switch(m_uiTalkId)
                {
                case 0 : // After "I am not"
                    m_uiTalkTimer = 9000 ; // 3 s self + 2s wait + 2s Autie + 2s wait
                    break ;

                case 1 : // After "Tell me"
                    m_uiTalkTimer = 10000 ; // 2s self + 2s wait + 4 s Auntie + 2s wait
                    break ;

                case 2 : // After "Where are"
                    m_uiTalkTimer = 11000 ; // 4s self + 2s wait + 3 s Auntie + 2s wait
                    break ;

                case 3 : // After "Auntie Stormstout"
                    m_uiTalkTimer = 19000 ; // 4s self + 2s wait + 11s Auntie + 2s wait
                    break ;

                case 4 : // After "I see"
                    m_uiTalkTimer = 8000 ; // 2 s self + 2s wait + 2s Auntie + 2s wait
                    break ;

                case 5 : // After "there is no time"
                    m_uiTalkTimer = 30000 ; // Custom timer
                    break ;

                case 6 :
                    m_uiTalkTimer = DIALOGUE_STOP_TIMER ; // Okay, end
                    break ;

                default :
                    break ;
                }
                ++m_uiTalkId;
            }
            else
                m_uiTalkTimer -= diff ;
        }

    private :
        uint32 m_uiTalkTimer ;
        uint32 m_uiTalkId ;
        bool m_bCanTalk ;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new npc_chen_stormstoutAI(creature);
    }
};

class npc_auntie_stormstout : public CreatureScript
{
public :
    npc_auntie_stormstout() : CreatureScript("npc_auntie_stormstout")
    {

    }

    class npc_auntie_stormstoutAI : public ScriptedAI
    {
    public :
        npc_auntie_stormstoutAI(Creature* creature) : ScriptedAI(creature)
        {
            m_uiTalkTimer = DIALOGUE_STOP_TIMER ;
        }

        void DoAction(int32 action)
        {
            if(action == 1)
            {
                m_uiTalkTimer = 200 ; // Before SAY_1
                m_uiTalkId = 0 ;
            }
        }

        void UpdateAI(uint32 diff)
        {
            // Return since the dialogue is not started
            if(m_uiTalkTimer == DIALOGUE_STOP_TIMER)
                return ;

            if(m_uiTalkTimer <= diff)
            {
                Talk(m_uiTalkId);
                switch(m_uiTalkId)
                {
                case 0 : // After "Oh Hello"
                    m_uiTalkTimer = 13000 ; // 2 s wait + 6 s self + 3 s Chen + 2s wait
                    break ;

                case 1 : // After "Oh Zan"
                    m_uiTalkTimer = 10000 ; // 4 s self + 2 s wait + 2 s Chen
                    break ;

                case 2 : // After "It is certainly"
                    m_uiTalkTimer = 12000 ; // 4s self + 2s wait + 4 s Chen
                    break ;

                case 3 : // After "Have you seen"
                    m_uiTalkTimer = 11000 ; // 3s self + 2s wait + 4 s Chen
                    break ;

                case 4 : // After "Abandonned"
                    m_uiTalkTimer = 17000 ; // 11 s self + 2 s wait + 2s Chen
                    break ;

                case 5 : // After "I have"
                    m_uiTalkTimer = DIALOGUE_STOP_TIMER ; // Okay, end
                    break ;

                default :
                    break ;
                }

                ++m_uiTalkId;
            }
            else
                m_uiTalkTimer -= diff ;
        }

    private :
        uint32 m_uiTalkTimer;
        uint32 m_uiTalkId ;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new npc_auntie_stormstoutAI(creature);
    }
};

#define MAX_DIFFERENT_HOZENS 8

namespace StormstoutBrewery {

enum Events {
    // Illusioner
    EVENT_ILLUSIONER_WAIT = 1,

    // Rolling barrel
    EVENT_BARREL_CHECK = 2,
};

enum Creatures {
    // Illusioners
    NPC_FIERY_TRICKSTER         = 56867,
    NPC_AQUA_DANCER             = 56865,
    MOB_SODDEN_HOZEN_BRAWLER    = 59605,
    MOB_INFLAMED_HOZEN_BRAWLER  = 56924,

    // Hozens
    MOB_DRUNKEN_HOZEN_BRAWLER   = 56862,
    MOB_HOZEN_HOLLERER          = 56783,
    MOB_HOZEN_PARY_ANIMAL_1     = 56927,
    MOB_HOZEN_PARY_ANIMAL_2     = 57097,
    MOB_HOZEN_PARY_ANIMAL_3     = 59684,
    MOB_SLEEPY_HOZEN_BRAWLER    = 56863,

    // Bouncer
    MOB_HOZEN_BOUNCER           = 56849,
};

static const uint32 hozens[MAX_DIFFERENT_HOZENS] = {MOB_SODDEN_HOZEN_BRAWLER, MOB_INFLAMED_HOZEN_BRAWLER, MOB_DRUNKEN_HOZEN_BRAWLER,
                        MOB_HOZEN_HOLLERER, MOB_HOZEN_PARY_ANIMAL_1, MOB_HOZEN_PARY_ANIMAL_2, MOB_HOZEN_PARY_ANIMAL_3,
                        MOB_SLEEPY_HOZEN_BRAWLER};
                        
static const Position hozenFleePosition = {-774.154231f, 1420.184014f, 139.579605f, 3.463936f} ;

enum Spells {
    // Illusioners
    SPELL_AQUATIC_ILLUSION          = 107044,
    SPELL_FIERY_ILLUSION            = 107175,

    // Barrel
    SPELL_RIDE_BREW_BARREL = 106614,
};

}
using namespace StormstoutBrewery ;

class npc_sb_illusioner : public CreatureScript {
public :
    npc_sb_illusioner() : CreatureScript("npc_sb_illusioner") {

    }

    class npc_sb_illusioner_AI : public ScriptedAI {
    public :
        npc_sb_illusioner_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript();
            _target = NULL ;
        }

        void SetHozenTarget(Creature* target) {
            _target = target ;
        }

        void JustDied(Unit* killer) {
            uint32 auraId = 0 ;
            switch(me->GetEntry()) {
            case NPC_AQUA_DANCER :
                auraId = SPELL_AQUATIC_ILLUSION ;
                break ;

            case NPC_FIERY_TRICKSTER :
                auraId = SPELL_FIERY_ILLUSION ;
                break ;

            default :
                break ;
            }

            if(_target)
                _target->RemoveAurasDueToSpell(auraId);
        }

    private :
        InstanceScript* _instance ;
        Creature* _target ;
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new npc_sb_illusioner_AI(creature);
    }
};

typedef npc_sb_illusioner::npc_sb_illusioner_AI IllusionerAI ;

class npc_sb_illusioner_master : public CreatureScript {
public :
    npc_sb_illusioner_master() : CreatureScript("npc_sb_illusioner_master") {

    }

    class npc_sb_illusioner_master_AI : public ScriptedAI {
    public :
        npc_sb_illusioner_master_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript();
        }

        void Reset() {
            _events.Reset();
            _events.ScheduleEvent(EVENT_ILLUSIONER_WAIT, 2000);
        }

        void UpdateAI(uint32 diff) {
            _events.Update(diff);

            while(uint32 eventId = _events.ExecuteEvent()) {
                switch(eventId) {
                case EVENT_ILLUSIONER_WAIT :
                    InitializeIllusioners();
                    break ;

                default :
                    break ;
                }
            }
        }

    private :
        void InitializeIllusioners() {
            std::list<Creature*> waterIllusioners, fireIllusioners, soddenHozens, inflamedHozens ;

            /*
             * Stores all our creatures in lists
             */
            GetCreatureListWithEntryInGrid(waterIllusioners, me, NPC_AQUA_DANCER, 500.0f);
            GetCreatureListWithEntryInGrid(fireIllusioners, me, NPC_FIERY_TRICKSTER, 500.0f);

            GetCreatureListWithEntryInGrid(soddenHozens, me, MOB_SODDEN_HOZEN_BRAWLER, 500.0f);
            GetCreatureListWithEntryInGrid(inflamedHozens, me, MOB_INFLAMED_HOZEN_BRAWLER, 500.0f);

            /*
             * Check for emptyness, prevents doing wierd things
             */
            if(waterIllusioners.empty() || fireIllusioners.empty()
                    || soddenHozens.empty() || inflamedHozens.empty())
                return ;

            /*
             * Check the size, to prevent one hozen to have multiple auras
             */
            if(waterIllusioners.size() < soddenHozens.size())
                soddenHozens.resize(waterIllusioners.size());
            else if(waterIllusioners.size() > soddenHozens.size())
                waterIllusioners.resize(soddenHozens.size());

            if(fireIllusioners.size() < inflamedHozens.size())
                inflamedHozens.resize(fireIllusioners.size());
            else if(fireIllusioners.size() > inflamedHozens.size())
                fireIllusioners.resize(inflamedHozens.size());

            /*
             * Now loop over each illusioner, and make it cast the
             * appropriate spell on one hozen
             */
            for(std::list<Creature*>::iterator iter = waterIllusioners.begin(), biter = soddenHozens.begin() ;
                iter != waterIllusioners.end(), biter != soddenHozens.end() ; ++iter, ++biter) {

                Creature* water = *iter, *sodden = *biter ;
                if(water && sodden) {
                    water->CastSpell(sodden, SPELL_AQUATIC_ILLUSION);
                    if(IllusionerAI* illusionerAI = dynamic_cast<IllusionerAI*>(water->AI()))
                        illusionerAI->SetHozenTarget(sodden);
                }
            }

            for(std::list<Creature*>::iterator iter = fireIllusioners.begin(), biter = inflamedHozens.begin() ;
                iter != fireIllusioners.end(), biter != inflamedHozens.end() ; ++iter, ++biter) {

                Creature* fire = *iter, *inflamed = *biter ;
                if(fire && inflamed) {
                    fire->CastSpell(inflamed, SPELL_AQUATIC_ILLUSION);
                    if(IllusionerAI* illusionerAI = dynamic_cast<IllusionerAI*>(fire->AI()))
                        illusionerAI->SetHozenTarget(inflamed);
                }
            }
        }

        EventMap _events ;
        InstanceScript* _instance ;
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new npc_sb_illusioner_master_AI(creature);
    }
};

class mob_sb_hozens_generic : public CreatureScript {
public :
    mob_sb_hozens_generic() : CreatureScript("mob_sb_hozen_generic") {

    }

    class mob_sb_hozens_generic_AI : public ScriptedAI {
    public :
        mob_sb_hozens_generic_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript();
        }

        void Reset() {
            _events.Reset();
        }
        
        void DoAction(int32 action) {
            if(me->GetEntry() == MOB_HOZEN_PARY_ANIMAL_1
                || me->GetEntry() == MOB_HOZEN_PARY_ANIMAL_2
                || me->GetEntry() == MOB_HOZEN_PARY_ANIMAL_3) {
                if(action == 1)
                    me->GetMotionMaster()->MovePoint(0, hozenFleePosition);
            }
        }
        
        void MovementInform(uint32 type, uint32 point) {
            if(type == POINT_MOTION_TYPE && point == 0)
                me->DisappearAndDie();
        }

        void UpdateAI(uint32 diff) {
            if(!UpdateVictim())
                return ;

            _events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return ;

            while(uint32 eventId = _events.ExecuteEvent()) {
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit *killer) {
            if(killer && killer->GetTypeId() == TYPEID_PLAYER)
                AddPower(1);
        }

    private :
        void AddPower(uint32 amount) {
            if(!me->GetMap())
                return ;

            Map* map = me->GetMap();
            Map::PlayerList const& playerList = map->GetPlayers();

            if(playerList.isEmpty())
                return ;

            for(Map::PlayerList::const_iterator iter = playerList.begin() ; iter != playerList.end() ; ++iter)
                AddPowerToPlayer(iter->GetSource(), amount);
        }

        void AddPowerToPlayer(Player* player, uint32 amount) {
            if(!player)
                return ;

            player->ModifyPower(POWER_ALTERNATE_POWER, amount);
            if(_instance)
                _instance->SetData64(INSTANCE_DATA64_KILLED_HOZENS, amount);
        }

        InstanceScript* _instance ;
        EventMap _events ;
    };
    
    CreatureAI* GetAI(Creature* creature) const {
        return new mob_sb_hozens_generic_AI(creature);
    }
};

class spell_sb_mind_illusion : public SpellScriptLoader {
public :
    spell_sb_mind_illusion() : SpellScriptLoader("spell_sb_mind_illusion") {

    }

    class spell_sb_mind_illusion_AuraScript : public AuraScript {
        PrepareAuraScript(spell_sb_mind_illusion_AuraScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ;
        }

        bool Load() {
            return true ;
        }

        void HandleEffectRemove(AuraEffect const* auraEff, AuraEffectHandleModes mode) {
            if(!GetOwner() || !GetOwner()->ToCreature())
                return ;

            Creature* owner = GetOwner()->ToCreature();

            switch(GetSpellInfo()->Id) {
            case 107044 :
                owner->CastSpell(owner, 114655);
                break ;

            case 107125 :
                owner->CastSpell(owner, 114656);
                break ;

            default :
                break ;
            }
        }

        void Register() {
            OnEffectRemove += AuraEffectRemoveFn(spell_sb_mind_illusion_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const {
        return new spell_sb_mind_illusion_AuraScript();
    }
};

class mob_habanero_brew : public CreatureScript
{
public :
    mob_habanero_brew() : CreatureScript("mob_habanero_brew")
    {

    }

    class mob_habanero_brewAI : public ScriptedAI
    {
    public :
        mob_habanero_brewAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void JustDied(Unit *killer)
        {
            DoCastAOE(107205);
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new mob_habanero_brewAI(creature);
    }
};

/** Spell target ervery unit in range, not checking if the target is a player or a creature,
 * which cause players to be instantly killed. We will handle this right here.
 */
class spell_stormstout_brewery_habanero_brew_spicy_explosion : public SpellScriptLoader 
{
public:
    /// Constructor of the ScriptLoader
    spell_stormstout_brewery_habanero_brew_spicy_explosion() : 
        SpellScriptLoader("spell_stormstout_brewery_habanero_brew_spicy_explosion") 
    {
        
    }
    
    /// Script of the spell
    class spell_stormstout_brewery_habanero_brew_spicy_explosion_SpellScript : public SpellScript 
    {
        PrepareSpellScript(spell_stormstout_brewery_habanero_brew_spicy_explosion_SpellScript);
        
        bool Validate(const SpellInfo *spellInfo) 
        {
            return true;
        }
        
        bool Load() 
        {
            return true;
        }
        
        void HandleEffects(SpellEffIndex effectIndex)
        {
            if(Unit *hit = GetHitUnit())
            {
                if(hit->GetTypeId() == TYPEID_PLAYER)
                    PreventHitDefaultEffect(effectIndex);
            }
        }
        
        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_stormstout_brewery_habanero_brew_spicy_explosion_SpellScript::HandleEffects, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            OnEffectHitTarget += SpellEffectFn(spell_stormstout_brewery_habanero_brew_spicy_explosion_SpellScript::HandleEffects, EFFECT_1, SPELL_EFFECT_INSTAKILL);
            OnEffectHitTarget += SpellEffectFn(spell_stormstout_brewery_habanero_brew_spicy_explosion_SpellScript::HandleEffects, EFFECT_2, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };
    
    SpellScript *GetSpellScript() const {
        return new spell_stormstout_brewery_habanero_brew_spicy_explosion_SpellScript();
    }
};

#define MAX_SUMMONING_BARRELS_POSITIONS 6

static const Position PointBarrelsPositions[MAX_SUMMONING_BARRELS_POSITIONS] =
{
    {-779.830566f, 1382.367676f, 146.725952f, 2.957428f},
    {-795.707092f, 1360.484253f, 146.713882f, 3.337561f},
    {-750.099548f, 1303.637207f, 146.692581f, 4.484246f},
    {-727.915039f, 1367.620117f, 146.710236f, 0.289437f},
    {-735.368713f, 1310.069702f, 146.700073f, 5.531971f},
    {-753.769287f, 1391.448730f, 146.722473f, 0.981375f}
};

class npc_rolling_barrel : public CreatureScript 
{
public :
    npc_rolling_barrel() : CreatureScript("npc_rolling_barrel") 
    {

    }

    class npc_rolling_barrel_AI : public ScriptedAI 
    {
    public :
        npc_rolling_barrel_AI(Creature* creature) : ScriptedAI(creature) 
        {
            _uiIndex = 0 ;
            _instance = creature->GetInstanceScript();
        }

        void Reset() 
        {
            _uiIndex = 0 ;

            DoCast(me, 106647); /* Let's roll ! */

            _events.Reset();
            _events.ScheduleEvent(StormstoutBrewery::EVENT_BARREL_CHECK, 500);
        }

        void SetData(uint32 uiIndex, uint32 uiValue) 
        {
            if(uiIndex == NPC_ROLLING_BARREL_DATA_SUMMONING_ID)
                _uiIndex = uiValue ;
        }

        void DoAction(int32 action) 
        {
            if(action == 0)
                me->GetMotionMaster()->MovePoint(0, PointBarrelsPositions[_uiIndex]);
        }

        void MovementInform(uint32 uiType, uint32 uiId) 
        {
            if(uiType == POINT_MOTION_TYPE && uiId == 0) 
            {
                if(_instance)
                    _instance->ProcessEvent(NULL, _uiIndex);

                DoCastAOE(106769); /* Generic */
                me->Kill(me);
            }
        }

        void UpdateAI(uint32 diff) 
        {
            _events.Update(diff);

            while(uint32 eventId = _events.ExecuteEvent()) 
            {
                switch(eventId) 
                {
                case StormstoutBrewery::EVENT_BARREL_CHECK :
                    if(Vehicle* vehicle = me->GetVehicleKit()) 
                    {
                        if(!me->HasAura(StormstoutBrewery::SPELL_RIDE_BREW_BARREL))
                            DoCast(me, StormstoutBrewery::SPELL_RIDE_BREW_BARREL);
                    }
                    _events.ScheduleEvent(StormstoutBrewery::EVENT_BARREL_CHECK, 500);
                    break ;

                default :
                    break ;
                }
            }
        }

    private :
        InstanceScript* _instance ;
        EventMap _events ;
        uint32 _uiIndex ;
    };

    CreatureAI* GetAI(Creature *creature) const 
    {
        return new npc_rolling_barrel_AI(creature);
    }
};

/* Some researches on the barrels spells :
    Applied on the barrel : 106614 always, even when there is no passenger !
        106614     => Periodically triggers 106768
                => Trigger 106768 ==> WHY ?
                => Apply Aura : Control Vehicle => because it can be boarded
            
        106768    => Periodically trigger 106769
            
        106769    => Trigger spell 107351 => Target hozens according to description
                => Trigger spell 106784 => Target Ook Ook according to description
        
        107351    => Knock back
                => School Damage
                => Aura Mod Damage % Taken
                => Effect 203 (triggerSpell == 106768)
                
        106784    => Aura Mod % Damage Taken
                => School Damage
                => Effect 203
                
    So where does this leads us ? 
        We apply 106614 on the barrel ; it triggers periodically 106768, who in return periodically triggers 106769 => Wierd, but we will let that; 
        Then, 107351 and 106784 are triggered at each tick => Target == TARGET_UNIT_SRC_AREA_ENTRY => must handle target selection
    
    What do we need then ?
        => Handle target select on 107351 and 106784
*/

static bool IsHozenTargetForBarrel(WorldObject *hozen)
{
    if(!hozen->ToUnit())
        return false;
    
    for(uint32 entry: hozens)
        if(hozen->ToUnit()->GetEntry() == entry)
            return true;
    
    return false;
}

class BrewExplosionPredicate
{
public:
    BrewExplosionPredicate(SpellInfo const* spellInfo) : m_spellId(spellInfo ? spellInfo->Id : 0) {}
    
    bool operator()(WorldObject *target)
    {
        // Ignore null targets or players
        if(!target)
            return true;
            
        if(target->GetTypeId() == TYPEID_PLAYER)
            return true;
            
        switch(m_spellId)
        {
        case 107351:
            // Remove not good hozens
            if(!IsHozenTargetForBarrel(target))
                return true;
            break;
            
        case 106784:
            // Remove everything except Ook Ook
            if(target->ToUnit()->GetEntry() != BOSS_OOK_OOK)
                return true;
            break;
            
        default:
            return true;
        }
        
        return false;
    }
private:
    uint32 m_spellId;
};

class spell_stormstout_brewery_brew_explosion : public SpellScriptLoader
{
public:
    spell_stormstout_brewery_brew_explosion() : SpellScriptLoader("spell_stormstout_brewery_brew_explosion") {}
    
    class spell_stormstout_brewery_brew_explosion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_stormstout_brewery_brew_explosion_SpellScript);
        
        void HandleTargetSelect(std::list<WorldObject*>& targets)
        {
            targets.remove_if(BrewExplosionPredicate(GetSpellInfo()));
        }
        
        void HandleAfterHit()
        {
            if(GetCaster())
                GetCaster()->Kill(GetCaster());
        }
        
        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_stormstout_brewery_brew_explosion_SpellScript::HandleTargetSelect, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_stormstout_brewery_brew_explosion_SpellScript::HandleTargetSelect, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            
            if(m_scriptSpellId == 107351)
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_stormstout_brewery_brew_explosion_SpellScript::HandleTargetSelect, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            
            AfterHit += SpellHitFn(spell_stormstout_brewery_brew_explosion_SpellScript::HandleAfterHit);
        }
    };
    
    SpellScript *GetSpellScript() const
    {
        return new spell_stormstout_brewery_brew_explosion_SpellScript();
    }
};

#define STALKER_BOUNCER 200501

class mob_hozen_bouncer : public CreatureScript
{
public :
    mob_hozen_bouncer() : CreatureScript("mob_hozen_bouncer")
    {

    }

    class mob_hozen_bouncerAI : public ScriptedAI
    {
    public :
        mob_hozen_bouncerAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset()
        {
            DoCast(me, 107019, true);
        }

        void DoAction(int32 action)
        {
            if(action == 1)
            {
                me->RemoveAurasDueToSpell(107019);
            }
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new mob_hozen_bouncerAI(creature);
    }
};

class spell_sb_doorguard : public SpellScriptLoader {
public :
    spell_sb_doorguard() : SpellScriptLoader("spell_sb_doorguard") {

    }

    class spell_sb_doorguard_AuraScript : public AuraScript {
        PrepareAuraScript(spell_sb_doorguard_AuraScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ;
        }

        bool Load() {
            return true ;
        }

        void HandlePeriodic(AuraEffect const* auraEff) 
        {
            std::list<Player*> players;
            GetPlayerListInGrid(players, GetCaster(), sSpellMgr->GetSpellInfo(GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell)->RangeEntry->MaxRangeHostile);
            
            if(players.empty())
                PreventDefaultAction();
        }

        void Register() {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sb_doorguard_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const {
        return new spell_sb_doorguard_AuraScript();
    }
};

class spell_sb_doorguard_target_selector : public SpellScriptLoader 
{
public :
    spell_sb_doorguard_target_selector() : SpellScriptLoader("spell_sb_doorguard_target_selector") 
    {
    
    }
    
    class spell_sb_doorguard_target_selector_SpellScript : public SpellScript 
    {
        PrepareSpellScript(spell_sb_doorguard_target_selector_SpellScript);
        
        bool Validate(const SpellInfo* spellInfo) 
        {
            return true ;
        }
        
        bool Load() 
        {
            return true ;
        }
        
        void FilterTargets(std::list<WorldObject*>& targets) 
        {
            targets.clear();
            
            std::list<Player*> players;
            GetPlayerListInGrid(players, GetCaster(), 12.0f);
            
            for(auto iter: players)
                targets.push_back(iter);
        }
        
        void HandleHitTarget(SpellEffIndex effectIndex)
        {
            PreventHitDefaultEffect(effectIndex);
            
            if(Player *player = GetHitPlayer())
            {
                float x = GetCaster()->GetPositionX() + 15.0f * std::cos(GetCaster()->GetOrientation());
                float y = GetCaster()->GetPositionY() + 15.0f * std::sin(GetCaster()->GetOrientation());
                float z = GetCaster()->GetPositionZ() + 1.0f;
                
                player->GetMotionMaster()->MoveJump(x, y, z, 12.5f, 12.5f);
            }
        }
        
        void Register() 
        {
            OnObjectAreaTargetSelect     += SpellObjectAreaTargetSelectFn(spell_sb_doorguard_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget             += SpellEffectFn(spell_sb_doorguard_target_selector_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };
    
    SpellScript* GetSpellScript() const 
    {
        return new spell_sb_doorguard_target_selector_SpellScript();
    }
};
#define MAX_BOUNCERS_POSITIONS 2
static const Position bouncersPositions[MAX_BOUNCERS_POSITIONS] =
{
    {-755.124268f, 1315.427979f, 146.711365f, 1.831958f},
    {-737.382507f, 1320.407959f, 146.711990f, 1.831958f}
};

#define MAX_SUMMON_DANCERS_POSITIONS 2
static const Position summonDancers[MAX_SUMMON_DANCERS_POSITIONS] =
{
    {-709.934143f, 1305.966553f, 146.692627f, 2.746932f},
    {-770.244080f, 1291.118652f, 146.693665f, 1.178493f}
};

#define MAX_SUMMON_DANCERS 11
#define MAX_MOVE_DANCERS_POSITIONS 3
#define DANCER_X 5.09552f
#define DANCER_Y 1.065163f
static const Position dancersPositions[MAX_MOVE_DANCERS_POSITIONS] =
{
    {-764.121338f, 1339.369751f, 146.756865f, 1.831958f},
    {-761.018616f, 1333.645264f, 146.725555f, 1.831958f},
    {-762.754883f, 1326.869995f, 146.719757f, 1.831958f}
};

class stalker_ook_ook_end_event : public CreatureScript
{
public :
    stalker_ook_ook_end_event() : CreatureScript("stalker_ook_ook_end_event")
    {

    }

    class stalker_ook_ook_end_eventAI : public ScriptedAI
    {
    public :
        stalker_ook_ook_end_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            firstBouncer = NULL ;
            secondBouncer = NULL ;

            m_uiTalkId = 0 ;
            m_uiTalkTimer = DIALOGUE_STOP_TIMER ;
        }

        void DoAction(int32 action)
        {
            if(action == 1)
            {
                DoMoveBouncers();
            }
        }

        void UpdateAI(uint32 diff)
        {
            // Return since we are not yet ready
            if(m_uiTalkTimer == DIALOGUE_STOP_TIMER)
                return ;

            if(m_uiTalkTimer <= diff)
            {
                switch(m_uiTalkId)
                {
                case 0 :
                    if(firstBouncer)
                        firstBouncer->AI()->Talk(m_uiTalkId);
                    m_uiTalkTimer = 3000 ;
                    break ;

                case 1 :
                    if(secondBouncer)
                    {
                        secondBouncer->AI()->Talk(m_uiTalkId);
                        secondBouncer->SetReactState(REACT_PASSIVE);
                        secondBouncer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        secondBouncer->GetMotionMaster()->MovePoint(0, bouncersPositions[1]);
                    }
                    m_uiTalkTimer = 2000 ;
                    break ;

                case 2 :
                    if(firstBouncer)
                        firstBouncer->AI()->Talk(m_uiTalkId);
                    DoPrepareDance();
                    m_uiTalkTimer = 3000 ;
                    break ;

                case 3 :
                    if(secondBouncer)
                        secondBouncer->AI()->Talk(m_uiTalkId);
                    m_uiTalkTimer = 3000 ;
                    break ;

                case 4 :
                    DoDance();
                    break ;

                default :
                    break ;
                }
                ++m_uiTalkId;
            }
            else
                m_uiTalkTimer -= diff ;
        }

        void DoMoveBouncers()
        {
            CreatureList bouncers ;
            GetCreatureListWithEntryInGrid(bouncers, me, 56849, 5000.0f);
            
            for(auto iter : bouncers)
            {
                iter->AI()->DoAction(1);
                iter->RemoveAurasDueToSpell(107019); // DoAction seems buggy
            }

            CreatureListConstIter iter = bouncers.begin() ;
            firstBouncer = *iter ;
            std::advance(iter, 1);
            secondBouncer = *iter ;

            m_uiTalkTimer = 200 ;

            if(firstBouncer)
            {
                firstBouncer->GetMotionMaster()->MovePoint(0, bouncersPositions[0]);
                firstBouncer->SetReactState(REACT_PASSIVE);
                firstBouncer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        void DoPrepareDance()
        {
            CreatureList hozens ;
            bool left = false ;
            for(uint8 i = 0 ; i < MAX_SUMMON_DANCERS ; ++i)
            {
                if(left)
                {
                    if(Creature* c = me->SummonCreature(59684, summonDancers[0]))
                    {
                        c->SetReactState(REACT_PASSIVE);
                        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        hozens.push_back(c);
                    }
                    left = false ;
                }
                else
                {
                    if(Creature* c = me->SummonCreature(59684, summonDancers[1]))
                    {
                        c->SetReactState(REACT_PASSIVE);
                        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        hozens.push_back(c);
                    }
                    left = true ;
                }
            }

            DoMoveHozens(hozens);
        }

        void DoMoveHozens(CreatureList const& hozens)
        {
            if(hozens.empty())
                return ;

            CreatureListConstIter iter = hozens.begin();

            Move(0, hozens, iter, 4);
            Move(1, hozens, iter, 3);
            Move(2, hozens, iter, 4);
        }

        void Move(const uint8 index, CreatureList const& source, CreatureListConstIter& iter, uint8 summonNumber)
        {
            float x = dancersPositions[index].GetPositionX() ;
            float y = dancersPositions[index].GetPositionY() ;
            float z = dancersPositions[index].GetPositionZ() + 1 ;

            for(uint8 i = 0 ; i < summonNumber ; ++i)
            {
                x += DANCER_X * i ;
                y += DANCER_Y * i ;
                std::advance(iter, 1);
                if(iter != source.end())
                    if(Creature* c = *iter)
                        c->GetMotionMaster()->MovePoint(0, x, y, z);
            }
        }

        void DoDance()
        {
            CreatureList dancers[2];
            GetCreatureListWithEntryInGrid(dancers[0], me, 56849, 50000.0f);
            GetCreatureListWithEntryInGrid(dancers[1], me, 59684, 50000.0f);

            for(uint8 i = 0 ; i < 2 ; ++i)
            {
                for(CreatureListConstIter iter = dancers[i].begin() ; iter != dancers[i].end() ; ++iter)
                {
                    if(Creature* c = *iter)
                    {
                        c->CastSpell(c, 128271, true);
                    }
                }
            }
            
            std::list<Player*> players ;
            GetPlayerListInGrid(players, me, 50000.0f);
            
            for(auto iter : players)
                iter->RemoveAurasDueToSpell(128271);
        }

    private :
        Creature* firstBouncer ;
        Creature* secondBouncer ;

        uint32 m_uiTalkTimer ;
        uint32 m_uiTalkId ;
    };
    
    CreatureAI* GetAI(Creature* creature) const {
        return new stalker_ook_ook_end_eventAI(creature);
    }
};

/**********************************************************/
/********************* HOPTALLUS **************************/
/**********************************************************/

#define MAX_TRASH_POINT_ID 6

static const Position TrashPoints[MAX_TRASH_POINT_ID] =
{
    {-710.459900f, 1310.748657f, 162.627029f, 2.754009f}, // First move after summon
    {-748.471802f, 1318.885498f, 162.630890f, 4.244696f}, // Entre tonneaux
    {-769.136719f, 1278.357056f, 162.695511f, 5.070935f}, // Devant la sortie
    {-761.958252f, 1247.301147f, 162.754562f, 3.387041f}, // Avant la pente
    {-796.072205f, 1238.755615f, 154.774200f, 1.951332f}, // Milieu de la pente
    {-809.778992f, 1273.019653f, 146.665207f, 0.371111f} // En bas de la pente
};

class mob_hoptallus_trash : public CreatureScript
{
public :
    mob_hoptallus_trash() : CreatureScript("mob_hoptallus_trash")
    {

    }

    class mob_hoptallus_trashAI : public ScriptedAI
    {
    public :
        mob_hoptallus_trashAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset()
        {
            m_uiPoint = 1 ;
            m_uiMoveTimer = 24 * 60 * 60 ;
            Position const movePosition = {-710.459900f, 1310.748657f, 162.627029f, 2.754009f}; // Aka, pos 0 (Motion Master)
            me->GetMotionMaster()->MovePoint(0, movePosition);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // sLog->outDebug(LOG_FILTER_NETWORKIO, "STORMSTOUT BREWERY: Virmen entering MovementInform, using type %u and point %u", type, id);
            if(type == POINT_MOTION_TYPE)
            {
                // sLog->outDebug(LOG_FILTER_NETWORKIO, "STORMSTOUT BREWERY: Virmen MovementInfo : setting timer !");
                m_uiMoveTimer = 100 ;
            }
        }

        void JustDied(Unit *killer)
        {
            if(InstanceScript* instance = me->GetInstanceScript())
                instance->SetData64(INSTANCE_DATA64_KILLED_HOPTALLUS_TRASH, 1);
        }

        void UpdateAI(uint32 diff)
        {
            if(m_uiMoveTimer <= diff)
            {
                if(m_uiPoint < MAX_TRASH_POINT_ID)
                {
                    Position pos = TrashPoints[m_uiPoint];
                    float x, y, z ;
                    x = pos.GetPositionX();
                    y = pos.GetPositionY();
                    z = pos.GetPositionZ();
                    
                    ++m_uiPoint ;
                    // sLog->outDebug(LOG_FILTER_NETWORKIO, "STORMSTOUT BREWERY: Virmen UpdateAI : next move point set to id %u, using x %f, y %f, z %f", m_uiPoint, x, y, z);
                    me->GetMotionMaster()->MovePoint(m_uiPoint, x, y, z);
                    m_uiMoveTimer = 24 * 60 * 60 ;
                }
                else
                {
                    if(InstanceScript* instance = me->GetInstanceScript())
                        instance->SetData64(INSTANCE_DATA64_KILLED_HOPTALLUS_TRASH, 1);
                    me->Kill(me);
                }
            }
            else
                m_uiMoveTimer -= diff ;
            
            if(!UpdateVictim())
                return ;

            DoMeleeAttackIfReady();
        }
        
    private :
        uint32 m_uiPoint ;
        uint32 m_uiMoveTimer ;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new mob_hoptallus_trashAI(creature);
    }
};

class npc_carrot_collector : public CreatureScript {
public :
    npc_carrot_collector() : CreatureScript("npc_carrot_collector") {

    }

    class npc_carrot_collector_AI : public ScriptedAI {
    public :
        npc_carrot_collector_AI(Creature* creature) : ScriptedAI(creature) {
            _carrotStalker = NULL ;
        }

        void Reset() {
            _carrotStalker = NULL ;
        }

        void DoAction(int32 action) {
            if(action == 1) {
                _carrotStalker = me->FindNearestCreature(200502, 50000.0f);
                if(_carrotStalker)
                    me->GetMotionMaster()->MovePoint(0, *_carrotStalker);
            }
        }

        void MovementInform(uint32 motionType, uint32 pointId) {
            if(motionType != POINT_MOTION_TYPE || pointId != 0)
                return ;

            if(_carrotStalker) {
                _carrotStalker->AI()->DoAction(0);
                me->GetMotionMaster()->MoveFollow(_carrotStalker, 1.0f, _carrotStalker->GetOrientation());
            }
        }

        void UpdateAI(uint32 diff) {
            return ;
        }

    private :
        Creature* _carrotStalker ;
    };

    CreatureAI* GetAI(Creature* creature) const {
        return new npc_carrot_collector_AI(creature);
    }
};

#define NPC_CARROT_STALKER 200502
#define MAX_CARROT_POSITIONS 8
static const Position carrotPositions[MAX_CARROT_POSITIONS] =
{
    {-657.059753f, 1256.340332f, 154.814529f, 4.925640f}, // milieu de pente
    {-639.456424f, 1192.562988f, 139.153397f, 0.247026f}, // Avant le saut
    {-628.554871f, 1195.119751f, 139.153397f, 0.247026f}, // Fin de plate-forme
    {-606.720825f, 1212.027222f, 138.538086f, 5.125917f}, // Après le saut
    {-598.784302f, 1192.206055f, 138.510284f, 7.434788f}, // Avant le pont
    {-597.464111f, 1133.276611f, 138.510178f, 5.664701f}, // A côte de la charette
    {-540.785522f, 1088.266846f, 151.069290f, 6.217621f}, // Coline
    {-481.942719f, 1074.370605f, 156.120697f, 5.696114f} // Fin de parcours
};

class stalker_carrot_door : public CreatureScript
{
public :
    stalker_carrot_door() : CreatureScript("stalker_carrot_door")
    {

    }

    class stalker_carrot_doorAI : public ScriptedAI
    {
    public :
        stalker_carrot_doorAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset()
        {
            DoCast(me, 116005, true);
        }

        void DoAction(int32 action)
        {
            if(action == 0) // Aka, start
                me->GetMotionMaster()->MovePoint(0, carrotPositions[0]); // Au milieu de la plate forme
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // sLog->outDebug(LOG_FILTER_NETWORKIO, "Stormstout Brewery: Carrot door: Entering MovementInform (type %u, id %u)", type, id);
            if(id == EVENT_JUMP && type == EFFECT_MOTION_TYPE) {
                me->GetMotionMaster()->MovePoint(4, carrotPositions[5]);
                return ;
            }
            
            if(type == POINT_MOTION_TYPE)
            {
                // sLog->outDebug(LOG_FILTER_NETWORKIO, "Stormstout Brewery: Carrot door: MovementInform: switching");
                switch(id)
                {
                case 0 :
                    me->GetMotionMaster()->MovePoint(1, carrotPositions[1]); // Devant la porte
                    break ;

                case 1 :
                    me->GetMotionMaster()->MovePoint(2, carrotPositions[2]); // Au bout de la plate-forme
                    break ;

                case 2 :
                    me->GetMotionMaster()->MovePoint(3, carrotPositions[3]); // Le saut
                    break;

                case 3 :
                    me->GetMotionMaster()->MoveJump(carrotPositions[4], 10.0f, 10.0f);
                    break;

                case 4 :
                    me->GetMotionMaster()->MovePoint(5, carrotPositions[6]);
                    break ;

                case 5 :
                    me->GetMotionMaster()->MovePoint(6, carrotPositions[7]);
                    break ;

                case 6 :
                    // sLog->outDebug(LOG_FILTER_NETWORKIO, "Carrot Path Ended");
                    break ;

                default :
                    break ;
                }
            }
        }

    private :
        uint32 m_uiAfterJumpTimer ;
        bool m_bActive ;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new stalker_carrot_doorAI(creature);
    }
};

/*******************************************************/
/********************* YANZHU **************************/
/*******************************************************/

#define STALKER_TARGET 200500

class stalker_gushing_brew : public CreatureScript
{
public :
    stalker_gushing_brew() : CreatureScript("stalker_gushing_brew")
    {

    }

    class stalker_gushing_brewAI : public ScriptedAI
    {
    public :
        stalker_gushing_brewAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset()
        {
            m_uiCheckTimer = 500;
            if(Creature* target = me->FindNearestCreature(STALKER_TARGET, 500.0f, true))
            {
                DoCast(target, 114379, true);
                _target = target ;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if(m_uiCheckTimer <= diff)
            {
                if(_target && _target->IsInWorld())
                    DoCast(_target, 114380);
                DoCheckForPlayers();
                m_uiCheckTimer = 500 ;
            }
            else
                m_uiCheckTimer -= diff ;
        }

        void DoCheckForPlayers()
        {
            if(Map* map = me->GetMap())
            {
                Map::PlayerList const& playerList = map->GetPlayers();
                if(!playerList.isEmpty())
                {
                    for(Map::PlayerList::const_iterator iter = playerList.begin() ; iter != playerList.end() ; ++iter)
                    {
                        if(Player* p = iter->GetSource())
                        {
                            if(_target)
                            {
                                if(p->IsInBetween(me, _target))
                                {
                                    DoCast(p, 114381, true);
                                }
                            }
                        }
                    }
                }
            }
        }

    private :
        uint32 m_uiCheckTimer ;
        Unit* _target ;
    };
};

class stalker_gushing_brew_target : public CreatureScript
{
public :
    stalker_gushing_brew_target() : CreatureScript("stalker_gushing_brew_target")
    {

    }

    class stalker_gushing_brew_targetAI : public ScriptedAI
    {
    public :
        stalker_gushing_brew_targetAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset()
        {
            m_uiMoveTimer = 5000 ;
            me->GetMotionMaster()->MoveRandom(1.0f);
        }

        void UpdateAI(uint32 diff)
        {
            if(m_uiMoveTimer <= diff)
            {
                me->GetMotionMaster()->MoveRandom(1.0f);
                m_uiMoveTimer = 5000 ;
            }
            else
                m_uiMoveTimer -= diff ;
        }

    private :
        uint32 m_uiMoveTimer ;
    };
};

static const Position summonFirstWavePositions[2] = {
    {-705.682800f, 1170.583618f, 166.156494f, 0.0f},
    {-701.111816f, 1154.608887f, 166.156494f, 0.0f}
};

static const Position summonSecondWavePositions[9] = {
    {-718.938965f, 1171.644287f, 166.156494f, 0.0f},
    {-715.915100f, 1159.415649f, 166.156494f, 0.0f},
    {-712.300415f, 1147.217163f, 166.156494f, 0.0f},
    {-700.215149f, 1150.571167f, 166.156494f, 0.0f},
    {-687.963074f, 1154.350342f, 166.156494f, 0.0f},
    {-691.251221f, 1166.405884f, 166.156494f, 0.0f},
    {-694.422852f, 1178.316162f, 166.156494f, 0.0f},
    {-706.848511f, 1174.876831f, 166.156494f, 0.0f},
    {-703.296143f, 1162.781860f, 166.156494f, 0.0f}
};

static const Position summonThirdWavePositions[4] = {
    {-709.214905f, 1152.527466f, 166.156494f, 0.0f},
    {-692.953735f, 1156.818848f, 166.156494f, 0.0f},
    {-697.649536f, 1173.198608f, 166.156494f, 0.0f},
    {-713.727356f, 1168.606079f, 166.156494f, 0.0f}
};

class npc_uncle_gao : public CreatureScript {

public :
    npc_uncle_gao() : CreatureScript("npc_uncle_gao") {

    }

    class npc_uncle_gao_AI : public ScriptedAI {
    public :
        npc_uncle_gao_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript();
        }

        /** ScriptedAI functions **/

        void Reset() {
            /** Initialize everything **/
            _events.Reset();

            _aleAlamental = _stoutAlamental = _wheatAlamental = 0 ;
            _numberOfSummons = 0 ;

            _phase = PHASE_NOT_STARTED ;

            /** And start **/
            _events.ScheduleEvent(EVENT_CHECK_FOR_PLAYERS, 500);
        }

        void UpdateAI(uint32 diff) {
            // Not start if Hoptallus not done
            if(_instance)
                if(_instance->GetData(INSTANCE_DATA_HOPTALLUS_STATUS) != DONE)
                    return ;

            // Update EventMap
            _events.Update(diff);

            // And switch
            while(uint32 eventId = _events.ExecuteEvent()) {
                switch(eventId) {
                case EVENT_CHECK_FOR_PLAYERS :
                    CheckForPlayers();
                    break ;

                case EVENT_SUMMON_FIRST_WAVE :
                    SummonFirstWave();
                    break ;

                case EVENT_SUMMON_SECOND_WAVE :
                    SummonSecondWave();
                    break ;

                case EVENT_SUMMON_THIRD_WAVE :
                    SummonThirdWave();
                    break ;

                case EVENT_SUMMON_YAN_ZHU :
                    SummonYanZhu();
                    break ;

                case EVENT_PERFECT_BREW :
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    Talk(TALK_PERFECT_BREW);
                    break ;

                default :
                    break ;
                }
            }
        }

        void SummonedCreatureDies(Creature *summoned, Unit *killer) {

            // Yan Zhu not yet started
            if(_phase < PHASE_YAN_ZHU) {
                --_numberOfSummons ;

                // Everybody killed, start next wave
                if(_numberOfSummons == 0) {
                    switch(_phase) {
                    case PHASE_FIRST_WAVE :
                        _phase = PHASE_SECOND_WAVE ;
                        Talk(TALK_SUMMON_SECOND_WAVE);
                        _events.ScheduleEvent(EVENT_SUMMON_SECOND_WAVE, 4000);
                        break ;

                    case PHASE_SECOND_WAVE :
                        _phase = PHASE_THIRD_WAVE ;
                        Talk(TALK_SUMMON_THIRD_WAVE);
                        _events.ScheduleEvent(EVENT_SUMMON_THIRD_WAVE, 4000);
                        break ;

                    case PHASE_THIRD_WAVE :
                        _phase = PHASE_YAN_ZHU ;
                        _events.ScheduleEvent(EVENT_SUMMON_YAN_ZHU, 4000);
                        break ;

                    default :
                        break ;
                    }
                }
            } else if(_phase == PHASE_YAN_ZHU) {
                // Yan Zhu has been killed, schedule final event
                _numberOfSummons = 0 ;
                _phase = PHASE_END ;
                Creature* yanZhu = me->FindNearestCreature(BOSS_YAN_ZHU, 200.0f, false);
                if(!yanZhu)
                    return ;

                Talk(TALK_YAN_ZHU_DEATH);
                me->GetMotionMaster()->MovePoint(POINT_YAN_ZHU_CORPSE, *yanZhu);
            } else return ;
        }

        void MovementInform(uint32 motionType, uint32 pointId) {
            if(motionType != POINT_MOTION_TYPE
                    || pointId != POINT_YAN_ZHU_CORPSE)
                return ;

            _events.ScheduleEvent(EVENT_PERFECT_BREW, 2000);
        }

        /** Non ScriptedAI functions **/

        void CheckForPlayers() {
            if(Map* map = me->GetMap()) {
                Map::PlayerList const& playerList = map->GetPlayers();

                if(playerList.isEmpty())
                    return ;

                for(Map::PlayerList::const_iterator c_iter = playerList.begin() ; c_iter != playerList.end() ; ++c_iter) {
                    if(Player* player = c_iter->GetSource()) {
                        float dist = me->GetExactDist2d(player);

                        // Player found, start next wave then return ;
                        if(dist <= 10.0f) {
                            _phase = PHASE_FIRST_WAVE ;

                            Talk(TALK_SUMMON_FIRST_WAVE);
                            _events.ScheduleEvent(EVENT_SUMMON_FIRST_WAVE, 4000);

                            /// @todo : remove this as soon as possible
                            /*if(_instance)
                                _instance->DoSendNotifyToInstance("Starting Gao Event");*/

                            return ;
                        }
                    }
                }

                // No player found, check again
                _events.ScheduleEvent(EVENT_CHECK_FOR_PLAYERS, 500);
            }
        }

        void SummonFirstWave() {
            _wheatAlamental = RAND(MOB_WHEAT_ALAMENTAL_BLOATED_BREW, MOB_WHEAT_ALAMENTAL_STOUT_BREW);

            for(uint8 i = 0 ; i < 2 ; ++i) {
                const Position summon = summonFirstWavePositions[i];
                me->SummonCreature(_wheatAlamental, summon, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60 * 60 * 24);
            }

            _numberOfSummons = 2 ;
        }

        void SummonSecondWave() {
            // _aleAlamental = MOB_ALE_ALAMENTAL_BUBBLING_BREW ;
            _aleAlamental = RAND(MOB_ALE_ALAMENTAL_BUBBLING_BREW, MOB_ALE_ALAMENTAL_YEASTY_BREW);

            for(uint8 i = 0 ; i < 9 ; ++i) {
                const Position summon = summonSecondWavePositions[i];
                me->SummonCreature(_aleAlamental, summon, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60 * 60 * 24);
            }

            _numberOfSummons = 9 ;
        }

        void SummonThirdWave() {
            _stoutAlamental = RAND(MOB_STOUT_ALAMENTAL_FIZZY_BREW, MOB_STOUT_ALAMENTAL_SUDSY_BREW);

            for(uint8 i = 0 ; i < 4 ; ++i) {
                const Position summon = summonThirdWavePositions[i] ;
                me->SummonCreature(_stoutAlamental, summon, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60 * 60 * 24);
            }

            _numberOfSummons = 4 ;
        }

        void SummonYanZhu() {
            Talk(TALK_SUMMON_YAN_ZHU);

            Position const summon = {-703.415771f, 1162.801025f, 166.141693f, 0.273505f}; // Correct height is 160, but YanZhu must "grow" from ground
            Creature* yanZhu = me->SummonCreature(BOSS_YAN_ZHU, summon, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 24 * HOUR * IN_MILLISECONDS);

            if(!yanZhu) {
                // sLog->outFatal(LOG_FILTER_NETWORKIO, "STORMSTOUT BREWERY : Unable to summon Yan Zhu the Uncasked !");
                if(_instance)
                    _instance->DoSendNotifyToInstance("DEBUG LOG : Unable to summon Yan Zhu the Uncasked");
            }

            // Cast the spells on YanZhu, based on which creatures were summoned
            //if(_stoutAlamental == MOB_STOUT_ALAMENTAL_FIZZY_BREW)
                yanZhu->AI()->SetData(0, SPELL_FIZZY_BREW);
            //else
            //    yanZhu->AI()->SetData(0, SPELL_SUDSY_BREW);

            /*if(_aleAlamental == MOB_ALE_ALAMENTAL_BUBBLING_BREW)
                yanZhu->AI()->SetData(1, SPELL_BUBBLING_BREW);
            else*/
                yanZhu->AI()->SetData(1, SPELL_YEASTY_BREW);

            // if(_wheatAlamental == MOB_WHEAT_ALAMENTAL_BLOATED_BREW)
                yanZhu->AI()->SetData(2, SPELL_BLACKOUT_BREW);
            // else
            //    yanZhu->AI()->SetData(2, SPELL_BLOATING_BREW);
            
            // Force boss to cast spells on self :
            yanZhu->AI()->Reset();
        }

    private :
        /// May be usefull
        EventMap _events ;

        /// Pointer to the instance
        InstanceScript* _instance ;

        /// Entries of the alamentals to be summoned ; also determines the spells YanZhu will cast
        uint32 _aleAlamental, _stoutAlamental, _wheatAlamental ;

        /// Npcs summoned ; when it reaches 0, it means we have to start the next phase
        uint32 _numberOfSummons ;
        
        /// Points to go to
        enum MovePoints {
            POINT_YAN_ZHU_CORPSE = 1
        };
        
        enum Phases {
            PHASE_NOT_STARTED   = 0,
            PHASE_FIRST_WAVE    = 1,
            PHASE_SECOND_WAVE   = 2,
            PHASE_THIRD_WAVE    = 3,
            PHASE_YAN_ZHU       = 4,
            PHASE_END           = 5
        };
        
        /// Current phase
        Phases _phase ;
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new npc_uncle_gao_AI(creature);
    }

private :
    /// Creatures to be summoned
    enum Creatures {
        // Stout alamentals
        MOB_STOUT_ALAMENTAL_SUDSY_BREW      = 59522,
        MOB_STOUT_ALAMENTAL_FIZZY_BREW      = 59520,

        // Ale alamentals
        MOB_ALE_ALAMENTAL_BUBBLING_BREW     = 59521,
        MOB_ALE_ALAMENTAL_YEASTY_BREW       = 59494,

        // Wheat alamentals
        MOB_WHEAT_ALAMENTAL_STOUT_BREW      = 59519,
        MOB_WHEAT_ALAMENTAL_BLOATED_BREW    = 59518
    };

    /// Spells to be casted
    enum Spells {
        SPELL_SUDSY_BREW    = 114933,
        SPELL_FIZZY_BREW    = 114934,

        SPELL_BLOATING_BREW = 114929,
        SPELL_BLACKOUT_BREW = 114930,

        SPELL_BUBBLING_BREW = 114931,
        SPELL_YEASTY_BREW   = 114932
    };

    /// Dialogs
    enum Talk {
        TALK_SUMMON_FIRST_WAVE  = 1,
        TALK_SUMMON_SECOND_WAVE = 2,
        TALK_SUMMON_THIRD_WAVE  = 3,
        TALK_SUMMON_YAN_ZHU     = 4,
        TALK_YAN_ZHU_DEATH      = 5,
        TALK_PERFECT_BREW       = 6
    };

    /// Events
    enum Events {
        EVENT_CHECK_FOR_PLAYERS     = 1,
        EVENT_SUMMON_FIRST_WAVE     = 2,
        EVENT_SUMMON_SECOND_WAVE    = 3,
        EVENT_SUMMON_THIRD_WAVE     = 4,
        EVENT_SUMMON_YAN_ZHU        = 5,
        EVENT_PERFECT_BREW          = 6
    };
};

/*************************/
/**** Uncle Gao Event ****/
/*************************/

/**
 * @namespace UncleGaoEvent
 *
 * @brief Namespace used to store all the datas related to the Uncle Gao Event, such as
 * spells, creatures, and other kinds of helpful things.
 */
namespace UncleGaoEvent {
    /**
     * @enum Spells
     *
     * @brief Global enum containing all the spells used by the npcs summoned during the Uncle Gao
     * Event.
     */
    enum Spells {
        // Generic
        SPELL_STOUT_BREW_BOLT           = 115650,
        SPELL_ALE_BREW_BOLT             = 116155,
        SPELL_WHEAT_BREW_BOLT           = 115652,

        // Sudsy Brew Alamental
        SPELL_SUDSY_SUDS                = 116178,

        // Fizzy Brew Alamental
        SPELL_FIZZY_CARBONATION         = 116164, // Trigger missile works strangely, better with the triggered spell

        // Bubbling Brew Alamental
        SPELL_BUBBLING_BUBBLE_SHIELD    = 128708, // Need script !

        // Yeasty Brew Alamental : nothing, curiously

        // Stout Brew Alamental
        SPELL_STOUT_BLACKOUT_BREW       = 106851, // Same as Yan-Zhu, no script to add

        // Bloated Brew Alamental
        SPELL_BLOATED_BLOAT             = 106546, // Same as Yan-Zhu, no script to add

        // Adds
        SPELL_SUD_PERIODIC              = 116179,
        SPELL_SUD_DAMAGES               = 116182,

        SPELL_CARBONATION_PERIODIC      = 116168,
        SPELL_CARBONATION_DAMAGES       = 116170
    };

    /**
     * @enum Events
     *
     * @brief Global enum containing all the ids of the events used by the npcs summoned during the
     * Uncle Gao Event.
     */
    enum Events {
        // Generic
        EVENT_STOUT_BREW_BOLT           = 1, // Used by 59522 / 59520
        EVENT_ALE_BREW_BOLT             = 2, // Used by 59521 / 59494
        EVENT_WHEAT_BREW_BOLT           = 3, // Used by 59519 / 59518

        // Sudsy
        EVENT_SUDSY_SUDS                = 4,

        // Fizzy
        EVENT_FIZZY_CARBONATION         = 5,

        // Bubbling
        EVENT_BUBBLING_BUBBLE_SHIELD    = 6,

        // Stout
        EVENT_STOUT_BLACKOUT_BREW       = 7,

        // Bloated
        EVENT_BLOATED_BLOAT             = 8
    };

    /**
     * @enum Creatures
     *
     * @brief Gloabl enum containing all the ids of the npcs summoned during the Uncle Gao Event.
     */
    enum Creatures {
        // Stout alamentals
        MOB_STOUT_ALAMENTAL_SUDSY_BREW      = 59522,
        MOB_STOUT_ALAMENTAL_FIZZY_BREW      = 59520,

        // Ale alamentals
        MOB_ALE_ALAMENTAL_BUBBLING_BREW     = 59521,
        MOB_ALE_ALAMENTAL_YEASTY_BREW       = 59494,

        // Wheat alamentals
        MOB_WHEAT_ALAMENTAL_STOUT_BREW      = 59519,
        MOB_WHEAT_ALAMENTAL_BLOATED_BREW    = 59518,

        // Summons
        MOB_CARBONATION                     = 56746,
        MOB_SUD                             = 56748,
        MOB_BUBBLE_SHIELD                   = 65522
    };

    /**
     * @class BloatedTargetSelector
     *
     * @brief A predicate inheriting from std::unary_function, taking a pointer to Unit as Arg and
     * returning bool. It is used to filter the targets during the cast of the spell bloat.
     */
    struct BloatedTargetSelector : public std::unary_function<Unit*, bool> {
    public :
        /// Constructor
        explicit BloatedTargetSelector(uint32 t = 0) : _t(t) {

        }

        /**
         * @fn operator ()
         *
         * @brief Overload of the operator () turning the class into a predicate
         *
         * @param target Pointer to the unit we are checking as a potential target
         *
         * @return true if the target fits condition to be added to temp targets list,
         * false otherwise
         */
        bool operator()(Unit* target) const {
            if(!target)
                return false ;

            if(target->GetTypeId() != TYPEID_PLAYER)
                return false ;

            if(target->HasAura(SPELL_BLOATED_BLOAT))
                return false ;

            return true ;
        }
        
        uint32 _t ;
    };
} // namespace UncleGaoEvent

class mob_alamental_gao : public CreatureScript {
public :
    mob_alamental_gao() : CreatureScript("mob_alamental_gao") {

    }

    class mob_alamental_gao_AI : public ScriptedAI {
    public :
        mob_alamental_gao_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript() ;
        }

        void Reset() {
            _events.Reset();
        }

        void EnterCombat(Unit *aggro) {
            switch(me->GetEntry()) {
            case UncleGaoEvent::MOB_STOUT_ALAMENTAL_SUDSY_BREW :
                _events.ScheduleEvent(UncleGaoEvent::EVENT_STOUT_BREW_BOLT, IsHeroic() ? 4000 : 5000);
                _events.ScheduleEvent(UncleGaoEvent::EVENT_SUDSY_SUDS, IsHeroic() ? 6000 : 7000);
                break ;

            case UncleGaoEvent::MOB_STOUT_ALAMENTAL_FIZZY_BREW :
                _events.ScheduleEvent(UncleGaoEvent::EVENT_STOUT_BREW_BOLT, IsHeroic() ? 4000 : 5000);
                _events.ScheduleEvent(UncleGaoEvent::EVENT_FIZZY_CARBONATION, IsHeroic() ? 8000 : 10000);
                break ;

            case UncleGaoEvent::MOB_ALE_ALAMENTAL_BUBBLING_BREW :
                _events.ScheduleEvent(UncleGaoEvent::EVENT_ALE_BREW_BOLT, IsHeroic() ? 4000 : 5000);
                _events.ScheduleEvent(UncleGaoEvent::EVENT_BUBBLING_BUBBLE_SHIELD, IsHeroic() ? 6000 : 7500);
                break ;

            case UncleGaoEvent::MOB_ALE_ALAMENTAL_YEASTY_BREW :
                _events.ScheduleEvent(UncleGaoEvent::EVENT_ALE_BREW_BOLT, IsHeroic() ? 4000 : 5000);
                break ;

            case UncleGaoEvent::MOB_WHEAT_ALAMENTAL_BLOATED_BREW :
                _events.ScheduleEvent(UncleGaoEvent::EVENT_WHEAT_BREW_BOLT, IsHeroic() ? 4000 : 5000);
                _events.ScheduleEvent(UncleGaoEvent::EVENT_BLOATED_BLOAT, IsHeroic() ? 5000 : 6000);
                break ;

            case UncleGaoEvent::MOB_WHEAT_ALAMENTAL_STOUT_BREW :
                _events.ScheduleEvent(UncleGaoEvent::EVENT_WHEAT_BREW_BOLT, IsHeroic() ? 4000 : 5000);
                _events.ScheduleEvent(UncleGaoEvent::EVENT_STOUT_BLACKOUT_BREW, IsHeroic() ? 6000 : 7000);
                break ;

            default :
                break ;
            }
        }

        void UpdateAI(uint32 diff) {
            if(!UpdateVictim())
                return ;

            _events.Update(diff);

            while(uint32 eventId = _events.ExecuteEvent()) {
                switch(eventId) {
                case UncleGaoEvent::EVENT_ALE_BREW_BOLT :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, UncleGaoEvent::SPELL_ALE_BREW_BOLT);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_ALE_BREW_BOLT, IsHeroic() ? urand(3000, 5000) : urand(5000, 8000));
                    break ;

                case UncleGaoEvent::EVENT_STOUT_BREW_BOLT :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, UncleGaoEvent::SPELL_STOUT_BREW_BOLT);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_STOUT_BREW_BOLT, IsHeroic() ? urand(3000, 5000) : urand(5000, 8000));
                    break ;

                case UncleGaoEvent::EVENT_WHEAT_BREW_BOLT :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, UncleGaoEvent::SPELL_WHEAT_BREW_BOLT);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_WHEAT_BREW_BOLT, IsHeroic() ? urand(3000, 5000) : urand(5000, 8000));
                    break ;

                case UncleGaoEvent::EVENT_SUDSY_SUDS :
                    DoCast(UncleGaoEvent::SPELL_SUDSY_SUDS);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_SUDSY_SUDS, IsHeroic() ? urand(10000, 11000) : urand(12000, 14000));
                    break ;

                case UncleGaoEvent::EVENT_FIZZY_CARBONATION :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        me->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), UncleGaoEvent::SPELL_FIZZY_CARBONATION, false);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_FIZZY_CARBONATION, IsHeroic() ? urand(10000, 11000) : urand(12000, 14000));
                    break ;

                case UncleGaoEvent::EVENT_BUBBLING_BUBBLE_SHIELD :
                    if(!me->HasAura(UncleGaoEvent::SPELL_BUBBLING_BUBBLE_SHIELD))
                        DoCast(me, UncleGaoEvent::SPELL_BUBBLING_BUBBLE_SHIELD);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_BUBBLING_BUBBLE_SHIELD, IsHeroic() ? urand(5000, 6000) : urand(7000, 9000));
                    break ;

                case UncleGaoEvent::EVENT_STOUT_BLACKOUT_BREW :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, UncleGaoEvent::SPELL_STOUT_BLACKOUT_BREW);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_STOUT_BLACKOUT_BREW, IsHeroic() ? urand(3000, 4000) : urand(5000, 6500));
                    break ;

                case UncleGaoEvent::EVENT_BLOATED_BLOAT :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, UncleGaoEvent::BloatedTargetSelector()))
                        DoCast(target, UncleGaoEvent::SPELL_BLOATED_BLOAT);
                    _events.ScheduleEvent(UncleGaoEvent::EVENT_BLOATED_BLOAT, IsHeroic() ? urand(7000, 8000) : urand(7500, 10000));
                    break ;

                default :
                    break ;
                }
            }

            DoMeleeAttackIfReady();
        }

    private :
        EventMap _events ;
        InstanceScript* _instance ;
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new mob_alamental_gao_AI(creature);
    }
};

class mobs_gao_summons : public CreatureScript {
public :
    mobs_gao_summons() : CreatureScript("mob_gao_summon") {

    }

    class mobs_gao_summons_AI : public ScriptedAI {
    public :
        mobs_gao_summons_AI(Creature* creature) : ScriptedAI(creature) {

        }

        void Reset() {
            switch(me->GetEntry()) {
            case UncleGaoEvent::MOB_CARBONATION :
                DoCast(me, UncleGaoEvent::SPELL_CARBONATION_PERIODIC);
                break ;

            case UncleGaoEvent::MOB_SUD :
                DoCast(me, UncleGaoEvent::SPELL_SUD_PERIODIC);
                break ;

            default :
                break ;
            }
        }

    private :

    };

    CreatureAI* GetAI(Creature *creature) const {
        return new mobs_gao_summons_AI(creature);
    }
};

class spell_gao_bubble_shield : public SpellScriptLoader {
public :
    spell_gao_bubble_shield() : SpellScriptLoader("spell_gao_bubble_shield") {

    }

    class spell_gao_bubble_shield_AuraScript : public AuraScript {
        PrepareAuraScript(spell_gao_bubble_shield_AuraScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ;
        }

        bool Load() {
            return true ;
        }

        void HandleAfterEffectApply(AuraEffect const* auraEff, AuraEffectHandleModes mode) {
            if(!GetCaster())
                return ;

            Unit* caster = GetCaster();

            std::list<Creature*> bubbles ;
            for(uint8 i = 0 ; i < 4 ; ++i) {
                bubbles.push_back(caster->SummonCreature(UncleGaoEvent::MOB_BUBBLE_SHIELD, caster->GetPositionX() + frand(0.0f, 3.0f),
                                                         caster->GetPositionY() + frand(0.0f, 3.0f), caster->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN));
            }

            if(Aura* aura = auraEff->GetBase())
                aura->ModStackAmount(3);

            for(std::list<Creature*>::iterator iter = bubbles.begin() ; iter != bubbles.end() ; ++iter) {
                if(Creature* bubble = *iter) {
                    bubble->EnterVehicle(caster);
                }
            }
        }

        void Register() {
            AfterEffectApply += AuraEffectApplyFn(spell_gao_bubble_shield_AuraScript::HandleAfterEffectApply, EFFECT_1, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const {
        return new spell_gao_bubble_shield_AuraScript();
    }
};

void AddSC_stormstout_brewery()
{
    // Ook Ook
    new npc_chen_stormstout();
    new npc_auntie_stormstout();
    new npc_sb_illusioner();
    new npc_sb_illusioner_master();
    new mob_sb_hozens_generic();
    new spell_sb_mind_illusion();
    new mob_habanero_brew();
    new spell_stormstout_brewery_habanero_brew_spicy_explosion();
    new npc_rolling_barrel();
    new spell_stormstout_brewery_brew_explosion();
    new mob_hozen_bouncer();
    new spell_sb_doorguard();
    new spell_sb_doorguard_target_selector();
    new stalker_ook_ook_end_event();

    // Hoptallus
    new mob_hoptallus_trash();
    new npc_carrot_collector();
    new stalker_carrot_door();

    // YanZhu
    new stalker_gushing_brew();
    new stalker_gushing_brew_target();
    new npc_uncle_gao();
    new mob_alamental_gao();
    new mobs_gao_summons();
    new spell_gao_bubble_shield();
}
