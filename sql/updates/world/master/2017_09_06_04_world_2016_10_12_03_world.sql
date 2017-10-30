--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43092;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 43092, 0, 0, 31, 0, 3, 24119, 0, 0, 0, 0, "", "Spell 'Stop the Ascension!: Halfdan's Soul Destruction' targets Halfdan's Soul");

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=17 AND SourceEntry=43089;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17, 0, 43089, 0, 0, 29, 0, 23671, 90, 0, 1, 0, 0, "", "Spell 'Vrykul Scroll of Ascension' requires NPC Halfdan the Ice-Hearted to not be nearby AND"),
(17, 0, 43089, 0, 0, 29, 0, 24119, 90, 0, 1, 0, 0, "", "Spell 'Vrykul Scroll of Ascension' requires NPC Halfdan's Soul to not be nearby");

UPDATE `creature_template` SET `HoverHeight`=4, `AIName`="SmartAI" WHERE `entry`=24118;
DELETE FROM `creature_template_addon` WHERE `entry` IN (24118, 24119);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `auras`) VALUES
(24118, 33554432, ""),
(24119, 33554432, "37119 36545");

UPDATE `creature_template` SET `unit_flags`=33587456, `dynamicflags`=32, `inhabittype`=4, `speed_walk`=0.6 WHERE `entry`=24119;

SET @CGUID := 42887;
DELETE FROM `creature` WHERE `guid` IN (@CGUID, @CGUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID  , 24118, 571, 0, 0, 1, 170, 0, 0, 1676.912, -4108.803, 278.9944, 0.1675403, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+1, 24118, 571, 0, 0, 1, 170, 0, 0, 1679.509, -4122.266, 279.408, 2.729512, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+1), 2411800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+1), 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 2411800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Data 1 1 Set - Call Actionlist"),
(2411800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Script - Talk 0"),
(2411800, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Script - Talk 1"),
(2411800, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 43092, 2, 0, 0, 0, 0, 19, 24119, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Script - Cast 'Stop the Ascension!: Halfdan's Soul Destruction'"),
(2411800, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 24119, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Script - Despawn Halfdan's Soul"),
(2411800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 23671, 0, 1, 0, 0, 0, 0, "Val'kyr Observer - On Script - Despawn Halfdan the Ice-Hearted"),
(2411800, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 44, 2, 0, 0, 0, 0, 0, 9, 24118, 0, 90, 0, 0, 0, 0, "Val'kyr Observer - On Script - Set Phasemask 2 to nearby Val'kyr Observer"),
(2411800, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 44, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Script - Set Phasemask 2 to Self"),
(2411800, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 92, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Val'kyr Observer - On Script - Interrupt Current Cast");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24119;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24119;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24119, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan's Soul - On Spawn - Set Run Off"),
(24119, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, "Halfdan's Soul - On Spawn - Move to position");

UPDATE `event_scripts` SET `x`=1668.817, `y`=-4117.592, `z`=273.4088, `o`=0.2443461 WHERE `id`=15672;
DELETE FROM `smart_scripts` WHERE entryorguid=23671;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23671, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 44, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Set Phasemask 3"),
(23671, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Talk 0"),
(23671, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 9, 24118, 0, 90, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Change Phasemask of Val'kyr Observer"),
(23671, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Set Unitflag IMMUNE_TO_PC"),
(23671, 0, 4, 0, 52, 0, 100, 0, 0, 23671, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Text 0 Over - Talk 1"),
(23671, 0, 5, 6, 52, 0, 100, 0, 1, 23671, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Text 1 Over - Remove Unitflag IMMUNE_TO_PC"),
(23671, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Text 1 Over - Attack Invoker"),
(23671, 0, 7, 8, 2, 0, 100, 1, 0, 50, 0, 0, 1, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Between 0% and 50% Health - Talk 2 (No Repeat)"),
(23671, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Between 50% and 75% Health - Cast 'Enrage' (No Repeat)"),
(23671, 0, 9, 10, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 24118, 0, 90, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Death - Set Data 1 1 to Val'kyr Observer"),
(23671, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43091, 2, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Death - Cast 'Stop the Ascension!: Summon Halfdan's Soul'"),
(23671, 0, 11, 0, 0, 0, 100, 0, 2000, 5000, 9500, 11500, 11, 35263, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Frost Attack'"),
(23671, 0, 12, 0, 0, 0, 100, 0, 2500, 5000, 6000, 10000, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Mortal Strike'"),
(23671, 0, 13, 0, 0, 0, 100, 0, 1250, 5000, 5000, 6000, 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Shield Block'"),
(23671, 0, 14, 0, 0, 0, 100, 0, 3000, 8000, 4000, 12000, 11, 32015, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Knockdown'"),
(23671, 0, 15, 0, 9, 0, 100, 0, 8, 25, 5000, 5000, 11, 19131, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Within 8-25 Range - Cast 'Shield Charge'");

DELETE FROM `creature_text` WHERE `entry`=23671;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23671, 0, 0, "You think I do not know what you are trying to do? You think I haven't been watching you?", 14, 0, 100, 1, 0, 0, 22787, 0, "Halfdan the Ice-Hearted"),
(23671, 1, 0, "You will not stop my ascension, tiny $r. Time to die!", 14, 0, 100, 1, 0, 0, 22788, 0, "Halfdan the Ice-Hearted"),
(23671, 2, 0, "No! You will not defeat me!", 14, 0, 100, 0, 0, 0, 22789, 0, "Halfdan the Ice-Hearted");

DELETE FROM `creature_text` WHERE `entry`=24118;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24118, 0, 0, "How unfortunate, Halfdan.", 12, 0, 100, 0, 0, 0, 22791, 0, "Val'kyr Observer"),
(24118, 1, 0, "We find you unworthy of ascension, Halfdan. Let your soul know oblivion!", 12, 0, 100, 0, 0, 0, 22792, 0, "Val'kyr Observer");
