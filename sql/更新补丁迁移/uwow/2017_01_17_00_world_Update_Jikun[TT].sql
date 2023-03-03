INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '138923','spell_caw_searcher'); 
UPDATE `areatrigger_data` SET `Radius`='53',`RadiusTarget`='53',`windSpeed`='-8',`polygon`='0' WHERE `entry`='587';
UPDATE `creature_template` SET `InhabitType`='7',`ScriptName`='npc_jikun_feed' WHERE `entry`='68178'; 
UPDATE `areatrigger_actions` SET `maxCharges`='1' WHERE `entry`='929' AND `id`='0';  