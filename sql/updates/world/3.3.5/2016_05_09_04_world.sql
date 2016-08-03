UPDATE `creature_template` SET `unit_flags`=33554432, `flags_extra`=0 WHERE `entry`=25744;
DELETE FROM `creature_summon_groups` WHERE `summonerId`=25741;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_summon_blood_elves_script',
'spell_muru_darkness',
'spell_dark_fiend_skin',
'spell_transform_visual_missile_periodic',
'spell_summon_blood_elves_periodic');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(46050,'spell_summon_blood_elves_script'),
(45996,'spell_muru_darkness'),
(45934,'spell_dark_fiend_skin'),
(46205,'spell_transform_visual_missile_periodic'),
(46041,'spell_summon_blood_elves_periodic');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (46208,46178);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46208,0,0,31,0,3,25741,0,0,0,'','Spell \'Transform Visual Missile\' targets M\'uru'),
(13,1,46178,0,0,31,0,3,25741,0,0,0,'','Spell \'Transform Visual Missile\' targets M\'uru');

UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=2 WHERE `DisplayID`=23842;
UPDATE `creature_model_info` SET `BoundingRadius`=6, `CombatReach`=6 WHERE `DisplayID`=23428;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5 WHERE `DisplayID`=22471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.48, `CombatReach`=11.2 WHERE `DisplayID`=22838;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8893, `CombatReach`=2.5 WHERE `DisplayID`=23177;
UPDATE `creature_model_info` SET `BoundingRadius`=6, `CombatReach`=15 WHERE `DisplayID`=23200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8893, `CombatReach`=2.5 WHERE `DisplayID`=23334;
UPDATE `creature_model_info` SET `BoundingRadius`=0.612, `CombatReach`=3 WHERE `DisplayID`=23350;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=3.75 WHERE `DisplayID`=23473;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6, `CombatReach`=3 WHERE `DisplayID`=23474;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6, `CombatReach`=3 WHERE `DisplayID`=23476;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6, `CombatReach`=3 WHERE `DisplayID`=23477;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6, `CombatReach`=3 WHERE `DisplayID`=23478;
UPDATE `creature_model_info` SET `BoundingRadius`=0.754676, `CombatReach`=3 WHERE `DisplayID`=23479;
UPDATE `creature_model_info` SET `BoundingRadius`=0.51705, `CombatReach`=2.025 WHERE `DisplayID`=23531;
UPDATE `creature_model_info` SET `BoundingRadius`=0.51705, `CombatReach`=2.025 WHERE `DisplayID`=23533;
UPDATE `creature_model_info` SET `BoundingRadius`=0.51705, `CombatReach`=2.025 WHERE `DisplayID`=23537;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5 WHERE `DisplayID`=23717;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `CombatReach`=4.5 WHERE `DisplayID`=26628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.375 WHERE `DisplayID`=29280;
