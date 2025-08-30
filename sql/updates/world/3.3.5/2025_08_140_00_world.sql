--
UPDATE `creature_text` SET `BroadcastTextId` = 2384 WHERE `CreatureID` = 15369 AND `GroupID` = 0;

UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512 WHERE `entry` IN (15369);

DELETE FROM `spell_target_position` WHERE `ID` IN (26538,26539,25709,25825,25826,25827,25828,25708);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(26538,0,509,-9678.29,1526.39,24.403833,0,0),
(26539,0,509,-9709,1551.2,23.9888,0,0),
(25709,0,509,-9778.91,1419.98,61.0743,0,0),
(25825,0,509,-9757.87,1416.71,76.7664,0,0),
(25826,0,509,-9805.95,1422.85,77.5852,0,0),
(25827,0,509,-9829.42,1456.37,90.7015,0,0),
(25828,0,509,-9827.58,1506.28,82.3052,0,0),
(25708,0,509,-9827.58,1506.28,82.3052,0,0); -- Just picked from 25828, dunno if we can find real position of this one

UPDATE `creature_template` SET `ScriptName` = 'npc_hive_zara_swarmer' WHERE `entry` = 15546;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 15546;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(15546,1,0,1,0,0,0,NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (25842,25844);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,25842,0,0,31,0,3,15546,0,0,0,0,"","Group 0: Spell 'Despawn Swarmers' (Effect 0) targets creature 'Hive'Zara Swarmer'"),
(13,1,25844,0,0,31,0,3,15546,0,0,0,0,"","Group 0: Spell 'Hive'Zara Swarmers Swarm' (Effect 0) targets creature 'Hive'Zara Swarmer'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_ayamiss_paralyze',
'spell_ayamiss_swarmer_start_loop',
'spell_ayamiss_swarmer_teleport_trigger');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(25725, 'spell_ayamiss_paralyze'),
(25711, 'spell_ayamiss_swarmer_start_loop'),
(25830, 'spell_ayamiss_swarmer_teleport_trigger');
