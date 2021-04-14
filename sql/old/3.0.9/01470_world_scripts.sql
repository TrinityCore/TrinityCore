-- Remove script for quest 8346. Note support for this quest will be added in next ACID release(25)
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (15273,15274,15294,15298,15367);
UPDATE `creature_template` SET `ScriptName`='mob_broggok_poisoncloud' WHERE `entry`=17662;
-- UPDATE `creature_template` SET `ScriptName`='npc_draenei_survivor' WHERE `entry`=16483;
