#ifndef NYALOTHA
#define NYALOTHA

#define DataHeader "N"

uint32 const EncounterCount = 12;

enum DataTypes
{
    DATA_WRATHION = 1,
    DATA_MAUT,
    DATA_SKITRA,
    DATA_XANESH,
    DATA_HIVEMIND,
    DATA_SHADHAR,
    DATA_DRESTAGATH,
    DATA_ILGYNOTH,
    DATA_VEXIONA,
    DATA_RADEN,
    DATA_CARAPACE,
    DATA_NZOTH,
};

enum Creatures
{
    //Wrathion    
    NPC_NZOTH_CONTROLLER            = 161884,
    NPC_WRATHION                    = 156818,
    NPC_WRATHION_SPECIAL            = 161720,
    NPC_MOLTEN_ERUPTION_STALKER     = 157348,
    NPC_CRACKLING_SHARD             = 158327,
    NPC_ASHWALKER_ASSASIN           = 160291,
    //Maut
    NPC_MAUT                        = 156523,
    NPC_DARK_MANIFESTATION          = 156650,
    NPC_MANA_ORB                    = 500506,
    //Prophet Skitra
    NPC_PROPHET_SKITRA              = 157620,
    NPC_PROPGET_SKITRA_PROJECTION   = 161901,
    NPC_IMAGE_OF_ABSOLUTION         = 160990,
    NPC_SKITRA_ABSOLUTION_MOVEMENT_CONTROLLER = 500527,
    //Shadhar
    NPC_SHADHAR                     = 157231,
    NPC_LIVING_MIASMA               = 157229,
    NPC_ENTROPIC_BUILDUP            = 500600,
    //Hivemind
    NPC_KAZIR                       = 157253,
    NPC_TEKRIS                      = 157254,
    NPC_AQIR_DRONE                  = 157255,
    NPC_AQIR_DARTER                 = 157256,
    NPC_AQIR_RAVAGER                = 160599,
    //Xanesh
    NPC_XANESH                      = 156575,
    NPC_QUEEN_AZSHARA_XANESH        = 156575,
    NPC_FLAYED_SOUL                 = 157005,
    NPC_RITUAL_OBELISK              = 157126,
    NPC_LARGE_RITUAL_OBELISK        = 162098,
    NPC_AWAKENED_TERROR             = 162432,
    NPC_TORMENT_VEHICLE             = 156840,
    NPC_VOID_ORB                    = 500523,
    NPC_GOAL_PORTAL                 = 500524,
    //Drestagath
    NPC_DRESTAGATH                  = 157602,
    NPC_EYE_OF_DRESTAGATH           = 157612,
    NPC_TENTACLE_OF_DRESTAGATH      = 157614,
    NPC_MAW_OF_DRESTAGATH           = 157613,
    //Ilgynoth
    NPC_ILGYNOTH                    = 158328,
    NPC_ORGAN_OF_CORRUPTION         = 158343,
    NPC_BLOOD_OF_NYALOTHA           = 159514,
    NPC_CLOTTED_CORRUPTION          = 163678,
    //Vexiona
    NPC_VEXIONA                     = 157354,
    NPC_ASCENDANT                   = 162719,
    NPC_GIFT_OF_THE_VOID            = 157422,
    NPC_DARK_GATEWAY                = 161148,
    NPC_FANATICAL_CULTIST           = 162715,
    NPC_SPELLBOUND_RITUALIST        = 162716,
    NPC_SINISTER_SOULCARVER         = 162717,
    NPC_IRON_WILLED_ENFORCER        = 157451,
    //Raden
    NPC_RADEN                       = 156866,
    NPC_ESSENCE_OF_VITA             = 156884,
    NPC_ESSENCE_OF_VOID             = 156980,
    NPC_VOID_HUNTER                 = 157366,
    NPC_CRACKLING_STALKER           = 157365,
    NPC_ESSENCE_OF_NIGHTMARE        = 160663,
    NPC_NIGHT_TERROR                = 160937,
    NPC_UNSTABLE_VOID_STALKER       = 157235,
    NPC_VOID_POOL_STALKER           = 157252,
    //Carapace
    NPC_FURY_OF_NZOTH               = 157439,
    NPC_WRATHION_CARAPACE           = 160177,
    NPC_AMALGAMATION_OF_FLESH       = 163841,
    NPC_NIGHTMARE_ANTIGEN           = 157452,
    NPC_SYNTHESIS_GROWTH            = 157475,
    NPC_MYCELIAL_CYST               = 157461,
    NPC_THRASHING_TENTACLE          = 162159,
    NPC_GAZE_OF_MADNESS             = 157442,
    NPC_INFINITE_DARKNESS           = 163232,
    //N'Zoth
    NPC_NZOTH                       = 158041,
    NPC_PSYCHUS                     = 158376,
    NPC_EXPOSED_SYNAPSE             = 159578,
    NPC_CORRUPTED_NEURON            = 162331,
    NPC_BASHER_TENTACLE             = 158367,
    NPC_CORRUPTOR_TENTACLE          = 158375,
    NPC_SPIKE_TENTACLE              = 160249,
    NPC_MINDS_EYE                   = 158122,
    NPC_THOUGHT_HARVESTER           = 162933,
    //Misc
    NPC_REORIGINATION_ANCHOR        = 162120,
};

enum Gameobjects
{
    GO_VAULT_OF_THE_BLACKE_EMPIRE = 341820,
};

enum Achievements
{
    ACHIEVEMENT_MYTHIC_WRATHION = 14041,
    ACHIEVMENT_MYTHIC_MAUT = 14043,
    ACHIEVMENT_MYTHIC_PROPHET_SKITRA = 14044,
    ACHIEVEMENT_MYTHIC_SHADHAR = 14048,
    ACHIEVEMENT_MYTHIC_DRESTAGATH = 14049,
    ACHIEVEMENT_MYTHIC_ILGYNOTH = 14052,
    ACHIEVMENT_MYTHIC_HIVEMIND = 14046,
    ACHIEVEMENT_MYTHIC_VEXIONA = 14050,
    ACHIEVEMENT_MYTHIC_RADEN = 14051,
    ACHIEVEMENT_MYTHIC_CARAPACE = 14054,
    ACHIEVEMENT_MYTHIC_NZOTH = 14055,
};

#endif
