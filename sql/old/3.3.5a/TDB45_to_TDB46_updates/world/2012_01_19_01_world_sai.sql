-- [Q] Mounting Hodir's Helm
-- Hodir's Helm KC Bunny SAI
SET @ENTRY := 30210;
SET @SPELL_READ_PRONOUNCEMENT := 56278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_READ_PRONOUNCEMENT,0,0,0,33,@ENTRY,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hodir's Helm KC Bunny - On Spellhit - Quest Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hodir's Helm KC Bunny - On Spellhit - Say Line 0"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,50,192080,30000,0,0,0,0,8,0,0,0,7390.143066,-2725.382080,874.256104,2.973291,"Hodir's Helm KC Bunny - On Spellhit - Summon Hodir's Helm");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Sons of Hodir! I humbly present to you... The Helm of Hodir!",42,0,100,0,0,0,"Hodir's Helm KC Bunny");
-- Update from sniff
UPDATE `gameobject_template` SET `flags`=`flags`|36 WHERE `entry`=192080;
-- Conditions for Read Pronouncement
DELETE FROM `conditions` WHERE `SourceEntry`=@SPELL_READ_PRONOUNCEMENT AND `ConditionValue2`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,0,@SPELL_READ_PRONOUNCEMENT,18,1,@ENTRY,"Read Pronouncement targets Hodir's Helm KC Bunny");
-- Spawn a helm bunny
SET @GUID := 40266; -- gap
DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,@ENTRY,571,1,1,0,0,7390.14,-2725.38,874.256,2.90103,300,0,0,42,0,0,0,0,0);
