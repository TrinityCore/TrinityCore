UPDATE `creature_template` SET `ScriptName`= 'npc_ertan_ertans_vortex' WHERE `entry`= 46007;

DELETE FROM `creature_template_addon` WHERE `entry`= 46007;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(46007, '86267');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_storms_edge_script',
'spell_storms_edge',
'spell_ertan_storms_edge',
'spell_ertan_storms_edge_script');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86284, 'spell_ertan_storms_edge'),
(86311, 'spell_ertan_storms_edge'),
(86299, 'spell_ertan_storms_edge_script');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (43878, 43879);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Swim`, `Rooted`) VALUES
(43878, 0, 1, 0, 1),
(43879, 0, 1, 0, 1);

DELETE FROM `spell_custom_attr` WHERE `entry` IN (86299, 86309, 93992);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(86299, 0x00000010),
(86309, 0x00000010),
(93992, 0x00000010);

DELETE FROM `creature_text` WHERE `CreatureID` IN (43878, 45704);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(43878, 0, 0, 'Filthy beasts! Your presence in Skywall will not be tolerated!', 14, 0, 100, 0, 0, 20876, 49570, 'Grandvizier Ertan - Aggro'),
(43878, 1, 0, '%s retracts her cyclone shield!', 41, 0, 100, 0, 0, 0, 47800, 'Grandvizier Ertan - Announce Storms Edge'),
(45704, 0, 0, '%s realizes it''s been spotted and quickly plays dead!', 16, 0, 100, 0, 0, 0, 46485, 'Lurking Tempest');
