DELETE FROM `creature_template_addon` WHERE `entry`=17975;
DELETE FROM `creature_addon` WHERE `guid`=82987;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(82987,829870,0,0,1,0,''); -- Converted from c_t_a, works on both normal and heroic entry

-- allow mounting inside Black Temple (outdoor areas)
UPDATE `instance_template` SET `allowMount`=1 WHERE `map`=564;

-- fix for issue #9997 by Exodius
UPDATE `spell_script_names` SET `spell_id`=28441 WHERE `spell_id`=28414 AND `ScriptName`='spell_item_ashbringer';
