--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=19823;

DELETE FROM `smart_scripts` WHERE `entryorguid`=19823 AND `source_type`=0;
INSERT INTO `smart_scripts` VALUES
(19823,0,0,0,6,0,100,0,0,0,0,0,33,22051,0,0,0,0,0,16,0,0,0,0,0,0,0,'Crazed Colossus - On Death - Quest Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=19823;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,19823,0,0,1,0,38224,0,0,0,0,0,'','Execute only if invoker has equipped Enchanted Illidari Tabard');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=38224;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(38224, 38225, 2, 'Illidari Agent Illusion - Illidari Disguise (Male)');

UPDATE `quest_template` SET `NextQuestId`=13718 WHERE `Id` =13593;
