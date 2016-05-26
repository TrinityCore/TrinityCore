-- 
SET @Oguid :=6008;
DELETE FROM `gameobject` WHERE `id`=186487;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@Oguid, 186487, 571, 1, 1, 2821.75, -3603.67, 245.555, 3.49556, 0, 0, 0.984379, -0.176061, -300, 0, 1);

SET @CGUID := 76053;
DELETE FROM `creature_template_addon` WHERE `entry` IN (24029);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(24029, 0, 0x0, 0x1, 12544); -- Wyrmcaller Vile - Frost Armor

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+5);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+5, 0, 0x0, 0x1, 43570); -- Invisible Stalker (Floating) - Frost State

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(43568,43569);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(43568, 34872, 1, 'Frost Strike'),
(43569, 34872, 1, 'Frost trigger ');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(43568);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,43568,0,0,31,0,3,15214,0,0,0,0,'',"Spell 'Frost Strike' Effect 0 can hit 'Invisible Stalker'");

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 15214, 571, 1, 1, 2842.762, -3599.551, 247.2563, 1.658063, 120, 0, 0), -- Invisible Stalker (Area: -Unknown-)
(@CGUID+1, 15214, 571, 1, 1, 2807.391, -3586.93, 247.6916, 3.455752, 120, 0, 0), -- Invisible Stalker (Area: -Unknown-)
(@CGUID+2, 15214, 571, 1, 1, 2833.016, -3621.016, 247.373, 1.850049, 120, 0, 0), -- Invisible Stalker (Area: -Unknown-)
(@CGUID+3, 23033, 571, 1, 1, 2831.685, -3611.948, 257.9287, 0.2479207, 120, 0, 0), -- Invisible Stalker (Floating) (Area: -Unknown-) (Auras: 43570 - Frost State)
(@CGUID+4, 23033, 571, 1, 1, 2832.849, -3638.875, 246.9362, 0.5235988, 120, 0, 0), -- Invisible Stalker (Floating) (Area: -Unknown-)
(@CGUID+5, 23033, 571, 1, 1, 2820.243, -3602.598, 261.4395, 6.161012, 120, 0, 0), -- Invisible Stalker (Floating) (Area: -Unknown-)
(@CGUID+6, 23033, 571, 1, 1, 2855.824, -3596.345, 248.4855, 5.131268, 120, 0, 0), -- Invisible Stalker (Floating) (Area: -Unknown-)
(@CGUID+7, 24029, 571, 1, 1, 2820.328, -3602.552, 247.9988, 3.665191, 120, 0, 0), -- Wyrmcaller Vile (Area: -Unknown-) (Auras: 12544 - Frost Armor)
(@CGUID+8, 23033, 571, 1, 1, 2818.341, -3604.437, 252.666, 3.845377, 120, 0, 0); -- Invisible Stalker (Floating) (Area: -Unknown-)

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=24029;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24029,-106031,-@CGUID,-(@CGUID+1),-(@CGUID+2),-(@CGUID+5),-(@CGUID+8)) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CGUID*100,@CGUID*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24029,0,0,0,1,0,100,1,0,0,3000,3000,11,43576,2,0,0,0,0,1,0,0,0,0,0,0,0,'Wyrmcaller Vile - OOC - Cast \'Frost Power\''),
(24029,0,1,0,0,0,100,0,0,0,4000,4000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wyrmcaller Vile - IC - Cast \'Frostbolt\''),  
(24029,0,2,0,0,0,100,0,0,0,6000,10000,11,15532,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wyrmcaller Vile - IC - Cast \'Frost Nova\''),
(24029,0,3,0,1,0,100,0,0,0,3000,3000,45,0,1,0,0,0,0,19,23033,10,0,0,0,0,0,'Wyrmcaller Vile - OOC - Cast \'Set Data\''),
(-106031,0,0,0,8,0,100,0,43568,0,0,0,80,@CGUID*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Stalker - On SpellHit \'Frost Strike\' - Call ActionList'),
(-@CGUID,0,0,0,8,0,100,0,43568,0,0,0,80,@CGUID*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Stalker - On SpellHit \'Frost Strike\' - Call ActionList'),
(-(@CGUID+1),0,0,0,8,0,100,0,43568,0,0,0,80,@CGUID*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Stalker - On SpellHit \'Frost Strike\' - Call ActionList'),
(-(@CGUID+2),0,0,0,8,0,100,0,43568,0,0,0,80,@CGUID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Stalker - On SpellHit \'Frost Strike\' - Call ActionList'),
(@CGUID*100,9,0,0,0,0,100,0,2400,2400,0,0,11,43569,2,0,0,0,0,19,23033,19,0,0,0,0,0,'Invisible Stalker - Action list - Cast \'Frost\''),
(@CGUID*100+1,9,0,0,0,0,100,0,2400,2400,0,0,11,43569,2,0,0,0,0,10,@CGUID+4,23033,0,0,0,0,0,'Invisible Stalker - Action list - Cast \'Frost\''),
(-(@CGUID+5),0,0,0,1,0,100,0,0,0,5000,7000,11,43591,2,0,0,0,0,19,24029,16,0,0,0,0,0,'Invisible Stalker - OOC - Cast \'Soul Siphon\''),
(-(@CGUID+8),0,0,0,38,0,100,0,0,1,0,0,11,43568,2,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Stalker - On data set - Cast \'Frost Strike\'');  
