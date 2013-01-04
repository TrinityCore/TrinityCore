DELETE FROM `creature` WHERE `id` IN (53520,53375,53698,53693,53487,53691,52530,53369,53680,53734,53896,53900) AND `map`=720;
DELETE FROM `gameobject` WHERE `id` IN (209036,208966,201722,209035) AND `map`=720;

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry` IN (53723,53154,53789,53792,53787,53788);

UPDATE `creature_template` SET `minlevel`=88,`maxlevel`=88,`exp`=3,`faction_A`=16,`faction_H`=16,`speed_walk`=3.2,`speed_run`=2,`baseattacktime`=2000,`rangeattacktime`=2000,`unit_class`=2,`unit_flags`=0x2008140,`unit_flags2`=0x8000800,`VehicleId`=1673,`HoverHeight`=14,`mana_mod_extra`=1.72414 WHERE `entry` IN (52530,54044,54045,54046);
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction_A`=16,`faction_H`=16,`speed_walk`=3.2,`speed_run`=2,`baseattacktime`=2000,`rangeattacktime`=2000,`unit_flags`=0x8000,`unit_flags2`=0x800,`VehicleId`=1695 WHERE `entry` IN (54056,54057); -- Blazing Monstrosity
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction_A`=16,`faction_H`=16,`speed_walk`=1,`speed_run`=1,`baseattacktime`=2000,`rangeattacktime`=2000,`unit_flags`=0x8000,`unit_flags2`=0x8800 WHERE `entry` IN (53795,54059); -- Egg Pile
UPDATE `creature_template` SET `spell1`=100076,`spell2`=100080,`spell3`=100078,`spell4`=100082 WHERE `entry`=53789;
UPDATE `creature_template` SET `spell1`=100090,`spell2`=100089,`spell3`=100091,`spell4`=100092 WHERE `entry`=53792;
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`exp`=3,`faction_A`=14,`faction_H`=14,`speed_walk`=1.2,`speed_run`=0.428571,`unit_flags`=0x2000000,`unit_flags2`=0x2000800 WHERE `entry` IN (53787,53788); -- Molten Barrage
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`exp`=3,`faction_A`=16,`faction_H`=16,`speed_walk`=3.2,`speed_run`=2,`unit_flags`=0x8000,`unit_flags2`=0x800,`baseattacktime`=2000,`rangeattacktime`=2000 WHERE `entry` IN (53794,54058); -- Smouldering Hatchling
UPDATE `creature_template` SET `minlevel`=86,`maxlevel`=86,`exp`=3,`faction_A`=16,`faction_H`=16,`speed_walk`=1,`speed_run`=1.14286,`unit_flags`=0,`unit_flags2`=0x800,`baseattacktime`=2000,`rangeattacktime`=2000,`unit_class`=8,`dynamicflags`=0 WHERE `entry` IN (53793,53973); -- Harbinger of Flame

UPDATE `creature_template` SET `difficulty_entry_1`=54044,`difficulty_entry_2`=54045,`difficulty_entry_3`=54046 WHERE `entry`=52530; -- Alysrazor
UPDATE `creature_template` SET `difficulty_entry_1`=54056 WHERE `entry`=53786; -- Blazing Monstrosity
UPDATE `creature_template` SET `difficulty_entry_1`=54057 WHERE `entry`=53791; -- Blazing Monstrosity
UPDATE `creature_template` SET `difficulty_entry_1`=54059 WHERE `entry`=53795; -- Egg Pile
UPDATE `creature_template` SET `difficulty_entry_1`=54058 WHERE `entry`=53794; -- Smouldering Hatchling
UPDATE `creature_template` SET `difficulty_entry_1`=53973 WHERE `entry`=53793; -- Harbinger of Flame

DELETE FROM `creature_template_addon` WHERE `entry` IN (53786,53791,54056,54057,53794,54058,54276,54019,53224,53102,52530,54044,54045,54046,53900,53680,53520,53693,53698);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(53786, 0, 0x0, 0x1, '100712 99480'), -- Blazing Monstrosity - Fire Hawk Smoke Cosmetic, Sleep (Ultra-High Priority)
(53791, 0, 0x0, 0x1, '100712 99480'), -- Blazing Monstrosity - Fire Hawk Smoke Cosmetic, Sleep (Ultra-High Priority)
(54056, 0, 0x0, 0x1, '100712 99480'), -- Blazing Monstrosity - Fire Hawk Smoke Cosmetic, Sleep (Ultra-High Priority)
(54057, 0, 0x0, 0x1, '100712 99480'), -- Blazing Monstrosity - Fire Hawk Smoke Cosmetic, Sleep (Ultra-High Priority)
(53794, 0, 0x0, 0x1, '100712'), -- Smouldering Hatchling - Fire Hawk Smoke Cosmetic
(54058, 0, 0x0, 0x1, '100712'), -- Smouldering Hatchling - Fire Hawk Smoke Cosmetic
(54276, 0, 0x0, 0x1, '101112'), -- Cinderslither Snake - Cinderslither Aura
(54019, 0, 0x0, 0x1, '100556'), -- Captive Druid of the Talon - Smouldering Roots
(53224, 0, 0x0, 0x1, '100743'), -- Flamewaker Taskmaster - Aura of Indomitability
(53102, 0, 0x3000000, 0x1, '100712'), -- Inferno Hawk - Fire Hawk Smoke Cosmetic
(52530, 0, 0x0, 0x1, '100712'), -- Alysrazor - Fire Hawk Smoke Cosmetic
(54044, 0, 0x0, 0x1, '100712'), -- Alysrazor - Fire Hawk Smoke Cosmetic
(54045, 0, 0x0, 0x1, '100712'), -- Alysrazor - Fire Hawk Smoke Cosmetic
(54046, 0, 0x0, 0x1, '100712'), -- Alysrazor - Fire Hawk Smoke Cosmetic
(53900, 0, 0x3000000, 0x1, '100712'), -- Blazing Broodmother - Fire Hawk Smoke Cosmetic
(53680, 0, 0x3000000, 0x1, '100712'), -- Blazing Broodmother - Fire Hawk Smoke Cosmetic
(53520, 0, 0x0, 0x1, '99327'), -- Plump Lava Worm - Fire Worm Cosmetic
(53693, 0, 0x0, 0x1, '99793'), -- Fiery Vortex - Fiery Vortex
(53698, 0, 0x0, 0x1, '99817'); -- Fiery Tornado - Fiery Tornado

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (53786,53791);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(53786,53789,1,'Blazing Monstrosity',5,0),
(53791,53792,1,'Blazing Monstrosity',5,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (53786,53791,53789,53792);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`) VALUES
(53786,98509,1),
(53791,98509,1),
(53789,93970,1),
(53792,93970,1);

