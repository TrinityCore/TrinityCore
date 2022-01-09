-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (29691, 29688, 29689) ;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29691,0,7,1,0, ""),
(29688,0,0,1,233, ""),
(29689,0,0,1,333, "");
UPDATE `gossip_menu_option` SET `OptionType`=3, `OptionNpcFlag`=128 WHERE `MenuID` IN (9848);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`= 29468;
UPDATE `creature` SET `position_x`=5766.979492, `position_y`=-1617.112793, `position_z`=234.942978, `orientation`=0.605617 WHERE `guid`= 97401;
