-- Ogron
DELETE FROM `smart_scripts` WHERE `entryorguid`=4983 AND `source_type`=0 AND `id`=8;
DELETE FROM `smart_scripts` WHERE `entryorguid`=498300 AND `source_type`=9 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=498302 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4983,0,8,0,38,0,100,0,2,2,0,0,80,498302,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogron - On Data Set 2 2 - Run Script"),
(498300,9,2,0,0,0,100,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogron - On Script - Remove Unit Flag 'Immune to NPC'"),
(498302,9,0,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogron - On Script - Say Line 6"),
(498302,9,1,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogron - On Script - Say Line 7"),
(498302,9,2,0,0,0,100,0,5000,5000,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogron - On Script - Add Unit Flag 'Immune to NPC'"),
(498302,9,3,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-3317.64,-3125.36,33.0284,0,"Ogron - On Script - Move to Position");

DELETE FROM `creature_text` WHERE `CreatureID`=4983 AND `GroupID`=8; -- Ogron shouldn't have ogres' common aggro texts

-- Paval Reethe
DELETE FROM `smart_scripts` WHERE `entryorguid`=4980 AND `source_type`=0 AND `id` IN (1,2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=498000 AND `source_type`=9 AND `id` IN (8,9,10);
DELETE FROM `smart_scripts` WHERE `entryorguid`=498001 AND `source_type`=9 AND `id` IN (3,4,5,6,7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4980,0,1,0,75,0,100,1,0,4983,10,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.77747,"Paval Reethe - On 'Ogron' in Range - Set Orientation"),
(4980,0,2,0,75,0,100,1,0,4983,10,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Paval Reethe - On 'Ogron' in Range - Set Emote State 333"),
(4980,0,3,0,8,0,100,0,7105,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Paval Reethe - On Spellhit 'Fake Shot' - Set Flag Standstate Kneel"),
(498000,9,8,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,11,5045,30,0,0,0,0,0,"Paval Reethe - On Script - Set Data 3 3"),
(498000,9,9,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,11,5044,30,0,0,0,0,0,"Paval Reethe - On Script - Set Data 3 3"),
(498000,9,10,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,11,5046,30,0,0,0,0,0,"Paval Reethe - On Script - Set Data 3 3"),
(498001,9,3,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,19,4983,0,0,0,0,0,0,"Paval Reethe - On Script - Set Data 2 2"),
(498001,9,4,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Paval Reethe - On Script - Kill Self");

UPDATE `smart_scripts` SET `target_type`=1, `target_param1`=0, `target_param3`=0 WHERE `entryorguid`=498000 AND `source_type`=9 AND `id` IN (0,1);
UPDATE `smart_scripts` SET `action_type`=1 WHERE `entryorguid`=498001 AND `source_type`=9 AND `id` IN (1,5,6);

UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=4980 AND `GroupID` IN (1,2,4);
UPDATE `creature_text` SET `Emote`=25 WHERE `CreatureID`=4980 AND `GroupID`=3;
UPDATE `creature_text` SET `Emote`=6 WHERE `CreatureID`=4980 AND `GroupID`=5;
UPDATE `creature_text` SET `Emote`=0 WHERE `CreatureID`=4980 AND `GroupID`=7;

-- Lieutenant Caldwell
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=504600 AND `source_type`=9 AND `id` IN (1,2);

DELETE FROM `smart_scripts` WHERE `entryorguid`=5046 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5046,0,3,0,38,0,100,0,3,3,0,0,49,0,0,0,0,0,0,19,4983,0,0,0,0,0,0,"Lieutenant Caldwell - On Data Set - Start Attaking");

UPDATE `creature_text` SET `Emote`=5 WHERE `CreatureID`=5046 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=5046 AND `GroupID`=1;
UPDATE `creature_text` SET `Emote`=25 WHERE `CreatureID`=5046 AND `GroupID`=2;

-- Private Hallan
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=504500 AND `source_type`=9 AND `id`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=5045 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5045,0,3,0,38,0,100,0,3,3,0,0,49,0,0,0,0,0,0,19,4983,0,0,0,0,0,0,"Private Hallan - On Data Set - Start Attaking");

-- Theramore Skirmisher
DELETE FROM `smart_scripts` WHERE `entryorguid`=5044 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5044,0,2,0,38,0,100,0,3,3,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Theramore Skirmisher - On Data Set - Start Attaking");
