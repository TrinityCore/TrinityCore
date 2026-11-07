-- Unlink unrelated MFF gamobject
DELETE FROM `game_event_gameobject` WHERE `guid`=17176 AND `eventEntry`=1;
-- Delete unrelated MFF gameobject
DELETE FROM `gameobject` WHERE `id`=181300 AND `guid`=17176;
DELETE FROM `gameobject_addon` WHERE `guid`=17176;
