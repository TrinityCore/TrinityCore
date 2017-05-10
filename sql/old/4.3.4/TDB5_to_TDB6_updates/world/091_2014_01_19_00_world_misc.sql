UPDATE `smart_scripts` SET `action_param1`=61752, `target_type`=7, `target_param1`=0, `comment`='Illidan Stormrage - On Just Died - Invoker Cast \'Illidan Kill Credit Master\'' WHERE `entryorguid`=32588 AND `source_type`=0 AND `id`=5;

DELETE FROM `spell_script_names` WHERE `spell_id`=61752;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61752, 'spell_q13400_illidan_kill_master');
