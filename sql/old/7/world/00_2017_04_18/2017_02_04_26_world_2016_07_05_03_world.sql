DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (29531, 45390, 29726); 
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(29726, 45406, 1, "Holiday - Midsummer, Ribbon Pole Periodic Visual");

DELETE FROM `spell_script_names` WHERE `spell_id` IN (45390, 45406);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45406, "spell_gen_ribbon_pole_dancer_check");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=29726;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 29726, 0, 0, 31, 0, 3, 17066, 0, 0, 0, 0, "", "Spell 'Test Ribbon Pole Channel' targets creature 'Ribbon Pole Debug Target'");
UPDATE `gameobject_template` SET `ScriptName`="go_midsummer_ribbon_pole" WHERE `entry`=181605;

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (46836, 46842);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 46836, 64, 0, "", "Spell Flame Patch - Ignore LOS"),
(0, 46842, 64, 0, "", "Spell Flame Ring - Ignore LOS");

UPDATE `creature_template_addon` SET `bytes1`=33554688 WHERE `entry`=17066;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=17066);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=17066;
UPDATE `creature_template` SET `ScriptName`="npc_midsummer_bunny_pole" WHERE `entry`=17066;
