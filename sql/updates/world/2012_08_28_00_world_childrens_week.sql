-- Assign core script to quest givers
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_orphan_matron_mercy',`gossip_menu_id`=0 WHERE `entry`=22819;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_orphan_matron_aria',`gossip_menu_id`=0 WHERE `entry`=34365;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_orphan_matron_battlewail',`gossip_menu_id`=0 WHERE `entry`=14451;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_orphan_matron_nightingale',`gossip_menu_id`=0 WHERE `entry`=14450;

-- Spawn Orphan Matron Aria
DELETE FROM `creature` WHERE `guid`=3019822;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`curhealth`,`curmana`) VALUES
(3019822,34365,571,5712.76,635.632,646.26,5.56071,12600,3994);

DELETE FROM `game_event_creature` WHERE `guid`=3019822;
INSERT INTO `game_event_creature`(`guid`,`eventEntry`) VALUES
(3019822,10);

-- Set conditions for quests of Blood Elf Orphan
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(11975,10963);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,11975,8,10945,'Accept quest 11975 - Quest 10945 needs to be rewarded'),
(19,11975,8,10953,'Accept quest 11975 - Quest 10953 needs to be rewarded'),
(19,11975,8,10951,'Accept quest 11975 - Quest 10951 needs to be rewarded'),
(19,10963,8,10945,'Accept quest 10963 - Quest 10945 needs to be rewarded'),
(19,10963,8,10953,'Accept quest 10963 - Quest 10953 needs to be rewarded'),
(19,10963,8,10951,'Accept quest 10963 - Quest 10951 needs to be rewarded'),
(20,11975,8,10945,'Show quest mark 11975 - Quest 10945 needs to be rewarded'),
(20,11975,8,10953,'Show quest mark 11975 - Quest 10953 needs to be rewarded'),
(20,11975,8,10951,'Show quest mark 11975 - Quest 10951 needs to be rewarded'),
(20,10963,8,10945,'Show quest mark 10963 - Quest 10945 needs to be rewarded'),
(20,10963,8,10953,'Show quest mark 10963 - Quest 10953 needs to be rewarded'),
(20,10963,8,10951,'Show quest mark 10963 - Quest 10951 needs to be rewarded');

UPDATE `quest_template` SET `NextQuestId`=10967,`ExclusiveGroup`=-11975 WHERE `Id` IN(11975,10963);
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id` IN(10945,10953,10951);

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`&~2, `EndText`='', `ObjectiveText2`='Salandria taken to the Caverns of Time', `ReqCreatureOrGOId2`=22817, `ReqCreatureOrGOCount2`=1 WHERE `Id`=10963;
UPDATE `locales_quest` SET `EndText_loc3`='', `ObjectiveText2_loc3`='Salandria zu den Höhlen der Zeit gebracht' WHERE `entry`=10963;

DELETE FROM `creature_questrelation` WHERE `id`=22817;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(22817,10945),
(22817,10953),
(22817,10951),
(22817,10963),
(22817,11975),
(22817,10967);

DELETE FROM `creature_involvedrelation` WHERE `id`=22817;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(22817,10942),
(22817,10951),
(22817,11975),
(22817,10963);

-- Set conditions for quests of Blood Elf Orphan and translate q 13960
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(13955,13957);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,13955,8,13930,'Accept quest 13955 - Quest 13930 needs to be rewarded'),
(19,13955,8,13934,'Accept quest 13955 - Quest 13934 needs to be rewarded'),
(19,13955,8,13951,'Accept quest 13955 - Quest 13951 needs to be rewarded'),
(19,13957,8,13930,'Accept quest 13957 - Quest 13930 needs to be rewarded'),
(19,13957,8,13934,'Accept quest 13957 - Quest 13934 needs to be rewarded'),
(19,13957,8,13951,'Accept quest 13957 - Quest 13951 needs to be rewarded'),
(20,13955,8,13930,'Show quest mark 13955 - Quest 13930 needs to be rewarded'),
(20,13955,8,13934,'Show quest mark 13955 - Quest 13934 needs to be rewarded'),
(20,13955,8,13951,'Show quest mark 13955 - Quest 13951 needs to be rewarded'),
(20,13957,8,13930,'Show quest mark 13957 - Quest 13930 needs to be rewarded'),
(20,13957,8,13934,'Show quest mark 13957 - Quest 13934 needs to be rewarded'),
(20,13957,8,13951,'Show quest mark 13957 - Quest 13951 needs to be rewarded');

UPDATE `quest_template` SET `NextQuestId`=13938,`ExclusiveGroup`=-13955 WHERE `Id` IN(13955,13957);
UPDATE `quest_template` SET `PrevQuestId`=13938, `RewMailTemplateId`=270 WHERE `Id`=13960;

UPDATE `locales_quest` SET `RequestItemsText_loc3`='Kekek möchte nicht gehen. Kekek möchte mehr von Nordend sehen.' WHERE `entry`=13960;

DELETE FROM `mail_loot_template` WHERE `entry`=270;
INSERT INTO `mail_loot_template`(`entry`,`item`,`ChanceOrQuestChance`) VALUES
(270,46544,100);

