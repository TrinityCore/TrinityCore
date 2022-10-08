/*
 *
 */

#ifndef BOSS_DRAGON_OF_NIGHTMARE_H
#define BOSS_DRAGON_OF_NIGHTMARE_H

enum
{
    SPELL_SEEPING_FOG_RIGHT         = 24813,
    SPELL_SEEPING_FOG_LEFT          = 24814,
    SPELL_NOXIOUS_BREATH            = 24818,
    SPELL_TAIL_SWEEP                = 15847,

    SPELL_MARK_OF_NATURE            = 25041,
    SPELL_AURA_OF_NATURE            = 25044,
    SPELL_SUMMON_PLAYER             = 24776,

    NPC_DREAM_FOG                   = 15224,

    SPELL_DREAM_FOG_AURA            = 24777
};

uint32 GetDrakeVar(uint32 entry);

struct boss_dragon_of_nightmareAI : ScriptedAI
{
    explicit boss_dragon_of_nightmareAI(Creature* pCreature);

    uint32 m_uiAuraOfNatureTimer;
    uint32 m_uiSeepingFogTimer;
    uint32 m_uiNoxiousBreathTimer;
    uint32 m_uiTailSweepTimer;
    uint32 m_uiSummonPlayerTimer;

    uint32 m_uiEventCounter;

    void Reset() override;
    void Aggro(Unit* pWho) override;
    void EnterEvadeMode() override;
    void JustDied(Unit* pKiller) override;
    virtual bool DoSpecialAbility() = 0;
    virtual bool UpdateDragonAI(uint32 const /*uiDiff*/) { return true; }
    void UpdateAI(uint32 const uiDiff) override;
};

struct boss_emerissAI : boss_dragon_of_nightmareAI
{
    explicit boss_emerissAI(Creature* pCreature);

    uint32 m_uiEmerissAuraTimer;
    uint32 m_uiVolatileInfectionTimer;

    void Reset() override;
    void Aggro(Unit* pWho) override;
    bool DoSpecialAbility() override;
    bool UpdateDragonAI(uint32 const uiDiff) override;
};

struct boss_lethonAI : boss_dragon_of_nightmareAI
{
    explicit boss_lethonAI(Creature* pCreature);

    void Reset() override;
    void Aggro(Unit* pWho) override;
    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override;
    void SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 uiPointId) override;
    bool DoSpecialAbility() override;
};

struct boss_taerarAI : boss_dragon_of_nightmareAI
{
    explicit boss_taerarAI(Creature* pCreature);

    uint32 m_uiArcaneBlastTimer;
    uint32 m_uiBellowingRoarTimer;
    uint32 m_uiShadesTimeoutTimer;

    uint8 m_uiShadesDead;

    void Reset() override;
    void Aggro(Unit* pWho) override;
    void EnterEvadeMode() override;
    bool DoSpecialAbility() override;
    void SummonedCreatureJustDied(Creature* pSummoned) override;
    void DoUnbanish();
    bool UpdateDragonAI(uint32 const uiDiff) override;
};

struct boss_ysondreAI : boss_dragon_of_nightmareAI
{
    explicit boss_ysondreAI(Creature* pCreature);

    uint32 m_uiLightningWaveTimer;

    void Reset() override;
    void Aggro(Unit* pWho) override;
    void JustSummoned(Creature* pSummoned) override;
    bool DoSpecialAbility() override;
    bool UpdateDragonAI(uint32 const uiDiff) override;
};

struct npc_spirit_shadeAI : ScriptedAI
{
    explicit npc_spirit_shadeAI(Creature* pCreature);

    uint32 m_uiDelay;
    ObjectGuid m_lethonGuid;

    void Reset() override;
    void EnterCombat(Unit*) override {}
    void AttackedBy(Unit*) override {}
    void AttackStart(Unit*) override {}
    void EnterEvadeMode() override {}
    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override;
    void UpdateAI(uint32 const uiDiff) override;
};

struct npc_shade_of_taerarAI : ScriptedPetAI
{
    explicit npc_shade_of_taerarAI(Creature* pCreature);

    uint32 m_uiAcidBreathTimer;
    uint32 m_uiPoisonCloudTimer;

    void Reset() override;
    void UpdatePetAI(uint32 const uiDiff) override;
};

struct npc_demented_druidAI : ScriptedAI
{
    explicit npc_demented_druidAI(Creature* pCreature);

    uint32 m_uiCurseOfThornsTimer;
    uint32 m_uiMoonFireTimer;
    uint32 m_uiSilenceTimer;

    void Reset() override;
    void UpdateAI(uint32 const uiDiff) override;
};

struct go_putrid_shroomAI : GameObjectAI
{
    explicit go_putrid_shroomAI(GameObject* pGo);

    uint32 m_uiDespawnTimer;

    void UpdateAI(uint32 const uiDiff) override;
};

#endif
