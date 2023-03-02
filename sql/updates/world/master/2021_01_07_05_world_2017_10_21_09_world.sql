-- Stillpine Hold overhaul
DELETE FROM `creature` WHERE `guid` IN (31934,36944,36956,36957,36958);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(31934, 17432, 530, 0, 0, '0', 0, 0, 1, -3359.00, -12295.73, 21.895, 3.4643, 300, 0, 0, 176, 0, 0, 0, 0, 0, 0),
(36944, 17432, 530, 0, 0, '0', 0, 0, 1, -3362.50, -12403.92, 24.512, 2.2446, 300, 0, 0, 176, 0, 0, 0, 0, 0, 0),
(36956, 17432, 530, 0, 0, '0', 0, 0, 1, -3380.84, -12411.39, 19.330, 2.4017, 300, 0, 0, 176, 0, 0, 0, 0, 0, 0),
(36957, 17437, 530, 0, 0, '0', 0, 0, 1, -3339.58, -12352.24, 22.844, 5.8677, 300, 0, 0, 176, 0, 0, 0, 0, 0, 0),
(36958, 17438, 530, 0, 0, '0', 0, 0, 0, -3336.31, -12352.47, 23.182, 3.6591, 300, 0, 0, 176, 0, 0, 0, 0, 0, 0);

-- Update NPC movement, delete wrong models and ranged weapons, correct angle/distance of formation
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (62912, 62911, 62913, 62914, 62878, 62877, 62895, 62893, 62894, 62875, 62874, 62885);
UPDATE `creature_formations` SET `dist`=5, `angle`=270 WHERE `memberGUID`=62891;
-- UPDATE `creature_template` SET `modelid2`=6802, `modelid3`=0, `modelid4`=0 WHERE `entry` IN (17432, 17439, 17437);
UPDATE `creature_addon` SET `bytes2`=4097 WHERE `guid`=62892;
UPDATE `creature_equip_template` SET `ItemID3`=0 WHERE `CreatureID` IN (17432, 17443, 17446, 17445, 17444, 17440, 17442, 17441) AND `ID`=1;

-- Delete four NPCs and all Stillpine Raiders
DELETE FROM `creature` WHERE `guid` IN (62884, 62883, 60792, 60777);
DELETE FROM `creature` WHERE `id`=17495;
