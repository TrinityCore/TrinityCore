#ifndef IRON_DOCKS_H
#define IRON_DOCKS_H

#define DataHeader      "ID"
#define IDScriptName    "instance_iron_docks"
#define IDMapId         1195

uint32 const EncounterCount = 4;

enum InstanceData
{
    DATA_FLESHRENDER_NOKGAR     = 0,
    DATA_GRIMRAIL_ENFORCERS,
    DATA_OSHIR,
    DATA_SKULLOC,
    ENCOUNTER_COUNT,

    // Fleshrender Nokgar

    // Grimrail Enforcers

    // Oshir

    // Skulloc

    // Various
};

enum CreatureEntries
{
    // Fleshrender Nokgar
    BOSS_FLESHRENDER_NOKGAR     = 81305,
    NPC_DREADFANG_MOUNTED       = 87241,
    NPC_DREADFANG               = 81297,

    // Grimrail Enforcers
    BOSS_GRIMRAIL_ENFORCERS     = 82184,
    NPC_AHRIOK_DUGRU            = 80816,
    NPC_MAKOGG_EMBERBLADE       = 86231,
    NPC_NEESA_NOX               = 80808,

    NPC_OGRE_TRAP               = 88758,
    NPC_BOMBSQUAD               = 80875,

    // Oshir
    BOSS_OSHIR                  = 79852,
    NPC_RAVENOUS_WOLF           = 89012,
    NPC_RYLAK_SKYTERROR         = 89011,

    // Skulloc
    BOSS_SKULLOC                = 83612,
    NPC_KORAMAR                 = 83613,
    NPC_ZOGGOSH                 = 83616,

    // Various
};

enum GameObjectEntries
{
};

template<class AI>
AI* GetIronDocksAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, IDScriptName);
}

template <typename AI>
struct IronDocksAILoader : public CreatureScript
{
    IronDocksAILoader(const char* scriptname) :
        CreatureScript(scriptname) { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetIronDocksAI<AI>(creature);
    }
};

#endif /* IRON_DOCKS_H */
