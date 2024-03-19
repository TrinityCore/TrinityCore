-- Can Swim
UPDATE `creature_template_difficulty` SET `StaticFlags1`= `StaticFlags1` | 0x10000000 WHERE `Entry` IN (40219, 41017, 40309, 40223, 39913, 41002, 41997, 41998);
-- Amphibious
UPDATE `creature_template_difficulty` SET `StaticFlags1`= `StaticFlags1` | 0x00080000 WHERE `Entry` IN (40276, 39918, 40987);
-- Cannot Swim
UPDATE `creature_template_difficulty` SET `StaticFlags3`= `StaticFlags3` | 0x00000100 WHERE `Entry`= 40987;

-- Add some wander distance to creatures
UPDATE `creature` SET `wander_distance`= 5, `MovementType`= 1 WHERE `guid` IN (349183, 349406, 349410, 349412, 349413, 349420, 349421, 349427, 349428, 349430, 349431, 349437, 349438, 349448, 349456, 349461, 349514, 349520, 349521, 349535, 349537, 349538, 349562, 349565, 349602, 349609, 349611, 349659, 349660, 349664, 349674, 349676, 349689, 349704, 349721, 349732, 349733, 349745, 349750, 349751, 349768, 349771);
