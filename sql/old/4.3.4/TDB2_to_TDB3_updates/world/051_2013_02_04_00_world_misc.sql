-- Something Stinks (A:24655 H:24536)
-- SET @GUID           := 85637; -- set by TDB (need 10)(85637,85638,85639,85640,85641,85642,85643,85644,85645,85646,43498,43502,45075,45099) 4.x verified
SET @EVENT          := 8; -- Love is in the Air

SET @BUNNY          := 38288; -- Love Guard Perfume Bunny
SET @GUARD_SW       := 68; -- Stormwind City Guard
SET @PATROOLER_SW   := 1976; -- Stormwind City Patroller
SET @GUARD_ORG      := 3296; -- Orgrimmar Grunt
SET @ELITE_ORG      := 14304; -- Kor'kron Elite

SET @SPELL_PULSE    := 71520; -- Heavily Perfumed Pulse
SET @SPELL_BUFF     := 71507; -- Heavily Perfumed
SET @SPELL_ANALYSIS := 70192; -- Fragrant Air Analysis

/* 4.x removed
DELETE FROM `creature` WHERE `id`=@BUNNY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@BUNNY,0,1,1,0,0,-8825.604,629.3108,94.1137,0,300,0,0,1,0,0,0,0,0), -- sw trade district
(@GUID+1,@BUNNY,0,1,1,0,0,-8988.889,849.4149,105.9425,0,300,0,0,1,0,0,0,0,0), -- sw mage quarter
(@GUID+2,@BUNNY,0,1,1,0,0,-8737.654,1051.887,90.8816,0,300,0,0,1,0,0,0,0,0), -- sw the park
(@GUID+3,@BUNNY,0,1,1,0,0,-8625.038,780.0799,96.73399,0,300,0,0,1,0,0,0,0,0), -- sw cathedral square
(@GUID+4,@BUNNY,0,1,1,0,0,-8433.189,607.2205,95.13025,0,300,0,0,1,0,0,0,0,0), -- sw dwarven district
(@GUID+5,@BUNNY,0,1,1,0,0,-8486.955,390.5139,108.4689,0,300,0,0,1,0,0,0,0,0), -- sw stormwind keep
(@GUID+6,@BUNNY,0,1,1,0,0,-8676.724,444.5052,99.73087,0,300,0,0,1,0,0,0,0,0), -- sw old town
--
(@GUID+7,@BUNNY,1,1,1,0,0,1573.92,-4397.11,16.00813,0,300,0,0,1,0,0,0,0,0), -- org valley of strength
(@GUID+8,@BUNNY,1,1,1,0,0,1893.24,-4507.31,24.94853,0,300,0,0,1,0,0,0,0,0), -- org the drag
(@GUID+9,@BUNNY,1,1,1,0,0,2015.27,-4687.4,28.61023,0,300,0,0,1,0,0,0,0,0); -- org valley of honor
*/

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_PULSE;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_BUFF;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_PULSE,0,0,31,0,3,@GUARD_SW,0,0,0,0,'',"Heavily Perfumed Pulse target Stormwind City Guard"),
(13,1,@SPELL_PULSE,0,1,31,0,3,@PATROOLER_SW,0,0,0,0,'',"Heavily Perfumed Pulse target Stormwind City Patroller"),
(13,1,@SPELL_PULSE,0,2,31,0,3,@GUARD_ORG,0,0,0,0,'',"Heavily Perfumed Pulse target Orgrimmar Grunt"),
(13,1,@SPELL_PULSE,0,3,31,0,3,@ELITE_ORG,0,0,0,0,'',"Heavily Perfumed Pulse target Kor'kron Elite"),
(17,0,@SPELL_BUFF,0,0,1,0,@SPELL_BUFF,0,0,1,0,0,'',"Apply Heavily Perfumed only when missing");

UPDATE `creature_template` SET `AIName`='SmartAI',`InhabitType`=4,`flags_extra`=`flags_extra`|128 WHERE `entry`=@BUNNY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BUNNY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BUNNY,0,0,0,60,0,100,0,0,0,600000,600000,11,@SPELL_PULSE,0,0,0,0,0,1,0,0,0,0,0,0,0,"On update(each 10 min) - Cast - Self");

-- ussing this because dummy effect #1 of spell 70192 is to remove the buff
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_ANALYSIS;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_ANALYSIS,-@SPELL_BUFF,1,'Remove Heavily Perfumed on Fragrant Air Analysis hit');

/* 4.x removed
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @GUID+0 AND @GUID+9;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(@EVENT,@GUID+0),
(@EVENT,@GUID+1),
(@EVENT,@GUID+2),
(@EVENT,@GUID+3),
(@EVENT,@GUID+4),
(@EVENT,@GUID+5),
(@EVENT,@GUID+6),
(@EVENT,@GUID+7),
(@EVENT,@GUID+8),
(@EVENT,@GUID+9);
*/
