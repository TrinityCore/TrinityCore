--
UPDATE `creature_template` SET `speed_walk` = 1, `scale` = 1 WHERE `entry` IN (17990,20189);
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.57143 WHERE `entry` = 20169;

DELETE FROM `creature_text` WHERE `CreatureID` = 17770;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17770,0,0,"Hungarfen roars in pain. ",16,0,100,15,0,0,16594,0,"Hungarfen EMOTE_ROARS");

DELETE FROM `spell_scripts` WHERE `id` = 34874;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(34874,0,0,18,0,0,0,0,0,0,0,"Despawn Underbog Mushrooms - On Effect Hit (Script Effect) - Target - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 34874;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,34874,0,0,31,0,3,17990,0,0,0,0,"","Group 0: Spell 'Despawn Underbog Mushrooms' (Effect 0) targets creature 'Underbog Mushroom'");

-- Needed to prevent spell hit everything including boss and mushrooms, temp solution
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 34168;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,34168,0,0,31,0,3,17990,0,0,0,0,"","Group 0: Spell 'Spore Cloud' (Effect 0) targets creature 'Underbog Mushroom'");
