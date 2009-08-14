UPDATE `creature_template` SET `ScriptName`='boss_netherspite', `RegenHealth` = '1' WHERE `entry`='15689';
UPDATE `creature_template` SET `faction_A` = '35', `faction_H` = '35', `modelid_A`='11686', `modelid_H`='11686', `unit_flags` = '33554496', `ScriptName` = '' WHERE `entry` IN ('17367','17368','17369');
UPDATE `creature_template` SET `minlevel` = '70', `maxlevel` = '70',`flags_extra`= '2', `speed`= '0.0001', `faction_A` = '16', `faction_H` = '16', `ScriptName` = 'mob_eventai'  WHERE `entry` = '16697';
DELETE FROM `eventai_scripts` WHERE `creature_id` = '16697';
INSERT INTO `eventai_scripts`
(`id`,`creature_id`,`event_type`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action1_type`,`action1_param1`,`action1_param2`,`action1_param3`,`comment`) VALUES
('1669701', '16697',         '0',         '100',          '3',        '3000',        '3000',        '3000',        '3000',          '11',         '46264',             '0',             '2','Void Zone - Cast Void Zone Effect'),
('1669702', '16697',         '1',         '100',          '3',        '3000',        '3000',        '3000',        '3000',          '11',         '46264',             '0',             '2','Void Zone - Cast Void Zone Effect');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN ('-30421','-30422','-30423','38637','38638','38639');
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
('-30421','38637','0','Netherspite\'s Perseverence'),
('-30422','38638','0','Netherspite\'s Serenity'),
('-30423','38639','0','Netherspite\'s Dominance');
UPDATE `script_texts` SET `type` = '3' WHERE `entry` IN ('-1532089','-1532090');