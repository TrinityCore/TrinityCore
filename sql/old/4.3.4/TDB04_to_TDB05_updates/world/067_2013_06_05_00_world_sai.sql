-- The Art of Being a Water Terror (13091)
SET @NPC_WATER_TERROR           := 30645; -- Water Terror
SET @AURA_HEALTH                := 57664; -- The Art of Being a Water Terror: Mod Health Regen %
SET @JOT_WARRIOR                := 29880; -- Jotunheim Warrior
SET @SPEAR_SISTER               := 30243; -- Njorndar Spear-Sister
SET @VAL_VARGUL                 := 30250; -- Valhalas Vargul
SET @WATER_MAGUS                := 30632; -- Mjordin Water Magus
SET @SLEEP_WATCHER              := 30725; -- Jotunheim Sleep-Watcher

UPDATE `creature_template` SET `speed_walk`=4,`speed_run`=2.14285707473755,`AIName`='SmartAI',`exp`=2,`spell1`=57643,`spell2`=57652,`spell3`=57665,`spell4`=57668,`VehicleId`=250,`minlevel`=80,`maxlevel`=80,`faction_A`=116,`faction_H`=116,`unit_flags`=0x8008 WHERE `entry`=@NPC_WATER_TERROR;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_WATER_TERROR;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_WATER_TERROR,0,0x0,0x101,'');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_WATER_TERROR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_WATER_TERROR,0,0,1,54,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Just Summoned - Set State Passive - Self'),
(@NPC_WATER_TERROR,0,1,0,61,0,100,0,0,0,0,0,75,@AURA_HEALTH,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Just Summoned - Add Aura - Self');


DELETE FROM `smart_scripts` WHERE `entryorguid`  IN (@JOT_WARRIOR,@WATER_MAGUS,@SPEAR_SISTER);
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@JOT_WARRIOR,@WATER_MAGUS,@SPEAR_SISTER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@JOT_WARRIOR,0,0,0,0,0,100,0,0,0,30000,30000,11,23262,2,0,0,0,0,2,0,0,0,0,0,0,0,'Jotunheim Warrior - IC - Cast Demoralize'),
(@JOT_WARRIOR,0,1,0,0,0,100,0,2000,3000,5000,7000,11,43410,2,0,0,0,0,2,0,0,0,0,0,0,0,'Jotunheim Warrior - IC - Cast Chop'),
(@JOT_WARRIOR,0,2,0,6,0,100,0,0,0,0,0,33,30644,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jotunheim Warrior - On Death - Give Kill Credit credit'),
(@SPEAR_SISTER,0,0,0,0,0,100,0,2000,3000,3000,4000,11,38029,2,0,0,0,0,2,0,0,0,0,0,0,0,'Njorndar Spear-Sister - IC - Cast Stab'),
(@SPEAR_SISTER,0,1,0,6,0,100,0,0,0,0,0,33,30644,0,0,0,0,0,7,0,0,0,0,0,0,0,'Njorndar Spear-Sister - On Death - Give Kill Credit credit'),
(@WATER_MAGUS,0,0,0,11,0,100,0,0,0,0,0,11,7855,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mjordin Water Magus - On Spawn - Summon Water Terror (Self)'),
(@WATER_MAGUS,0,1,0,0,0,100,0,0,0,3000,4000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mjordin Water Magus - IC - Cast Frostbolt'),
(@WATER_MAGUS,0,2,0,0,0,100,0,3000,3000,7000,9000,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mjordin Water Magus - IC - Cast Frost Nova'),
(@WATER_MAGUS,0,3,0,6,0,100,0,0,0,0,0,33,30644,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mjordin Water Magus - On Death - Give Kill Credit credit');
-- Valhalas Vargul
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@VAL_VARGUL;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@VAL_VARGUL;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@VAL_VARGUL,0,0,0,9,0,100,0,0,5,3000,5000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Valhalas Vargul - IC - Cast Cleave'),
(@VAL_VARGUL,0,1,0,6,0,100,0,0,0,0,0,33,30644,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valhalas Vargul - On Death - Give Kill Credit credit');

-- Jotunheim Sleep-Watcher 
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@SLEEP_WATCHER;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@SLEEP_WATCHER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@SLEEP_WATCHER,0,0,0,9,0,100,0,0,5,15000,25000,11,60870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jotunheim Sleep-Watcher - IC - Cast Bludgeoning Strike'),
(@SLEEP_WATCHER,0,1,0,9,0,100,0,0,5000,30000,45000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jotunheim Sleep-Watcher - IC - Cast Demoralizing Shout'),
(@SLEEP_WATCHER,0,2,0,6,0,100,0,0,0,0,0,33,30644,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jotunheim Sleep-Watcher - On Death - Give Kill Credit credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(@JOT_WARRIOR,@WATER_MAGUS,@SPEAR_SISTER,@VAL_VARGUL,@SLEEP_WATCHER);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,@JOT_WARRIOR,0,0,1,0,57615,0,0,0,0,'','Only run AI if player is possessing a water terror'),
(22,4,@WATER_MAGUS,0,0,1,0,57615,0,0,0,0,'','Only run AI if player is  possessing  a water terror'),
(22,2,@SPEAR_SISTER,0,0,1,0,57615,0,0,0,0,'','Only run AI if player is  possessing  a water terror'),
(22,2,@VAL_VARGUL,0,0,1,0,57615,0,0,0,0,'','Only run AI if player is possessing  a water terror'),
(22,3,@SLEEP_WATCHER,0,0,1,0,57615,0,0,0,0,'','Only run AI if player is possessing  a water terror');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=@NPC_WATER_TERROR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(16,0,@NPC_WATER_TERROR,0,0,23,0,4526,0,0,0,0,0,'','Water Terror (Vehicle) Allowed in Njorndar Village'),
(16,0,@NPC_WATER_TERROR,0,1,23,0,4524,0,0,0,0,0,'','Water Terror (Vehicle) Allowed in Valhalas'),
(16,0,@NPC_WATER_TERROR,0,2,23,0,4496,0,0,0,0,0,'','Water Terror (Vehicle) Allowed in Jotunheim');
