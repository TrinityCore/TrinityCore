DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_darkmoon_deathmatch',
'spell_darkmoon_island_deathmatch',
'spell_darkmoon_island_ring_toss');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(108941, 'spell_darkmoon_deathmatch'),
(101695, 'spell_darkmoon_island_ring_toss');

DELETE FROM `gameobject_template` WHERE `entry`= 209292;
INSERT INTO `gameobject_template` (`entry`,`type`, `displayId`, `name`, `size`, `Data0`, `Data1`, `Data3`, `Data6`, `VerifiedBuild`) VALUES
(209292, 8, 2770, '[DND] Spell Focus', 1, 1729, 1, 1, -1, -18019);

DELETE FROM `gameobject` WHERE `guid`= 200888;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(200888, 209292, 974, 5861, 5870, 169, -4289.51, 6309.706, 13.117, 4.302);

DELETE FROM `conditions` WHERE `SourceEntry` IN (101807, 101699, 101695) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 101807, 0, 0, 31, 0, 3, 54490, 0, 0, 0, '', 'Ring Toss - Target Dubenko'),
(13, 2, 101699, 0, 0, 31, 0, 3, 54490, 0, 0, 0, '', 'Ring Toss - Target Dubenko'),
(13, 1, 101695, 0, 0, 31, 0, 3, 54490, 0, 0, 0, '', 'Ring Toss - Target Dubenko');

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 6 WHERE `guid`= 290641;

-- Creature Dubenko 54490 SAI
SET @ENTRY := 54490;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 101807, 0, 0, 0, 11, 101738, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ring Toss (101807) hit  - Self: Cast spell Ring Toss (101738) on Self // ");

UPDATE `gossip_menu_option` SET `OptionType`= 1, `OptionNpcFlag`= 1 WHERE `MenuID` IN (13012, 13018, 13019);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (13012, 13018, 13019) AND `OptionID`= 1;
UPDATE `gossip_menu_option` SET `ActionMenuID`= 13013 WHERE `MenuID`= 13012 AND `OptionID`= 0;

-- Creature Jessica Rogers 54485 SAI
SET @ENTRY := 54485;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 13012, 2, 0, 0, 98, 13064, 18348, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 2 from menu 13012 selected - Action invoker: Send gossip ID 13064 with text 18348 // "),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 13012, 2, 0, 0, 57, 71083, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 2 from menu 13012 selected - Action invoker: Remove item 1x0 // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 101808, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Ring Toss Gossip (101808) on Action invoker // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Action invoker: Close gossip // ");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=54485 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `NegativeCondition`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 2, 54485, 0, 0, 2, 0, 71083, 1, 0, 0, 0, "", "If Invoker has 1 of item 71083 in backpack"),
(22, 1, 54485, 0, 0, 2, 0, 71083, 0, 0, 0, 0, "", "If Invoker has 0 of item 71083 in backpack");
