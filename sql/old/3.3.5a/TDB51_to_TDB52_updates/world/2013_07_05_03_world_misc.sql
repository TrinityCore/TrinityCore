-- Into the Pit (thx to KirkHammett)
SET @ENTRY         := 30174;
SET @SPELL_SMASH   := 54458;
SET @SPELL_DSHOUT  := 54459;
SET @SPELL_CHARGE  := 54460;

UPDATE `creature_template` SET `AIName`='SmartAI', `faction_A`=2128, `faction_H`=2128 WHERE  `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,0,0,2,31,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hyldsmeet Warbear - OOC - Set Faction'),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,7000,12000,11,@SPELL_SMASH,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hyldsmeet Warbear - In Combat - Cast Smash'),
(@ENTRY,0,2,0,0,0,100,0,1000,35000,70000,95000,11,@SPELL_DSHOUT,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hyldsmeet Warbear - In Combat - Cast Demoralizing Shout'),
(@ENTRY,0,3,0,0,0,100,0,5000,9000,11000,17000,11,@SPELL_CHARGE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hyldsmeet Warbear - In Combat - Cast Charge');

-- Some errors startup errors
UPDATE `creature_equip_template` SET `itemEntry1`=12883 WHERE `entry`=29927 AND `id`=1;

UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=37416;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37346;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37364;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37269;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37369;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37268;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37335;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=37483;
UPDATE `creature_template` SET `npcflag`=4194306 WHERE `entry`=37310;
UPDATE `creature_template` SET `npcflag`=4194306 WHERE `entry`=37426;
