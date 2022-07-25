--
DELETE FROM `spell_scripts` WHERE `id` = 53099;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_teleport_leaders_blessing','spell_59064_59439_portals');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (53099,57896,58418,58420,59064,59065,59439,60900,60940) AND `ScriptName` = 'spell_quest_portal_with_condition';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53099,'spell_quest_portal_with_condition'),
(57896,'spell_quest_portal_with_condition'),
(58418,'spell_quest_portal_with_condition'),
(58420,'spell_quest_portal_with_condition'),
(59064,'spell_quest_portal_with_condition'),
(59065,'spell_quest_portal_with_condition'),
(59439,'spell_quest_portal_with_condition'),
(60900,'spell_quest_portal_with_condition'),
(60940,'spell_quest_portal_with_condition');
