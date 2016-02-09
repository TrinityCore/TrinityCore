#ifndef BLOODMAUL_SLAG_MINES_H
#define BLOODMAUL_SLAG_MINES_H

#define DataHeader "BSM"
#define BSMScriptName "instance_bloodmaul_slag_mines"

uint32 const EncounterCount = 4;

enum InstanceData
{
    DATA_SLAVE_WATCHER_CRUSHTO = 0,
    DATA_FORGEMASTER_GOG_DUH,
    DATA_ROLTALL,
    DATA_GUG_ROKK,
    ENCOUNTER_COUNT,

    // Slave Watcher Crushto

    // Forgemaster Gog'duh

    // Roltall

    // Gug'Rokk
};

enum CreatureEntries
{
    // Slave Watcher Crushto
    BOSS_SLAVE_WATCHER_CRUSHTO      = 74787,

    NPC_CAPTURED_MINER_0            = 74355,
    NPC_CAPTURED_MINER_1            = 74356,
    NPC_CAPTURED_MINER_2            = 74357,

    // Forgemaster Gog'duh
    BOSS_FORGEMASTER_GOG_DUH        = 74366,

    // Roltall
    BOSS_ROLTALL                    = 75786,

    // Gug'Rokk
    BOSS_GUG_ROKK                   = 74790,


};

enum GameObjectEntries
{
};

template<class AI>
AI* GetBloodmaulSlagMinesAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, BSMScriptName);
}

template <typename AI>
struct BloodmaulSlagMinesAILoader : public CreatureScript
{
    BloodmaulSlagMinesAILoader(const char* scriptname) :
        CreatureScript(scriptname) { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetBloodmaulSlagMinesAI<AI>(creature);
    }
};

#endif /* BLOODMAUL_SLAG_MINES_H */
