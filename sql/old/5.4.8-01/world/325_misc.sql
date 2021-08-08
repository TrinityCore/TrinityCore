DELETE FROM disables WHERE entry in (110744, 110745, 122121, 122128) AND `sourceType`=0;
delete from disables where comment like "%divine star%";

DELETE FROM `spell_script_names` WHERE `spell_id` IN (110744, 110745, 122121, 122128);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(110744, 'spell_priest_divine_star'),
(110745, 'spell_priest_divine_star_aoe'),
(122121, 'spell_priest_divine_star'),
(122128, 'spell_priest_divine_star_aoe');

UPDATE `creature_template` SET `InhabitType`=7, `ScriptName`='npc_divine_star' WHERE `entry`=73692;
