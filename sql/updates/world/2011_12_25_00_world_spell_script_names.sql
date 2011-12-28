UPDATE `item_template` SET `ScriptName`='' WHERE `entry`=23654;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q9452_cast_net';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(29866,'spell_q9452_cast_net');
