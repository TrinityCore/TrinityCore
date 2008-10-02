DELETE FROM `spell_proc_event` WHERE `entry` IN ( '31830','31829','31828');
INSERT INTO `spell_proc_event` VALUES 
('31828', '0', '0', '0', '0', '32768', '0'),
('31829', '0', '0', '0', '0', '32768', '0'),
('31830', '0', '0', '0', '0', '32768', '0');

DELETE FROM `spell_proc_event` WHERE `entry` IN ( '33776','31785');
INSERT INTO `spell_proc_event` VALUES 
('31785', '0', '0', '0', '0', '536870912', '0'),
('33776', '0', '0', '0', '0', '536870912', '0');
