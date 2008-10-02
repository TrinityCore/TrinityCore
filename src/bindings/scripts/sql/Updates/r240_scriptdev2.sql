ALTER TABLE `eventai_scripts`
ADD `event_inverse_phase_mask` int(11) signed NOT NULL default '0', COMMENT 'Mask which phases this event will not trigger in';