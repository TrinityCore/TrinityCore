--
DELETE FROM `creature_text` WHERE `CreatureID` = 17380;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17380,0,0,"Kill them!",14,0,100,0,0,0,15115,0,"broggok SAY_INTRO"),
(17380,1,0,"Come intruders....",14,0,100,0,0,0,14259,0,"broggok SAY_AGGRO");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 26838;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,26838,0,0,31,0,3,16006,0,0,0,0,"","Group 0: Spell 'Despawn InCombat Trigger' (Effect 0) targets creature 'InCombat Trigger'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 26838 AND `ScriptName` = 'spell_gen_despawn_target';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(26838,'spell_gen_despawn_target');
-- Credit - Cmangos
DELETE FROM `waypoint_data` WHERE `id` = 1381150;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1381150,1,455.6496,33.33417,9.544375,NULL,0,1,0,100,0),
(1381150,2,456.105,44.3159,9.62544,NULL,0,1,0,100,0),
(1381150,3,458.401,50.6364,9.62375,NULL,0,1,0,100,0),
(1381150,4,461.782,54.9224,9.6233,NULL,0,1,0,100,0),
(1381150,5,463.657,60.3144,9.61813,NULL,0,1,0,100,0),
(1381150,6,456.328,78.3051,9.61487,1.53589,0,1,0,100,0);
