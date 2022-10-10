INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) values('67977','0','0','0','1','0','72242');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '140431','spell_rockfall_dummy'); 
UPDATE `creature_template` SET `ScriptName`='npc_rockfall' WHERE `entry`='68219'; 

