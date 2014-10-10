UPDATE `version` SET `db_version`='TDB 335.56', `cache_id`=56 LIMIT 1;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8301 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8301, 1, 0, 'I need another disguise, Borak. I lost the last one.', 19182, 1, 1, 0, 0, 0, 0, '', 0);

UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=37064, `action_param2`=2, `comment`='Borak, Son of Oronok - On Gossip Option 0 Selected -Cast Create Bundle of Bloodthistle' WHERE  `entryorguid`=21293 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24806, `action_param2`=2, `comment`='Hive\'Ashi Glyphed Crystal - On Gossip Option 0 Selected - Cast Create Hive\'Ashi Rubbing DND' WHERE  `entryorguid`=180454 AND `source_type`=1 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24807, `action_param2`=2, `comment`='Hive\'Regal Glyphed Crystal - On Gossip Option 0 Selected - Cast Create Hive\'Regal Rubbing DND' WHERE  `entryorguid`=180453 AND `source_type`=1 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24805, `action_param2`=2, `comment`='Hive\'Zora Glyphed Crystal - On Gossip Option 0 Selected - Cast Create Hive\'Zora Rubbing DND' WHERE  `entryorguid`=180455 AND `source_type`=1 AND `id`=1 AND `link`=0;

DELETE FROM  `smart_scripts` WHERE `entryorguid`=21293 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21293, 0, 5, 3, 62, 0, 100, 0, 8301, 1, 0, 0, 85, 37100, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Borak, Son of Oronok - On Gossip Option 1 Selected -Cast Create Blood Elf Disguise');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8301 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8301, 1, 0, 0, 9, 0, 10577, 0, 0, 0, 0, 0, '', 'Show gossip menu option if player has quest What Illidan Wants, Illidan Gets...'),
(15, 8301, 1, 0, 0, 2, 0, 30639, 1, 0, 1, 0, 0, '', 'Show gossip menu option if player does not have item Blood Elf Disguise');
UPDATE `creature_template` SET `ScriptName`= 'npc_invis_infernal_caster' WHERE `entry`=21417;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_infernal_attacker' WHERE `entry`=21419;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21419 AND `source_type`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=19252 WHERE  `menu_id`=8301 AND `id`=1;

UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28945, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 0 Selected - Cast Summon Confessor\'s Belt DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28939, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 0 Selected - Cast Summon Madcap\'s Bracers DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=22958, `action_param2`=2, `comment`='Highlord Demitrian - On Gossip Complete - Cast Summon Vessel of Rebirth DND' WHERE  `entryorguid`=14347 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28920, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 0 Selected - Cast Summon Freethinker\'s Bracers DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28923, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 0 Selected - Summon Augur\'s Belt DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=38255, `action_param2`=2, `comment`='Tally Zapnabber - On Gossip Option 0 Selected - Cast Create Gnome Cannon Waiver' WHERE  `entryorguid`=21460 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=25763, `action_param2`=2, `comment`='Draconic for Dummies - On Gossip Option 0 Selected - Cast Draconic For Dummies 7 DND' WHERE  `entryorguid`=180667 AND `source_type`=1 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=25765, `action_param2`=2, `comment`='Draconic for Dummies - On Gossip Option 0 Selected - Cast Draconic For Dummies 4 DND' WHERE  `entryorguid`=180666 AND `source_type`=1 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=25764, `action_param2`=2, `comment`='Draconic for Dummies - On Gossip Option 0 Selected - Cast Draconic For Dummies 5 DND' WHERE  `entryorguid`=180665 AND `source_type`=1 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28937, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 1 Selected - Cast Summon Madcap\'s Mantle DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28943, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 1 Selected - Cast Summon Confessor\'s Mantle DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28919, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 1 Selected - Cast Summon Freethinker\'s Belt DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28926, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 1 Selected - Cast Summon Augur\'s Bracers DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28946, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 2 Selected - Cast Summon Confessor\'s Bracers DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28935, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 2 Selected - Cast Summon Madcap\'s BP DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28909, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 2 Selected - Cast Summon Freethinker\'s  BP DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28959, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 2 Selected - Cast Summon Augur\'s BP DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24015, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman PRT R4 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24075, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman ROG R4 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24010, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 3 Selected - Cast Zul\'Gurub Talisman PAL R4 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24070, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman SHM R4 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24012, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman PRT R1 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24072, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman ROG R1 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24007, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 4 Selected - Cast Zul\'Gurub Talisman PAL R1 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24067, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman SHM R1 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24013, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman PRT R2 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24073, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman ROG R2 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24008, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 5 Selected - Cast Zul\'Gurub Talisman PAL R2 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24068, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman SHM R2 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24014, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman PRT R3 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24074, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman ROG R3 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24009, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 6 Selected - Cast Zul\'Gurub Talisman PAL R3 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24069, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman SHM R3 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28956, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 0 Selected - Cast Summon Demoniac\'s Mantle DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=14 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28929, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 0 Selected - Cast Summon Predator\'s Belt DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=14 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28908, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 0 Selected - Cast Summon Vindicator\'s Armguards  DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=14 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28941, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 0 Selected - Cast Summon Haruspex\'s Belt DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=14 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28954, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 1 Selected - Summon Demoniac\'s BP DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=15 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28930, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 1 Selected - Cast Summon Predator\'s Bracers DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=15 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28886, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 1 Selected - Cast Summon Vindicator\'s Belt  DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=15 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28942, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 1 Selected - Cast Summon Haruspex\'s Bracers DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=15 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28958, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 2 Selected - Casy Summon Demoniac\'s Bracers DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=16 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28921, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 2 Selected - Cast Summon Predator\'s Mantle DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=16 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28885, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 2 Selected - Cast Summon Vindicator\'s BP DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=16 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28940, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 2 Selected - Cast Summon Haruspex\'s BP DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=16 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24047, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman WLK R4 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=17 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24079, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman HUN R4 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=17 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24001, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman WAR R4 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=17 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24060, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman DRU R4 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=17 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24044, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman WLK R1 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=18 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24076, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman HUN R1 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=18 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=23998, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman WAR R1 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=18 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24055, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman DRU R1 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=18 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24045, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman WLK R2 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=19 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24077, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman HUN R2 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=19 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=23999, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman WAR R2 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=19 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24056, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman DRU R2 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=19 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24046, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman WLK R3 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=20 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24078, `action_param2`=2, `comment`='Falthir the Sightless - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman HUN R3 DND' WHERE  `entryorguid`=14905 AND `source_type`=0 AND `id`=20 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24000, `action_param2`=2, `comment`='Jin\'rokh the Breaker - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman WAR R3 DND' WHERE  `entryorguid`=14902 AND `source_type`=0 AND `id`=20 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24059, `action_param2`=2, `comment`='Maywiki of Zuldazar - On Gossip Option 6 Selected - Cast Create Zul\'Gurub Talisman DRU R3 DND' WHERE  `entryorguid`=14904 AND `source_type`=0 AND `id`=20 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28951, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 0 Selected - Cast Summon Illusionist\'s Mantle DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=28 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28949, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 1 Selected - Cast Summon Illusionist\'s BP DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=29 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=28952, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 2 Selected - Cast Summon Illusionist\'s Bracers DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=30 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24041, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 3 Selected - Cast Create Zul\'Gurub Talisman MAG R4 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=31 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24038, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 4 Selected - Cast Create Zul\'Gurub Talisman MAG R1 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=32 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24039, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 5 Selected - Cast Create Zul\'Gurub Talisman MAG R2 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=33 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24040, `action_param2`=2, `comment`='Al\'tabim the All-Seeing - On Gossip Option 6 Selected -Cast Create Zul\'Gurub Talisman MAG R3 DND' WHERE  `entryorguid`=14903 AND `source_type`=0 AND `id`=34 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=25600, `action_param2`=2, `comment`='Spirit of Azuregos - On Gossip Option 0 Selected - Cast Idol of Neptulon DND' WHERE  `entryorguid`=15481 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=31314, `action_param2`=2, `comment`='Blood Knight Dawnstar - On Gossip Option 0 Selected - Cast Summon Blood Knight Insignia' WHERE  `entryorguid`=17832 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- ModelID Fix For NPC: 21749
-- Also Remove Dwarf ModelID From ModelID of 21749
DELETE FROM `creature_model_info` WHERE `modelid` IN (20447, 20448, 20449, 20450, 18790);
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`) VALUES
(20447, 0.372, 1.5, 0, 20449), -- Male Green Orc
(20448, 0.372, 1.5, 0, 20450), -- Male Dark Green Orc
(20449, 0.236, 1.5, 1, 20448), -- Female Dark Green Orc
(20450, 0.236, 1.5, 1, 20447), -- Female Green Orc
(18790, 0.347, 1.5, 1, 18791); -- Dwarf
UPDATE `spell_dbc` SET `Effect1`=28,`EffectMiscValueB1`=64 WHERE `Id`IN(29396,29397);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(19656,17034) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(1965600,1965601) AND `source_type`=9;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` =17034;

