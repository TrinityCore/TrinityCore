-- Gug Fatcandle SAI
SET @ENTRY := 62;
UPDATE `creature_template` SET `mingold`=2, `maxgold`=7, `lootid`=62,`ExperienceModifier`=7.5, `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,10000,10000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gug Fatcandle - OOC - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3600,4000,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gug Fatcandle - In Combat CMC - Cast 'Fireball'");

UPDATE `creature` SET `spawntimesecs`=1800 WHERE `guid`=279748;
UPDATE `creature_template` SET `mingold`=1, `maxgold`=4, `lootid`=62,`ExperienceModifier`=7.5 WHERE `entry`=62;
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=62;

DELETE FROM `creature_loot_template` WHERE `Entry`=62;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(62,56147,0,100,0,1,0,1,1, 'Fatcandle Bag'),
(62,117,0,20,0,1,1,1,1, 'Tough Jerky'),
(62,159,0,20,0,1,2,1,1, 'Refreshing Spring Water');
