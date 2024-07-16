-- Unlink unrelated box gamobject
DELETE FROM `game_event_gameobject` WHERE `guid`=43692 AND `eventEntry`=8;
-- Delete unrelated box gameobject
DELETE FROM `gameobject` WHERE `id`=181015 AND `guid`=43692;
DELETE FROM `gameobject_addon` WHERE `guid`=43692;
