SET @YOGGSARON := 33288;
SET @SARA := 33134;
SET @GUARDIAN_OF_YOGGSARON := 33136;
SET @CORRUPTOR_TENTACLE := 33985;
SET @CONSTRICTOR_TENTACLE := 33983;
SET @CRUSHER_TENTACLE := 33966;

UPDATE `creature_template` SET `ScriptName`='boss_yoggsaron' WHERE `entry`=@YOGGSARON;
UPDATE `creature_template` SET `ScriptName`='boss_sara' WHERE `entry`=@SARA;
UPDATE `creature_template` SET `ScriptName`='npc_guardian_of_yoggsaron' WHERE `entry`=@GUARDIAN_OF_YOGGSARON;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (63802,63830);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(63802,'spell_yoggsaron_brain_link'),
(63830,'spell_yoggsaron_malady_of_the_mind');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (63882,63886,64173);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,63882,0,0,31,0,3,@SARA,0,0,0,'','Death Ray Warning Visual'),
(13,1,63886,0,0,31,0,3,@SARA,0,0,0,'','Death Ray Damage Visual'),
(13,1,64173,0,0,31,0,3,@SARA,0,0,0,'','Shattered Illusion'), -- replace by Yogg's ID if Sara is caster of this spell instead of Yogg
(13,1,64173,0,0,31,0,3,@CRUSHER_TENTACLE,0,0,0,'','Shattered Illusion'),
(13,1,64173,0,0,31,0,3,@CONSTRICTOR_TENTACLE,0,0,0,'','Shattered Illusion'),
(13,1,64173,0,0,31,0,3,@CORRUPTOR_TENTACLE,0,0,0,'','Shattered Illusion');
