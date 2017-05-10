-- The column `spell1` was misused for this NPC. This NPC is undead. He cannot be MCed. The spell 29307 should be cast using SmartAI or by Script.
-- Also, link the zombies chows to the custom ScriptedAI defined in boss_gluth.cpp.
UPDATE `creature_template` SET `spell1`=0, `ScriptName`='npc_zombie_chow' WHERE `entry`=16360;
UPDATE `creature_template` SET `spell1`=0 WHERE `entry`=30303;

-- connect the decimate spell (effect 0) used by Gluth (in both 10 man & 25) to the spell script defined in boss_gluth.cpp.
-- and connect the 2 zombie chow's search spells to a unique spell script used by both.
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gluth_decimate', 'spell_gluth_zombiechow_search');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28374, 'spell_gluth_decimate'),
(54426, 'spell_gluth_decimate'),
(28239, 'spell_gluth_zombiechow_search'),
(28404, 'spell_gluth_zombiechow_search');

-- add the condition to the multi-target insta-kill spell 28404 which is that only zombies are eligible targets to the spell.
-- add a condition to the decimate spell (28374/54426). It's damage component should only affect players and zombies.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry` IN (28374, 28404, 54426);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)  VALUES
(13, 1, 28404, 0, 0, 31, 0, 3, 16360, 0, 0, 0, 0, '', 'Zombie Chow Search targets zombies only'),
(13, 1, 28374, 0, 0, 31, 0, 3, 16360, 0, 0, 0, 0, '', 'Decimate damage should only hit zombie or player'),
(13, 1, 28374, 0, 1, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Decimate damage should only hit zombie or player'),
(13, 1, 54426, 0, 0, 31, 0, 3, 16360, 0, 0, 0, 0, '', 'Decimate damage should only hit zombie or player'),
(13, 1, 54426, 0, 1, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Decimate damage should only hit zombie or player');

-- adds Gluth's 5 emotes into the DB.
DELETE FROM `creature_text` WHERE `entry`=15932 AND `groupid` IN(0,1,2,3,4) AND `id`=0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15932, 0, 0, '%s spots a zombie to devour!', 16, 0, 100, 0, 0, 0, 12242, 2/3, 'Gluth - spots one'),
(15932, 1, 0, '%s decimates all nearby flesh!', 41, 0, 100, 0, 0, 0, 32321, 2/3, 'Gluth - decimate'),
(15932, 2, 0, '%s becomes enraged!', 41, 0, 100, 0, 0, 0, 24144, 2/3, 'Gluth - enrage'),
(15932, 3, 0, '%s devours all nearby zombies!', 16, 0, 100, 0, 0, 0, 12348, 2/3, 'Gluth - devours all'),
(15932, 4, 0, '%s goes into a berserker rage!', 41, 0, 100, 0, 0, 0, 34057, 2/3, 'Gluth - berserker');

-- move zombie chows to summon groups (gets rid of hardcoded spawn coords)
DELETE FROM `creature_summon_groups` WHERE `summonerId`=15932;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(15932,0,1,16360,3270.132,-3169.948,297.5891,5.88176,6,10000),
(15932,0,2,16360,3307.298,-3183.449,297.5891,5.74213,6,10000),
(15932,0,2,16360,3255.708,-3135.677,297.5891,1.86750,6,10000);
