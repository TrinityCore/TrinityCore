-- Creature Krennan Aranas 36132 SAI
SET @ENTRY := 36132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 14313, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest 14313 - Self: Target_0 = Action invoker // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 10, 255442, 0, 0, 0, 0, 0, 0, " Linked - Self: Send stored target 0 to Creature Gwen Armstead 34571 (255442) // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 255442, 0, 0, 0, 0, 0, 0, " Linked - Creature Gwen Armstead 34571 (255442): Set creature data #0 to 0 // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@ENTRY, 0, 4, 0, 59, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Talk 0 // ");

-- Creature Gwen Armstead 34571 SAI
SET @ENTRY := 34571;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On data 0 set to 0 - storedTarget[0]: Talk 0 // ");

DELETE FROM `creature_text` WHERE `CreatureID` IN (34571, 36132, 36453);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(34571, 0, 0, 'Welcome back, $n.  You were fortunate.  Krennan\'s treatment doesn\'t always work this well on people who\'ve had the Curse as long as you.', 12, 0, 100, 1, 0, 0, 36618, 'Gwen Armstead to Player'),
(36132, 0, 0, 'Do exercise caution.  Don\'t expect anyone to invite you to their homes just yet.  But at least they won\'t shoot you outright.', 12, 0, 100, 1, 0, 0, 36617, 'Krennan Aranas to Player'),
(36453, 0, 0, 'By the Light!  This must be the end of the world!', 12, 0, 100, 5, 0, 0, 36585, 'Duskhaven Villager');

DELETE FROM `world_map_template` WHERE `mapID` = 654;
INSERT INTO `world_map_template` (`mapID`, `ScriptName`) VALUES
(654, 'world_map_gilneas');

DELETE FROM `phase_area` WHERE `AreaId`= 4714 AND `PhaseId` IN (181, 182, 183);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 26 AND `SourceEntry`= 4714 AND `SourceGroup` IN (181, 182, 183);

DELETE FROM `spell_area` WHERE `spell` IN (68481, 68482, 68483) AND `area`= 4714;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(68481, 4714, 14375, 14321, 0, 0, 2, 1, 64, 1 | 2 | 8 | 32), -- Phase - Quest Zone-Specific 06 - after finishing 14375 (Last Chance at Humanity)
(68482, 4714, 14375, 14386, 0, 0, 2, 1, 64, 1 | 2 | 8 | 32), -- Phase - Quest Zone-Specific 07 - after finishing 14321 (Invasion)
(68483, 4714, 14386, 14466, 0, 0, 2, 1, 64, 1 | 2 | 8 | 32); -- Phase - Quest Zone-Specific 08 - after finishing 14386 (Leader of the Pack)

DELETE FROM `creature` WHERE `guid` IN (255464, 255758, 255951, 255762, 255494, 255501);
DELETE FROM `creature_addon` WHERE `guid` IN (255464, 255758, 255951, 255762, 255494, 255501);

UPDATE `creature` SET `spawntimesecs`= 2 WHERE `guid`= 255483;
-- Creature Duskhaven Villager 36453 SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`= -255464 AND `source_type`= 0;
SET @ENTRY := -255483;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2554640, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Start path #2554640, walk, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 5, 2554640, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 5 of path 2554640 reached - Self: Despawn instantly // ");
