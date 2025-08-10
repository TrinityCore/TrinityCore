-- Creature
UPDATE `creature_template` SET `ScriptName`='boss_dark_shaman_koranthal' WHERE `entry`=61412;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry`=61413;

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` = 119927;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 119927, 0, 0, 51, 0, 5, 61413, 0, '', 0, 0, 0, '', 'Spell \'Shadow Vortex\' can only hit \'Flame Visual\'');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 61412;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(61412, 0, 0, 'The power of the Dark Shaman will overwhelm you!', 14, 0, 100, 0, 0, 0, 61305, 0, 'Dark Shaman Koranthal to Player'),
(61412, 1, 0, '|TInterface\Icons\spell_shadow_shadowfury:20|tDark Shaman Koranthal summons a |r|cFF9E09DE|Hspell:119971|h[Shadow Storm]|h|r!', 41, 0, 100, 0, 0, 0, 61139, 0, 'Dark Shaman Koranthal to Player'),
(61412, 2, 0, 'My death... means... nothing...', 14, 0, 100, 0, 0, 0, 61306, 0, 'Dark Shaman Koranthal to Player');

-- Spell
DELETE FROM `spell_script_names` WHERE `spell_id`=119973;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(119973, 'spell_dark_shaman_koranthal_shadow_storm');
