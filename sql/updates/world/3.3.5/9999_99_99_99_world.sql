DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gift_of_the_harvester';
INSERT INTO `spell_script_names` VALUES
(52479, 'spell_gift_of_the_harvester');
UPDATE `gameobject_template` SET `Data3`=0,`AIName`='',`ScriptName`='gift_of_the_harvesterAI' WHERE `entry`=190769;