DELETE FROM `creature_questrelation` WHERE `id`=33532;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(33532,13938),
(33532,13960),
(33532,13930),
(33532,13951),
(33532,13934),
(33532,13955),
(33532,13957);

DELETE FROM `creature_involvedrelation` WHERE `id`=33532;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(33532,13938),
(33532,13930),
(33532,13927),
(33532,13951),
(33532,13934),
(33532,13955),
(33532,13957);

-- Set conditions for quests of Draenei Orphan
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(10956,10962);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,10956,8,10950,'Accept quest 10956 - Quest 10950 needs to be rewarded'),
(19,10956,8,10954,'Accept quest 10956 - Quest 10954 needs to be rewarded'),
(19,10956,8,10952,'Accept quest 10956 - Quest 10952 needs to be rewarded'),
(19,10962,8,10950,'Accept quest 10962 - Quest 10950 needs to be rewarded'),
(19,10962,8,10954,'Accept quest 10962 - Quest 10954 needs to be rewarded'),
(19,10962,8,10952,'Accept quest 10962 - Quest 10952 needs to be rewarded'),
(20,10956,8,10950,'Show quest mark 10956 - Quest 10950 needs to be rewarded'),
(20,10956,8,10954,'Show quest mark 10956 - Quest 10954 needs to be rewarded'),
(20,10956,8,10952,'Show quest mark 10956 - Quest 10952 needs to be rewarded'),
(20,10962,8,10950,'Show quest mark 10962 - Quest 10950 needs to be rewarded'),
(20,10962,8,10954,'Show quest mark 10962 - Quest 10954 needs to be rewarded'),
(20,10962,8,10952,'Show quest mark 10962 - Quest 10952 needs to be rewarded');

UPDATE `quest_template` SET `NextQuestId`=10966,`ExclusiveGroup`=-10968 WHERE `Id` IN(10968,10962);
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id` IN(10956,10968,10950,10952,10954);

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`&~2, `EndText`='', `ObjectiveText2`='Dornaa taken to the Caverns of Time', `ReqCreatureOrGOId2`=22818, `ReqCreatureOrGOCount2`=1 WHERE `Id`=10962;
UPDATE `locales_quest` SET `EndText_loc3`='', `ObjectiveText2_loc3`='Dornaa zu den Höhlen der Zeit gebracht' WHERE `entry`=10962;

DELETE FROM `creature_questrelation` WHERE `id`=22818;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(22818,10952),
(22818,10950),
(22818,10966),
(22818,10954),
(22818,10956),
(22818,10962);

DELETE FROM `creature_involvedrelation` WHERE `id`=22818;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(22818,10950),
(22818,10952),
(22818,10943),
(22818,10962);

-- Set conditions for quests of Orc Orphan. Set quest end and quest start relations for Orc Orphan
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(915,925);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,925,8,910,'Accept quest 925 - Quest 910 needs to be rewarded'),
(19,925,8,911,'Accept quest 925 - Quest 911 needs to be rewarded'),
(19,925,8,1800,'Accept quest 925 - Quest 1800 needs to be rewarded'),
(19,915,8,910,'Accept quest 915 - Quest 910 needs to be rewarded'),
(19,915,8,911,'Accept quest 915 - Quest 911 needs to be rewarded'),
(19,915,8,1800,'Accept quest 915 - Quest 1800 needs to be rewarded'),
(20,925,8,910,'Show quest mark 925 - Quest 910 needs to be rewarded'),
(20,925,8,911,'Show quest mark 925 - Quest 911 needs to be rewarded'),
(20,925,8,1800,'Show quest mark 925 - Quest 1800 needs to be rewarded'),
(20,915,8,910,'Show quest mark 915 - Quest 910 needs to be rewarded'),
(20,915,8,911,'Show quest mark 915 - Quest 911 needs to be rewarded'),
(20,915,8,1800,'Show quest mark 915 - Quest 1800 needs to be rewarded');

UPDATE `quest_template` SET `NextQuestId`=5502,`ExclusiveGroup`=-915,`PrevQuestId`=0 WHERE `Id` IN(915,925);
UPDATE `quest_template` SET `RequiredRaces`=690 WHERE `Id` IN(915,925,910,911,1800,5502);
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id` IN(910,1800,911);

DELETE FROM `creature_questrelation` WHERE `id`=14444;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(14444,910),
(14444,911),
(14444,1800),
(14444,925),
(14444,915),
(14444,5502);

DELETE FROM `creature_involvedrelation` WHERE `id`=14444;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(14444,925),
(14444,172),
(14444,910),
(14444,911),
(14444,1800),
(14444,915);

-- Set conditions for quests of Human Orphan. Set quest end and quest start relations for Human Orphan
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(558,4822);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,558,8,1687,'Accept quest 558 - Quest 1687 needs to be rewarded'),
(19,558,8,1558,'Accept quest 558 - Quest 1558 needs to be rewarded'),
(19,558,8,1479,'Accept quest 558 - Quest 1479 needs to be rewarded'),
(19,4822,8,1687,'Accept quest 4822 - Quest 1687 needs to be rewarded'),
(19,4822,8,1558,'Accept quest 4822 - Quest 1558 needs to be rewarded'),
(19,4822,8,1479,'Accept quest 4822 - Quest 1479 needs to be rewarded'),
(20,558,8,1687,'Show quest mark 558 - Quest 1687 needs to be rewarded'),
(20,558,8,1558,'Show quest mark 558 - Quest 1558 needs to be rewarded'),
(20,558,8,1479,'Show quest mark 558 - Quest 1479 needs to be rewarded'),
(20,4822,8,1687,'Show quest mark 4822 - Quest 1687 needs to be rewarded'),
(20,4822,8,1558,'Show quest mark 4822 - Quest 1558 needs to be rewarded'),
(20,4822,8,1479,'Show quest mark 4822 - Quest 1479 needs to be rewarded');

UPDATE `quest_template` SET `NextQuestId`=171,`ExclusiveGroup`=-558,`PrevQuestId`=0 WHERE `Id` IN(558,4822);
UPDATE `quest_template` SET `RequiredRaces`=1101 WHERE `Id` IN(558,4822,1687,1558,1479,171);
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id` IN(1687,1558,1479);

