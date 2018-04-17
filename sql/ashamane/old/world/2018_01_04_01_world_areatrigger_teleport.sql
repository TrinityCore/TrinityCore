UPDATE areatrigger SET spawn_mask = 8388870 WHERE spawn_mask = 8388614;

ALTER TABLE `areatrigger_teleport` CHANGE `ID` `ID` BIGINT(20) DEFAULT 0 NOT NULL; 
