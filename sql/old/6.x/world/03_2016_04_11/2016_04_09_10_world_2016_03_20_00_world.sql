--
UPDATE `creature_template` SET `InhabitType`=4 WHERE `Entry` IN (33377, 33779);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=33377;
DELETE FROM `creature` WHERE `id`=33167;
DELETE FROM `creature` WHERE `guid` IN (136266,136265);
UPDATE `creature` SET `position_x`=-733.608, `position_y`=-131.445, `position_z`=429.842, `orientation`= 4.15265 WHERE `guid`=136271;

SET @ENTRY1 := -136528;
SET @ENTRY2 := -136525;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@ENTRY1, @ENTRY2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY1,0,0,0,1,0,100,0,2000,2000,0,0,11,48310,0,0,0,0,0,10,137508,33779,0,0,0,0,0,'Kirin Tor Battle-Mage - OOC - cast Transitus Shield Beam'),
(@ENTRY2,0,0,0,1,0,100,0,2000,2000,0,0,11,48310,0,0,0,0,0,10,137507,33779,0,0,0,0,0,'Kirin Tor Battle-Mage - OOC - cast Transitus Shield Beam');
