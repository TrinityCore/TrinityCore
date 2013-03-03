local CREA_ENTRIES =
{
    16520,
    16517,
    963,
    29212,
    416,
}

for _, CREA_ENTRY in ipairs(CREA_ENTRIES) do
RegisterCreatureEvent(CREA_ENTRY,   1,    function(...) print("CREATURE_EVENT_ON_ENTER_COMBAT",                 1,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   2,    function(...) print("CREATURE_EVENT_ON_LEAVE_COMBAT",                 2,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   3,    function(...) print("CREATURE_EVENT_ON_TARGET_DIED",                  3,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   4,    function(...) print("CREATURE_EVENT_ON_DIED",                         4,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   5,    function(...) print("CREATURE_EVENT_ON_SPAWN",                        5,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   6,    function(...) print("CREATURE_EVENT_ON_REACH_WP",                     6,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   7,    function(...) print("CREATURE_EVENT_ON_AIUPDATE",                     7,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   8,    function(...) print("CREATURE_EVENT_ON_RECEIVE_EMOTE",                8,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   9,    function(...) print("CREATURE_EVENT_ON_DAMAGE_TAKEN",                 9,    ...) end )
RegisterCreatureEvent(CREA_ENTRY,   10,   function(...) print("CREATURE_EVENT_ON_PRE_COMBAT",                   10,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   11,   function(...) print("CREATURE_EVENT_ON_ATTACKED_AT",                  11,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   12,   function(...) print("CREATURE_EVENT_ON_OWNER_ATTACKED",               12,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   13,   function(...) print("CREATURE_EVENT_ON_OWNER_ATTACKED_AT",            13,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   14,   function(...) print("CREATURE_EVENT_ON_HIT_BY_SPELL",                 14,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   15,   function(...) print("CREATURE_EVENT_ON_SPELL_HIT_TARGET",             15,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   16,   function(...) print("CREATURE_EVENT_ON_SPELL_CLICK",                  16,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   17,   function(...) print("CREATURE_EVENT_ON_CHARMED",                      17,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   18,   function(...) print("CREATURE_EVENT_ON_POSSESS",                      18,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   19,   function(...) print("CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE",       19,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   20,   function(...) print("CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN",    20,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   21,   function(...) print("CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED",       21,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   22,   function(...) print("CREATURE_EVENT_ON_SUMMONED",                     22,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   23,   function(...) print("CREATURE_EVENT_ON_RESET",                        23,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   24,   function(...) print("CREATURE_EVENT_ON_REACH_HOME",                   24,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   25,   function(...) print("CREATURE_EVENT_ON_CAN_RESPAWN",                  25,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   26,   function(...) print("CREATURE_EVENT_ON_CORPSE_REMOVED",               26,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   27,   function(...) print("CREATURE_EVENT_ON_MOVE_IN_LOS",                  27,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   28,   function(...) print("CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS",          28,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   29,   function(...) print("CREATURE_EVENT_ON_PASSANGER_BOARDED",            29,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   30,   function(...) print("CREATURE_EVENT_ON_DUMMY_EFFECT",                 30,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   31,   function(...) print("CREATURE_EVENT_ON_QUEST_ACCEPT",                 31,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   32,   function(...) print("CREATURE_EVENT_ON_QUEST_SELECT",                 32,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   33,   function(...) print("CREATURE_EVENT_ON_QUEST_COMPLETE",               33,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   34,   function(...) print("CREATURE_EVENT_ON_QUEST_REWARD",                 34,   ...) end )
RegisterCreatureEvent(CREA_ENTRY,   35,   function(...) print("CREATURE_EVENT_ON_DIALOG_STATUS",                35,   ...) end )
end
