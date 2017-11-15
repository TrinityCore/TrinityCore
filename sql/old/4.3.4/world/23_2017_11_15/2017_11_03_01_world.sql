-- Remove the flag carrier spell cast since some guards should not have this aura
DELETE FROM `smart_scripts` WHERE `entryorguid`= 42218 AND `action_param1`= 78855;

-- Reduce the spawndist of multiple critter npc's to avoid having them walking inside buildings when pathfinding is enabled
UPDATE `creature` SET `spawndist`= 3 WHERE `guid` IN (279925, 279890, 279892, 279976, 280117);

-- Stormwind Infantry and Borhter Paxton Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (49869, 951);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(49869, 0, 0, 'I could use a heal, brother!', 12, 0, 100, 0, 0, 0, 49895, 'Stormwind Infantry'),
(49869, 0, 1, 'I need a heal!', 12, 0, 100, 0, 0, 0, 49898, 'Stormwind Infantry'),
(49869, 0, 2, 'Make yourself useful and heal me, Paxton!', 12, 0, 100, 0, 0, 0, 49896, 'Stormwind Infantry'),
(49869, 0, 3, 'HELP!', 12, 0, 100, 0, 0, 0, 49897, 'Stormwind Infantry'),
(951, 0, 0, 'Be healed, $g brother:sister;!', 12, 0, 100, 0, 0, 0, 49889, 'Brother Paxton'),
(951, 0, 1, 'AND I LAY MY HANDS UPON YOU!', 12, 0, 100, 0, 0, 0, 49890, 'Brother Paxton'),
(951, 0, 2, 'Let the Holy Light embrace you!', 12, 0, 100, 0, 0, 0, 49891, 'Brother Paxton'),
(951, 0, 3, 'BY THE LIGHT BE RENEWED!', 12, 0, 100, 0, 0, 0, 49892, 'Brother Paxton'),
(951, 0, 4, 'FIGHT ON, $G BROTHER:SISTER;!', 12, 0, 100, 0, 0, 0, 49893, 'Brother Paxton');

-- Set spawndist for several creatures
UPDATE `creature` SET `spawndist`= 10 WHERE `id` IN (49871, 50039, 42937);
UPDATE `creature` SET `MovementType`= 1 WHERE `id` IN (49871, 50039, 42937);
