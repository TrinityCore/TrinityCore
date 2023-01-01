UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=38463;
UPDATE `creature_template` SET `ScriptName`='npc_icc_orb_controller' WHERE `entry`=38463;
UPDATE `creature_template` SET `ScriptName`='npc_darkfallen_blood_knight' WHERE `entry`=37595;
UPDATE `creature_template` SET `ScriptName`='npc_darkfallen_noble' WHERE `entry`=37663;
UPDATE `creature_template` SET `ScriptName`='npc_vampiric_fiend' WHERE `entry`=37901;
UPDATE `creature_template` SET `ScriptName`='npc_darkfallen_archmage' WHERE `entry`=37664;
UPDATE `creature_template` SET `ScriptName`='npc_darkfallen_advisor' WHERE `entry`=37571;
UPDATE `creature_template` SET `ScriptName`='npc_darkfallen_tactician' WHERE `entry`=37666;
UPDATE `gameobject_template` SET `ScriptName`='go_empowering_blood_orb' WHERE `entry`=201741;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_icc_empowered_blood',
'spell_icc_empowered_blood_3',
'spell_icc_siphon_essence',
'spell_darkfallen_blood_mirror',
'spell_generic_remove_empowered_blood');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(70227,'spell_icc_empowered_blood'),
(70304,'spell_icc_empowered_blood_3'),
(70299,'spell_icc_siphon_essence'),
(70450,'spell_darkfallen_blood_mirror'),
(72131,'spell_generic_remove_empowered_blood'),
(70939,'spell_generic_remove_empowered_blood');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (72099,70299,70293);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,72099,0,0,31,0,3,36934,0,0,0,0,'','Effect_0 hits Empowering Orb Controller'),
(13,1,70299,0,0,31,0,3,36934,0,0,0,0,'','Effect_0 hits Empowering Orb Controller'),
(13,1,70293,0,0,31,0,3,38463,0,0,0,0,'','Effect_0 hits Empowering Orb Controller');

DELETE FROM `creature_template_movement` WHERE `CreatureId`=36934;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(36934,0,0,1,1,0,0);
