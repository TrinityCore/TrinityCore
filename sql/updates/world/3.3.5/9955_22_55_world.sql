DELETE FROM `creature_summon_groups` WHERE `summonerId`=22841; -- Shade of Akama
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(22841,0,1,23421,443.495,413.973,118.621,5.13127 ,6,6000),-- Ashtongue Channeler
(22841,0,1,23421,456.694,414.117,118.621,4.2586  ,6,6000),
(22841,0,1,23421,457.763,390.117,118.621,2.25148 ,6,6000),
(22841,0,1,23421,444.153,389.214,118.621,1.0821  ,6,6000),
(22841,0,1,23421,438.279,401.258,118.621,0.017453,6,6000),
(22841,0,1,23421,463.186,401.64 ,118.621,3.19395 ,6,6000),
(22841,0,1,23191,547.186,400.534,112.867,3.12414 ,8,   0); -- Akama

DELETE FROM `creature` WHERE `id` IN (23191,23421);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_shade_soul_channel_serverside','spell_shade_soul_channel');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(40401,'spell_shade_soul_channel_serverside'),
(40520,'spell_shade_soul_channel');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40902;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,2,40902,0,1,31,0,3,22841,0,0,0,0,'','Effect_1 - Hits Shade of Akama'),
(13,4,40902,0,2,31,0,3,23351,0,0,0,0,'','Effect_2 - Hits Trigger');

UPDATE `creature_template` SET `mechanic_immune_mask`=618610687 WHERE `entry`=23215; -- Ashtongue Sorcerer Immunity
UPDATE `creature_template` SET `ScriptName`='npc_ashtongue_broken' WHERE `entry`=23319;

DELETE FROM `creature_text` WHERE `entry`=23191 AND `groupid` IN (3,4);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(23191,3,0,'I will not last much longer!',14,0,100,0,0,11385,21784,0,'Akama SAY_LOW_HEALTH'),
(23191,4,0,'No! Not yet!',14,0,100,0,0,11386,21785,0,'Akama SAY_DEAD');
