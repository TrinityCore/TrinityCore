--
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.14286, `flags_extra` = `flags_extra`|512 WHERE `entry` = 14517;
UPDATE `creature_template_movement` SET `Flight` = 0 WHERE `CreatureId` = 14517;

DELETE FROM `creature_text` WHERE `CreatureID` = 14517 AND `GroupID` IN (3,4);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(14517,3,0,"%s emits a deafening shriek!",16,0,100,0,0,0,10370,0,"High Priestess Jeklik"),
(14517,4,0,"%s begins to cast a Great Heal!",16,0,100,0,0,0,10494,0,"High Priestess Jeklik");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 23974;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,23974,0,0,31,0,3,14758,0,0,0,0,"","Group 0: Spell 'Summon Frenzied Bloodseeker Bats' (Effect 0) targets creature 'Zul'Gurub Trigger'");

UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 2.14286, `BaseAttackTime` = 1000, `ScriptName` = 'npc_frenzied_bloodseeker_bat' WHERE `entry` = 14965;
