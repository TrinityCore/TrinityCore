-- [Q] The Flesh Lies... 
-- Withered Corpse SAI
SET @ENTRY := 20561;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,35372,0,0,0,33,20561,0,0,0,0,0,7,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit 'Protectorate Igniter' - Quest Credit 'The Flesh Lies...''"),
(@ENTRY,0,1,2,61,0,100,0,35372,0,0,0,50,184445,60,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit 'Protectorate Igniter' - Summon Gameobject 'Charred Remains'"),
(@ENTRY,0,2,0,61,0,100,0,35372,0,0,0,51,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit 'Protectorate Igniter' - Kill Target"),
(@ENTRY,0,3,4,10,0,100,1,0,4,0,0,12,20335,3,120000,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - Within 0-4 Range Out of Combat LoS - Summon Creature 'Parasitic Fleshbeast'"),
(@ENTRY,0,4,5,61,0,100,0,0,4,0,0,11,35309,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - Within 0-4 Range Out of Combat LoS - Cast 'Bloody Explosion'"),
(@ENTRY,0,5,0,61,0,100,0,0,4,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - Within 0-4 Range Out of Combat LoS - Despawn In 1000 ms");

DELETE FROM `creature_template_addon` WHERE `entry`=20561;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(20561, 0, 0, 3, 1, 0, '29266');
