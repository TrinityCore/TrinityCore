DELETE FROM `smart_scripts` WHERE `entryorguid`=28503 AND `source_type`=0 AND `id`>4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2850300 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-98865 AND `source_type`=0;
UPDATE `creature_template` SET `spell1`=54135, `spell2`=54132, `spell3`=54136 WHERE  `entry`=28931;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28503, 0, 5, 6, 62, 0, 100, 0, 9731, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Gossip Option 0 Selected - Store Target'),
(28503, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 85, 52863, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Gossip Option 0 Selected - Cast Drakuru Betrayal Teleport'),
(28503, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 12, 28998, 1, 600000, 0, 0, 0, 8, 0, 0, 0, 6175.246, -2017.655, 590.9613, 2.984513, 'Overlord Drakuru - On Gossip Option 0 Selected - Summon Drakuru');

DELETE FROM `spell_target_position` WHERE `id` IN(52863,57553);
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES 
(52863, 0, 571, 6161.15, -2015.36, 590.878, 6.196, 0), -- Drakuru Betrayal Teleport
(57553, 0, 571, 5875.43, -1981.37, 234.671, 0, 0); -- Escape Voltarus

UPDATE `creature_template` SET `faction`=2082,`unit_flags`=256 WHERE  `entry`=28998; -- Correct Faction (Not 35)

DELETE FROM `creature_template_addon` WHERE `entry`=28998;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(28998, 0, 0x0, 0x1, '58837 54104'); -- 28998 - 58837, 54104

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-52010,54089);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-52010, '-51966', 0,'On Remove Scourge Disguise Expiring - Also Remove Scourge Disguise'),
(54089, '52010', '1', 'On Hit Drop Disguise - Remove Scourge Disguise'); 

DELETE FROM `creature_text` WHERE `entry` =28998;
DELETE FROM `creature_text` WHERE `entry` =28498 AND `groupid`>6;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(28998, 0, 0, 'Behold, mon! We be creatin'' da greatest Scourge army ever seen!', 12, 0, 100, 396, 0, 14023, 'Overlord Drakuru',29441),
(28998, 1, 0, 'These be da first of many! We shall sweep across Zul''Drak like da wind....', 12, 0, 100, 396, 0, 14024, 'Overlord Drakuru',29442),
(28998, 2, 0, 'What treachery is this?! You be payin'' for this deceit with your life, mon!', 12, 0, 100, 0, 0, 14025, 'Overlord Drakuru',29885),
(28998, 3, 0, 'The Scepter of Domination glows brightly! Use it now!', 41, 0, 100, 0, 0, 0, 'Overlord Drakuru',29886),
(28998, 4, 0, 'How could dis be? Da Lich King said he be havin'' great plans for you, mon...', 14, 0, 100, 0, 0, 14027, 'Overlord Drakuru',29917),
(28998, 4, 1, 'Ya done turned your back on destiny, mon. Now you gunna die!', 14, 0, 100, 0, 0, 14029, 'Overlord Drakuru',29919),
(28998, 4, 2, 'Fool! Ya coulda been havin'' great power, mon!', 14, 0, 100, 0, 0, 14026, 'Overlord Drakuru',29916),
(28998, 4, 3, 'Your betrayal not gunna be slowin'' me down none, mon.', 14, 0, 100, 0, 0, 14030, 'Overlord Drakuru',29920),
(28998, 4, 4, 'I shoulda known not to be trustin'' nobody!', 14, 0, 100, 0, 0, 14028, 'Overlord Drakuru',29918),
(28998, 4, 5, 'I never needed ya, mon. I can crush Zul''Drak without ya!', 14, 0, 100, 0, 0, 14031, 'Overlord Drakuru',29921),
(28998, 5, 0, 'ENOUGH!', 14, 0, 100, 22, 0, 14020, 'Overlord Drakuru',29922),
(28998, 6, 0, 'Dis foolish treachery has cost ya your destiny!', 14, 0, 100, 396, 0, 14021, 'Overlord Drakuru',29923),
(28998, 7, 0, 'Master, dis mortal scum be double-crossin'' us. Dey must be made to suffer!', 12, 0, 100, 396, 0, 14022, 'Overlord Drakuru',29969),
(28998, 8, 0, 'Disguise Failing! Avoid Scourge Contact!', 41, 0, 100, 0, 0, 0, 'Overlord Drakuru',28891),
(28498, 7, 0, 'You have failed me, Drakuru!', 12, 0, 100, 396, 0, 14762, 'The Lich King',29986),
(28498, 8, 0, 'It is you who should suffer. Be content that your death is a quick one....', 12, 0, 100, 397, 0, 14763, 'The Lich King',29982),
(28498, 9, 0, 'As for you...', 12, 0, 100, 397, 0, 14764, 'The Lich King',29983),
(28498, 10, 0, 'I spare your insignificant life as a reward for this amusing betrayal. There may yet be a shred of potential in you.', 12, 0, 100, 396, 0, 14765, 'The Lich King',29984),
(28498, 11, 0, 'Be warned...', 12, 0, 100, 396, 0, 14766, 'The Lich King',29989),
(28498, 12, 0, 'When next we meet I shall require much more to justify your life.', 12, 0, 100, 396, 0, 14767, 'The Lich King',29985);

