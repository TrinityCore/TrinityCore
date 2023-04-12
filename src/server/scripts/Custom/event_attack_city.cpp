//
//#include "scriptPCH.h"
//
//#define ME m_creature
//
//#define DEBUG_ON
//
//// #######################
//// # npc_attack_master   #
//// #######################
//// Le mob qui lance et gere les attaques
//
//#define INVOC_DIST_PORTAL 20.0f
//#define BOSS_INVOC_RADIUS 10.0f
//enum
//{
//    // Phase 1 : Invocateurs
//    PHASE_INVOC_SUMMONERS = 1,
//    SUMMONER_COUNT = 10,
//    // Timer
//    DELAY_INVOC_SUMMONERS = 10 * 1000,
//    DELAY_INVOC_PORTAL = 45 * 1000,
//    // NPC
//    NPC_SUMMONER_ENTRY = 11582,
//    // Gobj
//    GOBJ_PORTAL_ENTRY = 181810, // Portail
//    GOBJ_PORTAL_2_ENTRY = 149018, // Fumee sur le portail
//    // Spells
//    SPELL_INSTANT_DEATH = 5,
//    SPELL_INVOCATION_ON_MASTER = 19984, // Sort avec un beau visuel de canalisation
//    SPELL_INVOCATION_MASTER = 21157,
//    SPELL_ECLAIR_PORTAL = 19984, // Eclair qui tombe du ciel
//    SPELL_SUMMONER_AURA_1 = 28330,
//    SPELL_SUMMONER_AURA_2 = 31951,
//
//
//    // Phase 2 : vagues de mobs
//    PHASE_WAVES = 2,
//    // Spells
//    SPELL_AURA_RED = 31951,//28330,
//    SPELL_AURA_BLUE = 31954,
//    MOBS_PER_WAVE = 1,
//
//    // Phase 3
//    PHASE_FINAL_FIGHT = 3,
//    NPC_BOSS_ADD1_COUNT = 10,
//    NPC_BOSS_ADD2_COUNT = 10,
//    MASTER_ADD1_COUNT = 5,
//    MASTER_ADD2_COUNT = 2,
//    // NPC
//    NPC_BOSS_CAPITAL = 12480,
//    NPC_BOSS_CAPITAL_ADD1 = 1976, // Patrouilleur de SW
//    NPC_BOSS_CAPITAL_ADD2 = 68, // Guet de SW
//
//    NPC_MASTER_ADD1 = 5624, // Abomination de UC
//    NPC_MASTER_ADD2 = 16428,
//};
//
//// Textes
//// Phase 1
//#define SAY_PORTAL_FINISHED_1            "Le portail est en place."
//#define SAY_PORTAL_FINISHED_2            "Travail termine, Maitre."
//#define SAY_PORTAL_FINISHED_3            "Nous pouvons commencer."
//#define SAY_PORTAL_FINISHED_MASTER_SAY   "Tres bien."
//#define SAY_PORTAL_FINISHED_MASTER_YELL  "Cette ville n'existera bientot plus !"
//// Phase 2
//#define SAY_WAVE_MOB_AT_NEW_WAVE         "Les renforts arrivents !"
//
//// 1 jour : utilise si le script plante, pour se mettre "en pause"
//#define CD_INFINY                        60*60*24*1000
//
//class CreatureWaveEntry
//{
//public:
//    uint32 uiWaveId;
//    uint32 uiMobEntry;
//};
//
//// TODO : Deplacer ces fonctions pour qu'elles soient accessibles
//// de tous les scripts SD0
//typedef std::list<uint64> MobsGUIDList;
//typedef MobsGUIDList::iterator MobsGUIDListIter;
//
//void SetAttackable(Unit* pCreature, bool Attackable)
//{
//    if (!pCreature)
//        return;
//    if (Attackable)
//    {
//        //pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);    //org
//        //pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SPAWNING);          //org
//        //pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);     //org
//        pCreature->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//        //I dont know how to write this
//        pCreature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//    }
//    else
//    {
//        /*
//        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
//        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SPAWNING);
//        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
//        */    //org
//
//        pCreature->SetUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//        //I dont know how to write this
//        pCreature->SetUnitFlag( UNIT_FLAG_IMMUNE_TO_NPC);
//    }
//}
//
//void GetRandomNearLoc(WorldObject* myObj, float& x, float& y)
//{
//    x = myObj->GetPositionX() + urand(0, 10) - urand(0, 10);
//    y = myObj->GetPositionY() + urand(0, 10) - urand(0, 10);
//}
//
//struct npc_attack_masterAI : public ScriptedAI
//{
//    npc_attack_masterAI(Creature* pCreature) : ScriptedAI(pCreature)
//    {
//        uiCurrentPhaseStep = 0;
//        uiPhase = PHASE_INVOC_SUMMONERS;
//        fSummonPositionX = pCreature->GetPositionX();
//        fSummonPositionY = pCreature->GetPositionY();
//        fSummonPositionZ = pCreature->GetPositionZ();
//        fSummonOrientation = pCreature->GetOrientation();
//        // Position de spawn du boss de la ville
//        fCityBossPositionX = -8958.0f;
//        fCityBossPositionY = 517.0f;
//        fCityBossPositionZ = 96.9f;
//        // Retourné
//        fCityBossOrientation = pCreature->GetOrientation() + M_PI;
//        Reset();
//    }
//
//    uint32 uiCD;
//    uint32 uiCurrentPhaseStep;
//    uint32 uiGobjEntry;
//    uint32 uiPhase;
//    float fSummonPositionX;
//    float fSummonPositionY;
//    float fSummonPositionZ;
//    float fSummonOrientation;
//
//    float fCityBossPositionX;
//    float fCityBossPositionY;
//    float fCityBossPositionZ;
//    float fCityBossOrientation;
//
//    // Event invocateurs
//    MobsGUIDList lInvocatorMobsGUID;
//    // Event vagues
//    MobsGUIDList lAllWaveMobsGUID;
//    MobsGUIDList lCurrWaveMobsGUID;
//    // Event bataille finale
//    MobsGUIDList lCityBossAddsMobsGUID;
//    uint64 uiCityBossGUID;
//
//    // Fonctions generiques
//#if 1
//    void Reset() override
//    {
//    }
//    void SetAttackableInList(MobsGUIDList mobsList, bool bAttackable)
//    {
//        for (const auto& itr : mobsList)
//        {
//            /*if (Unit* unit = Unit::GetUnit(*ME, itr))
//                SetAttackable(unit, bAttackable);*/
//        }
//    }
//    /*void MasterSay(char const* what)
//    {
//        ME->MonsterSay(what, 0, 0);
//    }
//    void MasterYell(char const* what)
//    {
//        ME->MonsterYell(what, 0, 0);
//    }
//    void DoSummonGobj(uint32 gobjEntry, float size)
//    {
//        GameObject* gobj = ME->SummonGameObject(
//            gobjEntry,
//            ME->GetPositionX(),
//            ME->GetPositionY(),
//            ME->GetPositionZ(),
//            ME->GetOrientation(),
//            0.0f, 0.0f, 0.0f, 0.0f, CD_INFINY
//        );
//        if (gobj)
//            gobj->SetObjectScale(size);
//    }*/
//#endif
//#if 1
//    // Deroulement de l'event
//    // ################################
//    // #        PHASE 1               #
//    // ################################
//    // Invocation des invocateurs, qui invoquent le portail.
//    // Delais :
//    // - DELAY_INVOC_SUMMONERS
//    // - DELAY_INVOC_PORTAL
//    void DoSummonSummoners(uint32 num)
//    {
//        // En radians, angle ou se situe l'invocateur, entre [0 : 2*M_PI]
//        float circleAng = (float(num) / float(SUMMONER_COUNT)) * (M_PI * 2);
//        //float positionX = ME->GetPositionX() + (cos(circleAng) * INVOC_DIST_PORTAL);
//        //float positionY = ME->GetPositionY() + (sin(circleAng) * INVOC_DIST_PORTAL);
//#ifdef DEBUG_ON
//        //sLog.Out(LOG_BASIC, LOG_LVL_MINIMAL, "Invocateur %u (ang %f) [%f,%f]", num, circleAng, positionX, positionY);
//#endif
//        /*Creature* summoner = ME->SummonCreature(
//            NPC_SUMMONER_ENTRY,
//            positionX,
//            positionY,*/
//            //ME->GetPositionZ() + 3.0f,
//            //circleAng - M_PI, // Demi tour
//            //TEMPSUMMON_MANUAL_DESPAWN,
//            //0
//        //);
//        /*summoner->CastSpell(summoner, SPELL_SUMMONER_AURA_1, true);
//        summoner->CastSpell(summoner, SPELL_SUMMONER_AURA_2, true);
//        summoner->CastSpell(ME, SPELL_INVOCATION_ON_MASTER, false);*/
//        //SetAttackable(summoner, false);
//        //lInvocatorMobsGUID.push_back(summoner->GetGUID().GetCounter());//.GetCounter()-->I did
//    }
//    void CanalisationFinished()
//    {
//        // On invoque le portail
//        /*DoSummonGobj(GOBJ_PORTAL_ENTRY, 5.0f);
//        DoSummonGobj(GOBJ_PORTAL_2_ENTRY, 2.0f);*/
//        DoSummon(GOBJ_PORTAL_ENTRY, 5.0f);
//        DoSummon(GOBJ_PORTAL_2_ENTRY, 2.0f);
//        // On fait un joli visuel
//        //ME->CastSpell(ME, SPELL_ECLAIR_PORTAL, true);
//        // On supprime les auras d'invocation
//        //ME->RemoveAurasDueToSpell(SPELL_INVOCATION_ON_MASTER);
//        // On desactive les invocateurs
//        /*uint8 num = 0;
//        for (const auto& itr : lInvocatorMobsGUID)
//        {
//            if (Unit* invoc = Unit::GetUnit(*ME, itr))
//            {
//                if (invoc->IsAlive())
//                {
//                    ++num;
//                    SetAttackable(invoc, false);
//                    if (num == 1)
//                        invoc->MonsterSay(SAY_PORTAL_FINISHED_1, 0, 0);
//                    else if (num == 2)
//                        invoc->MonsterSay(SAY_PORTAL_FINISHED_2, 0, 0);
//                    else if (num == 3)
//                        invoc->MonsterSay(SAY_PORTAL_FINISHED_3, 0, 0);
//                }
//            }
//        }*/
//        /*MasterSay(SAY_PORTAL_FINISHED_MASTER_SAY);
//        MasterYell(SAY_PORTAL_FINISHED_MASTER_YELL);*/
//        // Le maitre ne peut plus etre tue
//        //SetAttackable(ME, false);
//    }
//    void DoSummonAllSummoners()
//    {
//        for (uint32 i = 1; i <= SUMMONER_COUNT; ++i)
//            DoSummonSummoners(i);
//    }
//
//    void UpdateEvent_Summoners(uint32 const uiDiff)
//    {
//        switch (uiCurrentPhaseStep)
//        {
//        case 1:
//        {
//           /* SetAttackable(ME, false);
//            uiCD = DELAY_INVOC_SUMMONERS;
//            return;*/
//        }
//        case 2:
//        {
//            // Invocation des ritualistes, et canalisation
//            DoSummonAllSummoners();
//            //ME->CastSpell(ME, SPELL_INVOCATION_MASTER, false);
//            uiCD = DELAY_INVOC_PORTAL;
//            return;
//        }
//        case 3:
//        {
//            CanalisationFinished();
//            uiPhase = PHASE_WAVES;
//            uiCD = 10000;
//            return;
//        }
//        }
//    }
//#endif
//#if 1
//    // ################################
//    // #        PHASE 2               #
//    // ################################
//    // Le portail est pret. Les invocateurs et le maitre sont desactives.
//    // Invocation de vagues de mobs qui attaquent la ville.
//    // Le maitre et les invocateurs restent pret du portail
//    //void DoSummonWaveCreature(uint32 creatureEntry)
//    //{
//    //    Creature* crea = ME->SummonCreature(
//    //        creatureEntry,
//    //        fSummonPositionX,
//    //        fSummonPositionY,
//    //        fSummonPositionZ,
//    //        fSummonOrientation,
//    //        TEMPSUMMON_MANUAL_DESPAWN,
//    //        0
//    //    );
//    //    if (!crea)
//    //        return;
//    //    crea->GetMotionMaster()->MovePoint(0, fCityBossPositionX, fCityBossPositionY, fCityBossPositionZ);
//    //   /* crea->SetCombatStartPosition(fCityBossPositionX, fCityBossPositionY, fCityBossPositionZ);
//    //    lAllWaveMobsGUID.push_back(crea->GetGUID());
//    //    lCurrWaveMobsGUID.push_back(crea->GetGUID());*/
//    //}
//    void DoSummonWave(uint32 id)
//    {
//        uint32 i = 0;
//        uint32 mobs[MOBS_PER_WAVE] = { 0 };
//        for (i = 0; i < MOBS_PER_WAVE; ++i)
//        {
//            switch (urand(0, 1))
//            {
//            case 0:
//                mobs[i] = NPC_MASTER_ADD1;
//                break;
//            case 1:
//                mobs[i] = NPC_MASTER_ADD2;
//                break;
//            }
//        }
//        //i = 0;
//        //while (i < MOBS_PER_WAVE)
//        //{
//        //    if (mobs[i])
//        //        DoSummonWaveCreature(mobs[i]);
//        //    ++i;
//        //}
//    }
//    void BeforeSummonNewWave()
//    {
//        //if (!lCurrWaveMobsGUID.empty())
//        //{
//        //    for (const auto& it : lCurrWaveMobsGUID)
//        //    {
//        //        if (Unit* waveMob = Unit::GetUnit(*ME, it))
//        //        {
//        //            if (waveMob->IsAlive())
//        //            {
//        //                if (!waveMob->HasAura(SPELL_AURA_RED))
//        //                {
//        //                    waveMob->MonsterYell("Moi tout casser !", 0, 0);
//        //                    waveMob->CastSpell(waveMob, SPELL_AURA_RED, true);
//        //                }
//        //            }
//        //        }
//        //    }
//        //}
//    }
//    void UpdateEvent_Waves(uint32 const uiDiff)
//    {
//        BeforeSummonNewWave();
//        lCurrWaveMobsGUID.clear();
//
//        if (uiCurrentPhaseStep < 50)
//        {
//            DoSummonWave(uiCurrentPhaseStep);
//            uiCD = 2000;
//            return;
//        }
//        else
//        {
//            uiPhase = PHASE_FINAL_FIGHT;
//            uiCD = urand(60, 90) * 1000;
//            return;
//        }
//    }
//#endif
//#if 1
//    // ################################
//    // #        PHASE 3               #
//    // ################################
//    // Certaines vagues sont encore dans la ville.
//    // Le BOSS de la capitale intervient dans la bataille, avec des gardes.
//    // Le PNJ qui a invoqué le portail invoque des adds.
//    // Les invocateurs disparaissent.
//    // Les 2 camps se rentrent l'un dans l'autre
//    //Unit* GetCityBoss()
//    //{
//    //    return Unit::GetUnit(*ME, uiCityBossGUID);
//    //}
//    //void CityBossSay(char const* what)
//    //{
//    //    if (Unit* boss = GetCityBoss())
//    //        boss->MonsterSay(what, 0, 0);
//    //}
//    //void CityBossYell(char const* what)
//    //{
//    //    if (Unit* boss = GetCityBoss())
//    //        boss->MonsterYell(what, 0, 0);
//    //}
//    //void CityBossSummonCreature(uint32 entry)
//    //{
//    //    Unit* boss = GetCityBoss();
//    //    if (!boss)
//    //        return;
//    //    float positionX, positionY;
//    //    positionX = fCityBossPositionX - urand(1, BOSS_INVOC_RADIUS);
//    //    positionY = fCityBossPositionY - urand(1, BOSS_INVOC_RADIUS);
//    //    Creature* addSummoned = boss->SummonCreature(
//    //        entry,
//    //        positionX,
//    //        positionY,
//    //        fCityBossPositionZ,
//    //        fCityBossOrientation,
//    //        TEMPSUMMON_MANUAL_DESPAWN,
//    //        0
//    //    );
//    //    lCityBossAddsMobsGUID.push_back(addSummoned->GetGUID());
//    //}
//    //void MasterSummonCreatureAndAttack(uint32 entry)
//    //{
//    //    Unit* boss = GetCityBoss();
//    //    if (!boss)
//    //        return;
//    //    float positionX, positionY;
//    //    positionX = ME->GetPositionX() + urand(1, BOSS_INVOC_RADIUS);
//    //    positionY = ME->GetPositionY() + urand(1, BOSS_INVOC_RADIUS);
//    //    Creature* addSummoned = ME->SummonCreature(
//    //        entry,
//    //        positionX,
//    //        positionY,
//    //        ME->GetPositionZ(),
//    //        ME->GetOrientation(),
//    //        TEMPSUMMON_MANUAL_DESPAWN,
//    //        0
//    //    );
//    //    if (addSummoned->AI())
//    //        addSummoned->AI()->AttackStart(boss);
//    //    addSummoned->SetCombatStartPosition(fCityBossPositionX, fCityBossPositionY, fCityBossPositionZ);
//    //}
//    //void SetAllAttackable()
//    //{
//    //    SetAttackable(ME, true);
//    //    SetAttackable(GetCityBoss(), true);
//    //    SetAttackableInList(lInvocatorMobsGUID, true);
//    //    SetAttackableInList(lAllWaveMobsGUID, true);
//    //    SetAttackableInList(lCityBossAddsMobsGUID, true);
//    //}
//    //void UpdateEvent_FinalFight(uint32 const uiDiff)
//    //{
//    //    switch (uiCurrentPhaseStep)
//    //    {
//    //    case 1:
//    //    {
//    //        // Invocation du boss de la ville
//    //        uiCityBossGUID = 0;
//    //        Creature* cityBoss = m_creature->SummonCreature(
//    //            NPC_BOSS_CAPITAL,
//    //            fCityBossPositionX,
//    //            fCityBossPositionY,
//    //            fCityBossPositionZ,
//    //            fCityBossOrientation,
//    //            TEMPSUMMON_MANUAL_DESPAWN,
//    //            0
//    //        );
//    //        if (!cityBoss)
//    //        {
//    //            sLog.Out(LOG_BASIC, LOG_LVL_ERROR, "Impossible d'invoquer le maitre de la ville !");
//    //            uiCD = CD_INFINY;
//    //            return;
//    //        }
//    //        uiCityBossGUID = cityBoss->GetGUID();
//    //        uiCD = 2000;
//    //        return;
//    //    }
//    //    case 2:
//    //    {
//    //        // Le boss dit un truc
//    //        if (Unit* boss = GetCityBoss())
//    //            boss->MonsterYell("Gardes, venez defendre votre ville !", 0, 0);
//
//    //        uiCD = 3000;
//    //        return;
//    //    }
//    //    case 3:
//    //    {
//    //        // Il invoque ses adds
//    //        for (uint8 i = 1; i <= NPC_BOSS_ADD1_COUNT; ++i)
//    //            CityBossSummonCreature(NPC_BOSS_CAPITAL_ADD1);
//    //        uiCD = 3000;
//    //        // Pendant ce temps, notre maitre sombre envoit des attaques avec de jolis visuels
//    //        ME->CastSpell(ME, 19823, false);
//    //        return;
//    //    }
//    //    case 4:
//    //    {
//    //        // Il invoque ses adds (bis)
//    //        for (uint8 i = 1; i <= NPC_BOSS_ADD2_COUNT; ++i)
//    //            CityBossSummonCreature(NPC_BOSS_CAPITAL_ADD2);
//    //        // Pendant ce temps, notre maitre sombre envoit des attaques avec de jolis visuels (bis)
//    //        ME->CastSpell(ME, 8609, false);
//    //        MasterYell("J'appelle les forces des profondeurs : transformez moi cette ville en ruine.");
//    //        uiCD = 3000;
//    //        return;
//    //    }
//    //    case 5:
//    //    {
//    //        // Le maitre sombre invoque des adds lui aussi
//    //        CityBossYell("A l'attaque, mes braves !");
//    //        for (uint8 i = 0; i <= MASTER_ADD1_COUNT; ++i)
//    //            MasterSummonCreatureAndAttack(NPC_MASTER_ADD1);
//    //        uiCD = 3000;
//    //        return;
//    //    }
//    //    case 6:
//    //    {
//    //        // Le maitre sombre invoque des adds lui aussi (bis)
//    //        for (uint8 i = 0; i <= MASTER_ADD2_COUNT; ++i)
//    //            MasterSummonCreatureAndAttack(NPC_MASTER_ADD2);
//    //        uiCD = 3000;
//    //        return;
//    //    }
//    //    case 7:
//    //    {
//    //        MasterSay("La bataille peut commencer.");
//    //        // Tout le monde redevient attaquable
//    //        SetAllAttackable();
//    //        return;
//    //    }
//    //    }
//    //}
//#endif
//    void UpdateAI(uint32 const uiDiff) override
//    {
//        if (uiCD < uiDiff)
//        {
//            uint32 oldPhase = uiPhase;
//            uiCurrentPhaseStep++;
//#ifdef DEBUG_ON
//            //sLog.Out(LOG_BASIC, LOG_LVL_MINIMAL, "Updating phase %u, step %u", uiPhase, uiCurrentPhaseStep);
//#endif
//            switch (uiPhase)
//            {
//            case PHASE_INVOC_SUMMONERS:
//                UpdateEvent_Summoners(uiDiff);
//                break;
//            case PHASE_WAVES:
//                UpdateEvent_Waves(uiDiff);
//                break;
//            case PHASE_FINAL_FIGHT:
//                //UpdateEvent_FinalFight(uiDiff);
//                break;
//            }
//            if (uiPhase != oldPhase)
//                uiCurrentPhaseStep = 0;
//#ifdef DEBUG_ON
//            if (uiCD > 5000)
//                uiCD = 5000; // On accelere le tout.
//#endif
//        }
//        else
//            uiCD -= uiDiff;
//        if (uiPhase == PHASE_FINAL_FIGHT)
//            DoMeleeAttackIfReady();
//    }
//};
//
//CreatureAI* GetAI_npc_attack_master(Creature* pCreature)
//{
//    return new npc_attack_masterAI(pCreature);
//}
//
//// #######################
//// #  npc_event_wave_mob #
//// #######################
//// Chaque mob invoque par l'invocateur aura ce script.
//
//enum
//{
//    SPELL_DESTRUCTION = 19984,
//    GOBJ_FEU_ENTRY = 184752,
//    GOBJ_FUMEE_ENTRY = 149018,
//    NEAR_DEATH_SPELL = 13914,
//};
//
//#define YELL_AT_DESTRUCTION_1 "Booom !"
//#define YELL_AT_DESTRUCTION_2 "Moi tout casser !"
//
//struct npc_event_wave_mobAI : public ScriptedAI
//{
//    npc_event_wave_mobAI(Creature* pCreature, bool isBad) : ScriptedAI(pCreature)
//    {
//        bIsBad = isBad;
//        // Les textes
//        if (bIsBad)
//        {
//            m_lSayStr.push_back("Moi tuer !");
//            m_lSayStr.push_back("Moi obeir.");
//            m_lSayStr.push_back("Moi te voir, moi te chercher, moi te tuer.");
//        }
//        else
//        {
//            m_lSayStr.push_back("Stormwind ne tombera pas.");
//            m_lSayStr.push_back("Nous repousserons vos attaques une par une.");
//            m_lSayStr.push_back("La garde meurt, et ne se rend pas !");
//        }
//
//        // Les sorts
//        if (bIsBad)
//            m_lSpells.push_back(8609);
//        else
//        {
//
//        }
//
//        fRespawnPositionX = -8958.0f;
//        fRespawnPositionY = 517.0f;
//        fRespawnPositionZ = 96.9f;
//        Reset();
//    }
//
//    uint32 uiCD;
//    uint32 uiGobjEntry;
//    float fRespawnPositionX;
//    float fRespawnPositionY;
//    float fRespawnPositionZ;
//    bool bIsBad;
//    std::vector<std::string> m_lSayStr;
//    std::vector<uint32> m_lSpells;
//    std::vector<uint32> m_lGobj;
//
//    void Reset() override
//    {
//        uiCD = urand(5, 10) * 1000;
//    }
//    //void DoSummonGobj(uint32 uiGobjEntry, uint32 timeSpawned)
//    //{
//    //    float x, y;
//    //    GetRandomNearLoc(ME, x, y);
//    //    GameObject* gobj = m_creature->SummonGameObject(
//    //        uiGobjEntry,
//    //        x,
//    //        y,
//    //        m_creature->GetPositionZ(),
//    //        m_creature->GetOrientation(),
//    //        0.0f, 0.0f, 0.0f, 0.0f, timeSpawned
//    //    );
//    //   /* if (!gobj)
//    //        sLog.Out(LOG_BASIC, LOG_LVL_ERROR, "Impossible de spawner le gobj [Entry:%u]", uiGobjEntry);*/
//    //}
//   /* void DoSayRandom()
//    {
//        std::string sayStr = m_lSayStr[urand(0, m_lSayStr.size() - 1)];
//        ME->MonsterSay(sayStr.c_str(), 0, 0);
//    }
//    void DoCastRandomSpell()
//    {
//        uint32 randEntry = m_lSpells[urand(0, m_lSpells.size() - 1)];
//        ME->CastSpell(ME->GetVictim(), randEntry, false);
//    }*/
//    //void DoSpawnRandomGobj()
//    //{
//    //    uint32 randEntry = m_lGobj[urand(0, m_lGobj.size() - 1)];
//    //    DoSummonGobj(randEntry, 25);
//    //}
//    //void DoSpawnDestruction()
//    //{
//    //    // Si il y a deja un Gobj "feu" dans les environs, on arrete
//    //    // Histoire de pas surcharger les clients
//    //    if (GetClosestGameObjectWithEntry(ME, GOBJ_FEU_ENTRY, 5.0f))
//    //        return;
//    //    // On lance un sort "explosion", et on spawn un GoBj qui fait le visuel pendant 2 minutes
//    //    uint32 uiSpawnGobjEntry = 0;
//    //    switch (urand(0, 1))
//    //    {
//    //    case 0:
//    //        uiSpawnGobjEntry = GOBJ_FEU_ENTRY;
//    //        break;
//    //    case 1:
//    //        uiSpawnGobjEntry = GOBJ_FUMEE_ENTRY;
//    //        break;
//    //    }
//    //    ME->CastSpell(ME, SPELL_DESTRUCTION, false);
//    //    DoSummonGobj(uiSpawnGobjEntry, 120);
//    //    uint32 rnd = urand(0, 4);
//    //    if (rnd % 2 == 0)
//    //    {
//    //        if (rnd <= 2)
//    //            ME->MonsterYell(YELL_AT_DESTRUCTION_1, 0, 0);
//    //        else
//    //            ME->MonsterYell(YELL_AT_DESTRUCTION_2, 0, 0);
//    //    }
//    //}
//    //void DoRandomAction()
//    //{
//    //    if (bIsBad)
//    //    {
//    //        switch (urand(0, 5))
//    //        {
//    //        case 0:
//    //        case 1:
//    //            DoSayRandom();
//    //            break;
//    //        case 2:
//    //            DoCastRandomSpell();
//    //            break;
//    //            /*case 3:
//    //                DoSpawnRandomGobj();
//    //                break;*/
//    //        case 3:
//    //        case 4:
//    //        case 5:
//    //            DoSpawnDestruction();
//    //            break;
//    //        }
//    //    }
//    //    else
//    //    {
//    //        switch (urand(0, 5))
//    //        {
//    //        case 0:
//    //        case 1:
//    //            DoSayRandom();
//    //            break;
//    //        }
//    //        if (ME->GetHealthPercent() < 10.0f && !ME->HasAura(NEAR_DEATH_SPELL))
//    //            ME->CastSpell(ME, NEAR_DEATH_SPELL, false);
//    //    }
//    //}
//    //Unit* GetRandomNearUnitToAttack()
//    //{
//    //    std::list<Unit*> targets;
//    //    MaNGOS::AnyUnfriendlyUnitInObjectRangeCheck u_check(ME, ME, 120.0f);
//    //    MaNGOS::UnitListSearcher<MaNGOS::AnyUnfriendlyUnitInObjectRangeCheck> searcher(targets, u_check);
//    //    Cell::VisitAllObjects(ME, searcher, 120.0f);
//    //    Unit* nearest = nullptr;
//    //    uint32 quality = 0;
//    //    for (const auto& target : targets)
//    //    {
//    //        uint32 currVictimQuality = 0;
//    //        if (target->GetFactionTemplateId() == ME->GetFactionTemplateId())
//    //            continue;
//    //        if (!target->IsAlive())
//    //            continue;
//    //        uint32 entry = target->GetEntry();
//    //        if (entry == NPC_BOSS_CAPITAL_ADD1 || entry == NPC_BOSS_CAPITAL_ADD2
//    //            || entry == NPC_MASTER_ADD1 || entry == NPC_MASTER_ADD2)
//    //            currVictimQuality += 0xF0;
//    //        if (!nearest)
//    //        {
//    //            nearest = target;
//    //            currVictimQuality += 0x1;
//    //        }
//    //        // Priorite a attaquer dans la LoS
//    //        if (target->IsWithinLOSInMap(ME))
//    //            currVictimQuality += 0x4;
//    //        // Plus pret ?
//    //        if (target->GetDistance2d(ME) <= nearest->GetDistance2d(ME))
//    //            currVictimQuality += 0x2;
//    //        // Autre priorite : le niveau
//    //        if (target->GetLevel() > 50)
//    //            currVictimQuality += (target->GetLevel() - 50);
//    //        if (currVictimQuality > quality)
//    //        {
//    //            quality = currVictimQuality;
//    //            nearest = target;
//    //        }
//    //    }
//    //    // Il faut quand meme s'arreter a un moment, sinon toute la foret d'Elwynn va y passer.
//    //    if (quality <= 7)
//    //        return nullptr;
//    //    return nearest;
//    //}
//    //void UpdateAI(uint32 const uiDiff) override
//    //{
//    //    if (ME->IsStopped() && !ME->GetVictim())
//    //    {
//    //        if (Unit* newTarget = GetRandomNearUnitToAttack())
//    //            AttackStart(newTarget);
//    //        else
//    //        {
//    //            //sLog.Out(LOG_BASIC, LOG_LVL_ERROR, "Impossible de trouver une cible.");
//    //            return;
//    //        }
//    //    }
//    //    if (uiCD < uiDiff)
//    //    {
//    //        DoRandomAction();
//    //        uiCD = urand(5, 10) * 1000;
//    //    }
//    //    else
//    //        uiCD -= uiDiff;
//
//    //    DoMeleeAttackIfReady();
//    //}
//    //void JustDied(Unit* killer) override
//    //{
//    //    if (bIsBad)
//    //        DoSpawnDestruction();
//    //}
//};
//
//CreatureAI* GetAI_npc_event_wave_mob(Creature* pCreature)
//{
//    return new npc_event_wave_mobAI(pCreature, true);
//}
//CreatureAI* GetAI_npc_event_wave_mob_good(Creature* pCreature)
//{
//    return new npc_event_wave_mobAI(pCreature, false);
//}
//
////
//// npc_guard_master
////
//
//enum
//{
//    PHASE_SUMMON_GUARD = 1,
//    PHASE_IN_ATTACK = 2,
//
//    NPC_GUARD_1 = 1976,
//    NPC_GUARD_2 = 68,
//};
//
//struct npc_guard_masterAI : public ScriptedAI
//{
//    npc_guard_masterAI(Creature* pCreature) : ScriptedAI(pCreature)
//    {
//        uiCurrentPhaseStep = 0;
//        uiCD = 1000;
//        uiPhase = PHASE_SUMMON_GUARD;
//        uiSummonNum = 0;
//        fSummonPositionX = pCreature->GetPositionX();
//        fSummonPositionY = pCreature->GetPositionY();
//        fSummonPositionZ = pCreature->GetPositionZ();
//        fSummonOrientation = pCreature->GetOrientation();
//        Reset();
//    }
//
//    uint32 uiCD;
//    uint32 uiCurrentPhaseStep;
//    uint32 uiPhase;
//
//    uint32 uiSummonNum;
//
//    float fSummonPositionX;
//    float fSummonPositionY;
//    float fSummonPositionZ;
//    float fSummonOrientation;
//
//    // Event invocateurs
//    MobsGUIDList lMyAddsMobsGUID;
//    uint64 uiTarget;
//    // Fonctions generiques
//#if 1
//    void Reset() override
//    {
//        uiTarget = 0;
//    }
//    /*void MasterSay(char const* what)
//    {
//        ME->MonsterSay(what, 0, 0);
//    }
//    void MasterYell(char const* what)
//    {
//        ME->MonsterYell(what, 0, 0);
//    }*/
//    //void MoveInLineOfSight(Unit* pWho) override
//    //{
//    //    if (!uiTarget && pWho->GetTypeId() != TYPEID_PLAYER)
//    //        DoAllAttack(pWho);
//    //}
//#endif
//#if 1
//    // Deroulement de l'event
//    // ################################
//    // #        PHASE 1               #
//    // ################################
//    // Le maitre de la guarde "invoque" des gardes pour l'aider.
//    void DoSummonGard()
//    {
//        // Position de la garde :
//        // 6 4 2 [MAITRE] 1 3 5 ...
//        // Sur le rang de devans, ou de derriere ?
//        float range = 0.0f;
//        //float orientation = ME->GetOrientation() + M_PI / 2.0f;
//        float dist_coef;
//
//        //float x_coef = cos(orientation);
//        //float y_coef = sin(orientation);
//        switch (uiSummonNum % 2)
//        {
//        case 0:
//            dist_coef = 0.5f;
//            break;
//        case 1:
//            dist_coef = -0.5f;
//            break;
//        }
//        switch ((uiSummonNum) % 4)
//        {
//        case 0:
//        case 1:
//            range = -5.0f;
//            break;
//        case 2:
//        case 3:
//            range = -1.0f;
//            break;
//        }
//        float dist = dist_coef * float(uiSummonNum);
//        /*float x_range_add = cos(ME->GetOrientation()) * range;
//        float y_range_add = sin(ME->GetOrientation()) * range;
//
//        float positionX = ME->GetPositionX() + x_coef * dist + x_range_add;
//        float positionY = ME->GetPositionY() + y_coef * dist + y_range_add;*/
//#ifdef DEBUG_ON
//        /*sLog.Out(LOG_BASIC, LOG_LVL_MINIMAL, "[%u] Summon : coef [%f:%f] / dist [coef%f:%f] / pos [%f:%f] / o[%f]",
//            ME->GetEntry(), x_coef, y_coef, dist_coef, dist, positionX, positionY, orientation);*/
//#endif
//        uint32 creatureEntry;
//        switch (urand(0, 1))
//        {
//        case 0:
//            creatureEntry = NPC_GUARD_1;
//            break;
//        case 1:
//            creatureEntry = NPC_GUARD_2;
//            break;
//        }
//        //Creature* guard = ME->SummonCreature(
//        //    creatureEntry,
//        //    positionX,
//        //    positionY,
//        //    ME->GetPositionZ() + 1.0f,
//        //    ME->GetOrientation(), // Vers le "SUD"
//        //    TEMPSUMMON_MANUAL_DESPAWN,
//        //    0
//        //);
//        /*if (guard)
//            lMyAddsMobsGUID.push_back(guard->GetGUID());*/
//    }
//
//    void UpdateEvent_GuardsSummon(uint32 const uiDiff)
//    {
//        // 20 Gardes au total
//        if (uiCurrentPhaseStep > 0 && uiCurrentPhaseStep < 20)
//        {
//            ++uiSummonNum;
//            DoSummonGard();
//            uiCD = 500;
//        }
//        else
//        {
//            DoAllSay("Garde prete !");
//            uiPhase = PHASE_IN_ATTACK;
//            uiCD = 0;
//        }
//    }
//#endif
//#if 1
//    // ################################
//    // #        PHASE 2               #
//    // ################################
//    // La garde est invoquee : maintenant elle doit attaquer
//    //void DoAllAttack(Unit* pUnit)
//    //{
//    //    for (const auto& itr : lMyAddsMobsGUID)
//    //    {
//    //        if (Unit* crea = Unit::GetUnit(*ME, itr))
//    //        {
//    //            if (crea->IsAlive())
//    //                ((Creature*)crea)->AI()->AttackStart(crea);
//    //        }
//    //    }
//    //}
//    void DoAllSay(char const* what)
//    {
//        //for (const auto& itr : lMyAddsMobsGUID)
//        //{
//        //    if (Unit* crea = Unit::GetUnit(*ME, itr))
//        //    {
//        //        if (crea->IsAlive())
//        //            ((Creature*)crea)->MonsterSay(what, 0, 0);
//        //    }
//        //}
//    }
//    void UpdateEvent_Fight(uint32 const uiDiff)
//    {
//        uiCD = urand(60, 90) * 1000;
//        //switch (uiCurrentPhaseStep)
//        //{
//        //case 1:
//        //    MasterYell("A l'attaaaaaqqqquuueeeeee !!!");
//        //    break;
//        //default:
//        //{
//        //    break;
//        //}
//        //}
//    }
//#endif
//    void UpdateAI(uint32 const uiDiff) override
//    {
//        if (uiCD < uiDiff)
//        {
//            uint32 oldPhase = uiPhase;
//            uiCurrentPhaseStep++;
//#ifdef DEBUG_ON
//            //sLog.Out(LOG_BASIC, LOG_LVL_MINIMAL, "[%u]Updating phase %u, step %u", ME->GetEntry(), uiPhase, uiCurrentPhaseStep);
//#endif
//            switch (uiPhase)
//            {
//            case PHASE_SUMMON_GUARD:
//                UpdateEvent_GuardsSummon(uiDiff);
//                break;
//            case PHASE_IN_ATTACK:
//                UpdateEvent_Fight(uiDiff);
//                break;
//            }
//            if (uiPhase != oldPhase)
//                uiCurrentPhaseStep = 0;
//#ifdef DEBUG_ON
//            if (uiCD > 5000)
//                uiCD = 5000; // On accelere le tout.
//#endif
//        }
//        else
//            uiCD -= uiDiff;
//
//        DoMeleeAttackIfReady();
//    }
//};
//
//CreatureAI* GetAI_npc_guard_master(Creature* pCreature)
//{
//    return new npc_guard_masterAI(pCreature);
//}
//void AddSC_event_attack_city()
//{
//    /*Script* pNewScript;
//    pNewScript = new Script;
//    pNewScript->Name = "npc_attack_master";
//    pNewScript->GetAI = &GetAI_npc_attack_master;
//    pNewScript->RegisterSelf();
//
//    pNewScript = new Script;
//    pNewScript->Name = "npc_event_wave_mob";
//    pNewScript->GetAI = &GetAI_npc_event_wave_mob;
//    pNewScript->RegisterSelf();
//
//    pNewScript = new Script;
//    pNewScript->Name = "npc_event_wave_mob_good";
//    pNewScript->GetAI = &GetAI_npc_event_wave_mob_good;
//    pNewScript->RegisterSelf();
//
//    pNewScript = new Script;
//    pNewScript->Name = "npc_guard_master";
//    pNewScript->GetAI = &GetAI_npc_guard_master;
//    pNewScript->RegisterSelf();*/
//}
