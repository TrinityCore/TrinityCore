#include "../iron_docks.h"

enum Spells
{
    // Force spells and spells beneath are casted by controller
    SPELL_OGRE_TRAPS_CONTROL                    = 166568, //(+)SPELL_AURA_DUMMY
    SPELL_SANGUINE_SPHERE_CONTROL               = 166591, //(+)SPELL_AURA_DUMMY

    // Ahri'ok Dugru
    SPELL_BLOOD_BOLT                            = 165122, // + SPELL_EFFECT_SCHOOL_DAMAGE (N|H|C)

    SPELL_SANGUINE_SPHERE_FORCE                 = 165327, // + SPELL_EFFECT_FORCE_CAST
    SPELL_SANGUINE_SPHERE                       = 163689, // +-> + SPELL_AURA_SCHOOL_ABSORB (N|H)

    SPELL_TAINTED_BLOOD_FORCE                   = 165326, // + SPELL_EFFECT_FORCE_CAST
    SPELL_TAINTED_BLOOD                         = 163740, // +-> + SPELL_AURA_PERIODIC_DAMAGE (N|H|C)

    // Makogg Emberblade
    SPELL_FLAMING_SLASH_FORCE                   = 165307, // + SPELL_EFFECT_FORCE_CAST
    SPELL_FLAMING_SLASH                         = 163668, // +-> + SPELL_EFFECT_SCHOOL_DAMAGE (N|H|C)

    SPELL_LAVA_SWEEP_FORCE                      = 165152, // + SPELL_EFFECT_FORCE_CAST
    SPELL_LAVA_SWEEP                            = 165152, // +-> + SPELL_AURA_PERIODIC_DAMAGE (N|H|C)

    // Neesa Nox
    SPELL_GUTSHOT                               = 163334, // + SPELL_EFFECT_SCHOOL_DAMAGE (N|H|C)
    SPELL_BOMBSQUAD                             = 163362, // + SPELL_EFFECT_SUMMON[80875]

    SPELL_OGRE_TRAPS_1                          = 163275, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_2                          = 163278, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_3                          = 163279, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_4                          = 163303, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_5                          = 163304, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_6                          = 163305, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_7                          = 163306, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_8                          = 163307, // + SPELL_EFFECT_TRIGGER_MISSILE
    SPELL_OGRE_TRAPS_SUMMON                     = 163277, // +-> + SPELL_EFFECT_SUMMON[88758]

    SPELL_OGRE_TRAPS_FORCE                      = 165323, // + SPELL_EFFECT_FORCE_CAST
    SPELL_OGRE_TRAPS                            = 163390, // +-> + SPELL_AURA_PERIODIC_TRIGGER_SPELL
    SPELL_OGRE_TRAPS_SOUND                      = 171119, //     + SPELL_EFFECT_DUMMY

    SPELL_MALFUNCTIONING_JUMPER_CABLES_FORCE    = 165321, // + SPELL_EFFECT_FORCE_CAST
    SPELL_MALFUNCTIONING_JUMPER_CABLES          = 163376, // +-> + SPELL_EFFECT_SCHOOL_DAMAGE (N|H|C)

    // Neesa Nox - Ogre Trap
    SPELL_SHREDDED_TENDONS                      = 163276, // + SPELL_AURA_PERIODIC_DAMAGE (N|H|C) | SPELL_AURA_MOD_DECREASE_SPEED | SPELL_EFFECT_TRIGGER_SPELL
    SPELL_SHREDDED_TENDONS_STUN                 = 163276, // +-> + SPELL_AURA_MOD_STUN

    // Neesa Nox - Bombsquad
    SPELL_CHARGE                                = 163635, // + SPELL_EFFECT_JUMP_DEST | SPELL_AURA_DUMMY
    SPELL_BIG_BOOM                              = 163379, // +-> + SPELL_EFFECT_SCHOOL_DAMAGE (N|H|C) | SPELL_EFFECT_INSTAKILL

