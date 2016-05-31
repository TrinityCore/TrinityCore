UPDATE `creature_template` SET `gossip_menu_id`=8074 WHERE `entry`=19466; -- Exarch Orelis
UPDATE `creature_template` SET `gossip_menu_id`=8216 WHERE `entry`=20920; -- Magister Theledorn
UPDATE `creature_template` SET `gossip_menu_id`=8661 WHERE `entry`=21112; -- Bossi Pentapiston <Engineering Supplies>

DELETE FROM `gossip_menu` WHERE (`entry`=8074 AND `text_id`=9980) OR
(`entry`=8216 AND `text_id`=10211) OR
(`entry`=8304 AND `text_id`=10360) OR
(`entry`=8370 AND `text_id`=10444) OR
(`entry`=8385 AND `text_id`=10466) OR
(`entry`=8661 AND `text_id`=10889);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8074, 9980), -- 19466
(8216, 10211), -- 20920
(8304, 10360), -- 21461
(8370, 10444), -- 21755
(8385, 10466), -- 21824
(8661, 10889); -- 21112
