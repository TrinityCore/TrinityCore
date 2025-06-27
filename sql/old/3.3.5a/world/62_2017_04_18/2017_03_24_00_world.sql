-- Correct speed for Wicked Spirits and Spirit Bombs
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571 WHERE `entry` IN(39189,39190,39287,39288,39289);
UPDATE `creature_template` SET `InhabitType`=4, `HoverHeight`=4 WHERE `entry` IN(36609,39120,39121,39122);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_the_lich_king_harvest_souls_teleport';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(73655,'spell_the_lich_king_harvest_souls_teleport');

DELETE FROM `spell_custom_attr` WHERE `entry` IN(69409,73797,73798,73799);
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(69409,32768),
(73797,32768),
(73798,32768),
(73799,32768);