    // Shared
    SPELL_SUICIDE                               = 117624, // + SPELL_EFFECT_INSTAKILL
    SPELL_FEIGN_DEATH                           = 145363, // + SPELL_AURA_DUMMY | SPELL_AURA_MOD_STUN | SPELL_AURA_UNTRACKABLE
    SPELL_CANNON_BARRAGE                        = 168515, //(+)SPELL_AURA_DUMMY
    SPELL_ABRUPT_RESTORATION_H                  = 163705, // + SPELL_AURA_OBS_MOD_HEALTH (N|H|C) | SPELL_EFFECT_SEND_EVENT[41990]
    // Somehow triggered by 167638, 167644, 167645
    SPELL_EXIT_THE_GRIMRAIL                     = 167639, // + (Spell Effect 203) Server side spell 167637
};

enum Events
{
    // Ahri'ok Dugru
    EVENT_BLOOD_BOLT                            = 1,
    EVENT_SANGUINE_SPHERE,
    EVENT_TAINTED_BLOOD,

    // Makogg Emberblade
    EVENT_FLAMING_SLASH,
    EVENT_LAVA_SWEEP,

    // Neesa Nox
    EVENT_GUTSHOT,
    EVENT_MALFUNCTIONING_JUMPER_CABLES,
    EVENT_OGRE_TRAPS,
    EVENT_BOMBSQUAD,
};

enum Timer
{
    // Ahri'ok Dugru
    TIME_BLOOD_BOLT_INIT                        = 0 * IN_MILLISECONDS,
    TIME_BLOOD_BOLT_MIN                         = 0 * IN_MILLISECONDS,
    TIME_BLOOD_BOLT_MAX                         = 0 * IN_MILLISECONDS,

    TIME_SANGUINE_SPHERE_INIT                   = 0 * IN_MILLISECONDS,
    TIME_SANGUINE_SPHERE_MIN                    = 0 * IN_MILLISECONDS,
    TIME_SANGUINE_SPHERE_MAX                    = 0 * IN_MILLISECONDS,

    TIME_TAINTED_BLOOD_INIT                     = 0 * IN_MILLISECONDS,
    TIME_TAINTED_BLOOD_MIN                      = 0 * IN_MILLISECONDS,
    TIME_TAINTED_BLOOD_MAX                      = 0 * IN_MILLISECONDS,

    // Makogg Emberblade
    TIME_FLAMING_SLASH_INIT                     = 0 * IN_MILLISECONDS,
    TIME_FLAMING_SLASH_MIN                      = 0 * IN_MILLISECONDS,
    TIME_FLAMING_SLASH_MAX                      = 0 * IN_MILLISECONDS,

    TIME_LAVA_SWEEP_INIT                        = 0 * IN_MILLISECONDS,
    TIME_LAVA_SWEEP_MIN                         = 0 * IN_MILLISECONDS,
    TIME_LAVA_SWEEP_MAX                         = 0 * IN_MILLISECONDS,

    // Neesa Nox
    TIME_GUTSHOT_INIT                           = 0 * IN_MILLISECONDS,
    TIME_GUTSHOT_MIN                            = 0 * IN_MILLISECONDS,
    TIME_GUTSHOT_MAX                            = 0 * IN_MILLISECONDS,

    TIME_MALFUNCTIONING_JUMPER_CABLES_INIT      = 0 * IN_MILLISECONDS,
    TIME_MALFUNCTIONING_JUMPER_CABLES_MIN       = 0 * IN_MILLISECONDS,
    TIME_MALFUNCTIONING_JUMPER_CABLES_MAX       = 0 * IN_MILLISECONDS,

    TIME_OGRE_TRAPS_INIT                        = 0 * IN_MILLISECONDS,
    TIME_OGRE_TRAPS_MIN                         = 0 * IN_MILLISECONDS,
    TIME_OGRE_TRAPS_MAX                         = 0 * IN_MILLISECONDS,

    TIME_BOMBSQUAD_INIT                         = 0 * IN_MILLISECONDS,
    TIME_BOMBSQUAD_MIN                          = 0 * IN_MILLISECONDS,
    TIME_BOMBSQUAD_MAX                          = 0 * IN_MILLISECONDS,
};