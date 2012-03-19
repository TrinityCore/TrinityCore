DELETE FROM `command` WHERE `name`='modify scale';
INSERT INTO `command` VALUES
('modify scale',1,'.modify scale #scale\nModify size of the selected player or creature to \"normal scale\"*rate. If no player or creature is selected, modify your size.\n#rate may range from 0.1 to 10.');
