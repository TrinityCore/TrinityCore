UPDATE `creature_template` SET `ScriptName`='npc_pit_of_saron_icicle' WHERE `entry`=36847;
DELETE FROM `creature` WHERE `id`=32780 AND `guid` IN (202016,202240,201907,201923,202162,202021,202194,202235,202241,202020,202272,202169,202189,202262,202220,202245,202234,202219,202226,201933,202106,202123,201832,202025,202252,202039,202224,202274,202052,202133,202267,201966,202005,202066,202116,202153,202201,201896,202138,202218,201913,202004,201995,202178,202268,202280,202040,202176,201979,202090,202134,202154,202243,201895,202073,202195,202251,202167,202064,201972,201993,202117,201891,201812,201929,202012,202173,202092,202247,202136,201925,202239);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12994 AND `type`=18;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pos_ice_shards';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(70827, 'spell_pos_ice_shards');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5580,5581);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5580, 'at_pit_cavern_entrance'),
(5581, 'at_pit_cavern_end');

DELETE FROM `creature_text` WHERE `entry`=36794 AND `groupid`=3;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(36794,3,0,'Rimefang, trap them within the tunnel! BURY THEM ALIVE!',14,0,100,0,0,16757,36714,1,'SAY_TYRANNUS_CAVERN_ENTRANCE');