DELETE FROM `creature` WHERE  `id`=17034;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19656, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, 1965600, 1965601, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - On Just Summoned - Run Random Script'),
(1965600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 29396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - Script 1 - Cast Summon Kaliri Female'),
(1965601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 29397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - Script 2 - Cast Summon Kaliri Male'),
(17034, 0, 1, 0, 8, 0, 100, 0, 29435, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Female Kaliri Hatchling - On Spellhit Capture Female Kaliri Hatchling  - Despawn');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=181582;
DELETE FROM `smart_scripts` WHERE `entryorguid`=181582 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181582, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 12, 19656, 1, 30000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kaliri Nest - On State Changed - Summon Invisible Location Trigger'),
(181582, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kaliri Nest - On State Changed - Despawn');

UPDATE `gameobject` SET `state`=1 WHERE  `id`=181582;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=19656;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 19656, 0, 0, 23, 1, 3556, 0, 0, 0, 0, 0, '', '');

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`IN(13,17) AND  `SourceEntry`=29435;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 29435, 0, 0, 31, 0, 3, 17034, 0, 0, 0, 0, '', 'Capture Female Kaliri Hatchling requires target Female Kaliri Hatchling'),
(17, 0, 29435, 0, 0, 31, 1, 3, 17034, 0, 0, 0, 0, '', 'Capture Female Kaliri Hatchling requires target Female Kaliri Hatchling');
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=17 AND  `SourceEntry`=45274;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 45274, 0, 0, 31, 1, 3, 25226, 0, 0, 0, 0, '', 'The King\'s Empty Conch requires target Scalder'),
(17, 0, 45274, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', 'The King\'s Empty Conch requires target is dead');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(25226,25197);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25226,25197) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25226, 0, 0, 0, 9, 0, 100, 0, 0, 20, 10000, 15000, 11, 50257, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scalder - On Range - Cast Scalding Blast'),
(25226, 0, 1, 0, 9, 0, 100, 0, 0, 3000, 2500, 4000, 11, 32011, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scalder - On Range - Cast Water Bolt'),
(25197, 0, 0, 0,20, 0, 100, 0, 11571, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'King Mrgl-Mrgl - On Quest Reward (Learning to Communicate) - Say');

DELETE FROM `creature_text` WHERE `entry`=25197;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25197, 0, 0, 'There, $n, now you will be able to speak with, and understand, the Winterfin murlocs.', 12, 0, 100, 1, 0, 0, 'King Mrgl-Mrgl',24428);
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND  `SourceEntry`=29435;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=39812, `action_param2`=2, `comment`='Wild Sparrowhawk - On Script - Cast Captured Sparrowhawk' WHERE  `entryorguid`=2297900 AND `source_type`=9 AND `id`=2 AND `link`=0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(29851,29860,29858,29859);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(29851,29860,29858,29859) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2985100 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2985100, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 12, 29860, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 8552.679, 2653.384, 652.3538, 5.757316, 'General Lightsbane - Script - Summon Vile'),
(2985100, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 12, 29858, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 8597.88, 2668.878, 652.3538, 4.433503, 'General Lightsbane - Script - Summon Lady Nightswood'),
(2985100, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 12, 29859, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 8556.31, 2633.728, 652.4367, 0.3490658, 'General Lightsbane - Script - Summon The Leaper'),
(29851, 0, 0, 1, 7, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29860, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Set Data on Vile'),
(29851, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29858, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Set Data on Lady Nightswood'),
(29851, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29859, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Set Data on The Leaper'),
(29851, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Despawn'),
(29851, 0, 4, 5, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Just Summoned - Say Line'),
(29851, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Just Summoned - Attack'),
(29851, 0, 6, 0,  4, 0, 100, 0, 0, 0, 0, 0, 80, 2985100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Agro - Run Timed Action List (IC Only)'),
(29851, 0, 7, 0,  9, 0, 100, 0, 0, 5, 13000, 18000, 11, 60186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Range - Cast Plague Strike'),
(29851, 0, 8, 0,  9, 0, 100, 0, 0, 5, 8000, 11000, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Range - Cast Cleave'),
(29851, 0, 9, 0,  9, 0, 100, 0, 3000, 5000, 10000, 15000, 11, 60160, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Range - Cast Death and Decay'),
(29851, 0, 10, 11, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29860, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Death - Set Data on Vile'),
(29851, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29858, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Death - Set Data on Lady Nightswood'),
(29851, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29859, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Death - Set Data on The Leaper'),
(29860, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29860, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Just Summoned - Start WP'),
(29860, 0, 1, 2, 40, 0, 100, 0, 8, 29860, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Set Home Position'),
(29860, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Set Aggresive'),
(29860, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Say Line'),
(29860, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 29851, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Attack General Lightsbane'),
(29860, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Data Set 1 1 - Despawn'),
(29860, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 37548, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Agro - Cast Taunt'),
(29860, 0, 7, 0, 0, 0, 100, 0, 8000, 15000, 10000, 15000, 11, 37548, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - IC - Cast Taunt'),
(29860, 0, 8, 0, 9, 0, 100, 0, 0, 5, 5000, 8000, 11, 6253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Range - Cast Back Hand'),
(29860, 0, 9, 0, 0, 0, 100, 0, 10000, 15000, 15000, 23000, 11, 56646, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - IC - Cast Enrage'),
(29858, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29858, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Just Summoned - Start WP'),
(29858, 0, 1, 2, 40, 0, 100, 0, 7, 29858, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Set Home Position'),
(29858, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Set Aggresive'),
(29858, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Say Line'),
(29858, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 29851, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Attack General Lightsbane'),
(29858, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Data Set 1 1 - Despawn'),
(29858, 0, 6, 0, 0, 0, 100, 0, 0, 8000, 13000, 18000, 11, 5884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - IC - Cast Banshee Curse'),
(29858, 0, 7, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 16838, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Range - Cast Banshee Banshee Shiek'),
(29859, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29859, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Just Summoned - Start WP'),
(29859, 0, 1, 2, 40, 0, 100, 0, 6, 29859, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Set Home Position'),
(29859, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Set Aggresive'),
(29859, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Say Line'),
(29859, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 29851, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Attack General Lightsbane'),
(29859, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Data Set 1 1 - Despawn'),
(29859, 0, 6, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 60195, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Sinister Strike'),
(29859, 0, 7, 0, 0, 0, 100, 0, 5000, 8000, 30000, 35000, 11, 60177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Hunger For Blood');

DELETE FROM `waypoints` WHERE `entry` IN(29860,29858,29859);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(29860, 1,8550.583, 2654.241, 652.3538, 'Vile'),
(29860, 2,8551.562, 2654.033, 652.3538, 'Vile'),
(29860, 3,8554.787, 2652.161, 652.3538, 'Vile'),
(29860, 4,8560.368, 2648.921, 652.3538, 'Vile'),
(29860, 5,8576.063, 2639.811, 652.3538, 'Vile'),
(29860, 6,8577.143, 2639.184, 652.3538, 'Vile'),
(29860, 7,8578.033, 2638.667, 652.3539, 'Vile'),
(29860, 8,8578.033, 2638.667, 652.3539, 'Vile'),
(29858, 1,8598.499, 2671.039, 652.3538, 'Lady Nightswood'),
(29858, 2,8598.224, 2670.077, 652.3538, 'Lady Nightswood'),
(29858, 3,8597.247, 2666.667, 652.3538, 'Lady Nightswood'),
(29858, 4,8595.948, 2662.132, 652.3538, 'Lady Nightswood'),
(29858, 5,8593.374, 2653.144, 652.3538, 'Lady Nightswood'),
(29858, 6,8589.56, 2639.825, 652.3538, 'Lady Nightswood'),
(29858, 7,8589.56, 2639.825, 652.3538, 'Lady Nightswood'),
(29859, 1,8558.935, 2633.13, 652.1038, 'The Leaper'),
(29859, 2,8567.935, 2631.38, 652.1038, 'The Leaper'),
(29859, 3,8569.185, 2631.38, 652.1038, 'The Leaper'),
(29859, 4,8577.435, 2631.88, 652.1038, 'The Leaper'),
(29859, 5,8585.435, 2632.38, 652.1038, 'The Leaper'),
(29859, 6,8586.87, 2632.519, 652.3538, 'The Leaper');

DELETE FROM `creature_text` WHERE `entry` IN(29860,29859,29858,29851);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(29860, 0, 0, 'SMASH!', 12, 0, 100, 0, 0, 0, 'Vile',30471),
(29859, 0, 0, 'MRMRFRMRFRMRRRR!', 12, 0, 100, 0, 0, 0, 'The Leaper',30472),
(29858, 0, 0, 'My dear general, your time has come!', 12, 0, 100, 0, 0, 0, 'Lady Nightswood',30470),
(29851, 0, 0, 'You''re the one that''s been disrupting things? This should be easy.', 12, 0, 100, 0, 0, 0, 'General Lightsbane',30465);

-- General Lightsbane 13:52:37
-- Vile 13:52:44
-- Lady Nightswood 13:52:55
-- The Leaper 13:53:06
DELETE FROM `spell_script_names` WHERE `spell_id` IN (
42924,
43310,
42992,
42993,
42994,
43052,
43450
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(42924, 'spell_brewfest_giddyup'),
(43310, 'spell_brewfest_ram'),
(42992, 'spell_brewfest_ram'),
(42993, 'spell_brewfest_ram'),
(42994, 'spell_brewfest_ram'),
(43052, 'spell_brewfest_ram_fatigue'),
(43450, 'spell_brewfest_apple_trap');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=42924;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43450;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42924, 0, 0, 1, 0, 43332, 0, 0, 1, 172, 0, '', 'Cast Gore Bladder only if Cosmetic - Underwater Blood (no sound) aura is active'),
(13, 1, 43450, 0, 0, 1, 0, 43052, 0, 0, 0, 0, 0, '', 'Brewfest - apple trap - friendly DND targets only if does have aura Ram Fatigue');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-43883 AND `spell_effect`=-43052;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43450 AND `spell_effect`=-43052;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-43883, -43052, 0, 'Rental racing ram removed removes Ram Fatigue');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (
43332
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(43332, 'spell_brewfest_exhausted_ram');
SET @CGUID := 29977;

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND  `SourceEntry` IN(29070);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 29070, 0, 0, 31, 0, 3, 29840, 0, 0, 0, 0, '', 'Sovereign Rod target The Leaper'),
(13, 1, 29070, 0, 1, 31, 0, 3, 29770, 0, 0, 0, 0, '', 'Sovereign Rod target The Lady Nightswood'),
(13, 1, 29070, 0, 2, 31, 0, 3, 29769, 0, 0, 0, 0, '', 'Sovereign Rod target Vile'),
(13, 1, 29070, 0, 0, 1, 0, 29266, 0, 0, 0, 0, 0, '', 'Sovereign Rod target must have aura permament feign death'),
(13, 1, 29070, 0, 1, 1, 0, 29266, 0, 0, 0, 0, 0, '', 'Sovereign Rod target must have aura permament feign death'),
(13, 1, 29070, 0, 2, 1, 0, 29266, 0, 0, 0, 0, 0, '', 'Sovereign Rod target must have aura permament feign death');

DELETE FROM `creature_text` WHERE `entry` IN(29840,29770,29769);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(29840, 0, 0, 'Mrrfrmrfrmrrrrr!', 12, 0, 100, 0, 0, 0, 'The Leaper',30463),
(29840, 1, 0, 'Mrmrmmrmrmrmrm... mrmrmrmr?!', 12, 0, 100, 1, 0, 12937, 'The Leaper',30459),
(29770, 0, 0, 'Who intrudes upon my ritual?', 12, 0, 100, 0, 0, 0, 'Lady Nightswood',30462),
(29770, 1, 0, 'You dare?! Where is Baron Sliver? I would have words with him!', 12, 0, 100, 34, 0, 1173, 'Lady Nightswood',30458),
(29769, 0, 0, 'Crush... maim... DESTROY!', 12, 0, 100, 0, 0, 0, 'Vile',30461),
(29769, 1, 0, 'Vile free? Vile love $n!', 12, 0, 100, 34, 0, 1446, 'Vile',30460);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(29840,29770,29769);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(29840,29770,29769) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29770, 0, 1, 17, 61, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Set Unit Flags'),
(29770, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spawn - Set Invincibilty HP'),
(29770, 0, 3, 4, 2, 0, 100, 1, 0, 1, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Turn hp regen off'),
(29770, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Set Passive'),
(29770, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Cast Permament Feign Death'),
(29770, 0, 6, 1, 61, 0, 100, 1, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Despawn After 60 Seconds'),
(29770, 0, 7, 8, 8, 0, 100, 0, 29071, 0, 0, 0, 33, 29846, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit Sovereign Rod - Quest Credit Free Your Mind'),
(29770, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 2, 2050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Faction'),
(29770, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 18, 33040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Unit Flags'),
(29770, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Cast Arcane Explosion Visual'),
(29770, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Say Line 2'),
(29770, 0, 12, 13, 61, 0, 100, 1, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Remove Permament Feigm Death'),
(29770, 0, 13, 14, 61, 0, 100, 1, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Unit Flags 2'),
(29770, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Orientation'),
(29770, 0, 15, 23, 61, 0, 100, 1, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Dynamic Flags'),
(29770, 0, 16, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Agro - Say'),
(29770, 0, 17, 18, 61, 0, 100, 1, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - Link - Remove Unit Flags'),
(29770, 0, 18, 0, 61, 0, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - Link - Evade'),
(29770, 0, 19, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reset - Cast Permament Feign Death'),
(29770, 0, 20, 0, 0, 0, 100, 0, 0, 8000, 13000, 18000, 11, 5884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - IC - Cast Banshee Curse'),
(29770, 0, 21, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 16838, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Range - Cast Banshee Banshee Shiek'),
(29770, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Respawn - Set Unit Flags'),
(29770, 0, 23, 24, 61, 0, 100, 1, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set HP Regen on'),
(29770, 0, 24, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Despawn After 15 Seconds'),
(29770, 0, 25, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 55070, 0, 0, 0, 0, 0, 19, 29771, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - OOC - Cast Shadow Cultist: Blue Smoke Beam'),
(29840, 0, 1, 17, 61, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Set Unit Flags'),
(29840, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spawn - Set Invincibilty HP'),
(29840, 0, 3, 4, 2, 0, 100, 1, 0, 1, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Turn hp regen off'),
(29840, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Set Passive'),
(29840, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Cast Permament Feign Death'),
(29840, 0, 6, 1, 61, 0, 100, 1, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Despawn After 60 seconds'),
(29840, 0, 7, 8, 8, 0, 100, 0, 29071, 0, 0, 0, 33, 29847, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit Sovereign Rod - Quest Credit Free Your Mind'),
(29840, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 2, 2050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Faction'),
(29840, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 18, 33040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Unit Flags'),
(29840, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Cast Arcane Explosion Visual'),
(29840, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Say Line 2'),
(29840, 0, 12, 13, 61, 0, 100, 1, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Remove Permament Feigm Death'),
(29840, 0, 13, 14, 61, 0, 100, 1, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Unit Flags 2'),
(29840, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Orientation'),
(29840, 0, 15, 23, 61, 0, 100, 1, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Dynamic Flags'),
(29840, 0, 16, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Agro - Say'),
(29840, 0, 17, 18, 61, 0, 100, 1, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - Link - Remove Unit Flags'),
(29840, 0, 18, 0, 61, 0, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - Link - Evade'),
(29840, 0, 19, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reset - Cast Permament Feign Death'),
(29840, 0, 20, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 60195, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Sinister Strike'),
(29840, 0, 7, 21, 0, 0, 100, 0, 5000, 8000, 30000, 35000, 11, 60177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Hunger For Blood'),
(29840, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Respawn - Set Unit Flags'),
(29840, 0, 23, 24, 61, 0, 100, 1, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set HP Regen on'),
(29840, 0, 24, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Despawn After 15 Seconds'),
(29769, 0, 1, 17, 61, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Set Unit Flags'),
(29769, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spawn - Set Invincibilty HP'),
(29769, 0, 3, 4, 2, 0, 100, 1, 0, 1, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Turn hp regen off'),
(29769, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Set Passive'),
(29769, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Cast Permament Feign Death'),
(29769, 0, 6, 1, 61, 0, 100, 1, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Despawn After 60 seconds'),
(29769, 0, 7, 8, 8, 0, 100, 0, 29071, 0, 0, 0, 33, 29845, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit Sovereign Rod - Quest Credit Free Your Mind'),
(29769, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 2, 2050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Faction'),
(29769, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 18, 33040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Unit Flags'),
(29769, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Cast Arcane Explosion Visual'),
(29769, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Say Line 2'),
(29769, 0, 12, 13, 61, 0, 100, 1, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Remove Permament Feigm Death'),
(29769, 0, 13, 14, 61, 0, 100, 1, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Unit Flags 2'),
(29769, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Orientation'),
(29769, 0, 15, 23, 61, 0, 100, 1, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Dynamic Flags'),
(29769, 0, 16, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Agro - Say'),
(29769, 0, 17, 18, 61, 0, 100, 1, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - Link - Remove Unit Flags'),
(29769, 0, 18, 0, 61, 0, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - Link - Evade'),
(29769, 0, 19, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reset - Cast Permament Feign Death'),
(29769, 0, 20, 0, 9, 0, 100, 0, 0, 5, 5000, 8000, 11, 6253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Range - Cast Back Hand'),
(29769, 0, 21, 0, 0, 0, 100, 0, 10000, 15000, 15000, 23000, 11, 56646, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - IC - Cast Enrage'),
(29769, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Respawn - Set Unit Flags'),
(29769, 0, 23, 24, 61, 0, 100, 1, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set HP Regen on'),
(29769, 0, 24, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Despawn After 15 Seconds');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(29769,29770,29840);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 8, 29769, 0, 0, 1, 1, 29266, 0, 0, 0, 0, 0, '', 'Only run SAI if has aura Permanent Feign Death'),
(22, 8, 29770, 0, 0, 1, 1, 29266, 0, 0, 0, 0, 0, '', 'Only run SAI if has aura Permanent Feign Death'),
(22, 8, 29840, 0, 0, 1, 1, 29266, 0, 0, 0, 0, 0, '', 'Only run SAI if has aura Permanent Feign Death'),
(22, 20, 29769, 0, 0, 38, 1, 2, 4, 0, 0, 0, 0, '', 'Only run SAI if HP at 1% or less'),
(22, 20, 29770, 0, 0, 38, 1, 2, 4, 0, 0, 0, 0, '', 'Only run SAI if HP at 1% or less'),
(22, 20, 29840, 0, 0, 38, 1, 2, 4, 0, 0, 0, 0, '', 'Only run SAI if HP at 1% or less'),
(22, 26, 29770, 0, 0, 1, 1, 29266, 0, 0, 1, 0, 0, '', 'Only run SAI if does not have aura Permanent Feign Death');

DELETE FROM `creature` WHERE `guid`=@CGUID+0 AND `id`=29771;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phasemask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 29771, 571, 1, 2,  8406.269, 2829.692, 718.509, 3.996804, 120, 0, 0); -- 29771 (Area: 210)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24497,24527,24510);
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=24527;
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=24510;


DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24497;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24497, 0, 0, 0, 19, 0, 100, 0, 11409, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 1, 0, 20, 0, 100, 0, 11409, 0, 0, 0, 11, 44358, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 2, 0, 19, 0, 100, 0, 11412, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''There and Back Again'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 3, 0, 20, 0, 100, 0, 11412, 0, 0, 0, 11, 44358, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''There and Back Again'' Taken - Cast ''Rental Racing Ram''');


DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24527;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24527, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43660, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bok Dropcertain - Within 0-50 Range - Cast ''Brewfest - Throw Keg - DND''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24527;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24527, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', ''),
(22, 1, 24527, 0, 0, 2, 0, 33797, 1, 0, 1, 0, 0, '', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43662;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 43662, 0, 0, 31, 0, 3, 24510, 0, 0, 0, 0, '', '');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24510;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24510, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43714, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Driz Tumblequick <Ram Racing Apprentice> - Within 0-50 Range - Cast ''Brewfest - Throw Keg - DND'''),
(24510, 0, 1, 0, 8, 0, 100, 0, 43662, 0, 0, 0, 85, 44601, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Driz Tumblequick <Ram Racing Apprentice> - On SpellHit - Cast ''Brewfest - Relay Race - Intro - Assign Kill Credit''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24510;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24510, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', ''),
(22, 1, 24510, 0, 0, 2, 0, 33797, 1, 0, 0, 0, 0, '', '');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (
43714,
43876 
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(43714, 'spell_brewfest_relay_race_intro_force_player_to_throw'),
(43876, 'spell_brewfest_dismount_ram');
-- Converted Sentry SAI
SET @ENTRY := 24981;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName` = '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,11,45009,0,0,0,0,0,7,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Cast Converted Sentry Credit (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Set random movement (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,41,7500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Cast Despawn In 7500 ms (No Repeat)");
DELETE FROM `creature_template_addon` WHERE `entry`=24497;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(24497, 22631, 0x0, 0x1, '43880 44069 42146 43492'); -- Ram Master Ray - Ramstein's Swift Work Ram, See Supplier Mark, Brewfest Racing Ram Aura [DND], Brewfest - apple trap - Unfriendly DND

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8976;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8976, 1, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0),
(8976, 2, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8976;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8976, 1, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8976, 1, 0, 0, 9, 0, 11412, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "There and Back Again" taken'),
(15, 8976, 1, 0, 0, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "There and Back Again" rewarded'),
(15, 8976, 2, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8976, 2, 0, 0, 9, 0, 11409, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Now This is Ram Racing... Almost." taken'),
(15, 8976, 2, 0, 0, 28, 0, 11409, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Now This is Ram Racing... Almost." rewarded');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24497 AND `id` >= 4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24497, 0, 4, 6, 62, 0, 100, 0, 8976, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 5, 6, 62, 0, 100, 0, 8976, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Link - Cast ''Rental Racing Ram''');
UPDATE `creature_template` SET `faction`=21 WHERE `entry`=36672; -- Coldflame
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND  `SourceEntry` IN(60532,60545,60456);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 60532, 0, 0, 31, 0, 3, 32184, 0, 0, 0, 0, '', 'Heart Explosion Effects effects 1 & 2 Target the Lich King'),
(13, 3, 60532, 0, 1, 31, 0, 3, 32272, 0, 0, 0, 0, '', 'Heart Explosion Effects effects 1 & 2 Target High Invoker Basaleph'),
(13, 4, 60532, 0, 0, 31, 0, 3, 32272, 0, 0, 0, 0, '', 'Heart Explosion Effects effect 3 Targets High Invoker Basaleph'),
(13, 1, 60545, 0, 0, 31, 0, 3, 32175, 0, 0, 0, 0, '', 'Koltiras Revenge targets Chosen Zealot'),
(13, 1, 60456, 0, 0, 31, 0, 3, 32184, 0, 0, 0, 0, '', 'Tirion Smashes Heart targets The Lich King');

DELETE FROM `spell_target_position` WHERE `id`=60585;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES 
(60585, 0, 571, 6488.41, 411.684, 481.937, 4.74, 0);

DELETE FROM `creature_text` WHERE `entry` IN(32239,32311,32312,32184,32241);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(32239, 0, 0, 'It is time.  May the Light give us strength.', 12, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring',32578),
(32239, 1, 0, 'Keep your heads down and follow my lead.', 12, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring',32616),
(32239, 2, 0, 'Here it comes.  Stand ready.', 12, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring',32619),
(32239, 3, 0, 'Something''s wrong... I sense a dark presence.', 12, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring',32620),
(32239, 4, 0, 'The Lich King is here.  May the Light guide our blades.', 12, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring',32621),
(32239, 5, 0, 'You sound a little too confident.  Especially considering the way our last encounter ended.', 12, 0, 100, 25, 0, 0, 'Highlord Tirion Fordring',32592),
(32239, 6, 0, 'That might be, but I don''t need to stand on holy ground to run that disembodied heart of yours with the Ashbringer.', 12, 0, 100, 1, 0, 0, 'Highlord Tirion Fordring',32589),
(32239, 7, 0, 'The heart... the last remaining vestige of your humanity.  I had to stop it from being destroyed.  I had to see for myself.  And at last I''m sure...', 12, 0, 100, 1, 0, 0, 'Highlord Tirion Fordring',32590),
(32239, 8, 0, 'Only shadows from the past remain.  There''s nothing left to redeem!', 12, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring',32595),
(32311, 0, 0, 'Take courage, crusaders.  You do not fight alone!', 14, 0, 100, 0, 0, 0, 'Koltira Deathweaver',32708),
(32311, 1, 0, 'The Lich King is badly hurt.  We ought to stay behind and finish him.', 12, 0, 100, 0, 0, 0, 'Koltira Deathweaver',32725),
(32312, 0, 0, 'Quick, through the portal!  He won''t stay down for long.', 12, 0, 100, 0, 0, 0, 'Highlord Darion Mograine',32707),
(32312, 1, 0, 'Patience... we will get our chance soon enough.  Be content that for once, it is Tirion who is in our debt.', 12, 0, 100, 0, 0, 0, 'Highlord Darion Mograine',32726),
(32184, 0, 0, 'Uninvited guests!  Did you think you''d go unnoticed inside my dominion?', 12, 0, 100, 1, 0, 0, 'The Lich King',32582),
(32184, 1, 0, 'I must confess... you were not altogether unexpected.  I hope you find your final resting place... to your liking.', 12, 0, 100, 1, 0, 0, 'The Lich King',32585),
(32184, 2, 0, 'Last time we met, you had the advantage of fighting on holy ground.  You''ll find that our situation has been... reversed.', 12, 0, 100, 11, 0, 0, 'The Lich King',32588),
(32184, 3, 0, 'I call your bluff.  You''re a paladin after all.  Your obsession with redemption goes beyond the inane.', 12, 0, 100, 1, 0, 0, 'The Lich King',32593),
(32184, 4, 0, 'You surely wouldn''t destroy humanity''s only chance to redeem its most wayward son.  You''d sooner die!', 12, 0, 100, 1, 0, 0, 'The Lich King',32594),
(32184, 5, 0, 'Arrrrggggggggggh!!!!', 14, 0, 100, 34, 0, 0, 'The Lich King',32694),
(32184, 6, 0, 'You... will pay for that, old man.  Slay them all!', 14, 0, 100, 0, 0, 0, 'The Lich King',32698),
(32241, 0, 0, 'Tirion''s down!  Defend him with your lives!', 14, 0, 100, 0, 0, 0, 'Disguised Crusader',32687);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(32239,32241,32184,24042,32175,32312,32309,32310,32311);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(32239,32241,-74513,-74514,-74515,32184,24042,32175,32312,32309,32310,32311) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3223900,3218400,3217500,3217501,3217502,3217503,3217504,3217505,3231200) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(3231200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 61487, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Tirions Gambit Event Credit'),
(3231200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 0'),
(3231200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 0'),
(3231200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 0'),
(3231200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 0'),
(3231200, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, 193941, 120, 0, 0, 0, 0, 8, 0, 0, 0, 6133.566, 2757.817, 573.914, 0, 'Highlord Darion Mograine - On Data Set 2 2 - Cast Tirions Gambit Event Credit'),
(3231200, 9, 6, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 32311, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 1 on Koltira Deathweaver'),
(3231200, 9, 7, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 1 on Darion Mograine'),
(3231200, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 6, 6, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Highlord Tirion Fordring'),
(3231200, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 32310, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Highlord Tirion Fordring'),
(3231200, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 32311, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Highlord Tirion Fordring'),
(3231200, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 32309, 0, 200, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Highlord Tirion Fordring'),
(3231200, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 9, 32241, 0, 200, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Disguised Crusader'),
(3231200, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 6, 6, 0, 0, 0, 0, 9, 32241, 0, 200, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Disguised Crusader'),
(3231200, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 60000, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Despawn'),
(3231200, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32184, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Despawn'),
(3217500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 4, 1, 0, 0, 0, 0, 21, 200, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - Script 1 - Follow Player'),
(3217501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 4, 2, 0, 0, 0, 0, 21, 200, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - Script 1 - Follow Player'),
(3217502, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 4, 3, 0, 0, 0, 0, 21, 200, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - Script 1 - Follow Player'),
(3217503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 4, 4, 0, 0, 0, 0, 21, 200, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - Script 1 - Follow Player'),
(3217504, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 4, 5, 0, 0, 0, 0, 21, 200, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - Script 1 - Follow Player'),
(3217505, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 4, 6, 0, 0, 0, 0, 21, 200, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - Script 1 - Follow Player'),
(3223900, 9, 0, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - Script - Say Line 2'),
(3223900, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - Script - Say Line 3'),
(3223900, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - Script - Say Line 4'),
(3223900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 32184, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 6180.305, 2657.647, 573.8704, 1.999412, 'Highlord Tirion Fordring - Script - Summon The Lich King'),
(3218400, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data 1 1 (Highlord Tirion Fordring)'),
(3218400, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Face Highlord Tirion Fordring'),
(3218400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 0'),
(3218400, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 1'),
(3218400, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 5 (Highlord Tirion Fordring)'),
(3218400, 9, 5, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 2'),
(3218400, 9, 6, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 6 (Highlord Tirion Fordring)'),
(3218400, 9, 7, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 3'),
(3218400, 9, 8, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 4'),
(3218400, 9, 9, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 7 (Highlord Tirion Fordring)'),
(3218400, 9, 10, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 8 (Highlord Tirion Fordring)'),
(3218400, 9, 11, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data 2 2 (Highlord Tirion Fordring)'),
(3218400, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 32241, 0, 200, 0, 0, 0, 0, 'The Lich King - Script - Set Data 2 2 (Disguised Crusader)'),
(3218400, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 32239, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data 3 3 (Highlord Tirion Fordring)'),
(3218400, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Play emote OneShotWoundCritical'),
(3218400, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 5'),
(3218400, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 124725, 24042, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data 1 1 (Generic Trigger LAB)'),
(3218400, 9, 17, 0, 0, 0, 100, 0, 500, 500, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Bytes 1'),
(3218400, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Immune to NPc'),
(3218400, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 32241, 0, 200, 0, 0, 0, 0, 'The Lich King - Script - Set Data 3 3 (Disguised Crusader)'),
(3218400, 9, 20, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 32241, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 0 (Disguised Crusader)'),
(3218400, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 9, 32241, 0, 200, 0, 0, 0, 0, 'The Lich King - Script - Set Data 5 5 (Disguised Crusader)'),
(3218400, 9, 22, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 5'),
(3218400, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 32175, 0, 200, 0, 0, 0, 0, 'The Lich King - Script - Say Line 5'),
(3218400, 9, 24, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 12, 32312, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 6173.659, 2673.544, 574.2061, 1.987102, 'The Lich King - Script - Set Data Chosen Zealot'),
(3218400, 9, 25, 0, 0, 0, 100, 0, 180000, 180000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 32311, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data 2 2 on Koltira Deathweaver'),
(32309, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 29, 5, 0, 0, 0, 0, 0, 19, 32312, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Just Summoned - Follow  Highlord Darion Mograine'),
(32310, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 32310, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thassarian - On Just Summoned - Start WP'),
(32311, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 32311, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Just Summoned - Start WP'),
(32309, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Data Set - Set Home Position'),
(32310, 0, 1, 2, 40, 0, 100, 0, 8, 32310, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thassarian - On Data Set - Set Home Position'),
(32311, 0, 1, 2, 40, 0, 100, 0, 12, 32311, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Data Set - Set Home Position'),
(32309, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Data Set - Set Hostile'),
(32310, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thassarian - On Data Set - Set Hostile'),
(32311, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Data Set - Set Hostile'),
(32311, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 11, 60545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Data Set - Cast Koltiras Revenge'),
(32309, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Data Set - Set Invincibility HP'),
(32309, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Data Set - Set Passive'),
(32310, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thassarian - On Data Set - Set Passive'),
(32311, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Data Set - Set Passive'),
(32309, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Data Set - Despawn After 30 seconds'),
(32310, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thassarian - On Data Set - Despawn After 30 seconds'),
(32311, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Data Set - Despawn After 30 seconds'),
(32309, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ebon Knight - On Data Set - Evade'),
(32310, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thassarian - On Data Set - Evade'),
(32311, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Koltira Deathweaver - On Data Set - Evade'),
(24042, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 11, 60484, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Generic Trigger LAB - OLD - On Data Set - Cast Heart Explosion'),
(24042, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 60532, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Generic Trigger LAB - OLD - On Data Set - Cast Heart Explosion Effects'),
(32175, 0, 0, 1, 38, 0, 100, 0, 2, 2, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Set Aggresive'),
(32175, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Set Bytes 1'),
(32175, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Set Emote State None'),
(32175, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Evade'),
(32175, 0, 4, 5, 38, 0, 100, 0, 1, 1, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 1 1 - Set Passive'),
(32175, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 17, 27, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Set Emote State - STATE_READYUNARMED'),
(32175, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Set Bytes 1'),
(32175, 0, 7, 9, 61, 0, 100, 0, 0, 0, 0, 0, 87, 3217500, 3217501, 3217502, 3217503, 3217504, 3217505, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 1 1 - Run Random Script'),
(32175, 0, 8, 0, 38, 0, 100, 0, 3, 3, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 2 2 - Set Aggresive'),
(32175, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - On Data Set 1 1 - Set Phase 2'),
(32175, 0, 10, 0, 1, 2, 100, 0, 0, 0, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Chosen Zealot - OOC (Phase 2) - Set Orientation'),
(32239, 0, 0, 1, 62, 0, 100, 0, 10200, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Close Gossip Menu'),
(32239, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Set Npc Flags'),
(32239, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 32241, 0, 200, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Set Data Disguised Crusader'),
(32239, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Set Emote State 0'),
(32239, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Say Line 0'),
(32239, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 32239, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Start WP'),
(32239, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 35536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Gossip Select - Start WP'),
(32239, 0, 7, 8, 40, 0, 100, 1, 5, 32239, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Reached WP5 - Say Line 1'),
(32239, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 32272, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 6131.263, 2763.725, 573.9973, 5.131268, 'Highlord Tirion Fordring - On Reached WP5 - Summon High Invoker Basaleph'),
(32239, 0, 9, 0, 40, 0, 100, 1, 13, 32239, 0, 0, 80, 3223900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Reached WP13 - Run Script'),
(32239, 0, 10, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 3223900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Data Set - Start WP (Path 2)'),
(32239, 0, 11, 13, 40, 0, 100, 1, 3, 3223900, 0, 0, 71, 0, 0, 13262, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Reached WP3 (Path2) - Equip Item'),
(32239, 0, 12, 0, 38, 0, 100, 0, 2, 2, 0, 0, 11, 60456, 0, 0, 0, 0, 0, 19, 32184, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Data Set - Cast Tirion Smashes Heart'),
(32239, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Reached WP3 (Path 2) - Set Home Position'),
(32239, 0, 14, 15, 38, 0, 100, 0, 3, 3, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 32184, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Data Set - Set Orientation'),
(32239, 0, 15, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Data Set - Set Bytes 1'),
(32239, 0, 16, 0, 38, 0, 100, 0, 6, 6, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring - On Data Set - Despawn'),
(32184, 0, 0, 3, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 32184, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Just Summoned - Start WP'),
(32184, 0, 1, 2, 40, 0, 100, 0, 6, 32184, 0, 0, 80, 3218400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Reached WP8 - Run Script'),
(32184, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Reached WP8 - Set Home Position'),
(32184, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Reached WP8 - Switch HP Regen off'),
(32184, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Data Set - Despawn'),
(32312, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 32312, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Just Summoned - Start WP'),
(32312, 0, 1, 0, 40, 0, 100, 1, 8, 32312, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP1 - Summon Group'),
(32312, 0, 2, 3, 40, 0, 100, 1, 14, 32312, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Home Position'),
(32312, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 32309, 0, 200, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Data 1 1 Ebon Knight'),
(32312, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32310, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Data 1 1 Thassarian'),
(32312, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32311, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Data 1 1 Koltira'),
(32312, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 32311, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Data 1 1 Koltira'),
(32312, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Hostile'),
(32312, 0, 8, 10, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 32175, 0, 200, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP9 - Set Data 3 3 Chosen Zealot'),
(32312, 0, 9, 0, 7, 2, 100, 0, 0, 0, 0, 0, 80, 3231200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Evade (Phase 2) - Run Script'),
(32312, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Just Summoned - Set Phase 2'),
(-74513, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 3224100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Start WP'),
(-74514, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 3224101, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Start WP'),
(-74515, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 3224102, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Start WP'),
(-74513, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Remove Bytes 1'),
(-74514, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Remove Bytes 1'),
(-74515, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Remove Bytes 1'),
(-74513, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 53, 0, 3224103, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Start WP Path 2'),
(-74514, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 53, 0, 3224104, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Start WP Path 2'),
(-74515, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 53, 0, 3224105, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Start WP Path 2'),
(-74513, 0, 3, 7, 40, 0, 100, 0, 3, 3224103, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Reached WP3 (Path 2) - Set Home Position'),
(-74514, 0, 3, 7, 40, 0, 100, 0, 3, 3224104, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Reached WP3 (Path 2) - Set Home Position'),
(-74515, 0, 3, 7, 40, 0, 100, 0, 2, 3224105, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Reached WP1 (Path 2) - Set Home Position'),
(-74513, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 32184, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Set Oriietation'),
(-74514, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 32184, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Set Orientation'),
(-74515, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 32184, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Set Orientation'),
(-74513, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 375, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Set Emote State'),
(-74514, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 375, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Set Emote State'),
(-74515, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 375, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Set Emote State'),
(-74513, 0, 6, 0, 38, 0, 100, 0, 6, 6, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader - On Data Set - Despawn'),
(-74514, 0, 6, 0, 38, 0, 100, 0, 6, 6, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader - On Data Set - Despawn'),
(-74515, 0, 6, 0, 38, 0, 100, 0, 6, 6, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader - On Data Set - Despawn'),
(-74513, 0, 7, 8, 61, 0, 100, 0, 5, 5, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Set Invincibility HP'),
(-74514, 0, 7, 8, 61, 0, 100, 0, 5, 5, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Set Invincibilty HP'),
(-74515, 0, 7, 8, 61, 0, 100, 0, 5, 5, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Set Invincibility HP'),
(-74513, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Set Hostile'),
(-74514, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Set Hostile'),
(-74515, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Set Hostile'),
(-74513, 0, 9, 10, 38, 0, 100, 0, 4, 4, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Set Passive'),
(-74514, 0, 9, 10, 38, 0, 100, 0, 4, 4, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Set Passive'),
(-74515, 0, 9, 10, 38, 0, 100, 0, 4, 4, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Set Set Passive'),
(-74513, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 1 - On Data Set - Evade'),
(-74514, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 2 - On Data Set - Evade'),
(-74515, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disguised Crusader 3 - On Data Set - Evade');


DELETE FROM `waypoints` WHERE `entry` IN(32239,3224100,3224101,3224102,3223900,3224103,3224104,3224105,32312,32184,32311,32310);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
-- Owner GUID: Full: 0xF1307DF1007193AC Type: Unit Entry: 32241 Low: 7443372
(3224100, 1,6255.6, 2654.405, 570.5411, 'Disguised Crusader 1'),
(3224100, 2,6249.35, 2645.405, 570.5411, 'Disguised Crusader 1'),
(3224100, 3,6230.1, 2629.655, 570.5411, 'Disguised Crusader 1'),
(3224100, 4,6217.1, 2622.655, 570.5411, 'Disguised Crusader 1'),
(3224100, 5,6205.6, 2622.405, 570.5411, 'Disguised Crusader 1'),
(3224100, 6,6196.85, 2623.905, 570.5411, 'Disguised Crusader 1'),
(3224100, 7,6185.403, 2647.951, 572.0817, 'Disguised Crusader 1'),
(3224100, 8,6178.403, 2662.951, 574.8317, 'Disguised Crusader 1'),
(3224100, 9,6164.403, 2693.701, 574.0817, 'Disguised Crusader 1'),
(3224100, 10,6157.653, 2708.701, 574.0817, 'Disguised Crusader 1'),
(3224100, 11,6148.903, 2727.201, 574.0817, 'Disguised Crusader 1'),
(3224100, 12,6153.403, 2736.701, 574.0817, 'Disguised Crusader 1'),
(3224100, 13,6178.653, 2749.201, 574.0817, 'Disguised Crusader 1'),
(3224100, 14,6170.568, 2762.95, 573.914, 'Disguised Crusader 1'),
-- Owner GUID: Full: 0xF1307DF1007193AC Type: Unit Entry: 32241 Low: 7443372
(3224103, 1,6162.497, 2759.066, 574.164, 'Disguised Crusader 1 Path 2'),
(3224103, 2,6151.747, 2762.066, 574.164, 'Disguised Crusader 1 Path 2'),
(3224103, 3,6140.247, 2763.566, 574.164, 'Disguised Crusader 1 Path 2'),
-- Owner GUID: Full: 0xF1307DF1007193B0 Type: Unit Entry: 32241 Low: 7443376
(3224101, 1,6237.105, 2639.326, 570.5411, 'Disguised Crusader 2'),
(3224101, 2,6230.855, 2634.076, 570.5411, 'Disguised Crusader 2'),
(3224101, 3,6218.105, 2624.826, 570.5411, 'Disguised Crusader 2'),
(3224101, 4,6198.605, 2617.576, 570.5411, 'Disguised Crusader 2'),
(3224101, 5,6188.855, 2621.576, 570.5411, 'Disguised Crusader 2'),
(3224101, 6,6176.773, 2653.593, 573.8317, 'Disguised Crusader 2'),
(3224101, 7,6168.773, 2671.843, 574.3317, 'Disguised Crusader 2'),
(3224101, 8,6159.773, 2691.343, 574.0817, 'Disguised Crusader 2'),
(3224101, 9,6148.523, 2715.593, 574.0817, 'Disguised Crusader 2'),
(3224101, 10,6140.773, 2732.093, 574.0817, 'Disguised Crusader 2'),
(3224101, 11,6159.023, 2742.843, 574.0817, 'Disguised Crusader 2'),
(3224101, 12,6174.273, 2749.343, 574.0817, 'Disguised Crusader 2'),
(3224101, 13,6168.286, 2761.969, 573.914, 'Disguised Crusader 2'),
-- Owner GUID: Full: 0xF1307DF1007193B0 Type: Unit Entry: 32241 Low: 7443376
(3224104, 1,6161.965, 2757.105, 574.164, 'Disguised Crusader 2 Path 2'),
(3224104, 2,6148.465, 2755.605, 574.164, 'Disguised Crusader 2 Path 2'),
(3224104, 3,6132.715, 2757.605, 574.164, 'Disguised Crusader 2 Path 2'),
-- Owner GUID: Full: 0xF1307DF1007193AE Type: Unit Entry: 32241 Low: 7443374
(3224102, 1,6238.134, 2664.245, 570.5411, 'Disguised Crusader 3'),
(3224102, 2,6238.134, 2651.495, 570.5411, 'Disguised Crusader 3'),
(3224102, 3,6229.384, 2629.995, 570.5411, 'Disguised Crusader 3'),
(3224102, 4,6210.384, 2622.745, 570.5411, 'Disguised Crusader 3'),
(3224102, 5,6200.634, 2631.995, 570.5411, 'Disguised Crusader 3'),
(3224102, 6,6196.85, 2623.905, 570.5411, 'Disguised Crusader 3'),
(3224102, 7,6178.815, 2677.46, 574.3317, 'Disguised Crusader 3'),
(3224102, 8,6171.315, 2691.71, 574.0817, 'Disguised Crusader 3'),
(3224102, 9,6163.565, 2707.96, 574.0817, 'Disguised Crusader 3'),
(3224102, 10,6159.815, 2715.71, 574.0817, 'Disguised Crusader 3'),
(3224102, 11,6151.315, 2733.71, 574.0817, 'Disguised Crusader 3'),
(3224102, 12,6154.565, 2737.46, 574.0817, 'Disguised Crusader 3'),
(3224102, 13,6179.565, 2751.46, 574.0817, 'Disguised Crusader 3'),
(3224102, 14,6173.314, 2764.15, 573.914, 'Disguised Crusader 3'),
-- Owner GUID: Full: 0xF1307DF1007193AE Type: Unit Entry: 32241 Low: 7443374
(3224105, 1,6158.404, 2754.641, 574.164, 'Disguised Crusader 3 Path 2'),
(3224105, 2,6134.994, 2759.132, 573.914, 'Disguised Crusader 3 Path 2'),
-- Owner GUID: Full: 0xF1307DEF007193AA Type: Unit Entry: 32239 Low: 7443370
(32239, 1,6241.011, 2653.922, 570.5411, 'Highlord Tirion Fordring'),
(32239, 2,6239.011, 2644.922, 570.5411, 'Highlord Tirion Fordring'),
(32239, 3,6224.011, 2631.422, 570.5411, 'Highlord Tirion Fordring'),
(32239, 4,6207.011, 2627.922, 570.5411, 'Highlord Tirion Fordring'), 
(32239, 5,6193.261, 2629.172, 570.5411, 'Highlord Tirion Fordring'), -- Line 2
(32239, 6,6181.6, 2656.623, 573.5817, 'Highlord Tirion Fordring'),
(32239, 7,6174.35, 2672.123, 574.3317, 'Highlord Tirion Fordring'),
(32239, 8,6164.6, 2692.873, 574.0817, 'Highlord Tirion Fordring'),
(32239, 9,6154.6, 2714.373, 574.0817, 'Highlord Tirion Fordring'),
(32239, 10,6146.1, 2732.873, 574.0817, 'Highlord Tirion Fordring'),
(32239, 11,6160.6, 2743.623, 574.0817, 'Highlord Tirion Fordring'),
(32239, 12,6170.1, 2753.873, 574.0817, 'Highlord Tirion Fordring'),
(32239, 13,6165.772, 2760.747, 573.914, 'Highlord Tirion Fordring'),
-- GUID: Full: 0xF1307DB80076BD66 Type: Unit Entry: 32184 Low: 7781734
(32184, 1,6174.985, 2669.289, 574.4298, 'The Lich King'),
(32184, 2,6164.939, 2691.6, 573.914, 'The Lich King'), 
(32184, 3,6156.291, 2709.657, 573.914, 'The Lich King'), 
(32184, 4,6147.657, 2729.304, 573.914, 'The Lich King'),
(32184, 5,6131.82, 2757.886, 573.914, 'The Lich King'),
(32184, 6,6131.82, 2757.886, 573.914, 'The Lich King'),
-- Owner GUID: Full: 0xF1307DEF007193AA Type: Unit Entry: 32239 Low: 7443370
(3223900, 1,6169.14, 2758.224, 574.164, 'Highlord Tirion Fordring Path 2'),
(3223900, 2,6163.64, 2756.224, 574.164, 'Highlord Tirion Fordring Path 2'),
(3223900, 3,6156.64, 2756.724, 574.164, 'Highlord Tirion Fordring Path 2'),
(3223900, 4,6142.507, 2757.701, 573.914, 'Highlord Tirion Fordring Path 2'),
-- GUID: Full: 0xF1307E380076C8EE Type: Unit Entry: 32312 Low: 7784686
(32312, 1,6176.699, 2666.668, 574.5868, 'Highlord Darion Mograine'),
(32312, 2,6171.327, 2678.818, 573.9142, 'Highlord Darion Mograine'),
(32312, 3,6165.052, 2693.011, 573.9141, 'Highlord Darion Mograine'),
(32312, 4,6164.547, 2694.153, 573.9141, 'Highlord Darion Mograine'),
(32312, 5,6164.547, 2694.153, 573.9141, 'Highlord Darion Mograine'),
(32312, 6,6164.982, 2693.149, 574.1641, 'Highlord Darion Mograine'),
(32312, 7,6164.482, 2694.399, 574.1641, 'Highlord Darion Mograine'),
(32312, 8,6159.982, 2704.899, 574.1641, 'Highlord Darion Mograine'),
(32312, 9,6159.232, 2706.649, 574.1641, 'Highlord Darion Mograine'),
(32312, 10,6157.982, 2709.149, 574.1641, 'Highlord Darion Mograine'),
(32312, 11,6154.946, 2715.455, 574.1641, 'Highlord Darion Mograine'),
(32312, 12,6154.196, 2717.205, 574.1641, 'Highlord Darion Mograine'),
(32312, 13,6143.353, 2738.469, 574.1641, 'Highlord Darion Mograine'),
(32312, 14,6138.019, 2754.837, 573.9141, 'Highlord Darion Mograine'),
-- GUID: Full: 0xF1307E370076C8EF Type: Unit Entry: 32311 Low: 7784687
(32311, 1,6159.867, 2705.287, 574.1641, 'Koltira Deathweaver'),
(32311, 2,6159.367, 2707.287, 574.1641, 'Koltira Deathweaver'),
(32311, 3,6158.367, 2709.537, 574.1641, 'Koltira Deathweaver'),
(32311, 4,6155.617, 2717.037, 574.1641, 'Koltira Deathweaver'),
(32311, 5,6155.117, 2718.537, 574.1641, 'Koltira Deathweaver'),
(32311, 6,6154.849, 2717.368, 574.1641, 'Koltira Deathweaver'),
(32311, 7,6154.349, 2718.368, 574.1641, 'Koltira Deathweaver'),
(32311, 8,6150.599, 2726.618, 574.1641, 'Koltira Deathweaver'),
(32311, 9,6147.419, 2732.72, 573.9141, 'Koltira Deathweaver'),
(32311, 10,6141.567, 2743.204, 574.1641, 'Koltira Deathweaver'),
(32311, 11,6139.709, 2746.204, 573.9141, 'Koltira Deathweaver'),
(32311, 12,6137.443, 2751.248, 574.1641, 'Koltira Deathweaver'),
 -- GUID: Full: 0xF1307E360076C8F0 Type: Unit Entry: 32310 Low: 7784688
(32310, 1,6159.335, 2705.071, 574.1641, 'Thassarian'),
(32310, 2,6158.585, 2706.571, 574.1641, 'Thassarian'),
(32310, 3,6157.335, 2709.071, 574.1641, 'Thassarian'),
(32310, 4,6153.585, 2717.321, 574.1641, 'Thassarian'),
(32310, 5,6153.186, 2717.784, 574.1641, 'Thassarian'),
(32310, 6,6149.186, 2726.034, 574.1641, 'Thassarian'),
(32310, 7,6146.444, 2731.355, 573.9141, 'Thassarian'),
(32310, 8,6141.1, 2740.615, 573.9141, 'Thassarian');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=32312;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(32312, 0, 1, 32309, 6161.294, 2699.628, 573.9141, 1.920898, 3, 600000),
(32312, 0, 1, 32309, 6164.255, 2698.859, 573.9141, 2.01017, 3, 600000),
(32312, 0, 1, 32309, 6161.909, 2695.987, 573.914, 1.889949, 3, 600000),
(32312, 0, 1, 32309, 6163.728, 2696.768, 573.9141, 1.966068, 3, 600000),
(32312, 0, 1, 32309, 6160.207, 2698.687, 573.9141, 1.874134, 3, 600000),
(32312, 0, 1, 32309, 6164.456, 2699.853, 573.9141, 2.005516, 3, 600000),
(32312, 0, 1, 32309, 6160.355, 2698.815, 573.9141, 1.910763, 3, 600000),
(32312, 0, 1, 32310, 6162.42, 2698.646, 573.9141, 2.076199, 3, 600000),
(32312, 0, 1, 32311, 6162.563, 2699.107, 573.9141, 2.015445, 3, 600000);
--
DELETE FROM `creature` WHERE `id`=417;
UPDATE `quest_template` SET `LimitTime` = 60 * 4 WHERE `Id` IN (11407,11408,11293,11294);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8976 AND `id`=3;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8976, 3, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8976 AND `SourceEntry`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8976, 3, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8976, 3, 0, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for Drohn''s Distillery!" taken'),
(15, 8976, 3, 0, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(15, 8976, 3, 0, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for Drohn''s Distillery!" rewarded'),
(15, 8976, 3, 0, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for T''chali''s Voodoo Brewery!" rewarded');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24497 AND `id` >= 4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24497, 0, 4, 7, 62, 0, 100, 0, 8976, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 5, 7, 62, 0, 100, 0, 8976, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 6, 7, 62, 0, 100, 0, 8976, 3, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Bark for T''chali''s Voodoo Brewery!'' / ''Bark for Drohn''s Distillery!'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Link - Cast ''Rental Racing Ram''');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24498,24499);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24498;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24498, 0, 0, 0, 19, 0, 100, 0, 11407, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cort Gorestein - On Quest ''Bark for Drohn''s Distillery!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24499;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24499, 0, 0, 0, 19, 0, 100, 0, 11408, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ja''ron - On Quest ''Bark for T''chali''s Voodoo Brewery!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24527 AND `ConditionTypeOrReference` IN (9,28);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24527, 0, 0, 9, 0, 11412, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "There and Back Again" taken'),
(22, 1, 24527, 0, 0, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "There and Back Again" taken');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (
43259,
43260,
43261,
43262
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(43259, 'spell_brewfest_barker_bunny'),
(43260, 'spell_brewfest_barker_bunny'),
(43261, 'spell_brewfest_barker_bunny'),
(43262, 'spell_brewfest_barker_bunny');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4801,4802,4803,4804);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4801, 'SmartTrigger'),
(4802, 'SmartTrigger'),
(4803, 'SmartTrigger'),
(4804, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4801;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4801, 2, 0, 0, 46, 0, 100, 0, 4801, 0, 0, 0, 85, 43259, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 1''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4802;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4802, 2, 0, 0, 46, 0, 100, 0, 4802, 0, 0, 0, 85, 43260, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 2''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4803;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4803, 2, 0, 0, 46, 0, 100, 0, 4803, 0, 0, 0, 85, 43261, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 3''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4804;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4804, 2, 0, 0, 46, 0, 100, 0, 4804, 0, 0, 0, 85, 43262, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 4''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4801,4802,4803,4804);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4801, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4801, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4801, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4801, 2, 0, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4801, 2, 1, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4802, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4802, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4802, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4802, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4802, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4803, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4803, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4803, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4803, 2, 0, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4803, 2, 1, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4804, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4804, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4804, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4804, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4804, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken');
DELETE FROM `gameobject` WHERE `guid`=31688;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(31688, 186717, 1, 1, 1, 1349.707, -4357.939, 26.95916, -0.593412, 0, 0, 0, 1, 120, 255, 1); -- Brewfest Banner (Area: 0)
--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 7583 AND `id` = 1 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7583, 0, 1, 0, 8, 0, 100, 0, 17166, 0, 0, 0, 33, 7583, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sprinkle - On Spellhit \'Release Umi\'s Yeti\' - Quest Credit \'Are We There, Yeti?\'');
-- Alter creature_loot_template
ALTER TABLE `creature_loot_template` DROP PRIMARY KEY;
ALTER TABLE `creature_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `creature_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `creature_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `creature_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `creature_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `creature_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `creature_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `creature_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `creature_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `creature_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `creature_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `creature_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `creature_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `creature_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter disenchant_loot_template
ALTER TABLE `disenchant_loot_template` DROP PRIMARY KEY;
ALTER TABLE `disenchant_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `disenchant_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `disenchant_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `disenchant_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `disenchant_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `disenchant_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `disenchant_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `disenchant_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `disenchant_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `disenchant_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter fishing_loot_template
ALTER TABLE `fishing_loot_template` DROP PRIMARY KEY;
ALTER TABLE `fishing_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `fishing_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `fishing_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `fishing_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `fishing_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `fishing_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `fishing_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `fishing_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `fishing_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `fishing_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `fishing_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `fishing_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter gameobject_loot_template
ALTER TABLE `gameobject_loot_template` DROP PRIMARY KEY;
ALTER TABLE `gameobject_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `gameobject_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `gameobject_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `gameobject_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `gameobject_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `gameobject_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `gameobject_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `gameobject_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `gameobject_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter item_loot_template
ALTER TABLE `item_loot_template` DROP PRIMARY KEY;
ALTER TABLE `item_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `item_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `item_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `item_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `item_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `item_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `item_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `item_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `item_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `item_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `item_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `item_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter mail_loot_template
ALTER TABLE `mail_loot_template` DROP PRIMARY KEY;
ALTER TABLE `mail_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `mail_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `mail_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `mail_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `mail_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `mail_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `mail_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `mail_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `mail_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `mail_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `mail_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `mail_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `mail_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `mail_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `mail_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter milling_loot_template
ALTER TABLE `milling_loot_template` DROP PRIMARY KEY;
ALTER TABLE `milling_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `milling_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `milling_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `milling_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `milling_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `milling_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `milling_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `milling_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `milling_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `milling_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `milling_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `milling_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `milling_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `milling_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `milling_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter pickpocketing_loot_template
ALTER TABLE `pickpocketing_loot_template` DROP PRIMARY KEY;
ALTER TABLE `pickpocketing_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `pickpocketing_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `pickpocketing_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `pickpocketing_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `pickpocketing_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `pickpocketing_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `pickpocketing_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `pickpocketing_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `pickpocketing_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter prospecting_loot_template
ALTER TABLE `prospecting_loot_template` DROP PRIMARY KEY;
ALTER TABLE `prospecting_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `prospecting_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `prospecting_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `prospecting_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `prospecting_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `prospecting_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `prospecting_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `prospecting_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `prospecting_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `prospecting_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `prospecting_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `prospecting_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter reference_loot_template
ALTER TABLE `reference_loot_template` DROP PRIMARY KEY;
ALTER TABLE `reference_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `reference_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `reference_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `reference_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `reference_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `reference_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `reference_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `reference_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `reference_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `reference_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `reference_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `reference_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `reference_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `reference_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `reference_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter skinning_loot_template
ALTER TABLE `skinning_loot_template` DROP PRIMARY KEY;
ALTER TABLE `skinning_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `skinning_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `skinning_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `skinning_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `skinning_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `skinning_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `skinning_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `skinning_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `skinning_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `skinning_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `skinning_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `skinning_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `skinning_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `skinning_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter spell_loot_template
ALTER TABLE `spell_loot_template` DROP PRIMARY KEY;
ALTER TABLE `spell_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `spell_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `spell_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `spell_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `spell_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `spell_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `spell_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `spell_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `spell_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `spell_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `spell_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `spell_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `spell_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `spell_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `spell_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);
UPDATE `creature_text` SET `BroadcastTextId`=28844 WHERE `entry`=29 AND `groupid`=1;
UPDATE `creature_text` SET `BroadcastTextId`=12223 WHERE `entry`=16329 AND `groupid`=0;
UPDATE `creature_text` SET `BroadcastTextId`=29304 WHERE `entry`=22515 AND `groupid`=6;
UPDATE `creature_text` SET `BroadcastTextId`=29305 WHERE `entry`=22515 AND `groupid`=7;
UPDATE `creature_text` SET `BroadcastTextId`=29306 WHERE `entry`=22515 AND `groupid`=8;
UPDATE `creature_text` SET `BroadcastTextId`=29307 WHERE `entry`=22515 AND `groupid`=9;
UPDATE `creature_text` SET `BroadcastTextId`=29308 WHERE `entry`=22515 AND `groupid`=10;
UPDATE `creature_text` SET `BroadcastTextId`=24747 WHERE `entry`=25504 AND `groupid`=0;
UPDATE `creature_text` SET `BroadcastTextId`=27243 WHERE `entry`=25504 AND `groupid`=1;
UPDATE `creature_text` SET `BroadcastTextId`=27245 WHERE `entry`=25504 AND `groupid`=2;
UPDATE `creature_text` SET `BroadcastTextId`=24748 WHERE `entry`=25504 AND `groupid`=3;
UPDATE `creature_text` SET `BroadcastTextId`=24749 WHERE `entry`=25504 AND `groupid`=4;
UPDATE `creature_text` SET `BroadcastTextId`=28396 WHERE `entry`=28122 AND `groupid`=3;
UPDATE `creature_text` SET `BroadcastTextId`=28382 WHERE `entry`=28122 AND `groupid`=4;
UPDATE `creature_text` SET `BroadcastTextId`=28507 WHERE `entry`=28511 AND `groupid`=0;
UPDATE `creature_text` SET `BroadcastTextId`=28465 WHERE `entry`=28511 AND `groupid`=1;
UPDATE `creature_text` SET `BroadcastTextId`=28899 WHERE `entry`=28841 AND `groupid`=1;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=12663 WHERE `menu_id`=6341 AND `id`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=12674 WHERE `menu_id`=21265 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=12657 WHERE `menu_id`=21270 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=12659 WHERE `menu_id`=21271 AND `id`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=12660 WHERE `menu_id`=21271 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=12658 WHERE `menu_id`=21271 AND `id`=2;
--
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=29 AND `groupid`=1;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=6;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=7;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=8;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=9;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=10;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=33765 WHERE `menu_id`=10371;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=33762 WHERE `option_text` LIKE 'I wish to know about Dual Talent Specialization.';
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=33762 WHERE `option_text` LIKE 'Learn about Dual Talent Specialization.';
--
UPDATE `locales_quest` SET `Title_loc2` = REPLACE(`Title_loc2`, "[PÉRIMÉ] ", "");
UPDATE `locales_quest` SET `Title_loc2` = REPLACE(`Title_loc2`, "[PÉRIMÉ]", "");
UPDATE `locales_quest` SET `Title_loc6` = REPLACE(`Title_loc6`, "[DEPRECATED] ", "");
UPDATE `locales_quest` SET `Title_loc6` = REPLACE(`Title_loc6`, "[DEPRECATED]", "");
UPDATE `locales_quest` SET `Title_loc7` = REPLACE(`Title_loc7`, "[DEPRECATED] ", "");
UPDATE `locales_quest` SET `Title_loc7` = REPLACE(`Title_loc7`, "[DEPRECATED]", "");
UPDATE `locales_quest` SET `Title_loc8` = REPLACE(`Title_loc8`, "[DEPRECATED] ", "");
UPDATE `locales_quest` SET `Title_loc8` = REPLACE(`Title_loc8`, "[DEPRECATED]", "");
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=11325 WHERE `option_text` LIKE 'May I have your report?';
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=3370 WHERE `option_text` LIKE 'I want to browse your goods.';
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=33765 WHERE `menu_id`=0 AND `id`=16;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=4384 WHERE `menu_id`=21 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=4261 WHERE `menu_id`=1186 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=9672 WHERE `menu_id`=5848 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=9672 WHERE `menu_id`=5849 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=33765 WHERE `menu_id`=6647 AND `id`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=20452 WHERE `menu_id`=8568 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=20453 WHERE `menu_id`=8568 AND `id`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=34567 WHERE `menu_id`=10502 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=35446 WHERE `menu_id`=10502 AND `id`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=51468 WHERE `menu_id`=10502 AND `id`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=36760 WHERE `menu_id`=10854 AND `id`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=37552 WHERE `menu_id`=10854 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=21522 WHERE `menu_id`=21335 AND `id`=0;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=5483;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(5483, 0, 0, 'Barnil, I seem to have misplaced Chapter I.', 9018, 1, 1, 0, 0, 0, 0, '', 0),
(5483, 1, 0, 'Barnil, I seem to have misplaced Chapter II.', 9019, 1, 1, 0, 0, 0, 0, '', 0),
(5483, 2, 0, 'Barnil, I seem to have misplaced Chapter III.', 9020, 1, 1, 0, 0, 0, 0, '', 0),
(5483, 3, 0, 'Barnil, I seem to have misplaced Chapter IV.', 9021, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `creature_text` WHERE `entry` IN(716);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(716, 0, 0, 'I see you misplaced that chapter you worked so hard to put together, $n. Well, you left it right here!', 12, 0, 100, 0, 0, 0, 'Barnil Stonepot', 9022);

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(716);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(716) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(716, 0, 0, 4, 62, 0, 100, 0, 5483, 0, 0, 0, 85, 22208, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 0 Selected - Invoker cast Create Chapter 1 DND '),
(716, 0, 1, 4, 62, 0, 100, 0, 5483, 1, 0, 0, 85, 22209, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 1 Selected - Invoker cast Create Chapter 2 DND '),
(716, 0, 2, 4, 62, 0, 100, 0, 5483, 2, 0, 0, 85, 22210, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 2 Selected - Invoker cast Create Chapter 3 DND '),
(716, 0, 3, 4, 62, 0, 100, 0, 5483, 3, 0, 0, 85, 22211, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 3 Selected - Invoker cast Create Chapter 4 DND '),
(716, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - Link - Say Line'),
(716, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - Link - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5483;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 5483, 0, 0, 0, 2, 0, 2756, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter I'),
(15, 5483, 0, 0, 0, 8, 0, 339, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter I rewarded'),
(15, 5483, 0, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn'),
(15, 5483, 1, 0, 0, 2, 0, 2757, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter II'),
(15, 5483, 1, 0, 0, 8, 0, 340, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter II rewarded'),
(15, 5483, 1, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn'),
(15, 5483, 2, 0, 0, 2, 0, 2758, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter III'),
(15, 5483, 2, 0, 0, 8, 0, 341, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter III rewarded'),
(15, 5483, 2, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn'),
(15, 5483, 3, 0, 0, 2, 0, 2759, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter IV'),
(15, 5483, 3, 0, 0, 8, 0, 342, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter IV rewarded'),
(15, 5483, 3, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (23558,23627,23628,24364,24468);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23558;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23558, 0, 0, 0, 19, 0, 100, 0, 11318, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 1, 0, 19, 0, 100, 0, 11122, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''There and Back Again'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 2, 5, 62, 0, 100, 0, 8934, 3, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Bark for the Barleybrews!'' / ''Bark for the Thunderbrews!'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 3, 5, 62, 0, 100, 0, 8934, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 4, 5, 62, 0, 100, 0, 8934, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Link - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23627;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23627, 0, 0, 0, 19, 0, 100, 0, 11293, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Becan Barleybrew - On Quest ''Bark for the Barleybrews!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23628;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23628, 0, 0, 0, 19, 0, 100, 0, 11294, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Daran Thunderbrew - On Quest ''Bark for the Thunderbrews!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24364;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24364, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43660, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bok Dropcertain - Within 0-25 Range - Cast ''Brewfest - Throw Keg - DND''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24468;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24468, 0, 1, 0, 8, 0, 100, 0, 43662, 0, 0, 0, 85, 44601, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Pol Amberstill <Ram Racing Apprentice> - On SpellHit - Cast ''Brewfest - Relay Race - Intro - Assign Kill Credit'''),
(24468, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43714, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Pol Amberstill <Ram Racing Apprentice> - Within 0-25 Range - Cast ''Brewfest - Throw Keg - DND''');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8934;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8934, 1, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0),
(8934, 2, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0),
(8934, 3, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8934;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8934, 1, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8934, 2, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8934, 3, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),

(15, 8934, 1, 0, 0, 9, 0, 11122, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "There and Back Again" taken'),
(15, 8934, 2, 0, 0, 9, 0, 11318, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Now This is Ram Racing... Almost." taken'),
(15, 8934, 3, 0, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for the Barleybrews!" taken'),
(15, 8934, 3, 0, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for the Thunderbrews!" taken'),

(15, 8934, 1, 0, 0, 28, 0, 11122, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "There and Back Again" rewarded'),
(15, 8934, 2, 0, 0, 28, 0, 11318, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Now This is Ram Racing... Almost." rewarded'),
(15, 8934, 3, 0, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for the Barleybrews!" rewarded'),
(15, 8934, 3, 0, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for the Thunderbrews!" rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24364;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24364, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does have Aura "Rental Racing Ram"'),
(22, 1, 24364, 0, 0, 2, 0, 33797, 1, 0, 1, 0, 0, '', 'SAI triggers only if player does not have Item "Portable Brewfest Keg"'),
(22, 1, 24364, 0, 0, 9, 0, 11122, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "There and Back Again" taken'),
(22, 1, 24364, 0, 0, 28, 0, 11122, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "There and Back Again" taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24468;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24468, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does have Aura "Rental Racing Ram"'),
(22, 1, 24468, 0, 0, 2, 0, 33797, 1, 0, 0, 0, 0, '', 'SAI triggers only if player does have Item "Portable Brewfest Keg"');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43662 AND `ConditionValue2`=24468;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 43662, 0, 1, 31, 0, 3, 24468, 0, 0, 0, 0, '', 'Brewfest - Throw Keg - Player - DND targets Pol Amberstill <Ram Racing Apprentice>');
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4769,4770,4772,4774);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4769, 'SmartTrigger'),
(4774, 'SmartTrigger'),
(4770, 'SmartTrigger'),
(4772, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4769;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4769, 2, 0, 0, 46, 0, 100, 0, 4769, 0, 0, 0, 85, 43259, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 1''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4770;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4770, 2, 0, 0, 46, 0, 100, 0, 4770, 0, 0, 0, 85, 43261, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 3''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4772;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4772, 2, 0, 0, 46, 0, 100, 0, 4772, 0, 0, 0, 85, 43260, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 4''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4774;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4774, 2, 0, 0, 46, 0, 100, 0, 4774, 0, 0, 0, 85, 43262, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 2''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4769,4770,4772,4774);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4769, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4769, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4769, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4769, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4769, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken'),

(22, 1, 4770, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4770, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4770, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4770, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4770, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken'),

(22, 1, 4772, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4772, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4772, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4772, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4772, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken'),

(22, 1, 4774, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4774, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4774, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4774, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4774, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4801,4802,4803,4804);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4801, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4801, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4801, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4801, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4801, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4802, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4802, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4802, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4802, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4802, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4803, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4803, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4803, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4803, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4803, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4804, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4804, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4804, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4804, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4804, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken');
UPDATE `quest_template` SET `SpecialFlags`=0 WHERE `Id` = 11122;
UPDATE `quest_template` SET `SpecialFlags`=0 WHERE `Id` = 11293;
UPDATE `quest_template` SET `SpecialFlags`=1 WHERE `Id` = 11293;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=184312 AND `source_type`=1 AND `id`=7;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=184311 AND `source_type`=1 AND `id`=8;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN(177964,174713,174712,174709,174708,174686,174608,174607,174605,174604,174602,174603,174596,173324,171939,173284,174601,174684,164885,164888,174599,174594,164887,174600,174598,164886,173327,174595,171942,174606,174597) AND `source_type`=1 AND `id`=0;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN(164885,164886,164887,164888,171939,171942,173284,173324,173327,174594,174595,174596,174597,174598,174599,174600,174601,174602,174603,174604,174605,174606,174607,174608,174684,174686,174708,174709,174712,174713,191124);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN(29525,29863,24198,23698,21611,21503);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN(8978,2706) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN(4675,28156) AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=21057 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=25806 AND `source_type`=0 AND `id`=2;
--
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=11038 WHERE `menu_id`=21278 AND `id`=0;

-- BroadcastTextID0
UPDATE `npc_text` SET `BroadcastTextID0`=3989 WHERE `ID`=1643;
UPDATE `npc_text` SET `BroadcastTextID0`=3991 WHERE `ID`=1644;
UPDATE `npc_text` SET `BroadcastTextID0`=3992 WHERE `ID`=1647;
UPDATE `npc_text` SET `BroadcastTextID0`=3993 WHERE `ID`=1648;
UPDATE `npc_text` SET `BroadcastTextID0`=3994 WHERE `ID`=1649;
UPDATE `npc_text` SET `BroadcastTextID0`=3996 WHERE `ID`=1650;
UPDATE `npc_text` SET `BroadcastTextID0`=4002 WHERE `ID`=1651;
UPDATE `npc_text` SET `BroadcastTextID0`=4004 WHERE `ID`=1652;
UPDATE `npc_text` SET `BroadcastTextID0`=4009 WHERE `ID`=1655;
UPDATE `npc_text` SET `BroadcastTextID0`=4011 WHERE `ID`=1656;
UPDATE `npc_text` SET `BroadcastTextID0`=4012 WHERE `ID`=1657;
UPDATE `npc_text` SET `BroadcastTextID0`=4083 WHERE `ID`=1693;
UPDATE `npc_text` SET `BroadcastTextID0`=4170 WHERE `ID`=1753;
UPDATE `npc_text` SET `BroadcastTextID0`=4171 WHERE `ID`=1754;
UPDATE `npc_text` SET `BroadcastTextID0`=4172 WHERE `ID`=1755;
UPDATE `npc_text` SET `BroadcastTextID0`=4173 WHERE `ID`=1756;
UPDATE `npc_text` SET `BroadcastTextID0`=4182 WHERE `ID`=1758;
UPDATE `npc_text` SET `BroadcastTextID0`=4184 WHERE `ID`=1759;

-- BroadcastTextID1
UPDATE `npc_text` SET `BroadcastTextID1`=2880 WHERE `ID`=882;
UPDATE `npc_text` SET `BroadcastTextID1`=6319 WHERE `ID`=905;
UPDATE `npc_text` SET `BroadcastTextID1`=6312 WHERE `ID`=922;
UPDATE `npc_text` SET `BroadcastTextID1`=6313 WHERE `ID`=923;
UPDATE `npc_text` SET `BroadcastTextID1`=6324 WHERE `ID`=928;
UPDATE `npc_text` SET `BroadcastTextID1`=5085 WHERE `ID`=2762;
UPDATE `npc_text` SET `BroadcastTextID1`=6343 WHERE `ID`=2769;
UPDATE `npc_text` SET `BroadcastTextID1`=5107 WHERE `ID`=2774;
UPDATE `npc_text` SET `BroadcastTextID1`=6349 WHERE `ID`=2775;
UPDATE `npc_text` SET `BroadcastTextID1`=6350 WHERE `ID`=2776;
UPDATE `npc_text` SET `BroadcastTextID1`=5116 WHERE `ID`=2794;
UPDATE `npc_text` SET `BroadcastTextID1`=6335 WHERE `ID`=2795;
UPDATE `npc_text` SET `BroadcastTextID1`=5365 WHERE `ID`=2797;
UPDATE `npc_text` SET `BroadcastTextID1`=6337 WHERE `ID`=2798;
UPDATE `npc_text` SET `BroadcastTextID1`=5132 WHERE `ID`=2801;
UPDATE `npc_text` SET `BroadcastTextID1`=6344 WHERE `ID`=2804;
UPDATE `npc_text` SET `BroadcastTextID1`=6347 WHERE `ID`=2807;
UPDATE `npc_text` SET `BroadcastTextID1`=5346 WHERE `ID`=3025;
UPDATE `npc_text` SET `BroadcastTextID1`=5358 WHERE `ID`=3036;
UPDATE `npc_text` SET `BroadcastTextID1`=5373 WHERE `ID`=3040;
UPDATE `npc_text` SET `BroadcastTextID1`=6361 WHERE `ID`=3042;
UPDATE `npc_text` SET `BroadcastTextID1`=6334 WHERE `ID`=3814;
UPDATE `npc_text` SET `BroadcastTextID1`=7053 WHERE `ID`=4310;
UPDATE `npc_text` SET `BroadcastTextID1`=10134 WHERE `ID`=7387;
UPDATE `npc_text` SET `BroadcastTextID1`=10367 WHERE `ID`=7484;
UPDATE `npc_text` SET `BroadcastTextID1`=10413 WHERE `ID`=7498;
UPDATE `npc_text` SET `BroadcastTextID1`=10418 WHERE `ID`=7500;
UPDATE `npc_text` SET `BroadcastTextID1`=10420 WHERE `ID`=7501;
UPDATE `npc_text` SET `BroadcastTextID1`=10391 WHERE `ID`=7502;
UPDATE `npc_text` SET `BroadcastTextID1`=10396 WHERE `ID`=7505;
UPDATE `npc_text` SET `BroadcastTextID1`=10399 WHERE `ID`=7506;
UPDATE `npc_text` SET `BroadcastTextID1`=10405 WHERE `ID`=7508;
UPDATE `npc_text` SET `BroadcastTextID1`=10407 WHERE `ID`=7509;
UPDATE `npc_text` SET `BroadcastTextID1`=10766 WHERE `ID`=15296;
UPDATE `npc_text` SET `BroadcastTextID1`=18268 WHERE `ID`=20551;
UPDATE `npc_text` SET `BroadcastTextID1`=18269 WHERE `ID`=20564;
UPDATE `npc_text` SET `BroadcastTextID1`=22227 WHERE `ID`=11256;
UPDATE `npc_text` SET `BroadcastTextID1`=45371 WHERE `ID`=16783;
UPDATE `npc_text` SET `BroadcastTextID1`=6111 WHERE `ID`=3668;
UPDATE `npc_text` SET `BroadcastTextID1`=10386 WHERE `ID`=7496;

-- BroadcastTextID2
UPDATE `npc_text` SET `BroadcastTextID2`=22228 WHERE `ID`=11256;
UPDATE `npc_text` SET `BroadcastTextID2`=18282 WHERE `ID`=20551;
UPDATE `npc_text` SET `BroadcastTextID2`=2909 WHERE `ID`=900;
UPDATE `npc_text` SET `BroadcastTextID2`=13816 WHERE `ID`=8893;

-- BroadcastTextID3
UPDATE `npc_text` SET `BroadcastTextID3`=2878 WHERE `ID`=879;

-- BroadcastTextID4
UPDATE `npc_text` SET `BroadcastTextID5`=13345 WHERE `ID`=8760;

-- Misc
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=3297;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=7530;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=7635;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=7669;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=8061;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=8480;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=8484;
UPDATE `npc_text` SET `text7_0`='' WHERE `ID`=8934;
--
SET @Linda :=32687;
SET @Alec :=32692;

UPDATE creature_template SET `AIName`='SmartAI' WHERE entry IN (@Linda, @Alec);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Linda AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Linda*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Linda*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Linda, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 87, @Linda*100, @Linda*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Linda - OOC_LOS - RANDOM_TIMED_ACTIONLIST'),
(@Linda*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Linda - RANDOM_TIMED_ACTIONLIST -  talk'),
(@Linda*100+1,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@Alec,5,0,0,0,0,0,'Linda - RANDOM_TIMED_ACTIONLIST -  talk');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Linda;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Linda,0,5,1090,128,0,0,'','event require Kirin Tor Exalted');


DELETE FROM creature_text WHERE entry IN (@Linda, @Alec);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Linda, 0, 0, 'There goes the finest $c I have the honor of knowing.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32866), 
(@Linda, 0, 1, '$n, you''re an inspiration.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32867), 
(@Linda, 0, 2, 'A fine example of a $g man:woman;, that $n.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32868), 
(@Linda, 0, 3, 'You couldn''t ask for a finer person than $n, I say.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32869), 
(@Linda, 0, 4, '$n, wonderful to see you. Wonderful.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32870),  
(@Linda, 0, 5, '$n! Ah, fantastic to see you out and about. Busy as always, hm?', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32871),

(@Alec, 0, 0, 'There goes the finest $c I have the honor of knowing.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32866), 
(@Alec, 0, 1, '$n, you''re an inspiration.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32867), 
(@Alec, 0, 2, 'A fine example of a $g man:woman;, that $n.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32868), 
(@Alec, 0, 3, 'You couldn''t ask for a finer person than $n, I say.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32869), 
(@Alec, 0, 4, '$n, wonderful to see you. Wonderful.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32870),  
(@Alec, 0, 5, '$n! Ah, fantastic to see you out and about. Busy as always, hm?', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32871);
--
SET @ENTRY := 29483;
SET @SPELL_ENERGY_SURGE := 54559;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` =@ENTRY;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|4|33554432, `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 9, 0, 100, 0, 1, 20, 1000, 1000, 11, @SPELL_ENERGY_SURGE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'K3 Perimeter Turret - Within 1-20 Range - Cast ''Energy Surge''');
ALTER TABLE `creature` ADD `zoneId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Zone Identifier' AFTER `map`;
ALTER TABLE `creature` ADD `areaId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Area Identifier' AFTER `zoneId`;

ALTER TABLE `gameobject` ADD `zoneId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Zone Identifier' AFTER `map`;
ALTER TABLE `gameobject` ADD `areaId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Area Identifier' AFTER `zoneId`;
SET @CGUID :=74960;
SET @OGUID :=21104;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0 , 24545, 530, 1, 1, -1882.759, 5575.42, -12.3448, 4.677482, 120, 0, 0), -- Thunderbrew "Apprentice" (Area: Shattrath City)
(@CGUID+1 , 24484, 530, 1, 1, -1872.835, 5560.321, -12.3448, 2.748216, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43910 - Brewfest Reveler - Gnome)
(@CGUID+2 , 24484, 530, 1, 1, -1878.838, 5562.812, -12.3448, 5.889809, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+3 , 24484, 530, 1, 1, -1878.618, 5556.088, -12.3448, 3.259485, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43910 - Brewfest Reveler - Gnome)
(@CGUID+4 , 24484, 530, 1, 1, -1897.398, 5558.127, -12.3448, 1.710423, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44004 - Brewfest Reveler - Goblin - Female)
(@CGUID+5 , 24484, 530, 1, 1, -1899.819, 5560.333, -12.3448, 0.3665192, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44003 - Brewfest Reveler - Goblin - Male)
(@CGUID+6 , 24484, 530, 1, 1, -1921.889, 5554.328, -12.34481, 0.04066804, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43916 - Brewfest Reveler - Troll)
(@CGUID+7 , 24484, 530, 1, 1, -1916.578, 5551.592, -12.34481, 2.666002, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43917 - Brewfest Reveler - Undead)
(@CGUID+8 , 24484, 530, 1, 1, -1924.595, 5549.645, -12.3448, 1.046868, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43914 - Brewfest Reveler - Orc)
(@CGUID+9 , 24484, 530, 1, 1, -1897.494, 5562.316, -12.3448, 4.433136, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44003 - Brewfest Reveler - Goblin - Male)
(@CGUID+10, 24501, 530, 1, 1, -1926.787, 5562.968, -12.3448, 5.061455, 120, 0, 0), -- Drohn's Distillery Apprentice (Area: Shattrath City)
(@CGUID+11, 24484, 530, 1, 1, -1895.234, 5560.195, -12.34481, 2.80998, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44003 - Brewfest Reveler - Goblin - Male)
(@CGUID+12, 23511, 530, 1, 1, -1906.297, 5569.852, -12.3448, 4.974188, 120, 0, 0); -- Gordok Brew Apprentice (Area: Shattrath City)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+1 , 0, 0x0, 0x101, '43910'), -- Brewfest Reveler - 43910 - Brewfest Reveler - Gnome
(@CGUID+2 , 0, 0x0, 0x101, '43909'), -- Brewfest Reveler - 43909 - Brewfest Reveler - Dwarf
(@CGUID+3 , 0, 0x0, 0x101, '43910'), -- Brewfest Reveler - 43910 - Brewfest Reveler - Gnome
(@CGUID+4 , 0, 0x0, 0x101, '44004'), -- Brewfest Reveler - 44004 - Brewfest Reveler - Goblin - Female
(@CGUID+5 , 0, 0x0, 0x101, '44003'), -- Brewfest Reveler - 44003 - Brewfest Reveler - Goblin - Male
(@CGUID+6 , 0, 0x0, 0x101, '43916'), -- Brewfest Reveler - 43916 - Brewfest Reveler - Troll
(@CGUID+7 , 0, 0x0, 0x101, '43917'), -- Brewfest Reveler - 43917 - Brewfest Reveler - Undead
(@CGUID+8 , 0, 0x0, 0x101, '43914'), -- Brewfest Reveler - 43914 - Brewfest Reveler - Orc
(@CGUID+9 , 0, 0x0, 0x101, '44003'), -- Brewfest Reveler - 44003 - Brewfest Reveler - Goblin - Male
(@CGUID+11, 0, 0x0, 0x101, '44003'); -- Brewfest Reveler - 44003 - Brewfest Reveler - Goblin - Male

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 186259, 530, 1, 1, -1875.389, 5579.114, -12.42814, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- Thunderbrew Festive Wagon (Area: Shattrath City)
(@OGUID+1, 180037, 530, 1, 1, -1909.218, 5569.716, -12.42814, 4.97419, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Shattrath City)
(@OGUID+2, 180037, 530, 1, 1, -1906.963, 5573.009, -12.42814, 3.47321, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Shattrath City)
(@OGUID+3, 178666, 530, 1, 1, -1882.575, 5582.089, -12.42814, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Gypsy Wagon (Area: Shattrath City)
(@OGUID+4, 178666, 530, 1, 1, -1928.171, 5567.508, -12.42814, 3.38594, 0, 0, 0, 1, 120, 255, 1), -- Gypsy Wagon (Area: Shattrath City)
(@OGUID+5, 186255, 530, 1, 1, -1920.9, 5568.442, -12.42814, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Drohn's Distillery Festive Wagon (Area: Shattrath City)
(@OGUID+6, 186257, 530, 1, 1, -1900.552, 5575.883, -12.42814, 1.937312, 0, 0, 0, 1, 120, 255, 1), -- Gordok Festive Wagon (Area: Shattrath City)
(@OGUID+7, 180037, 530, 1, 1, -1893.456, 5576.866, -12.42814, 4.223697, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Shattrath City)
(@OGUID+8, 180037, 530, 1, 1, -1904.326, 5571.048, -12.42814, 1.902409, 0, 0, 0, 1, 120, 255, 1); -- Haybail 01 (Area: Shattrath City)

DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, @CGUID+0),
(24, @CGUID+1),
(24, @CGUID+2),
(24, @CGUID+3),
(24, @CGUID+4),
(24, @CGUID+5),
(24, @CGUID+6),
(24, @CGUID+7),
(24, @CGUID+8),
(24, @CGUID+9),
(24, @CGUID+10),
(24, @CGUID+11),
(24, @CGUID+12);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=24 AND `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(24, @OGUID+0),
(24, @OGUID+1),
(24, @OGUID+2),
(24, @OGUID+3),
(24, @OGUID+4),
(24, @OGUID+5),
(24, @OGUID+6),
(24, @OGUID+7),
(24, @OGUID+8);
--
UPDATE `npc_text` SET `BroadcastTextID0`=5793 WHERE `ID`=3464;
UPDATE `npc_text` SET `BroadcastTextID0`=10046 WHERE `ID`=7339;
UPDATE `npc_text` SET `BroadcastTextID0`=10048 WHERE `ID`=7340;
UPDATE `npc_text` SET `BroadcastTextID0`=10053 WHERE `ID`=7341;
UPDATE `npc_text` SET `BroadcastTextID0`=10062 WHERE `ID`=7355;
UPDATE `npc_text` SET `BroadcastTextID0`=10065 WHERE `ID`=7356;
UPDATE `npc_text` SET `BroadcastTextID0`=10082 WHERE `ID`=7362;
UPDATE `npc_text` SET `BroadcastTextID0`=10086 WHERE `ID`=7363;
UPDATE `npc_text` SET `BroadcastTextID0`=10092 WHERE `ID`=7365;
UPDATE `npc_text` SET `BroadcastTextID0`=10210 WHERE `ID`=7437;
UPDATE `npc_text` SET `BroadcastTextID0`=10366 WHERE `ID`=7484;
UPDATE `npc_text` SET `BroadcastTextID0`=10412 WHERE `ID`=7498;
UPDATE `npc_text` SET `BroadcastTextID0`=10417 WHERE `ID`=7500;
UPDATE `npc_text` SET `BroadcastTextID0`=10419 WHERE `ID`=7501;
UPDATE `npc_text` SET `BroadcastTextID0`=10390 WHERE `ID`=7502;
UPDATE `npc_text` SET `BroadcastTextID0`=10395 WHERE `ID`=7505;
UPDATE `npc_text` SET `BroadcastTextID0`=10404 WHERE `ID`=7508;
UPDATE `npc_text` SET `BroadcastTextID0`=10406 WHERE `ID`=7509;
UPDATE `npc_text` SET `BroadcastTextID0`=10466 WHERE `ID`=7596;
UPDATE `npc_text` SET `BroadcastTextID0`=10468 WHERE `ID`=7597;
UPDATE `npc_text` SET `BroadcastTextID0`=10470 WHERE `ID`=7598;
UPDATE `npc_text` SET `BroadcastTextID0`=10475 WHERE `ID`=7614;
UPDATE `npc_text` SET `BroadcastTextID0`=10493 WHERE `ID`=7641;
UPDATE `npc_text` SET `BroadcastTextID0`=10543 WHERE `ID`=7674;
UPDATE `npc_text` SET `BroadcastTextID0`=10547 WHERE `ID`=7676;
UPDATE `npc_text` SET `BroadcastTextID0`=10548 WHERE `ID`=7677;
UPDATE `npc_text` SET `BroadcastTextID0`=10557 WHERE `ID`=7683;
UPDATE `npc_text` SET `BroadcastTextID0`=17814 WHERE `ID`=20201;
UPDATE `npc_text` SET `BroadcastTextID0`=27613 WHERE `ID`=13100;
UPDATE `npc_text` SET `BroadcastTextID0`=9499 WHERE `ID`=6938;
UPDATE `npc_text` SET `BroadcastTextID0`=6016 WHERE `ID`=447;
UPDATE `npc_text` SET `BroadcastTextID0`=20391 WHERE `ID`=10412;
UPDATE `npc_text` SET `BroadcastTextID0`=19868 WHERE `ID`=10616;
UPDATE `npc_text` SET `BroadcastTextID0`=14430 WHERE `ID`=9080;
UPDATE `npc_text` SET `BroadcastTextID0`=10567 WHERE `ID`=7692;
UPDATE `npc_text` SET `BroadcastTextID0`=6001 WHERE `ID`=3579;
UPDATE `npc_text` SET `BroadcastTextID0`=5035 WHERE `ID`=2725;
--
UPDATE `creature` SET `map`=571 WHERE `guid`=101828 AND `id`=25434;
UPDATE `creature` SET `position_y`=-6381.79 WHERE `guid`=82822 AND `id`=16303;
UPDATE `creature` SET `position_y`=-6395.32 WHERE `guid`=82826 AND `id`=16303;
UPDATE `creature` SET `position_y`=-6343.51 WHERE `guid`=82827 AND `id`=16303;
UPDATE `creature` SET `map`=1 WHERE `guid`=40251 AND `id`=29346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(25285,31033);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25285,31033) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2528500 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25285, 0, 0, 0, 10, 0, 100, 0, 1, 50, 120000, 300000, 80, 2528500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - OOC LOS - Run Script'),
(31033, 0, 0, 0, 10, 0, 100, 0, 1, 20, 600000, 900000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Crusader of Virtue - OOC LOS - Say Line'),
(2528500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 0'),
(2528500, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25301, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 0 (Counselor Talbot)'),
(2528500, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 25250, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 2 (General Arlos)'),
(2528500, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 1');

DELETE FROM `creature_text` WHERE `entry` IN(25301,25285,31033);
DELETE FROM `creature_text` WHERE `entry` =25250 AND `groupid`=2;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25250, 2, 0, 'Your offer will be carefully considered, harbinger.  In the meantime we will make use of your delegation in an advisory role.', 12, 7, 100, 1, 0, 0, 'General Arlos',24790),
(25301, 0, 0, 'Our troops, general, consist mostly of villagers and peasants.  Good men, but not quite rid of the prejudices and superstitions of their upbringing.  They''re not ready to fight alongside our more exotic allies.', 12, 7, 100, 1, 0, 0, 'Counselor Talbot',24789),
(25285, 0, 0, 'Give the word, general.  I will have two regiments at your disposal in a month''s time.', 12, 7, 100, 0, 0, 0, 'Harbinger Vurenn',24787),
(25285, 1, 0, 'Very well, general.  Should you change your mind, my people will be more than willing to provide military assistance.', 12, 7, 100, 0, 0, 0, 'Harbinger Vurenn',24788),
(31033, 0, 0, 'There goes the hero of the Vanguard!', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31385),
(31033, 0, 1, '%s cheers at you.', 16, 1, 100, 71, 0, 0, 'Crusader of Virtue',25275),
(31033, 0, 2, 'We couldn''t have done it without you, $g sir:ma''am;.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31384),
(31033, 0, 3, 'You honor us with your presence, $n.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31386),
(31033, 0, 4, 'Thank you, $n. From the bottom of my heart. Thank you.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31388),
(31033, 0, 5, 'Call on me anytime, $n.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31389);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=31033;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 31033, 0, 0, 8, 0, 13157, 0, 0, 0, 0, 0, '', 'Crusader of Virtue - Only run SAI if player is rewarded for quest 13157');
--
UPDATE `creature_text` SET `BroadcastTextId`=9633 WHERE `entry`=14467 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=7798 WHERE `entry`=701 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=8355 WHERE `entry`=12923 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=8355 WHERE `entry`=12924 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=8355 WHERE `entry`=12925 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=10601 WHERE `entry`=11380 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=23175 WHERE `entry`=23863 AND `groupid`=2 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=23176 WHERE `entry`=23863 AND `groupid`=3 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=23178 WHERE `entry`=23863 AND `groupid`=5 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=23179 WHERE `entry`=23863 AND `groupid`=6 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=23181 WHERE `entry`=23863 AND `groupid`=8 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=23182 WHERE `entry`=23863 AND `groupid`=8 AND `id`=1;
UPDATE `creature_text` SET `BroadcastTextId`=23183 WHERE `entry`=23863 AND `groupid`=9 AND `id`=0;
-- BroadcastTextID0
UPDATE `npc_text` SET `BroadcastTextID0`=3962 WHERE `ID`=1620;
UPDATE `npc_text` SET `BroadcastTextID0`=3963 WHERE `ID`=1621;
UPDATE `npc_text` SET `BroadcastTextID0`=8806 WHERE `ID`=6789;
UPDATE `npc_text` SET `BroadcastTextID0`=9168 WHERE `ID`=6789;
UPDATE `npc_text` SET `BroadcastTextID0`=9626 WHERE `ID`=7002;
UPDATE `npc_text` SET `BroadcastTextID0`=9628 WHERE `ID`=7003;
UPDATE `npc_text` SET `BroadcastTextID0`=9630 WHERE `ID`=7004;
UPDATE `npc_text` SET `BroadcastTextID0`=9632 WHERE `ID`=7005;
UPDATE `npc_text` SET `BroadcastTextID0`=11275 WHERE `ID`=8060;
UPDATE `npc_text` SET `BroadcastTextID0`=11892 WHERE `ID`=8326;
UPDATE `npc_text` SET `BroadcastTextID0`=11894 WHERE `ID`=8327;
UPDATE `npc_text` SET `BroadcastTextID0`=12100 WHERE `ID`=8426;
UPDATE `npc_text` SET `BroadcastTextID0`=12280 WHERE `ID`=8516;
UPDATE `npc_text` SET `BroadcastTextID0`=14071 WHERE `ID`=8975;
UPDATE `npc_text` SET `BroadcastTextID0`=14386 WHERE `ID`=9064;
UPDATE `npc_text` SET `BroadcastTextID0`=17555 WHERE `ID`=9949;
UPDATE `npc_text` SET `BroadcastTextID0`=19019 WHERE `ID`=10339;
UPDATE `npc_text` SET `BroadcastTextID0`=19431 WHERE `ID`=10454;
UPDATE `npc_text` SET `BroadcastTextID0`=20459 WHERE `ID`=10733;
UPDATE `npc_text` SET `BroadcastTextID0`=20643 WHERE `ID`=10798;
UPDATE `npc_text` SET `BroadcastTextID0`=20883 WHERE `ID`=10830;
UPDATE `npc_text` SET `BroadcastTextID0`=21404 WHERE `ID`=10926;
UPDATE `npc_text` SET `BroadcastTextID0`=21535 WHERE `ID`=10967;
UPDATE `npc_text` SET `BroadcastTextID0`=21542 WHERE `ID`=10976;
UPDATE `npc_text` SET `BroadcastTextID0`=21610 WHERE `ID`=11026;
UPDATE `npc_text` SET `BroadcastTextID0`=21618 WHERE `ID`=11029;
UPDATE `npc_text` SET `BroadcastTextID0`=21814 WHERE `ID`=11059;

-- npc_text
UPDATE `npc_text` SET `BroadcastTextID0`=10796 WHERE `ID`=7804;
UPDATE `npc_text` SET `BroadcastTextID0`=2545 WHERE `ID`=6491;
UPDATE `npc_text` SET `BroadcastTextID0`=6877 WHERE `ID`=4194;

-- creature_text
UPDATE `creature_text` SET `BroadcastTextId`=6198 WHERE `entry`=3977 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=35523 WHERE `entry`=35320 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=35529 WHERE `entry`=35320 AND `groupid`=1 AND `id`=0;
--
UPDATE `creature_template` SET `faction`=834 WHERE `entry`=14435;
UPDATE `creature_template` SET `faction`=90 WHERE `entry`=6268;
--
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=21611;
DELETE FROM `waypoint_data` WHERE `id`=1131170;
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=113117;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=113117;

DELETE FROM `waypoints` WHERE `entry`=23734;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(23734, 1, 629.388, -5021.37, 3.04091, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 2, 630.836, -5011.95, 3.8314, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 3, 630.836, -5011.95, 3.8314, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 4, 624.458, -5003.92, 3.59241, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 5, 614.28, -5005.49, 3.06355, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 6, 607.946, -5014.89, 3.10032, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 7, 612.983, -5025.49, 2.03711, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 8, 625.177, -5026.14, 2.32847, 'Anchorite Yazmina <First Aid Trainer>');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(23734,23728);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23734,23728) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2373400,2373401,2373402,2373403,237404,2372800) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23734, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 23734, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - On Spawn - Start WP'),
(23734, 0, 1, 0, 40, 0, 5, 0, 0, 0, 0, 0, 87, 2373400,2373401,2373402,2373403,0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - On Reached WP - Run Random Script'),
(23728, 0, 0, 0, 10, 0, 100, 0, 1, 50, 120000, 300000, 80, 2372800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - OOC LOS - Run Script'),
(2372800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 0'),
(2372800, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 1'),
(2372800, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 2'),
(2372800, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 3'),
(2373400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 1 - Pause WP'),
(2373401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Pause WP'),
(2373401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 23783, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Face Injured Defender'),
(2373401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Say Line 1'),
(2373401, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Set Bytes 1'),
(2373401, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Set Emote State 69'),
(2373401, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Set Emote State 0'),
(2373401, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Say Line 2'),
(2373401, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Remove Bytes 1'),
(2373402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Pause WP'),
(2373402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 23783, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Face Injured Defender'),
(2373402, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Say Line 3'),
(2373402, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Set Bytes 1'),
(2373402, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Set Emote State 69'),
(2373402, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Set Emote State 0'),
(2373402, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Say Line 0'),
(2373402, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Remove Bytes 1'),
(2373403, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Pause WP'),
(2373403, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 23783, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Face Injured Defender'),
(2373403, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Say Line 4'),
(2373403, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Set Bytes 1'),
(2373403, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Set Emote State 69'),
(2373403, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Set Emote State 0'),
(2373403, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Say Line 5'),
(2373403, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Remove Bytes 1');

DELETE FROM `creature_text` WHERE `entry` IN(23734,23728);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(23734, 0, 0, 'That should slow the infection down a little.', 12, 7, 100, 1, 0, 0, 'Anchorite Yazmina',22251),
(23734, 1, 0, 'I can only hope the treatment will work.', 12, 7, 100, 1, 0, 0, 'Anchorite Yazmina',22828),
(23734, 2, 0, 'I just don''t have the medical supplies I need to properly treat all of you.', 12, 7, 100, 1, 0, 5495, 'Anchorite Yazmina',22829),
(23734, 3, 0, 'Oh my, let me change those bandages!', 12, 7, 100, 5, 0, 0, 'Anchorite Yazmina',22250),
(23734, 4, 0, 'Don''t worry, soldier. Yazmina is going to take care of you.', 12, 7, 100, 1, 0, 0, 'Anchorite Yazmina',22830),
(23734, 5, 0, '%s shakes her head.', 16, 7, 100, 274, 0, 0, 'Anchorite Yazmina',22831),
(23728, 0, 0, '%s clears his throat.', 16, 7, 100, 0, 0, 0, 'Guard Captain Zorek',22737),
(23728, 1, 0, 'I look across this base and all I see is fear... Are you gonna be scared when the Lich King''s armies are sittin'' pretty in Stormwind? Ironforge? NO! You''re not. And do you know why? Because you''ll be dead, that''s why.', 12, 7, 100, 1, 0, 0, 'Guard Captain Zorek',22738),
(23728, 2, 0, 'So when you''re feeling that tinglin'' sensation at the base of your spine and you''re ''bout ready to wet your pants, embrace it. Let it enrage you. That fear is the only thing that''s gonna keep you breathin''.', 12, 7, 100, 25, 0, 0, 'Guard Captain Zorek',22739),
(23728, 3, 0, 'Am I clear? Do you understand what I''m sayin''? I don''t wanna have to send any more coffins or letters home.', 12, 7, 100, 6, 0, 0, 'Guard Captain Zorek',22740);
--
UPDATE `smart_scripts` SET `entryorguid`='21661' WHERE `entryorguid`=21611;
DELETE FROM `gameobject_template` WHERE `entry` IN (184718,184722);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `data0`, `data1`, `data2`, `data3`, `size`, `VerifiedBuild`) VALUES
(184718, 6, 327, 'Cauldron Summoner', 0, 0, 0, 36549, 1, -18019),
(184722, 6, 327, 'Cauldron Bug Summoner', 0, 0, 0, 36552, 1, -18019);

DELETE FROM `gameobject` WHERE  `guid` IN(25566,25567) AND `id` IN(184721,184717,184722,184718);

INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(25566, 184718, 530, 1, 1, -970.813, 2172, 15.5428, -2.33874, 0, 0, 0.920505, -0.390731, 0, 100, 1, 0),
(25567, 184722, 530, 1, 1, -970.813, 2172, 15.5428, -2.33874, 0, 0, 0.920505, -0.390731, 0, 100, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=36546;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 36546, 0, 0, 31, 0, 5, 184715, 0, 0, 0, 0, '', 'Boil Bleeding Hollow Blood - Cursed Cauldron'),
(13, 2, 36546, 0, 0, 31, 0, 5, 184722, 0, 0, 0, 0, '', 'Boil Bleeding Hollow Blood - Cauldron Bug Summoner');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(21308,21306);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21308,21306) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21308, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 36555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab Summoner - On Spawn - Cast Summon Cursed Scarabs'),
(21306, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 89, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Set Random Movement'),
(21306, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Set Run On'),
(21306, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 36556, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Cast Cursed Scarab Periodic'),
(21306, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 36559, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Cast Cursed Scarab Despawn Timer'),
(21306, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 31309, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Cast Spirit Particles (red, big)'),
(21306, 0, 5, 0, 8, 0, 100, 0, 36560, 0, 0, 0, 41, 40000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spellhit (Cursed Scarab Despawn Periodic Trigger) - Despawn'),
(21306, 0, 6, 7, 1, 0, 100, 1, 5000, 90000, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - OOC - Set faction'),
(21306, 0, 7, 8, 61, 0, 100, 1, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - OOC - Set Hostile'),
(21306, 0, 8, 0, 61, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - OOC - Attack Sumoner');
-- npc_text
UPDATE `npc_text` SET `BroadcastTextID0`=5195 WHERE `ID`=2838;
UPDATE `npc_text` SET `BroadcastTextID0`=11738 WHERE `ID`=8296;
UPDATE `npc_text` SET `BroadcastTextID0`=11790 WHERE `ID`=8282;
UPDATE `npc_text` SET `BroadcastTextID0`=11797 WHERE `ID`=8298;
UPDATE `npc_text` SET `BroadcastTextID0`=20625 WHERE `ID`=10787;
UPDATE `npc_text` SET `BroadcastTextID0`=37804 WHERE `ID`=15240;
UPDATE `npc_text` SET `BroadcastTextID0`=11736 WHERE `ID`=8244;
UPDATE `npc_text` SET `BroadcastTextID0`=11799 WHERE `ID`=8291;
UPDATE `npc_text` SET `BroadcastTextID0`=12770 WHERE `ID`=8663;
UPDATE `npc_text` SET `BroadcastTextID0`=14410 WHERE `ID`=9072;
UPDATE `npc_text` SET `BroadcastTextID0`=14546 WHERE `ID`=9110;
UPDATE `npc_text` SET `BroadcastTextID0`=17748 WHERE `ID`=9984;
UPDATE `npc_text` SET `BroadcastTextID0`=21971 WHERE `ID`=11093;
UPDATE `npc_text` SET `BroadcastTextID0`=27167 WHERE `ID`=12978;
UPDATE `npc_text` SET `BroadcastTextID0`=32577 WHERE `ID`=14089;
UPDATE `npc_text` SET `BroadcastTextID0`=37148 WHERE `ID`=15155;
UPDATE `npc_text` SET `BroadcastTextID0`=38655 WHERE `ID`=15412;
UPDATE `npc_text` SET `BroadcastTextID0`=40449 WHERE `ID`=15866;
UPDATE `npc_text` SET `BroadcastTextID0`=40471 WHERE `ID`=15873;
UPDATE `npc_text` SET `BroadcastTextID0`=40482 WHERE `ID`=15877;