DELETE FROM `creature_questrelation` WHERE `id`=14305;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(14305,171),
(14305,558),
(14305,1687),
(14305,1479),
(14305,1558),
(14305,4822);

DELETE FROM `creature_involvedrelation` WHERE `id`=14305;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(14305,1468),
(14305,558),
(14305,1687),
(14305,1479),
(14305,1558),
(14305,4822);

-- Set conditions for quests of Oracle Orphan. Set quest end and quest start relations for Human Orphan. Add reward for last quest.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(13954,13956);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,13954,8,13929,'Accept quest 13954 - Quest 13929 needs to be rewarded'),
(19,13954,8,13933,'Accept quest 13954 - Quest 13933 needs to be rewarded'),
(19,13954,8,13950,'Accept quest 13954 - Quest 13950 needs to be rewarded'),
(19,13956,8,13929,'Accept quest 13956 - Quest 13929 needs to be rewarded'),
(19,13956,8,13933,'Accept quest 13956 - Quest 13933 needs to be rewarded'),
(19,13956,8,13950,'Accept quest 13956 - Quest 13950 needs to be rewarded'),
(20,13954,8,13929,'Show quest mark 13954 - Quest 13929 needs to be rewarded'),
(20,13954,8,13933,'Show quest mark 13954 - Quest 13933 needs to be rewarded'),
(20,13954,8,13950,'Show quest mark 13954 - Quest 13950 needs to be rewarded'),
(20,13956,8,13929,'Show quest mark 13956 - Quest 13929 needs to be rewarded'),
(20,13956,8,13933,'Show quest mark 13956 - Quest 13933 needs to be rewarded'),
(20,13956,8,13950,'Show quest mark 13956 - Quest 13950 needs to be rewarded');

UPDATE `quest_template` SET `NextQuestId`=13937,`ExclusiveGroup`=-13954 WHERE `Id` IN(13954,13956);
UPDATE `quest_template` SET `PrevQuestId`=13937, `RewMailTemplateId`=269 WHERE `Id`=13959;

DELETE FROM `mail_loot_template` WHERE `entry`=269;
INSERT INTO `mail_loot_template`(`entry`,`item`,`ChanceOrQuestChance`) VALUES
(269,46545,100);

DELETE FROM `creature_questrelation` WHERE `id`=33533;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(33533,13929),
(33533,13933),
(33533,13950),
(33533,13954),
(33533,13956),
(33533,13937),
(33533,13959);

DELETE FROM `creature_involvedrelation` WHERE `id`=33533;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(33533,13929),
(33533,13933),
(33533,13950),
(33533,13954),
(33533,13956),
(33533,13937),
(33533,13926);

-- Add Small Paper Zeppelin items to event offers of Clockwork Assistant and Jepetto Joybuzz. Change quest requirements
DELETE `game_event_npc_vendor` FROM `game_event_npc_vendor` INNER JOIN `creature` ON `game_event_npc_vendor`.`guid`=`creature`.`guid` WHERE `id` IN(29478,29716);
INSERT INTO `game_event_npc_vendor`(`eventEntry`,`guid`,`item`) SELECT 10,`guid`,46693 FROM `creature` WHERE `id` IN(29478,29716);

UPDATE `quest_template` SET `ReqCreatureOrGOId1`=33533, `ReqCreatureOrGOCount1`=1, `ReqSpellCast1`=65357 WHERE `Id`=13937;
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=33532, `ReqCreatureOrGOCount1`=1, `ReqSpellCast1`=65357 WHERE `Id`=13938;

-- Spawn Playmate and add script
UPDATE `creature_template` SET `ScriptName`='npc_winterfin_playmate' WHERE `entry`=34489;

DELETE FROM `creature` WHERE `guid`=3019823;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(3019823,34489,571,4382.502,6066.199,0.724562,3.571894);

DELETE FROM `game_event_creature` WHERE `guid`=3019823;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019823);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1998866 AND -1998862;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998862,'Look!','Schau!','npc_children_week_winterfin'),
(-1998863,'Wanna see what I can do?','Möchtet ihr sehen was ich kann?','npc_children_week_winterfin'),
(-1998864,'We can dance too!','Wir können auch tanzen!','npc_children_week_winterfin'),
(-1998865,'Now dance together!','Tanzt zusammen!','npc_children_week_winterfin'),
(-1998866,'We made a new friend!','Wir haben einen neuen Freund gewonnen!','npc_children_week_winterfin');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=4382,`PointY`=6066 WHERE `Id`=13950;