DELETE FROM `creature_text` WHERE `entry`=53795;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(53795, 0, 0, 'The Molten Eggs begin to crack and splinter!', 41, 0, 100, 0, 0, 0, 'Molten Egg - EMOTE_CRACKING_EGGS');

-- ScriptNames and conditions
UPDATE `instance_template` SET `script`='instance_firelands' WHERE `map`=720;
UPDATE `creature_template` SET `ScriptName`='npc_harbinger_of_flame' WHERE `entry`=53793;
UPDATE `creature_template` SET `ScriptName`='npc_blazing_monstrosity' WHERE `entry` IN (53786,53791);
UPDATE `creature_template` SET `ScriptName`='npc_molten_barrage' WHERE `entry` IN (53787,53788);
UPDATE `creature_template` SET `ScriptName`='npc_egg_pile' WHERE `entry`=53795;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_alysrazor_cosmetic_egg_xplosion';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_alysrazor_turn_monstrosity';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_alysrazor_aggro_closest';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_alysrazor_fieroblast';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(100099,'spell_alysrazor_cosmetic_egg_xplosion'),
(100076,'spell_alysrazor_turn_monstrosity'),
(100078,'spell_alysrazor_turn_monstrosity'),
(100080,'spell_alysrazor_turn_monstrosity'),
(100082,'spell_alysrazor_turn_monstrosity'),
(100089,'spell_alysrazor_turn_monstrosity'),
(100090,'spell_alysrazor_turn_monstrosity'),
(100091,'spell_alysrazor_turn_monstrosity'),
(100092,'spell_alysrazor_turn_monstrosity'),
(100462,'spell_alysrazor_aggro_closest'),
(100094,'spell_alysrazor_fieroblast'),
(101223,'spell_alysrazor_fieroblast'),
(101294,'spell_alysrazor_fieroblast'),
(101295,'spell_alysrazor_fieroblast'),
(101296,'spell_alysrazor_fieroblast');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (100558,100071,100074,100070,100076,100078,100080,100082,100089,100090,100091,100092);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,100558,0,0,31,0,3,54019,0,0,0,0,'','Sacrifice to the Flame - Captive Druid of the Talon'),
(13,1,100071,0,0,31,0,3,53787,0,0,0,0,'','Molten Barrage'),
(13,1,100074,0,0,31,0,3,53788,0,0,0,0,'','Molten Barrage'),
(13,2,100070,0,0,31,0,3,53786,0,0,0,0,'','Molten Barrage - Blazing Monstrosity'),
(13,2,100070,0,1,31,0,3,53791,0,0,0,0,'','Molten Barrage - Blazing Monstrosity'),
(13,2,100070,0,2,31,0,3,53793,0,0,0,0,'','Molten Barrage - Harbinger of Flame'),
(13,2,100070,0,3,31,0,3,53795,0,0,0,0,'','Molten Barrage - Egg Pile'),
(13,2,100070,0,4,31,0,3,53794,0,0,0,0,'','Molten Barrage - Smouldering Hatchling'),
(13,1,100076,0,0,31,0,3,53787,0,0,0,0,'','Left-Side Smack - Molten Barrage'),
(13,2,100076,0,1,31,0,3,53786,0,0,0,0,'','Left-Side Smack - Blazing Monstrosity'),
(13,1,100078,0,0,31,0,3,53787,0,0,0,0,'','Right-Side Smack - Molten Barrage'),
(13,2,100078,0,1,31,0,3,53786,0,0,0,0,'','Right-Side Smack - Blazing Monstrosity'),
(13,1,100080,0,0,31,0,3,53787,0,0,0,0,'','Head Bonk - Molten Barrage'),
(13,2,100080,0,1,31,0,3,53786,0,0,0,0,'','Head Bonk - Blazing Monstrosity'),
(13,1,100082,0,0,31,0,3,53787,0,0,0,0,'','Tickle - Molten Barrage'),
(13,2,100082,0,1,31,0,3,53786,0,0,0,0,'','Tickle - Blazing Monstrosity'),
(13,1,100089,0,0,31,0,3,53788,0,0,0,0,'','Head Bonk - Molten Barrage'),
(13,2,100089,0,1,31,0,3,53791,0,0,0,0,'','Head Bonk - Blazing Monstrosity'),
(13,1,100090,0,0,31,0,3,53788,0,0,0,0,'','Left-Side Smack - Molten Barrage'),
(13,2,100090,0,1,31,0,3,53791,0,0,0,0,'','Left-Side Smack - Blazing Monstrosity'),
(13,1,100091,0,0,31,0,3,53788,0,0,0,0,'','Right-Side Smack - Molten Barrage'),
(13,2,100091,0,1,31,0,3,53791,0,0,0,0,'','Right-Side Smack - Blazing Monstrosity'),
(13,1,100092,0,0,31,0,3,53788,0,0,0,0,'','Tickle - Molten Barrage'),
(13,2,100092,0,1,31,0,3,53791,0,0,0,0,'','Tickle - Blazing Monstrosity');
