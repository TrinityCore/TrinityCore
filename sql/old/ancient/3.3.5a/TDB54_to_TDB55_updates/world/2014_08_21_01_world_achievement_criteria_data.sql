-- Supreme Defender
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3698, 3699);
INSERT INTO `achievement_criteria_data` VALUES
(3698,6,3277,0,''),
(3698,7,23335,0,''), -- Alliance target should have Alliance Flag buff
(3699,6,3277,0,''),
(3699,7,23333,0,''); -- Horde target should have Horde Flag buff
