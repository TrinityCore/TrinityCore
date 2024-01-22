UPDATE `creature_template` SET `ScriptName`= 'boss_argaloth' WHERE `ScriptName`= 'boss_pit_lord_argaloth';
UPDATE `creature_template` SET `flags_extra`= 0x80, `AIName`= 'NullCreatureAI' WHERE `entry`= 47829;
UPDATE `creature_template_difficulty` SET `StaticFlags1`= 0x2000306, `StaticFlags2`= 0x100000, `StaticFlags3`= 0x8400, `StaticFlags4`= 0x210 WHERE `Entry`= 47829;
UPDATE `creature_template_addon` SET `Auras`= '' WHERE `entry`= 47829;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_argaloth_meteor_slash', 'spell_argaloth_fel_firestorm_forcecast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88972, 'spell_argaloth_fel_firestorm'),
(88987, 'spell_argaloth_fel_firestorm_forcecast');

DELETE FROM `spell_custom_attr` WHERE `entry`= 88942;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(88942, 0x8);

DELETE FROM `creature_text` WHERE `CreatureID`= 47120;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(47120, 0, 0, '|TInterface\\Icons\\spell_fire_felrainoffire.blp:20|t%s begins to cast |cFFFF0000|Hspell:88972|h[Fel Firestorm]|h|r!', 41, 0, 100, 0, 0, 0, 48107, 'Argaloth - Announce Fel Firestorm');
