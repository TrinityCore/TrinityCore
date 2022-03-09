-- Stalvan Mistmantle entry=20355 guid=83697 add sleep state
DELETE FROM `creature` where guid=83697 and id=20355;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (83697, 20355, 560, 0, 0, 3, 1, 0, 0, 1805.070312, 1042.846069, 19.421974, 4.69566, 300, 0, 0, 498, 544, 0, 0, 0, 0, '', 0);
DELETE FROM `creature_addon` where guid=83697;
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES (83697, 0, 0, 0, 3, 4097, 0, 0, 55474);

-- Zixil entry=20419 guid=83677 add emote and creature_text
DELETE FROM `creature_addon` where guid=83677;
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES (83677, 0, 0, 0, 0, 0, 173, 0, NULL);
DELETE FROM `creature_text` where CreatureID=20419;
INSERT INTO `creature_text`(`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (20419, 0, 0, "Just a few more swings and it'll be ready...", 12, 0, 100, 173, 0, 0, 18133, 0, 'Zixil'),(20419, 1, 0, "Maybe I can sell these things to other goblins? I'll be rich! Rich I say!", 12, 0, 100, 173, 0, 0, 18134, 0, 'Zixil');

-- Kirin Tor Mage entry=20422 guid=83700,83701,83702,83703 add emote state
DELETE FROM `creature_addon` where guid in (83700,83701,83702,83703);
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES (83700, 0, 0, 0, 0, 0, 69, 0, NULL),(83701, 0, 0, 0, 0, 0, 69, 0, NULL),(83702, 0, 0, 0, 0, 0, 69, 0, NULL),(83703, 0, 0, 0, 0, 0, 69, 0, NULL);
