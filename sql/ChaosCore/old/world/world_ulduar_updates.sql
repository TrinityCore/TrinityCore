DELETE FROM `reference_loot_template` WHERE `entry` IN (34125,34126,34127);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- ilvl 219
('34125','45934','0','1','1','1','1'),
('34125','45935','0','1','1','1','1'),
('34125','45936','0','1','1','1','1'),
('34125','45940','0','1','1','1','1'),
('34125','45941','0','1','1','1','1'),
-- 1 elder alive emblems
('34126','40753','100','2','0','1','1'),
('34126','45624','100','2','0','1','1'),
-- 2 elder alive emblems
('34127','40753','100','4','0','1','1'),
('34127','45624','100','4','0','1','1');

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (27078,27081);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- 10 normal
('27078','1','100','1','0','-34125','1'),
('27078','2','100','1','0','-34105','1'),
('27078','4','100','2','0','-34126','1'),
('27078','5','100','4','0','-34127','1'),
('27078','40753','100','1','0','1','1'),
('27078','45087','100','1','0','1','1'),
('27078','45644','0','1','1','1','1'),
('27078','45645','0','1','1','1','1'),
('27078','45646','0','1','1','1','1'),
('27078','46110','100','1','0','1','1'),
-- 10 hard
('27081','1','100','1','0','-34125','1'),
('27081','2','100','1','0','-34105','1'),
('27081','40753','100','1','0','4','4'),
('27081','45624','100','1','0','2','2'),
('27081','45087','100','1','0','1','1'),
('27081','45294','0','1','2','1','1'),
('27081','45644','0','1','1','1','1'),
('27081','45645','0','1','1','1','1'),
('27081','45646','0','1','1','1','1'),
('27081','45788','-100','1','0','1','1'),
('27081','45943','0','1','2','1','1'),
('27081','45945','0','1','2','1','1'),
('27081','45946','0','1','2','1','1'),
('27081','45947','0','1','2','1','1'),
('27081','46110','100','1','0','1','1');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=63322;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13,63322,18,1,0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (63025,64233,63024,64234,63018,65121);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(63024, 'spell_xt002_bomb_select_target'),
(64234, 'spell_xt002_bomb_select_target'),
(63018, 'spell_xt002_bomb_select_target'),
(65121, 'spell_xt002_bomb_select_target');

-- Junk Bot
UPDATE `creature_template` SET `difficulty_entry_1`=34114 WHERE `entry`=33855;
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `dmg_multiplier`=15 WHERE `entry`=34114;

-- Add passive Flag to various Ulduar triggers
UPDATE creature_template SET unit_flags = unit_flags|512 WHERE entry IN (
33054, -- Thorim Trap Bunny
33500, -- Vezax Bunny
33575, -- Channel Stalker Freya
33661, -- Armsweep Stalker Kologarn
34188, -- Razorscale Devouring Flame Stalker
34189, -- Razorscale Devouring Flame Stalker (heroic)
34098, -- Auriaya Seeping Essence Stalker
34174  -- Auriaya Seeping Essence Stalker (heroic)
);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62968,65761,62713);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(62968, 'spell_elder_essence_targeting'),
(65761, 'spell_elder_essence_targeting'),
(62713, 'spell_elder_essence_targeting');

DELETE FROM `conditions` WHERE `SourceEntry`=62834 AND `SourceTypeOrReferenceId`=13 AND `ConditionTypeOrReference`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,62834,18,1,0, 'Boombot Boom - Player target'),
(13,62834,18,1,33343, 'Boombot Boom - Scrapbot target'),
(13,62834,18,1,33344, 'Boombot Boom - Pummeler target'),
(13,62834,18,1,33346, 'Boombot Boom - Boombot target'),
(13,62834,18,1,33329, 'Boombot Boom - Heart of the Deconstructor target'),
(13,62834,18,1,33293, 'Boombot Boom - XT-002 target');

DELETE FROM `conditions` WHERE `SourceEntry`=62711 AND `SourceTypeOrReferenceId`=13 AND `ConditionTypeOrReference`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,62711,18,1,33118, 'Ingis - Grab');

-- set 25N chopper spells
UPDATE `creature_template` SET `spell1`=62974, `spell2`=62286, `spell3`=62299, `spell4`=64660 WHERE `entry`=34045;

-- longer steelforged defender respawn timer (should not be DB spawned at all?)
UPDATE `creature` SET `spawntimesecs`=1800 WHERE `id`=33236;

-- Yogg-Saron emotes
DELETE FROM script_texts WHERE entry IN (-1603342, -1603343, -1603344);	
INSERT INTO script_texts VALUES 	
(33288, -1603342, "Portals open into Yogg-Saron's mind!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 5, 0, 0, "YoggSaron EMOTE_PORTALS"),	
(33288, -1603343, "The Illusion shatters and a path to the central chamber opens!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 5, 0, 0, "YoggSaron EMOTE_OPEN_CHAMBER"),	
(33288, -1603344, "Yogg-Saron prepares to unleash Empowering Shadows!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 5, 0, 0, "YoggSaron EMOTE_EMPOWERING");
	
-- Ulduar Keepers Images	
DELETE FROM `creature` WHERE `id` IN (33213, 33241, 33242, 33244);	
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES	
(33241, 603, 3, 1, 0, 0, 2057.81, -24.0768, 421.532, 3.12904, 604800, 0, 0, 14433075, 0, 0, 0),	
(33242, 603, 3, 1, 0, 0, 2036.81, -73.7053, 411.353, 2.43575, 604800, 0, 0, 14433075, 0, 0, 0),	
(33244, 603, 3, 1, 0, 0, 2036.74, 25.4642, 411.357, 3.81412, 604800, 0, 0, 14433075, 0, 0, 0),	
(33213, 603, 3, 1, 0, 0, 1939.29, -90.6994, 411.357, 1.02595, 604800, 0, 0, 14433075, 0, 0, 0);

-- Remove NON_SELECTABLE from Clockwork Mechanic	
UPDATE creature_template SET unit_flags = unit_flags &~ 33554432 WHERE entry = 34184;
UPDATE creature_template SET unit_flags = unit_flags &~ 33554432 WHERE entry = 34219;

UPDATE `script_texts` SET `sound`=15476 WHERE `entry`=-1603053;
DELETE FROM `gameobject` WHERE `guid` = '42516';
UPDATE `gameobject` SET `spawnMask`=3 WHERE `map`=603;