DELETE FROM `quest_poi` WHERE `questId`=13950;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13950,16,571,486,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13950;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13950,4382,6066);

-- Add poi and spawn npc
UPDATE `creature_template` SET `ScriptName`='npc_snowfall_glade_playmate' WHERE `entry`=34490;

DELETE FROM `creature` WHERE `guid`=3019844;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(3019844,34490,571,3325.193,1026.451,138.1712,2.062184);
DELETE FROM `game_event_creature` WHERE `guid`=3019844;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019844);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1998895 AND -1998891;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998891,'Look!','Schau!','npc_snowfall_glade_playmate'),
(-1998892,'Better watch out!','Pass lieber auf!','npc_snowfall_glade_playmate'),
(-1998893,'Got you good!','Hab dich!','npc_snowfall_glade_playmate'),
(-1998894,'Got you back!','Ich dich auch!','npc_snowfall_glade_playmate'),
(-1998895,'Good snowball fight!','Gute Schneeballschlacht!','npc_snowfall_glade_playmate');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=3325,`PointY`=1026 WHERE `Id`=13951;

DELETE FROM `quest_poi` WHERE `questId`=13951;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13951,16,571,488,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13951;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13951,3325,1026);

-- Assign script and add texts for Soo Roo
UPDATE `creature_template` SET `ScriptName`='npc_high_oracle_soo_roo' WHERE `entry`=34386;

DELETE FROM `creature` WHERE `guid`=3019824;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(3019824,34386,571,4120.996,-329.486,121.443817,0.299253);

DELETE FROM `game_event_creature` WHERE `guid`=3019824;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019824);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1998869 AND -1998867;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998867,"Look! Is that us? We think it's us. A bit older, maybe?","Schau! Sind das wir? Wir denken, wir sind es. Ein wenig älter vielleicht.",'npc_high_oracle_soo_roo'),
(-1998868,"We remember this visit, yes we do. Never forget what you learn from your new friend, little Roo. You got great future ahead.","Wir erinnern uns an diesen Besuch. Vergesse niemals, was du von deinem neuen Freund lernst, kleiner Roo. Du hast eine großartige Zukunft vor dir.",'npc_high_oracle_soo_roo'),
(-1998869,"Looks like we blessed by Great Ones! Shrines give magic, make us high-oracle someday? Maybe?","Schaut aus, als sein wir von dem Großen gesegnet! Heiligtümer geben Magie, machen uns eines Tages zu einem Hochorakel? Vielleicht?",'npc_high_oracle_soo_roo');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=4121,`PointY`=-329 WHERE `entry`=13933;

DELETE FROM `quest_poi` WHERE `questId`=13933;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13933,16,571,488,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13933;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13933,4121,-329);

-- Spawn npc and add POIs and script
UPDATE `creature_template` SET `ScriptName`='npc_elder_kekek' WHERE `entry`=34387;

DELETE FROM `creature` WHERE `guid`=3019845;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(3019845,34387,571,4181.482,-461.453,120.728,1.398097);

DELETE FROM `game_event_creature` WHERE `guid`=3019845;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019845);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1998898 AND -1998896;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998896,"Look! That must be Kekek as a mighty warrior! See? What Kekek tell you?","Schau! Das muss Kekek als mächtiger Krieger sein! Siehst du? Was erzählt Kekek dir?",'npc_elder_kekek'),
(-1998897,"No worry, Kekek. You grow up, be strong for Frenzyheart. You lead people back to old home, where there no big-tongue babies.","Keine Sorge, Kekek. Du wirst auch groß, sei stark für die Wildherzen. Du leitest das Volk zurück zur alten Heimat, wo keine Großzungenbabies sind.",'npc_elder_kekek'),
(-1998898,"Hmm... that Kekek very old. Must be elder, leader of Frenzyheart. This good. Kekek have good future as warrior and leader. Kekek very happy you bring him here. Orphan-lady never do that for Kekek.","Hmm... dieser Kekek sein sehr alt. Muss Ältester sein, Anführer der Wildherzen. Das ist gut. Kekek hat eine große Zukunft als Krieger und Anführer. Kekek ist sehr glücklich, dass du ihn hier her bringst. Die Waisenmatrone hat das nie getan.",'npc_elder_kekek');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=4181,`PointY`=-461 WHERE `Id`=13934;

DELETE FROM `quest_poi` WHERE `questId`=13934;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13934,16,571,488,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13934;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13934,4181,-461);

-- Assign script and add texts for The Etymidian
DELETE FROM `creature_template` WHERE `entry`=1010595;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010595,20570,11686,"Northrend Children\'s Week Etymidian Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_etymidian_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010595;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010595,"Nordend Kinderwoche Etymidian Trigger");

DELETE FROM `creature` WHERE `guid`=3019840;
INSERT INTO `creature`(`guid`,`id`,`phaseMask`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019840,1010595,3,1,-6193.86,-1219.55,-160.768);