UPDATE `smart_scripts` SET `event_param2`=28498 WHERE  `entryorguid`=28498 AND `source_type`=0 AND `id` IN(1,3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=28498;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 28498, 0, 0, 23, 1, 4196, 0, 0, 0, 0, 0, '', 'The Lich King - Only Run SAI in Drak Tharon Keep'),
(22, 6, 28498, 0, 0, 23, 1, 4314, 0, 0, 0, 0, 0, '', 'The Lich King - Only Run SAI in Voltarus');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(54250,54105);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 54250, 0, 0, 31, 0, 3, 28960, 0, 0, 0, 0, '', 'Drakurus Skull Missile targets Totally Generic Bunny'),
(13, 1, 54105, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Blight Fog Targets Player'),
(13, 1, 54105, 0, 1, 31, 0, 3, 28931, 0, 0, 0, 0, '', 'Blight Fog Targets Blightblood Troll');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(28931,28998,28960,29100);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=202357;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2899800,2899801,2849801,2899802) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(28998,28931,28960,29100) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(202357) AND `source_type`=1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28498 AND `source_type`=0 AND `id`>4;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28960, 0, 0, 1, 8, 0, 100, 0, 54250, 0, 0, 0, 11, 54253, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Totally Generic Bunny (JSB) - On Spell hit (Drakurus Skull Missile) - Cast Spawn Drakurus Skull'),
(28960, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 50, 202357, 120, 0, 0, 0, 0, 8, 0, 0, 0, 6185.989, -2029.698, 590.8779, 0, 'Totally Generic Bunny (JSB) - On Spell hit (Drakurus Skull Missile) - Spawn Drakurus Last Wish'),
(28960, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 51807, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Totally Generic Bunny (JSB) - On Data Set 1 1 - Cast Athas Portal'),
(28960, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 28, 51807, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Totally Generic Bunny (JSB) - On Data Set 2 2 - Remove Aura Athas Portal'),
(29100, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Totally Generic Bunny x8.0 (JSB) - On Data Set 1 1 - Cast Teleport Visual Only'),
(29100, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 11, 53104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Totally Generic Bunny x8.0 (JSB) - On Data Set 2 2 - Cast Scourge Spotlight'),
(29100, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 28, 53104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Totally Generic Bunny x8.0 (JSB) - On Data Set 3 3 - Remove Aura Scourge Spotlight'),
(202357, 1, 0, 0, 62, 0, 100, 0, 11091, 0, 0, 0, 85, 57553, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drakurus Last Wish - On Gossip Select - Invoker Cast Escape Voltarus'),
(28998, 0, 0, 0, 54, 0, 100, 1, 0, 0, 0, 0, 80, 2899800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Just Summoned Run Script'),
(28998, 0, 1, 0, 7, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Evade - Set Unit Flags'),
(28998, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Agro - Disable Combat Movement'),
(28998, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 29100, 0, 200, 0, 0, 0, 0, 'Overlord Drakuru - On Agro - Set Data'),
(28998, 0, 4, 0, 9, 0, 100, 0, 10, 100, 3000, 7000, 11, 54113, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Range - Cast Shadow Bolt'),
(28998, 0, 5, 0, 0, 0, 100, 0, 5000, 10000, 15000, 35000, 11, 54087, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - IC - Cast Throw Blight Crystal'),
(28998, 0, 6, 0, 0, 0, 100, 0, 15000, 25000, 20000, 35000, 1, 4, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - IC - Say'),
(28998, 0, 7, 0, 2, 0, 100, 1, 0, 10, 0, 0, 80, 2899801, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Less than 10% HP - Run script 2'),
(28998, 0, 8, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 2899802, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Data Set - Run Script 3'),
(28998, 0, 9, 10, 1, 0, 100, 0, 90000, 90000, 0, 0, 11, 61492, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - OOC - Cast Despawn Blightblood'),
(28998, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 29100, 0, 200, 0, 0, 0, 0, 'Overlord Drakuru - OOC - Set Data 3 3 on Totally Generic Bunny (JSB)'),
(28998, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - OOC - Despawn'),
(28998, 0, 12, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - On Death - Despawn after 2 seconds'),
(28931, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Data Set 1 1 - Set Unit Flags'),
(28931, 0, 1, 0, 7, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Evade - Set Unit Flags'),
(28931, 0, 2, 0, 8, 0, 100, 0, 61492, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Spellhit (Despawn Blightblood) - Despawn'),
(28931, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Spellhit (Despawn Blightblood) - Despawn'),
(28931, 0, 4, 0, 4, 0, 100, 1, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Agro - Set Phase 2'),
(28931, 0, 5, 0, 8, 0, 100, 1, 53103, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Spellhit (Charm Blightblood Troll) - Set Phase 2'),
(28931, 0, 6, 0, 0, 2, 100, 1, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 29100, 10, 0, 0, 0, 0, 0, 'Blightblood Troll - IC (Phase 2) - Set Data 3 3 on Totally Generic Bunny (JSB)'),
(28931, 0, 7, 0, 1, 2, 100, 1, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 29100, 10, 0, 0, 0, 0, 0, 'Blightblood Troll - OOC (Phase 2) - Set Data 3 3 on Totally Generic Bunny (JSB)'),
(28498, 0, 5, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2849800, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Just Summoned - Start Waypoint'),
(28498, 0, 6, 0, 40, 0, 100, 0, 4, 2849800, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 28998, 0, 0, 0, 0, 0, 0, 'The Lich King - Reached WP4 - Say'),
(28498, 0, 7, 0, 40, 0, 100, 0, 8, 2849800, 0, 0, 80, 2849801, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Reached WP8 - Run Script'),
(28498, 0, 8, 9, 40, 0, 100, 0, 4, 2849801, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 98914, 28960, 0, 0, 0, 0, 0, 'The Lich King - Reached WP4 (Path 2) - Set Data'),
(28498, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Reached WP4 (Path 2) - Despawn'),
(2899800, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Say'),
(2899800, 9, 1, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 29100, 0, 200, 0, 0, 0, 0, 'Overlord Drakuru - Script - Say'),
(2899800, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 12, 28931, 1, 600000, 0, 0, 0, 8, 0, 0, 0, 6184.146, -1970.17, 586.8419, 4.590216, 'Overlord Drakuru - Script - Summon Blightblood Troll 1'),
(2899800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 28931, 1, 600000, 0, 0, 0, 8, 0, 0, 0, 6222.855, -2026.631, 586.8419, 3.001966, 'Overlord Drakuru - Script - Summon Blightblood Troll 2'),
(2899800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 28931, 1, 600000, 0, 0, 0, 8, 0, 0, 0, 6127.512, -2008.651, 586.8419, 6.161012, 'Overlord Drakuru - Script - Summon Blightblood Troll 3'),
(2899800, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 28931, 1, 600000, 0, 0, 0, 8, 0, 0, 0, 6166.278, -2065.312, 586.8419, 1.448623, 'Overlord Drakuru - Script - Summon Blightblood Troll 4'),
(2899800, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Say'),
(2899800, 9, 7, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Say'),
(2899800, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 54089, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Cast Drop Disguise'),
(2899800, 9, 9, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Remove Scourge Disguise from Target'),
(2899800, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Set Unit Flags'),
(2899800, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 28931, 0, 200, 0, 0, 0, 0, 'Overlord Drakuru - Script - Set Data on Blightblood Troll'),
(2899800, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 974, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Set Faction'),
(2899800, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script - Say'),
(2849801, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say'),
(2849801, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say'),
(2849801, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 54236, 0, 0, 0, 0, 0, 19, 28998, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Cast Touch of Death'),
(2849801, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 28998, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Set Orientation'),
(2849801, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Set Orientation'),
(2849801, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say'),
(2849801, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say'),
(2849801, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say'),
(2849801, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say'),
(2849801, 9, 9, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 53, 0, 2849801, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Start WP Path 2'),
(2899802, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 54248, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 3 - Cast Drakurus Death'),
(2899802, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 54250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 3 - Cast Drakurus Skull Missile'),
(2899802, 9, 2, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 3 - Die'),
(2899801, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Set HP Regen off'),
(2899801, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Set Phase 0'),
(2899801, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 2082, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Set Faction'),
(2899801, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Evade'),
(2899801, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Say'),
(2899801, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 61492, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Cast Despawn Blightblood'),
(2899801, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Set Orientation'),
(2899801, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Say'),
(2899801, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 98914, 28960, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Set Data'),
(2899801, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 12, 28498, 1, 90000, 0, 0, 0, 8, 0, 0, 0, 6141.839, -2011.344, 590.3961,6.040418, 'Overlord Drakuru - Script 2 - Spawn The Lich King'),
(2899801, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 28498, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - Script 2 - Set Orientation');

DELETE FROM `waypoints` WHERE `entry` IN(2849800,2849801);

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2849800, 1,6139.436, -2010.837, 589.1911, 'The Lich King'),
(2849800, 2,6140.423, -2010.994, 589.1911, 'The Lich King'),
(2849800, 3,6142.035, -2011.393, 590.5623, 'The Lich King'),
(2849800, 4,6143.037, -2011.641, 590.8799, 'The Lich King'),
(2849800, 5,6145.518, -2012.255, 590.8799, 'The Lich King'),
(2849800, 6,6152.936, -2014.092, 590.8787, 'The Lich King'),
(2849800, 7,6164.27, -2016.898, 590.8779, 'The Lich King'),
(2849800, 8,6164.27, -2016.898, 590.8779, 'The Lich King'),
(2849801, 1,6153.504, -2014.085, 591.119, 'The Lich King'),
(2849801, 2,6145.754, -2012.335, 591.119, 'The Lich King'),
(2849801, 3,6143.254, -2011.835, 591.119, 'The Lich King'),
(2849801, 4,6142.254, -2011.585, 590.869, 'The Lich King');
