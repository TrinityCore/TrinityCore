-- Spawn of Bael'Gar https://www.wowhead.com/npc=9436/spawn-of-baelgar#comments
UPDATE `creature_template` SET `dmgschool` = 2 WHERE `entry` = 9436;

-- Bael'Gar SAI (Source: 60NofGfarBE & d9lG5gYSA9c & 54vt4almLOg)
SET @ID := 9016;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,4,2,0,100,1,0,80,0,0,11,13895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'Gar - Between 0-80% Health - Cast 'Summon Spawn of Bael'Gar' (No Repeat)"),
(@ID,0,1,4,2,0,100,1,0,60,0,0,11,13895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'Gar - Between 0-60% Health - Cast 'Summon Spawn of Bael'Gar' (No Repeat)"),
(@ID,0,2,4,2,0,100,1,0,40,0,0,11,13895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'Gar - Between 0-40% Health - Cast 'Summon Spawn of Bael'Gar' (No Repeat)"),
(@ID,0,3,4,2,0,100,1,0,20,0,0,11,13895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'Gar - Between 0-20% Health - Cast 'Summon Spawn of Bael'Gar' (No Repeat)"),
(@ID,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'Gar - On Link - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s begins to summon a lava spawn!",16,0,100,0,0,0,5283,0,"Bael'Gar");

UPDATE `creature_template_addon` SET `auras` = "13879" WHERE `entry` = 9016; -- Magma Splash
DELETE FROM `creature_addon` WHERE `guid` = 45885;
