SET @allowedFlags := 0x00000001 | 0x00000008 | 0x00000200 | 0x00001000 | 0x00008000 | 0x00010000;

UPDATE `item_instance` SET `flags` = (`flags` & @allowedFlags);
