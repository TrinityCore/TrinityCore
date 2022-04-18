-- Portals / Voidwalkers
UPDATE `spell_target_position` SET `PositionZ` = 17.0863, `Orientation` = 3.121871, `VerifiedBuild` = 0 WHERE `ID` = 33582;
UPDATE `spell_target_position` SET `Orientation` = 1.360249 WHERE `ID` = 33583;
UPDATE `spell_target_position` SET `Orientation` = 5.580167 WHERE `ID` = 33584;
UPDATE `spell_target_position` SET `Orientation` = 0.047734 WHERE `ID` = 33585;
UPDATE `spell_target_position` SET `Orientation` = 6.012834 WHERE `ID` = 33586;

-- Draw Shadows
DELETE FROM `spell_target_position` WHERE `ID` = 33558;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(33558,0,555,-253.54771,-263.64563,17.169674,3.054326,0),
(33558,1,555,-253.54771,-263.64563,17.169674,3.054326,0);

-- Empowering Shadows
UPDATE `conditions` SET `ConditionValue2` = 18732 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39364;

-- Evade / Death spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (33568,33618);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,33568,0,0,31,0,3,19224,0,0,0,0,"","Group 0: Spell 'Despawn Void Portals' (Effect 0) targets creature 'Void Portal'"),
(13,1,33568,0,1,31,0,3,19427,0,0,0,0,"","Group 1: Spell 'Despawn Void Portals' (Effect 0) targets creature 'Voidwalker Summoner'"),
(13,1,33618,0,0,31,0,3,19226,0,0,0,0,"","Group 0: Spell 'Great Sacrifice' (Effect 0) targets creature 'Void Traveler'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 33568 AND `ScriptName` = 'spell_gen_despawn_target';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(33568,'spell_gen_despawn_target');

--
UPDATE `creature_template` SET `ScriptName` = 'npc_voidwalker_summoner' WHERE `entry` = 19427;
UPDATE `creature_template` SET `ScriptName` = 'npc_void_traveler' WHERE `entry` = 19226;

DELETE FROM `creature_text` WHERE `CreatureID` = 18732;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18732,0,0,"Come to my aid! Heed your master now!",14,0,100,0,0,10523,17867,0,"Grandmaster Vorpil SAY_HELP"),
(18732,1,0,"I'll make an offering of your blood!",14,0,100,0,0,10524,17868,0,"Grandmaster Vorpil SAY_AGGRO1"),
(18732,1,1,"You'll be a fine example for the others!",14,0,100,0,0,10525,17869,0,"Grandmaster Vorpil SAY_AGGRO2"),
(18732,1,2,"Good, a worthy sacrifice!",14,0,100,0,0,10526,17870,0,"Grandmaster Vorpil SAY_AGGRO3"),
(18732,2,0,"I serve with pride.",14,0,100,0,0,10527,17871,0,"Grandmaster Vorpil SAY_SLAY1"),
(18732,2,1,"Your death is for the greater cause...",14,0,100,0,0,10528,17872,0,"Grandmaster Vorpil SAY_SLAY2"),
(18732,3,0,"I give my life... gladly.",14,0,100,0,0,10529,17873,0,"Grandmaster Vorpil SAY_DEATH"),
(18732,4,0,"The darkness in your souls draws you ever closer...",14,0,100,0,0,0,16302,0,"Grandmaster Vorpil SAY_DRAW"),
(18732,5,0,"Fools.",14,0,100,0,0,0,16330,0,"Grandmaster Vorpil SAY_WIPE");
