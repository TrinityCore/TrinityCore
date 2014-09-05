-- Move cs_misc command output hardcoded strings to DB so they can be localized too
DELETE FROM `trinity_string` WHERE `entry` IN (5030,5035,5039,5040,5041,5042,5043,5044);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5030, '<unauthorized>'),
(5035, 'No reason'),
(5039, 'Console'),
(5040, 'Character'),
(5041, 'Permanently'),
(5042, 'You are outdoors'),
(5043, 'You are indoors'),
(5044, 'no VMAP available for area info');
