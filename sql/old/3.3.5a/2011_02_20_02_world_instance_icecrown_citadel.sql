SET @GUID := 137746;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+30 AND @GUID+33;
DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (@GUID+06,@GUID+07) AND `linkType`=0;
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
(@GUID+00,@GUID+06,0), -- Valithria Dreamwalker
(@GUID+01,@GUID+06,0), -- Valithria Dreamwalker
(@GUID+02,@GUID+06,0), -- Risen Archmage
(@GUID+03,@GUID+06,0), -- Risen Archmage
(@GUID+04,@GUID+06,0), -- Risen Archmage
(@GUID+05,@GUID+06,0), -- Risen Archmage
(@GUID+06,@GUID+06,0), -- Green Dragon Combat Trigger
(@GUID+07,@GUID+07,0), -- Sister Svalna
(@GUID+08,@GUID+07,0), -- Ymirjar Frostbinder
(@GUID+09,@GUID+07,0), -- Ymirjar Frostbinder
(@GUID+10,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+11,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+12,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+13,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+14,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+15,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+16,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+17,@GUID+07,0), -- Ymirjar Battle-Maiden
(@GUID+18,@GUID+07,0), -- Ymirjar Warlord
(@GUID+19,@GUID+07,0), -- Ymirjar Warlord
(@GUID+20,@GUID+07,0), -- Ymirjar Warlord
(@GUID+21,@GUID+07,0), -- Ymirjar Warlord
(@GUID+22,@GUID+07,0), -- Ymirjar Huntress
(@GUID+23,@GUID+07,0), -- Ymirjar Huntress
(@GUID+24,@GUID+07,0), -- Ymirjar Huntress
(@GUID+25,@GUID+07,0), -- Ymirjar Huntress
(@GUID+26,@GUID+07,0), -- Ymirjar Huntress
(@GUID+27,@GUID+07,0), -- Ymirjar Huntress
(@GUID+28,@GUID+07,0), -- Ymirjar Deathbringer
(@GUID+29,@GUID+07,0), -- Ymirjar Deathbringer
(151761,@GUID+07,0), -- Captain Arnath
(151762,@GUID+07,0), -- Captain Brandon
(151763,@GUID+07,0), -- Captain Grondel
(151764,@GUID+07,0), -- Captain Rupert
(151767,@GUID+07,0); -- Crok Scourgebane

SET @EQUIP := 2423;
DELETE FROM `creature_equip_template` WHERE `entry` BETWEEN @EQUIP AND @EQUIP+3;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EQUIP+0,45128,0,0),
(@EQUIP+1,47519,0,0),
(@EQUIP+2,45075,0,0),
(@EQUIP+3,48025,0,47521);

DELETE FROM `creature_template` WHERE `entry` IN (3712202,3712203,3712302,3712303,3712402,3712403,3712502,3712503,3712902,3712903);
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37122; -- Captain Arnath
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37123; -- Captain Brandon
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37124; -- Captain Grondel
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37125; -- Captain Rupert
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37129; -- Crok Scourgebane

UPDATE `creature_template` SET `baseattacktime`=1500,`equipment_id`=@EQUIP+0 WHERE `entry` IN (37122,38298); -- Captain Arnath
UPDATE `creature_template` SET `baseattacktime`=1500,`equipment_id`=@EQUIP+1 WHERE `entry` IN (37123,38299); -- Captain Brandon
UPDATE `creature_template` SET `baseattacktime`=1500,`equipment_id`=@EQUIP+2 WHERE `entry` IN (37124,38303); -- Captain Grondel
UPDATE `creature_template` SET `baseattacktime`=1500,`equipment_id`=@EQUIP+3 WHERE `entry` IN (37125,38304); -- Captain Rupert
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=2050 WHERE `entry` IN (37129,38000); -- Crok Scourgebane
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=38752; -- Green Dragon Combat Trigger