DELETE FROM `game_event_creature` WHERE `guid`=3019840;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019840);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1998873 AND -1998870;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998870,"Wow! A real Great One? We don't even think Soo-say has met a real Great One!","Wow! Ein echter Riese? Wir glauben, nicht einmal Soo-say hat je einen echten Riesen getroffen!",'npc_cw_etymidian_trigger'),
(-1998871,"Um, hello, Mr. Great One. We are honored to meet you.","Um, hallo Herr Riese. Es ist uns eine Ehre, Euch zu treffen.",'npc_cw_etymidian_trigger'),
(-1998872,"Maybe you're asleep, Mr. Great One? We stand. Must be hard working being Great One, collecting all the shinies we leave for you.","Wahrscheinlich schlaft Ihr, Herr Riese? Wir verstehen. Es muss harte Arbeit sein, all die Schätze zu sammeln, die wir Euch überlassen.",'npc_cw_etymidian_trigger'),
(-1998873,"We brought you a gift, Great One. Maybe you see it when you wake up. Maybe you remember we came to see you, oki?","Wir haben Euch ein Geschenk gebracht, Riese. Vielleicht bemerkt Ihr es, wenn Ihr aufwacht. Vielleicht erinnert Ihr Euch daran, dass wir kamen um Euch zu sehen, oki?",'npc_cw_etymidian_trigger');

UPDATE `quest_template` SET `PointMapId`=1,`PointX`=-6193,`PointY`=-1223 WHERE `Id`=13956;

DELETE FROM `quest_poi` WHERE `questId`=13956;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13956,16,1,201,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13956;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13956,-6193,-1223);

DELETE FROM `gameobject_template` WHERE `entry`=411510;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `size`, `data1`, `data6`) VALUES 
(411510,5,2973,'Gift for the Great One',0.5,0,0);

DELETE FROM `locales_gameobject` WHERE `entry`=411510;
INSERT INTO `locales_gameobject`(`entry`,`name_loc3`) VALUES
(411510,'Geschenk für den Großen');

