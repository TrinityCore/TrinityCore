/*
 * Copyright (C) 2010-2014 Anathema Script Engine project <http://valkyrie-wow.com/>
 */

#ifndef BOSS_OMEN_H
#define BOSS_OMEN_H

enum
{
    NPC_OMEN                = 15467,

    SPELL_FIREWORK_EFFECT   = 25495,
    SPELL_CLEAVE            = 20677,
    SPELL_ELUNES_CANDLE     = 26374,
    SPELL_OMENS_MOONLIGHT   = 26392,
    SPELL_STARFALL          = 26540,
    SPELL_SELF_DAMAGE       = 26544,

    SOUND_CHARACTER_SPLASH    = 1097,
    SOUND_HYDRA_SPECIAL_AGGRO = 8460,

    GAME_EVENT_MINIONS_OF_OMEN = 43,
};

struct Coords
{
    float x, y, z, o;
};

struct OmenDataStruct
{
    uint8 m_uiFireworksCount;
    time_t m_uiNextRespawn;
    bool m_bOmenAlive;
};

const Coords OmenSummon = { 7560.01f, -2838.36f, 449.575f, 4.01426f };
const Coords OmenHome = { 7542.5f, -2870.67f, 459.498f, 1.13905f };

static OmenDataStruct OmenData = { 0, 0, false };

struct boss_omenAI : ScriptedAI
{
    explicit boss_omenAI(Creature* creature);

    void Reset() override;
    void OnRemoveFromWorld() override;
    void MovementInform(uint32 movementType, uint32 data) override;
    void UpdateAI(uint32 const uiDiff) override;
    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override;
    void JustDied(Unit* pKiller) override;
    
    static void OnFireworkLaunch(Unit* pSummoner);
};

#endif
