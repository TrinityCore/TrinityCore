-- Fix quest: Badlands Reagent Run II (2203)

UPDATE `item_loot_template` SET `mincountOrRef`=3, `maxcount`=3 WHERE `item`=7866;

DELETE FROM `item_loot_template` WHERE `item`=7866 AND `entry`=16883;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=9712;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,9712,0,31,3,2726,0,0,'','Spell Thaumaturgy Channel targets Scorched Guardian');

DELETE FROM `spell_script_names` WHERE `spell_id`=9712;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(9712,'spell_q2203_thaumaturgy_channel');
