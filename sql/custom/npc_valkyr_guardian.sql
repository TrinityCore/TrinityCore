UPDATE `creature_template` SET ScriptName = 'npc_valkyr_guardian' WHERE entry IN (38391, 38392);
UPDATE `creature_template` SET `mindmg`='1500', `maxdmg`='1800' WHERE (`entry`='38392');
UPDATE `creature_template` SET `dmg_multiplier`='1' WHERE `entry` IN ('38392', '38391');
UPDATE `creature_template` SET `mindmg`='1300', `maxdmg`='1500' WHERE (`entry`='38391');
