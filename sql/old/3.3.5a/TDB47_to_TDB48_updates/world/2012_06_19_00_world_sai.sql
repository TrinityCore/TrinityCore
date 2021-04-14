-- Fix Quest 13231 The Broken Front and 13232 Finish Me!
-- Dying Soldier SAI
SET @ENTRY  := 31304;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,10040,0,0,0,11,58955,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Cast Alliance Quest Aura on player'),
(@ENTRY,0,1,2,62,0,100,0,10040,3,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Set npcflag'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Close Gossip'),
(@ENTRY,0,3,4,62,0,100,0,10040,1,0,0,85,59226,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Player cast Finish It on npc'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Close Gossip'),
(@ENTRY,0,6,7,8,0,100,0,59226,0,0,0,11,3240,2,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Spellhit - Cast Bloody Explosion on self'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,33,31312,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Give Kill credit to player'),
(@ENTRY,0,8,9,25,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Spawn - Set npcflag'),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Spawn - Set react state'),
(@ENTRY,0,10,0,19,0,100,0,13232,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Quest accept - Set npcflag');
-- Creature updates
UPDATE `creature_template` SET `npcflag`=3,`RegenHealth`=0 WHERE `entry`=31304;
UPDATE `creature` SET `npcflag`=0 WHERE `guid`=122230;
UPDATE `creature` SET `curhealth`=37 WHERE `id`=31304;

-- Start Fixing Quest 13228 The Broken Front and 13230 No Mercy!
-- Creature updates
UPDATE `creature_template` SET `npcflag`=3,`RegenHealth`=0 WHERE `entry`=31273;
UPDATE `creature` SET `curhealth`=37 WHERE `id`=31273;
