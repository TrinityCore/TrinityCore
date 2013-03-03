local GO_ENTRIES =
{
    68,
}

for _, GO_ENTRY in ipairs(GO_ENTRIES) do
--RegisterGameObjectEvent(GO_ENTRY, 1,  function(...) print("GAMEOBJECT_EVENT_ON_AIUPDATE",            1,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 2,  function(...) print("GAMEOBJECT_EVENT_ON_RESET",               2,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 3,  function(...) print("GAMEOBJECT_EVENT_ON_DUMMY_EFFECT",        3,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 4,  function(...) print("GAMEOBJECT_EVENT_ON_QUEST_ACCEPT",        4,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 5,  function(...) print("GAMEOBJECT_EVENT_ON_QUEST_REWARD",        5,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 6,  function(...) print("GAMEOBJECT_EVENT_ON_DIALOG_STATUS",       6,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 7,  function(...) print("GAMEOBJECT_EVENT_ON_DESTROYED",           7,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 8,  function(...) print("GAMEOBJECT_EVENT_ON_DAMAGED",             8,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 9,  function(...) print("GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE",   9,  ...) end )
RegisterGameObjectEvent(GO_ENTRY, 10, function(...) print("GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED",    10, ...) end )
end
