-- Added aura Acidic Wound on Gurtogg Bloodboil
DELETE FROM `creature_addon` where `guid`=52761;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52761, 0, 0, 0, 0, 0, 40484);

-- SpellScripts
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gurtogg_bloodboil_insignificance';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40618, 'spell_gurtogg_bloodboil_insignificance');

-- Added creature script in Fel Geyser creature
UPDATE `creature_template` SET `ScriptName`='npc_fel_geyser' WHERE `entry`=23254;

-- Conditions for spell Taunt Gurtogg
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40603;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,40603,0,0,31,0,3,22948,0,0,0,0,'','Effect_0 and Effect_1 - Hits Gurtogg Bloodboil');

-- Fix Texts
UPDATE `creature_text` SET `Text`='I hunger.',`BroadcastTextId`=21744 WHERE `CreatureID`=22948 AND `GroupID`=2 AND `ID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=22948 AND `GroupID`IN(3,4);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22948,3,0,'I\'ll rip the meat from your bones!',14,0,100,0,0,11438,21745,0,'bloodboil SAY_ENRAGE');
