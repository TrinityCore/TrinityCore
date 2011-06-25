UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=33571;
UPDATE `creature_template` SET `ScriptName`='npc_pool_of_tar' WHERE `entry`=33090;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (65044,65045);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13,65044,18,1,33090),
(13,65045,18,1,33090),
(13,65044,18,1,33060),
(13,65045,18,1,33060),
(13,65044,18,1,33062),
(13,65045,18,1,33062),
(13,65044,18,1,33109),
(13,65045,18,1,33109);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (65044,65045);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(65044, 'spell_flame_leviathan_flames'),
(65045, 'spell_flame_leviathan_flames');