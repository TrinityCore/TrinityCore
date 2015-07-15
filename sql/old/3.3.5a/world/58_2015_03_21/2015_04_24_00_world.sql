-- Manual Spawn Randy Whizzlesprocket
SET @GUID := 49056;
DELETE FROM `creature` WHERE `guid` = @GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID, 17288, 540, 0, 0, 2, 1, 0, 0, 131.106, 254.520, -45.236, 3.951, 7200, 0, 0, 6104, 0, 0, 0, 0, 0);

-- Missing 2xEmblem of Justice from quest 'Imprisoned in the citadel'
UPDATE `quest_template` SET `RewardItemId1` = 29434, `RewardItemCount1` = 2 WHERE `Id` IN (9524,9525);

-- Update Shattered Hand Executioner loot Table
UPDATE `creature_loot_template` SET `LootMode` = 8, `GroupId` = 1, `Chance` = 0 WHERE `Entry` = 20585;
DELETE FROM `creature_loot_template` WHERE `Entry` = 20585 AND `Item` IN (31716,29434,22829,22832,24726);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(20585, 31716,     0, 100, 1, 2|4|8, 0, 1, 1, NULL), -- Unused Axe
(20585, 29434,     0, 100, 0,     8, 0, 1, 1, NULL), -- 1x Emblem of Justice (3 Prisoners Rescued)
(20585, 22829,     0,   0, 0, 2|4|8, 2, 2, 8, NULL), -- Greater Potions
(20585, 22832,     0,   0, 0, 2|4|8, 2, 2, 8, NULL),
(20585, 24726, 24726, 100, 0,   4|8, 0, 1, 1, NULL); -- Scroll of XXXX VI

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17301 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '', ScriptName = 'boss_shattered_executioner', `flags_extra` = 0 WHERE `entry` = 17301;
UPDATE `creature_template` SET `unit_flags` = 33088 WHERE `entry` IN (17301,20585);
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` IN (19523,19524,20572,20573);
UPDATE `creature_template` SET `flags_extra` = 0 WHERE `entry` = 20585;

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4524;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4524, 'at_nethekurse_exit');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (39288,39289,39290);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39288, 'spell_kargath_executioner'),
(39289, 'spell_kargath_executioner'),
(39290, 'spell_kargath_executioner');

UPDATE `gameobject_template` SET `flags` = 34 WHERE `entry` IN (182539,182540); -- Sniffed value
-- Missing texts
SET @KARGATH := 16808;
SET @BROADCAST := 13721;
DELETE FROM `creature_text` WHERE `entry` = @KARGATH AND `groupid` IN (3,4);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@KARGATH, 3, 0, 'The Alliance dares to intrude this far into my fortress?  Bring out the Honor Hold prisoners and call for the executioner!  They''ll pay with their lives for this trespass!', 14, 0, 100, 0, 0, 0, @BROADCAST+0, 3, 'kargath SAY_CALL_EXECUTIONER_A'),
(@KARGATH, 4, 0, 'Thrall''s false Horde dares to intrude this far into my fortress?  Bring out the Thrallmar prisoners and call for the executioner!  They''ll pay with their lives for this trespass!', 14, 0, 100, 0, 0, 0, @BROADCAST+1, 3, 'kargath SAY_CALL_EXECUTIONER_H');