DELETE FROM `gameobject` WHERE `guid`=2026630;
INSERT INTO `gameobject`(`guid`,`id`,`map`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`) VALUES
(2026630,411510,1,2,-6193.83,-1223.08,-160.876,1.5234,0,0,0.690154,0.723663);

DELETE FROM `game_event_gameobject` WHERE `guid`=2026630;
INSERT INTO `game_event_gameobject`(`eventEntry`,`guid`) VALUES
(10,2026630);

-- change gold loot
UPDATE `item_template` SET `minMoneyLoot` = 50000 WHERE `entry` = 23022;
UPDATE `item_template` SET `maxMoneyLoot` = 50000 WHERE `entry` = 23022;

-- Assign script and add texts for The Biggest Tree Ever!
DELETE FROM `creature_template` WHERE `entry`=1010587;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010587,20570,11686,"Northrend Children\'s Week Biggest Tree Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_the_biggest_tree_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010587;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010587,"Nordend Kinderwoche Größter Baum Trigger");

DELETE FROM `creature` WHERE `guid`=3019825;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(3019825,1010587,571,4022.666,-3777.682,115.443588,4.857019);

DELETE FROM `game_event_creature` WHERE `guid`=3019825;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019825);

DELETE FROM `script_texts` WHERE `entry`=-1998874;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998874,"We here! Only, if this is world tree, how come it broke when they tried to put whole world in?","Wir sind da! Nur, wenn das der Weltenbaum ist, wie kommt es, dass er kaputt ging, als sie versuchten die ganze Welt reinzustecken?",'npc_the_biggest_tree_trigger');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=4022,`PointY`=-3777 WHERE `Id`=13929;

DELETE FROM `quest_poi` WHERE `questId`=13929;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13929,16,571,490,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13929;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13929,4022,-3777);

-- Add poi, create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010597;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010597,20570,11686,"Northrend Children\'s Grizzlemaw Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_grizzlemaw_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010597;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010597,"Nordend Kinderwoche Grauschlund Trigger");

DELETE FROM `creature` WHERE `guid` IN(3019842,3019843,3106167);
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019842,1010597,571,4068.82,-3811,223.4),
(3019843,1010597,571,4073.2,-3734.354,222.6634),
(3106167,1010597,571,3923.109,-3763.967,165.362);

DELETE FROM `game_event_creature` WHERE `guid` IN(3019842,3019843,3106167);
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019842),
(10,3019843),
(10,3106167);

DELETE FROM `script_texts` WHERE `entry`=-1998890;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998890,"You think maybe one day, Kekek lead Frenzyheart home, like bear-men fight to get tree-city back? Kekek want own home, not city with purple men, not jungle with big-tongues.","Denkt ihr Kekek könnte die Wildherzen eines Tages hierher leiten um die Baumstadt zurückzuerobern? Kekek möchte ein eigenes Heim, keine Stadt mit lilanen Leuten, keinen Dschungel mit Großzungen.",'npc_the_biggest_tree_trigger');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=4071,`PointY`=-3773 WHERE `entry`=13930;

DELETE FROM `quest_poi` WHERE `questId`=13930;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13930,16,571,490,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13930;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13930,4071,-3773);

-- Create scripted trigger and spawn him, add script texts and fix poi
DELETE FROM `creature_template` WHERE `entry`=1010594;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010594,20570,11686,"Northrend Children\'s Week Alexstrasza Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_alexstrasza_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010594;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010594,"Nordend Kinderwoche Alexstrasza Trigger");

DELETE FROM `creature` WHERE `guid`=3019839;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019839,1010594,571,3531.02,271.403,342.804);

DELETE FROM `game_event_creature` WHERE `guid`=3019839;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019839);

DELETE FROM `script_texts` WHERE (`entry` BETWEEN -1998879 AND -1998875) OR (`entry` BETWEEN -1998889 AND -1998885);
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998875,"So that's the queen of the dragons? Hmm... we thought she'd be bigger. Yes, we did.","Das ist also die Königin der Drachen?",'npc_cw_alexstrasza_trigger'),
(-1998876,"How come she doesn't look like the other dragons? could she turn into a big ol' dragon if she wanted to?","Wie kommt es, dass sie nicht aussieht wie die anderen Drachen? Könnte sie sich in einen großen alten Drachen verwandeln, wenn sie wollte?",'npc_cw_alexstrasza_trigger'),
(-1998877,"Um... Your Majesty, would you turn into a dragon for us?","Um... Eure Majestät, würdet ihr euch in einen Drachen verwandeln für uns?",'npc_cw_alexstrasza_trigger'),
(-1998878,"If I was in my dragon form, there wouldn't be any room for anyone else, little one.","Wenn ich in meiner Drachenform wäre, würde hier kein Platz für jemand anders mehr sein, Kleiner.",'npc_cw_alexstrasza_trigger'),
(-1998879,"Oki... How about now?","Oki... und jetzt?",'npc_cw_alexstrasza_trigger'),
(-1998885,"Kekek thought we go see dragon queen. This just some elf-lady with funny horns.","Kekek dachte wir sehen die Drachenkönigin. Das ist nur eine Elfendame mit lustigen Hörnern.",'npc_cw_alexstrasza_trigger'),
(-1998886,"Rest assured, Kekek, she is the queen of the dragons. We often take the forms of smaller beings when we work with them.","Seid sicher, sie ist die Königin der Drachen. Wir nehmen oft die Gestalt kleinerer Wesen an, wenn wir mit ihnen arbeiten.",'npc_cw_alexstrasza_trigger'),
(-1998887,"But why? Dragons big and powerful. Elf-lady weak. Kekek want to see dragon queen's real form.","Aber warum? Drachen groß und machtvoll. Elfendame schwach. Kekek möchte die richtige Form der Drachenkönigin sehen.",'npc_cw_alexstrasza_trigger'),
(-1998888,"If I was in my dragon form, there wouldn't be any room for anyone else, little one.","Wenn ich in meiner Drachenform wäre, würde hier kein Platz für jemand anders mehr sein, Kleiner.",'npc_cw_alexstrasza_trigger'),
(-1998889,"Oh! Now Kekek understand. Not want to be crushed by big dragon-lady. Maybe come back sometime when not so crowded. Nice to meet you, dragon-lady.","Oh! Jetzt versteht Kekek. Möchte nicht von der großen Drachendame erdrückt werden. Vielleicht kommt zurück wenn nicht so überfüllt. Schön Sie getroffen zu haben, Drachenkönigin.",'npc_cw_alexstrasza_trigger');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=3530,`PointY`=271 WHERE `entry` IN(13954,13955);

DELETE FROM `quest_poi` WHERE `questId` IN(13954,13955);
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13954,16,571,488,3),
(13955,16,571,488,3);

DELETE FROM `quest_poi_points` WHERE `questid` IN(13954,13955);
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13954,3530,271),
(13955,3530,271);

-- Create scripted trigger and spawn him, add script texts and fix poi
DELETE FROM `creature_template` WHERE `entry`=1010596;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010596,20570,11686,"Northrend Children\'s Week Nesingwary Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_nesingwary_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010596;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010596,"Nordend Kinderwoche Nesingwary Trigger");

DELETE FROM `creature` WHERE `guid`=3019841;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019841,1010596,571,5584.49,5748.84,-71.9047);

DELETE FROM `game_event_creature` WHERE `guid`=3019841;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019841);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1998884 AND -1998880;
INSERT INTO `script_texts`(`entry`,`content_default`,`content_loc3`,`comment`) VALUES
(-1998880,"Wow. At last, Kekek get to meet Hemet Nesingwary!","Wow. Jetzt trifft Kekek doch noch Hemet Nesingwary!",'npc_cw_nesingwary_trigger'),
(-1998881,"Even Frenzyheart know all about you after you come to Sholazar. Maybe you teach Kekek your tricks?","Sogar die Wildherzen wissen alles über Euch nachdem Ihr nach Sholazar gekommen seid. Vielleicht mögt Ihr Kekek ja eure Tricks lehren?",'npc_cw_nesingwary_trigger'),
(-1998882,"Well, lad, you can start by readin' The Green Hills of Stranglethorn. Then, maybe you can join me on one of my safaris. What do you say?","Nun, Bursche, wie wäre es, wenn du erst einmal die grünen Hügel des Schlingendorntals liest? Vielleicht kannst du mich dann auf einer meiner Safaris begleiten. Was sagst du?",'npc_cw_nesingwary_trigger'),
(-1998883,"Not sure how reading helps. Kekek can't read anyway, but if Hemet Nesingwary say, Kekek try.","Weiß nicht wie Lesen hilft. Kekek kann sowieso nicht lesen, aber wenn Hemet Nesingwary sagt, versucht es Kekek.",'npc_cw_nesingwary_trigger'),
(-1998884,"Maybe give up and throw book at animals, but try.","Vielleicht aufgeben und Buch auf Tiere werfen, aber versuchen.",'npc_cw_nesingwary_trigger');

UPDATE `quest_template` SET `PointMapId`=571,`PointX`=5584,`PointY`=5748 WHERE `Id`=13957;

DELETE FROM `quest_poi` WHERE `questId`=13957;
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13957,16,571,493,3);

DELETE FROM `quest_poi_points` WHERE `questid`=13957;
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13957,5584,5748);

-- Update queesttemplate for A Trip to the Dark Portal to be completed with areatriggers
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id`=10951;
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id`=10952;

-- Add gossip texts for Orphan Matron Aria and correct source item things for quests for getting an Orphan of the Oracle or Orphan of the Wolvar
UPDATE `quest_template` SET `SrcItemId`=0, `SrcItemCount`=0 WHERE `Id` IN(13926,13927);

DELETE FROM `npc_text` WHERE `ID` IN(2002010,2002011);
INSERT INTO `npc_text`(`ID`,`text0_0`) VALUES
(2002010,'Are you sure, you want to take care of an Orphan of the Oracles?'),
(2002011,'Are you sure, you want to take care of an Orphan of the Wolvar?');

DELETE FROM `locales_npc_text` WHERE `entry` IN(2002010,2002011);
INSERT INTO `locales_npc_text`(`entry`,`Text0_0_loc3`) VALUES
(2002010,'Seid ihr sicher, dass ihr die Verantwortung für ein Waisenkind der Orakel übernehmen wollt?'),
(2002011,'Seid ihr sicher, dass ihr die Verantwortung für ein Waisenkind der Wolvar übernehmen wollt?');

-- Get low... to the window, to the wall! *sing*. Joke. The amount of height is too damn high in this guy :O
UPDATE `creature` SET `position_z`=-302.919 WHERE `guid`=84434 AND `id`=17538;


-- Create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010588;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010588,20570,11686,"Azeroth Children\'s Week Stonewrought Dam Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_area_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010588;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010588,"Azeroth Kinderwoche Steinwerkdamm Trigger");

DELETE FROM `creature` WHERE `guid`=3019833;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019833,1010588,0,-4754.681,-3313.454,310.3);

DELETE FROM `game_event_creature` WHERE `guid`=3019833;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019833);

-- Create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010589;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010589,20570,11686,"Azeroth Children\'s Week Bough of the Eternals Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_area_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010589;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010589,"Azeroth Kinderwoche Baum der Ewigen Trigger");

DELETE FROM `creature` WHERE `guid`=3019834;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019834,1010589,1,9933,2500,1318);

UPDATE `quest_poi_points` SET `x`=9933,`y`=2500 WHERE `questId`=1479 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019834;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019834);

-- Create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010590;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010590,20570,11686,"Azeroth Children\'s Week Gateway to the Frontier Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_area_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010590;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010590,"Azeroth Kinderwoche Tor zur Grenze Trigger");

DELETE FROM `creature` WHERE `guid`=3019835;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019835,1010590,1,1260.812,-2223.765,92.1);

UPDATE `quest_poi_points` SET `x`=1260.812,`y`=-2223.765 WHERE `questId`=911 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019835;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019835);

-- Create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010591;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010591,20570,11686,"Azeroth Children\'s Week Down at the Docks Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_area_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010591;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010591,"Azeroth Kinderwoche Unten an den Docks Trigger");

DELETE FROM `creature` WHERE `guid`=3019836;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019836,1010591,1,-998.183,-3822.07,5.2954);

UPDATE `quest_poi_points` SET `x`=-998.183,`y`=-3822.07 WHERE `questId`=910 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019836;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019836);

-- Create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010592;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010592,20570,11686,"Azeroth Children\'s Week Spooky Lighthouse Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_area_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010592;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010592,"Azeroth Kinderwoche Gruseliger Leuchtturm Trigger");

DELETE FROM `creature` WHERE `guid`=3019837;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019837,1010592,0,-11400.211,1944.599,10.112);

UPDATE `quest_poi_points` SET `x`=-11400.211,`y`=1944.599 WHERE `questId`=1687 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019837;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019837);

-- Create scripted trigger and spawn him
DELETE FROM `creature_template` WHERE `entry`=1010593;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `faction_A`, `faction_H`, `mindmg`, `maxdmg`, `attackpower`, `unit_class`, `dynamicflags`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `InhabitType`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(1010593,20570,11686,"Azeroth Children\'s Week Undercity Trigger",35,35,2,2,24,1,8,1,1,44,10,7,128,'npc_cw_area_trigger',12340);

DELETE FROM `locales_creature` WHERE `entry`=1010593;
INSERT INTO `locales_creature`(`entry`,`name_loc3`) VALUES
(1010593,"Azeroth Kinderwoche Unterstadt Trigger");

DELETE FROM `creature` WHERE `guid`=3019831;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019831,1010593,0,1642.018,239.69847,62.5924);

UPDATE `quest_poi_points` SET `x`=1642,`y`=239 WHERE `questId`=1800 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019831;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019831);

-- Add script and fix quest
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22872;

DELETE `game_event_creature` FROM `game_event_creature` INNER JOIN `creature` ON `creature`.`guid`=`game_event_creature`.`guid` WHERE `id`=22872;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) SELECT 10,`guid` FROM `creature` WHERE `id`=22872;

UPDATE `creature` SET `position_x`=-8531.8125,`position_y`=-4400.425,`position_z`=-216.9644 WHERE `guid`=23099 AND `id`=22872;

-- Add script and fix quest
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry` IN(22905,22851);

DELETE `game_event_creature` FROM `game_event_creature` INNER JOIN `creature` ON `creature`.`guid`=`game_event_creature`.`guid` WHERE `id` IN(22905,22851);
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) SELECT 10,`guid` FROM `creature` WHERE `id` IN(22905,22851);

