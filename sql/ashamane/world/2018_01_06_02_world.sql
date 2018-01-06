DELETE FROM `creature_template_addon` WHERE `entry` IN (112958,5502,11827,11828,5504,114246,9977,7295,5505,5506,112912);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`auras`) VALUES
(112958,0, 0, 0,   1, 0, 0, 0, 0, ''), -- Soulare of Andorhal
(5502,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Shylamiir
(11827, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Kimberly Grant
(11828, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Kelly Grant
(5504,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sheldras Moontree
(114246,0, 0, 0, 256, 0, 0, 0, 0, ''), -- Karl Wogksch
(9977,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sylista
(7295,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Shailiea
(5505,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Theridran
(5506,  0, 0, 0, 257, 0, 0, 0, 0, ''); -- Maldryn

UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `faction`=2110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112958; -- Soulare of Andorhal
UPDATE `creature_template` SET `npcflag`=17, `unit_flags`=512, `flags_extra`=0 WHERE `entry`=5502; -- Shylamiir
UPDATE `creature_template` SET `unit_flags`=512, `flags_extra`=0 WHERE `entry`=11828; -- Kelly Grant
UPDATE `creature_template` SET `unit_flags`=512, `flags_extra`=0 WHERE `entry`=11827; -- Kimberly Grant
UPDATE `creature_template` SET `gossip_menu_id`=0, `flags_extra`=0 WHERE `entry`=5504; -- Sheldras Moontree
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction`=12, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=114246; -- Karl Wogksch
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=4194433, `flags_extra`=0 WHERE `entry`=9977; -- Sylista
UPDATE `creature_template` SET `unit_flags`=512, `flags_extra`=0 WHERE `entry`=7295; -- Shailiea
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags`=512, `flags_extra`=0 WHERE `entry`=5505; -- Theridran
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags`=512, `flags_extra`=0 WHERE `entry`=5506; -- Maldryn

DELETE FROM `gossip_menu` WHERE (`MenuID`=14103 AND `TextID`=4783) OR (`MenuID`=14102 AND `TextID`=4783);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(14103, 4783), -- 5505 (Theridran)
(14102, 4783); -- 5504 (Sheldras Moontree)

-- Stormwind City Cemetery gameobject
DELETE FROM `page_text` WHERE `ID`= 3715; -- Tiffin Ellerian Wrynn Memorial (206500)
INSERT INTO `page_text` (`ID`,`Text`,`NextPageID`,`PlayerConditionID`,`Flags`,`VerifiedBuild`) VALUES
(3715,'Tiffin Ellerian Wrynn \nQueen of Stormwind \nFair and just, a wit as quick as her smile. \nMay the Light inherit your warmth, for our world grows cold in your absence. ',0,0,0,23420);
