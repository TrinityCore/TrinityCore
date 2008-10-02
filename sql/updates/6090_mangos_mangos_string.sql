DELETE FROM `mangos_string` WHERE `entry` IN (583,584,585,586,587,588);

INSERT INTO `mangos_string` VALUES
(583,'%d - |cffffffff|Hgameevent:%d|h[%s]|h|r%s',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(584,'No event found!',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(585,'Event not exist!',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(586,'Event %u: %s%s\nStart: %s End: %s Occurence: %s Length: %s\nNext state change: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(587,'Event %u already active!',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(588,'Event %u not active!',NULL,NULL,NULL,NULL,NULL,NULL,NULL);