-- Spawn trigger and update template
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22838;

DELETE FROM `creature` WHERE `guid`=3019827;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(3019827,22838,530,-2075.759,8559.336,23.027,4.857019);

UPDATE `quest_poi_points` SET `x`=-2075.759,`y`=8559.336 WHERE `questId`=10954 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019827;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019827);

-- Spawn trigger and update template
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22866;

DELETE FROM `creature` WHERE `guid`=3019838;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019838,22866,530,9506.086,-7329.313,14.397272);

UPDATE `quest_poi_points` SET `x`=9506,`y`=-7329 WHERE `questId`=11975 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019838;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019838);

-- Spawn trigger and update template
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22831;

DELETE FROM `creature` WHERE `guid`=3019828;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019828,22831,530,-3320.860,4925.095,-101.1);

UPDATE `quest_poi_points` SET `x`=-3320.860,`y`=4925.095 WHERE `questId`=10950 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019828;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019828);

-- Spawn trigger and update template
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22829;

DELETE FROM `creature` WHERE `guid`=3019829;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019829,22829,530,203.587,8550.11,22.3256);

UPDATE `quest_poi_points` SET `x`=203.587,`y`=8550.11 WHERE `questId`=10945 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019829;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019829);

-- Spawn trigger and update template
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22839;

