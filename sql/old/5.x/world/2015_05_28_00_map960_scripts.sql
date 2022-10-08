UPDATE `instance_template` SET `script`='instance_temple_of_jade_serpent' WHERE (`map`='960');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_peril' WHERE (`entry`='59726');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_strife' WHERE (`entry`='59051');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_nodding_tiger' WHERE (`entry`='59544');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_golden_beetle' WHERE (`entry`='59545');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_jiang_xiang' WHERE (`entry`='65317');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_songbird_queen' WHERE (`entry`='59553');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_talking_fish' WHERE (`entry`='59546');
DELETE FROM smart_scripts WHERE entryorguid IN (59726,59051,59544,59545,65317,59553,59546);
