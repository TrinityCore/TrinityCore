#ifndef DEF_SHIELDS_REST
#define DEF_SHIELDS_REST

enum Spells
{
};

enum Data
{
    DATA_STAGE_1                = 0,
    DATA_STAGE_2                = 1,
    DATA_STAGE_3                = 2,
    DATA_STAGE_4                = 3,
    DATA_STAGE_5                = 4,
    DATA_STAGE_FINAL            = 5,

    DATA_YRGRIM_EVENT,
};

enum eSpells
{
    //- Stage 2
    SPELL_LIGHTNING_BLAST       = 210711,
    SPELL_INNA_SHOOT            = 210661,
    SPELL_INNA_PIN_DOWN_FILTER  = 210426,
    SPELL_INNA_PIN_DOWN         = 210395,

    SPELL_SHADOWY_GHOST_VISUAL  = 210118,
    SPELL_LIGHTNING_STRIKE_VIS  = 210842,

    SPELL_FIERCE_WINDS          = 210976,
    SPELL_FIERCE_WINDS_AT       = 210975,
    SPELL_FIERCE_WINDS_STUN     = 210942,
    SPELL_COLDWIND_BLAST        = 191038,

    SPELL_SPIRIT_WINDS_AT       = 210880,

    //- Stage 5
    SPELL_PENTA_STRIKE          = 191883,
    SPELL_BLADESTORM            = 128749,
    SPELL_SHIELD_BASH           = 191887,

    SPELL_GOLDEN_GHOST_VISUAL   = 210310,
    SPELL_FROSTBOLT             = 209851,
    SPELL_RAZOR_ICE             = 211067, //189510 dmg
    SPELL_RAZOR_ICE_AT          = 189487,
    SPELL_ICE_BLOCK_TARGET_AURA = 211014,
    SPELL_ICE_BLOCK             = 211011,
    SPELL_ICICLE_BARRAGE        = 209846,
    
    //- Stage Final
    SPELL_PETRIFIED             = 210338,
    SPELL_DIVINE_SHIELD         = 642,
    SPELL_COSMETIC_HEARTHSTONE  = 181040,

    //Other
    SPELL_SCALING_ITEM_LEVEL    = 197352,
    SPELL_SUMMON_HIPPO          = 209884,
    SPELL_FLY_TO_STORMHEIM      = 209908,
    SPELL_SUMMON_ORIK           = 210036,
    SPELL_SUMMON_CATO           = 210043,
    SPELL_SCENE_YRGRIM          = 210269,
    SPELL_TRUTHGUARD_SCENE      = 210132,
    SPELL_TRUTHGUARD_CREDIT     = 210133,
    SPELL_SUMMON_HIPPO_INST     = 210358,
    SPELL_RETURN_TO_DALARAN     = 210360,

    SPELL_CATO_HOLY_LIGHT_1     = 210373,
    SPELL_CATO_HOLY_LIGHT_2     = 215986,
    SPELL_CATO_DENOUNCE         = 210374,
    SPELL_CATO_HOLY_SHOCK       = 210375,
    SPELL_CATO_LIGHT_OF_DAWN    = 210376,

    SPELL_ORIK_CRUSADER_STRIKE  = 210370,
    SPELL_ORIK_DIVINE_STORM     = 210369,
    SPELL_ORIK_HAMMER_JUSTICE   = 210368,
    SPELL_ORIK_JUDGMENT         = 210371,
};

enum eCreatures
{
    //Stage 1
    NPC_ORIK_TRUEHEART_INTRO    = 105910,
    NPC_CATO_INTRO              = 105694,

    NPC_ORIK_TRUEHEART_PET      = 105911,
    NPC_CATO_PET                = 105912,

    //Stage 2
    NPC_INNA_THE_CRYPTSTALKER   = 106245,
    NPC_DRAKE_SHAE              = 106246,
    NPC_QUICKSTEEL_ARROW        = 106230, //Trigger

    NPC_SPECTRAL_CHAMPION       = 106347,
    NPC_RESTLESS_TOMBGUARD      = 105967,
    NPC_GUARDIAN_ORB            = 105966,
    NPC_SPECTRAL_WINDSHAPER     = 105968,
    NPC_FIERCE_WINDS            = 106432, //Trigger
    NPC_INVISIBLE_MAN           = 64367, //Trigger

    //Stage 5
    NPC_YRGRIM_THE_TRUTHSEEKER  = 105695,
    NPC_RUNESHAPER_GRISELDA     = 106172,
    NPC_RAZOR_ICE               = 106527,
    
    //Stage Final
    NPC_YRGRIM_TRUTHSEEKER_2    = 106202,
    NPC_TRUTHGUARD_OATHSEEKER   = 106190, //Trigger

    //Other
    NPC_HIPPOGRYPH_DALARAN      = 105883,
    NPC_HIPPOGRYPH_DALARAN_SUM  = 105886,
    NPC_HIPPOGRYPH_SCENARIO     = 106203,
    NPC_HIPPOGRYPH_SCENARIO_SUM = 106205,
    
};

enum eGameObects
{
    GO_FIRST_DOOR               = 249364,
    GO_EVENT_DOOR               = 249458,
    GO_YRGRIM_JOURNEY           = 249402,
    GO_YRGRIM_CHALLENGE         = 249403,
    GO_YRGRIMS_REST             = 249404,
    GO_ART_CHEST                = 249420,
};

Position const doorPos[2] =
{
    {4809.79f, 168.43f, -11.21f, 4.51f},
    {4844.10f, 346.21f, -28.97f, 4.51f}
};

Position const windshaperPos[3] =
{
    {4831.78f, 337.74f, -28.89f}, //210976
    {4841.72f, 335.98f, -28.89f}, //210977
    {4850.86f, 334.13f, -28.89f}  //210978
};

Position const windEndPos[3] =
{
    {4818.89f, 263.76f, -28.97f},
    {4828.64f, 261.48f, -28.97f},
    {4837.18f, 259.24f, -28.97f}
};

Position const igrimEventPos[4] =
{
    {4820.45f, 232.03f, -21.70f},
    {4828.43f, 264.62f, -28.97f},
    {4840.41f, 330.45f, -28.89f},
    {4848.82f, 369.0f,  -36.08f}
};

#endif