DELETE FROM `creature` WHERE `guid`=3019830;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019830,22839,530,-781.294,6943.52,33.3344);

UPDATE `quest_poi_points` SET `x`=-781.294,`y`=6943.52 WHERE `questId`=10953 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019830;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019830);

-- Spawn trigger and update template
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=128,`unit_flags`=0,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry`=22833;

DELETE FROM `creature` WHERE `guid`=3019832;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(3019832,22833,530,-248,956,62.592);

UPDATE `quest_poi_points` SET `x`=-248,`y`=956 WHERE `questId`=10952 AND `id`=0 AND `idx`=0;

DELETE FROM `game_event_creature` WHERE `guid`=3019832;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) VALUES
(10,3019832);

-- Start time
DELETE FROM `game_event` WHERE `eventEntry`=10;
INSERT INTO `game_event`(`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES 
(10,'2012-04-29 00:00:00','2021-05-02 00:00:00',525600,10080,201,'Kinderwoche',0);

-- Set holiday requirement for whistles
UPDATE `item_template` SET `HolidayId`=201 WHERE `entry` IN(46396,46397,31880,31881,18598,18597);

-- Avoid premature completion of the main achievement for those who did it already last year
DELETE FROM disables WHERE sourceType = 4 AND entry IN (6663,6668,6665,6667,6672,6673,12899,12901);
INSERT INTO disables (sourceType, entry, comment) VALUES
(4, 6663, "Childrens Week - Avoid premature completion"),
(4, 6668, "Childrens Week - Avoid premature completion"),
(4, 6665, "Childrens Week - Avoid premature completion"),
(4, 6667, "Childrens Week - Avoid premature completion"),
(4, 6672, "Childrens Week - Avoid premature completion"),
(4, 6673, "Childrens Week - Avoid premature completion"),
(4, 12899, "Childrens Week - Avoid premature completion"),
(4, 12901, "Childrens Week - Avoid premature completion");

-- Assign usage of whistles to childrens week
DELETE FROM `conditions` where SourceEntry IN ( 23012,23013,39478,39479,65352,65353);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ErrorTextId`, `Comment`) VALUES 
(17, 0, 23012, 0, 12, 10, 0, "Orphan Whislte only while children's week"),
(17, 0, 23013, 0, 12, 10, 0, "Orphan Whislte only while children's week"),
(17, 0, 39478, 0, 12, 10, 0, "Orphan Whislte only while children's week"),
(17, 0, 39479, 0, 12, 10, 0, "Orphan Whislte only while children's week"),
(17, 0, 65352, 0, 12, 10, 0, "Orphan Whislte only while children's week"),
(17, 0, 65353, 0, 12, 10, 0, "Orphan Whislte only while children's week");
