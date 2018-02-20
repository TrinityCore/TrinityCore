-- Add Flying InhabitType for Doom Blossom.
UPDATE `creature_template` SET `InhabitType`=`InhabitType`|4 WHERE `entry`= 23123;
-- Add missing spells to Ghost (Vengeful Spirit)
UPDATE `creature_template` SET `spell1`=40325, `spell3`=40157, `spell4`=40175, `spell5`=40314, `spell7`=40322 WHERE `entry`=23109;
-- Add missing auras in Shadowy Construct
DELETE FROM `creature_template_addon` WHERE `entry`=23111;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23111, 0, 0, 0, 0, 0, '40326 40334');

-- Teron Gorefiend texts
DELETE FROM `creature_text` where `CreatureID`= 22871;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22871, 0, 0, 'I was the first you know. For me the wheel of death has spun many times. So much time has passed... I have a lot of catching up to do.' , 14, 0, 100, 0, 0, 11512, 21098, 0, 'Teron Gorefiend SAY_INTRO'),
(22871, 1, 0, 'Vengeance is mine!', 14, 0, 100, 0, 0, 11513, 21097, 0, 'Teron Gorefiend SAY_AGGRO'),
(22871, 2, 0, 'I have use for you...', 14, 0, 100, 0, 0, 11514, 21099, 0, 'Teron Gorefiend SAY_SLAY1'),
(22871, 2, 1, 'It gets worse.', 14, 0, 100, 0, 0, 11515, 21100, 0, 'Teron Gorefiend SAY_SLAY2'),
(22871, 3, 0, 'What are you afraid of?', 14, 0, 100, 0, 0, 11517, 21102, 0, 'Teron Gorefiend SAY_INCINERATE1'),
(22871, 3, 1, 'You will show the proper respect!', 14, 0, 100, 0, 0, 11520, 21105, 0, 'Teron Gorefiend SAY_INCINERATE2'),
(22871, 4, 0, "Death really isn't so bad.", 14, 0, 100, 0, 0, 11516, 21101, 0, 'Teron Gorefiend SAY_DOOM_BLOSSOM1'),
(22871, 4, 1, 'I have something for you...', 14, 0, 100, 0, 0, 11519, 21104, 0, 'Teron Gorefiend SAY_DOOM_BLOSSOM2'),
(22871, 5, 0, 'Give in.', 14, 0, 100, 0, 0, 11518, 21103, 0, 'Teron Gorefiend SPELL_CRUSHING_SHADOWS'),
(22871, 6, 0, 'The wheel... spins... again.', 14, 0, 100, 0, 0, 11521, 21106, 0, 'Teron Gorefiend SAY_DEATH');

-- Area Trigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=4665;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4665,'at_teron_gorefiend_entrance');

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_teron_gorefiend_spiritual_vengeance','spell_teron_gorefiend_shadow_of_death','spell_teron_gorefiend_shadow_of_death_remove');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40268,'spell_teron_gorefiend_spiritual_vengeance'),
(40251,'spell_teron_gorefiend_shadow_of_death'),
(41999,'spell_teron_gorefiend_shadow_of_death_remove');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40268;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,40268,0,0,31,0,3,23109,0,0,0,0,'','Effect_0 and Effect_1 hits Vengeful Spirit');
