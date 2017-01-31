--
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (4488,17209,17238,89713,97229);
DELETE from `item_script_names` WHERE `ScriptName` IN ('423','internalitemhandler');
