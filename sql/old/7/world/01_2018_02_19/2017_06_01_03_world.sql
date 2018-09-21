-- Condition for source quest make available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=26391;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26391, 0, 1, 8, 0, 28817, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 2, 8, 0, 28818, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 3, 8, 0, 28819, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 4, 8, 0, 28819, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 5, 8, 0, 28820, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 6, 8, 0, 28821, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 7, 8, 0, 28822, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 8, 8, 0, 28823, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 9, 8, 0, 29083, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.'),
(19, 0, 26391, 0, 10, 8, 0, 31145, 0, 0, 0, 0, 0, '', 'Make quest available on questgiver for quest Extinguishing Hope if quest The Rear is Clear has been rewarded.');

-- Add Fire Extinguisher spell for quest Extinguishing Hope
DELETE FROM `spell_area` WHERE `spell` IN (80209);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80209,9,26391,0,0,1101,2,1,10,0),(80209,59,26391,0,0,1101,2,1,10,0);

UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry`=42937;
DELETE FROM `creature_loot_template` WHERE `Entry`=42937;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(42937,58361,0,100,1,1,0,1,1, 'Blackrock Orc Weapon'),
(42937,1,11111,0.1,0,1,1,1,1, 'Reference Small Pouch');

UPDATE `creature_template` SET `lootid`=49874 WHERE `entry`=49874;
DELETE FROM `creature_loot_template` WHERE `Entry`=49874;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(49874,1,11111,0.1,0,1,1,1,1, 'Reference Small Pouch');

 UPDATE `creature_template` SET  `mingold`=1, `maxgold`=5, `lootid`=42938 WHERE `entry`=42938;
DELETE FROM `creature_loot_template` WHERE `Entry`=42938;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(42938,1,11111,0.1,0,1,1,1,1, 'Reference Small Pouch');

UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid`=279837;

-- Blackrock Spy SAI
UPDATE `smart_scripts` SET `event_chance`=25, `action_param3`=1, `target_type`=2 WHERE `entryorguid`=49874;

-- Blackrock Spy Text
SET @ENTRY := 49874;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Orc KILL $r!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Spy'),
(@ENTRY, 0, 1, 'Blackrock take forest!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Spy'),
(@ENTRY, 0, 2, 'The grapes were VERY TASTY!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Spy'),
(@ENTRY, 0, 3, 'Eat you!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Spy');

-- Blackrock Invader SAI
SET @ENTRY := 42937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,1,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Invader - On Aggro - Say Line 0 (No Repeat)");

-- Blackrock Invader Text
SET @ENTRY := 42937;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Orc KILL $r!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Invader'),
(@ENTRY, 0, 1, 'Blackrock take forest!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Invader'),
(@ENTRY, 0, 2, 'The grapes were VERY TASTY!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Invader'),
(@ENTRY, 0, 3, 'Eat you!', 12, 0, 100, 0, 0, 0, 0, 'Blackrock Invader');

-- Blackrock Invader Equipment
DELETE FROM `creature_equip_template` WHERE `CreatureID`=42937;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(42937, 1, 10898, 12456, 0),
(42937, 2, 17383, 0, 0),
(42937, 3, 14877, 0, 0),
(42937, 4, 18062, 0, 0);

UPDATE `creature` SET `equipment_id`=-1 WHERE `id`=42937;
