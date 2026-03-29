DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
	'spell_gen_background_filter', 
	'spell_item_selfie_camera_mk2', 
	'spell_gen_selfie_camera_filter', 
	'spell_gen_take_selfie'
);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(258730, 'spell_gen_background_filter'),
(181884, 'spell_item_selfie_camera_mk2'),
(181767, 'spell_gen_selfie_camera_filter'),
(181779, 'spell_gen_selfie_camera_filter'),
(181773, 'spell_gen_selfie_camera_filter'),
(181842, 'spell_gen_take_selfie');

DELETE FROM `quest_template` WHERE `ID` IN (49760, 49761, 49762, 49763, 49764);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestSortID`, `QuestInfoID`, `RewardSpell`, `Flags`, `LogTitle`, `LogDescription`, `QuestDescription`, `Expansion`, `VerifiedBuild`) VALUES
(49760, 2, 0, 0, 258750, 0x00000400, 'S.E.L.F.I.E. Camera - Frostmourne Filter', 'Take a selfie with The Lich King in Icecrown Citadel.', 'Use the S.E.L.F.I.E. Camera MkII while fighting The Lich King.', 0, 0),
(49761, 2, 0, 0, 258749, 0x00000400, 'S.E.L.F.I.E. Camera - Firelands Filter', 'Take a selfie with Ragnaros in Firelands.', 'Use the S.E.L.F.I.E. Camera MkII while fighting Ragnaros.', 0, 0),
(49762, 2, 0, 0, 258803, 0x00000400, 'S.E.L.F.I.E. Camera - Argus Filter', 'Take a selfie with Argus the Unmaker in Antorus.', 'Use the S.E.L.F.I.E. Camera MkII while fighting Argus.', 0, 0),
(49763, 2, 0, 0, 258751, 0x00000400, 'S.E.L.F.I.E. Camera - Sha Filter', 'Take a selfie with the Sha of Fear.', 'Use the S.E.L.F.I.E. Camera MkII while fighting the Sha of Fear.', 0, 0),
(49764, 2, 0, 0, 258752, 0x00000400, 'S.E.L.F.I.E. Camera - Twilight Filter', 'Take a selfie with Cho\'gall in The Bastion of Twilight.', 'Use the S.E.L.F.I.E. Camera MkII while fighting Cho\'gall.', 0, 0);

DELETE FROM `trinity_string` WHERE `entry` = 10058;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES 
(10058, "S.E.L.F.I.E. Camera captures %s!");

-- Create spell group for selfie camera filters (exclusive - only one can be active at a time)
DELETE FROM `spell_group` WHERE `id` = 2000;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(2000, 181767), -- Sketch Filter
(2000, 181779), -- Death Filter
(2000, 181773), -- Black and White Filter
(2000, 258750), -- Frostmourne Filter
(2000, 258749), -- Firelands Filter
(2000, 258803), -- Argus Filter
(2000, 258751), -- Sha Filter
(2000, 258752); -- Twilight Filter

DELETE FROM `spell_group_stack_rules` WHERE `group_id` = 2000;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(2000, 1); -- SPELL_GROUP_STACK_RULE_EXCLUSIVE
