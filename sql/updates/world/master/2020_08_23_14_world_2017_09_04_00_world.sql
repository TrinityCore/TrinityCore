UPDATE `creature` SET `position_x`=1942.307, `position_y`=43.54681, `position_z`=411.3578, `orientation`=3.535151 WHERE `guid`=137496; -- Auriaya

SET @GUID:= 48308;
-- Sanctum Sentry
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID+0, 34014, 603, 0, 0, '14,33', 0, 0, 0, 0, 0, 1944.99, 35.473570, 411.3606, 2.74932, 604800, 0, 0, 334680, 0, 0, 0, 0, 0,'' , 0),
(@GUID+1, 34014, 603, 0, 0, '14,33', 0, 0, 0, 0, 0, 1939.99, 42.584860, 411.3577, 2.70377, 604800, 0, 0, 334680, 0, 0, 0, 0, 0,'', 0);
UPDATE `creature` SET `modelid`=0, `position_x`=1943.659, `position_y`=57.08639, `position_z`=411.3522 WHERE `guid`=137491;
UPDATE `creature` SET `modelid`=0, `position_x`=1938.484, `position_y`=51.14733, `position_z`=411.3549 WHERE `guid`=137490;

DELETE FROM `creature_formations` WHERE `leaderGUID`=137496 AND `memberGUID` IN (@GUID,@GUID+1);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(137496,@GUID,5,90,515,0,0),
(137496,@GUID+1,5,270,515,0,0);

UPDATE `creature_template` SET `ScriptName`='npc_seeping_essence_stalker' WHERE `entry`=34098; -- Auriaya Seeping Essence Stalker
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839 WHERE `entry`=34014; -- Sanctum Sentry
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839 WHERE `entry`=34035; -- Feral Defender
UPDATE `creature_template` SET `unit_flags`=2048, `ScriptName`='npc_swarming_guardian' WHERE `entry`=34034; -- Swarming Guardian

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=64898; -- Instakill Arachnopod
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,64898,0,0,31,0,3,34183,0,0,0,0,'','Effect_0 hits Arachnopod Destroyer');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_auriaya_agro_creator',
'spell_auriaya_random_agro_periodic',
'spell_auriaya_feral_essence_removal',
'spell_auriaya_feral_rush');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63709, 'spell_auriaya_agro_creator'),
(61906, 'spell_auriaya_random_agro_periodic'),
(64456, 'spell_auriaya_feral_essence_removal'),
(64496, 'spell_auriaya_feral_rush'),
(64674, 'spell_auriaya_feral_rush');

DELETE FROM `creature_text` WHERE `CreatureID`=33515;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(33515,0,0,'Some things are better left alone!',14,0,100,0,0,15473,34341,0,'Auriaya SAY_AGGRO'),
(33515,1,1,'The secret dies with you.',14,0,100,0,0,15474,34354,0,'Auriaya SAY_SLAY_1'),
(33515,1,2,'There is no escape!',14,0,100,0,0,15475,37177,0,'Auriaya SAY_SLAY_2'),
(33515,2,0,'You waste my time!',14,0,100,0,0,15477,34358,0,'Auriaya SAY_BERSERK'),
(33515,3,0,'%s begins to cast Terrifying Screech.',41,0,100,0,0,0,34450,0,'Auriaya EMOTE_FEAR'),
(33515,4,0,'%s begins to activate the Feral Defender!',41,0,100,0,0,0,34162,0,'Auriaya EMOTE_DEFENDER');
